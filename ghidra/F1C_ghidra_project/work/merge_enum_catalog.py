"""
Merge enum_catalog worker outputs into docs/24-enum-catalog.md.

Output format per worker:
  === ENUM DISCOVERIES ===
  ### EnumName
  | Value | Meaning | Evidence | Confidence |

  === MAGIC NUMBERS ===
  | Value | Hex | Type | Used In | Likely Meaning |

Usage:
    python work/merge_enum_catalog.py [--archive]
"""
import re
import shutil
import sys
from datetime import datetime
from pathlib import Path

ROOT         = Path(__file__).parent.parent
OUTPUT_DIR   = ROOT / "analysis_pipeline" / "output" / "enum_catalog"
OUT_DOC      = ROOT / "docs" / "24-enum-catalog.md"
ARCHIVE_BASE = ROOT / "analysis_pipeline" / "output" / "archive" / "enum_catalog"

ARCHIVE = "--archive" in sys.argv


def read(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return f.read()


def extract_section(content, marker):
    pat = re.compile(
        r'===\s*' + re.escape(marker) + r'\s*===\s*\n(.*?)(?====|\Z)',
        re.DOTALL
    )
    m = pat.search(content)
    return m.group(1).strip() if m else ""


def parse_enum_blocks(text):
    """Split '### EnumName\\n...' blocks into dict name->body."""
    blocks = {}
    parts = re.split(r'^### ', text, flags=re.MULTILINE)
    for part in parts:
        if not part.strip():
            continue
        lines = part.split('\n', 1)
        name = lines[0].strip()
        body = lines[1].strip() if len(lines) > 1 else ""
        if name in blocks:
            # Merge: append rows from duplicate (different workers may find more values)
            blocks[name] += "\n" + body
        else:
            blocks[name] = body
    return blocks


def parse_table_rows(text):
    rows = []
    for line in text.splitlines():
        line = line.strip()
        if not line.startswith('|'):
            continue
        if re.search(r'Value|Hex|---', line):
            continue
        if '|' in line and len(line) > 5:
            rows.append(line)
    return rows


def dedup_rows(rows):
    """Remove exact duplicate table rows."""
    seen = set()
    out = []
    for r in rows:
        if r not in seen:
            seen.add(r)
            out.append(r)
    return out


def main():
    worker_files = sorted(OUTPUT_DIR.glob("worker_*.md"))
    if not worker_files:
        print(f"No worker files in {OUTPUT_DIR}")
        sys.exit(1)

    merged_enums   = {}   # name -> body text
    all_magic_rows = []
    raw_dumps      = []  # per-function dumps from batch files (=== BATCH N === format)
    workers_read   = 0

    for wf in worker_files:
        content = read(wf)
        if not content.strip():
            print(f"  SKIP {wf.name}: empty")
            continue

        has_standard = "=== ENUM DISCOVERIES ===" in content or "=== MAGIC NUMBERS ===" in content

        if has_standard:
            enum_text = extract_section(content, "ENUM DISCOVERIES")
            blocks = parse_enum_blocks(enum_text)
            for name, body in blocks.items():
                if name in merged_enums:
                    merged_enums[name] += "\n" + body
                else:
                    merged_enums[name] = body

            magic_text = extract_section(content, "MAGIC NUMBERS")
            all_magic_rows.extend(parse_table_rows(magic_text))
            print(f"  {wf.name}: {len(blocks)} enums, {len(parse_table_rows(magic_text))} magic rows")
        else:
            # Batch file: === BATCH N — items X-Y === format with ### FUN_ADDR blocks
            # Collect as raw per-function dumps
            batch_sections = re.findall(
                r'===\s*BATCH[^=]*===\s*\n(.*?)(?====|\Z)',
                content, re.DOTALL
            )
            for section in batch_sections:
                raw_dumps.append(section.strip())
            func_count = len(re.findall(r'^### ', content, re.MULTILINE))
            print(f"  {wf.name}: batch format — {func_count} function dumps")

        workers_read += 1

    if not merged_enums and not all_magic_rows:
        print("No content found. Workers may not have finished.")
        sys.exit(1)

    all_magic_rows = dedup_rows(all_magic_rows)

    lines = []
    lines.append("# Enum & Magic Number Catalog\n")
    lines.append(f"*Merged from {workers_read} worker(s) on {datetime.now().strftime('%Y-%m-%d')}.*\n")
    lines.append(f"**{len(merged_enums)} enum groups | {len(all_magic_rows)} magic number entries**\n")
    lines.append("")

    if merged_enums:
        lines.append("## Enum Discoveries\n")
        for name in sorted(merged_enums.keys()):
            lines.append(f"### {name}\n")
            lines.append(merged_enums[name])
            lines.append("")

    if all_magic_rows:
        lines.append("## Magic Numbers\n")
        lines.append("| Value | Hex | Type | Used In | Likely Meaning |")
        lines.append("|-------|-----|------|---------|---------------|")
        lines.extend(all_magic_rows)
        lines.append("")

    if raw_dumps:
        lines.append("## Raw Per-Function Magic Number Dumps\n")
        lines.append(f"*{len(raw_dumps)} batch section(s) from context-limited workers.*\n")
        lines.append("\n\n---\n\n".join(raw_dumps))
        lines.append("")

    OUT_DOC.write_text("\n".join(lines), encoding="utf-8")
    print(f"\nWrote {OUT_DOC} ({OUT_DOC.stat().st_size // 1024} KB)")

    if ARCHIVE:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        dest = ARCHIVE_BASE / ts
        dest.mkdir(parents=True, exist_ok=True)
        for wf in worker_files:
            shutil.move(str(wf), str(dest / wf.name))
        print(f"Archived {len(worker_files)} files -> {dest}")


if __name__ == "__main__":
    main()
