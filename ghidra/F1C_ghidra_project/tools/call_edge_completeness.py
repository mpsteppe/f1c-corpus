"""
Phase 5 — Cross-Reference Completeness
Extracts ALL FUN_XXXXXXXX call references from every .c file,
diffs against knowledge_graph/call_graph.json, adds missing edges.

Outputs:
  work/new_call_edges.csv          — missing edges found
  knowledge_graph/call_graph.json  — updated (backup saved first)
  knowledge_graph/callers.json     — updated
"""
import re
import os
import json
import csv
import shutil
from pathlib import Path

ROOT        = Path(r"%USERPROFILE%\Desktop\F1C_ghidra_project")
DIRS        = [
    ROOT / "analysis_pipeline" / "analyzed",
    ROOT / "decompiled_all",
]
CG_PATH     = ROOT / "knowledge_graph" / "call_graph.json"
CAL_PATH    = ROOT / "knowledge_graph" / "callers.json"
OUT_CSV     = ROOT / "work" / "new_call_edges.csv"

FUN_RE   = re.compile(r'\bFUN_([0-9A-Fa-f]{8})\b')
FNAME_RE = re.compile(r'0x([0-9A-Fa-f]{8})__FUN_')

def addr(hex8: str) -> str:
    return f"0x{int(hex8, 16):08x}"

def load_c_edges():
    """Returns dict: caller_addr -> set of callee_addr (from .c source)."""
    edges = {}
    total_files = 0
    for d in DIRS:
        if not d.exists():
            continue
        for path in d.iterdir():
            if path.suffix != '.c':
                continue
            m = FNAME_RE.search(path.name)
            if not m:
                continue
            caller = addr(m.group(1))
            content = path.read_text(encoding='utf-8', errors='replace')
            callees = {addr(h) for h in FUN_RE.findall(content)}
            callees.discard(caller)  # self-ref
            if callees:
                edges[caller] = callees
            total_files += 1
    print(f"  Scanned {total_files} .c files")
    return edges

def load_existing_graph():
    """Returns dict: caller_addr -> set of callee_addr."""
    with open(CG_PATH, encoding='utf-8') as f:
        raw = json.load(f)
    existing = {}
    for caller, entries in raw.items():
        existing[caller] = {e['callee'] for e in entries}
    return existing, raw

def main():
    print("Loading existing call graph...")
    existing, raw = load_existing_graph()
    total_existing = sum(len(v) for v in existing.values())
    print(f"  {len(existing)} callers, {total_existing} edges")

    print("Extracting edges from .c files...")
    c_edges = load_c_edges()
    total_c = sum(len(v) for v in c_edges.values())
    print(f"  {len(c_edges)} callers, {total_c} edges found in source")

    print("Diffing...")
    new_edges = []
    for caller, callees in c_edges.items():
        known = existing.get(caller, set())
        for callee in callees:
            if callee not in known:
                new_edges.append((caller, callee))

    print(f"  {len(new_edges)} missing edges found")

    # Write CSV
    with open(OUT_CSV, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(['caller', 'callee'])
        w.writerows(sorted(new_edges))
    print(f"  Written: {OUT_CSV}")

    if not new_edges:
        print("Nothing to add. Call graph already complete.")
        return

    # Backup + update call_graph.json
    backup = CG_PATH.with_suffix('.json.bak')
    shutil.copy(CG_PATH, backup)
    print(f"  Backup: {backup}")

    for caller, callee in new_edges:
        if caller not in raw:
            raw[caller] = []
        raw[caller].append({'callee': callee, 'description': 'extracted_from_source'})

    with open(CG_PATH, 'w', encoding='utf-8') as f:
        json.dump(raw, f, indent=2)
    print(f"  Updated: {CG_PATH}")

    # Rebuild callers.json
    print("Rebuilding callers.json...")
    callers: dict[str, list[str]] = {}
    for caller, entries in raw.items():
        for e in entries:
            callee = e['callee']
            if callee not in callers:
                callers[callee] = []
            if caller not in callers[callee]:
                callers[callee].append(caller)

    cal_backup = CAL_PATH.with_suffix('.json.bak')
    shutil.copy(CAL_PATH, cal_backup)
    with open(CAL_PATH, 'w', encoding='utf-8') as f:
        json.dump(callers, f, indent=2)
    print(f"  Updated: {CAL_PATH}")

    # Stats
    new_total = sum(len(v) for v in raw.values())
    print(f"\nDone.")
    print(f"  Edges before: {total_existing:,}")
    print(f"  Edges added:  {len(new_edges):,}")
    print(f"  Edges after:  {new_total:,}")

    # Orphan impact
    with open(ROOT / "knowledge_graph" / "functions.json", encoding='utf-8') as f:
        all_fns = set(json.load(f).keys())
    has_edge = set(raw.keys()) | set(c for entries in raw.values() for e in entries for c in [e['callee']])
    orphans_after = len(all_fns - has_edge)
    print(f"  Orphan functions after: {orphans_after:,}")

if __name__ == "__main__":
    main()
