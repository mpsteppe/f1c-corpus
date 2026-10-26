r"""
xbin_feature_diff.py — SYMMETRIC feature diff between two isiMotor1 binaries.

Same architecture, different "bricks". Produces TWO bins:
  A_only : functions in A whose string anchors are ABSENT from B  (A has, B lacks)
  B_only : functions in B whose string anchors are ABSENT from A  (B has, A lacks)

A function is a portable FEATURE candidate when its meaningful string literals
(config keys, filenames, UI labels, asserts) don't appear anywhere in the other
binary. String-less helper functions are ignored — they aren't features.

Inputs per binary: <name>_classified.csv (novel list + size) + <name>_strings.csv
(func->strings, and the whole string set). Classified files come from xbin_match.py
run in BOTH directions.

Usage:
  python cross_binary/scripts/xbin_feature_diff.py \
    f1c:cross_binary/_fingerprints/f1c_strings.csv:cross_binary/_delta/f1c_vs_f1_2002_classified.csv \
    f1_2002:cross_binary/_fingerprints/f1_2002_full_strings.csv:cross_binary/_delta/f1_2002_full_classified.csv
"""
import csv, re, sys
from collections import defaultdict

def norm(s): return re.sub(r'\s+', ' ', s).strip().lower()
ROSTER = re.compile(r'^[A-Z0-9 .\'-]{3,}$')          # ALLCAPS roster/season data → skip
SRCFILE = re.compile(r'([A-Za-z0-9_]+\.(?:cpp|c|h))', re.I)

def load(spec):
    name, strings_csv, classified = spec.split(':', 2)
    func_strs = defaultdict(list)   # addr -> [strings]
    all_strs = set()                # every normalized string in this binary
    for r in csv.DictReader(open(strings_csv, newline='')):
        s = r['string']
        all_strs.add(norm(s))
        for a in (r.get('referencing_functions') or '').split(';'):
            a = a.strip().lower()
            if a:
                func_strs[a].append(s)
    novels = {}                     # addr -> size (byte-novel = absent at byte level)
    for r in csv.DictReader(open(classified, newline='')):
        if r['verdict'] == 'NOVEL':
            novels[r['sibling_addr'].lower()] = int(r['size'])
    return name, func_strs, all_strs, novels

def exclusive(name, func_strs, novels, other_strs):
    """funcs in `name` whose meaningful strings are >=80% absent from other binary."""
    out = []
    for a, sz in novels.items():
        strs = [s for s in func_strs.get(a, []) if len(s) > 6 and not s.startswith('1#')]
        meaningful = [s for s in strs if not ROSTER.match(s)]
        if len(meaningful) < 2:
            continue
        absent = [s for s in meaningful if norm(s) not in other_strs]
        if len(absent) / len(meaningful) >= 0.8 and len(absent) >= 2:
            src = ''
            for s in strs:
                m = SRCFILE.findall(s)
                if m: src = m[0].lower(); break
            out.append((sz, a, src, ' | '.join(absent[:5])))
    out.sort(key=lambda r: -r[0])
    return out

def main():
    if len(sys.argv) != 3:
        print(__doc__); sys.exit(1)
    A = load(sys.argv[1]); B = load(sys.argv[2])
    (an, af, aset, anov) = A; (bn, bf, bset, bnov) = B

    a_only = exclusive(an, af, anov, bset)   # A has, B lacks
    b_only = exclusive(bn, bf, bnov, aset)   # B has, A lacks

    for label, rows, other in ((f'{an} HAS / {bn} LACKS', a_only, bn),
                                (f'{bn} HAS / {an} LACKS', b_only, an)):
        print(f"\n===== {label} : {len(rows)} feature functions =====")
        by_src = defaultdict(list)
        for sz, a, src, st in rows:
            by_src[src or '(no src file)'].append((sz, a, st))
        for src in sorted(by_src, key=lambda s: -sum(x[0] for x in by_src[s])):
            tot = sum(x[0] for x in by_src[src])
            print(f"  [{src}]  {len(by_src[src])} funcs, {tot}B")
            for sz, a, st in sorted(by_src[src], reverse=True)[:6]:
                print(f"      {sz:>6}B {a}  {st[:66]}")

    # write CSVs (names carry BOTH binaries so runs don't clobber each other)
    for tag, rows in ((f'{an}_not_{bn}', a_only), (f'{bn}_not_{an}', b_only)):
        p = f'cross_binary/_delta/featdiff_{tag}.csv'
        with open(p, 'w', newline='') as f:
            w = csv.writer(f); w.writerow(['size', 'addr', 'src_file', 'exclusive_strings'])
            w.writerows(rows)
        print(f"  -> {p}")

if __name__ == '__main__':
    main()
