#!/usr/bin/env python3
r"""Item A — source-file range expansion.

Functions compiled from one .cpp are contiguous in .text. We know the home file
for a set of ANCHOR functions (any function that references a `\Source\xxx.cpp`
string — assert/trace sites — is compiled from that file: FACT). Sort all
functions by address; each anonymous function between two same-file anchors
inherits that file. Boundary regions (between anchors of different files) are
assigned to the lower anchor but flagged lower-confidence.

Inputs (static, on disk):
  tools/ida_functions.csv   full address list (6170 funcs)
  tools/ida_strings.csv     string -> ref_funcs (for \Source\ path anchors)
  work/source_atlas.csv     extra anchors (wrapper_addr -> file)

Output: work/source_file_map_expanded.csv
  func_addr, file, confidence, method
    confidence: ANCHOR (fact) | HIGH (bracketed same file) |
                MED (boundary region) | LOW (beyond last/ before first anchor)
"""
import csv, os, re
from bisect import bisect_right

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FUNCS = os.path.join(ROOT, "tools", "ida_functions.csv")
STRINGS = os.path.join(ROOT, "tools", "ida_strings.csv")
ATLAS = os.path.join(ROOT, "work", "source_atlas.csv")
OUT = os.path.join(ROOT, "work", "source_file_map_expanded.csv")

SRCPATH = re.compile(r"[\\/]Source[\\/]([A-Za-z0-9_]+\.cpp)", re.I)


def parse_addr(s):
    s = s.strip()
    try:
        return int(s, 16) if s.lower().startswith("0x") else int(s, 16)
    except ValueError:
        return None


def split_refs(s):
    return [x for x in re.split(r"[|;, ]+", s.strip()) if x.startswith("0x")]


def main():
    # all function addresses
    funcs = []
    for r in csv.DictReader(open(FUNCS, encoding="utf-8", errors="replace")):
        a = parse_addr(r["addr"])
        if a is not None:
            funcs.append(a)
    funcs = sorted(set(funcs))

    # anchors: addr -> file  (a func may reference several; keep the first seen)
    anchors = {}
    for r in csv.DictReader(open(STRINGS, encoding="utf-8", errors="replace")):
        m = SRCPATH.search(r["value"])
        if not m:
            continue
        for fn in split_refs(r["ref_funcs"]):
            a = parse_addr(fn)
            if a is not None:
                anchors.setdefault(a, m.group(1))
    if os.path.exists(ATLAS):
        for r in csv.DictReader(open(ATLAS, encoding="utf-8", errors="replace")):
            a = parse_addr(r.get("wrapper_addr", ""))
            if a is not None and r["file"]:
                anchors.setdefault(a, r["file"])

    aitems = sorted(anchors.items())          # (addr, file)
    aaddrs = [a for a, _ in aitems]
    afiles = [f for _, f in aitems]

    # index of an anchor address -> its position in funcs list (to measure gap in #funcs)
    fpos = {a: i for i, a in enumerate(funcs)}
    GAP = 8   # boundary funcs within this many funcs of the lower anchor may inherit it

    rows = []
    conf_count = {"ANCHOR": 0, "HIGH": 0, "MED": 0, "UNKNOWN": 0}
    for a in funcs:
        if a in anchors:
            rows.append((a, anchors[a], "ANCHOR", "references \\Source path"))
            conf_count["ANCHOR"] += 1
            continue
        i = bisect_right(aaddrs, a)           # index of first anchor > a
        below_a = aaddrs[i - 1] if i > 0 else None
        below = afiles[i - 1] if i > 0 else None
        above = afiles[i] if i < len(afiles) else None
        if below is not None and below == above:
            rows.append((a, below, "HIGH", "bracketed same file"))
            conf_count["HIGH"] += 1
        elif below is not None and below_a in fpos and (fpos[a] - fpos[below_a]) <= GAP:
            # boundary region but close to the lower anchor -> tentatively inherit it
            rows.append((a, below, "MED", f"near-anchor boundary (<= {GAP} funcs)"))
            conf_count["MED"] += 1
        else:
            # sparse/large gap or before-first/after-last -> DO NOT GUESS
            rows.append((a, "", "UNKNOWN", "no bracketing anchor"))
            conf_count["UNKNOWN"] += 1

    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["func_addr", "file", "confidence", "method"])
        for a, fl, c, m in rows:
            w.writerow(["0x%08x" % a, fl, c, m])

    from collections import Counter
    usable = [r for r in rows if r[2] in ("ANCHOR", "HIGH")]
    perfile = Counter(fl for _, fl, c, _ in rows if fl and c in ("ANCHOR", "HIGH"))
    print(f"{len(funcs)} funcs  |  {len(anchors)} anchors ({len(set(afiles))} files)")
    for k in ("ANCHOR", "HIGH", "MED", "UNKNOWN"):
        print(f"   {conf_count[k]:5d}  {k}")
    print(f"USABLE (ANCHOR+HIGH, fact/bracketed): {len(usable)} funcs, {len(perfile)} files")
    print(f"-> {OUT}")
    print("usable file assignments by count:")
    for fn, n in perfile.most_common(25):
        print(f"   {n:5d}  {fn}")


if __name__ == "__main__":
    main()
