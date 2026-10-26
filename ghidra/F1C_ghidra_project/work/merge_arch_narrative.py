"""
merge_arch_narrative.py — prepend arch_narrative worker output to the top of target docs.

Workers output narrative prose to output/arch_narrative/worker_X.md with:
  <!-- target: docs/XX-name.md -->
  ## System Overview ...

This script prepends the narrative to the top of each target doc.

Usage: python work/merge_arch_narrative.py [--dry-run]
"""
import os, re, sys
from datetime import datetime

AN_DIR   = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\arch_narrative'
DOCS_DIR = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs'
CHANGELOG= r'%USERPROFILE%\Desktop\F1C_ghidra_project\work\CHANGELOG.md'
ARCHIVE  = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\archive'

DRY_RUN = '--dry-run' in sys.argv


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except Exception:
            pass
    return ''


def extract_narrative(content):
    """Return (target_doc, narrative_text) from worker output.
    Handles both <!-- target: docs/XX --> and <!-- ARCHITECTURE NARRATIVE ... docs/XX ... --> formats."""
    entries_m = re.search(r'=== FULL ENTRIES ===\n(.*)', content, re.DOTALL)
    section = entries_m.group(1) if entries_m else content

    # Find any docs/ reference in first 600 chars of section
    doc_pat  = re.compile(r'docs/([\w\-]+\.md)')
    comment_pat = re.compile(r'<!--[^>]+-->')

    # Look for target in comment blocks
    target = None
    last_comment_end = 0
    for cm in comment_pat.finditer(section[:800]):
        dm = doc_pat.search(cm.group(0))
        if dm:
            target = 'docs/' + dm.group(1)
            last_comment_end = cm.end()
            break

    # Also check heading lines like "# WORKER B OUTPUT — ... docs/18..."
    if not target:
        dm = doc_pat.search(section[:400])
        if dm:
            target = 'docs/' + dm.group(1)
            last_comment_end = dm.end()

    if not target:
        return None, None

    # Narrative = everything after comments/header, starting at first ##
    rest = section[last_comment_end:].strip()
    # If rest doesn't start with ##, find first ## heading
    h2 = re.search(r'^##', rest, re.M)
    if h2:
        rest = rest[h2.start():]

    # Strip any remaining comment blocks
    rest = comment_pat.sub('', rest).strip()
    return target, rest


def main():
    files = sorted(f for f in os.listdir(AN_DIR)
                   if re.match(r'worker_[A-F]\.md$', f))

    applied = []
    skipped = []

    for fname in files:
        path = os.path.join(AN_DIR, fname)
        content = read_file(path)
        if len(content) < 200:
            skipped.append((fname, 'too short'))
            continue

        target, narrative = extract_narrative(content)
        if not target or not narrative:
            skipped.append((fname, 'no target or empty narrative'))
            continue

        doc_path = os.path.join(DOCS_DIR, os.path.basename(target))
        if not os.path.exists(doc_path):
            skipped.append((fname, f'target not found: {target}'))
            continue

        doc_content = read_file(doc_path)

        # Check if narrative already prepended (avoid double-prepend on re-run)
        if '## System Overview' in doc_content[:5000]:
            skipped.append((fname, f'narrative already present in {target}'))
            continue

        words = len(narrative.split())
        print(f"  {fname} -> {target}: {words} words narrative")

        new_content = narrative.rstrip('\n') + '\n\n---\n\n' + doc_content
        if not DRY_RUN:
            open(doc_path, 'w', encoding='utf-8').write(new_content)
        applied.append((fname, target, words))

    print(f"\n{'='*40}")
    print(f"Applied: {len(applied)}")
    print(f"Skipped: {len(skipped)}")
    for fname, reason in skipped:
        print(f"  SKIP {fname}: {reason}")

    if applied and not DRY_RUN:
        today = datetime.now().strftime('%Y-%m-%d')
        entry = f"\n\n## Phase 4 Arch Narrative — Merged ({today})\n\n"
        entry += f"Prepended narratives to {len(applied)} doc files:\n\n"
        for fname, target, words in applied:
            entry += f"- {fname} -> {target} ({words} words)\n"
        open(CHANGELOG, 'a', encoding='utf-8').write(entry)

        ts = datetime.now().strftime('%Y-%m-%d_%H%M%S')
        arc = os.path.join(ARCHIVE, f'{ts}_arch_narrative')
        os.makedirs(arc, exist_ok=True)
        for fname in files:
            src = os.path.join(AN_DIR, fname)
            if os.path.exists(src):
                os.replace(src, os.path.join(arc, fname))
        print(f"Archived to output/archive/{ts}_arch_narrative/")

    if DRY_RUN:
        print("\n[DRY-RUN] No files modified.")


if __name__ == '__main__':
    main()
