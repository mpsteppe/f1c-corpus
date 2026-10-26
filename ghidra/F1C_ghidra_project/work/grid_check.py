import ctypes, struct
pid=14596;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10|0x20|0x8,False,pid)
b=ctypes.create_string_buffer(4);bn=ctypes.create_string_buffer(64)
def r(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<I',b.raw)[0]
def name(veh):
    k32.ReadProcessMemory(h,veh+0x4620,bn,64,None)
    raw=bn.raw;null=raw.find(b'\x00')
    if null>=0: raw=raw[:null]
    return ''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()

# Grid array: 0x5EF9A0, stride 0x1230, -1=empty
GRID=0x5EF9A0; STRIDE=0x1230
print("=== Grid Array ===")
for i in range(24):
    v=r(GRID+i*STRIDE)
    print(f"  [{i:2d}] = {v}")

# Live positions from driver block
DRV=0x5F0DEC; DSTRIDE=0x48C0
print("\n=== Live Positions ===")
count=r(0x5C329C)
for i in range(count):
    veh=r(0x7C54F0+i*4)
    if veh>0x10000:
        pos=r(DRV+i*DSTRIDE+0x06B4)
        fs=r(veh+0x4064)
        n=name(veh)
        print(f"  [{i:2d}] pos={pos:2d} finish={fs} {n}")

k32.CloseHandle(h)
