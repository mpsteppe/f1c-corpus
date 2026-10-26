"""
merge_global_sweep.py — merge all global_sweep worker output into docs/12-globals-reference.md.

Handles two row formats workers used:
  Format A: | DAT_XXXXXXXX | Name | module | type | range | desc | used_by | confidence |
  Format B: | # | DAT_XXXXXXXX | Name | module | type | range | desc | used_by | confidence |

Normalises to Format A, deduplicates by DAT_ address, appends to docs/12.

Usage: python work/merge_global_sweep.py [--dry-run]
"""
import os, re, sys
from datetime import datetime

GS_DIR     = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep'
TARGET_DOC = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md'
CHANGELOG  = r'%USERPROFILE%\Desktop\F1C_ghidra_project\work\CHANGELOG.md'
ARCHIVE    = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\archive'

DRY_RUN = '--dry-run' in sys.argv

# Regex: row starting with | DAT_ or | <number> | DAT_
ROW_A = re.compile(r'^\| (DAT_[0-9A-Fa-f]+) \| (.+)$')
ROW_B = re.compile(r'^\| \d+ \| (DAT_[0-9A-Fa-f]+) \| (.+)$')
# Deep-dive sections for unnamed globals
DEEP_DIVE = re.compile(r'^### (DAT_[0-9A-Fa-f]+.+?)$(?:\n(?!###).+)*', re.M)

SKIP_PATTERN = re.compile(r'ProposedName|value_range|Address|DAT_ \|', re.I)


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except Exception:
            pass
    return ''


def extract_rows(content):
    """Return list of (addr, normalised_row_string) from a worker file."""
    rows = []
    for line in content.splitlines():
        line = line.strip()
        if not line.startswith('|'):
            continue
        if SKIP_PATTERN.search(line):
            continue
        m = ROW_B.match(line)
        if m:
            addr = m.group(1).upper()
            rest = m.group(2)
            rows.append((addr, f'| {addr} | {rest}'))
            continue
        m = ROW_A.match(line)
        if m:
            addr = m.group(1).upper()
            rest = m.group(2)
            rows.append((addr, f'| {addr} | {rest}'))
    return rows


def extract_deep_dives(content):
    """Return deep-dive blocks for unnamed globals."""
    return DEEP_DIVE.findall(content)


def get_existing_addrs(path):
    if not os.path.exists(path):
        return set()
    c = read_file(path)
    return set(m.upper() for m in re.findall(r'DAT_[0-9A-Fa-f]+', c))


def main():
    files = sorted(f for f in os.listdir(GS_DIR)
                   if f.endswith('.md') and re.match(r'worker_[A-T]\.md$', f))

    seen_addrs = get_existing_addrs(TARGET_DOC)
    all_rows = []
    all_deep_dives = []
    per_worker = {}

    for fname in files:
        letter = fname[7]
        path = os.path.join(GS_DIR, fname)
        content = read_file(path)
        rows = extract_rows(content)

        new_rows = []
        for addr, row in rows:
            if addr not in seen_addrs:
                seen_addrs.add(addr)
                new_rows.append(row)

        deep_dives = extract_deep_dives(content)
        all_deep_dives.extend(deep_dives)
        all_rows.extend(new_rows)
        per_worker[fname] = (len(rows), len(new_rows))
        print(f"  {fname}: {len(rows)} rows extracted | {len(new_rows)} new")

    print(f"\nTotal new rows: {len(all_rows)} / 875")
    print(f"Deep-dive sections: {len(all_deep_dives)}")

    if not all_rows:
        print("Nothing new to append.")
        return

    table_header = (
        "\n\n---\n\n"
        "## Global Sweep Results (Phase 2B)\n\n"
        "| DAT_ Address | Name | Module | Type | Value Range | Description | Used By | Confidence |\n"
        "|-------------|------|--------|------|-------------|-------------|---------|------------|\n"
    )
    table_body = '\n'.join(all_rows)

    deep_dive_section = ''
    if all_deep_dives:
        deep_dive_section = (
            "\n\n## Unnamed Globals — Analysis\n\n"
            + '\n\n'.join(all_deep_dives)
        )

    combined = table_header + table_body + deep_dive_section

    if not DRY_RUN:
        with open(TARGET_DOC, 'a', encoding='utf-8') as f:
            f.write(combined)
        print(f"Written to docs/12-globals-reference.md")

        today = datetime.now().strftime('%Y-%m-%d')
        entry = f"\n\n## Phase 2B Global Sweep — Merged ({today})\n\n"
        entry += f"Appended {len(all_rows)} global rows + {len(all_deep_dives)} deep-dives to docs/12:\n\n"
        for fname, (total, new) in sorted(per_worker.items()):
            entry += f"- {fname}: {total} rows, {new} new\n"
        open(CHANGELOG, 'a', encoding='utf-8').write(entry)

        ts = datetime.now().strftime('%Y-%m-%d_%H%M%S')
        arc = os.path.join(ARCHIVE, f'{ts}_global_sweep')
        os.makedirs(arc, exist_ok=True)
        for fname in files:
            src = os.path.join(GS_DIR, fname)
            os.replace(src, os.path.join(arc, fname))
        print(f"Archived to output/archive/{ts}_global_sweep/")
    else:
        print("\n[DRY-RUN] No files modified.")


if __name__ == '__main__':
    main()
