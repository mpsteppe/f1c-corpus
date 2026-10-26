"""Extract embedded PDB path (CodeView RSDS/NB10 record) from a PE's debug directory.
No deps, pure struct. Usage: python pdb_path_dump.py <exe1> [exe2 ...]
"""
import struct, sys, os

def get_pdb_path(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:2] != b'MZ':
        return None
    e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
    if data[e_lfanew:e_lfanew+4] != b'PE\0\0':
        return None
    coff_off = e_lfanew + 4
    machine, nsections = struct.unpack_from('<HH', data, coff_off)
    opt_hdr_size = struct.unpack_from('<H', data, coff_off + 16)[0]
    opt_off = coff_off + 20
    magic = struct.unpack_from('<H', data, opt_off)[0]
    is_pe32plus = (magic == 0x20b)
    # Data directories: PE32 at opt_off+96, PE32+ at opt_off+112; Debug dir = index 6
    dd_off = opt_off + (112 if is_pe32plus else 96)
    debug_dir_rva, debug_dir_size = struct.unpack_from('<II', data, dd_off + 6*8)
    if debug_dir_rva == 0:
        return None

    # section table to convert RVA->file offset
    sect_off = opt_off + opt_hdr_size
    sections = []
    for i in range(nsections):
        s = data[sect_off+i*40 : sect_off+i*40+40]
        name = s[:8].rstrip(b'\0').decode('latin1')
        vsize, vaddr, rawsize, rawptr = struct.unpack_from('<IIII', s, 8)
        sections.append((vaddr, vsize, rawptr, rawsize, name))

    def rva2off(rva):
        for vaddr, vsize, rawptr, rawsize, name in sections:
            if vaddr <= rva < vaddr + max(vsize, rawsize):
                return rawptr + (rva - vaddr)
        return None

    dbg_off = rva2off(debug_dir_rva)
    if dbg_off is None:
        return None

    n_entries = debug_dir_size // 28
    results = []
    for i in range(n_entries):
        entry = data[dbg_off + i*28 : dbg_off + i*28 + 28]
        if len(entry) < 28:
            break
        chars, ts, majv, minv, dtype, sz, rva, ptr = struct.unpack('<IIHHIIII', entry)
        if dtype != 2:  # IMAGE_DEBUG_TYPE_CODEVIEW
            continue
        raw = data[ptr:ptr+sz]
        if raw[:4] == b'RSDS':
            guid = raw[4:20]
            age = struct.unpack_from('<I', raw, 20)[0]
            pdb = raw[24:].split(b'\0')[0].decode('latin1', errors='replace')
            results.append(('RSDS', pdb, age))
        elif raw[:4] == b'NB10':
            pdb = raw[16:].split(b'\0')[0].decode('latin1', errors='replace')
            results.append(('NB10', pdb, None))
    return results

if __name__ == '__main__':
    for p in sys.argv[1:]:
        print(f"=== {p} ===")
        try:
            r = get_pdb_path(p)
        except Exception as e:
            print(f"  ERROR: {e}")
            continue
        if not r:
            print("  no CodeView debug directory / PDB path found")
        else:
            for kind, pdb, age in r:
                print(f"  [{kind}] {pdb}" + (f"  (age={age})" if age is not None else ""))
