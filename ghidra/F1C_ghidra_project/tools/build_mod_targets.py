#!/usr/bin/env python3
r"""Rank candidate mod patch-points from enforcement/validation strings.

Every assert/error/validation string in the binary marks a branch that BLOCKS,
PENALIZES, or GATES game behavior — i.e. exactly the branches a byte-patch or
DLL-hook mod wants to relax, redirect, or bypass. This scores those branches.

Sources (all static, on disk):
  tools/ida_strings.csv   value + ref_funcs for every string
  work/source_atlas.csv   trace-site file/line/method map (optional enrich)

Subsystem tag: a function that references a `...\Source\xxx.cpp` assert string
belongs to xxx.cpp. That builds a broad func->file map beyond the 193 trace sites.

Output: work/mod_targets.csv  (func_addr, file, category, rank, string)
sorted by rank desc. rank = mod value, not string frequency.
"""
import csv, os, re
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STRINGS = os.path.join(ROOT, "tools", "ida_strings.csv")
ATLAS = os.path.join(ROOT, "work", "source_atlas.csv")
OUT = os.path.join(ROOT, "work", "mod_targets.csv")

# category -> (rank, regex).  Higher rank = higher mod value.
CATS = [
    ("race_rule",      5, r"penalt|disqualif|illegal|black.?flag|\bcut\b|drive.?through|stop.?go|warning|jump.?start|speeding|pit lane"),
    ("physics_limit",  4, r"should be|must be|out of range|exceed|\bclamp|maximum|minimum|positive|negative|too (?:high|low|large|many|few)|limit"),
    ("data_gate",      3, r"non-existent|not found|could not (?:load|open|find)|no .* in|doesn't have|missing|unable to (?:load|open)"),
    ("config_valid",   2, r"invalid|bad |unexpected|not allowed|out of memory|allocation"),
]
CAT_RE = [(name, rank, re.compile(rx, re.I)) for name, rank, rx in CATS]

SRCPATH = re.compile(r"[\\/]Source[\\/]([A-Za-z0-9_]+\.cpp)", re.I)


def split_refs(s):
    return [x for x in re.split(r"[|;, ]+", s.strip()) if x.startswith("0x")]


def main():
    rows = list(csv.DictReader(open(STRINGS, encoding="utf-8", errors="replace")))

    # func -> source file, from assert path strings
    func_file = {}
    for r in rows:
        m = SRCPATH.search(r["value"])
        if m:
            for fn in split_refs(r["ref_funcs"]):
                func_file.setdefault(fn.lower(), m.group(1))

    # enrich from source_atlas target/wrapper addrs
    if os.path.exists(ATLAS):
        for a in csv.DictReader(open(ATLAS, encoding="utf-8", errors="replace")):
            for col in ("target_addr", "wrapper_addr"):
                fa = a.get(col, "")
                if fa and a["file"]:
                    func_file.setdefault(fa.lower(), a["file"])

    def categorize(val):
        for name, rank, rx in CAT_RE:
            if rx.search(val):
                return name, rank
        return None, 0

    out = []
    seen = set()
    for r in rows:
        val = r["value"].strip()
        refs = split_refs(r["ref_funcs"])
        if not refs:
            continue
        cat, rank = categorize(val)
        if not cat:
            continue
        for fn in refs:
            key = (fn.lower(), val)
            if key in seen:
                continue
            seen.add(key)
            out.append(dict(func_addr=fn, file=func_file.get(fn.lower(), ""),
                            category=cat, rank=rank, string=val))

    out.sort(key=lambda r: (-r["rank"], r["file"], r["func_addr"]))
    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["rank", "category", "file", "func_addr", "string"])
        w.writeheader()
        for r in out:
            w.writerow({k: r[k] for k in w.fieldnames})

    from collections import Counter
    bycat = Counter(r["category"] for r in out)
    tagged = sum(1 for r in out if r["file"])
    print(f"{len(out)} mod-target rows  |  {tagged} with a source file  |  {len(func_file)} funcs file-tagged")
    for c, _, _ in CAT_RE:
        print(f"   {bycat.get(c,0):4d}  {c}")
    print(f"-> {OUT}")


if __name__ == "__main__":
    main()
