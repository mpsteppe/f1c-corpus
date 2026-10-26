"""
Merge struct_audit worker output into docs/13-audit-report.md.

Workers produce annotated struct sections:
  ## StructName — Section N
  | Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
  ...
  === NEW OFFSETS DISCOVERED ===
  | Struct | Offset | Type | Found In | Notes |
  ...
  === SUMMARY ===
  ...

This script:
  1. Reads all worker_*.md from output/struct_audit/
  2. Strips boilerplate headers (=== AUDIT RESULTS ===)
  3. Collects sections, new offsets, and per-worker summaries
  4. Writes docs/13-audit-report.md

Run: python work/merge_struct_audit.py
"""

import os
import re

ROOT       = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUTPUT_DIR = os.path.join(ROOT, "analysis_pipeline", "output", "struct_audit")
OUT_DOC    = os.path.join(ROOT, "docs", "13-audit-report.md")


def split_worker(content):
    """Return (section_blocks, new_offset_rows, summary_text) from one worker file.

    Handles two formats:
      A) Single === NEW OFFSETS DISCOVERED === block at end
      B) Multiple per-section === NEW OFFSETS DISCOVERED === blocks inline
    """
    new_offset_rows = []
    summary_text    = ""
    section_blocks  = []

    DELIM_NEW     = re.compile(r'^={3,}\s*NEW OFFSETS DISCOVERED\s*={0,}', re.I | re.M)
    DELIM_SUMMARY = re.compile(r'^={3,}\s*SUMMARY.*={0,}', re.I | re.M)
    DELIM_AUDIT   = re.compile(r'^={3,}\s*AUDIT RESULTS\s*={0,}', re.I | re.M)

    # Remove boilerplate opener
    content = DELIM_AUDIT.sub('', content)

    # Tokenise into segments: split on all === markers, tagging each segment type
    all_delims = sorted(
        [(m.start(), m.end(), 'new')     for m in DELIM_NEW.finditer(content)] +
        [(m.start(), m.end(), 'summary') for m in DELIM_SUMMARY.finditer(content)],
        key=lambda x: x[0]
    )

    if not all_delims:
        # No delimiters at all — treat whole content as sections
        return content.strip(), [], ""

    # Everything before first delimiter = section text
    current_section_text = content[:all_delims[0][0]].strip()
    if current_section_text:
        section_blocks.append(current_section_text)

    for i, (start, end, kind) in enumerate(all_delims):
        seg_end = all_delims[i + 1][0] if i + 1 < len(all_delims) else len(content)
        seg = content[end:seg_end].strip()

        if kind == 'new':
            new_offset_rows.extend(extract_new_offset_rows(seg))
            # Remaining section text after the new-offsets block
            # Find the next ## header inside seg to detect trailing section text
            next_h2 = re.search(r'^## ', seg, re.M)
            if next_h2:
                section_blocks.append(seg[next_h2.start():].strip())
        elif kind == 'summary':
            summary_text += seg + "\n"

    return "\n\n".join(section_blocks), new_offset_rows, summary_text.strip()


def extract_new_offset_rows(text):
    """Extract table rows from a new-offsets block, skip header/separator lines."""
    rows = []
    for line in text.splitlines():
        line = line.strip()
        if not line.startswith("|"):
            continue
        if line.startswith("|---") or line.startswith("|-----"):
            continue
        if "Struct" in line and "Offset" in line and "Type" in line:
            continue
        if "(None" in line or "script did not" in line:
            continue
        rows.append(line)
    return rows


def main():
    if not os.path.isdir(OUTPUT_DIR):
        print(f"No output directory: {OUTPUT_DIR}")
        return

    worker_files = sorted(
        f for f in os.listdir(OUTPUT_DIR)
        if f.startswith("worker_") and f.endswith(".md")
    )
    if not worker_files:
        print("No worker output files found")
        return

    print(f"Reading {len(worker_files)} worker files...")

    all_sections   = []
    all_new_rows   = []
    all_summaries  = []
    seen_sections  = set()

    for wf in worker_files:
        path = os.path.join(OUTPUT_DIR, wf)
        content = open(path, encoding="utf-8", errors="replace").read()
        sections_text, new_rows, summary_text = split_worker(content)

        # Collect section blocks (split on ## headers)
        blocks = re.split(r'(?=^## )', sections_text, flags=re.M)
        new_in_worker = 0
        for block in blocks:
            block = block.strip()
            if not block or not block.startswith("## "):
                continue
            # Deduplicate by normalised header
            header = block.splitlines()[0].strip()
            key = re.sub(r'\s*[—-]\s*Section \d+', '', header)
            key = re.sub(r'^## (?:Section \d+:\s*)?', '', key).lower().strip()
            if key in seen_sections:
                continue
            seen_sections.add(key)
            all_sections.append((wf, block))
            new_in_worker += 1

        all_new_rows.extend(new_rows)

        if summary_text:
            all_summaries.append((wf, summary_text))

        print(f"  {wf}: {new_in_worker} sections, {len(new_rows)} new offset rows")

    print(f"\nTotal sections: {len(all_sections)}")
    print(f"Total new offset rows: {len(all_new_rows)}")

    # Build output
    lines = []
    lines.append("# docs/13 Struct Confidence Audit Report")
    lines.append("")
    lines.append(f"Generated from {len(worker_files)} DS worker runs. "
                 f"{len(all_sections)} struct sections audited.")
    lines.append("")
    lines.append("Each section contains: confidence scores per field, .c evidence, conflicts, "
                 "and newly discovered offsets.")
    lines.append("")
    lines.append("---")
    lines.append("")

    # Per-worker summaries first
    if all_summaries:
        lines.append("## Worker Summaries")
        lines.append("")
        for wf, summary in all_summaries:
            label = wf.replace("worker_", "Worker ").replace(".md", "")
            lines.append(f"### {label}")
            lines.append("")
            lines.append(summary)
            lines.append("")
        lines.append("---")
        lines.append("")

    # Aggregated new offsets
    if all_new_rows:
        lines.append("## All New Offsets Discovered")
        lines.append("")
        lines.append("| Struct | Offset | Type | Found In | Notes |")
        lines.append("|--------|--------|------|----------|-------|")
        for row in all_new_rows:
            lines.append(row)
        lines.append("")
        lines.append("---")
        lines.append("")

    # All audited sections
    lines.append("## Audited Struct Sections")
    lines.append("")
    for wf, block in all_sections:
        lines.append(block)
        lines.append("")
        lines.append("---")
        lines.append("")

    with open(OUT_DOC, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))

    print(f"Written: {OUT_DOC}")


if __name__ == "__main__":
    main()
