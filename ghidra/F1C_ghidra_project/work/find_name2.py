import ctypes, struct

pid = 5492
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10, False, pid)
b4 = ctypes.create_string_buffer(4)
b64 = ctypes.create_string_buffer(80)

def ru32(addr):
    k32.ReadProcessMemory(h, addr, b4, 4, None)
    return struct.unpack('<I', b4.raw)[0]

def rstr(addr, n=64):
    k32.ReadProcessMemory(h, addr, b64, n, None)
    raw = b64.raw
    null = raw.find(b'\x00')
    if null >= 0: raw = raw[:null]
    return ''.join(chr(b) if 32 <= b < 127 else '' for b in raw)

# Driver block: 0x005F0DEC + slot * 0x48C0
# Driver name at +0x4620 per SetDriverName(0x4C6980): this+0x4620
DRIVER_BASE = 0x005F0DEC
STRIDE = 0x48C0

print("=== Driver names from driver blocks (+0x4620) ===")
for slot in range(0, 8):
    block = DRIVER_BASE + slot * STRIDE
    name = rstr(block + 0x4620, 64)
    if name.strip():
        print(f"  slot {slot}: \"{name.strip()}\"")

# Also try vehicle structs (VehiclePtrArray)
print("\n=== Driver names from vehicle structs (+0x4620) ===")
for slot in range(0, 8):
    veh = ru32(0x007C54F0 + slot * 4)
    if veh < 0x10000: continue
    name = rstr(veh + 0x4620, 64)
    if name.strip():
        print(f"  slot {slot}: \"{name.strip()}\"")

# Also try scanning for any readable name string near vehicle+0x4000 region
print("\n=== Scanning veh slot 2 for readable strings ===")
veh = ru32(0x007C54F0 + 2 * 4)
for off in range(0x4000, 0x4800, 0x40):
    name = rstr(veh + off, 40)
    if name and len(name) > 3 and name.strip():
        print(f"  veh+0x{off:04x}: \"{name.strip()}\"")

k32.CloseHandle(h)
