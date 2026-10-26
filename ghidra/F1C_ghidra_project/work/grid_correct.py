import ctypes, struct
pid=14596;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4)
bn=ctypes.create_string_buffer(64)

def name(veh):
    if veh < 0x10000: return "?"
    k32.ReadProcessMemory(h,veh+0x4620,bn,64,None)
    raw=bn.raw;null=raw.find(b'\x00')
    if null>=0: raw=raw[:null]
    return ''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()

# Correct stride: 0x48C0 = 18624
STRIDE = 0x48C0
GRID = 0x5EF9A0

print("=== Grid (stride 0x48C0) ===")
for i in range(24):
    addr = GRID + i * STRIDE
    k32.ReadProcessMemory(h, addr, b, 4, None)
    v0 = struct.unpack('<I', b.raw)[0]
    k32.ReadProcessMemory(h, addr+4, b, 4, None)
    v4 = struct.unpack('<I', b.raw)[0]
    marker = "<< EMPTY" if v0 == 0xFFFFFFFF else ""
    print(f"  [{i:2d}] +0x00={v0:11d} +0x04=0x{v4:08X} {marker} {name(v4)}")

k32.CloseHandle(h)
