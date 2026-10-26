"""
Merge global_validate worker output into docs/12-globals-reference.md.

Workers produce table rows:
    | DAT_XXXXXXXX | Name | Module | Type | Access | Ref Count | Notes |

This script:
  1. Reads all worker_X.md files from output/global_validate/
  2. Extracts table rows
  3. Deduplicates against existing docs/12 entries
  4. Appends new rows to docs/12-globals-reference.md

Run: python work/merge_global_validate.py
"""

import os
import re
import sys

ROOT  = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DOC12 = os.path.join(ROOT, "docs", "12-globals-reference.md")

subdir = "global_validate"
for arg in sys.argv[1:]:
    if arg.startswith("--subdir="):
        subdir = arg.split("=", 1)[1]
    elif arg == "--subdir" and sys.argv.index(arg) + 1 < len(sys.argv):
        subdir = sys.argv[sys.argv.index(arg) + 1]

OUTPUT_DIR = os.path.join(ROOT, "analysis_pipeline", "output", subdir)


def extract_table_rows(content):
    """Extract DAT_ table rows from worker output."""
    rows = []
    for line in content.splitlines():
        line = line.strip()
        if not line.startswith("|"):
            continue
        if "DAT_" not in line:
            continue
        if "Address" in line and "Name" in line:
            continue
        if line.startswith("|---"):
            continue
        rows.append(line)
    return rows


def load_existing_addrs():
    """Get addresses already in docs/12."""
    addrs = set()
    if not os.path.exists(DOC12):
        return addrs
    with open(DOC12, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = re.search(r'DAT_([0-9a-fA-F]{8})', line)
            if m:
                addrs.add(m.group(1).lower())
    return addrs


def main():
    if not os.path.isdir(OUTPUT_DIR):
        print(f"No output directory: {OUTPUT_DIR}")
        return

    worker_files = sorted(
        f for f in os.listdir(OUTPUT_DIR) if f.startswith("worker_") and f.endswith(".md")
    )
    if not worker_files:
        print("No worker output files found")
        return

    print(f"Reading {len(worker_files)} worker files...")

    existing = load_existing_addrs()
    print(f"Existing globals in docs/12: {len(existing)}")

    all_rows = []
    seen_addrs = set()

    for wf in worker_files:
        path = os.path.join(OUTPUT_DIR, wf)
        content = open(path, encoding="utf-8", errors="replace").read()
        rows = extract_table_rows(content)
        new = 0
        for row in rows:
            m = re.search(r'DAT_([0-9a-fA-F]{8})', row)
            if not m:
                continue
            addr = m.group(1).lower()
            if addr in existing or addr in seen_addrs:
                continue
            seen_addrs.add(addr)
            all_rows.append(row)
            new += 1
        print(f"  {wf}: {len(rows)} rows, {new} new")

    print(f"\nTotal new globals: {len(all_rows)}")

    if not all_rows:
        print("Nothing to merge.")
        return

    # Append to docs/12
    with open(DOC12, "a", encoding="utf-8") as f:
        label = subdir.replace("_", " ").title()
        f.write(f"\n\n### {label} ({len(all_rows)} globals)\n\n")
        f.write("| Address | Name | Module | Type | Access | Ref Count | Notes |\n")
        f.write("|---------|------|--------|------|--------|-----------|-------|\n")
        for row in all_rows:
            f.write(row + "\n")

    print(f"Appended {len(all_rows)} rows to {DOC12}")


if __name__ == "__main__":
    main()
