"""
Phase 0 — Binary Coverage Audit
Finds .text regions Ghidra missed entirely.

Inputs:
  work/function_sizes.csv   — exported by scripts/ExportFunctionSizes.java
  F1 Challenge V10/F1 Challenge Online.exe

Output:
  work/binary_coverage_gaps.csv — address, size, classification, hex_preview
"""
import csv
import struct
import os
import sys

EXE = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
FUNC_CSV = r"%USERPROFILE%\Desktop\F1C_ghidra_project\work\function_sizes.csv"
OUT_CSV       = r"%USERPROFILE%\Desktop\F1C_ghidra_project\work\binary_coverage_gaps.csv"
OUT_CANDS_CSV = r"%USERPROFILE%\Desktop\F1C_ghidra_project\work\new_function_candidates.csv"
MIN_GAP  = 16   # bytes — smaller gaps are likely alignment padding

# ── PE parsing ───────────────────────────────────────────────────────────────

def get_text_section(path):
    with open(path, "rb") as f:
        data = f.read()

    # MZ header
    if data[:2] != b"MZ":
        raise ValueError("Not a PE file")
    pe_offset = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe_offset:pe_offset+4] != b"PE\0\0":
        raise ValueError("PE signature not found")

    # COFF header
    machine, num_sections = struct.unpack_from("<HH", data, pe_offset + 4)
    opt_header_size = struct.unpack_from("<H", data, pe_offset + 20)[0]

    # Optional header — image base + magic
    opt_off = pe_offset + 24
    magic = struct.unpack_from("<H", data, opt_off)[0]
    if magic == 0x10b:   # PE32
        image_base = struct.unpack_from("<I", data, opt_off + 28)[0]
    elif magic == 0x20b:  # PE32+
        image_base = struct.unpack_from("<Q", data, opt_off + 24)[0]
    else:
        raise ValueError(f"Unknown optional header magic: {magic:#x}")

    # Section headers
    sec_off = opt_off + opt_header_size
    for i in range(num_sections):
        off = sec_off + i * 40
        name = data[off:off+8].rstrip(b"\x00").decode("ascii", errors="replace")
        vsize, vaddr, rawsize, rawoff = struct.unpack_from("<IIII", data, off + 8)
        if name == ".text":
            return image_base + vaddr, image_base + vaddr + vsize, rawoff, data
    raise ValueError(".text section not found")

# ── Gap detection ─────────────────────────────────────────────────────────────

def load_functions(path):
    fns = []
    with open(path, encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            addr = int(row["address"], 16)
            size = int(row["size"])
            fns.append((addr, size))
    fns.sort()
    return fns

def find_gaps(text_start, text_end, functions):
    covered = []
    for addr, size in functions:
        if addr >= text_start and addr < text_end:
            covered.append((addr, addr + size))

    covered.sort()
    # merge overlapping ranges
    merged = []
    for s, e in covered:
        if merged and s <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(merged[-1][1], e))
        else:
            merged.append([s, e])

    gaps = []
    cursor = text_start
    for s, e in merged:
        if s > cursor:
            gaps.append((cursor, s, s - cursor))
        cursor = max(cursor, e)
    if cursor < text_end:
        gaps.append((cursor, text_end, text_end - cursor))
    return gaps

PROLOGUE_PATTERNS = [
    bytes([0x55, 0x8b, 0xec]),               # PUSH EBP; MOV EBP, ESP
    bytes([0x55, 0x89, 0xe5]),               # PUSH EBP; MOV EBP, ESP (GCC)
    bytes([0x8b, 0xff, 0x55, 0x8b, 0xec]),  # MOV EDI,EDI; PUSH EBP; MOV EBP,ESP
    bytes([0x53, 0x55, 0x56]),               # PUSH EBX; PUSH EBP; PUSH ESI
    bytes([0x51, 0x53, 0x55, 0x56]),         # PUSH ECX; EBX; EBP; ESI
    bytes([0x56, 0x57]),                      # PUSH ESI; PUSH EDI
    bytes([0x83, 0xec]),                      # SUB ESP, n
    bytes([0x81, 0xec]),                      # SUB ESP, imm32
]

def find_prologue_offset(hexbytes):
    """Scan past NOP/INT3 prefix to find prologue. Returns offset or -1."""
    b = bytes(hexbytes)
    i = 0
    while i < len(b) and b[i] in (0x90, 0xCC, 0x00):
        i += 1
    if i == 0:
        return -1  # no prefix to skip
    tail = b[i:]
    for pat in PROLOGUE_PATTERNS:
        if tail[:len(pat)] == pat:
            return i
    return -1

