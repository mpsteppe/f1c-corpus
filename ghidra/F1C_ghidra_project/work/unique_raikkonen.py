import ctypes, struct
pid=18532;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4)

def ru32(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<I',b.raw)[0]

count = ru32(0x5C329C)
vehicles = []
for i in range(count):
    veh = ru32(0x7C54F0 + i*4)
    if veh > 0x10000: vehicles.append((i, veh))

# Find Raikkonen (slot 7)
ri = 7; rveh = vehicles[ri][1]

# Compare Raikkonen vs all others - find fields where Raikkonen is unique
# Focus on int fields (not floats) in non-position area
print("=== Unique int fields: Raikkonen vs all others ===")
for off in range(0, 0x4900, 4):
    rv = ru32(rveh + off)
    all_same = True
    for i, veh in vehicles:
        if i == ri: continue
        v = ru32(veh + off)
        if v != rv:
            all_same = False
            break
    if all_same and rv != 0:
        print(f"  veh+0x{off:04X} = 0x{rv:08X} ({rv}) [Raikkonen unique]")

# Also check driver block
DRV=0x5F0DEC; STR=0x48C0
print("\n=== Unique driver block int fields ===")
for off in range(0, 0x4000, 4):
    rv = ru32(DRV + ri*STR + off)
    all_same = True
    for i, veh in vehicles:
        if i == ri: continue
        v = ru32(DRV + i*STR + off)
        if v != rv:
            all_same = False
            break
    if all_same and rv != 0:
        print(f"  drv+0x{off:04X} = 0x{rv:08X} ({rv}) [Raikkonen unique]")

k32.CloseHandle(h)
