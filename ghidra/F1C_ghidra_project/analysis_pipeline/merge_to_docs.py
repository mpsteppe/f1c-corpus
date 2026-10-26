"""
merge_to_docs.py — push worker output files into the real docs/ files.

Run: python merge_to_docs.py

Reads output/worker_*.md, extracts:
  - Triage lines  -> appended to docs/decompiled_full_index_final.md
  - Full entries  -> appended to target docs/ file per <!-- target: --> comment

Skips addresses already present in the target file (no duplicates).
Prints a summary of what was written.
"""

import os
import re
import sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

WORKSPACE   = os.path.dirname(os.path.abspath(__file__))
OUTPUT_DIR  = os.path.join(WORKSPACE, "output")
DOCS_DIR    = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs"
INDEX_FILE  = os.path.join(DOCS_DIR, "decompiled_full_index_final.md")
LETTERS     = "ABCDEFGHIJKLMNOPQRST"

DEFAULT_TARGET = "docs/20-math-utilities.md"  # fallback if no target comment


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1', 'cp1252'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except:
            pass
    return ""


def get_existing_addresses(path):
    """Return set of lowercase hex addresses that already have a ## FUN_ heading in the file."""
    if not os.path.exists(path):
        return set()
    content = read_file(path)
    # Only match actual ## FUN_ section headers, not mentions in Calls/Globals/etc.
    return set(m.lower() for m in re.findall(r'^#{2,3} FUN_([0-9a-fA-F]+)', content, re.MULTILINE))


def extract_triage_lines(content):
    """Return list of triage row strings from === TRIAGE LINES === section."""
    lines = []
    in_section = False
    for line in content.splitlines():
        if "=== TRIAGE LINES ===" in line:
            in_section = True
            continue
        if "=== FULL ENTRIES ===" in line:
            break
        if in_section and re.match(r'^\| 0x[0-9a-fA-F]+', line):
            lines.append(line)
    return lines


def extract_full_entries(content):
    """
    Return list of (target_doc, addr, entry_text) tuples.
    Each entry starts with optional <!-- target: ... --> comment.
    """
    results = []
    # Split on <!-- target: ... --> markers or ## / ### FUN_ headers
    h2_pattern = re.compile(r'^#{2,3} FUN_([0-9a-fA-F]+)', re.MULTILINE)
    target_pattern = re.compile(r'<!-- target:\s*(docs/[\w\-\.]+)\s*-->')

    # Work through the FULL ENTRIES section only
    entries_match = re.search(r'=== FULL ENTRIES ===\n(.*)', content,
                              re.DOTALL)
    if not entries_match:
        return results
    entries_section = entries_match.group(1)

    # Split into individual entries: everything between ## FUN_ headers
    matches = list(h2_pattern.finditer(entries_section))
    last_target = DEFAULT_TARGET   # propagate last known target for entries missing one
    for i, m in enumerate(matches):
        addr = m.group(1).lower()
        start = m.start()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(entries_section)
        block = entries_section[start:end]

        # Find target comment — look in the 200 chars before ## FUN_
        preceding = entries_section[max(0, start - 200):start]
        tm = target_pattern.findall(preceding)
        if tm:
            target = tm[-1]
            last_target = target   # remember for following entries that omit target
        else:
            target = last_target   # propagate instead of falling to global default

        # Strip leading <!-- target --> line from block if present
        full_text = block.rstrip('\n') + '\n\n'
        results.append((target, addr, full_text))

    return results


def append_to_file(path, text):
    with open(path, 'a', encoding='utf-8') as f:
        f.write(text)


def merge_worker(path, stats):
    if not os.path.exists(path):
        return
    content = read_file(path)
    if not content.strip() or content.strip().count('\n') < 3:
        return

    label = os.path.basename(path)
    print(f"\n{label}:")

    # ── Triage lines ─────────────────────────────────────────────────────────
    triage_lines = extract_triage_lines(content)
    existing_idx = get_existing_addresses(INDEX_FILE)
    new_triage = []
    for line in triage_lines:
        m = re.match(r'\| (0x[0-9a-fA-F]+)', line)
        if m and m.group(1)[2:].lower() not in existing_idx:
            new_triage.append(line)
            existing_idx.add(m.group(1)[2:].lower())

    if new_triage:
        append_to_file(INDEX_FILE, '\n'.join(new_triage) + '\n')
        stats['triage'] += len(new_triage)
        print(f"  triage lines added: {len(new_triage)}")
    else:
        print(f"  triage lines: 0 new (all already in index)")

    # ── Full entries ──────────────────────────────────────────────────────────
    entries = extract_full_entries(content)
    for target, addr, text in entries:
        doc_path = os.path.join(DOCS_DIR, os.path.basename(target))
        if not os.path.exists(doc_path):
            print(f"  SKIP {addr}: target not found ({target})")
            stats['skipped'] += 1
            continue

        existing = get_existing_addresses(doc_path)
        if addr in existing:
            stats['duplicate'] += 1
            continue

        append_to_file(doc_path, text)
        stats['entries'] += 1
        stats.setdefault('by_doc', {})
        stats['by_doc'][os.path.basename(target)] = \
            stats['by_doc'].get(os.path.basename(target), 0) + 1

    by_doc = stats.get('by_doc', {})
    if by_doc:
        for doc, n in sorted(by_doc.items()):
            print(f"  {doc}: +{n} entries")