def classify(hexbytes, size):
    if not hexbytes:
        return "empty"
    b = bytes(hexbytes)

    # pure padding
    if all(x == 0xCC for x in b):
        return "INT3_padding"
    if all(x == 0x00 for x in b):
        return "zero_padding"
    if all(x == 0x90 for x in b):
        return "NOP_padding"
    if set(b) <= {0xCC, 0x90, 0x00}:
        return "alignment_padding"

    # clean function prologue at byte 0
    for pat in PROLOGUE_PATTERNS:
        if b[:len(pat)] == pat:
            return "function_prologue"

    # NOP/INT3-padded prologue (function with alignment prefix)
    off = find_prologue_offset(hexbytes)
    if off > 0:
        return f"padded_prologue+{off}"

    # jump/pointer table: 4-byte-aligned addresses in .text range
    if size >= 8 and len(b) >= 8:
        maybe_table = True
        for i in range(0, min(16, len(b) - 3), 4):
            val = int.from_bytes(b[i:i+4], "little")
            if not (0x00400000 <= val <= 0x00600000):
                maybe_table = False
                break
        if maybe_table:
            return "jump_table"

    if size < 64:
        return "tail_or_split"

    return "unknown_code"

def va_to_file_offset(va, text_va_start, text_raw_off):
    return text_raw_off + (va - text_va_start)

# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    if not os.path.exists(FUNC_CSV):
        print(f"ERROR: {FUNC_CSV} not found.")
        print("Run scripts/ExportFunctionSizes.java via Ghidra headless first.")
        sys.exit(1)

    print("Parsing PE...")
    text_start, text_end, text_raw_off, raw_data = get_text_section(EXE)
    text_size = text_end - text_start
    print(f"  .text VA: {text_start:#010x} – {text_end:#010x}  ({text_size:,} bytes)")

    print("Loading functions...")
    fns = load_functions(FUNC_CSV)
    print(f"  {len(fns)} functions loaded")

    print("Finding gaps...")
    gaps = find_gaps(text_start, text_end, fns)
    gaps = [(s, e, sz) for s, e, sz in gaps if sz >= MIN_GAP]
    print(f"  {len(gaps)} gaps >= {MIN_GAP} bytes")

    with open(OUT_CSV, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["address", "end", "size", "classification", "hex_preview"])
        for va_start, va_end, size in gaps:
            file_off = va_to_file_offset(va_start, text_start, text_raw_off)
            chunk = raw_data[file_off:file_off+32]
            hexpreview = chunk.hex(" ")
            cls = classify(list(chunk), size)
            writer.writerow([f"{va_start:#010x}", f"{va_end:#010x}", size, cls, hexpreview])

    print(f"\nDone. Output: {OUT_CSV}")

    # Summary stats + candidates output
    by_class = {}
    candidates = []
    with open(OUT_CSV, encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            c = row["classification"]
            by_class[c] = by_class.get(c, 0) + 1
            # actionable: clean or padded prologues, or large unknown_code
            is_prologue = c in ("function_prologue",) or c.startswith("padded_prologue+")
            is_large_unknown = c == "unknown_code" and int(row["size"]) >= 256
            if is_prologue or is_large_unknown:
                pad_off = 0
                if c.startswith("padded_prologue+"):
                    pad_off = int(c.split("+")[1])
                fn_addr = int(row["address"], 16) + pad_off
                candidates.append({
                    "fn_address": f"{fn_addr:#010x}",
                    "gap_address": row["address"],
                    "gap_size": row["size"],
                    "classification": c,
                    "confidence": "HIGH" if is_prologue else "MEDIUM",
                    "hex_preview": row["hex_preview"],
                })

    with open(OUT_CANDS_CSV, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=["fn_address","gap_address","gap_size","classification","confidence","hex_preview"])
        writer.writeheader()
        writer.writerows(sorted(candidates, key=lambda r: -int(r["gap_size"])))

    print("\nGap classification summary:")
    for k, v in sorted(by_class.items(), key=lambda x: -x[1]):
        print(f"  {k:30s} {v:5d}")

    total_unknown = sum(int(r["gap_size"]) for r in candidates if r["confidence"] == "MEDIUM")
    print(f"\n  HIGH confidence (prologue-detected): {sum(1 for r in candidates if r['confidence']=='HIGH')}")
    print(f"  MEDIUM confidence (large unknown):   {sum(1 for r in candidates if r['confidence']=='MEDIUM')}")
    print(f"  Total actionable candidates: {len(candidates)}")
    print(f"  Candidate output: {OUT_CANDS_CSV}")

if __name__ == "__main__":
    main()
