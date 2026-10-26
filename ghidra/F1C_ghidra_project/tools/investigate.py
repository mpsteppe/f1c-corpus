"""
F1C Investigation Dossier — one-shot context bundler for bug hunts.

WHY THIS EXISTS
---------------
Reverse-engineering a bug in this codebase used to burn huge token counts on
two avoidable things:
  1. Reading .c files one at a time ("let me check FUN_x ... now FUN_y ...").
  2. Re-deriving struct-offset math by hand, over and over
     (0x117d*4 = 0x45F4, 13000 = 0x32C8, 0xcaf = 0x32BC ...).

This tool does BOTH in a single invocation for any number of functions:
  - Dumps each function's decompiled .c source.
  - Auto-decodes EVERY struct access into a table:
        raw expr | int-index | byte offset | inferred type | known field (docs/13)
    so nobody recomputes idx*4 or decimal->hex again.
  - Resolves every DAT_ global against docs/12 (address -> name).
  - Resolves every called FUN_ against the knowledge graph (address -> name).
  - Prints direct callers/callees so the next hop is already on screen.

USAGE
-----
  # LOCATE (concept/term -> ranked addresses; start here, no more guessing greps)
  python tools/investigate.py find "commentary"       # strings + names + globals + docs (incl. doc BODIES)
  python tools/investigate.py global DAT_007c56a4     # who touches a global (graph + raw scan)
  python tools/investigate.py uses 007d017c           # raw .c scan for ANY token (hex/offset/id)

  # SYSTEM (concept -> whole-subsystem map: functions, globals, specs, chains, hooks)
  python tools/investigate.py system tire             # one-screen subsystem dossier
  python tools/investigate.py system "session"        # matches doc titles + spec/chain names

  # MOD (concept -> ranked patch surface: patch-points, writable params, hooks)
  python tools/investigate.py mod penalty             # mod_targets + docs/16 fields + globals

  # PARAM (data-file field name -> parser function -> file format; tier-1 mod join)
  python tools/investigate.py param FuelConsumption   # who parses it, from which file, section

  # DOSSIER (once you have an address)
  python tools/investigate.py 0x004ef5a0
  python tools/investigate.py 004ef5a0 004b8940 004b87c0     # several at once
  python tools/investigate.py 0x004ef5a0 --no-source          # tables only
  python tools/investigate.py 0x004ef5a0 --snippet            # only decisive lines (cheap sweep)
  python tools/investigate.py 0x004ef5a0 --callees            # also dump callee source

Typical flows:
  bug:  find "<concept>"    ->  pick addr  ->  investigate.py <addr>
  mod:  system "<concept>"  ->  mod "<concept>"  ->  investigate.py <addr> --snippet

Pass all the functions a hypothesis touches in ONE call. Read the combined
dossier once. Build the offset table once. Reason once.
"""

import os
import re
import shutil
import subprocess
import sys
import glob
import json

if sys.platform == 'win32':
    sys.stdout.reconfigure(encoding='utf-8', errors='replace')

PROJ_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
KG_DIR = os.path.join(PROJ_ROOT, "knowledge_graph")
ANALYZED_DIR = os.path.join(PROJ_ROOT, "analysis_pipeline", "analyzed")
DOCS_DIR = os.path.join(PROJ_ROOT, "docs")

_cache = {}


def _load_json(name):
    if name not in _cache:
        path = os.path.join(KG_DIR, name)
        try:
            with open(path, encoding='utf-8') as f:
                _cache[name] = json.load(f)
        except FileNotFoundError:
            _cache[name] = {}
    return _cache[name]


def _norm(addr):
    """Normalize any address form to 0x00xxxxxx (8 hex digits)."""
    a = addr.strip().lower()
    if a.startswith('fun_'):
        a = a[4:]
    if a.startswith('0x'):
        a = a[2:]
    a = a.zfill(8)
    return '0x' + a


# ---------------------------------------------------------------------------
# docs/12 globals: DAT_addr -> name
# ---------------------------------------------------------------------------
def load_global_names():
    if 'global_names' in _cache:
        return _cache['global_names']
    names = {}
    path = os.path.join(DOCS_DIR, "12-globals-reference.md")
    row = re.compile(r'^\|\s*(DAT_[0-9a-fA-F]+)\s*\|\s*([^|]+?)\s*\|')
    try:
        with open(path, encoding='utf-8') as f:
            for line in f:
                m = row.match(line)
                if m:
                    names[m.group(1).lower()] = m.group(2).strip()
    except FileNotFoundError:
        pass
    _cache['global_names'] = names
    return names


# ---------------------------------------------------------------------------
# docs/13 struct offsets: "+0xNNN" -> [(struct_section, type, field), ...]
# Scoped by section: docs/13 holds MANY distinct structs (VehicleStruct,
# CameraStruct, UI controls...). A flat first-wins map silently attached the
# wrong struct's field name to an offset — worse than no label. Keep every
# candidate with its owning section so ambiguity is visible.
# ---------------------------------------------------------------------------
_SECTION_SKIP = re.compile(
    r'^(source:|summary|new struct offset|consolidated|multi-function|'
    r'unused|struct offset)', re.I)


def _section_tag(heading):
    """'VehicleStruct (param_1 — vehicle struct)' -> 'VehicleStruct'"""
    h = heading.strip().strip('#').strip()
    m = re.match(r'[A-Za-z_][\w/]*', h)
    return m.group(0) if m else h[:24]


def load_struct_offsets():
    if 'struct_offsets' in _cache:
        return _cache['struct_offsets']
    offs = {}
    # Match rows like: | +0x1db4 | double | Effective engine lifetime |
    row = re.compile(r'^\|\s*(\+0x[0-9a-fA-F]+)[^|]*\|\s*([^|]+?)\s*\|\s*([^|]+?)\s*\|')
    for fname in ("13-struct-offsets.md", "13-audit-report.md"):
        path = os.path.join(DOCS_DIR, fname)
        section = '?'
        try:
            with open(path, encoding='utf-8', errors='replace') as f:
                for line in f:
                    if line.startswith('#'):
                        h = line.strip('#').strip()
                        if h and not _SECTION_SKIP.match(h):
                            section = _section_tag(h)
                        continue
                    m = row.match(line)
                    if m:
                        key = m.group(1).lower()
                        rec = (section, m.group(2).strip(), m.group(3).strip())
                        cands = offs.setdefault(key, [])
                        # dedup same section (13-audit re-lists synthesized rows)
                        if not any(c[0] == section for c in cands):
                            cands.append(rec)
        except FileNotFoundError:
            pass
    _cache['struct_offsets'] = offs
    return offs


