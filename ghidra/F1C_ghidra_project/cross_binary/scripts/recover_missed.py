r"""
recover_missed.py — stage functions whose STRINGS are absent from F1C but were
excluded from the delta (false byte-matches / false source-clears). String-absence
is exact evidence of novelty and overrides byte/source matching.

Scans every function-with-strings per game, flags >=80% F1C-absent meaningful
strings, stages any not already in not_analyzed/analyzed, appends to the ledger.
"""
import csv, re, os, glob, shutil
from collections import defaultdict

ROOT = r'%USERPROFILE%\Desktop\F1C_ghidra_project'
def norm(s): return re.sub(r'\s+', ' ', s).strip().lower()
ROSTER = re.compile(r"^[A-Z0-9 .'-]{3,}$")
GAMES = {
  'f1_2002_full': ('source_material/F1 2002', 'cross_binary/_fingerprints/f1_2002_full_strings.csv',
                   'cross_binary/_fingerprints/f1_2002_full_byte_sigs.csv'),
  'nascar03': ('source_material/Nascar Thunder 2003', 'tools/nascar03_strings.csv', 'tools/nascar03_byte_sigs.csv'),
  'nascar04': ('source_material/Nascar Thunder 2004', 'tools/nascar04_strings.csv', 'tools/nascar04_byte_sigs.csv'),
  'scgt': ('source_material/Sports Car GT', 'cross_binary/_fingerprints/scgt_strings.csv',
           'cross_binary/_fingerprints/scgt_byte_sigs.csv'),
}

f1c = set(norm(r['string']) for r in csv.DictReader(open('cross_binary/_fingerprints/f1c_strings.csv', newline='')))

total = 0
for name, (gdir, spath, sigpath) in GAMES.items():
    sizes = {}
    for r in csv.DictReader(open(sigpath, newline='')):
        sizes[r['address'].lower()] = int(r['size'])
    fs = defaultdict(list)
    for r in csv.DictReader(open(spath, newline='')):
        for a in (r.get('referencing_functions') or '').split(';'):
            a = a.strip().lower()
            if a:
                fs[a].append(r['string'])
    stage = os.path.join(gdir, 'pipeline', 'not_analyzed')
    analyzed = os.path.join(gdir, 'pipeline', 'analyzed')
    have = set()
    for d in (stage, analyzed):
        for p in glob.glob(os.path.join(d, '*.c')):
            m = re.search(r'0x([0-9a-fA-F]+)__', os.path.basename(p))
            if m: have.add('0x' + m.group(1).lower().zfill(8))
    srcmap = {}
    for p in glob.glob(os.path.join(gdir, 'decompiled', '*.c')):
        m = re.search(r'0x([0-9a-fA-F]+)__', os.path.basename(p))
        if m: srcmap['0x' + m.group(1).lower().zfill(8)] = p
    added = []
    for a, strs in fs.items():
        aa = a if a.startswith('0x') else '0x' + a
        aa = '0x' + aa[2:].zfill(8)
        mean = [s for s in strs if len(s) > 6 and not s.startswith('1#') and not ROSTER.match(s)]
        if len(mean) < 2:
            continue
        absent = [s for s in mean if norm(s) not in f1c]
        if len(absent) / len(mean) >= 0.8 and len(absent) >= 2 and aa not in have:
            src = srcmap.get(aa)
            if src:
                shutil.copy2(src, os.path.join(stage, os.path.basename(src)))
                added.append((aa, sizes.get(aa, 0)))
    # append to ledger as tier R (recovered)
    ledger = f'cross_binary/_delta/{name}_analysis_delta.csv'
    with open(ledger, 'a', newline='') as f:
        w = csv.writer(f)
        for a, sz in added:
            w.writerow([a, sz, 'R', 'STRING_ABSENT', '0'])
    print(f'{name}: recovered + staged {len(added)} string-absent functions')
    total += len(added)
print(f'\nTOTAL recovered: {total}')
