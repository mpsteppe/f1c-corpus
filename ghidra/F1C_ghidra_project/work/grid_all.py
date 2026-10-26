import ctypes, struct
pid=14596;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4)

print("=== Grid slots (first int + veh ptr) ===")
for i in range(22):
    addr = 0x5EF9A0 + i * 0x1230
    k32.ReadProcessMemory(h, addr, b, 4, None)
    v0 = struct.unpack('<I', b.raw)[0]
    k32.ReadProcessMemory(h, addr+4, b, 4, None)
    v4 = struct.unpack('<I', b.raw)[0]
    
    # Get name from veh ptr
    name = "?"
    if v4 > 0x10000:
        bn=ctypes.create_string_buffer(64)
        k32.ReadProcessMemory(h, v4+0x4620, bn, 64, None)
        raw=bn.raw;null=raw.find(b'\x00')
        if null>=0: raw=raw[:null]
        name = ''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()
    
    marker = "EMPTY" if v0 == 0xFFFFFFFF else f"     "
    print(f"  [{i:2d}] +0x00={v0:11d} +0x04=0x{v4:08X} {marker} {name}")

k32.CloseHandle(h)
