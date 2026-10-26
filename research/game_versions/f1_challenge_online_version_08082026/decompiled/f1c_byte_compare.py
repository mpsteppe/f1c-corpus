#!/usr/bin/env python3
"""Byte-level compare: old F1 Challenge Online.exe (V10, corpus source) vs new v49.

Function boundaries of the OLD exe come from the corpus's tools/ida_functions.csv.
Function boundaries of the NEW exe come from IDA (functions_meta.jsonl).
Sections are parsed from each PE so mapping is exact, not hardcoded.
"""
import csv
import hashlib
import json
import os
import struct


def parse_pe(path):
    with open(path, "rb") as f:
        data = f.read()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    magic = struct.unpack_from("<H", data, pe + 0x18)[0]
    assert magic == 0x10B, "not PE32"
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
            if off + 0 < file_len:
                return off
    return None


def main():
    old_data, old_base, old_sec = parse_pe(r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe")
    new_data, new_base, new_sec = parse_pe(r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\F1 Challenge Online.exe")
    old_csv = r"%USERPROFILE%\Desktop\f1c_ida_decompiled\tools\ida_functions.csv"
    new_meta = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\decompiled\functions_meta.jsonl"
    out_dir = r"%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\decompiled"

    old_funcs = {}
    with open(old_csv, newline="") as f:
        for row in csv.DictReader(f):
            try:
                addr = int(row["addr"], 16)
                size = int(row["size"])
            except Exception:
                continue
            off = va_to_off(addr, old_base, old_sec, len(old_data))
            if off is None or off + size > len(old_data):
                continue
            old_funcs[addr] = (size, hashlib.md5(old_data[off:off + size]).hexdigest())

    new_funcs = {}
    with open(new_meta) as f:
        for line in f:
            m = json.loads(line)
            new_funcs[int(m["addr"], 16)] = (m["size"], m["md5"])

    unchanged, changed, new_only, removed = [], [], [], []
    for addr, (size, h) in old_funcs.items():
        if addr in new_funcs:
            nsize, nh = new_funcs[addr]
            (unchanged if nh == h else changed).append(addr if nh == h else (addr, size, h, nsize, nh))
        else:
            removed.append((addr, size))
    for addr, (size, h) in new_funcs.items():
        if addr not in old_funcs:
            new_only.append((addr, size, h))

    report = {
        "old_functions_sliced": len(old_funcs),
        "new_functions_total": len(new_funcs),
        "unchanged": len(unchanged),
        "changed": len(changed),
        "new_only": len(new_only),
        "removed": len(removed),
    }
    print(json.dumps(report, indent=2))

    with open(os.path.join(out_dir, "byte_compare.json"), "w") as f:
        json.dump(report, f, indent=2)
    with open(os.path.join(out_dir, "changed_functions.json"), "w") as f:
        json.dump([{"addr": hex(a), "old_size": s, "old_md5": h, "new_size": ns, "new_md5": nh} for a, s, h, ns, nh in changed], f, indent=1)
    with open(os.path.join(out_dir, "new_functions.json"), "w") as f:
        json.dump([{"addr": hex(a), "size": s, "md5": h} for a, s, h in new_only], f, indent=1)
    with open(os.path.join(out_dir, "removed_functions.json"), "w") as f:
        json.dump([{"addr": hex(a), "size": s} for a, s in removed], f, indent=1)


if __name__ == "__main__":
    main()
