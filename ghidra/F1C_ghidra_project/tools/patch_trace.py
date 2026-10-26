#!/usr/bin/env python3
"""Unlock the F1C in-game trace level clamp (item B, HANDOFF 2026-07-17).

FUN_004d7960 clamps the requested trace level to a hard max of 2:
    cmp eax,2            ; 83 f8 02   imm at file offset 0xd7971
    jle +6
    mov dword[esi],2     ; c7 06 02 00 00 00   imm at file offset 0xd7976
The "notrace" cmdline arg (FUN_004d7a00) actually ENABLES trace by setting the
level to 3000; the clamp then forces it back to 2. Raising both immediates to N
lets 3000 clamp to N instead, so every trace site whose threshold <= N now emits
(gate in FUN_004d7a50: `if (*level < threshold) return 0;`).

Reversible: writes a .bak once, --restore puts it back.

Usage:
    python tools/patch_trace.py --level 10          # patch in place (backs up)
    python tools/patch_trace.py --restore           # revert
    python tools/patch_trace.py --level 10 --dry    # show, don't write
"""
import argparse, os, shutil, sys

EXE = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
OFF_CMP = 0xd7971   # imm byte of  cmp eax, 2
OFF_MOV = 0xd7976   # imm byte of  mov dword[esi], 2   (dword, low byte here)
ORIG = 0x02


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--exe", default=EXE)
    ap.add_argument("--level", type=int, default=10,
                    help="new trace cap (1..255). Effective level = min(3000, N) = N")
    ap.add_argument("--restore", action="store_true")
    ap.add_argument("--dry", action="store_true")
    a = ap.parse_args()

    bak = a.exe + ".bak"

    if a.restore:
        if not os.path.exists(bak):
            sys.exit("no .bak found next to exe")
        shutil.copy2(bak, a.exe)
        print("restored from", bak)
        return

    if not (1 <= a.level <= 255):
        sys.exit("level must be 1..255 (single-byte immediate)")

    data = bytearray(open(a.exe, "rb").read())

    cur_cmp, cur_mov = data[OFF_CMP], data[OFF_MOV]
    print(f"current: cmp imm=0x{cur_cmp:02x}  mov imm=0x{cur_mov:02x}")
    if cur_cmp != ORIG or cur_mov != ORIG:
        print(f"WARNING: expected both 0x{ORIG:02x}; already patched or wrong exe/offsets")

    print(f"new    : cmp imm=0x{a.level:02x}  mov imm=0x{a.level:02x}  (level cap = {a.level})")
    if a.dry:
        print("(dry run, no write)")
        return

    if not os.path.exists(bak):
        shutil.copy2(a.exe, bak)
        print("backup ->", bak)
    data[OFF_CMP] = a.level
    data[OFF_MOV] = a.level
    open(a.exe, "wb").write(data)
    print("patched in place. Launch with the 'notrace' arg to enable, then read LOG/trace.txt")


if __name__ == "__main__":
    main()
