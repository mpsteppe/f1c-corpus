# crossmatch2.py — second-tier match for functions the exact-hash pass (crossmatch.py)
# missed. Different compiler build (2002 F1C vs 2003 NT2004) means logically-identical
# functions can still get different Hex-Rays var numbering / instruction order, so the
# text-hash approach undercounts. This pass matches on a STRUCTURAL fingerprint instead
# of text: the field-offset access pattern (base/off/R-W) + guard ops + callee/global
# counts + body line count, all already extracted deterministically into
# skeleton_facts_all.json. Two functions sharing that fingerprint are almost certainly
# the same original function even if the decompiled text differs.
#
# Reads crossmatch.json's leftovers, only operates on:
#   - NT2004 funcs not already in "identical"
#   - F1C funcs not already consumed as a match target
# Output: crossmatch2.json (same shape + a "confidence" note), and a merged
# gtr2_still_unmatched.json = the real analysis backlog.
import json, os

F1C_FACTS = r"%USERPROFILE%/Desktop/F1/f1c_ida_decompiled/skeleton_facts_all.json"
NT_FACTS = r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/skeleton_facts_all.json"
F1C_DIR = r"%USERPROFILE%/Desktop/F1/f1c_ida_decompiled/functions"
NT_DIR = r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/functions"
CROSSMATCH1 = r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/crossmatch.json"
OUT = r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/crossmatch2.json"
FINAL_OUT = r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/gtr2_still_unmatched.json"


def line_count(path):
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as f:
            return sum(1 for _ in f)
    except Exception:
        return -1


def fingerprint(facts, addr8, line_count_val):
    fields = tuple(sorted(
        (f.get('base', ''), f.get('off_hex', ''), f.get('rw', ''))
        for f in facts.get('fields', [])
    ))
    guards = tuple(sorted(
        (g.get('base', ''), g.get('off', g.get('off_hex', '')), g.get('op', ''))
        for g in facts.get('guards', [])
    ))
    return (
        len(facts.get('callees', [])),
        len(facts.get('globals', [])),
        fields,
        guards,
        line_count_val,
    )


def build_index(facts_path, funcs_dir, exclude_files):
    facts = json.load(open(facts_path, 'r', encoding='utf-8'))
    idx = {}
    file_by_addr = {}
    for fn in os.listdir(funcs_dir):
        if not fn.endswith('.c'):
            continue
        addr8 = fn.rsplit('_', 1)[-1][:-2]  # strip .c, take trailing addr token
        file_by_addr[addr8] = fn

    for addr8, f in facts.items():
        fn = file_by_addr.get(addr8)
        if fn is None or fn in exclude_files:
            continue
        lc = line_count(os.path.join(funcs_dir, fn))
        if lc < 3:  # trivial/degenerate functions -> too many false-positive collisions
            continue
        fp = fingerprint(f, addr8, lc)
        # skip fully-empty fingerprints (no fields/guards/callees/globals) -- no signal
        if fp[0] == 0 and fp[1] == 0 and not fp[2] and not fp[3]:
            continue
        idx.setdefault(fp, []).append(fn)
    return idx


def main():
    cm1 = json.load(open(CROSSMATCH1, 'r', encoding='utf-8'))
    already_matched_nt = {e['nt2004'] for e in cm1['identical']}
    already_matched_f1c = set()
    for e in cm1['identical']:
        already_matched_f1c.update(e['f1c'])

    nt_idx = build_index(NT_FACTS, NT_DIR, already_matched_nt)
    f1c_idx = build_index(F1C_FACTS, F1C_DIR, already_matched_f1c)

    identical2 = []
    matched_nt = set()
    for fp, nt_files in nt_idx.items():
        f1c_files = f1c_idx.get(fp)
        if not f1c_files:
            continue
        for nf in nt_files:
            identical2.append({"nt2004": nf, "f1c": f1c_files, "tier": "structural"})
            matched_nt.add(nf)

    nt_only_after = sorted(set(cm1['nt2004_only']) - matched_nt) + \
        sorted(f for f in nt_idx if f not in nt_idx)  # no-op, kept explicit
    # actual unmatched = original nt2004_only minus newly matched via structural pass,
    # PLUS nt funcs that had degenerate/skipped fingerprints in this pass but weren't
    # in identical1 either (already covered since nt2004_only already includes those).
    still_unmatched = sorted(set(cm1['nt2004_only']) - matched_nt)

    result = {
        "_meta": {"tier": "structural fingerprint (fields+guards+callee/global counts+line count)"},
        "stats": {
            "matched_this_pass": len(identical2),
            "gtr2_still_unmatched": len(still_unmatched),
        },
        "identical": identical2,
    }
    with open(OUT, 'w', encoding='utf-8') as f:
        json.dump(result, f, indent=1)
    with open(FINAL_OUT, 'w', encoding='utf-8') as f:
        json.dump({
            "count": len(still_unmatched),
            "files": still_unmatched,
        }, f, indent=1)

    print(f"[crossmatch2] structural matches: {len(identical2)}")
    print(f"[crossmatch2] still unmatched (real delta): {len(still_unmatched)} -> {FINAL_OUT}")


if __name__ == "__main__":
    main()
