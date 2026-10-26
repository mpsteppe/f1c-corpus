#!/usr/bin/env python3
"""Bugfix: AI simplified driving after instant replay.

STATUS: NO WORKING PATCH YET — see docs/28-known-bugs.md for full analysis.

Root cause: FUN_004ef5a0 (Vehicle State Setter) has an InternalState != 5 gate
at VA 0x004ef623 that returns early, preventing AI_ENABLE from firing during
replay exit when InternalState hasn't reached RACING (5). Mid-race replays work
fine; early replays (during formation/lights) leave AI in simplified mode.

Three patch attempts failed:
  1. Save offset change → grid bunching
  2. Phase 5→3 comparison → timer delay too long for short tracks
  3. NOP jne in backup enable → timer delay still present

Proposed fix (not yet validated): NOP the InternalState gate in FUN_004ef5a0
at VA 0x004ef62a (75 46 → 90 90). Risk: may break formation driving during
normal game startup since 0→1 transition also passes through this path.

See docs/28-known-bugs.md BUG-001 for full analysis including disassembly,
runtime traces, and alternative fix strategies.
"""
import os
import struct
import sys

SRC = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
IMAGE_BASE = 0x00400000

# PROPOSED — not yet validated safe for normal startup
EDITS = [
    (0x004ef62a, "7546", "9090",
     "NOP InternalState!=5 return in FUN_004ef5a0 — allows AI_ENABLE on any X->1 transition"),
]


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    opt = struct.unpack_from("<H", data, pe + 20)[0]
    sstart = pe + 24 + opt
    out = []
    for i in range(nsec):
        off = sstart + i * 40
        va = struct.unpack_from("<I", data, off + 12)[0]
        vs = struct.unpack_from("<I", data, off + 8)[0]
        pr = struct.unpack_from("<I", data, off + 20)[0]
        out.append((va, vs, pr))
    return out


def va_to_fo(secs, va):
    rva = va - IMAGE_BASE
    for v, vs, pr in secs:
        if v <= rva < v + vs:
            return pr + (rva - v)
    return None


def main():
    if not os.path.exists(SRC):
        print(f"ERROR: source exe not found: {SRC}")
        sys.exit(1)

    data = bytearray(open(SRC, "rb").read())
    secs = sections(data)

    staged = []
    for va, orig_hex, new_hex, note in EDITS:
        fo = va_to_fo(secs, va)
        if fo is None:
            print(f"ERROR: VA {va:#010x} not mapped")
            sys.exit(1)
        orig = bytes.fromhex(orig_hex)
        actual = bytes(data[fo:fo + len(orig)])
        if actual != orig:
            print(f"ERROR: byte mismatch at {va:#010x} (fo {fo:#x})")
            print(f"       expected {orig_hex}, found {actual.hex()}")
            print("       Aborting — wrong exe version or already patched.")
            sys.exit(1)
        staged.append((fo, orig, bytes.fromhex(new_hex), va, note))

    dst = os.path.join(os.path.dirname(SRC), "F1 Challenge Online (ReplayAIFix).exe")
    for fo, orig, new, va, note in staged:
        data[fo:fo + len(new)] = new
        print(f"  patched {va:#010x}: {orig.hex()} -> {new.hex()}  ({note})")

    open(dst, "wb").write(data)
    print(f"\nWrote patched exe: {dst}")
    print("Original untouched.")
    print("\nWARNING: This patch has NOT been validated. It may break formation")
    print("driving during normal game startup. Test carefully:")
    print("  1. Normal race start — AI should stay in formation until lights out")
    print("  2. Early replay — AI should recover after replay exit")
    print("  3. Mid-race replay — should still work (already works unpatched)")


if __name__ == "__main__":
    main()
