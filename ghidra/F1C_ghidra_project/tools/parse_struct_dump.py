"""
parse_struct_dump.py
Usage: python parse_struct_dump.py inputs/memory_dumps/driver0.bin [--docs path/to/docs/10-vehicle-physics.md]

Parses a raw memory dump of one vehicle struct (0x48C0 bytes) and produces:
- Annotated offset table (float / int / ptr / string guesses)
- Cross-reference against Ghidra docs/10 documented offsets
- Gap list: offsets with live data but no documentation
"""

import struct
import re
import sys
import math
import os

STRUCT_SIZE = 0x48C0
BASE_ADDR   = 0x005F0DEC  # driver 0 at preferred load base

# ── helpers ────────────────────────────────────────────────────────────────────

def is_sane_float(f):
    if math.isnan(f) or math.isinf(f):
        return False
    return -1e6 < f < 1e6

def is_printable_ascii(b4):
    return all(0x20 <= c < 0x7F for c in b4)

def guess_type(b4, val_u32, val_f32, val_i32):
    if is_printable_ascii(b4):
        return "str4", ''.join(chr(c) for c in b4)
    if is_sane_float(val_f32) and val_f32 != 0.0:
        return "float", val_f32
    if 0 < val_u32 < 0x10000000 and (val_u32 & 0xFFF00000) in (0x00400000 & 0xFFF00000,):
        return "ptr?", hex(val_u32)
    if val_u32 > 0x00400000 and val_u32 < 0x01000000:
        return "ptr?", hex(val_u32)
    if val_i32 != 0:
        return "int", val_i32
    return "zero", 0

# ── load Ghidra docs offsets ────────────────────────────────────────────────────

def load_known_offsets(docs_path):
    known = {}
    if not docs_path or not os.path.exists(docs_path):
        return known
    pattern = re.compile(r'\+0x([0-9a-fA-F]+)\s*\|?\s*([^\|\n]+)')
    with open(docs_path, encoding='utf-8', errors='replace') as f:
        for line in f:
            m = pattern.search(line)
            if m:
                offset = int(m.group(1), 16)
                label  = m.group(2).strip().rstrip('|').strip()
                if offset < STRUCT_SIZE:
                    known[offset] = label
    return known

# ── main ───────────────────────────────────────────────────────────────────────

def parse(dump_path, docs_path=None):
    with open(dump_path, 'rb') as f:
        data = f.read()

    if len(data) < STRUCT_SIZE:
        print(f"[!] File too small: {len(data)} bytes, expected {STRUCT_SIZE}")
        return

    known = load_known_offsets(docs_path)
    print(f"Loaded {len(known)} documented offsets from Ghidra docs.\n")

    rows_all      = []
    rows_active   = []
    rows_gap      = []
    rows_strings  = []

    i = 0
    while i + 4 <= STRUCT_SIZE:
        b4     = data[i:i+4]
        u32    = struct.unpack_from('<I', data, i)[0]
        f32    = struct.unpack_from('<f', data, i)[0]
        i32    = struct.unpack_from('<i', data, i)[0]
        kind, val = guess_type(b4, u32, f32, i32)
        label  = known.get(i, '')
        doc    = 'DOCUMENTED' if label else ''

        row = (i, hex(i), kind, val, doc, label)
        rows_all.append(row)

        if kind != 'zero':
            rows_active.append(row)
            if not label:
                rows_gap.append(row)
        if kind == 'str4':
            rows_strings.append(row)
        i += 4

    # ── output ─────────────────────────────────────────────────────────────────

    out_path = dump_path.replace('.bin', '_annotated.txt')
    with open(out_path, 'w', encoding='utf-8') as out:
        def w(line=''):
            out.write(line + '\n')

        w("=" * 80)
        w("VEHICLE STRUCT DUMP — ANNOTATED")
        w(f"Source: {dump_path}   Size: {len(data)} bytes   Struct: 0x48C0")
        w(f"Base address: {hex(BASE_ADDR)}  (driver 0, preferred load)")
        w("=" * 80)
        w()

        w("── ACTIVE OFFSETS (non-zero) ──────────────────────────────────────────────────")
        w(f"{'Offset':<8} {'Hex':<8} {'Type':<7} {'Value':<20} {'Ghidra Label'}")
        w("-" * 72)
        for (off, hexoff, kind, val, doc, label) in rows_active:
            star = '*' if doc else ' '
            w(f"{star}{hexoff:<7} {off:<8} {kind:<7} {str(val):<20} {label}")
        w()

        w("── GAPS: active but undocumented ──────────────────────────────────────────────")
        w(f"{'Offset':<8} {'Hex':<8} {'Type':<7} {'Value'}")
        w("-" * 48)
        for (off, hexoff, kind, val, doc, label) in rows_gap:
            w(f"{hexoff:<8} {off:<8} {kind:<7} {val}")
        w()

        w("── STRING FRAGMENTS ───────────────────────────────────────────────────────────")
        consecutive = []
        for (off, hexoff, kind, val, doc, label) in rows_strings:
            consecutive.append((off, val))
        # merge consecutive string fragments
        if consecutive:
            merged = consecutive[0][1]
            prev_off = consecutive[0][0]
            strings_merged = []
            for off, s in consecutive[1:]:
                if off == prev_off + 4:
                    merged += s
                    prev_off = off
                else:
                    strings_merged.append((prev_off - len(merged) + 4, merged))
                    merged = s
                    prev_off = off
            strings_merged.append((prev_off - len(merged) + 4, merged))
            for start_off, s in strings_merged:
                w(f"  +{hex(start_off):<8} \"{s}\"")
        w()

        w("── DOCUMENTED OFFSETS NOT SEEN IN DUMP (zero/missing) ────────────────────────")
        seen_offsets = {r[0] for r in rows_active}
        for off, label in sorted(known.items()):
            if off not in seen_offsets:
                w(f"  +{hex(off):<8} {label}")
        w()

        w("── STATS ──────────────────────────────────────────────────────────────────────")
        w(f"  Total 4-byte slots : {STRUCT_SIZE // 4}")
        w(f"  Non-zero slots     : {len(rows_active)}")
        w(f"  Documented         : {len(rows_active) - len(rows_gap)}")
        w(f"  Undocumented gaps  : {len(rows_gap)}")
        w(f"  String fragments   : {len(rows_strings)}")

    print(f"Written: {out_path}")

    # also write a compact CSV for spreadsheet use
    csv_path = dump_path.replace('.bin', '_gaps.csv')
    with open(csv_path, 'w', encoding='utf-8') as csv:
        csv.write("offset_hex,offset_dec,type,value,ghidra_label\n")
        for (off, hexoff, kind, val, doc, label) in rows_active:
            csv.write(f"{hexoff},{off},{kind},{val},{label}\n")
    print(f"Written: {csv_path}")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python parse_struct_dump.py inputs/memory_dumps/driver0.bin [docs/10-vehicle-physics.md]")
        sys.exit(1)
    docs = sys.argv[2] if len(sys.argv) > 2 else None
    parse(sys.argv[1], docs)