# addr, then ANY separator run (real dash, colon, or mojibake em-dash bytes), then title
_DOC_TITLE_RE = re.compile(r'^#{2,4}\s*FUN_([0-9a-fA-F]{6,8})\b(.*)$')


def _clean_title(raw):
    # strip leading separators/whitespace/mojibake junk before the real title text
    t = raw.strip()
    while t and (t[0].isspace() or not (t[0].isalnum())):
        t = t[1:]
    return t[:60].strip()


def _load_doc_titles():
    """addr -> H2/H3 title from docs/*.md '## FUN_xxxx — Title' headers."""
    if 'doc_titles' in _cache:
        return _cache['doc_titles']
    titles = {}
    for path in glob.glob(os.path.join(DOCS_DIR, "*.md")):
        try:
            with open(path, encoding='utf-8', errors='replace') as f:
                for ln in f:
                    if ln.startswith('#') and 'FUN_' in ln:
                        m = _DOC_TITLE_RE.match(ln.strip())
                        if m:
                            title = _clean_title(m.group(2))
                            if title:
                                titles.setdefault(_norm(m.group(1)), title)
        except OSError:
            pass
    _cache['doc_titles'] = titles
    return titles


def func_name(addr):
    funcs = _load_json('functions.json')
    info = funcs.get(addr)
    if info:
        n = info.get('name', '')
        if n and n not in ('Unknown', '--'):
            return n
    # fallback: the human-written doc heading (often present where the graph says "Unknown")
    return _load_doc_titles().get(addr, '')


def _decompiled_dirs():
    return [
        ANALYZED_DIR,
        os.path.join(PROJ_ROOT, "decompiled_all"),
        os.path.join(PROJ_ROOT, "decompiled_full"),
        os.path.join(PROJ_ROOT, "tools", "decompiled_ida"),
    ]


def find_source(addr):
    """Locate the decompiled .c file for an address."""
    hexpart = addr[2:]
    for d in _decompiled_dirs():
        matches = glob.glob(os.path.join(d, f"0x{hexpart}__*.c"))
        if matches:
            return matches[0]
    return None


def _addr_from_name(name):
    """Extract the owning function address from a decompiled filename."""
    m = re.match(r'0x([0-9a-fA-F]{8})__', name)
    if m:
        return _norm(m.group(1))
    m = re.search(r'FUN_([0-9a-fA-F]{6,8})', name)  # e.g. TrackAggression__FUN_00424080.c
    return _norm(m.group(1)) if m else None


def scan_decompiled(token):
    """
    Ground truth: grep every decompiled .c body for `token`, return {addr: hits}.
    Used where the knowledge graph is incomplete (it misses some globals/edges).
    Uses ripgrep when available, else a pure-Python walk.
    """
    dirs = [d for d in _decompiled_dirs() if os.path.isdir(d)]
    results = {}
    rg = shutil.which('rg')
    if rg:
        try:
            out = subprocess.run(
                [rg, '-c', '-i', '--no-messages', '-F', token, *dirs],
                capture_output=True, text=True, timeout=90)
            for line in out.stdout.splitlines():
                path, _, cnt = line.rpartition(':')
                addr = _addr_from_name(os.path.basename(path))
                if addr and cnt.isdigit():
                    results[addr] = results.get(addr, 0) + int(cnt)
            if results or out.returncode in (0, 1):
                return results
        except Exception:
            pass
    tl = token.lower()
    for d in dirs:
        try:
            names = os.listdir(d)
        except OSError:
            continue
        for name in names:
            if not name.endswith('.c'):
                continue
            addr = _addr_from_name(name)
            if not addr:
                continue
            try:
                with open(os.path.join(d, name), encoding='utf-8', errors='replace') as f:
                    c = f.read().lower().count(tl)
            except OSError:
                continue
            if c:
                results[addr] = results.get(addr, 0) + c
    return results


# ---------------------------------------------------------------------------
# Offset decoding
# ---------------------------------------------------------------------------
INT_TYPE_SIZE = {
    'char': 1, 'byte': 1, 'undefined1': 1, 'bool': 1,
    'short': 2, 'undefined2': 2, 'ushort': 2, 'wchar': 2,
    'int': 4, 'uint': 4, 'undefined4': 4, 'float': 4, 'long': 4, 'ulong': 4,
    'double': 8, 'undefined8': 8, '__int64': 8, 'longlong': 8,
}

# *(type *)(base + offset)   -> direct byte offset
CAST_RE = re.compile(
    r'\*\(\s*([A-Za-z_][\w ]*?)\s*\*\s*\)\s*\(\s*([^)]+?)\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)'
)
# name[index]  -> int-indexed, byte = index * 4
INDEX_RE = re.compile(r'\b(param_\d+|[a-zA-Z_]\w*)\s*\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]')


def _to_int(tok):
    return int(tok, 16) if tok.lower().startswith('0x') else int(tok)


# Any base reached through an offset this large is a real struct pointer, not a
# stack local: no MSVC stack frame here is 4 KB, and the vehicle struct is 0x48C0.
STRUCT_MIN_OFFSET = 0x1000

PARAM_RE = re.compile(r'^param_\d+$')
# LHS = param_N   (direct alias of the struct pointer)
ALIAS_RE = re.compile(r'\b([A-Za-z_]\w*)\s*=\s*(param_\d+)\b')
# strip a leading deref so "*param_1" classifies by its inner base
_LEAD_STAR = re.compile(r'^\**')


def _base_token(base):
    """Bare identifier of a base expr, ignoring a leading deref."""
    b = _LEAD_STAR.sub('', base).strip()
    m = re.match(r'[A-Za-z_]\w*', b)
    return m.group(0) if m else b


