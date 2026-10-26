import ctypes, struct, os
pid = 18532
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10|0x20, False, pid)
b4 = ctypes.create_string_buffer(4)
bn = ctypes.create_string_buffer(64)

def ru32(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<I', b4.raw)[0]
def rf32(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<f', b4.raw)[0]

def name(veh):
    if veh < 0x10000: return "?"
    k32.ReadProcessMemory(h, veh+0x4620, bn, 64, None)
    raw = bn.raw; null = raw.find(b'\x00')
    if null >= 0: raw = raw[:null]
    return ''.join(chr(c) if 32 <= c < 127 else '' for c in raw).strip()

count = ru32(0x5C329C)
vehicles = []
for i in range(count):
    veh = ru32(0x7C54F0 + i*4)
    if veh > 0x10000:
        vehicles.append((i, veh, name(veh)))

# Find Raikkonen
raikkonen = None
for i, veh, nm in vehicles:
    if "Raikkonen" in nm:
        raikkonen = (i, veh, nm)
        break

if not raikkonen:
    print("Raikkonen not found"); k32.CloseHandle(h); exit()

ri, rveh, rnm = raikkonen
print(f"Raikkonen: slot {ri}, veh=0x{rveh:08X}")

# Compare vs Schumacher (slot 1)
si, sveh, snm = vehicles[1]
print(f"Reference: slot {si}, veh=0x{sveh:08X} ({snm})")

# Scan vehicle struct for unique values
print("\nUnique fields (Raikkonen != Schumacher):")
for off in range(0, 0x4900, 4):
    rv = ru32(rveh + off)
    sv = ru32(sveh + off)
    if rv != sv:
        rf = rf32(rveh + off)
        sf = rf32(sveh + off)
        # Show meaningful differences
        if abs(rv - sv) > 0:
            print(f"  veh+0x{off:04X}: R=0x{rv:08X} ({rf:.4f}f) vs S=0x{sv:08X} ({sf:.4f}f)")

# Also diff driver blocks
DRV = 0x5F0DEC; STR = 0x48C0
print("\nUnique driver fields:")
for off in range(0, 0x4000, 4):
    rv = ru32(DRV + ri*STR + off)
    sv = ru32(DRV + si*STR + off)
    if rv != sv and not (off >= 0 and off < 0x40):  # skip vehicle filename area
        print(f"  drv+0x{off:04X}: R=0x{rv:08X} S=0x{sv:08X} diff={rv-sv}")

k32.CloseHandle(h)
