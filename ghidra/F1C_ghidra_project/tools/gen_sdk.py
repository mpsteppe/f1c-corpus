"""
gen_sdk.py — compile the knowledge base into a programmable SDK.

Emits (to mods/sdk/):
  f1c_sdk.h     — C header: global accessor macros, struct field accessor
                  macros, named function addresses, vtable addresses.
                  Compile DLL mods against NAMES, not hand-copied offsets.
  f1c_sdk.json  — same data machine-readable; consumed by tools/poke.py,
                  tools/gen_hook.py, Frida scripts.

WHY ACCESSOR MACROS, NOT typedef struct:
  docs/13 offsets are observational — overlapping ranges, conflicting names at
  the same offset, gaps. A literal `struct` would need every byte accounted
  for and would silently break on any conflict. Accessor macros are per-field
  independent:  VEH_PositionX(v) -> *(float*)((uint8_t*)(v)+0x08)
  Conflicts stay visible as comments instead of corrupting a layout.

The exe is non-ASLR (MSVC 2002, image base 0x400000): absolute addresses are
valid at runtime, so globals are plain casts of literal addresses.

Regenerate after every docs merge:
  python tools/gen_sdk.py
"""

import json
import os
import re
import sys
import time

if sys.platform == 'win32':
    sys.stdout.reconfigure(encoding='utf-8', errors='replace')

PROJ_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DOCS_DIR = os.path.join(PROJ_ROOT, "docs")
KG_DIR = os.path.join(PROJ_ROOT, "knowledge_graph")
OUT_DIR = os.path.join(PROJ_ROOT, "mods", "sdk")
VTABLE_CSV = os.path.join(PROJ_ROOT, "work", "vtables.csv")

C_TYPES = {
    'float': ('float', 4), 'double': ('double', 8),
    'int': ('int32_t', 4), 'uint': ('uint32_t', 4), 'int32': ('int32_t', 4),
    'short': ('int16_t', 2), 'ushort': ('uint16_t', 2),
    'char': ('int8_t', 1), 'byte': ('uint8_t', 1), 'bool': ('uint8_t', 1),
    'ptr': ('void*', 4), 'pointer': ('void*', 4),
    'undefined4': ('uint32_t', 4), 'undefined2': ('uint16_t', 2),
    'undefined1': ('uint8_t', 1), 'undefined8': ('uint64_t', 8),
}


def c_type(raw):
    """docs type string -> (c_type, size). Arrays/strings -> pointer to base."""
    t = (raw or '').strip().strip('`').lower()
    if not t:
        return ('int32_t', 4)
    base = re.match(r'[a-z_0-9]+', t)
    base = base.group(0) if base else t
    if '[' in t or base in ('str', 'string', 'offset'):
        # char[] / float[4] / string-offset globals: expose as pointer-to-base
        bt = C_TYPES.get(base, ('uint8_t', 1))
        return (bt[0] + '*', 4) if base not in C_TYPES else (bt[0] + '*', 4)
    return C_TYPES.get(base, ('int32_t', 4))


_ID_CLEAN = re.compile(r'[^A-Za-z0-9_]+')


def ident(name, fallback):
    """Sanitize a docs name into a C identifier; '' if hopeless."""
    n = name.strip().strip('`')
    n = re.split(r'[(—→—]| - ', n)[0].strip()  # drop parentheticals/notes
    n = _ID_CLEAN.sub('_', n).strip('_')
    if not n or not re.match(r'[A-Za-z_]', n):
        return fallback
    return n[:48]


# ---------------------------------------------------------------------------
# docs/12 globals — mixed 3-col and 7-col tables
# ---------------------------------------------------------------------------
def parse_globals():
    path = os.path.join(DOCS_DIR, "12-globals-reference.md")
    out = {}  # addr_int -> dict
    with open(path, encoding='utf-8', errors='replace') as f:
        for line in f:
            if not line.startswith('| DAT_'):
                continue
            cols = [c.strip() for c in line.strip().strip('|').split('|')]
            if len(cols) < 2:
                continue
            m = re.match(r'DAT_([0-9a-fA-F]{6,8})', cols[0])
            if not m:
                continue
            addr = int(m.group(1), 16)
            name = cols[1]
            # 7-col validate rows: addr|name|category|type|kind|refs|desc
            raw_type = cols[3] if len(cols) >= 4 else ''
            desc = cols[-1] if len(cols) >= 5 else (cols[2] if len(cols) > 2 else '')
            ct, size = c_type(raw_type)
            nm = ident(name, f'g_{addr:08x}')
            # first (baseline docs/12) wins — those names are curated
            if addr not in out:
                out[addr] = {'name': nm, 'raw_name': name, 'type': ct,
                             'size': size, 'desc': desc[:100]}
    return out


# ---------------------------------------------------------------------------
# docs/13 struct sections
# ---------------------------------------------------------------------------
_SECTION_SKIP = re.compile(
    r'^(source:|summary|new struct offset|consolidated|multi-function|'
    r'unused|struct offset|\d)', re.I)
