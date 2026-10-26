"""
Analyze IDA data xrefs against existing documentation.

Produces:
  1. ida_undocumented_globals.csv — globals IDA found that docs/12 doesn't have
  2. ida_global_validation.csv   — documented globals with IDA ref counts + type info
  3. Summary stats to stdout

Run: python tools/ida_data_xref_analysis.py
"""

import csv
import os
import re

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DOCS = os.path.join(ROOT, "docs")
TOOLS = os.path.dirname(os.path.abspath(__file__))

DATA_XREFS  = os.path.join(TOOLS, "ida_data_xrefs.csv")
OUTPUT_UNDOC = os.path.join(TOOLS, "ida_undocumented_globals.csv")
OUTPUT_VALID = os.path.join(TOOLS, "ida_global_validation.csv")


def load_documented_globals():
    """Extract all DAT_ addresses and names from docs/12."""
    globals_map = {}
    doc12 = os.path.join(DOCS, "12-globals-reference.md")
    if not os.path.exists(doc12):
        return globals_map
    with open(doc12, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = re.search(r'DAT_([0-9a-fA-F]{8})\s*\|\s*([^|]+)', line)
            if m:
                addr = "0x" + m.group(1).lower()
                name = m.group(2).strip()
                globals_map[addr] = name
    return globals_map


def load_ida_xrefs():
    """Load IDA data xrefs into {global_addr: [(func_addr, access, ida_name), ...]}."""
    xrefs = {}
    with open(DATA_XREFS, encoding="utf-8") as f:
        for row in csv.DictReader(f):
            gaddr = row["global_addr"]
            entry = (row["func_addr"], row["access"], row["global_name"])
            xrefs.setdefault(gaddr, []).append(entry)
    return xrefs


def main():
    if not os.path.exists(DATA_XREFS):
        print(f"ERROR: {DATA_XREFS} not found")
        return

    documented = load_documented_globals()
    ida_xrefs = load_ida_xrefs()

    print(f"Documented globals (docs/12): {len(documented)}")
    print(f"IDA global addresses: {len(ida_xrefs)}")

    # Split into documented vs undocumented
    validated = []
    undocumented = []

    for gaddr, refs in sorted(ida_xrefs.items(), key=lambda x: len(x[1]), reverse=True):
        ref_count = len(refs)
        ida_name = refs[0][2] if refs else ""
        accesses = set(r[1] for r in refs)
        access_str = ",".join(sorted(accesses))
        func_addrs = sorted(set(r[0] for r in refs))

        if gaddr in documented:
            our_name = documented[gaddr]
            validated.append({
                "addr": gaddr,
                "our_name": our_name,
                "ida_name": ida_name,
                "ref_count": ref_count,
                "access_pattern": access_str,
                "top_funcs": "|".join(func_addrs[:10]),
            })
        else:
            undocumented.append({
                "addr": gaddr,
                "ida_name": ida_name,
                "ref_count": ref_count,
                "access_pattern": access_str,
                "func_count": len(func_addrs),
                "top_funcs": "|".join(func_addrs[:10]),
            })

    # Write undocumented globals
    with open(OUTPUT_UNDOC, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["addr", "ida_name", "ref_count", "access_pattern", "func_count", "top_funcs"])
        w.writeheader()
        w.writerows(undocumented)
    print(f"\nUndocumented globals: {len(undocumented)} -> {os.path.basename(OUTPUT_UNDOC)}")

    # Write validation table
    with open(OUTPUT_VALID, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["addr", "our_name", "ida_name", "ref_count", "access_pattern", "top_funcs"])
        w.writeheader()
        w.writerows(validated)
    print(f"Validated globals: {len(validated)} -> {os.path.basename(OUTPUT_VALID)}")

    # Stats
    overlap = len(validated)
    ida_only = len(undocumented)
    doc_only = len(documented) - overlap

    print(f"\n{'='*60}")
    print(f"SUMMARY")
    print(f"{'='*60}")
    print(f"  Both IDA + docs/12:  {overlap}")
    print(f"  IDA-only (new):      {ida_only}")
    print(f"  docs/12-only:        {doc_only}")
    print(f"  Total unique:        {overlap + ida_only + doc_only}")

    # Top undocumented by ref count
    print(f"\n{'='*60}")
    print(f"TOP 40 UNDOCUMENTED GLOBALS (by reference count)")
    print(f"{'='*60}")
    for row in undocumented[:40]:
        print(f"  {row['ref_count']:4d} refs  {row['addr']}  {row['ida_name'][:40]:40s}  ({row['access_pattern']})")

    # Globals in docs/12 but IDA never saw referenced
    doc_not_ida = {a: n for a, n in documented.items() if a not in ida_xrefs}
    if doc_not_ida:
        print(f"\n{'='*60}")
        print(f"DOCUMENTED BUT IDA SAW NO REFERENCES ({len(doc_not_ida)})")
        print(f"{'='*60}")
        for addr, name in sorted(doc_not_ida.items())[:20]:
            print(f"  {addr}  {name}")
        if len(doc_not_ida) > 20:
            print(f"  ... and {len(doc_not_ida)-20} more")


if __name__ == "__main__":
    main()
