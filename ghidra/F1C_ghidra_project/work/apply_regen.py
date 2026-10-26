"""
apply_regen.py — apply worker_REGEN.md corrections by REPLACING existing ## FUN_ entries in docs/.

Strategy per entry:
  1. Try target doc from <!-- target: --> comment
  2. If not found there, search all docs/ for the ## FUN_ header (handles wrong-target routing)
  3. If not found anywhere, APPEND to target doc as a new entry

Usage:
    python work/apply_regen.py [--dry-run]
"""
import re, os, sys
from datetime import date

REGEN_FILE  = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_REGEN.md'
DOCS_DIR    = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs'
CHANGELOG   = r'%USERPROFILE%\Desktop\F1C_ghidra_project\work\CHANGELOG.md'

DRY_RUN = '--dry-run' in sys.argv


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except Exception:
            pass
    return ''


def build_addr_index():
    """Map addr (lower) -> doc filename for every ## FUN_ header across all docs."""
    idx = {}
    for fname in os.listdir(DOCS_DIR):
        if not fname.endswith('.md'):
            continue
        c = read_file(os.path.join(DOCS_DIR, fname))
        for m in re.finditer(r'^## FUN_([0-9A-Fa-f]{8})', c, re.M):
            idx[m.group(1).lower()] = fname
    return idx


def extract_entries(content):
    """Return list of (target_doc, addr, full_entry_text)."""
    target_pat = re.compile(r'<!-- target:\s*(docs/[\w\-\.]+)\s*-->')
    h2_pat     = re.compile(r'^## FUN_([0-9A-Fa-f]{8})', re.M)

    entries_m = re.search(r'=== FULL ENTRIES ===\n(.*)', content, re.DOTALL)
    if not entries_m:
        print("ERROR: no === FULL ENTRIES === section found")
        return []
    section = entries_m.group(1)

    matches = list(h2_pat.finditer(section))
    last_target = None
    results = []
    for i, m in enumerate(matches):
        addr = m.group(1).lower()
        start = m.start()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(section)
        block = section[start:end].rstrip('\n')

        preceding = section[max(0, start - 300):start]
        tm = target_pat.findall(preceding)
        target = tm[-1] if tm else last_target
        if target:
            last_target = target

        if target:
            results.append((target, addr, block))
        else:
            print(f"  WARN: no target for FUN_{addr.upper()}, skipping")

    return results


def replace_entry_in_doc(doc_path, addr, new_text):
    """Replace ## FUN_{addr} block in doc_path. Return True if replaced."""
    content = read_file(doc_path)
    h2_pat = re.compile(r'^## FUN_([0-9A-Fa-f]{8})', re.M)
    matches = list(h2_pat.finditer(content))

    target_idx = None
    for i, m in enumerate(matches):
        if m.group(1).lower() == addr.lower():
            target_idx = i
            break

    if target_idx is None:
        return False

    m = matches[target_idx]
    start = m.start()
    if target_idx + 1 < len(matches):
        end = matches[target_idx + 1].start()
    else:
        end = len(content)

    new_content = content[:start] + new_text.rstrip('\n') + '\n\n' + content[end:]
    if not DRY_RUN:
        open(doc_path, 'w', encoding='utf-8').write(new_content)
    return True


def append_entry_to_doc(doc_path, new_text):
    """Append new entry to end of doc_path."""
    if not DRY_RUN:
        with open(doc_path, 'a', encoding='utf-8') as f:
            f.write('\n' + new_text.rstrip('\n') + '\n\n')


def main():
    if not os.path.exists(REGEN_FILE):
        print(f"REGEN file not found: {REGEN_FILE}")
        sys.exit(1)

    content = read_file(REGEN_FILE)
    entries = extract_entries(content)
    print(f"Entries in REGEN file: {len(entries)}")

    addr_index = build_addr_index()

    replaced = []
    appended = []
    wrong_target_fixed = []
    target_missing = []

    for target, addr, new_text in entries:
        target_path = os.path.join(DOCS_DIR, os.path.basename(target))

        # Step 1: try target doc
        if os.path.exists(target_path) and replace_entry_in_doc(target_path, addr, new_text):
            replaced.append((addr, target))
            mode = '[DRY-RUN] ' if DRY_RUN else ''
            print(f"  {mode}REPLACED FUN_{addr.upper()} in {os.path.basename(target)}")
            continue

        # Step 2: search actual location across all docs
        actual_fname = addr_index.get(addr.lower())
        if actual_fname:
            actual_path = os.path.join(DOCS_DIR, actual_fname)
            if replace_entry_in_doc(actual_path, addr, new_text):
                wrong_target_fixed.append((addr, actual_fname, os.path.basename(target)))
                mode = '[DRY-RUN] ' if DRY_RUN else ''
                print(f"  {mode}REPLACED FUN_{addr.upper()} in {actual_fname} (was routed to {os.path.basename(target)})")
                continue

        # Step 3: append as new entry to target doc
        if os.path.exists(target_path):
            append_entry_to_doc(target_path, new_text)
            appended.append((addr, target))
            mode = '[DRY-RUN] ' if DRY_RUN else ''
            print(f"  {mode}APPENDED FUN_{addr.upper()} to {os.path.basename(target)} (new entry)")
        else:
            print(f"  SKIP FUN_{addr.upper()}: target file not found ({target})")
            target_missing.append(addr)

    print(f"\n{'='*40}")
    print(f"Replaced (correct target):  {len(replaced)}")
    print(f"Replaced (wrong target fix):{len(wrong_target_fixed)}")
    print(f"Appended (new entries):     {len(appended)}")
    print(f"Target file missing:        {len(target_missing)}")

    if (replaced or wrong_target_fixed or appended) and not DRY_RUN:
        today = date.today().isoformat()
        entry = f"\n\n## Phase 1 REGEN — Applied Corrections ({today})\n\n"
        entry += f"Applied {len(replaced)+len(wrong_target_fixed)} replacements + {len(appended)} new entries from worker_REGEN.md:\n\n"
        for addr, target in replaced:
            entry += f"- [CORRECTION] FUN_{addr.upper()} ({target}) — replaced\n"
        for addr, actual, intended in wrong_target_fixed:
            entry += f"- [CORRECTION] FUN_{addr.upper()} ({actual}) — replaced (worker routed to {intended})\n"
        for addr, target in appended:
            entry += f"- [NEW ENTRY] FUN_{addr.upper()} ({target}) — appended (no prior entry)\n"
        if target_missing:
            entry += f"\nSkipped (target doc not found):\n"
            for addr in target_missing:
                entry += f"- FUN_{addr.upper()}\n"
        open(CHANGELOG, 'a', encoding='utf-8').write(entry)
        print(f"\nLogged to CHANGELOG.")

    if DRY_RUN:
        print("\n[DRY-RUN] No files modified.")


if __name__ == '__main__':
    main()