def decode_offsets(src):
    """
    Return (struct_rows, other_rows).

    struct_rows: accesses through the struct pointer (param_N) or a proven /
                 offset-implied alias of it -> docs/13 field names attached.
    other_rows:  accesses through stack locals / element-walk pointers -> NO
                 docs/13 lookup (attaching vehicle-struct names there is wrong).
    """
    struct_offs = load_struct_offsets()
    found = {}  # dedup key -> record

    def add(base, byte, form, index, chain, ctype):
        btok = _base_token(base)
        key = (btok, byte, index, chain)
        rec = found.setdefault(key, {
            'base': btok, 'form': form, 'index': index, 'byte': byte,
            'type': ctype, 'chain': chain, 'count': 0,
        })
        rec['count'] += 1

    for m in CAST_RE.finditer(src):
        ctype, base, off = m.group(1).strip(), m.group(2).strip(), m.group(3)
        byte = _to_int(off)
        chain = base.strip().startswith('*')
        add(base, byte, f'*({ctype} *)({base} + {off})', None, chain, ctype)

    for m in INDEX_RE.finditer(src):
        base, idx = m.group(1), m.group(2)
        idx_val = _to_int(idx)
        add(base, idx_val * 4, f'{base}[{idx}]', idx_val, False, 'int (idx*4)')

    # --- classify bases as struct-pointer or not ---
    struct_bases = {b for b in {r['base'] for r in found.values()} if PARAM_RE.match(b)}
    # any base ever reached through a big offset is a struct pointer
    maxoff = {}
    for r in found.values():
        maxoff[r['base']] = max(maxoff.get(r['base'], 0), r['byte'])
    struct_bases |= {b for b, mx in maxoff.items() if mx >= STRUCT_MIN_OFFSET}
    # direct aliases: X = param_N, or X = <known struct base>
    for _ in range(3):  # transitive closure, a few passes is plenty
        for lhs, rhs in ALIAS_RE.findall(src):
            if rhs in struct_bases:
                struct_bases.add(lhs)

    for rec in found.values():
        rec['struct'] = rec['base'] in struct_bases
        if rec['struct']:
            cands = struct_offs.get(f'+0x{rec["byte"]:x}', [])
            if len(cands) == 1:
                sec, ty, fld = cands[0]
                rec['field'] = f'{fld} [{ty}|{sec}]'
            elif cands:
                # ambiguous across structs — show candidates, never pick silently
                shown = '; '.join(f'{fld[:24]} [{sec}]' for sec, ty, fld in cands[:2])
                more = f' +{len(cands)-2}?' if len(cands) > 2 else ' ?'
                rec['field'] = shown + more
            else:
                rec['field'] = ''
        else:
            rec['field'] = ''  # never map non-struct bases to docs/13

    rows = sorted(found.values(), key=lambda r: (r['byte'], r['base']))
    return [r for r in rows if r['struct']], [r for r in rows if not r['struct']]


def print_offset_table(src):
    struct_rows, other_rows = decode_offsets(src)
    if not struct_rows and not other_rows:
        print("  (no struct offset accesses detected)")
        return

    if struct_rows:
        print(f"  {'byte':>8}  {'int-idx':>8}  {'x':>2}  {'base':10s}  {'form':38s}  known field (docs/13)")
        print(f"  {'-'*8}  {'-'*8}  {'-'*2}  {'-'*10}  {'-'*38}  {'-'*30}")
        for r in struct_rows:
            byte = f'+0x{r["byte"]:x}'
            idx = f'0x{r["index"]:x}' if r['index'] is not None else '-'
            chain = '↳' if r['chain'] else ''
            cnt = f'×{r["count"]}' if r['count'] > 1 else ''
            print(f"  {byte:>8}  {idx:>8}  {chain:>2}  {r['base']:10s}  {r['form'][:38]:38s}  {r['field']}  {cnt}")
        if any(r['chain'] for r in struct_rows):
            print("  (↳ = pointer-chain base like *param_1; offset is into a SUB-object)")
    else:
        print("  (no struct-pointer accesses; see local/other accesses below)")

    if other_rows:
        print(f"\n  local / non-struct-pointer accesses (NO docs/13 mapping — likely stack or element-walk):")
        compact = ", ".join(sorted({r['form'][:34] for r in other_rows}))
        print(f"    {compact[:1000]}")


# ---------------------------------------------------------------------------
# Globals + calls in a source body
# ---------------------------------------------------------------------------
DAT_RE = re.compile(r'\bDAT_[0-9a-fA-F]+\b')
FUN_RE = re.compile(r'\bFUN_[0-9a-fA-F]+\b')


def print_globals(src):
    names = load_global_names()
    hits = sorted(set(DAT_RE.findall(src)))
    if not hits:
        print("  (none)")
        return
    for g in hits:
        nm = names.get(g.lower(), '')
        print(f"  {g:18s}  {nm if nm else '(unnamed in docs/12)'}")


def print_calls(src, self_addr):
    hits = sorted(set(FUN_RE.findall(src)))
    printed = False
    for f in hits:
        a = _norm(f)
        if a == self_addr:
            continue
        nm = func_name(a)
        print(f"  {f:20s}  {nm}")
        printed = True
    if not printed:
        print("  (none)")


def print_graph_edges(addr):
    call_graph = _load_json('call_graph.json')
    callers_graph = _load_json('callers.json')
    calls = call_graph.get(addr, [])
    callers = callers_graph.get(addr, [])
    if calls:
        print(f"  callees ({len(calls)}): " +
              ", ".join(f"FUN_{c['callee'][2:].upper()}" +
                        (f"({func_name(c['callee'])[:24]})" if func_name(c['callee']) else "")
                        for c in calls[:20]))
    if callers:
        suffix = f" +{len(callers)-20} more" if len(callers) > 20 else ""
        print(f"  callers ({len(callers)}): " +
              ", ".join(f"FUN_{c['caller'][2:].upper()}" +
                        (f"({func_name(c['caller'])[:24]})" if func_name(c['caller']) else "")
                        for c in callers[:20]) + suffix)
    if not calls and not callers:
        print("  (no static edges in graph — may be vtable/callback-dispatched)")


# ---------------------------------------------------------------------------
# Identity enrichment — source atlas, vtables, mod-targets (work/*.csv)
# ---------------------------------------------------------------------------
import csv as _csv

ATLAS_CSV = os.path.join(PROJ_ROOT, "work", "source_atlas.csv")
SFMAP_CSV = os.path.join(PROJ_ROOT, "work", "source_file_map_expanded.csv")
VTABLE_CSV = os.path.join(PROJ_ROOT, "work", "vtables.csv")
MODTGT_CSV = os.path.join(PROJ_ROOT, "work", "mod_targets.csv")
FPCONST_CSV = os.path.join(PROJ_ROOT, "work", "fp_constants.csv")


