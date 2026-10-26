#!/usr/bin/env python3
"""
search_docs.py — search all docs/*.md files, return section-context + related tokens.

AUTO-DETECTS query type:

    python search_docs.py 0x15c4             # hex offset
    python search_docs.py +0x15c4            # same
    python search_docs.py DAT_007c56a4       # global
    python search_docs.py 007c56a4           # same (bare)
    python search_docs.py FUN_0042fd00       # function
    python search_docs.py 0042fd00           # same (bare)
    python search_docs.py EngineMap          # keyword

For each match, also prints every FUN_, DAT_, and offset referenced in
the same section — so you can follow the chain without knowing what to
search next.

Options:
    -C N        context lines before/after match (default: 3)
    -l          file:line list only, no context
    --all       include decompiled_full_index_final.md (7k rows)

Force mode (only if auto-detect is wrong):
    --offset  --global  --fun  --keyword
"""

import re
import sys
from pathlib import Path
from collections import defaultdict

if sys.stdout.encoding and sys.stdout.encoding.lower() != "utf-8":
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

DOCS_DIR = Path(__file__).parent / "docs"
SEP = "-" * 72

RE_OFFSET_QUERY = re.compile(r"^\+?0x[0-9a-f]+$", re.IGNORECASE)
# 5–9 hex chars (with or without DAT_/FUN_ prefix) — covers full and partial addresses
RE_ADDR_QUERY   = re.compile(r"^(DAT_|FUN_)?[0-9a-f]{5,9}$", re.IGNORECASE)

# tokens to harvest from sections
RE_FUN     = re.compile(r"\bFUN_[0-9a-fA-F]{6,8}\b")
RE_DAT     = re.compile(r"\bDAT_[0-9a-fA-F]{8}\b")
RE_OFFSET  = re.compile(r"\+0x[0-9a-fA-F]+\b")


def detect_mode(query, args):
    if args.offset:      return "offset"
    if args.global_addr: return "global"
    if args.fun:         return "fun"
    if args.keyword:     return "keyword"
    q = query.strip()
    if RE_OFFSET_QUERY.match(q):
        return "offset"
    if RE_ADDR_QUERY.match(q):
        upper = q.upper()
        if upper.startswith("DAT_") or upper.startswith("007") or upper.startswith("008"):
            return "global"
        if upper.startswith("FUN_") or upper.startswith("004") or upper.startswith("005"):
            return "fun"
        return "global"
    return "keyword"


def build_pattern(query, mode):
    if mode == "offset":
        raw = re.sub(r"^[+]?0x", "", query, flags=re.IGNORECASE).lstrip("+").lower()
        val = int(raw, 16)
        patterns = [
            rf"\+?0x0*{re.escape(raw)}\b",
            rf"\+0*{re.escape(raw)}\b",
            rf"\b{val}\b",
        ]
        return re.compile("|".join(patterns), re.IGNORECASE)
    elif mode == "global":
        raw = re.sub(r"^DAT_", "", query, flags=re.IGNORECASE).lstrip("0").lower() or "0"
        # partial prefix (< 8 hex chars) → prefix match; full address → exact word match
        boundary = r"\b" if len(raw) >= 8 else ""
        return re.compile(rf"DAT_0*{re.escape(raw)}{boundary}", re.IGNORECASE)
    elif mode == "fun":
        raw = re.sub(r"^FUN_", "", query, flags=re.IGNORECASE).lstrip("0").lower() or "0"
        boundary = r"\b" if len(raw) >= 8 else ""
        return re.compile(rf"FUN_0*{re.escape(raw)}{boundary}", re.IGNORECASE)
    else:
        return re.compile(re.escape(query), re.IGNORECASE)


def section_bounds(lines, match_lineno):
    """Return (start_idx, end_idx) of the section containing match_lineno."""
    start = 0
    for i in range(match_lineno, -1, -1):
        if lines[i].startswith("## ") or lines[i].startswith("### "):
            start = i
            break
    end = len(lines)
    for i in range(start + 1, len(lines)):
        if lines[i].startswith("## ") or lines[i].startswith("### "):
            end = i
            break
    return start, end


