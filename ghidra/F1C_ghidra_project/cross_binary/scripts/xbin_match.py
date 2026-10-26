"""
xbin_match.py — cross-binary DELTA finder (isiMotor1 family vs F1C).

Given F1C reference fingerprints and ONE sibling binary's fingerprints,
classify every sibling function as:

  BYTE_EXACT  full_hash identical to an F1C func           -> duplicate
  BYTE_NORM   (size, head_bytes) identical to an F1C func  -> ~duplicate
  STRING      shares a 1:1 meaningful string with an F1C func -> same
  NOVEL       none of the above                            -> KEEP (delta)

Fingerprint inputs per binary (produced by IDA export, ida_*_export.py):
  <name>_byte_sigs.csv : address,name,size,head_bytes,full_hash
  <name>_strings.csv   : address,string,length,type,referencing_functions

Outputs:
  _delta/<sibling>_classified.csv  every sibling func + verdict
  _delta/<sibling>_novel.csv       NOVEL funcs only (feed to decompile+workers)

Pure stdlib. Zero tokens. Byte-level = decompiler-independent.
"""
import csv, sys, os, argparse
from collections import defaultdict

def mask(hexstr):
    """Zero relocated operands: E8/E9 rel32 targets + in-image absolute
    addresses (0x00400000-0x008fffff). Makes shared engine code that differs
    only by relocation hash-identical across binaries. BinDiff-lite."""
    try:
        b = bytearray.fromhex(hexstr)
    except ValueError:
        return hexstr
    i, n = 0, len(b)
    while i < n:
        if b[i] in (0xE8, 0xE9) and i + 5 <= n:
            b[i+1:i+5] = b'\x00\x00\x00\x00'; i += 5; continue
        if i + 4 <= n:
            v = b[i] | b[i+1] << 8 | b[i+2] << 16 | b[i+3] << 24
            if 0x00400000 <= v <= 0x008fffff:
                b[i:i+4] = b'\x00\x00\x00\x00'; i += 4; continue
        i += 1
    return bytes(b).hex()

def load_sigs(path):
    """addr -> (size, head_bytes, masked_head, full_hash)"""
    out = {}
    with open(path, newline='') as f:
        for r in csv.DictReader(f):
            head = r['head_bytes']
            out[r['address']] = (r['size'], head, mask(head), r['full_hash'])
    return out

def load_string_index(path):
    """string -> set(func_addr). Only meaningful strings kept."""
    idx = defaultdict(set)
    with open(path, newline='') as f:
        for r in csv.DictReader(f):
            s = r.get('string', '')
            refs = r.get('referencing_functions', '') or ''
            if not s or not refs:
                continue
            if len(s) <= 8 or s.startswith('1#') or s.startswith('_'):
                continue
            for a in refs.split(';'):
                a = a.strip()
                if a:
                    idx[s].add(a)
    return idx

def load_f1c_string_index(str_path, dataxref_path):
    """F1C strings have empty referencing_functions. Join string->addr
    (ida_strings) with global_addr->func (ida_data_xrefs) instead."""
    str_at = {}   # global_addr -> string
    with open(str_path, newline='') as f:
        for r in csv.DictReader(f):
            s = r.get('string', '')
            if s and len(s) > 8 and not s.startswith('1#') and not s.startswith('_'):
                str_at[r['address']] = s
    idx = defaultdict(set)  # string -> set(func_addr)
    with open(dataxref_path, newline='') as f:
        for r in csv.DictReader(f):
            g = r.get('global_addr', '')
            if g in str_at:
                idx[str_at[g]].add(r['func_addr'])
    return idx