_ROW = re.compile(
    r'^\|\s*\+0x([0-9a-fA-F]+)\s*\|\s*([^|]+?)\s*\|\s*([^|]+?)\s*\|(.*)$')


def _struct_prefix(section):
    """'VehicleStruct' -> 'VEHICLE'; 'VehicleWheelDataStruct' -> 'VWD'"""
    words = re.findall(r'[A-Z][a-z]+|[A-Z]{2,}|[a-z]+', section)
    words = [w for w in words if w.lower() != 'struct'] or [section]
    if len(words) == 1:
        return words[0][:8].upper()
    return ''.join(w[0] for w in words[:5]).upper()


def parse_structs():
    """[(section, prefix, [(offset,int, ctype, field, note)])] — docs/13 main file only
    (audit report rows are corrections, kept out of the compiled surface)."""
    path = os.path.join(DOCS_DIR, "13-struct-offsets.md")
    structs = {}
    order = []
    section = None
    with open(path, encoding='utf-8', errors='replace') as f:
        for line in f:
            if line.startswith('#'):
                h = line.strip('#').strip()
                if h and not _SECTION_SKIP.match(h):
                    m = re.match(r'[A-Za-z_][\w/]*', h)
                    section = m.group(0) if m else None
                    if section and section not in structs:
                        structs[section] = {}
                        order.append(section)
                continue
            if section is None:
                continue
            m = _ROW.match(line)
            if not m:
                continue
            off = int(m.group(1), 16)
            ct, _sz = c_type(m.group(2))
            fld = ident(m.group(3), '')
            if not fld:
                continue
            note = m.group(4).strip('| ').split('|')[0].strip()[:60]
            # first name at an offset wins; later ones recorded as alternates
            slot = structs[section].setdefault(off, [])
            if fld not in [s[1] for s in slot]:
                slot.append((ct, fld, note))
    result = []
    for sec in order:
        rows = structs[sec]
        if len(rows) < 3:      # noise sections
            continue
        result.append((sec, _struct_prefix(sec), sorted(rows.items())))
    return result


# ---------------------------------------------------------------------------
# knowledge graph named functions
# ---------------------------------------------------------------------------
def parse_functions():
    path = os.path.join(KG_DIR, "functions.json")
    out = {}
    try:
        with open(path, encoding='utf-8') as f:
            funcs = json.load(f)
    except FileNotFoundError:
        return out
    for addr, info in funcs.items():
        nm = info.get('name', '')
        if not nm or nm in ('Unknown', '--'):
            # graph 'name' is mostly Unknown; the doc heading lives in 'summary'
            # (often prefixed with mojibake separator bytes — strip them)
            nm = (info.get('summary') or '').strip()
            while nm and not (nm[0].isalnum() or nm[0] == '_'):
                nm = nm[1:]
        if not nm:
            continue
        cid = ident(nm, '')
        if not cid or cid.lower() in ('unknown', 'unnamed'):
            continue
        out[int(addr, 16)] = {'name': cid, 'raw_name': nm,
                              'game_logic': bool(info.get('is_game_logic'))}
    return out


def parse_vtables():
    import csv
    out = []
    try:
        with open(VTABLE_CSV, encoding='utf-8', errors='replace') as f:
            for r in csv.DictReader(f):
                if r.get('kind') == 'vtable':
                    out.append((int(r['vtable_addr'], 16), int(r['slots'])))
    except FileNotFoundError:
        pass
    return out


# ---------------------------------------------------------------------------
# emit
# ---------------------------------------------------------------------------
def dedup_names(items):
    """items: list of (addr, dict-with-name). Suffix duplicates with _addr."""
    seen = {}
    for addr, d in items:
        n = d['name']
        if n in seen:
            d['name'] = f"{n}_{addr:x}"
        else:
            seen[n] = addr
    return items