def _load_atlas():
    """addr(wrapper or target) -> (file,line,class,method,message)"""
    if 'atlas' in _cache:
        return _cache['atlas']
    m = {}
    try:
        with open(ATLAS_CSV, encoding='utf-8', errors='replace') as f:
            for r in _csv.DictReader(f):
                info = (r.get('file', ''), r.get('line', ''), r.get('cls', ''),
                        r.get('method', ''), r.get('message', ''))
                for col in ('wrapper_addr', 'target_addr'):
                    a = _norm(r.get(col, '')) if r.get(col) else ''
                    if a:
                        m.setdefault(a, info)
    except FileNotFoundError:
        pass
    _cache['atlas'] = m
    return m


def _load_sfmap():
    """addr -> (file, confidence)  (ANCHOR/HIGH only — the usable ones)"""
    if 'sfmap' in _cache:
        return _cache['sfmap']
    m = {}
    try:
        with open(SFMAP_CSV, encoding='utf-8', errors='replace') as f:
            for r in _csv.DictReader(f):
                if r.get('confidence') in ('ANCHOR', 'HIGH') and r.get('file'):
                    m[_norm(r['func_addr'])] = (r['file'], r['confidence'])
    except FileNotFoundError:
        pass
    _cache['sfmap'] = m
    return m


def _load_vtables():
    """method_addr -> [(vtable,slot,nslots)] ; ctor_addr -> [(vtable,nslots)]"""
    if 'vtables' in _cache:
        return _cache['vtables']
    meth, ctor = {}, {}
    try:
        with open(VTABLE_CSV, encoding='utf-8', errors='replace') as f:
            for r in _csv.DictReader(f):
                if r.get('kind') != 'vtable':
                    continue
                vb = r['vtable_addr']
                slots = r['method_addrs'].split('|')
                n = len(slots)
                for i, s in enumerate(slots):
                    meth.setdefault(_norm(s), []).append((vb, i, n))
                for c in r.get('ctor_funcs', '').split('|'):
                    if c:
                        ctor.setdefault(_norm(c), []).append((vb, n))
    except FileNotFoundError:
        pass
    _cache['vtables'] = (meth, ctor)
    return meth, ctor


def _load_modtargets():
    """addr -> [(rank,category,string)]"""
    if 'modtgt' in _cache:
        return _cache['modtgt']
    m = {}
    try:
        with open(MODTGT_CSV, encoding='utf-8', errors='replace') as f:
            for r in _csv.DictReader(f):
                m.setdefault(_norm(r['func_addr']), []).append(
                    (r.get('rank', ''), r.get('category', ''), r.get('string', '')))
    except FileNotFoundError:
        pass
    _cache['modtgt'] = m
    return m


def _load_fp_by_func():
    """func_addr -> sorted list of distinct constant values it reads."""
    if 'fp_by_func' in _cache:
        return _cache['fp_by_func']
    m = {}
    try:
        with open(FPCONST_CSV, encoding='utf-8', errors='replace') as f:
            for r in _csv.DictReader(f):
                for fn in (r.get('ref_funcs') or '').split('|'):
                    if fn:
                        m.setdefault(_norm(fn), set()).add(r.get('value', ''))
    except FileNotFoundError:
        pass
    _cache['fp_by_func'] = m
    return m


def print_identity(addr):
    """Real source file/line/name, vtable role, mod-target flag for one addr."""
    addr = _norm(addr)
    lines = []

    a = _load_atlas().get(addr)
    if a:
        fl, ln, cls, meth, msg = a
        name = f"{cls}::{meth}" if cls and meth else (msg or "")
        loc = f"{fl}:{ln}" if fl else ""
        lines.append(f"  source (atlas, FACT): {loc}" + (f"  {name}" if name else ""))
    else:
        sf = _load_sfmap().get(addr)
        if sf:
            lines.append(f"  source file ({sf[1]}): {sf[0]}")

    meth, ctor = _load_vtables()
    if addr in ctor:
        for vb, n in ctor[addr][:3]:
            lines.append(f"  vtable: CONSTRUCTS {vb} ({n} virtual methods)")
    if addr in meth:
        for vb, i, n in meth[addr][:3]:
            lines.append(f"  vtable: method slot {i} of {vb} ({n} slots) — vtable-swap hookable")

    for rank, cat, s in _load_modtargets().get(addr, [])[:4]:
        tag = "CONFIRMED" if addr == '0x004bc0e0' else "candidate"
        lines.append(f"  MOD-TARGET [{cat} r{rank}, {tag}]: {s[:60]}")

    fp = _load_fp_by_func().get(addr)
    if fp:
        vals = sorted(fp, key=lambda v: (len(v), v))[:12]
        lines.append(f"  FP constants read ({len(fp)}): " + ", ".join(vals))

    if lines:
        print("\n-- identity (atlas / vtable / mod-target) --")
        for ln_ in lines:
            print(ln_)


# ---------------------------------------------------------------------------
# Snippet extraction — only the decisive lines of a .c body
# ---------------------------------------------------------------------------
_HEX_CMP_RE = re.compile(r'[<>=!]=?\s*-?0x[0-9a-fA-F]+|[<>=!]=?\s*-?\d+\.\d')


def _interesting_line(ln):
    return bool(DAT_RE.search(ln) or FUN_RE.search(ln) or
                CAST_RE.search(ln) or INDEX_RE.search(ln) or
                _HEX_CMP_RE.search(ln) or
                re.search(r'\breturn\b', ln))


def print_snippet(src, max_lines=120):
    """Lines touching globals / struct offsets / calls / constants / returns,
    ±1 context, gaps marked. 5-10x cheaper than full dump for sweeps."""
    lines = src.splitlines()
    keep = set()
    for i, ln in enumerate(lines):
        if _interesting_line(ln):
            keep.update((i - 1, i, i + 1))
    shown, prev = 0, -2
    for i in sorted(k for k in keep if 0 <= k < len(lines)):
        if shown >= max_lines:
            print(f"    ... snippet capped at {max_lines} lines")
            break
        if i > prev + 1:
            print("    ...")
        print(f"  {i+1:4d}| {lines[i].rstrip()[:110]}")
        prev = i
        shown += 1


