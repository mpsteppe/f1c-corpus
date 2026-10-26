"""
Post-process IDA export CSVs and integrate with the project.

Run after run_ida_export.bat completes:
    python tools/ida_diff_and_import.py

Actions:
  1. Diff ida_functions.csv vs work/function_sizes.csv
       -> prints functions IDA found that Ghidra missed (resolve giant gaps)
  2. Map vtable slots to orphan function addresses
       -> prints new caller edges for vtable_member orphans
       -> appends new edges to work/new_call_edges.csv
  3. Report FLIRT-matched names for previously unnamed functions
       -> prints renaming candidates
  4. Check the 3 known giant gap addresses specifically
"""

import csv
import json
import os

ROOT      = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))

IDA_FUNCS   = os.path.join(TOOLS_DIR, "ida_functions.csv")
IDA_VTABLES = os.path.join(TOOLS_DIR, "ida_vtables.csv")
GHIDRA_CSV  = os.path.join(ROOT, "work", "function_sizes.csv")
ORPHAN_CSV  = os.path.join(ROOT, "work", "orphan_resolve_summary.csv")
EDGES_CSV   = os.path.join(ROOT, "work", "new_call_edges.csv")
KG_FUNCS    = os.path.join(ROOT, "knowledge_graph", "functions.json")

# Known giant gaps from binary_coverage_audit.py
GIANT_GAPS = [
    ("0x0056fa96", 24_000, "unknown_code"),
    ("0x0047fc54", 22_000, "unknown_code"),
    ("0x00575bbd", 17_000, "unknown_code"),
]

def load_csv_set(path, key_col):
    result = {}
    if not os.path.exists(path):
        return result
    with open(path, encoding="utf-8") as f:
        for row in csv.DictReader(f):
            k = row[key_col].lower().strip()
            result[k] = row
    return result


def load_existing_edges():
    existing = set()
    if not os.path.exists(EDGES_CSV):
        return existing
    with open(EDGES_CSV, encoding="utf-8") as f:
        for row in csv.DictReader(f):
            existing.add((row["caller"].lower(), row["callee"].lower()))
    return existing


def normalize_addr(s):
    s = s.strip().lower()
    if s.startswith("0x"):
        return s
    return "0x" + s.lstrip("0") or "0x0"


