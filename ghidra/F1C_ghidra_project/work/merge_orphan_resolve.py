"""
Merge orphan_resolve worker output into new_call_edges.csv + rebuild graph.

Reads:  analysis_pipeline/output/orphan_resolve/worker_*.md
Writes: work/new_call_edges.csv  (appends new edges)
        work/orphan_resolve_summary.csv  (full classification table)
Then:   rebuilds knowledge graph
"""
import re
import os
import csv
import subprocess
import sys

ROOT     = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUTDIR   = os.path.join(ROOT, "analysis_pipeline", "output", "orphan_resolve")
EDGES    = os.path.join(ROOT, "work", "new_call_edges.csv")
SUMMARY  = os.path.join(ROOT, "work", "orphan_resolve_summary.csv")
REBUILD  = os.path.join(ROOT, "tools", "knowledge_graph", "rebuild.py")
PYTHON   = r"%USERPROFILE%\AppData\Local\Python\bin\python3.exe"

ROW_RE   = re.compile(
    r'^\| (0x[0-9a-fA-F]+) \| (\w+) \| (\w+) \| (.+?) \| (.+?) \|'
)
ADDR_RE  = re.compile(r'0x[0-9a-fA-F]{8}')

def parse_workers():
    rows = []
    for letter in "ABCDEFGHIJKLMNOPQRST":
        path = os.path.join(OUTDIR, f"worker_{letter}.md")
        if not os.path.exists(path):
            continue
        for line in open(path, encoding="utf-8", errors="replace"):
            m = ROW_RE.match(line)
            if not m:
                continue
            addr, cls, conf, evidence, suggested = (
                m.group(1), m.group(2), m.group(3),
                m.group(4).strip(), m.group(5).strip()
            )
            rows.append({
                "address": addr,
                "classification": cls,
                "confidence": conf,
                "evidence": evidence,
                "suggested_caller": suggested,
            })
    return rows


def extract_new_edges(rows):
    """Return list of (caller, callee) tuples from vtable/callback rows with named callers."""
    actionable_classes = {"vtable_member", "callback", "static_init"}
    edges = []
    for row in rows:
        if row["classification"] not in actionable_classes:
            continue
        callee = row["address"]
        # Extract any 0xXXXXXXXX addresses from suggested_caller field
        callers = ADDR_RE.findall(row["suggested_caller"])
        for caller in callers:
            edges.append((caller.lower(), callee.lower()))
    return edges


def load_existing_edges():
    existing = set()
    if not os.path.exists(EDGES):
        return existing
    with open(EDGES, encoding="utf-8") as f:
        for row in csv.DictReader(f):
            existing.add((row["caller"], row["callee"]))
    return existing


def main():
    print("Parsing worker output...")
    rows = parse_workers()
    print(f"  {len(rows)} classifications read")

    # Write full summary CSV
    with open(SUMMARY, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["address","classification","confidence","evidence","suggested_caller"])
        w.writeheader()
        w.writerows(sorted(rows, key=lambda r: r["classification"]))
    print(f"  Summary: {SUMMARY}")

    # Breakdown
    from collections import Counter
    counts = Counter(r["classification"] for r in rows)
    print("\nClassification breakdown:")
    for cls, n in counts.most_common():
        print(f"  {cls:30s} {n:3d}")

    # Extract new edges
    new_edges = extract_new_edges(rows)
    existing  = load_existing_edges()
    truly_new = [(c, e) for c, e in new_edges if (c, e) not in existing]

    print(f"\nNew edges from vtable/callback/static_init: {len(truly_new)}")

    if truly_new:
        # Append to new_call_edges.csv
        file_exists = os.path.exists(EDGES)
        with open(EDGES, "a", newline="", encoding="utf-8") as f:
            w = csv.writer(f)
            if not file_exists:
                w.writerow(["caller", "callee"])
            for caller, callee in sorted(truly_new):
                w.writerow([caller, callee])
        print(f"  Appended to: {EDGES}")
    else:
        print("  No new edges with named callers found.")
        print("  (vtable/callback orphans lack explicit caller addresses — expected)")

    # Stats on actionable orphans
    vtable   = [r for r in rows if r["classification"] == "vtable_member"]
    callback = [r for r in rows if r["classification"] == "callback"]
    gl       = [r for r in rows if r["classification"] == "game_logic_isolated"]
    dead     = [r for r in rows if r["classification"] == "dead_code"]
    ep       = [r for r in rows if r["classification"] == "entry_point"]

    print(f"\n=== ACTIONABLE SUMMARY ===")
    print(f"  vtable_member:       {len(vtable):3d}  — document which vtable slot")
    print(f"  callback:            {len(callback):3d}  — document registration site")
    print(f"  game_logic_isolated: {len(gl):3d}  — real code, missing dispatch edges")
    print(f"  dead_code:           {len(dead):3d}  — safe to deprioritize")
    print(f"  entry_point:         {len(ep):3d}  — SEH/CRT/Winsock, expected orphans")

    # Rebuild graph
    print(f"\nRebuilding knowledge graph...")
    result = subprocess.run([PYTHON, REBUILD], capture_output=True, text=True)
    for line in result.stdout.splitlines():
        if any(k in line for k in ["edges", "orphan", "functions", "Done"]):
            print(f"  {line.strip()}")
    if result.returncode != 0:
        print("REBUILD ERROR:", result.stderr[:300])

    print("\nDone.")


if __name__ == "__main__":
    main()