def emit(globals_, structs, funcs, vtables):
    os.makedirs(OUT_DIR, exist_ok=True)
    stamp = time.strftime('%Y-%m-%d %H:%M')

    g_items = dedup_names(sorted(globals_.items()))
    f_items = dedup_names(sorted(funcs.items()))

    h = []
    w = h.append
    w("/*")
    w(" * f1c_sdk.h — F1 Challenge 99-02 modding SDK (AUTO-GENERATED, do not edit)")
    w(f" * Generated {stamp} by tools/gen_sdk.py from docs/12, docs/13,")
    w(" * knowledge_graph/functions.json, work/vtables.csv.")
    w(" *")
    w(" * Binary: F1 Challenge Online.exe — x86 PE32, image base 0x400000, NO ASLR:")
    w(" * absolute addresses below are valid at runtime inside the game process.")
    w(" *")
    w(" * Field/global names are REVERSE-ENGINEERED observations, not ground truth.")
    w(" * Conflicting field names at one offset are kept as comments — pick by context.")
    w(" */")
    w("#ifndef F1C_SDK_H")
    w("#define F1C_SDK_H")
    w("#include <stdint.h>")
    w("")
    w("#define F1C_IMAGE_BASE 0x00400000")
    w("")

    # -------- globals --------
    w("/* ======================================================================")
    w(f" * GLOBALS ({len(g_items)}) — g_Name reads/writes the live global directly.")
    w(" * ====================================================================== */")
    for addr, d in g_items:
        ct = d['type']
        star = ct.endswith('*')
        cmt = d['desc'] or d['raw_name']
        cmt = cmt.replace('*/', '* /')
        if star:
            # array/string global: pointer TO the data, not deref
            w(f"#define g_{d['name']} (({ct})0x{addr:08X})  /* {cmt} */")
        else:
            w(f"#define g_{d['name']} (*({ct}*)0x{addr:08X})  /* {cmt} */")
    w("")

    # -------- structs --------
    w("/* ======================================================================")
    w(f" * STRUCT FIELD ACCESSORS ({len(structs)} structs)")
    w(" * Usage: float x = VEH_PositionX(vehPtr);  VEH_PositionX(vehPtr) = 1.0f;")
    w(" * ====================================================================== */")
    used_prefix = {}
    for sec, prefix, rows in structs:
        if prefix in used_prefix:
            prefix = f"{prefix}{used_prefix[prefix]}"
        used_prefix[prefix.rstrip('0123456789')] = \
            used_prefix.get(prefix.rstrip('0123456789'), 1) + 1
        w("")
        w(f"/* ---- {sec} ({len(rows)} fields) ---- */")
        seen_f = set()
        for off, cands in rows:
            ct, fld, note = cands[0]
            if fld in seen_f:
                fld = f"{fld}_{off:x}"
            seen_f.add(fld)
            alts = '; alt: ' + ', '.join(c[1] for c in cands[1:]) if len(cands) > 1 else ''
            cmt = (note + alts).replace('*/', '* /').strip()
            deref = f"(*({ct}*)((uint8_t*)(p) + 0x{off:04X}))"
            w(f"#define {prefix}_{fld}(p) {deref}"
              + (f"  /* {cmt[:70]} */" if cmt else ""))
    w("")

    # -------- functions --------
    w("/* ======================================================================")
    w(f" * NAMED FUNCTIONS ({len(f_items)}) — raw addresses; cast to the right")
    w(" * signature yourself (see docs entry). Most are __thiscall (ecx=this).")
    w(" * Example:")
    w(" *   typedef void(__thiscall *SetAISpeed_t)(void* self, float d);")
    w(" *   ((SetAISpeed_t)FN_AISpeedDeltaSetter)(aiPtr, 0.5f);")
    w(" * ====================================================================== */")
    for addr, d in f_items:
        raw = d['raw_name'].replace('*/', '* /')[:60]
        w(f"#define FN_{d['name']} 0x{addr:08X}  /* {raw} */")
    w("")

    # -------- vtables --------
    w("/* ======================================================================")
    w(f" * VTABLES ({len(vtables)}) — .rdata vtable base addresses (docs/36).")
    w(" * Slot i entry: *(uint32_t*)(VTBL_xxx + 4*i). Swap = VirtualProtect+write.")
    w(" * ====================================================================== */")
    for addr, slots in sorted(vtables):
        w(f"#define VTBL_{addr:08X} 0x{addr:08X}  /* {slots} slots */")
    w("")
    w("#endif /* F1C_SDK_H */")

    hpath = os.path.join(OUT_DIR, "f1c_sdk.h")
    with open(hpath, 'w', encoding='utf-8') as f:
        f.write('\n'.join(h) + '\n')

    # -------- JSON sidecar --------
    j = {
        'generated': stamp,
        'image_base': 0x400000,
        'globals': {d['name']: {'addr': addr, 'type': d['type'], 'size': d['size'],
                                'desc': d['desc']}
                    for addr, d in g_items},
        'structs': {sec: {f'0x{off:04x}': [{'type': c[0], 'name': c[1]} for c in cands]
                          for off, cands in rows}
                    for sec, _p, rows in structs},
        'functions': {d['name']: addr for addr, d in f_items},
        'vtables': {f'0x{a:08x}': n for a, n in vtables},
    }
    jpath = os.path.join(OUT_DIR, "f1c_sdk.json")
    with open(jpath, 'w', encoding='utf-8') as f:
        json.dump(j, f, indent=1)

    print(f"wrote {os.path.relpath(hpath, PROJ_ROOT)}: "
          f"{len(g_items)} globals, {len(structs)} structs, "
          f"{len(f_items)} functions, {len(vtables)} vtables")
    print(f"wrote {os.path.relpath(jpath, PROJ_ROOT)}")


def main():
    emit(parse_globals(), parse_structs(), parse_functions(), parse_vtables())


if __name__ == '__main__':
    main()
