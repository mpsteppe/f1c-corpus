"""
merge_struct_synth.py — append all struct_synth worker output into docs/13-struct-offsets.md.

Workers wrote free-form (no <!-- target: --> comments), so we concatenate directly.
Skips workers with no useful content (O, Q, R — non-source docs).
Archives worker files after merge.

Usage: python work/merge_struct_synth.py [--dry-run]
"""
import os, re, sys
from datetime import datetime

STRUCT_SYNTH_DIR = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_synth'
TARGET_DOC       = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md'
CHANGELOG        = r'%USERPROFILE%\Desktop\F1C_ghidra_project\work\CHANGELOG.md'
ARCHIVE_DIR      = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\archive'

DRY_RUN = '--dry-run' in sys.argv

# Workers assigned non-source docs — skip their output
SKIP_WORKERS = {'O', 'Q', 'R'}

# Known assignment from generate time (fallback when header lacks doc name)
WORKER_DOC = {
    'A': 'docs/06-session-race-logic.md',
    'B': 'docs/20-math-utilities.md',
    'C': 'docs/01-engine-architecture.md',
    'D': 'docs/18-physics-dynamics.md',
    'E': 'docs/10-vehicle-physics.md',
    'F': 'docs/08-file-formats.md',
    'G': 'docs/19-renderer.md',
    'H': 'docs/17-physics-collision.md',
    'I': 'docs/03-engine-wear-damage.md',
    'J': 'docs/09-track-system.md',
    'K': 'docs/21-audio-network-internals.md',
    'L': 'docs/02-ai-system.md',
    'M': 'docs/07-pit-system.md',
    'N': 'docs/04-tire-system.md',
    'P': 'docs/05-weather-system.md',
}


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except Exception:
            pass
    return ''


def get_source_doc(content, letter):
    """Extract source doc name from worker header, fall back to known assignment."""
    m = re.search(r'docs/[\w\-\.]+\.md', content[:300])
    if m:
        return m.group(0)
    return WORKER_DOC.get(letter, 'unknown')


def main():
    files = sorted(f for f in os.listdir(STRUCT_SYNTH_DIR) if f.endswith('.md'))

    merged_sections = []
    skipped = []
    stats = {}

    for fname in files:
        letter_m = re.match(r'worker_([A-T])\.md$', fname)
        if not letter_m:
            continue
        letter = letter_m.group(1)
        if letter in SKIP_WORKERS:
            skipped.append(fname)
            continue

        path = os.path.join(STRUCT_SYNTH_DIR, fname)
        content = read_file(path)
        if not content.strip() or len(content) < 50:
            skipped.append(fname)
            continue

        source_doc = get_source_doc(content, letter)
        structs = len(re.findall(r'^## ', content, re.M))
        tables  = len(re.findall(r'^\| Offset', content, re.M))

        if structs == 0 and tables == 0:
            skipped.append(fname)
            continue

        stats[fname] = (source_doc, structs, tables)

        # Strip the worker header line (first H1) — keep the rest
        body = re.sub(r'^# Worker [A-T][^\n]*\n', '', content, count=1).strip()

        section = (
            f"\n\n---\n\n"
            f"## Source: {source_doc}\n\n"
            + body
        )
        merged_sections.append(section)
        print(f"  {fname}: {structs} structs, {tables} tables ({source_doc})")

    print(f"\nSkipped: {', '.join(skipped)}")
    print(f"Merging {len(merged_sections)} worker outputs into docs/13")

    if not merged_sections:
        print("Nothing to merge.")
        return

    combined = ''.join(merged_sections)

    if not DRY_RUN:
        with open(TARGET_DOC, 'a', encoding='utf-8') as f:
            f.write(combined)
        print(f"Written to {TARGET_DOC}")

        # Log to CHANGELOG
        today = datetime.now().strftime('%Y-%m-%d')
        entry = f"\n\n## Phase 2A Struct Synthesis — Merged ({today})\n\n"
        entry += f"Appended {len(merged_sections)} worker outputs to docs/13-struct-offsets.md:\n\n"
        for fname, (src, structs, tables) in sorted(stats.items()):
            entry += f"- {fname}: {structs} structs, {tables} offset-tables ({src})\n"
        open(CHANGELOG, 'a', encoding='utf-8').write(entry)

        # Archive worker files
        ts = datetime.now().strftime('%Y-%m-%d_%H%M%S')
        arc = os.path.join(ARCHIVE_DIR, f'{ts}_struct_synth')
        os.makedirs(arc, exist_ok=True)
        for fname in files:
            src = os.path.join(STRUCT_SYNTH_DIR, fname)
            os.replace(src, os.path.join(arc, fname))
        print(f"Archived to output/archive/{ts}_struct_synth/")
    else:
        print("\n[DRY-RUN] No files modified.")
        total_structs = sum(s for _, s, _ in stats.values())
        total_tables  = sum(t for _, _, t in stats.values())
        print(f"Would append: {total_structs} structs, {total_tables} offset-tables")


if __name__ == '__main__':
    main()