def build_f1c_ref(sig_path, str_path, dataxref_path):
    sigs = load_sigs(sig_path)
    hash_idx = {}                 # full_hash -> f1c_addr (strongest, rare)
    mask_idx = {}                 # (size, masked_head) -> f1c_addr (primary)
    for addr, (size, head, mhead, h) in sigs.items():
        if h:
            hash_idx.setdefault(h, addr)
        mask_idx.setdefault((size, mhead), addr)
    # Prefer the refs column if present (re-exported f1c_strings.csv);
    # else fall back to the ida_strings + ida_data_xrefs join.
    str_idx = load_string_index(str_path)
    if not str_idx:
        str_idx = load_f1c_string_index(str_path, dataxref_path)
    # keep only 1:1 strings (referenced by exactly one f1c func) = strong anchor
    strong_str = {s: next(iter(a)) for s, a in str_idx.items() if len(a) == 1}
    return hash_idx, mask_idx, strong_str

def classify(sibling_sigs, sibling_strings, hash_idx, mask_idx, strong_str):
    # invert sibling strings: func_addr -> set(strings) restricted to 1:1-in-sibling
    sib_func_str = defaultdict(set)
    for s, addrs in sibling_strings.items():
        if len(addrs) == 1 and s in strong_str:
            sib_func_str[next(iter(addrs))].add(s)

    rows = []
    for addr, (size, head, mhead, h) in sibling_sigs.items():
        if h and h in hash_idx:
            rows.append((addr, size, 'BYTE_EXACT', hash_idx[h], f'MD5 identical {size}B'))
        elif (size, mhead) in mask_idx:
            rows.append((addr, size, 'BYTE_MASK', mask_idx[(size, mhead)], f'masked size+head match {size}B'))
        elif addr in sib_func_str:
            s = sorted(sib_func_str[addr])[0]
            rows.append((addr, size, 'STRING', strong_str[s], f'shared 1:1 string: {s[:40]}'))
        else:
            rows.append((addr, size, 'NOVEL', '', ''))
    return rows

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('sibling', help='sibling name, e.g. nascar03')
    ap.add_argument('--f1c-sigs', default='tools/f1c_byte_sigs.csv')
    ap.add_argument('--f1c-strings', default='tools/ida_strings.csv')
    ap.add_argument('--f1c-dataxrefs', default='tools/ida_data_xrefs.csv')
    ap.add_argument('--sib-sigs', help='default tools/<sibling>_byte_sigs.csv')
    ap.add_argument('--sib-strings', help='default tools/<sibling>_strings.csv')
    ap.add_argument('--out', default='cross_binary/_delta')
    a = ap.parse_args()

    sib_sigs_p = a.sib_sigs or f'tools/{a.sibling}_byte_sigs.csv'
    sib_str_p  = a.sib_strings or f'tools/{a.sibling}_strings.csv'

    hash_idx, mask_idx, strong_str = build_f1c_ref(a.f1c_sigs, a.f1c_strings, a.f1c_dataxrefs)
    sib_sigs = load_sigs(sib_sigs_p)
    sib_strings = load_string_index(sib_str_p)
    rows = classify(sib_sigs, sib_strings, hash_idx, mask_idx, strong_str)

    os.makedirs(a.out, exist_ok=True)
    cls_p = os.path.join(a.out, f'{a.sibling}_classified.csv')
    nov_p = os.path.join(a.out, f'{a.sibling}_novel.csv')
    with open(cls_p, 'w', newline='') as f:
        w = csv.writer(f); w.writerow(['sibling_addr','size','verdict','f1c_addr','anchor'])
        w.writerows(rows)
    with open(nov_p, 'w', newline='') as f:
        w = csv.writer(f); w.writerow(['sibling_addr','size','verdict','f1c_addr','anchor'])
        w.writerows([r for r in rows if r[2] == 'NOVEL'])

    from collections import Counter
    c = Counter(r[2] for r in rows)
    tot = len(rows)
    print(f'{a.sibling}: {tot} sibling funcs')
    for k in ('BYTE_EXACT','BYTE_MASK','STRING','NOVEL'):
        print(f'  {k:11s} {c.get(k,0):5d}  ({100*c.get(k,0)/tot:.1f}%)')
    matched = tot - c.get('NOVEL', 0)
    print(f'  matched-to-F1C: {matched} ({100*matched/tot:.1f}%)  novel: {c.get("NOVEL",0)}')
    print(f'  -> {cls_p}\n  -> {nov_p}')

if __name__ == '__main__':
    main()
