import ctypes, struct, os
pid = 18532
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10|0x20|0x8, False, pid)
b = ctypes.create_string_buffer(4)
bn = ctypes.create_string_buffer(128)

def r(a): k32.ReadProcessMemory(h, a, b, 4, None); return struct.unpack('<I', b.raw)[0]
def rf(a): k32.ReadProcessMemory(h, a, b, 4, None); return struct.unpack('<f', b.raw)[0]
def name(veh):
    if veh < 0x10000: return "?"
    k32.ReadProcessMemory(h, veh+0x4620, bn, 128, None)
    raw = bn.raw; null = raw.find(b'\x00')
    if null >= 0: raw = raw[:null]
    return ''.join(chr(c) if 32 <= c < 127 else '' for c in raw).strip()

# Find Raikkonen
count = r(0x5C329C)
raikkonen_veh = 0
raikkonen_idx = -1
for i in range(count):
    veh = r(0x7C54F0 + i*4)
    if veh > 0x10000:
        nm = name(veh)
        if "Raikkonen" in nm:
            raikkonen_veh = veh
            raikkonen_idx = i
            break

if not raikkonen_veh:
    print("Raikkonen not found")
    k32.CloseHandle(h)
    exit()

veh = raikkonen_veh
i = raikkonen_idx
print(f"=== Raikkonen (slot {i}, veh=0x{veh:08X}) ===")

# Dump all status fields
fields_veh = [
    (0x4064, 'FinishState'),
    (0x4068, 'ReasonCode'),
    (0x4510, 'behavior_state'),
    (0x453C, 'liveLapRatio'),
    (0x443C, 'safety_follow'),
    (0x44A8, 'queue_ptr'),
    (0x44B0, 'queue_count'),
    (0x44F4, 'baseSpeed'),
    (0x02D4, 'actualSpeed'),
    (0x09A8, 'carConditions'),
    (0x32C8, '+0x32C8'),
    (0x4070, 'damageFlags'),
    (0x402C, 'pitSubst+0'),
    (0x4030, 'pitSubst+4'),
    (0x4034, 'pitSubst+8'),
    (0x403C, 'pitSubst+16'),
    (0x4040, 'pitSubst+20'),
]

for off, fname in fields_veh:
    v = r(veh + off)
    print(f"  veh+0x{off:04X} {fname:20s} = 0x{v:08X} ({v})")

# Driver block fields
DRV = 0x5F0DEC
STR = 0x48C0
drv = DRV + i * STR
driver_fields = [
    (0x01C8, 'callToBox'),
    (0x0204, 'driverStatus'),
    (0x0188, 'nextChosenTires'),
    (0x12C4, 'pittingStatus'),
    (0x06B4, 'position'),
    (0x06BC, 'plannedPosition'),
    (0x06D8, 'lapNumber'),
    (0x04D0, '+0x04D0'),
    (0x04D4, '+0x04D4'),
    (0x06B1, 'DNF_DSQ_flag(byte)'),
]

print(f"\n=== Driver block ({i}) ===")
for off, fname in driver_fields:
    v = r(drv + off)
    print(f"  drv+0x{off:04X} {fname:20s} = 0x{v:08X} ({v})")

# Also read the pitStop compounds
print("\n=== Pit stop compounds ===")
for off in [0x1170, 0x1174, 0x1178, 0x117C, 0x1180, 0x1184, 0x1188, 0x118C, 0x1190]:
    v = r(veh + off)
    print(f"  veh+0x{off:04X} = 0x{v:08X} ({v})")

# Check pit lane - pitFlags from VehiclePitFlags
print("\n=== Pit flags ===")
v = r(0x5F073C + i * STR)
print(f"  VehiclePitFlags[{i}] = {v}")

k32.CloseHandle(h)
