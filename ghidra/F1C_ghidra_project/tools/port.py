"""
port.py — sibling-function porting workbench (feature resurrection flow).

Given a function in an isiMotor sibling (NASCAR Thunder 03/04, F1 2002, SCGT)
that F1C lacks or hides, put EVERYTHING needed to translate it onto F1C structs
on one screen:

  1. the sibling's decompiled source (source_material/<game>/decompiled/)
  2. the sibling's doc entry, if the architect wrote one (docs/40-43)
  3. cross-binary matches: which F1C functions are byte-identical or source-
     similar to it (cross_binary/_delta/*), i.e. shared engine code you can
     reuse verbatim + the F1C neighbours to graft new logic between.

USAGE
-----
  python tools/port.py nascar03 0x004c9650      # the caution-length chooser
  python tools/port.py f1_2002 0x0049xxxx
  python tools/port.py list                      # known game keys + dirs

Games: nascar03, nascar04, f1_2002, f1_2002_demo, scgt
"""

import csv
import glob
import os
import re
import sys

if sys.platform == 'win32':
    sys.stdout.reconfigure(encoding='utf-8', errors='replace')

PROJ_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SRC_MAT = os.path.join(PROJ_ROOT, "source_material")
DELTA = os.path.join(PROJ_ROOT, "cross_binary", "_delta")

# game key -> (source_material dir, cross_binary CSV stem)
GAMES = {
    'nascar03':     ("Nascar Thunder 2003", "nascar03"),
    'nascar04':     ("Nascar Thunder 2004", "nascar04"),
    'f1_2002':      ("F1 2002", "f1c_vs_f1_2002"),
    'f1_2002_demo': ("F1 2002 DEMO", "f1_2002_demo"),
    'scgt':         ("Sports Car GT", "scgt"),
}


def norm(a):
    a = a.lower().replace('0x', '').lstrip('0') or '0'
    return f"0x{int(a, 16):08x}"


def find_decompiled(game_dir, addr):
    hexpart = norm(addr)[2:]
    d = os.path.join(SRC_MAT, game_dir, "decompiled")
    for pat in (f"0x{hexpart}__*.c", f"*{hexpart.upper()}*.c", f"*{hexpart}*.c"):
        hits = glob.glob(os.path.join(d, pat))
        if hits:
            return hits[0]
    return None


def find_doc_entry(game_dir, addr):
    """Grab the paragraph(s) around the sibling addr in docs/40-43."""
    hexpart = norm(addr)[2:]
    out = []
    for path in glob.glob(os.path.join(SRC_MAT, game_dir, "docs", "4*.md")):
        try:
            with open(path, encoding='utf-8', errors='replace') as f:
                lines = f.readlines()
        except OSError:
            continue
        for i, ln in enumerate(lines):
            if hexpart in ln.lower():
                lo = max(0, i - 1)
                hi = min(len(lines), i + 8)
                block = ''.join(lines[lo:hi]).strip()
                out.append((os.path.basename(path), block[:900]))
    return out


def find_matches(stem, addr):
    """cross_binary classified + srcmatch rows for this sibling addr."""
    a = norm(addr)
    byte_matches, src_matches = [], []
    cpath = os.path.join(DELTA, f"{stem}_classified.csv")
    if os.path.exists(cpath):
        with open(cpath, encoding='utf-8', errors='replace') as f:
            for r in csv.DictReader(f):
                sib = r.get('sibling_addr') or r.get('addr') or ''
                if sib and norm(sib) == a:
                    byte_matches.append(r)
    # srcmatch stems differ (nascar03_srcmatch, f1_2002_full_srcmatch)
    for sp in (f"{stem}_srcmatch.csv", f"{stem.replace('f1c_vs_','')}_full_srcmatch.csv",
               f"{stem.replace('f1c_vs_','')}_srcmatch.csv"):
        spath = os.path.join(DELTA, sp)
        if os.path.exists(spath):
            with open(spath, encoding='utf-8', errors='replace') as f:
                for r in csv.DictReader(f):
                    sib = r.get('sibling_addr') or ''
                    if sib and norm(sib) == a:
                        src_matches.append(r)
            break
    return byte_matches, src_matches


def f1c_func_name(addr):
    """Best-effort F1C name via investigate.py's resolver."""
    try:
        sys.path.insert(0, os.path.dirname(__file__))
        import investigate
        return investigate.func_name(investigate._norm(addr))
    except Exception:
        return ''


def cmd_port(game_key, addr):
    if game_key not in GAMES:
        sys.exit(f"unknown game '{game_key}' — one of: {', '.join(GAMES)}")
    game_dir, stem = GAMES[game_key]
    a = norm(addr)
    print("=" * 78)
    print(f"  PORT: {game_key} {a}  ->  F1 Challenge")
    print("=" * 78)

    # doc entry
    docs = find_doc_entry(game_dir, addr)
    if docs:
        print(f"\n-- sibling doc entry ({game_dir}) --")
        for fn, block in docs[:2]:
            print(f"  [{fn}]")
            for ln in block.splitlines():
                print(f"    {ln}")

    # cross-binary matches (the reusable/graft points)
    byte_m, src_m = find_matches(stem, addr)
    if byte_m:
        print(f"\n-- F1C byte/structural matches (shared engine code — reuse as-is) --")
        for r in byte_m[:6]:
            verdict = r.get('verdict') or r.get('decision') or '?'
            f1c = r.get('f1c_addr') or r.get('best_f1c') or ''
            anchor = r.get('anchor') or r.get('shared_anchors') or ''
            nm = f1c_func_name(f1c) if f1c else ''
            print(f"    [{verdict}] F1C {f1c} {nm[:34]:34s} {anchor[:40]}")
    if src_m:
        print(f"\n-- F1C source-similarity matches (TF-IDF — likely counterpart / neighbours) --")
        for r in src_m[:6]:
            f1c = r.get('best_f1c') or r.get('f1c_addr') or ''
            score = r.get('score') or ''
            nm = f1c_func_name(f1c) if f1c else ''
            print(f"    score {score:>5}  F1C {f1c} {nm[:40]}")
    if not byte_m and not src_m:
        print(f"\n-- no cross-binary match rows for {a} in {stem}_* "
              f"(likely a sibling-exclusive function — that's the point) --")

    # sibling source last (the bulk)
    src = find_decompiled(game_dir, addr)
    if src:
        print(f"\n-- sibling source: {os.path.relpath(src, PROJ_ROOT)} --")
        with open(src, encoding='utf-8', errors='replace') as f:
            print(f.read().rstrip())
    else:
        print(f"\n  !! no decompiled .c for {a} under {game_dir}/decompiled/")
    print()
    print("  next: translate onto F1C structs using mods/sdk/f1c_sdk.h + the matches above;")
    print("        scaffold with  python tools/gen_hook.py tick <name>")


def cmd_list():
    print("game keys:")
    for k, (d, stem) in GAMES.items():
        dd = os.path.join(SRC_MAT, d, "decompiled")
        n = len(glob.glob(os.path.join(dd, "*.c"))) if os.path.isdir(dd) else 0
        print(f"  {k:14s} {d:24s} {n} decompiled  (delta stem: {stem})")


def main():
    args = sys.argv[1:]
    if not args or args[0] == 'list':
        cmd_list() if args and args[0] == 'list' else print(__doc__)
        return
    if len(args) < 2:
        sys.exit("usage: python tools/port.py <game> <sibling_addr>")
    cmd_port(args[0], args[1])


if __name__ == '__main__':
    main()