# ---------------------------------------------------------------------------
# Dossier for one function
# ---------------------------------------------------------------------------
def dossier(addr, source_mode='full'):
    addr = _norm(addr)
    nm = func_name(addr)
    src_path = find_source(addr)

    print("=" * 78)
    print(f"  FUN_{addr[2:].upper()}" + (f" — {nm}" if nm else ""))
    print("=" * 78)

    print_identity(addr)

    print("\n-- graph edges --")
    print_graph_edges(addr)

    if not src_path:
        print("\n  !! no .c source found for this address")
        return

    with open(src_path, encoding='utf-8') as f:
        src = f.read()

    print(f"\n-- struct offsets (auto-decoded, byte = int-index×4) --")
    print_offset_table(src)

    print(f"\n-- globals referenced --")
    print_globals(src)

    print(f"\n-- functions called (name-resolved) --")
    print_calls(src, addr)

    rel = os.path.relpath(src_path, PROJ_ROOT)
    if source_mode == 'full':
        print(f"\n-- source: {rel} --")
        print(src.rstrip())
    elif source_mode == 'snippet':
        print(f"\n-- source snippet (decisive lines only): {rel} --")
        print_snippet(src)
    print()


# ---------------------------------------------------------------------------
# LOCATOR — concept/term -> ranked addresses. Fuses string-refs, function
# names/summaries, globals, and doc headings so you never guess a grep again.
# ---------------------------------------------------------------------------
import csv

IDA_STRINGS = os.path.join(PROJ_ROOT, "tools", "ida_strings.csv")


def _load_string_refs():
    """value(lower) -> list of (string, [addrs])  from ida_strings.csv."""
    if 'string_refs' in _cache:
        return _cache['string_refs']
    rows = []
    try:
        with open(IDA_STRINGS, encoding='utf-8', errors='replace') as f:
            for r in csv.DictReader(f):
                val = (r.get('value') or '').strip()
                refs = [_norm(a) for a in (r.get('ref_funcs') or '').split('|') if a.strip()]
                if val:
                    rows.append((val, sorted(set(refs))))
    except FileNotFoundError:
        pass
    _cache['string_refs'] = rows
    return rows


def scan_docs(term, max_files=None):
    """Full-text scan of docs/ (recursive: includes 30-impl-specs, 31-call-chains).
    Returns [(relpath, hitcount, sample_line)] ranked by hits."""
    t = term.lower()
    results = {}
    rg = shutil.which('rg')
    if rg:
        try:
            out = subprocess.run(
                [rg, '-n', '-i', '--no-messages', '-F', '-g', '*.md', term, DOCS_DIR],
                capture_output=True, text=True, timeout=60)
            if out.returncode in (0, 1):
                for line in out.stdout.splitlines():
                    m = re.match(r'^(.*?):(\d+):(.*)$', line)
                    if not m:
                        continue
                    rel = os.path.relpath(m.group(1), PROJ_ROOT).replace('\\', '/')
                    cnt, sample = results.get(rel, (0, m.group(3).strip()))
                    results[rel] = (cnt + 1, sample)
                return sorted(((p, c, s) for p, (c, s) in results.items()),
                              key=lambda r: -r[1])
        except Exception:
            pass
    for root, _dirs, names in os.walk(DOCS_DIR):
        for name in names:
            if not name.endswith('.md'):
                continue
            path = os.path.join(root, name)
            try:
                with open(path, encoding='utf-8', errors='replace') as f:
                    cnt, sample = 0, ''
                    for ln in f:
                        if t in ln.lower():
                            cnt += 1
                            if not sample:
                                sample = ln.strip()
                    if cnt:
                        rel = os.path.relpath(path, PROJ_ROOT).replace('\\', '/')
                        results[rel] = (cnt, sample)
            except OSError:
                continue
    return sorted(((p, c, s) for p, (c, s) in results.items()), key=lambda r: -r[1])


def cmd_find(term):
    """Locate anything matching `term` across strings, functions, globals, docs."""
    t = term.lower()
    funcs = _load_json('functions.json')
    # addr -> set of (source, detail) reasons
    hits = {}

    def note(addr, source, detail):
        addr = _norm(addr)
        hits.setdefault(addr, []).append((source, detail))

    # 1) string literals -> referencing functions (the big unused index)
    str_matches = []
    for val, refs in _load_string_refs():
        if t in val.lower():
            str_matches.append((val, refs))
            for a in refs:
                note(a, 'string', f'"{val[:50]}"')

    # 2) function names / summaries / algorithm family
    for addr, info in funcs.items():
        blob = ' '.join(str(info.get(k, '')) for k in
                        ('name', 'summary', 'algorithm_family', 'triage_category')).lower()
        if t in blob:
            note(addr, 'name/summary', (info.get('name') or '')[:50])

    # 3) globals (docs/12): name or address
    gmatches = []
    for gaddr, gname in load_global_names().items():
        if t in gname.lower() or t in gaddr.lower():
            gmatches.append((gaddr, gname))

    # 4) doc section headings
    doc_hits = []
    for path in glob.glob(os.path.join(DOCS_DIR, "*.md")):
        try:
            with open(path, encoding='utf-8', errors='replace') as f:
                for ln in f:
                    if ln.startswith('#') and t in ln.lower():
                        doc_hits.append((os.path.basename(path), ln.strip('#').strip()[:70]))
        except OSError:
            pass

    # ---- rank & print ----
    # score: string-ref hits are strongest signal, then name, then multi-source
    def score(addr):
        srcs = hits[addr]
        s = 0
        s += 5 * sum(1 for x in srcs if x[0] == 'string')
        s += 3 * sum(1 for x in srcs if x[0] == 'name/summary')
        s += len({x[0] for x in srcs})  # multi-source bonus
        return s

    print(f"\n=== find: '{term}' ===")

    if hits:
        print(f"\nFUNCTIONS ({len(hits)}) — feed any into: python tools/investigate.py <addr>")
        ranked = sorted(hits, key=lambda a: (-score(a), a))
        for addr in ranked[:25]:
            nm = func_name(addr)
            doc = funcs.get(addr, {}).get('doc_file', '')
            why = '; '.join(sorted({f'{s}:{d}' for s, d in hits[addr]}))[:80]
            print(f"  {addr}  {nm[:34]:34s}  [{doc}]  {why}")
        if len(ranked) > 25:
            print(f"  ... {len(ranked)-25} more")
    else:
        print("\nFUNCTIONS: none")

    if gmatches:
        print(f"\nGLOBALS ({len(gmatches)}) — feed into: python tools/investigate.py global <DAT_>")
        for gaddr, gname in gmatches[:15]:
            print(f"  {gaddr}  {gname[:60]}")
        if len(gmatches) > 15:
            print(f"  ... {len(gmatches)-15} more")

    if doc_hits:
        print(f"\nDOC SECTIONS ({len(doc_hits)}):")
        for fn, head in doc_hits[:15]:
            print(f"  docs/{fn}  {head}")
        if len(doc_hits) > 15:
            print(f"  ... {len(doc_hits)-15} more")

    # full-text over ALL docs bodies (impl-specs, call-chains, field semantics)
    body_hits = scan_docs(term)
    if body_hits:
        print(f"\nDOC CONTENT ({len(body_hits)} files) — impl-specs/call-chains often ARE the answer:")
        for rel, cnt, sample in body_hits[:12]:
            print(f"  {rel:58s} ×{cnt:<4d} {sample[:55]}")
        if len(body_hits) > 12:
            print(f"  ... {len(body_hits)-12} more files")

    if str_matches and not hits:
        print(f"\n(matched {len(str_matches)} strings but none had function xrefs)")

    if not hits and not gmatches and not doc_hits:
        print("  nothing found — try a shorter / different term")
    print()


