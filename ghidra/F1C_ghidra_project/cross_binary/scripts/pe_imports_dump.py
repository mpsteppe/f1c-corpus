import struct, sys

def dump(path):
    data = open(path, 'rb').read()
    e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
    coff_off = e_lfanew + 4
    nsections = struct.unpack_from('<H', data, coff_off + 2)[0]
    opt_hdr_size = struct.unpack_from('<H', data, coff_off + 16)[0]
    opt_off = coff_off + 20
    magic = struct.unpack_from('<H', data, opt_off)[0]
    is_pe32plus = (magic == 0x20b)
    dd_off = opt_off + (112 if is_pe32plus else 96)
    import_rva, import_size = struct.unpack_from('<II', data, dd_off + 1*8)

    sect_off = opt_off + opt_hdr_size
    sections = []
    for i in range(nsections):
        s = data[sect_off+i*40 : sect_off+i*40+40]
        vsize, vaddr, rawsize, rawptr = struct.unpack_from('<IIII', s, 8)
        sections.append((vaddr, vsize, rawptr, rawsize))

    def rva2off(rva):
        for vaddr, vsize, rawptr, rawsize in sections:
            if vaddr <= rva < vaddr + max(vsize, rawsize):
                return rawptr + (rva - vaddr)
        return None

    def cstr(off):
        end = data.find(b'\0', off)
        return data[off:end].decode('latin1', errors='replace')

    off = rva2off(import_rva)
    names = []
    while True:
        entry = data[off:off+20]
        if len(entry) < 20 or entry == b'\0'*20:
            break
        oft, ts, fchain, name_rva, ft = struct.unpack('<IIIII', entry)
        name_off = rva2off(name_rva)
        names.append(cstr(name_off))
        off += 20
    return names

if __name__ == '__main__':
    for p in sys.argv[1:]:
        print(f"=== {p} ===")
        for n in dump(p):
            print(" ", n)
