"""
bundle_small.py — pack small .c files from not_analyzed/ into bundle files.

Run this before generating worker batches to reduce file-read overhead.
DS reads one bundle file and produces one triage line per FILE section.

Bundle files are written to not_analyzed/bundles/.
Re-running regenerates bundles from whatever .c files still exist there.

Usage:
    python bundle_small.py [--max-size BYTES] [--per-bundle N]
"""

import os
import re
import sys
import shutil
import argparse

sys.stdout.reconfigure(encoding='utf-8', errors='replace')

WORKSPACE    = os.path.dirname(os.path.abspath(__file__))
NOT_ANALYZED = os.path.join(WORKSPACE, "not_analyzed")
BUNDLE_DIR   = os.path.join(NOT_ANALYZED, "bundles")

DEFAULT_MAX_SIZE  = 2000   # files under 2KB get bundled
DEFAULT_PER_BUNDLE = 50    # files per bundle


def read_file(path):
    for enc in ('utf-8', 'utf-8-sig', 'latin-1', 'cp1252'):
        try:
            return open(path, encoding=enc, errors='replace').read()
        except Exception:
            pass
    return ""


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--max-size',    type=int, default=DEFAULT_MAX_SIZE)
    parser.add_argument('--per-bundle',  type=int, default=DEFAULT_PER_BUNDLE)
    args = parser.parse_args()

    if not os.path.isdir(NOT_ANALYZED):
        print(f"not_analyzed/ not found: {NOT_ANALYZED}")
        sys.exit(1)

    # Collect small files
    small = []
    for fname in os.listdir(NOT_ANALYZED):
        if not fname.endswith('.c'):
            continue
        path = os.path.join(NOT_ANALYZED, fname)
        size = os.path.getsize(path)
        if size < args.max_size:
            small.append((size, path, fname))

    small.sort()   # smallest first — trivial stubs lead each bundle

    print(f"Small files (<{args.max_size}B): {len(small)}")
    print(f"Bundle size: {args.per_bundle} files/bundle")
    n_bundles = (len(small) + args.per_bundle - 1) // args.per_bundle
    print(f"Bundles to create: {n_bundles}")

    # Clear and recreate bundle dir
    if os.path.isdir(BUNDLE_DIR):
        shutil.rmtree(BUNDLE_DIR)
    os.makedirs(BUNDLE_DIR)

    written = 0
    for bundle_idx in range(n_bundles):
        chunk = small[bundle_idx * args.per_bundle : (bundle_idx + 1) * args.per_bundle]
        bundle_name = f"bundle_{bundle_idx:04d}.bundle"
        bundle_path = os.path.join(BUNDLE_DIR, bundle_name)

        lines = []
        for size, path, fname in chunk:
            content = read_file(path)
            line_count = content.count('\n') + 1
            lines.append(f"===== FILE: {fname} ({line_count} lines, {size}B) =====\n")
            lines.append(content.rstrip('\n'))
            lines.append(f"\n===== END: {fname} =====\n\n")

        with open(bundle_path, 'w', encoding='utf-8', errors='replace') as f:
            f.write(''.join(lines))

        written += 1

    print(f"Written {written} bundle files to: {BUNDLE_DIR}")
    print(f"Large files (>={args.max_size}B) in not_analyzed/: "
          f"{len([f for f in os.listdir(NOT_ANALYZED) if f.endswith('.c') and os.path.getsize(os.path.join(NOT_ANALYZED, f)) >= args.max_size])}")


if __name__ == '__main__':
    main()
