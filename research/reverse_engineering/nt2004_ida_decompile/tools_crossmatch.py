# crossmatch.py — find NT2004 functions that are IDENTICAL to an F1C function
# (same shared engine, so a large fraction should be byte-for-byte same logic),
# so the LLM/skeleton-fill pipeline only spends effort on the functions that
# actually DIFFER between the two games.
#
# Method: normalize each decompiled .c body by alpha-renaming every
# address-derived token (sub_XXXXXX, off_XXXXXX, loc_XXXXXX, byte_/word_/dword_/
# unk_XXXXXX, raw 0x.. literals that look like addresses) to a canonical SYM#
# in order of first appearance within that function. This makes two functions
# that are logically identical but relocated to different addresses / renamed
# by IDA hash identical. Exact-match only (no fuzzy diff — cheap and precise;
# near-matches are a separate, smaller follow-up pass on the leftovers).
#
# Output: crossmatch.json
#   identical   : [{nt2004: "<file>", f1c: ["<file>", ...]}]   NT2004 funcs with
#                 >=1 byte-identical-normalized F1C counterpart (可能 multiple
#                 F1C funcs collide onto the same shape — list all)
#   nt2004_only : [<file>, ...]   NT2004 funcs with NO F1C match -> the ACTUAL
#                 delta to analyze first
#   stats
import re, os, json, hashlib, sys

F1C_DIR = r"%USERPROFILE%/Desktop/f1c_ida_decompiled/functions"
NT_DIR = r"%USERPROFILE%/Desktop/nt2004_ida_decompile/functions"
OUT = r"%USERPROFILE%/Desktop/nt2004_ida_decompile/crossmatch.json"

SYM_RE = re.compile(
    r'\b(?:sub|off|loc|byte|word|dword|qword|unk|asc|stru|dbl|flt|nullsub)_[0-9A-Fa-f]{5,8}\b'
    r'|\b0[xX][0-9A-Fa-f]{5,8}\b'
)
# generic hex-address-looking word without prefix (rare, e.g. bare "4A5D10")
BAREHEX_RE = re.compile(r'\b[0-9A-Fa-f]{6,8}\b')

def normalize(src):
    # drop the first line signature/addr-bearing decl noise is kept (types matter);
    # only address-ish tokens get canonicalized.
    canon = {}
    counter = [0]

    def repl(m):
        tok = m.group(0)
        if tok not in canon:
            canon[tok] = f"SYM{counter[0]}"
            counter[0] += 1
        return canon[tok]

    s = SYM_RE.sub(repl, src)
    s = BAREHEX_RE.sub(repl, s)
    # collapse whitespace so formatting differences don't matter
    s = re.sub(r'\s+', ' ', s).strip()
    return s

def hash_dir(d):
    buckets = {}
    for fn in os.listdir(d):
        if not fn.endswith('.c'):
            continue
        path = os.path.join(d, fn)
        try:
            with open(path, 'r', encoding='utf-8', errors='ignore') as f:
                src = f.read()
        except Exception:
            continue
        if not src.strip():
            continue
        norm = normalize(src)
        h = hashlib.sha1(norm.encode('utf-8')).hexdigest()
        buckets.setdefault(h, []).append(fn)
    return buckets

def main():
    print("[crossmatch] hashing F1C...", file=sys.stderr)
    f1c = hash_dir(F1C_DIR)
    print(f"[crossmatch] F1C: {sum(len(v) for v in f1c.values())} funcs, {len(f1c)} unique shapes", file=sys.stderr)

    print("[crossmatch] hashing NT2004...", file=sys.stderr)
    nt = hash_dir(NT_DIR)
    print(f"[crossmatch] NT2004: {sum(len(v) for v in nt.values())} funcs, {len(nt)} unique shapes", file=sys.stderr)

    identical = []
    nt_only = []
    for h, nt_files in nt.items():
        if h in f1c:
            for nf in nt_files:
                identical.append({"nt2004": nf, "f1c": f1c[h]})
        else:
            nt_only.extend(nt_files)

    result = {
        "_meta": {
            "f1c_functions": sum(len(v) for v in f1c.values()),
            "nt2004_functions": sum(len(v) for v in nt.values()),
        },
        "stats": {
            "nt2004_identical_to_f1c": len(identical),
            "nt2004_only_delta": len(nt_only),
        },
        "identical": identical,
        "nt2004_only": sorted(nt_only),
    }
    with open(OUT, 'w', encoding='utf-8') as f:
        json.dump(result, f, indent=1)
    print(f"[crossmatch] DONE identical={len(identical)} nt2004_only={len(nt_only)} -> {OUT}", file=sys.stderr)

if __name__ == "__main__":
    main()
