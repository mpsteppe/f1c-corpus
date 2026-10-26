"""
Merge gap_analyze worker outputs into docs/23-gap-analysis.md.

Output format per worker:
  === GAP CLASSIFICATIONS ===
  | Start | End | Size | Classification | Confidence | Description |

  === NOTABLE FINDINGS ===
  [prose]

Usage:
    python work/merge_gap_analyze.py [--archive]
"""
import re
import shutil
import sys
from collections import Counter
from datetime import datetime
from pathlib import Path

ROOT         = Path(__file__).parent.parent
OUTPUT_DIR   = ROOT / "analysis_pipeline" / "output" / "gap_analyze"
OUT_DOC      = ROOT / "docs" / "23-gap-analysis.md"
ARCHIVE_BASE = ROOT / "analysis_pipeline" / "output" / "archive" / "gap_analyze"

ARCHIVE = "--archive" in sys.argv

TABLE_HEADER = "| Start | End | Size | Classification | Confidence | Description |"
TABLE_SEP    = "|-------|-----|------|----------------|------------|-------------|"


def read(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return f.read()


def extract_section(content, marker):
    """Extract content between === MARKER === and next === or EOF."""
    pat = re.compile(
        r'===\s*' + re.escape(marker) + r'\s*===\s*\n(.*?)(?====|\Z)',
        re.DOTALL
    )
    m = pat.search(content)
    return m.group(1).strip() if m else ""


def parse_table_rows(text):
    """Extract classification rows — first column must be a hex address."""
    rows = []
    for line in text.splitlines():
        line = line.strip()
        if not line.startswith('|'):
            continue
        first_col = line.split('|')[1].strip() if '|' in line else ''
        if not re.match(r'0x[0-9a-fA-F]+', first_col):
            continue
        rows.append(line)
    return rows


def main():
    worker_files = sorted(OUTPUT_DIR.glob("worker_*.md"))
    if not worker_files:
        print(f"No worker files in {OUTPUT_DIR}")
        sys.exit(1)

    seen_starts  = set()   # dedup by start address
    all_rows     = []
    all_findings = []
    workers_read = 0
    category_counts = Counter()

    for wf in worker_files:
        content = read(wf)
        if not content.strip():
            print(f"  SKIP {wf.name}: empty")
            continue

        table_text = extract_section(content, "GAP CLASSIFICATIONS")
        rows = parse_table_rows(table_text)
        new_rows = 0
        for row in rows:
            start_col = row.split('|')[1].strip()
            if start_col in seen_starts:
                continue
            seen_starts.add(start_col)
            all_rows.append(row)
            new_rows += 1
            parts = [p.strip() for p in row.split('|') if p.strip()]
            if len(parts) >= 4:
                category_counts[parts[3]] += 1

        findings = extract_section(content, "NOTABLE FINDINGS")
        if findings:
            all_findings.append(f"<!-- {wf.name} -->\n{findings}")

        workers_read += 1
        skipped = len(rows) - new_rows
        print(f"  {wf.name}: {new_rows} gaps added ({skipped} dupes skipped)")

    if not all_rows:
        print("No classification rows found. Workers may not have finished.")
        sys.exit(1)

    # Build output
    lines = []
    lines.append("# .text Gap Analysis\n")
    lines.append(f"*Merged from {workers_read} worker(s) on {datetime.now().strftime('%Y-%m-%d')}.*\n")
    lines.append(f"**Total gaps classified: {len(all_rows)}**\n")
    lines.append("")

    lines.append("## Summary by Category\n")
    lines.append("| Category | Count |")
    lines.append("|----------|-------|")
    for cat, count in sorted(category_counts.items(), key=lambda x: -x[1]):
        lines.append(f"| {cat} | {count} |")
    lines.append("")

    lines.append("## Full Classification Table\n")
    lines.append(TABLE_HEADER)
    lines.append(TABLE_SEP)
    lines.extend(all_rows)
    lines.append("")

    if all_findings:
        lines.append("## Notable Findings\n")
        lines.append("\n\n---\n\n".join(all_findings))
        lines.append("")

    OUT_DOC.write_text("\n".join(lines), encoding="utf-8")
    print(f"\nWrote {OUT_DOC} ({OUT_DOC.stat().st_size // 1024} KB, {len(all_rows)} rows)")

    if ARCHIVE:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        dest = ARCHIVE_BASE / ts
        dest.mkdir(parents=True, exist_ok=True)
        for wf in worker_files:
            shutil.move(str(wf), str(dest / wf.name))
        print(f"Archived {len(worker_files)} files -> {dest}")


if __name__ == "__main__":
    main()
