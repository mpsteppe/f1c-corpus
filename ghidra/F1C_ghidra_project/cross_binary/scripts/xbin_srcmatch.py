r"""
xbin_srcmatch.py — SECOND-LAYER matcher on decompiled .c text.

Byte-matching (xbin_match.py) misses functions that do the same job but
compile differently (older compiler, different inlining). This clears those
by comparing a COMPILER-INDEPENDENT semantic fingerprint of the decompiled
source: numeric constants + string literals + named API calls + structure.

Ground truth for calibration = the byte-matched pairs already in
_delta/<name>_classified.csv (verdict BYTE_EXACT/BYTE_MASK/STRING). Those are
known-same functions; their source-similarity sets the CLEAR threshold.

Output _delta/<name>_srcmatch.csv:
  sibling_addr,size,decision,best_f1c,score,anchor
  decision = CLEARED (F1C has equivalent) | REVIEW | TRUE_NOVEL

Usage:
  python cross_binary/scripts/xbin_srcmatch.py f1_2002_full \
    "source_material/F1 2002/decompiled" \
    --classified cross_binary/_delta/f1_2002_full_classified.csv
"""
import csv, re, os, sys, argparse, glob, random
from collections import defaultdict

ADDR_RE = re.compile(r'0x([0-9a-fA-F]{6,8})__')
HEX_RE  = re.compile(r'0x[0-9a-fA-F]+')
DEC_RE  = re.compile(r'(?<![\w.])\d{3,}(?![\w.])')          # decimals >=100
STR_RE  = re.compile(r'"((?:[^"\\]|\\.){3,})"')             # string literals >=3 chars
CALL_RE = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]{2,})\s*\(')  # ident before (
KW = {'if','while','for','switch','return','sizeof','else','do','case','goto'}
# decompiler-local names that differ across binaries -> not usable as anchors
LOCAL_RE = re.compile(r'^(sub_|loc_|off_|unk_|dword_|word_|byte_|qword_|flt_|dbl_|'
                      r'j_|nullsub_|jpt_|asc_|a[A-Z]|v\d+$|dw\d+)', re.I)

def _keep_hex(h):
    """drop in-image address constants (differ across binaries); keep magic
    numbers, struct offsets, float bit-patterns."""
    try:
        v = int(h, 16)
    except ValueError:
        return False
    return not (0x400000 <= v <= 0x8fffff)

def fingerprint(text):
    consts = set(h for h in HEX_RE.findall(text) if _keep_hex(h))
    consts |= set('#' + m for m in DEC_RE.findall(text))
    strs   = set(STR_RE.findall(text))
    apis   = set(c for c in CALL_RE.findall(text)
                 if c not in KW and not LOCAL_RE.match(c))
    struct = (text.count(' if '), text.count('while') + text.count(' for '),
              text.count('switch'), text.count('='), text.count('return'))
    tokens = consts | strs | apis                    # combined anchor set
    return tokens, struct

import math

def build_idf(fps):
    """token -> idf, over the reference (F1C) corpus."""
    df = defaultdict(int)
    for _, (toks, _) in fps.items():
        for t in toks:
            df[t] += 1
    N = len(fps)
    return {t: math.log(N / c) for t, c in df.items()}, df

def tfidf_cos(sib_toks, f1c_toks, idf):
    """cosine over shared IDF-weighted anchors. Unknown tokens (not in F1C
    idf) get a high default weight so rare sibling-only anchors still count."""
    default = math.log(6000)
    shared = sib_toks & f1c_toks
    if not shared:
        return 0.0
    num = sum(idf.get(t, default) ** 2 for t in shared)
    da = sum(idf.get(t, default) ** 2 for t in sib_toks) ** .5
    db = sum(idf.get(t, default) ** 2 for t in f1c_toks) ** .5
    return num / (da * db) if da and db else 0.0

def load_corpus(d):
    fps = {}
    for p in glob.glob(os.path.join(d, '*.c')):
        m = ADDR_RE.search(os.path.basename(p))
        if not m:
            continue
        addr = '0x' + m.group(1).lower().zfill(8)
        try:
            text = open(p, encoding='utf-8', errors='replace').read()
        except OSError:
            continue
        fps[addr] = fingerprint(text)
    return fps

def build_index(fps, df, max_df=300):
    """token -> set(addr). Skip ubiquitous tokens (df>max_df) as anchors —
    they never discriminate and blow up candidate sets."""
    idx = defaultdict(set)
    for addr, (toks, _) in fps.items():
        for t in toks:
            if df.get(t, 1) <= max_df:
                idx[t].add(addr)
    return idx

def score(sib_fp, f1c_fp, idf):
    return tfidf_cos(sib_fp[0], f1c_fp[0], idf)

def best_match(sib_addr, sib_fp, f1c_fps, f1c_idx, idf):
    cand = set()
    for t in sib_fp[0]:
        holders = f1c_idx.get(t)
        if holders:
            cand |= holders
    best_a, best_s = None, 0.0
    for a in cand:
        s = score(sib_fp, f1c_fps[a], idf)
        if s > best_s:
            best_s, best_a = s, a
    return best_a, best_s

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('name')
    ap.add_argument('sib_dir')
    ap.add_argument('--f1c-dir', default='analysis_pipeline/analyzed')
    ap.add_argument('--classified', required=True)
    ap.add_argument('--out', default=None)
    a = ap.parse_args()

    print('loading F1C corpus...'); f1c = load_corpus(a.f1c_dir)
    print(f'  {len(f1c)} F1C funcs')
    idf, df = build_idf(f1c)
    f1c_idx = build_index(f1c, df)
    print('loading sibling corpus...'); sib = load_corpus(a.sib_dir)
    print(f'  {len(sib)} sibling funcs')

    matched_pairs, novels = [], []
    with open(a.classified, newline='') as f:
        for r in csv.DictReader(f):
            sa = r['sibling_addr'].lower()
            if r['verdict'] == 'NOVEL':
                novels.append((sa, r['size']))
            elif r['f1c_addr']:
                matched_pairs.append((sa, r['f1c_addr'].lower()))

    MIN_ANCHORS = 4                     # below this, source-matching is unreliable
    def anchored(fp): return len(fp[0]) >= MIN_ANCHORS

    # --- calibrate on known-same pairs that HAVE enough anchors ---
    sims = []
    for sa, fa in matched_pairs:
        if sa in sib and fa in f1c and anchored(sib[sa]) and anchored(f1c[fa]):
            sims.append(score(sib[sa], f1c[fa], idf))
    sims.sort()
    def pct(p): return sims[int(p * (len(sims) - 1))] if sims else 0.0
    # random non-pairs for separation check
    rnd = []
    fa_list = [x for x in f1c if anchored(f1c[x])]
    anv = [sa for sa, _ in novels if sa in sib and anchored(sib[sa])]
    for sa in random.sample(anv, min(500, len(anv))):
        rnd.append(score(sib[sa], f1c[random.choice(fa_list)], idf))
    rnd.sort()
    rnd_p95 = rnd[int(0.95 * (len(rnd) - 1))] if rnd else 0.0
    clear_thr = max(pct(0.25), rnd_p95 + 0.05, 0.15)    # cleanly above random
    review_thr = max(rnd_p95, 0.08)
    print(f'\ncalibration on {len(sims)} anchored known-same pairs:')
    print(f'  known-match score  p25={pct(.25):.3f} median={pct(.5):.3f} p75={pct(.75):.3f}')
    print(f'  random-pair score  median={rnd[len(rnd)//2]:.3f} p95={rnd_p95:.3f}')
    print(f'  CLEAR>= {clear_thr:.3f}   REVIEW>= {review_thr:.3f}   (min {MIN_ANCHORS} anchors)')

    # --- classify novels against F1C ---
    out = a.out or f'cross_binary/_delta/{a.name}_srcmatch.csv'
    rows = []
    for sa, size in novels:
        if sa not in sib:
            rows.append((sa, size, 'NO_SRC', '', '0', '')); continue
        if not anchored(sib[sa]):
            rows.append((sa, size, 'LOW_ANCHOR', '', '0', '')); continue
        ba, bs = best_match(sa, sib[sa], f1c, f1c_idx, idf)
        if bs >= clear_thr:
            dec = 'CLEARED'
        elif bs >= review_thr:
            dec = 'REVIEW'
        else:
            dec = 'TRUE_NOVEL'
        shared = ';'.join(list(sib[sa][0] & f1c[ba][0])[:5]) if ba else ''
        rows.append((sa, size, dec, ba or '', f'{bs:.3f}', shared))
    with open(out, 'w', newline='') as f:
        w = csv.writer(f); w.writerow(['sibling_addr','size','decision','best_f1c','score','shared_anchors'])
        w.writerows(rows)

    from collections import Counter
    c = Counter(r[2] for r in rows)
    print(f'\n{len(rows)} byte-novels re-checked against F1C source:')
    for k in ('CLEARED','REVIEW','TRUE_NOVEL','LOW_ANCHOR','NO_SRC'):
        print(f'  {k:11s} {c.get(k,0):5d}')
    print(f'  -> {out}')
    print(f'\nCLEARED = F1C has an equivalent function (byte missed it). '
          f'TRUE_NOVEL = genuinely absent from F1C.')

if __name__ == '__main__':
    main()
