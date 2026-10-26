import ctypes, struct
pid = 18532
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10 | 0x20 | 0x8, False, pid)

b4 = ctypes.create_string_buffer(4)
def r(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<I', b4.raw)[0]
def rf(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<f', b4.raw)[0]

i = 7  # Raikkonen
veh = r(0x7C54F0 + i*4)
DRV = 0x5F0DEC; STR = 0x48C0

print(f"=== Raikkonen IN PITS ===")
# Veh fields
for off, name in [
    (0x4064, "FinishState"), (0x4068, "ReasonCode"),
    (0x4510, "behavior_state"), (0x443C, "safety_follow"),
    (0x44B0, "queue_count"), (0x32C8, "pit_gate"),
    (0x4070, "damageFlags"), (0x402C+20, "pitSubst+20"),
    (0x402C+40, "pitSubst+40"), (0x402C+44, "pitSubst+44"),
]:
    print(f"  +0x{off:04X} {name:20s} = {r(veh+off)}")
for off, name in [
    (0x0394, "wing_damage"), (0x15FC, "aero_damage"),
    (0x453C, "liveLapRatio"), (0x44F4, "baseSpeed"),
    (0x02D4, "actualSpeed"),
]:
    print(f"  +0x{off:04X} {name:20s} = {rf(veh+off):.4f}")

# Driver block
print(f"\n=== Driver block ===")
for off, name in [
    (0x01C8, "callToBox"), (0x0204, "driverStatus"),
    (0x06B4, "position"), (0x06D8, "lapNumber"),
    (0x12C4, "pittingStatus"),
]:
    v = r(DRV + i*STR + off)
    print(f"  +0x{off:04X} {name:20s} = {v} (0x{v:08X})")

print(f"\nVehiclePitFlags = {r(0x5F073C + i*STR)}")

k32.CloseHandle(h)
