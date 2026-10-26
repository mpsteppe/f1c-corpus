r"""
xbin_dedup.py — collapse per-sibling NOVEL lists into one unified delta.

A function shared across siblings (e.g. present in F1-2002-demo AND NASCAR03)
but absent from F1C is ONE engine function F1C lacks. Cluster novels by their
masked byte signature (compiler-generation-stable within the 2002-04 cluster)
so we hand workers each engine function once, ranked by how many siblings
carry it (more siblings = more confidently real engine code, not game-specific).

Usage:
  python cross_binary/scripts/xbin_dedup.py \
    demo:cross_binary/_fingerprints/f1_2002_demo_byte_sigs.csv:cross_binary/_delta/f1_2002_demo_novel.csv \
    nascar03:tools/nascar03_byte_sigs.csv:cross_binary/_delta/nascar03_novel.csv \
    nascar04:tools/nascar04_byte_sigs.csv:cross_binary/_delta/nascar04_novel.csv

Output: cross_binary/_delta/unified_novel.csv
  cluster_key,size,n_siblings,siblings,addrs
Only same-compiler-generation siblings should be passed (see _README caveat).
"""
import csv, sys, os
from collections import defaultdict
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xbin_match import mask

def load_sig_map(path):
    m = {}
    with open(path, newline='') as f:
        for r in csv.DictReader(f):
            m[r['address']] = (r['size'], mask(r['head_bytes']))
    return m

def load_novel_addrs(path):
    a = set()
    with open(path, newline='') as f:
        for r in csv.DictReader(f):
            a.add(r['sibling_addr'])
    return a

def main():
    specs = sys.argv[1:]
    if not specs:
        print(__doc__); sys.exit(1)
    clusters = defaultdict(lambda: defaultdict(list))  # key -> {sibling: [addrs]}
    for spec in specs:
        name, sig_path, nov_path = spec.split(':', 2)
        sigs = load_sig_map(sig_path)
        for addr in load_novel_addrs(nov_path):
            if addr not in sigs:
                continue
            size, mhead = sigs[addr]
            key = f'{size}:{mhead}'
            clusters[key][name].append(addr)

    out = 'cross_binary/_delta/unified_novel.csv'
    rows = []
    for key, sibs in clusters.items():
        size = key.split(':', 1)[0]
        addrs = ';'.join(f'{s}={",".join(a)}' for s, a in sorted(sibs.items()))
        rows.append((key[:80], size, len(sibs), '|'.join(sorted(sibs)), addrs))
    rows.sort(key=lambda r: (-r[2], -int(r[1])))  # most-shared, then largest first
    with open(out, 'w', newline='') as f:
        w = csv.writer(f); w.writerow(['cluster_key','size','n_siblings','siblings','addrs'])
        w.writerows(rows)

    from collections import Counter
    dist = Counter(r[2] for r in rows)
    print(f'unified novel clusters: {len(rows)}  -> {out}')
    for n in sorted(dist, reverse=True):
        print(f'  in {n} sibling(s): {dist[n]} clusters')
    multi = sum(v for k, v in dist.items() if k >= 2)
    print(f'  cross-confirmed (>=2 siblings): {multi}  <- highest-priority engine funcs F1C lacks')

if __name__ == '__main__':
    main()
