# tools_reclassify_structural.py
# Reclassify crossmatch2.json (structural-fingerprint tier) into TRUSTED vs JUNK.
#
# Spot-check finding (2026-07-27): structural matches are sound for functions
# with real bodies, but collide for tiny accessors/thunks (e.g. a 1-line
# byte-reader at this->+24 matched a float-reader at this->+24; a 1-line thunk
# "matched" 110 F1C candidates). Fingerprint lacks return type / instruction
# detail, so small functions are ambiguous by construction.
#
# Rule (deterministic, no LLM):
#   TRUSTED  if body_lines >= MIN_LINES  OR  (len(fields)+len(guards)) >= MIN_TUPLES
#   JUNK     otherwise  -> returned to the unmatched worklist
#
# Inputs : crossmatch2.json, gtr2_still_unmatched.json,
#          skeleton_facts_all.json, functions/*.c
# Outputs: crossmatch2_trusted.json, crossmatch2_junk.json,
#          gtr2_unmatched_final.json  (still_unmatched + junk nt2004 files)

import json, os, re, sys

DIR = os.path.dirname(os.path.abspath(__file__))
MIN_LINES = 8
MIN_TUPLES = 2

def load(name):
    with open(os.path.join(DIR, name), encoding="utf-8") as f:
        return json.load(f)

def body_lines(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return sum(1 for ln in f if ln.strip() and not ln.strip().startswith("//"))

def addr_of(filename):
    m = re.search(r"_([0-9a-fA-F]{8})\.c$", filename)
    return m.group(1).lower() if m else None

def main():
    cm2 = load("crossmatch2.json")
    facts = load("skeleton_facts_all.json")
    unmatched = load("gtr2_still_unmatched.json")

    trusted, junk = [], []
    for pair in cm2["identical"]:
        nt = pair["nt2004"]
        path = os.path.join(DIR, "functions", nt)
        if not os.path.exists(path):
            junk.append({**pair, "reason": "missing .c file"})
            continue
        lines = body_lines(path)
        addr = addr_of(nt)
        f = facts.get(addr, {})
        tuples = len(f.get("fields", [])) + len(f.get("guards", []))
        rec = {**pair, "body_lines": lines, "fact_tuples": tuples}
        if lines >= MIN_LINES or tuples >= MIN_TUPLES:
            trusted.append(rec)
        else:
            rec["reason"] = f"tiny body ({lines} lines, {tuples} tuples) - fingerprint collision risk"
            junk.append(rec)

    junk_nt = sorted(p["nt2004"] for p in junk)
    final_unmatched = sorted(set(unmatched["files"]) | set(junk_nt))

    out_t = {"_meta": cm2["_meta"],
             "rule": f"trusted if body_lines>={MIN_LINES} or fields+guards>={MIN_TUPLES}",
             "stats": {"trusted": len(trusted)},
             "identical": trusted}
    out_j = {"stats": {"junk": len(junk)}, "identical": junk}
    out_u = {"count": len(final_unmatched),
             "note": "gtr2_still_unmatched + structural-junk returns",
             "files": final_unmatched}

    for name, obj in [("crossmatch2_trusted.json", out_t),
                      ("crossmatch2_junk.json", out_j),
                      ("gtr2_unmatched_final.json", out_u)]:
        with open(os.path.join(DIR, name), "w", encoding="utf-8") as fh:
            json.dump(obj, fh, indent=1)

    print(f"trusted: {len(trusted)}  junk: {len(junk)}  "
          f"final unmatched: {len(final_unmatched)} (was {unmatched['count']})")
    # size histogram of junk to show what got kicked back
    from collections import Counter
    h = Counter(p.get("body_lines", -1) for p in junk)
    print("junk body-line histogram:", dict(sorted(h.items())))

if __name__ == "__main__":
    main()
