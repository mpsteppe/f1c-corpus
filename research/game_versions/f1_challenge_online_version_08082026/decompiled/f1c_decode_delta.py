#!/usr/bin/env python3
"""Decode the v10->v49 binary delta. Outputs a human-readable report.

Covered regions (file offsets):
  .text patches: 0x2d9d3, 0xa0f80, 0xaa375, 0xaa3b1, 0x14285d
  .rdata:        0x1bd0c0 (13B), 0x1bd0e1 (48B)
  .data:         0x1c01f4 (104B), 0x1c02d0 (44B), 0x1c0550 (4B)
  .text1:        0x1ed015 (203B), 0x1ee580 (114B)
"""
import struct
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

OLD = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
NEW = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\F1 Challenge Online.exe"
OUT = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\decompiled"

old = open(OLD, "rb").read()
new = open(NEW, "rb").read()

# VA for .text: off + 0x400000 (rawptr==vaddr==0x1000)
# VA for .text1: off - 0x1ED000 + 0x4D8000
# VA for .rdata: off - 0x19E000 + 0x59E000
# VA for .data:  off - 0x1BE000 + 0x5BE000
TEXT_VA = lambda off: 0x400000 + off
TEXT1_VA = lambda off: 0x4D8000 + off - 0x1ED000
RDATA_VA = lambda off: 0x59E000 + off - 0x19E000
DATA_VA = lambda off: 0x5BE000 + off - 0x1BE000

md = Cs(CS_ARCH_X86, CS_MODE_32)


def dis(region_name, off, size, vafn):
    print("=" * 70)
    print("REGION %s  off=0x%x size=%d  VA=%s" % (region_name, off, size, hex(vafn(off))))
    print("=" * 70)
    ob = old[off:off + size]
    nb = new[off:off + size]
    print("OLD: %s" % ob.hex(" "))
    print("NEW: %s" % nb.hex(" "))
    # merged disasm view: disassemble both at their VAs, diff line by line
    od = list(md.disasm(ob, vafn(off)))
    nd = list(md.disasm(nb, vafn(off)))
    rows = []
    for i in range(max(len(od), len(nd))):
        o = od[i] if i < len(od) else None
        n = nd[i] if i < len(nd) else None
        mark = "  "
        if o and n and (o.bytes != n.bytes or o.mnemonic != n.mnemonic or o.op_str != n.op_str):
            mark = ">>"
        rows.append((mark, o, n))
    for mark, o, n in rows:
        os_ = ("%08x: %-24s %s %s" % (o.address, o.bytes.hex(" "), o.mnemonic, o.op_str)) if o else " " * 44
        ns_ = ("%08x: %-24s %s %s" % (n.address, n.bytes.hex(" "), n.mnemonic, n.op_str)) if n else ""
        print("%s | %s | %s" % (mark, os_, ns_))


def ascii_at(data, off, n):
    return "".join(chr(c) if 32 <= c < 127 else "." for c in data[off:off + n])


def dump_data(region_name, off, size, vafn, label=""):
    print("=" * 70)
    print("DATA %s  off=0x%x size=%d VA=%s %s" % (region_name, off, size, hex(vafn(off)), label))
    print("=" * 70)
    ob = old[off:off + size]
    nb = new[off:off + size]
    print("OLD: %s | %r" % (ob.hex(" "), ascii_at(old, off, size)))
    print("NEW: %s | %r" % (nb.hex(" "), ascii_at(new, off, size)))
    print("dwords old:", [hex(struct.unpack_from("<I", ob, i)[0]) for i in range(0, len(ob) - 3, 4)])
    print("dwords new:", [hex(struct.unpack_from("<I", nb, i)[0]) for i in range(0, len(nb) - 3, 4)])


out = []
# .text patches
dis(".text GamePostMainLoop patch", 0x2D9D3, 4, TEXT_VA)
dis(".text Options_Setup patch", 0xA0F80, 4, TEXT_VA)
dis(".text PlayerOptionsInitializer patch A", 0xAA375, 1, TEXT_VA)
dis(".text PlayerOptionsInitializer patch B", 0xAA3B1, 1, TEXT_VA)
dis(".text sub_5427D0 patch", 0x14285D, 4, TEXT_VA)
# rdata / data
dump_data(".rdata consts", 0x1BD0C0, 13, RDATA_VA)
dump_data(".rdata consts2", 0x1BD0E1, 48, RDATA_VA)
dump_data(".data globals", 0x1C01F4, 104, DATA_VA)
dump_data(".data globals2", 0x1C02D0, 44, DATA_VA)
dump_data(".data global3", 0x1C0550, 4, DATA_VA)
# text1 entry stub
dis(".text1 entry stub A", 0x1ED015, 203, TEXT1_VA)
dis(".text1 entry stub B", 0x1EE580, 114, TEXT1_VA)
