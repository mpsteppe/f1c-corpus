r"""
build_delta.py — select the "functions we do NOT know" delta per sibling game
and stage their .c files into a per-game F1C-grade pipeline.

Delta = Tier1 (TRUE_NOVEL or string-absent feature) UNION
        Tier2 (not CLEARED, size>=128, and LOW_ANCHOR or weak-REVIEW score<0.30).
Excludes everything proven 1:1 with F1C (BYTE match or source CLEARED).

Per game creates:
  source_material/<game>/pipeline/{not_analyzed, analyzed, output, prompts}
  source_material/<game>/pipeline/not_analyzed/*.c   (staged delta files)
  cross_binary/_delta/<name>_analysis_delta.csv       (the ledger)
"""
import csv, os, shutil, glob, re

GAMES = {
  'f1_2002_full': ('source_material/F1 2002',              'f1_2002'),
  'nascar03':     ('source_material/Nascar Thunder 2003',  'nascar03'),
  'nascar04':     ('source_material/Nascar Thunder 2004',  'nascar04'),
  'scgt':         ('source_material/Sports Car GT',        'scgt'),
}
ROOT = r'%USERPROFILE%\Desktop\F1C_ghidra_project'

def load(name, featname):
    dec, score = {}, {}
    for r in csv.DictReader(open(f'cross_binary/_delta/{name}_srcmatch.csv', newline='')):
        a = r['sibling_addr'].lower(); dec[a] = r['decision']; score[a] = float(r['score'])
    size = {}
    for r in csv.DictReader(open(f'cross_binary/_delta/{name}_classified.csv', newline='')):
        if r['verdict'] == 'NOVEL':
            size[r['sibling_addr'].lower()] = int(r['size'])
    feats = set()
    fp = f'cross_binary/_delta/featdiff_{featname}_not_f1c.csv'
    if os.path.exists(fp):
        for r in csv.DictReader(open(fp, newline='')):
            feats.add(r['addr'].lower())
    return dec, score, size, feats

def select(dec, score, size, feats):
    rows = []
    for a, sz in size.items():
        d = dec.get(a, '?'); s = score.get(a, 0.0)
        if d == 'CLEARED':
            continue
        tier1 = (d == 'TRUE_NOVEL') or (a in feats)
        tier2 = sz >= 128 and (d == 'LOW_ANCHOR' or (d == 'REVIEW' and s < 0.30))
        if tier1 or tier2:
            rows.append((a, sz, 'T1' if tier1 else 'T2', d, f'{s:.3f}'))
    rows.sort(key=lambda r: (r[2], -r[1]))
    return rows

def main():
    grand = 0
    for name, (gdir, featname) in GAMES.items():
        dec, score, size, feats = load(name, featname)
        rows = select(dec, score, size, feats)
        # index by lowercase 8-hex addr -> source .c path
        srcmap = {}
        for p in glob.glob(os.path.join(gdir, 'decompiled', '*.c')):
            m = re.search(r'0x([0-9a-fA-F]+)__', os.path.basename(p))
            if m:
                srcmap['0x' + m.group(1).lower().zfill(8)] = p
        stage = os.path.join(gdir, 'pipeline', 'not_analyzed')
        for sub in ('not_analyzed', 'analyzed', 'output', 'prompts'):
            os.makedirs(os.path.join(gdir, 'pipeline', sub), exist_ok=True)
        staged = 0
        for a, sz, tier, d, s in rows:
            src = srcmap.get(a)
            if src:
                shutil.copy2(src, os.path.join(stage, os.path.basename(src)))
                staged += 1
        with open(f'cross_binary/_delta/{name}_analysis_delta.csv', 'w', newline='') as f:
            w = csv.writer(f); w.writerow(['addr', 'size', 'tier', 'src_decision', 'score'])
            w.writerows(rows)
        t1 = sum(1 for r in rows if r[2] == 'T1')
        print(f'{name:13} delta={len(rows):5} (T1={t1}, T2={len(rows)-t1})  staged .c={staged} -> {stage}')
        grand += len(rows)
    print(f'\nTOTAL delta functions to document: {grand}')

if __name__ == '__main__':
    main()