def extract_related(section_lines, exclude_pattern):
    """
    Pull all FUN_, DAT_, +0xOFFSET tokens from a section.
    Exclude anything that matches the search query itself.
    Returns (funs, dats, offsets) as sorted lists.
    """
    text = "\n".join(section_lines)
    funs    = sorted(set(RE_FUN.findall(text)))
    dats    = sorted(set(RE_DAT.findall(text)))
    offsets = sorted(set(RE_OFFSET.findall(text)))
    if exclude_pattern:
        funs    = [x for x in funs    if not exclude_pattern.search(x)]
        dats    = [x for x in dats    if not exclude_pattern.search(x)]
        offsets = [x for x in offsets if not exclude_pattern.search(x)]
    return funs, dats, offsets


def search_file(path, pattern, context_lines):
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    except Exception:
        return []

    results = []
    # track which sections we've already harvested related-tokens from
    seen_sections = {}  # (file, sec_start) -> related payload

    for i, line in enumerate(lines):
        if not pattern.search(line):
            continue
        sec_start, sec_end = section_bounds(lines, i)
        section_header = lines[sec_start].rstrip() if lines[sec_start].startswith(("## ", "### ")) else None

        ctx_start = max(0, i - context_lines)
        ctx_end   = min(len(lines) - 1, i + context_lines)

        sec_key = (path.name, sec_start)
        if sec_key not in seen_sections:
            funs, dats, offsets = extract_related(lines[sec_start:sec_end], pattern)
            seen_sections[sec_key] = (funs, dats, offsets)

        results.append({
            "file":         path.name,
            "lineno":       i + 1,
            "section":      section_header,
            "sec_key":      sec_key,
            "context_start": ctx_start + 1,
            "context":      lines[ctx_start:ctx_end + 1],
            "match_offset": i - ctx_start,
        })

    return results, seen_sections


def format_related(funs, dats, offsets):
    lines = []
    if funs:
        lines.append("  Functions : " + "  ".join(funs))
    if dats:
        lines.append("  Globals   : " + "  ".join(dats))
    if offsets:
        lines.append("  Offsets   : " + "  ".join(sorted(set(offsets))))
    return lines


def print_results(all_results, all_sections, list_only, mode, query):
    if not all_results:
        print(f"No matches for: {query!r}  (mode: {mode})")
        return

    files_hit = len(set(r["file"] for r in all_results))

    # Track which sections already had their "Related" block printed
    printed_related = set()

    for r in all_results:
        if list_only:
            print(f"{r['file']}:{r['lineno']}")
            continue

        print(SEP)
        sec = f"  [{r['section']}]" if r["section"] else ""
        print(f"  {r['file']}:{r['lineno']}{sec}")
        print()

        for j, ctx_line in enumerate(r["context"]):
            lineno = r["context_start"] + j
            marker = ">>>" if j == r["match_offset"] else "   "
            print(f"  {marker} {lineno:5d}  {ctx_line}")

        # Print related once per section
        sk = r["sec_key"]
        if sk not in printed_related:
            printed_related.add(sk)
            funs, dats, offsets = all_sections[sk]
            related_lines = format_related(funs, dats, offsets)
            if related_lines:
                print()
                print("  Also in this section:")
                for rl in related_lines:
                    print(rl)

        print()

    if not list_only:
        print(SEP)
        print(f"  {len(all_results)} match(es) in {files_hit} file(s)  [mode: {mode}]")


def parse_args():
    import argparse
    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    p.add_argument("query", help="What to search for — auto-detected")
    p.add_argument("-C", dest="context", type=int, default=3, metavar="N")
    p.add_argument("-l", dest="list_only", action="store_true")
    p.add_argument("--all",     dest="include_all",  action="store_true")
    p.add_argument("--offset",  action="store_true")
    p.add_argument("--global",  dest="global_addr",  action="store_true")
    p.add_argument("--fun",     action="store_true")
    p.add_argument("--keyword", action="store_true")
    return p.parse_args()


def main():
    args = parse_args()
    mode    = detect_mode(args.query, args)
    pattern = build_pattern(args.query, mode)

    files = sorted(DOCS_DIR.glob("*.md"))
    if not args.include_all:
        files = [f for f in files if f.name != "decompiled_full_index_final.md"]

    all_results  = []
    all_sections = {}

    for f in files:
        results, sections = search_file(f, pattern, args.context)
        all_results.extend(results)
        all_sections.update(sections)

    print_results(all_results, all_sections, args.list_only, mode, args.query)


if __name__ == "__main__":
    main()
