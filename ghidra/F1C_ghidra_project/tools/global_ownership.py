"""
Global Ownership Map generator.
Reads ida_data_xrefs.csv + knowledge_graph/systems.json + docs/12-globals-reference.md
Outputs docs/14-global-ownership.md
"""
import csv
import json
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).parent.parent
XREFS_CSV   = ROOT / "tools" / "ida_data_xrefs.csv"
SYSTEMS_JSON = ROOT / "knowledge_graph" / "systems.json"
GLOBALS_DOC  = ROOT / "docs" / "12-globals-reference.md"
OUT_DOC      = ROOT / "docs" / "14-global-ownership.md"

# ── 1. Build func_addr → subsystem (doc file) map ────────────────────────────

def load_systems(path):
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    func_to_system = {}  # normalized hex addr → doc file name
    for doc_file, info in data.items():
        if not isinstance(info, dict) or "functions" not in info:
            continue
        for fn in info["functions"]:
            addr = fn.get("address", "")
            if addr:
                func_to_system[addr.lower()] = doc_file
    return func_to_system

# ── 2. Parse docs/12 for human-readable global names ─────────────────────────

def load_global_names(path):
    names = {}  # normalized hex addr → name string
    row_re = re.compile(r"\|\s*(DAT_[0-9a-fA-F]+)\s*\|\s*([^|]+)\|")
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = row_re.search(line)
            if m:
                raw_addr = m.group(1).strip()   # DAT_007c56a4
                name     = m.group(2).strip()
                # normalize to 0x00xxxxxx form for matching
                hex_part = raw_addr[4:]         # 007c56a4
                norm = f"0x00{hex_part}".lower() if len(hex_part) == 6 else f"0x{hex_part}".lower()
                names[norm] = f"{raw_addr} ({name})"
    return names

# ── 3. Read xrefs CSV ─────────────────────────────────────────────────────────

