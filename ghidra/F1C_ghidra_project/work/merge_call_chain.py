"""
Merge call_chain worker outputs into docs/31-call-chains/.

Each worker_X.md may contain multiple chain documents separated by `# Chain:` headers.
Each chain is written to its own file: 31-call-chains/NN-chain-name.md

Usage:
    python work/merge_call_chain.py [--dry-run]
"""

import os, re, sys, shutil

WORKSPACE     = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INPUT_DIR     = os.path.join(WORKSPACE, 'analysis_pipeline', 'output', 'call_chain')
OUTPUT_DIR    = os.path.join(WORKSPACE, 'docs', '31-call-chains')
ARCHIVE_DIR   = os.path.join(WORKSPACE, 'analysis_pipeline', 'output', 'archive')

DRY_RUN = '--dry-run' in sys.argv

os.makedirs(OUTPUT_DIR, exist_ok=True)

def slugify(title):
    s = title.lower()
    s = re.sub(r'[^a-z0-9]+', '-', s)
    return s.strip('-')[:60]


def split_chains(content):
    """Split worker output into individual chain docs.
    Accepts both '# Chain:' and '# Chain N:' formats."""
    parts = re.split(r'(?=^# Chain[\s\d]*:)', content, flags=re.MULTILINE)
    chains = []
    for part in parts:
        part = part.strip()
        if not part or not re.match(r'^# Chain[\s\d]*:', part):
            continue
        m = re.match(r'^# Chain[\s\d]*:\s*(.+)', part)
        if m:
            title = m.group(1).strip()
            chains.append((title, part))
    return chains


# Collect all worker files
worker_files = sorted(
    f for f in os.listdir(INPUT_DIR)
    if re.match(r'worker_[A-T]\.md$', f)
) if os.path.isdir(INPUT_DIR) else []

if not worker_files:
    print(f"No worker_X.md files found in {INPUT_DIR}")
    sys.exit(1)

all_chains = []
for wf in worker_files:
    path = os.path.join(INPUT_DIR, wf)
    content = open(path, encoding='utf-8', errors='ignore').read()
    chains = split_chains(content)
    print(f"{wf}: {len(chains)} chain(s) found")
    all_chains.extend(chains)

print(f"\nTotal chains: {len(all_chains)}")

# Deduplicate by title (seed address should be in the title)
seen_titles = set()
deduped = []
for title, content in all_chains:
    key = title[:40]
    if key not in seen_titles:
        seen_titles.add(key)
        deduped.append((title, content))
    else:
        print(f"  [SKIP duplicate] {title[:60]}")

print(f"After dedup: {len(deduped)} chains")

# Write each chain to its own file
for i, (title, content) in enumerate(deduped, 1):
    slug = slugify(title)
    fname = f"{i:04d}-{slug}.md"
    out_path = os.path.join(OUTPUT_DIR, fname)
    if DRY_RUN:
        print(f"  [DRY RUN] would write: docs/31-call-chains/{fname}  ({len(content)} chars)")
    else:
        with open(out_path, 'w', encoding='utf-8') as f:
            f.write(content + '\n')
        print(f"  wrote: docs/31-call-chains/{fname}")

if not DRY_RUN:
    # Archive worker files
    import datetime
    ts = datetime.datetime.now().strftime('%Y%m%d_%H%M%S')
    arc = os.path.join(ARCHIVE_DIR, f'call_chain_{ts}')
    os.makedirs(arc, exist_ok=True)
    for wf in worker_files:
        shutil.move(os.path.join(INPUT_DIR, wf), os.path.join(arc, wf))
    print(f"\nArchived worker files to: {arc}")

print("Done.")