def cmd_global(gaddr):
    """Global usage — knowledge graph MERGED with a raw .c scan (graph misses some)."""
    names = load_global_names()
    key = gaddr
    if not gaddr.lower().startswith('dat_'):
        key = 'DAT_' + _norm(gaddr)[2:]
    hexpart = _norm(key[4:] if key.lower().startswith('dat_') else key)[2:]

    guse = _load_json('globals_usage.json')
    graph_fns = {}
    for k, v in guse.items():
        if k.lower() == key.lower():
            for u in v.get('functions', []):
                graph_fns[_norm(u['function'])] = u.get('access', '?')
            break

    # ground-truth scan for the bare hex (catches DAT_, _DAT_, PTR_..._<hex>)
    scan_fns = scan_decompiled(hexpart)

    all_addrs = sorted(set(graph_fns) | set(scan_fns))
    nm = names.get(key.lower(), '')
    print(f"\n{key}  {nm}")
    print(f"  {len(all_addrs)} functions reference this "
          f"(graph:{len(graph_fns)}  scan:{len(scan_fns)})")
    for a in all_addrs[:60]:
        src = 'graph+scan' if (a in graph_fns and a in scan_fns) else \
              ('graph-only' if a in graph_fns else 'scan-only')
        acc = graph_fns.get(a, '')
        print(f"    {a}  {func_name(a)[:38]:38s}  {src} {acc}")
    if len(all_addrs) > 60:
        print(f"    ... {len(all_addrs)-60} more")
    if not all_addrs:
        print("  (not referenced in any decompiled .c — may be data-only / unnamed)")
    print()


def scan_decompiled_lines(token):
    """Like scan_decompiled but returns {addr: [(lineno, text), ...]} for context."""
    dirs = [d for d in _decompiled_dirs() if os.path.isdir(d)]
    out_map = {}
    rg = shutil.which('rg')
    if rg:
        try:
            out = subprocess.run(
                [rg, '-n', '-i', '--no-messages', '-F', token, *dirs],
                capture_output=True, text=True, timeout=90)
            if out.returncode in (0, 1):
                for line in out.stdout.splitlines():
                    # path:lineno:text
                    m = re.match(r'^(.*?):(\d+):(.*)$', line)
                    if not m:
                        continue
                    addr = _addr_from_name(os.path.basename(m.group(1)))
                    if addr:
                        out_map.setdefault(addr, []).append((int(m.group(2)), m.group(3).strip()))
                if out_map:
                    return out_map
        except Exception:
            pass
    tl = token.lower()
    for d in dirs:
        try:
            names = os.listdir(d)
        except OSError:
            continue
        for name in names:
            if not name.endswith('.c'):
                continue
            addr = _addr_from_name(name)
            if not addr:
                continue
            try:
                with open(os.path.join(d, name), encoding='utf-8', errors='replace') as f:
                    for i, ln in enumerate(f, 1):
                        if tl in ln.lower():
                            out_map.setdefault(addr, []).append((i, ln.strip()))
            except OSError:
                continue
    return out_map


_ASSIGN_RE = re.compile(r'[<>=!]=|[-+*/&|^]=|=')


def _rw_tag(line, token):
    """W if the token-access is written on this line, else R. Heuristic but reliable
    for Ghidra output: an access followed by a bare '=' (not ==,<=,+=, etc.) is a write."""
    idx = line.lower().find(token.lower())
    if idx < 0:
        return 'R'
    after = line[idx + len(token):]
    m = _ASSIGN_RE.search(after)
    if m and m.group(0) == '=':
        # bare assignment after the access, and nothing that re-reads it first
        return 'W'
    return 'R'


def cmd_uses(token):
    """Raw ground-truth: which functions' .c bodies contain `token`, WITH sample line + R/W.
    Token = any literal — a DAT_ address, a bare hex, a struct offset, an identifier."""
    lines_map = scan_decompiled_lines(token)
    print(f"\n=== uses: '{token}' ===")
    if not lines_map:
        print("  no decompiled function contains that token")
        print("  (tip: for a global try the bare hex, e.g. 007d017c not DAT_007d017c)")
        return

    funcs = _load_json('functions.json')
    # per-function: count, W if any write line, one representative sample (prefer a write)
    rows = []
    for a, lns in lines_map.items():
        tags = [_rw_tag(t, token) for _, t in lns]
        is_w = 'W' in tags
        # prefer showing a write line, else the first
        sample = next(((n, t) for (n, t), tg in zip(lns, tags) if tg == 'W'), lns[0])
        rows.append((a, len(lns), is_w, sample))

    # writers first (usually what you want), then by hit count
    rows.sort(key=lambda r: (not r[2], -r[1], r[0]))
    nw = sum(1 for r in rows if r[2])
    print(f"{len(rows)} functions ({nw} write, {len(rows)-nw} read-only) "
          f"— W = writes the field, R = reads only\n")
    for a, cnt, is_w, (lineno, text) in rows[:40]:
        tag = 'W' if is_w else 'R'
        c = f'×{cnt}' if cnt > 1 else ''
        print(f"  [{tag}] {a}  {func_name(a)[:30]:30s} {c:4s}  L{lineno}: {text[:60]}")
    if len(rows) > 40:
        print(f"  ... {len(rows)-40} more")
    print()


