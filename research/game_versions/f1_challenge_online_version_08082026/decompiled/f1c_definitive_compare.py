#!/usr/bin/env python3
"""Definitive byte compare old vs new F1 Challenge Online.exe.

For every old-IDB function address: slice old bytes and new bytes at same range.
  - identical bytes  -> function still present byte-for-byte (analysis artifact if unmarked)
  - different bytes  -> real code change
For every new function not in old IDB: check old bytes at that range
  - old bytes all-zero / padding / no code -> genuine new code
  - else -> boundary/analysis artifact
"""
import hashlib
import json
import os
import struct

OLD_EXE = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
NEW_EXE = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\F1 Challenge Online.exe"
OLD_META = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\decompiled\old_functions_meta.jsonl"
NEW_META = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\decompiled\functions_meta.jsonl"
OUT_DIR = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\decompiled"


def parse_pe(path):
    with open(path, "rb") as f:
        data = f.read()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    image_base = struct.unpack_from("<I", data, pe + 0x34)[0]
    n_sections = struct.unpack_from("<H", data, pe + 6)[0]
    opt_size = struct.unpack_from("<H", data, pe + 0x14)[0]
    sec_off = pe + 0x18 + opt_size
    sections = []
    for i in range(n_sections):
        o = sec_off + i * 40
        name = data[o:o + 8].rstrip(b"\x00").decode("ascii", "replace")
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        sections.append({"name": name, "vaddr": vaddr, "vsize": vsize, "rawptr": rawptr, "rawsize": rawsize})
    return data, image_base, sections


def va_to_off(va, image_base, sections, file_len):
    rva = va - image_base
    for s in sections:
        if s["vaddr"] <= rva < s["vaddr"] + s["vsize"]:
            off = rva - s["vaddr"] + s["rawptr"]
            if off < file_len:
                return off
    return None


def load_meta(path):
    d = {}
    with open(path) as f:
        for line in f:
            m = json.loads(line)
            d[int(m["addr"], 16)] = (m["size"], m["md5"], m["name"])
    return d


def main():
    old_data, old_base, old_sec = parse_pe(OLD_EXE)
    new_data, new_base, new_sec = parse_pe(NEW_EXE)
    old_meta = load_meta(OLD_META)
    new_meta = load_meta(NEW_META)

    def slice_both(addr, size):
        o = va_to_off(addr, old_base, old_sec, len(old_data))
        n = va_to_off(addr, new_base, new_sec, len(new_data))
        ob = old_data[o:o + size] if o is not None else b""
        nb = new_data[n:n + size] if n is not None else b""
        return ob, nb

    real_changed, analysis_artifact = [], []
    for addr, (size, h, name) in sorted(old_meta.items()):
        if addr in new_meta:
            if new_meta[addr][1] != h:
                real_changed.append((addr, size, name))
        else:
            ob, nb = slice_both(addr, size)
            if nb == ob and len(nb) == size:
                analysis_artifact.append((addr, size, name))
            else:
                real_changed.append((addr, size, name, "missing/bytes-differ"))

    real_new, boundary_artifact = [], []
    for addr, (size, h, name) in sorted(new_meta.items()):
        if addr in old_meta:
            continue
        ob, nb = slice_both(addr, size)
        if ob.count(0) >= len(ob) * 0.9 or ob == b"":
            real_new.append((addr, size, name))
        else:
            boundary_artifact.append((addr, size, name))

    print("=== REAL code changes (byte-different at same range): %d ===" % len(real_changed))
    for a in real_changed:
        print("  %08x  %s" % (a[0], a[2]))
    print("=== Analysis artifacts (present+identical bytes, unmarked in new IDB): %d ===" % len(analysis_artifact))
    print("=== REAL new code (old range was padding/absent): %d ===" % len(real_new))
    for a in real_new:
        print("  %08x  %s" % (a[0], a[2]))
    print("=== Boundary artifacts (bytes differ but new func overlaps old func): %d ===" % len(boundary_artifact))
    for a in boundary_artifact:
        print("  %08x  %s" % (a[0], a[2]))

    with open(os.path.join(OUT_DIR, "real_changes.json"), "w") as f:
        json.dump([{"addr": hex(a[0]), "name": a[2]} for a in real_changed], f, indent=1)
    with open(os.path.join(OUT_DIR, "real_new_code.json"), "w") as f:
        json.dump([{"addr": hex(a[0]), "name": a[2], "size": a[1]} for a in real_new], f, indent=1)


if __name__ == "__main__":
    main()
