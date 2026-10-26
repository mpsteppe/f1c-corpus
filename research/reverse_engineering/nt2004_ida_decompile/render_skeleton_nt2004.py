# render_skeleton_nt2004.py
# Render pre-filled .md skeletons for the NT2004 UNMATCHED worklist.
# Adapted from F1C's render_skeleton.py; differences:
#   - no callgraph.json      -> callers computed by inverting skeleton_facts
#                               callees; frame-path/persistence left to the LLM
#   - callee names           -> nt2004_name_seed.json (F1C twins, tier-tagged)
#   - extra section          -> string literals referenced (strings_index.json),
#                               the strongest naming signal this corpus has
#   - scope                  -> ONLY files in nt2004_unmatched_final.json
#                               (matched functions link to F1C fills instead)
#
# Deterministic here, never computed by the LLM: fields, globals, callees,
# callers, guards, strings. Semantic blanks: [LLM] / [LLM: ...].

import json, os
from collections import defaultdict

ROOT = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(ROOT, "skeletons")
os.makedirs(OUT, exist_ok=True)

def load(name):
    with open(os.path.join(ROOT, name), encoding="utf-8") as f:
        return json.load(f)

FACTS = load("skeleton_facts_all.json")
STRINGS = load("strings_index.json")["by_function"]
SEED = load("nt2004_name_seed.json")["names"]
UNMATCHED = set(load("nt2004_unmatched_final.json")["files"])

# invert callees -> callers
CALLERS = defaultdict(list)
for a, f in FACTS.items():
    for c in f["callees"]:
        CALLERS[c["addr"].lower()].append({"addr": a, "name": f["name"]})

def seed_name(addr):
    e = SEED.get(addr)
    return f"{e['name']} [{e['tier']}]" if e else None

def render(addr8, fact):
    name = fact["name"]
    L = []
    L.append(f"## {name}_{addr8} — [LLM: short descriptive name]\n")
    L.append("**Summary:** [LLM: 1-2 sentences — what it does, what system]\n")

    callers = CALLERS.get(addr8, [])
    if callers:
        cl = ", ".join(f"{seed_name(c['addr']) or c['name']} ({c['addr']})"
                       for c in callers[:12])
        if len(callers) > 12:
            cl += f" … +{len(callers)-12} more"
    else:
        cl = "(none static — top-level or indirect-only)"
    L.append(f"**Called by:** {cl}\n")

    L.append("**Struct fields accessed:**\n")
    L.append("| Base | Offset | R/W | Init (literal → value) | Purpose |")
    L.append("|------|--------|-----|------------------------|---------|")
    for f in fact["fields"]:
        if "error" in f:
            continue
        init = "—"
        if "init_literal" in f:
            fv = f.get("init_float")
            init = f"{f['init_literal']}" + (f" → {fv}f" if fv is not None else "")
        L.append(f"| {f['base']} | {f['off_hex']} | {f['rw']} | {init} | [LLM] |")
    L.append("")

    writes = [f for f in fact["fields"] if "W" in f.get("rw", "")]
    if writes:
        L.append("**Written-by note (persistence):**")
        for f in writes:
            L.append(f"- {f['base']} {f['off_hex']}: [LLM: written once/"
                     "conditional/recalc every frame? would an external poke survive?]")
        L.append("")

    L.append("**Globals referenced:**\n")
    L.append("| Address | Name | R/W | Role |")
    L.append("|---------|------|-----|------|")
    for g in fact["globals"]:
        L.append(f"| {g['addr']} | {g['name']} | {g['rw']} | [LLM] |")
    L.append("")

    L.append("**Functions called:**\n")
    L.append("| Address | Name | Purpose |")
    L.append("|---------|------|---------|")
    for c in fact["callees"]:
        nm = seed_name(c["addr"].lower()) or c["name"]
        L.append(f"| {c['addr']} | {nm} | [LLM] |")
    L.append("")

    guards = fact.get("guards", [])
    if guards:
        L.append("**Guard conditions (deterministic — field vs literal):**\n")
        L.append("| Base | Offset | Test | Value | Field / meaning |")
        L.append("|------|--------|------|-------|-----------------|")
        for g in guards:
            val = f"{g['value']}"
            if g.get("value_float") is not None:
                val += f" → {g['value_float']}f"
            L.append(f"| {g['base']} | {g['off_hex']} | {g['op']} | {val} | [LLM] |")
        L.append("")
        L.append("**Guard interpretation:** [LLM: from the table — what PASSES vs "
                 "what is BLOCKED]\n")
    else:
        L.append("**Guard conditions:** [LLM: from code — field, checked values, "
                 "what PASSES vs what is BLOCKED]\n")

    sl = STRINGS.get(addr8.upper()) or STRINGS.get(addr8) or []
    if sl:
        L.append("**String literals referenced (deterministic):**\n")
        for e in sl[:20]:
            s = e["s"].replace("|", "\\|")
            L.append(f"- `{s}`")
        if len(sl) > 20:
            L.append(f"- … +{len(sl)-20} more")
        L.append("")
    return "\n".join(L)

def main():
    n = blanks = 0
    for fn in sorted(UNMATCHED):
        base = fn[:-2]  # strip .c
        addr8 = base.rsplit("_", 1)[-1].lower()
        fact = FACTS.get(addr8)
        if fact is None:
            continue
        md = render(addr8, fact)
        blanks += md.count("[LLM")
        with open(os.path.join(OUT, base + ".md"), "w", encoding="utf-8") as fh:
            fh.write(md)
        n += 1
    print(f"[render] {n} skeletons -> {OUT}  avg blanks {blanks/max(n,1):.1f}")

if __name__ == "__main__":
    main()