# ---------------------------------------------------------------------------
# SYSTEM — concept -> whole-subsystem map in one screen. The modding entry
# point: functions + names, shared globals, impl spec, call chains, patch
# points, vtable hooks. Replaces "find + N dossiers + mental reassembly".
# ---------------------------------------------------------------------------
IMPL_SPEC_DIR = os.path.join(DOCS_DIR, "30-impl-specs")
CALL_CHAIN_DIR = os.path.join(DOCS_DIR, "31-call-chains")


def _doc_stem(doc_key):
    """'docs/04-tire-system.md' -> 'tire system'"""
    base = os.path.basename(doc_key)
    base = re.sub(r'^\d+-', '', base)
    return base.rsplit('.md', 1)[0].replace('-', ' ')


def _list_md(dirpath):
    try:
        return sorted(n for n in os.listdir(dirpath) if n.endswith('.md'))
    except OSError:
        return []


def cmd_system(term):
    t = term.lower()
    systems = _load_json('systems.json')

    matched = [k for k in systems if t in _doc_stem(k).lower() or t in k.lower()]
    specs = [n for n in _list_md(IMPL_SPEC_DIR) if t in n.replace('-', ' ')]
    chains = [n for n in _list_md(CALL_CHAIN_DIR) if t in n.replace('-', ' ')]

    print(f"\n=== system: '{term}' ===")
    if not matched and not specs and not chains:
        print("  no doc/spec/chain name matches — try `find` for full-text search")
        return
    if len(matched) > 1:
        print(f"\nmatched {len(matched)} system docs (detailing first):")
        for k in matched:
            print(f"  {k}  ({systems[k].get('function_count', '?')} functions)")

    for doc_key in matched[:1]:
        info = systems[doc_key]
        fns = info.get('functions', [])
        addrs = {_norm(f['address']) for f in fns}

        # moddability breakdown
        modd = {}
        for f in fns:
            raw = (f.get('moddability') or 'unknown').split()[0]
            m = raw.lower().strip('`.,—-') or 'unknown'
            if m not in ('hardcoded', 'configurable', 'hookable', 'yes', 'no',
                         'partial', 'unknown'):
                m = 'other'
            modd[m] = modd.get(m, 0) + 1
        breakdown = ', '.join(f'{k}:{v}' for k, v in
                              sorted(modd.items(), key=lambda x: -x[1]))
        print(f"\n{doc_key} — {len(fns)} functions  [{breakdown}]")

        # functions, named ones first
        rows = []
        for f in fns:
            a = _norm(f['address'])
            nm = func_name(a)
            rows.append((a, nm, (f.get('moddability') or '')[:30]))
        rows.sort(key=lambda r: (not r[1], r[0]))
        for a, nm, md in rows[:40]:
            print(f"  {a}  {nm[:44]:44s}  {md}")
        if len(rows) > 40:
            print(f"  ... {len(rows)-40} more (see {doc_key})")

        # shared globals: which DAT_ are touched by the most functions here
        guse = _load_json('globals_usage.json')
        gnames = load_global_names()
        counts = []
        for g, v in guse.items():
            n = sum(1 for u in v.get('functions', [])
                    if _norm(u['function']) in addrs)
            if n >= 2:
                counts.append((n, g))
        counts.sort(reverse=True)
        if counts:
            print(f"\n  shared globals (touched by ≥2 system functions):")
            for n, g in counts[:12]:
                print(f"    {g:18s} ×{n:<3d} {gnames.get(g.lower(), '')[:50]}")

        # mod targets inside this system
        tgt = _load_modtargets()
        hits = [(a, r) for a in sorted(addrs) for r in tgt.get(a, [])]
        if hits:
            print(f"\n  MOD-TARGETS in this system ({len(hits)}):")
            for a, (rank, cat, s) in hits[:10]:
                print(f"    {a}  [{cat} r{rank}]  {s[:55]}")
            if len(hits) > 10:
                print(f"    ... {len(hits)-10} more (work/mod_targets.csv)")

        # vtable constructors inside this system (swap-hookable classes)
        meth, ctor = _load_vtables()
        vhits = [(a, ctor[a]) for a in sorted(addrs) if a in ctor]
        if vhits:
            print(f"\n  vtable constructors (class factories, swap-hookable):")
            for a, vts in vhits[:8]:
                vt = ', '.join(f'{vb}({n} slots)' for vb, n in vts[:2])
                print(f"    {a}  {func_name(a)[:34]:34s}  {vt}")

    if specs:
        print(f"\n  IMPL SPECS (read these first for reimplementation/mod design):")
        for n in specs[:6]:
            print(f"    docs/30-impl-specs/{n}")
    if chains:
        print(f"\n  CALL CHAINS ({len(chains)}):")
        for n in chains[:10]:
            print(f"    docs/31-call-chains/{n}")
        if len(chains) > 10:
            print(f"    ... {len(chains)-10} more")
    print("\n  next: python tools/investigate.py mod \"" + term + "\"  |  investigate.py <addr> --snippet")
    print()


# ---------------------------------------------------------------------------
# MOD — concept -> ranked patch surface. Fuses mod_targets.csv (byte patches),
# docs/16-moddable-fields.md (data-file params, no patch needed), writable
# globals (docs/12), and vtable hooks.
# ---------------------------------------------------------------------------
MODDABLE_MD = os.path.join(DOCS_DIR, "16-moddable-fields.md")


def _load_moddable_sections():
    """[(heading, source_line, [bullet_lines])] from docs/16-moddable-fields.md"""
    if 'moddable16' in _cache:
        return _cache['moddable16']
    secs = []
    cur = None
    try:
        with open(MODDABLE_MD, encoding='utf-8', errors='replace') as f:
            for ln in f:
                if ln.startswith('## '):
                    cur = [ln[3:].strip(), '', []]
                    secs.append(cur)
                elif cur is not None:
                    s = ln.strip()
                    if s.lower().startswith('source:'):
                        cur[1] = cur[1] or s
                    elif s.startswith('- '):
                        cur[2].append(s[2:])
                    elif s.startswith('|') and not re.match(r'^\|[\s:|-]+\|?$', s):
                        cur[2].append(s.strip('|').replace('|', ' — ').strip())
    except FileNotFoundError:
        pass
    _cache['moddable16'] = secs
    return secs


