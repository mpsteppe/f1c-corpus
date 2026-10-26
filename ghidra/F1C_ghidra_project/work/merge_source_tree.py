"""
Merge source_tree worker outputs into docs/00-source-tree.md.

Each worker covers a non-overlapping subset of source paths, so merge is
additive: concatenate all Source File Details sections, aggregate statistics.

Usage:
    python work/merge_source_tree.py [--archive]
"""
import os
import re
import shutil
import sys
from datetime import datetime
from pathlib import Path

ROOT       = Path(__file__).parent.parent
OUTPUT_DIR = ROOT / "analysis_pipeline" / "output" / "source_tree"
OUT_DOC    = ROOT / "docs" / "00-source-tree.md"
ARCHIVE_BASE = ROOT / "analysis_pipeline" / "output" / "archive" / "source_tree"

ARCHIVE = "--archive" in sys.argv


def read(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return f.read()


def extract_section(content, header):
    """Extract content of a ## header section (prefix match, up to next ## or EOF)."""
    pattern = re.compile(
        r'^##\s+' + re.escape(header) + r'[^\n]*\n(.*?)(?=^##\s|\Z)',
        re.MULTILINE | re.DOTALL
    )
    m = pattern.search(content)
    return m.group(1).strip() if m else ""


def extract_stats(content):
    """Parse '## Statistics*' section — handles bullet lists and markdown tables."""
    stats_text = extract_section(content, "Statistics")
    out = {}
    # Bullet: "- Source files: 18" or "- .cpp files: N"
    for m in re.finditer(r'-\s+([^:|\n]+?):\s*(\d+)', stats_text):
        key = m.group(1).strip().rstrip('.')
        out[key] = out.get(key, 0) + int(m.group(2))
    # Markdown table: "| Unique .cpp files | 19 |"
    for m in re.finditer(r'\|\s*([^|]+?)\s*\|\s*(\d+)[^|]*\|', stats_text):
        key = m.group(1).strip()
        if key and key.lower() not in ('metric', 'count', 'value'):
            out[key] = out.get(key, 0) + int(m.group(2))
    return out


def main():
    worker_files = sorted(OUTPUT_DIR.glob("worker_*.md"))
    if not worker_files:
        print(f"No worker files in {OUTPUT_DIR}")
        sys.exit(1)

    all_details   = []
    all_dir_lines = []
    total_stats   = {}
    workers_read  = 0

    for wf in worker_files:
        content = read(wf)
        if not content.strip():
            print(f"  SKIP {wf.name}: empty")
            continue

        # Directory Structure
        dir_block = extract_section(content, "Directory Structure")
        if dir_block:
            all_dir_lines.append(f"<!-- from {wf.name} -->\n{dir_block}")

        # Source File Details — collect all ### subsections
        details_block = extract_section(content, "Source File Details")
        if details_block:
            all_details.append(details_block.strip())

        # Statistics
        for k, v in extract_stats(content).items():
            total_stats[k] = total_stats.get(k, 0) + v

        workers_read += 1
        print(f"  {wf.name}: ok")

    if not all_details:
        print("No '## Source File Details' sections found in any worker output.")
        print("Workers may not have finished yet, or output format differs.")
        sys.exit(1)

    # Build output doc
    lines = []
    lines.append("# F1 Challenge 99-02 — Reconstructed Source Tree\n")
    lines.append(f"*Merged from {workers_read} worker(s) on {datetime.now().strftime('%Y-%m-%d')}.*\n")
    lines.append("")

    if all_dir_lines:
        lines.append("## Directory Structure\n")
        lines.append("\n\n".join(all_dir_lines))
        lines.append("")

    lines.append("## Source File Details\n")
    lines.append("\n\n".join(all_details))
    lines.append("")

    if total_stats:
        lines.append("## Statistics\n")
        for k, v in sorted(total_stats.items()):
            lines.append(f"- {k}: {v}")
        lines.append("")

    OUT_DOC.write_text("\n".join(lines), encoding="utf-8")
    print(f"\nWrote {OUT_DOC} ({OUT_DOC.stat().st_size // 1024} KB)")

    if ARCHIVE:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        dest = ARCHIVE_BASE / ts
        dest.mkdir(parents=True, exist_ok=True)
        for wf in worker_files:
            shutil.move(str(wf), str(dest / wf.name))
        print(f"Archived {len(worker_files)} worker files -> {dest}")


if __name__ == "__main__":
    main()
