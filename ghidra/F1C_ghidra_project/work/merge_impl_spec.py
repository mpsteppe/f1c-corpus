"""
Merge impl_spec worker outputs into docs/30-impl-specs/.

Each worker_X.md may contain one or more system specs separated by `# Implementation Spec:` headers.
Each spec is written to its own file: 30-impl-specs/NN-system-name-spec.md

Usage:
    python work/merge_impl_spec.py [--dry-run]
"""

import os, re, sys, shutil

WORKSPACE     = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INPUT_DIR     = os.path.join(WORKSPACE, 'analysis_pipeline', 'output', 'impl_spec')
OUTPUT_DIR    = os.path.join(WORKSPACE, 'docs', '30-impl-specs')
ARCHIVE_DIR   = os.path.join(WORKSPACE, 'analysis_pipeline', 'output', 'archive')

DRY_RUN = '--dry-run' in sys.argv

os.makedirs(OUTPUT_DIR, exist_ok=True)

def slugify(title):
    """Convert system name to file slug."""
    s = title.lower()
    s = re.sub(r'[^a-z0-9]+', '-', s)
    return s.strip('-')


def split_specs(content):
    """Split worker output into individual specs by `# Implementation Spec:` header."""
    parts = re.split(r'(?=^# Implementation Spec:)', content, flags=re.MULTILINE)
    specs = []
    for part in parts:
        part = part.strip()
        if not part or not part.startswith('# Implementation Spec:'):
            continue
        m = re.match(r'^# Implementation Spec:\s*(.+)', part)
        if m:
            title = m.group(1).strip()
            specs.append((title, part))
    return specs


# Collect all worker files
worker_files = sorted(
    f for f in os.listdir(INPUT_DIR)
    if re.match(r'worker_[A-T]\.md$', f)
) if os.path.isdir(INPUT_DIR) else []

if not worker_files:
    print(f"No worker_X.md files found in {INPUT_DIR}")
    sys.exit(1)

all_specs = []
for wf in worker_files:
    path = os.path.join(INPUT_DIR, wf)
    content = open(path, encoding='utf-8', errors='ignore').read()
    specs = split_specs(content)
    print(f"{wf}: {len(specs)} spec(s) found")
    all_specs.extend(specs)

print(f"\nTotal specs: {len(all_specs)}")

# Write each spec to its own file
for i, (title, content) in enumerate(all_specs, 1):
    slug = slugify(title)
    fname = f"{i:02d}-{slug}-spec.md"
    out_path = os.path.join(OUTPUT_DIR, fname)
    if DRY_RUN:
        print(f"  [DRY RUN] would write: docs/30-impl-specs/{fname}  ({len(content)} chars)")
    else:
        with open(out_path, 'w', encoding='utf-8') as f:
            f.write(content + '\n')
        print(f"  wrote: docs/30-impl-specs/{fname}")

if not DRY_RUN:
    # Archive worker files
    import datetime
    ts = datetime.datetime.now().strftime('%Y%m%d_%H%M%S')
    arc = os.path.join(ARCHIVE_DIR, f'impl_spec_{ts}')
    os.makedirs(arc, exist_ok=True)
    for wf in worker_files:
        shutil.move(os.path.join(INPUT_DIR, wf), os.path.join(arc, wf))
    print(f"\nArchived worker files to: {arc}")

print("Done.")