def cmd_mod(term):
    t = term.lower()
    print(f"\n=== mod: '{term}' ===")
    any_out = False

    # 1) data-file parameters — cheapest mod path, no byte patch
    sec_hits = []
    for head, src, bullets in _load_moddable_sections():
        bmatch = [b for b in bullets if t in b.lower()]
        if t in head.lower():
            sec_hits.append((head, src, bullets[:8]))
        elif bmatch:
            sec_hits.append((head, src, bmatch[:8]))
    if sec_hits:
        any_out = True
        print(f"\nDATA-FILE PARAMS (docs/16 — edit .svm/.hdv/.gdb etc., NO patch needed):")
        for head, src, bullets in sec_hits[:8]:
            print(f"  ## {head}" + (f"   [{src}]" if src else ""))
            for b in bullets:
                print(f"     - {b[:70]}")

    # 2) byte-patch targets — mod_targets.csv (docs/35 tiers apply)
    tgt_rows = []
    for addr, rows in _load_modtargets().items():
        for rank, cat, s in rows:
            if t in s.lower() or t in cat.lower():
                tgt_rows.append((int(rank or 0), addr, cat, s))
    if tgt_rows:
        any_out = True
        tgt_rows.sort(key=lambda r: (-r[0], r[1]))
        print(f"\nPATCH-POINTS ({len(tgt_rows)}) — string↔func xref = FACT; effect = HYPOTHESIS"
              f" unless marked CONFIRMED:")
        meth, _ctor = _load_vtables()
        for rank, addr, cat, s in tgt_rows[:15]:
            tag = 'CONFIRMED' if addr == '0x004bc0e0' else 'candidate'
            hook = '  [vtable-hookable]' if addr in meth else ''
            print(f"  r{rank} {addr}  [{cat}] {tag}{hook}  {s[:50]}")
            nm = func_name(addr)
            if nm:
                print(f"        = {nm[:60]}")
        if len(tgt_rows) > 15:
            print(f"  ... {len(tgt_rows)-15} more (work/mod_targets.csv)")

    # 3) writable globals — patch at runtime (process-attach) or find writer
    gmatches = [(a, n) for a, n in load_global_names().items() if t in n.lower()]
    if gmatches:
        any_out = True
        print(f"\nGLOBALS ({len(gmatches)}) — runtime-pokeable; `global <DAT_>` shows writers:")
        for a, n in gmatches[:10]:
            print(f"  DAT_{a[4:]}  {n[:60]}")
        if len(gmatches) > 10:
            print(f"  ... {len(gmatches)-10} more")

    if not any_out:
        print("  nothing in mod surface — try `system` or `find` first")
    print()


# ---------------------------------------------------------------------------
# PARAM — data-file field name -> the parser function that reads it, its file
# format, and its docs/16 section. Tier-1 modding: "I want to change X in a
# .hdv — which field, and does the engine even read it?"
# ---------------------------------------------------------------------------
def cmd_param(term):
    t = term.lower()
    secs = _load_moddable_sections()
    hits = []
    for head, src, bullets in secs:
        for b in bullets:
            if t in b.lower():
                hits.append((head, src, b))
    print(f"\n=== param: '{term}' ===")
    if not hits:
        # maybe they searched a section name
        shead = [(h, s, bs) for h, s, bs in secs if t in h.lower()]
        if shead:
            for h, s, bs in shead[:4]:
                print(f"\n## {h}   {s}")
                for b in bs[:12]:
                    print(f"   - {b[:72]}")
            return
        print("  no docs/16 field matches — try `find` or `mod`")
        return

    # group by parser function
    by_parser = {}
    for head, src, b in hits:
        m = re.search(r'FUN_[0-9a-fA-F]+', src)
        parser = m.group(0) if m else '(parser not recorded)'
        by_parser.setdefault(parser, []).append((head, src, b))

    for parser, rows in by_parser.items():
        head, src, _ = rows[0]
        # strip "Source: `FUN_...` (... parser)," prefix, keep the file/format tail
        fmt = re.sub(r'^source:\s*`?FUN_[0-9a-fA-F]+`?\s*(\([^)]*\))?,?\.?\s*',
                     '', src, flags=re.I).strip(' ,.') if src else ''
        print(f"\n  parser: {parser}   section: {head}")
        if fmt:
            print(f"  file/format: {fmt[:70]}")
        for _h, _s, b in rows[:12]:
            print(f"     - {b[:72]}")
        if parser.startswith('FUN_'):
            a = _norm(parser)
            print(f"  -> dossier: python tools/investigate.py {a}")
            # show what the parser reads/writes at a glance
            src_path = find_source(a)
            if src_path:
                nm = func_name(a)
                print(f"     {parser} = {nm}" if nm else f"     {parser}")
    print()


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    flags = {a for a in sys.argv[1:] if a.startswith('--')}

    if not args:
        print(__doc__)
        return

    # subcommands
    if args[0] == 'find':
        if len(args) < 2:
            print("usage: python tools/investigate.py find <term>")
            return
        cmd_find(' '.join(args[1:]))
        return
    if args[0] == 'global':
        if len(args) < 2:
            print("usage: python tools/investigate.py global <DAT_addr|addr>")
            return
        cmd_global(args[1])
        return
    if args[0] == 'uses':
        if len(args) < 2:
            print("usage: python tools/investigate.py uses <token>   (DAT_/hex/offset/identifier)")
            return
        cmd_uses(' '.join(args[1:]))
        return
    if args[0] == 'system':
        if len(args) < 2:
            print("usage: python tools/investigate.py system <term>")
            return
        cmd_system(' '.join(args[1:]))
        return
    if args[0] == 'mod':
        if len(args) < 2:
            print("usage: python tools/investigate.py mod <term>")
            return
        cmd_mod(' '.join(args[1:]))
        return
    if args[0] == 'param':
        if len(args) < 2:
            print("usage: python tools/investigate.py param <field-name>")
            return
        cmd_param(' '.join(args[1:]))
        return

    if '--no-source' in flags:
        source_mode = 'none'
    elif '--snippet' in flags:
        source_mode = 'snippet'
    else:
        source_mode = 'full'
    follow_callees = '--callees' in flags

    targets = [_norm(a) for a in args]

    if follow_callees:
        call_graph = _load_json('call_graph.json')
        extra = []
        for a in list(targets):
            for c in call_graph.get(a, []):
                if c['callee'] not in targets and c['callee'] not in extra:
                    extra.append(c['callee'])
        targets += extra

    for a in targets:
        dossier(a, source_mode=source_mode)


if __name__ == '__main__':
    main()
