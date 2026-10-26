r"""
merge_delta.py — per-game merge (mirrors F1C merge_to_docs.py principles).

Reads pipeline/output/worker_*.md for one game:
  - triage lines  -> docs/decompiled_index.md
  - full entries  -> routed to docs/NN by <!-- target: --> comment
  - dedup by '## sub_' header, archives worker files, moves processed .c to analyzed/

Usage: python cross_binary/scripts/merge_delta.py "source_material/F1 2002"
"""
import os, re, sys, glob, shutil, time

def read(p):
    for enc in ('utf-8', 'utf-8-sig', 'cp1252', 'latin-1'):
        try: return open(p, encoding=enc, errors='replace').read()
        except OSError: return ''
    return ''

def existing(path):
    if not os.path.exists(path): return set()
    return set(m.lower() for m in re.findall(r'^#{2,3} sub_([0-9a-fA-F]+)', read(path), re.M))

def main():
    gdir = sys.argv[1]
    docs = os.path.join(gdir, 'docs')
    outdir = os.path.join(gdir, 'pipeline', 'output')
    index = os.path.join(docs, 'decompiled_index.md')
    analyzed = os.path.join(gdir, 'pipeline', 'analyzed')
    notdir = os.path.join(gdir, 'pipeline', 'not_analyzed')
    os.makedirs(analyzed, exist_ok=True)
    tri_add, full_add = 0, 0

    for wf in sorted(glob.glob(os.path.join(outdir, 'worker_*.md'))):
        content = read(wf)
        # triage
        tri = re.findall(r'^\| 0x[0-9a-fA-F]+.*$', content.split('=== FULL ENTRIES ===')[0], re.M)
        if tri:
            open(index, 'a', encoding='utf-8').write('\n'.join(tri) + '\n'); tri_add += len(tri)
        # full entries, split on target comment / header
        body = content.split('=== FULL ENTRIES ===')[-1]
        # find (target, addr, text) blocks
        parts = re.split(r'(<!-- target:\s*(docs/[\w\-\.]+)\s*-->)', body)
        # walk: parts = [pre, marker, target, text, marker, target, text, ...]
        i = 1
        cur_target = '40-gameplay.md'
        while i < len(parts):
            cur_target = os.path.basename(parts[i+1]); text = parts[i+2]
            for m in re.finditer(r'(^#{2,3} sub_([0-9a-fA-F]+).*?)(?=^#{2,3} sub_|\Z)', text, re.M | re.S):
                addr = m.group(2).lower(); entry = m.group(1).rstrip()
                tgt = os.path.join(docs, cur_target)
                if addr in existing(tgt):
                    continue
                open(tgt, 'a', encoding='utf-8').write('\n\n' + entry + '\n')
                full_add += 1
                # move processed .c
                for c in glob.glob(os.path.join(notdir, f'0x{addr.zfill(8)}__*.c')):
                    shutil.move(c, os.path.join(analyzed, os.path.basename(c)))
            i += 3
        # archive worker file
        arch = os.path.join(outdir, 'archive', time.strftime('%Y%m%d_%H%M%S'))
        os.makedirs(arch, exist_ok=True)
        shutil.move(wf, os.path.join(arch, os.path.basename(wf)))

    print(f'{gdir}: +{tri_add} triage, +{full_add} full entries merged into {docs}')

if __name__ == '__main__':
    main()
