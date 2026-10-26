"""
identify_offsets.py — Cross-reference dynamic offsets against Ghidra decompiled files

Reads each .c file ONCE, matches all offset patterns simultaneously, parallelized
across all CPU cores. ~50-100x faster than the naive per-offset scan.

Usage: python tools/identify_offsets.py [--summary monitor_output/summary.txt]
                                         [--decompiled decompiled_all,"Isolated Workspace/analyzed"]
                                         [--docs docs/10-vehicle-physics.md]
                                         [--workers 8]
"""

import os
import re
import sys
import argparse
import multiprocessing
from pathlib import Path
from concurrent.futures import ProcessPoolExecutor, as_completed

CONTEXT_LINES = 4

# ── parse dynamic offsets from summary ─────────────────────────────────────────

def load_dynamic_offsets(summary_path):
    offsets = {}
    in_section = False
    with open(summary_path, encoding='utf-8', errors='replace') as f:
        for line in f:
            if 'UNDOCUMENTED DYNAMIC FIELDS' in line:
                in_section = True
                continue
            if in_section and line.startswith('──'):
                break
            if in_section and line.startswith('0x'):
                parts = line.split(None, 2)
                if parts:
                    try:
                        off = int(parts[0], 16)
                        offsets[off] = parts[2].strip() if len(parts) > 2 else ''
                    except ValueError:
                        pass
    return offsets

# ── build combined regex for all offsets ───────────────────────────────────────

def build_pattern_map(offsets):
    # offset -> list of plain strings to search for
    pat_map = {}
    for offset in offsets:
        h = hex(offset)
        pats = [
            f'+ {h})',
            f'+ {h},',
            f'+ {h}]',
            f'+ {h} ',
            f'+{h})',
        ]
        if offset % 4 == 0:
            idx = offset // 4
            if idx > 9:
                pats.append(f'[{hex(idx)}]')
        pat_map[offset] = pats
    return pat_map

# ── worker: scan one file for all patterns ─────────────────────────────────────
# Must be top-level for multiprocessing pickling

def scan_file(args):
    filepath, pat_map, context_lines = args
    path = Path(filepath)
    try:
        text = path.read_text(encoding='utf-8', errors='replace')
    except Exception:
        return filepath, {}

    lines = text.splitlines()

    # extract func name from header (first 5 lines)
    func_name = path.stem
    for line in lines[:5]:
        m = re.search(r'Function:\s*(FUN_[0-9a-fA-F]+)', line)
        if m:
            func_name = m.group(1)
            break
        m = re.search(r'Strings:.*\[(.{1,60}?)\]', line)
        if m:
            func_name = m.group(1)
            break

    file_results = {}  # offset -> list of hit dicts

    for i, line in enumerate(lines):
        for offset, pats in pat_map.items():
            for pat in pats:
                if pat in line:
                    start = max(0, i - context_lines)
                    end   = min(len(lines), i + context_lines + 1)
                    hit = {
                        'line_no':  i + 1,
                        'match':    line.strip(),
                        'context':  lines[start:end],
                        'func':     func_name,
                        'filename': path.name,
                    }
                    file_results.setdefault(offset, []).append(hit)
                    break  # one pattern match per line per offset

    return filepath, file_results

# ── load known offsets from docs ────────────────────────────────────────────────

def load_known(docs_path):
    known = {}
    if not docs_path or not os.path.exists(docs_path):
        return known
    pat = re.compile(r'\+0x([0-9a-fA-F]+)\s*\|?\s*([^\|\n]+)')
    with open(docs_path, encoding='utf-8', errors='replace') as f:
        for line in f:
            m = pat.search(line)
            if m:
                off   = int(m.group(1), 16)
                label = m.group(2).strip().rstrip('|').strip()
                known[off] = label
    return known

# ── write report ───────────────────────────────────────────────────────────────