def main():
    if not os.path.exists(IDA_FUNCS):
        print(f"ERROR: {IDA_FUNCS} not found — run run_ida_export.bat first")
        return

    # ── Load IDA functions ──────────────────────────────────────────────────
    ida_funcs = {}
    with open(IDA_FUNCS, encoding="utf-8") as f:
        for row in csv.DictReader(f):
            addr = normalize_addr(row["addr"])
            ida_funcs[addr] = row
    print(f"IDA: {len(ida_funcs)} functions")

    # ── Load Ghidra functions ───────────────────────────────────────────────
    ghidra_funcs = {}
    if os.path.exists(GHIDRA_CSV):
        with open(GHIDRA_CSV, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                addr = normalize_addr(row.get("address", row.get("addr", "")))
                ghidra_funcs[addr] = row
    print(f"Ghidra: {len(ghidra_funcs)} functions")

    # ── 1. Functions IDA found that Ghidra missed ───────────────────────────
    print("\n" + "=" * 60)
    print("1. IDA-only functions (Ghidra missed)")
    print("=" * 60)
    ida_only = {a: r for a, r in ida_funcs.items() if a not in ghidra_funcs}
    print(f"   Total: {len(ida_only)}")

    # Filter to game code range (skip imports/thunks at high addresses)
    GAME_START = 0x00401000
    GAME_END   = 0x005e0000
    game_ida_only = {
        a: r for a, r in ida_only.items()
        if GAME_START <= int(a, 16) <= GAME_END
    }
    print(f"   In game code range (0x401000-0x5e0000): {len(game_ida_only)}")

    for addr in sorted(game_ida_only, key=lambda x: int(x, 16)):
        r = game_ida_only[addr]
        print(f"   {addr}  size={r['size']:>6}  {r['source']:10s}  {r['name'][:60]}")

    # ── 2. Giant gap check ──────────────────────────────────────────────────
    print("\n" + "=" * 60)
    print("2. Giant gap analysis (Ghidra missed, IDA result)")
    print("=" * 60)
    for gap_addr, gap_size, _ in GIANT_GAPS:
        gap_int = int(gap_addr, 16)
        # Find all IDA functions within this gap region
        gap_end = gap_int + gap_size
        found = [
            (a, r) for a, r in ida_funcs.items()
            if gap_int <= int(a, 16) < gap_end
        ]
        found.sort(key=lambda x: int(x[0], 16))
        status = f"{len(found)} functions found by IDA" if found else "NOT found by IDA either"
        print(f"\n   Gap {gap_addr} (~{gap_size//1024}KB): {status}")
        for addr, r in found:
            in_ghidra = "ghidra" if addr in ghidra_funcs else "IDA-only"
            print(f"     {addr}  size={r['size']:>6}  {in_ghidra:10s}  {r['name'][:50]}")

    # ── 3. FLIRT-matched names for known functions ──────────────────────────
    print("\n" + "=" * 60)
    print("3. FLIRT-matched names (functions IDA identified, Ghidra didn't)")
    print("=" * 60)
    flirt_matches = {
        a: r for a, r in ida_funcs.items()
        if r["source"] == "flirt" and a in ghidra_funcs
    }
    print(f"   {len(flirt_matches)} functions with FLIRT names")
    for addr in sorted(flirt_matches, key=lambda x: int(x, 16))[:50]:
        r = flirt_matches[addr]
        print(f"   {addr}  {r['name'][:60]}")
    if len(flirt_matches) > 50:
        print(f"   ... and {len(flirt_matches)-50} more")

    # ── 4. Vtable → orphan mapping ──────────────────────────────────────────
    print("\n" + "=" * 60)
    print("4. Vtable orphan resolution")
    print("=" * 60)

    if not os.path.exists(IDA_VTABLES):
        print("   ida_vtables.csv not found — skipping")
    elif not os.path.exists(ORPHAN_CSV):
        print("   orphan_resolve_summary.csv not found — skipping")
    else:
        # Load orphan vtable_member addresses
        vtable_orphans = set()
        with open(ORPHAN_CSV, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                if row["classification"] == "vtable_member":
                    vtable_orphans.add(normalize_addr(row["address"]))
        print(f"   vtable_member orphans: {len(vtable_orphans)}")

        # Load vtable data
        new_edges = []
        existing  = load_existing_edges()
        resolved  = 0

        vtable_to_funcs = {}  # vtable_addr -> list of (slot, func_addr, func_name)
        with open(IDA_VTABLES, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                vt = normalize_addr(row["vtable_addr"])
                fn = normalize_addr(row["func_addr"])
                vtable_to_funcs.setdefault(vt, []).append((int(row["slot"]), fn, row["func_name"]))

        # For each vtable, check if any slot points to an orphan function
        for vt_addr, slots in sorted(vtable_to_funcs.items()):
            for slot_idx, fn_addr, fn_name in slots:
                if fn_addr in vtable_orphans:
                    # Find sibling functions in the same vtable as context (the class)
                    sibling = next(
                        (f for s, f, _ in slots if s == 0 and f != fn_addr),
                        vt_addr
                    )
                    edge = (vt_addr, fn_addr)
                    if edge not in existing:
                        new_edges.append(edge)
                        existing.add(edge)
                    print(f"   RESOLVED: {fn_addr} ({fn_name}) <- vtable {vt_addr} slot {slot_idx}")
                    resolved += 1

        print(f"\n   Resolved: {resolved} vtable_member orphans")
        print(f"   New edges: {len(new_edges)}")

        if new_edges:
            file_exists = os.path.exists(EDGES_CSV)
            with open(EDGES_CSV, "a", newline="", encoding="utf-8") as f:
                w = csv.writer(f)
                if not file_exists:
                    w.writerow(["caller", "callee"])
                for caller, callee in sorted(new_edges):
                    w.writerow([caller, callee])
            print(f"   Appended to: {EDGES_CSV}")
            print("   Run: python tools/knowledge_graph/rebuild.py")

    print("\nDone.")


if __name__ == "__main__":
    main()
