# build_priority_index_nt2004.py
# Step 2 - rank the unmatched NT2004 worklist (gtr2_unmatched_final.json).
#
# F1C's builder can't be reused directly: it needs callgraph.json,
# name_index.json vehicle fields and skeletons_filled/ - none of which exist
# here yet. This scorer uses only what NT2004 has:
#
#   +1/+2/+3  fact substance (>=10 / >=30 / >=60 facts)
#   +1        per seed-named callee (cap +5) - connectivity to identified code
#   +2/+4     module known via __FILE__ string (+4 gameplay core, +2 other)
#   +1        per gameplay keyword in seed-named callees (cap +4)
#   +1/+2     caller count (>=5 / >=20) - hub functions
#
# Scope: ONLY files in gtr2_unmatched_final.json (matched functions already
# have F1C fills; ranking them is wasted effort).
#
# Output: priority_index_nt2004.md (top 300), priority_index_nt2004.json (all).

import json, os, re
from collections import Counter

ROOT = os.path.dirname(os.path.abspath(__file__))

def load(name):
    with open(os.path.join(ROOT, name), encoding="utf-8") as f:
        return json.load(f)

facts = load("skeleton_facts_all.json")
strings = load("strings_index.json")
seed = load("gtr2_name_seed.json")["names"]
unmatched = set(load("gtr2_unmatched_final.json")["files"])

CORE_MODULES = {"hdvehicle.cpp", "ai_db.cpp", "tire_manager.cpp", "steward.cpp",
                "aibehavior.cpp", "aistate.cpp", "vehicle.cpp", "race.cpp",
                "racemanager.cpp", "spotter.cpp", "pacecar.cpp", "caution.cpp",
                "damage.cpp", "pitcrew.cpp", "pitstop.cpp", "draft.cpp"}
KEYWORDS = ("AI", "Tire", "Vehicle", "Steward", "Pit", "Race", "Damage",
            "Caution", "Spotter", "Draft", "Engine", "Wheel", "Suspension",
            "Brake", "Steering", "Throttle", "Collision", "Track", "Driver",
            "Lap", "Qualif", "Season", "Championship", "Pace", "Yellow")

# module per function from __FILE__ strings
CPP_RE = re.compile(r"Source\\([^\\]+\.cpp)", re.I)
module_of = {}
for addr, sl in strings["by_function"].items():
    for e in sl:
        m = CPP_RE.search(e["s"])
        if m:
            module_of[addr.lower()] = m.group(1).lower()
            break

# caller counts (invert callees)
callers = Counter()
for a, f in facts.items():
    for c in f["callees"]:
        callers[c["addr"].lower()] += 1

def addr_of(filename):
    m = re.search(r"_([0-9a-fA-F]{8})\.c$", filename)
    return m.group(1).lower() if m else None

rows = []
for fn in unmatched:
    addr = addr_of(fn)
    if addr is None or addr not in facts:
        continue
    f = facts[addr]
    nf = len(f["fields"]) + len(f["globals"]) + len(f["guards"]) + len(f["callees"])
    score, why = 0, []
    if nf >= 10: score += 1; why.append("facts>=10")
    if nf >= 30: score += 1; why.append("facts>=30")
    if nf >= 60: score += 1; why.append("facts>=60")

    named_callees, kw_hits = 0, set()
    for c in f["callees"]:
        ca = c["addr"].lower()
        if ca in seed:
            named_callees += 1
            nm = seed[ca]["name"]
            for kw in KEYWORDS:
                if kw.lower() in nm.lower():
                    kw_hits.add(kw)
    if named_callees:
        score += min(named_callees, 5); why.append(f"named_callees={named_callees}")
    if kw_hits:
        score += min(len(kw_hits), 4); why.append("kw:" + ",".join(sorted(kw_hits)))

    mod = module_of.get(addr)
    if mod:
        if mod in CORE_MODULES:
            score += 4; why.append(f"CORE:{mod}")
        else:
            score += 2; why.append(f"mod:{mod}")

    nc = callers.get(addr, 0)
    if nc >= 5: score += 1
    if nc >= 20: score += 1
    if nc >= 5: why.append(f"callers={nc}")

    if score < 3:
        continue
    rows.append({"addr": addr, "nt_file": fn, "name": seed.get(addr, {}).get("name") or f["name"],
                 "seed_tier": seed.get(addr, {}).get("tier"),
                 "score": score, "facts": nf, "module": mod, "callers": nc,
                 "named_callees": named_callees, "why": why})

rows.sort(key=lambda r: (-r["score"], r["addr"]))
with open(os.path.join(ROOT, "priority_index_nt2004.json"), "w", encoding="utf-8") as fh:
    json.dump(rows, fh, indent=1)

L = ["# NT2004 Priority Index - UNMATCHED functions only (the delta worklist)",
     "",
     f"{len(rows)} of {len(unmatched)} unmatched scored >=3. "
     "Score: substance +1/+1/+1 (10/30/60 facts), named callee +1 (cap 5), "
     "module +4 core/+2 other, gameplay keywords +1 (cap 4), hub +1/+1 (5/20 callers).",
     "",
     "| Score | Function | Module | Callers | Why |",
     "|---:|---|---|---:|---|"]
for r in rows[:300]:
    nm = f"{r['name']}_{r['addr']}"
    L.append(f"| {r['score']} | {nm} | {r['module'] or '-'} | {r['callers']} | {'; '.join(r['why'])} |")
with open(os.path.join(ROOT, "priority_index_nt2004.md"), "w", encoding="utf-8") as fh:
    fh.write("\n".join(L) + "\n")

mods = Counter(r["module"] for r in rows if r["module"])
print(f"scored: {len(rows)} / {len(unmatched)} unmatched; top 300 -> priority_index_nt2004.md")
print("top modules:", mods.most_common(12))
print("top 10:")
for r in rows[:10]:
    print(f"  {r['score']:2d}  {r['name']}_{r['addr']}  [{r['module']}]  {'; '.join(r['why'])}")
