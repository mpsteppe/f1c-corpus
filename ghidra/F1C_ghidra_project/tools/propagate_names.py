#!/usr/bin/env python3
r"""Cross-binary NAME PROPAGATION (technique #1 from the 2026-07-17 capability audit).

Problem: 3,018 F1C functions are byte-identical to NASCAR 03/04 twins, but only
~340 carry a name. The NASCAR binaries ship DEBUG asserts that name their own
functions ("Entered DynMan::Init()", "...\dynman.cpp"). Propagate those names
ALONG THE BYTE-MATCH EDGE onto the F1C twin.

Ground truth chain (all FACT-tier — byte-identity + literal strings in the exe):
    NASCAR string "Entered X::Y()"  (names a NASCAR func addr)
      -> cross_binary_final.csv byte-match edge (nascar_addr == f1c twin)
      -> F1C func is X::Y

Inputs (all in tools/):
    cross_binary_final.csv          f1c_addr, nascar03_addr, nascar04_addr, class, method, name, ...
    nascar03_strings.csv            address, string, length, type, referencing_functions (';'-sep)
    nascar04_strings.csv            same

Output:
    work/f1c_name_propagation.csv   f1c_addr, propagated_name, source_file, confidence,
                                    evidence_binary, evidence_string, already_named

Nothing is written into docs/. This is a proposal table for review, then a merge.
"""
import csv, os, re, sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
OUT = os.path.join(ROOT, "work", "f1c_name_propagation.csv")

# Class::Method(  — the assert/trace naming pattern. Captures optional "Entered " prefix.
METHOD_RE = re.compile(r"([A-Za-z_]\w*)::(~?[A-Za-z_]\w*)\s*\(")
CPP_RE = re.compile(r"[\\/]([A-Za-z0-9_]+\.cpp)\b", re.I)


def load_strings(path):
    """Return (name_by_addr, srcfile_by_addr) for one NASCAR binary."""
    names = {}      # nascar_func_addr -> "Class::Method"
    srcs = {}       # nascar_func_addr -> "file.cpp"
    if not os.path.exists(path):
        return names, srcs
    with open(path, encoding="utf-8", errors="ignore") as f:
        for r in csv.DictReader(f):
            s = r.get("string", "")
            refs = [a.strip() for a in re.split(r"[;|]", r.get("referencing_functions", "")) if a.strip()]
            m = METHOD_RE.search(s)
            if m:
                nm = f"{m.group(1)}::{m.group(2)}"
                for a in refs:
                    names.setdefault(a.lower(), nm)
            c = CPP_RE.search(s)
            if c:
                for a in refs:
                    srcs.setdefault(a.lower(), c.group(1).lower())
    return names, srcs


def main():
    n03_names, n03_src = load_strings(os.path.join(TOOLS, "nascar03_strings.csv"))
    n04_names, n04_src = load_strings(os.path.join(TOOLS, "nascar04_strings.csv"))

    rows = []
    stats = defaultdict(int)
    with open(os.path.join(TOOLS, "cross_binary_final.csv"), encoding="utf-8", errors="ignore") as f:
        for r in csv.DictReader(f):
            f1c = (r.get("f1c_addr") or "").strip().lower()
            if not f1c:
                continue
            n03 = (r.get("nascar03_addr") or "").strip().lower()
            n04 = (r.get("nascar04_addr") or "").strip().lower()
            existing = (r.get("name") or "").strip()
            already = bool(existing) and "?" not in existing

            # Prefer nascar04 (richer debug set), fall back to nascar03.
            name = n04_names.get(n04) or n03_names.get(n03)
            src = n04_src.get(n04) or n03_src.get(n03)
            if not name and not src:
                continue

            evb = "nascar04" if (n04_names.get(n04) or n04_src.get(n04)) else "nascar03"
            rows.append({
                "f1c_addr": f1c,
                "propagated_name": name or "",
                "source_file": src or "",
                "confidence": r.get("confidence", ""),
                "match_type": r.get("match_type", ""),
                "evidence_binary": evb,
                "already_named": "yes" if already else "no",
            })
            if name:
                stats["with_method_name"] += 1
                if not already:
                    stats["NEW_method_name"] += 1
            if src:
                stats["with_source_file"] += 1

    rows.sort(key=lambda x: (x["already_named"] == "yes", x["f1c_addr"]))
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["f1c_addr", "propagated_name", "source_file",
                                          "confidence", "match_type", "evidence_binary", "already_named"])
        w.writeheader()
        w.writerows(rows)

    print(f"wrote {OUT}")
    print(f"total propagated rows       : {len(rows)}")
    print(f"  with a Class::Method name : {stats['with_method_name']}")
    print(f"    NEW (not already named) : {stats['NEW_method_name']}")
    print(f"  with a source .cpp file   : {stats['with_source_file']}")


if __name__ == "__main__":
    main()