def backup_and_clear_workers(worker_paths):
    """Archive all worker files; reset standard worker_X.md, delete batch files."""
    from datetime import datetime
    timestamp = datetime.now().strftime("%Y-%m-%d_%H%M%S")
    # For subdir modes, archive under output/archive/<subdir>/ to keep history separate
    base_output = os.path.join(os.path.dirname(os.path.abspath(__file__)), "output")
    if OUTPUT_DIR != base_output:
        subdir_name = os.path.basename(OUTPUT_DIR)
        archive_dir = os.path.join(base_output, "archive", subdir_name, timestamp)
    else:
        archive_dir = os.path.join(base_output, "archive", timestamp)
    os.makedirs(archive_dir, exist_ok=True)

    for src in worker_paths:
        fname = os.path.basename(src)
        dst = os.path.join(archive_dir, fname)
        os.replace(src, dst)

        # Standard worker_X.md in top-level output/ — reset to empty template
        if OUTPUT_DIR == base_output and re.match(r'^worker_[A-U]\.md$', fname):
            letter = fname[7]
            with open(src, 'w', encoding='utf-8') as f:
                f.write(f"# Worker {letter} Output\n\n=== TRIAGE LINES ===\n\n=== FULL ENTRIES ===\n")
        # Subdir mode or batch files — archived copy is enough, no reset needed

    print(f"Archived to: {os.path.relpath(archive_dir, base_output)}/")


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--move-only', action='store_true',
                        help='Skip merge, just run move_analyzed() on current docs state')
    parser.add_argument('--subdir', default=None,
                        help='Merge from output/<subdir>/ instead of output/ (no archive/clear by default)')
    parser.add_argument('--archive', action='store_true',
                        help='When used with --subdir: archive files after merging (same as standard mode)')
    args = parser.parse_args()

    if args.move_only:
        print("-- Move-only mode --")
        move_analyzed()
        return

    global OUTPUT_DIR
    no_archive = False
    if args.subdir:
        OUTPUT_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "output", args.subdir)
        no_archive = not args.archive
        print(f"-- Subdir mode: {OUTPUT_DIR} ({'archive after merge' if args.archive else 'no archive'}) --")

    stats = {'triage': 0, 'entries': 0, 'duplicate': 0, 'skipped': 0}

    # Collect all worker output files: worker_X.md and worker_X_batchN.md
    all_files = sorted(os.listdir(OUTPUT_DIR)) if os.path.isdir(OUTPUT_DIR) else []
    worker_paths = []
    for fname in all_files:
        if not fname.endswith('.md'):
            continue
        if not re.match(r'^worker_[A-U](\.md|_batch\d+\.md)$', fname):
            continue
        path = os.path.join(OUTPUT_DIR, fname)
        if os.path.getsize(path) > 100:
            worker_paths.append(path)

    if not worker_paths:
        print(f"No worker output files found in {OUTPUT_DIR}")
        print("Tip: run with --move-only to just sync analyzed/ from current docs state.")
        return

    print(f"Merging {len(worker_paths)} file(s):")
    for p in worker_paths:
        print(f"  {os.path.basename(p)}")

    for path in worker_paths:
        merge_worker(path, stats)

    print(f"\n{'='*40}")
    print(f"Triage lines added to index: {stats['triage']}")
    print(f"Full entries written to docs: {stats['entries']}")
    print(f"Duplicates skipped:           {stats['duplicate']}")
    print(f"Missing target files skipped: {stats['skipped']}")
    print(f"{'='*40}")
    print(f"\nDone. Review docs/ changes before committing.")

    if no_archive:
        print("Subdir mode — files NOT archived or cleared.")
        return

    # ── Move newly documented files to analyzed/ ──────────────────────────────
    move_analyzed()

    # ── Archive worker files and reset for next batch ─────────────────────────
    backup_and_clear_workers(worker_paths)


def move_analyzed():
    """Move files from not_analyzed/ to analyzed/ if their address appears in docs/
    as a full ## FUN_ entry OR as a triage line in the index."""
    not_analyzed = os.path.join(WORKSPACE, "not_analyzed")
    analyzed     = os.path.join(WORKSPACE, "analyzed")

    if not os.path.isdir(not_analyzed):
        return

    # Full ## FUN_ entries across all docs/ files
    documented = set()
    for f in os.listdir(DOCS_DIR):
        if not f.endswith('.md'):
            continue
        content = read_file(os.path.join(DOCS_DIR, f))
        for m in re.finditer(r'^## FUN_([0-9a-fA-F]+)', content, re.MULTILINE):
            documented.add(m.group(1).lower())

    # Triage-only entries in the master index (math_util / unknown / etc.)
    # Accept both "| 0x..." and "0x..." line formats
    if os.path.exists(INDEX_FILE):
        idx_content = read_file(INDEX_FILE)
        for line in idx_content.splitlines():
            m = re.match(r'\|?\s*(0x[0-9a-fA-F]+)', line)
            if m:
                documented.add(m.group(1)[2:].lower())

    moved = 0
    for fname in os.listdir(not_analyzed):
        if not fname.endswith('.c'):
            continue
        m = re.search(r'0x(00[0-9a-fA-F]{6})', fname, re.IGNORECASE)
        if not m:
            continue
        addr = m.group(1).lower()
        if addr in documented:
            src = os.path.join(not_analyzed, fname)
            dst = os.path.join(analyzed, fname)
            os.replace(src, dst)
            moved += 1

    print(f"Moved to analyzed/: {moved} files")
    remaining = len([f for f in os.listdir(not_analyzed) if f.endswith('.c')])
    print(f"Remaining in not_analyzed/: {remaining} files")


if __name__ == '__main__':
    main()
