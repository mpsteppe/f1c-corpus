"""
generate_review_queue.py

Reads the triage index, finds all functions classified as game_logic /
collision / physics_math / dynamics / renderer / audio / network that
do NOT yet have a full ## FUN_ entry in docs/, and writes a queue file.

Output: work/review_queue.jsonl  (one JSON object per line)

Run before generating batches in Full Entry mode.
"""

import re, os, json, sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

WORKSPACE    = os.path.dirname(os.path.abspath(__file__))
DOCS_DIR     = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs"
INDEX_FILE   = os.path.join(DOCS_DIR, "decompiled_full_index_final.md")
NOT_ANALYZED = os.path.join(WORKSPACE, "not_analyzed")
ANALYZED     = os.path.join(WORKSPACE, "analyzed")
WORK_DIR     = os.path.join(WORKSPACE, "work")
OUTPUT       = os.path.join(WORK_DIR, "review_queue.jsonl")

NEED_FULL = {'game_logic', 'collision', 'physics_math', 'dynamics',
             'renderer', 'audio', 'network'}

DETERMINISTIC_TARGET = {
    'collision':    'docs/17-physics-collision.md',
    'physics_math': 'docs/18-physics-dynamics.md',
    'dynamics':     'docs/18-physics-dynamics.md',
    'renderer':     'docs/19-renderer.md',
    'audio':        'docs/21-audio-network-internals.md',
    'network':      'docs/21-audio-network-internals.md',
}

# game_logic routing: scan .c file for these globals, first match wins
GLOBAL_HINTS = [
    (['DAT_007d01a0', 'DAT_005bf9b0', 'DAT_008aae70'],
        'docs/02-ai-system.md'),
    (['DAT_007cea5c'],
        'docs/03-engine-wear-damage.md'),
    (['DAT_007d0c60', 'DAT_007ce958'],
        'docs/04-tire-system.md'),
    (['DAT_007cf080'],
        'docs/05-weather-system.md'),
    (['DAT_007cec30', 'DAT_007cec54', 'DAT_007cec78'],
        'docs/07-pit-system.md'),
    (['DAT_007c56a4', 'DAT_007c56a8', 'DAT_007cef84', 'DAT_007cebc4',
      'DAT_007d0308', 'DAT_007d0410', 'DAT_007d0b64', 'DAT_008acf9c',
      'DAT_008acf90', 'DAT_008acf94'],
        'docs/06-session-race-logic.md'),
    (['DAT_007d00ec'],
        'docs/01-engine-architecture.md'),
    (['DAT_005ea3d8', 'DAT_008ac488', 'DAT_008ac48c', 'DAT_008ac490'],
        'docs/09-track-system.md'),
    (['DAT_007c54e8', 'DAT_007c54f0', 'DAT_005c329c'],
        'docs/10-vehicle-physics.md'),
]


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1', 'cp1252'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except Exception:
            pass
    return ""


def suggest_target(cat, c_path):
    if cat in DETERMINISTIC_TARGET:
        return DETERMINISTIC_TARGET[cat]
    content = read_file(c_path)
    for globals_list, doc in GLOBAL_HINTS:
        if any(g in content for g in globals_list):
            return doc
    return 'docs/06-session-race-logic.md'   # most common fallback


def build_file_index():
    idx = {}
    for directory in [ANALYZED, NOT_ANALYZED]:
        if not os.path.isdir(directory):
            continue
        for fname in os.listdir(directory):
            if not fname.endswith('.c'):
                continue
            m = re.search(r'0x(00[0-9a-fA-F]{6})', fname, re.I)
            if m:
                idx[m.group(1).lower()] = os.path.join(directory, fname)
    return idx


def get_documented():
    documented = set()
    for f in os.listdir(DOCS_DIR):
        if not f.endswith('.md'):
            continue
        c = read_file(os.path.join(DOCS_DIR, f))
        for m in re.finditer(r'^## FUN_([0-9a-fA-F]+)', c, re.MULTILINE):
            documented.add(m.group(1).lower())
    return documented


def main():
    os.makedirs(WORK_DIR, exist_ok=True)

    print("Reading docs for existing ## FUN_ entries...")
    documented = get_documented()
    print(f"  Already documented: {len(documented)}")

    print("Indexing .c files in analyzed/ and not_analyzed/...")
    file_index = build_file_index()
    print(f"  Files indexed: {len(file_index)}")

    print("Scanning triage index...")
    queue = []
    missing_file = 0
    already_done = 0
    wrong_cat = 0
    cat_summary = {}

    for line in read_file(INDEX_FILE).splitlines():
        m = re.match(r'\|?\s*(0x[0-9a-fA-F]+)\s*\|\s*(\d+)\s*\|\s*([^|]+?)\s*\|', line)
        if not m:
            continue
        addr_full = m.group(1)
        addr      = addr_full[2:].lower()
        line_count = int(m.group(2))
        cat       = m.group(3).strip().lower()

        if cat not in NEED_FULL:
            wrong_cat += 1
            continue
        if addr in documented:
            already_done += 1
            continue

        c_path = file_index.get(addr)
        if not c_path:
            missing_file += 1
            continue

        target = suggest_target(cat, c_path)
        queue.append({
            'addr':     addr,
            'addr_full': addr_full,
            'category': cat,
            'lines':    line_count,
            'path':     c_path,
            'target':   target,
        })
        cat_summary[cat] = cat_summary.get(cat, 0) + 1

    # Sort: game_logic first (highest value), then by line count desc
    CAT_PRIO = {'game_logic': 0, 'collision': 1, 'dynamics': 2,
                'physics_math': 3, 'renderer': 4, 'audio': 5, 'network': 6}
    queue.sort(key=lambda x: (CAT_PRIO.get(x['category'], 9), -x['lines']))

    with open(OUTPUT, 'w', encoding='utf-8') as f:
        for item in queue:
            f.write(json.dumps(item) + '\n')

    print(f"\nQueue written: {len(queue)} entries -> {OUTPUT}")
    print(f"  Skipped (wrong category):   {wrong_cat}")
    print(f"  Skipped (already in docs/): {already_done}")
    print(f"  Skipped (no .c file found): {missing_file}")
    print(f"\nBreakdown by category:")
    for cat, n in sorted(cat_summary.items(), key=lambda x: -x[1]):
        print(f"  {cat:<20} {n}")
    print(f"\nRun 1_batch_gui.bat, switch to Full Entry mode, then Generate.")


if __name__ == '__main__':
    main()
