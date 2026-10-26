# tools_anchor_names.py
# Step 1 - seed NT2004 function naming from F1C twins.
#
# For every exact-tier (crossmatch.json) and trusted-structural-tier
# (crossmatch2_trusted.json) pair: if the F1C side has a REAL name
# (filename not of the form sub_XXXX_<addr>.c), transfer it to the
# NT2004 function.
#
# Rules:
#   exact tier            -> tier "exact"    (CONFIRMED-equivalent identity)
#   trusted structural    -> tier "structural" (DERIVED until spot-checked)
#   multi-candidate pairs -> name taken only if EXACTLY ONE candidate is named
#   conflict (two tiers give different names) -> exact tier wins, conflict logged
#
# NT2004 name = F1C base name + "__nt" suffix marker is NOT added; the map
# records the F1C name verbatim plus source filename for traceability.
#
# Output: gtr2_name_seed.json  { nt_addr8: {nt_file, name, f1c_file, tier} }

import json, os, re
from collections import Counter

DIR = os.path.dirname(os.path.abspath(__file__))

def load(name):
    with open(os.path.join(DIR, name), encoding="utf-8") as f:
        return json.load(f)

def addr_of(filename):
    m = re.search(r"_([0-9a-fA-F]{8})\.c$", filename)
    return m.group(1).lower() if m else None

def real_name(filename):
    base = filename.rsplit("_", 1)[0]          # strip _<addr8>.c
    if re.fullmatch(r"sub_[0-9A-Fa-f]+", base):
        return None
    return base

def collect(pairs, tier, seed, conflicts):
    for pair in pairs:
        nt = pair["nt2004"]
        cands = pair["f1c"]
        named = [(real_name(c), c) for c in cands]
        named = [(n, c) for n, c in named if n]
        if len({n for n, _ in named}) != 1:
            continue                          # zero or >1 distinct names: ambiguous
        name, f1c_file = named[0]
        addr = addr_of(nt)
        if addr is None:
            continue
        if addr in seed and seed[addr]["name"] != name:
            conflicts.append({"nt": nt, "kept": seed[addr], "rejected": {"name": name, "tier": tier}})
            if seed[addr]["tier"] == "exact":
                continue                      # exact wins
        if addr in seed and seed[addr]["tier"] == "exact" and tier == "structural":
            continue
        seed[addr] = {"nt_file": nt, "name": name, "f1c_file": f1c_file, "tier": tier}

def main():
    cm1 = load("crossmatch.json")
    cm2 = load("crossmatch2_trusted.json")
    seed, conflicts = {}, []
    collect(cm1["identical"], "exact", seed, conflicts)
    collect(cm2["identical"], "structural", seed, conflicts)

    tiers = Counter(v["tier"] for v in seed.values())
    out = {"_meta": "NT2004 function-name seed from F1C twins (tools_anchor_names.py)",
           "stats": {"named": len(seed), "tiers": dict(tiers), "conflicts": len(conflicts)},
           "names": dict(sorted(seed.items())),
           "conflicts": conflicts}
    with open(os.path.join(DIR, "gtr2_name_seed.json"), "w", encoding="utf-8") as f:
        json.dump(out, f, indent=1)
    print(f"named: {len(seed)}  tiers: {dict(tiers)}  conflicts: {len(conflicts)}")
    # show a sample of recognizable anchors
    for a, v in list(sorted(seed.items(), key=lambda kv: kv[1]["name"]))[:15]:
        print(f"  {a}  {v['name']:45s} [{v['tier']}]")

if __name__ == "__main__":
    main()