def load_xrefs(path):
    writers  = defaultdict(set)  # global_addr → set of func_addr
    readers  = defaultdict(set)
    offsets  = defaultdict(set)  # address-of references
    gnames   = {}                # global_addr → global_name from IDA

    with open(path, encoding="utf-8", errors="replace", newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            func  = row["func_addr"].strip().lower()
            gaddr = row["global_addr"].strip().lower()
            gname = row.get("global_name", "").strip()
            acc   = row["access"].strip().lower()
            if gname:
                gnames[gaddr] = gname
            if acc == "write":
                writers[gaddr].add(func)
            elif acc == "read":
                readers[gaddr].add(func)
            elif acc == "offset":
                offsets[gaddr].add(func)

    return writers, readers, offsets, gnames

# ── 4. Subsystem label (short name from doc file path) ───────────────────────

def subsystem_label(doc_file):
    stem = Path(doc_file).stem          # e.g. "04-tire-system"
    parts = stem.split("-", 1)
    return parts[1].replace("-", " ") if len(parts) > 1 else stem

# ── 5. Map a set of func addrs → subsystem label set ─────────────────────────

def funcs_to_subsystems(func_set, func_to_system):
    labels = set()
    for f in func_set:
        sys = func_to_system.get(f)
        if sys:
            labels.add(subsystem_label(sys))
        else:
            labels.add("unknown")
    return labels

# ── 6. Main ───────────────────────────────────────────────────────────────────

def main():
    print("Loading systems.json …")
    func_to_system = load_systems(SYSTEMS_JSON)
    print(f"  {len(func_to_system)} functions mapped to subsystems")

    print("Loading docs/12 names …")
    doc12_names = load_global_names(GLOBALS_DOC)
    print(f"  {len(doc12_names)} named globals from docs/12")

    print("Loading ida_data_xrefs.csv …")
    writers, readers, offsets, ida_names = load_xrefs(XREFS_CSV)
    all_globals = set(writers) | set(readers) | set(offsets)
    print(f"  {len(all_globals)} unique globals, {sum(len(v) for v in writers.values())} writes, "
          f"{sum(len(v) for v in readers.values())} reads, "
          f"{sum(len(v) for v in offsets.values())} offsets")

    # Compute subsystem sets for each global
    def label(gaddr):
        if gaddr in doc12_names:
            return doc12_names[gaddr]
        if gaddr in ida_names:
            return f"{ida_names[gaddr]} ({gaddr})"
        return gaddr

    # Classify globals
    shared_write  = {}  # written by 2+ subsystems
    sole_write    = {}  # written by exactly 1 subsystem
    read_only     = {}  # no writers
    no_static_writer = {}  # no write xrefs at all (offset or read only)

    for gaddr in sorted(all_globals):
        wfuncs = writers.get(gaddr, set())
        rfuncs = readers.get(gaddr, set())
        ofuncs = offsets.get(gaddr, set())
        wsys   = funcs_to_subsystems(wfuncs, func_to_system)
        rsys   = funcs_to_subsystems(rfuncs | ofuncs, func_to_system)

        entry = {
            "addr": gaddr,
            "label": label(gaddr),
            "wsys": wsys,
            "rsys": rsys,
            "wcount": len(wfuncs),
            "rcount": len(rfuncs) + len(ofuncs),
        }

        if len(wsys) >= 2:
            shared_write[gaddr] = entry
        elif len(wsys) == 1:
            sole_write[gaddr] = entry
        else:
            read_only[gaddr] = entry

    # Group sole-write by subsystem
    by_subsystem = defaultdict(lambda: {"owns": [], "reads": []})
    for gaddr, e in sole_write.items():
        owner = next(iter(e["wsys"]))
        by_subsystem[owner]["owns"].append(e)
    # Also track what each subsystem reads from others
    for gaddr, e in sole_write.items():
        owner = next(iter(e["wsys"]))
        for rsub in e["rsys"]:
            if rsub != owner:
                by_subsystem[rsub]["reads"].append({**e, "owned_by": owner})

    # ── Output ────────────────────────────────────────────────────────────────
    lines = []
    lines.append("# Global Ownership Map\n")
    lines.append(f"Generated from IDA data xrefs ({sum(len(v) for v in writers.values()) + sum(len(v) for v in readers.values()) + sum(len(v) for v in offsets.values())} total references across {len(all_globals)} globals).\n")
    lines.append("")

    lines.append("## Summary Statistics\n")
    lines.append(f"- Total globals with xrefs: {len(all_globals)}")
    lines.append(f"- Globals with write xrefs: {len(writers)}")
    lines.append(f"- Read/offset-only globals (no static writer): {len(read_only)}")
    lines.append(f"- Written by exactly one subsystem: {len(sole_write)}")
    lines.append(f"- **Shared mutable state (2+ subsystems write): {len(shared_write)}** — COUPLING POINTS")
    lines.append("")

    lines.append("## Shared Mutable State (written by 2+ subsystems)\n")
    lines.append("These globals are the coupling interfaces between subsystems.\n")
    lines.append("| Global | Writers | Readers |")
    lines.append("|--------|---------|---------|")
    for gaddr, e in sorted(shared_write.items(), key=lambda x: x[1]["wcount"], reverse=True):
        w = ", ".join(sorted(e["wsys"]))
        r = ", ".join(sorted(e["rsys"])) if e["rsys"] else "—"
        lines.append(f"| {e['label']} | {w} | {r} |")
    lines.append("")

    lines.append("## Per-Subsystem Ownership\n")
    for subsys in sorted(by_subsystem.keys()):
        data = by_subsystem[subsys]
        lines.append(f"### {subsys}\n")
        owns = sorted(data["owns"], key=lambda x: x["addr"])
        reads = sorted(data["reads"], key=lambda x: x["addr"])
        if owns:
            lines.append(f"**Owns — sole writer ({len(owns)} globals):**")
            for e in owns:
                r = f" ← read by: {', '.join(sorted(e['rsys']))}" if e["rsys"] else ""
                lines.append(f"- `{e['label']}`{r}")
        else:
            lines.append("**Owns:** none")
        lines.append("")
        if reads:
            lines.append(f"**Reads from other subsystems ({len(reads)} globals):**")
            for e in reads:
                lines.append(f"- `{e['label']}` (owned by {e['owned_by']})")
        lines.append("")

    lines.append("## Orphan Globals (no static writer found)\n")
    lines.append("These are written at runtime (config loading, OS callbacks, DLL init) or the writer is inlined/indirect.\n")
    lines.append("| Global | Readers | Ref count |")
    lines.append("|--------|---------|-----------|")
    for gaddr, e in sorted(read_only.items(), key=lambda x: x[1]["rcount"], reverse=True)[:200]:
        r = ", ".join(sorted(e["rsys"])) if e["rsys"] else "—"
        lines.append(f"| {e['label']} | {r} | {e['rcount']} |")
    if len(read_only) > 200:
        lines.append(f"\n*(showing top 200 of {len(read_only)} orphan globals by reference count)*")
    lines.append("")

    out = "\n".join(lines)
    OUT_DOC.write_text(out, encoding="utf-8")
    print(f"\nWrote {OUT_DOC} ({OUT_DOC.stat().st_size // 1024} KB, {len(lines)} lines)")
    print(f"Shared coupling points: {len(shared_write)}")
    print(f"Subsystems mapped: {len(by_subsystem)}")

if __name__ == "__main__":
    main()
