import ctypes, struct
pid=18532;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4)

def rf(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<f',b.raw)[0]
def r(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<I',b.raw)[0]

# Find Raikkonen
for i in range(24):
    veh=r(0x7C54F0+i*4)
    if veh>0x10000:
        k32.ReadProcessMemory(h,veh+0x4620,b,64,None)
        raw=b.raw;null=raw.find(b'\x00')
        if null>=0: raw=raw[:null]
        nm=''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()
        if 'Raikkonen' in nm: break

print(f"=== Raikkonen veh=0x{veh:08X} — damage scan ===")

# Scan for non-zero damage-related floats in aerodynamics area
# Wing damage is typically 0.0..1.0 float values
print("\nAero/damage area (0x0F00-0x1300):")
for off in range(0x0F00, 0x1300, 4):
    v = r(veh + off)
    f = rf(veh + off)
    if v != 0 and v != 0xBF800000 and v != 0x3F800000 and v != 0xFFFFFFFF:
        if f > 0.001 and abs(f) < 1000:
            print(f"  +0x{off:04X} = 0x{v:08X} float={f:.4f}")

# Also scan the vehicle physics header area (0x1800+)
print("\nPhysics header area (0x1800-0x1C00):")
for off in range(0x1800, 0x1C00, 4):
    v = r(veh + off)
    f = rf(veh + off)
    if v != 0 and v != 0xBF800000 and v != 0x3F800000:
        if f > 0.001 and abs(f) < 1000:
            print(f"  +0x{off:04X} = 0x{v:08X} float={f:.4f}")

# Check wing-specific area - the F1CUI says wing positions at specific offsets
print("\nKnown wing/aero area:")
for off in [0x1170, 0x1174, 0x1178, 0x117C, 0x1180, 0x1194, 0x1198, 0x119C, 0x11A0, 0x11A4, 0x11A8, 0x11AC, 0x11B0, 0x11C4, 0x11C8, 0x11CC, 0x11D0, 0x11E8, 0x11EC, 0x11F0, 0x11F4, 0x120C, 0x1210, 0x1214, 0x1218, 0x1230, 0x1234, 0x1238, 0x123C]:
    v = r(veh + off)
    f = rf(veh + off)
    if v != 0:
        print(f"  +0x{off:04X} = 0x{v:08X} int={v} float={f:.4f}")

k32.CloseHandle(h)