def write_report(out_path, results, dynamic, known, n_files):
    found     = {off for off, hits in results.items() if hits}
    not_found = {off for off, hits in results.items() if not hits}

    with open(out_path, 'w', encoding='utf-8') as f:
        def w(line=''):
            f.write(line + '\n')

        w("# Offset Identification Report")
        w(f"Decompiled files scanned : {n_files}")
        w(f"Dynamic undocumented offsets : {len(dynamic)}")
        w(f"Found in Ghidra : {len(found)}")
        w(f"Not found : {len(not_found)}")
        w()

        w(f"## Found in Ghidra ({len(found)} offsets)")
        w()
        for offset in sorted(found):
            samples = dynamic.get(offset, '')
            doc     = known.get(offset, '')
            w(f"### `{hex(offset)}` (dec {offset})")
            if doc:
                w(f"> Already in docs: {doc}")
            w(f"**Sample values:** {samples[:120]}")
            w()
            seen_files = set()
            for hit in results[offset][:10]:  # max 10 hits total
                fname = hit['filename']
                if fname not in seen_files:
                    seen_files.add(fname)
                    w(f"**`{fname}`** — `{hit['func']}`")
                w(f"  Line {hit['line_no']}: `{hit['match']}`")
                w("  ```c")
                for ctx_line in hit['context']:
                    w(f"  {ctx_line}")
                w("  ```")
            w()

        w("---")
        w(f"## Not found ({len(not_found)} offsets)")
        w("Accessed via pointer arithmetic or not in scanned files.")
        w()
        w("| Offset | Dec | Sample values |")
        w("|--------|-----|---------------|")
        for offset in sorted(not_found):
            w(f"| `{hex(offset)}` | {offset} | {dynamic.get(offset,'')[:80]} |")

# ── main ───────────────────────────────────────────────────────────────────────

def run(summary_path, decompiled_dirs, docs_path, out_path, workers):
    print(f"Loading offsets from {summary_path} ...")
    dynamic  = load_dynamic_offsets(summary_path)
    known    = load_known(docs_path)
    pat_map  = build_pattern_map(dynamic)
    print(f"  {len(dynamic)} offsets, {len(known)} documented")

    c_files = []
    for d in decompiled_dirs:
        c_files.extend(str(p) for p in Path(d).glob('*.c'))
    n_files = len(c_files)
    print(f"Scanning {n_files} files with {workers} workers ...")

    # aggregate: offset -> flat list of hit dicts
    results = {off: [] for off in dynamic}

    task_args = [(fp, pat_map, CONTEXT_LINES) for fp in c_files]

    done = 0
    with ProcessPoolExecutor(max_workers=workers) as pool:
        futures = {pool.submit(scan_file, a): a[0] for a in task_args}
        for future in as_completed(futures):
            _, file_results = future.result()
            for offset, hits in file_results.items():
                if offset in results:
                    results[offset].extend(hits)
            done += 1
            if done % 500 == 0 or done == n_files:
                print(f"  {done}/{n_files} files done ...")

    print(f"Writing {out_path} ...")
    write_report(out_path, results, dynamic, known, n_files)

    found = sum(1 for hits in results.values() if hits)
    print(f"Done. {found} offsets identified, {len(dynamic)-found} not found.")
    print(f"Report: {out_path}")


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--summary',   default='monitor_output/summary.txt')
    parser.add_argument('--decompiled',default='decompiled_all')
    parser.add_argument('--docs',      default='docs/10-vehicle-physics.md')
    parser.add_argument('--out',       default='monitor_output/identified_offsets.md')
    parser.add_argument('--workers',   type=int,
                        default=max(1, multiprocessing.cpu_count() - 1))
    args = parser.parse_args()

    dirs = [d.strip() for d in args.decompiled.split(',') if os.path.isdir(d.strip())]
    if not dirs:
        print(f"No valid dirs: {args.decompiled}")
        sys.exit(1)

    run(args.summary, dirs, args.docs, args.out, args.workers)
