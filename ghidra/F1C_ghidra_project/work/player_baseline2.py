import ctypes, struct, os
pid = 1800
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10, False, pid)
b4 = ctypes.create_string_buffer(4)

def r(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<I', b4.raw)[0]
def rf(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<f', b4.raw)[0]

player = r(0x7C54E8)
DRV = 0x5F0DEC; STR = 0x48C0

print("=== CONTINUED: AI/pit behavior region ===")
for off, name in [
    (0x453C, "liveLapRatio"), (0x44F4, "baseSpeed"), (0x02D4, "actualSpeed"),
    (0x09A8, "carConditions"), (0x32C8, "pit_gate_32C8"),
    (0x1180, "PitStopFlag"), (0x3D60, "this3928"),
]:
    print(f"  +0x{off:04X} {name:25s} = {rf(player+off):.4f}")

print("\n--- Driver block ---")
for off, name in [
    (0x01C8, "callToBox"), (0x0204, "driverStatus"),
    (0x0188, "nextChosenTires"), (0x12C4, "pittingStatus"),
    (0x06B4, "position"), (0x06BC, "plannedPosition"),
    (0x06D8, "lapNumber"), (0x06B1, "DNF_DSQ"),
    (0x1290, "nextStintFuel"), (0x1418, "penalties0"),
]:
    f = rf(DRV + off)
    print(f"  drv+0x{off:04X} {name:25s} = {f:.4f}")

print(f"\n  VehiclePitFlags = {r(0x5F073C + 0*STR)}")

# Dump all non-zero driver floats (0x0100-0x2000)
print("\n--- All REGULAR driver floats (0x0100-0x2000) ---")
for off in range(0x0100, 0x2000, 4):
    f = rf(DRV + off)
    if f != 0 and abs(f) < 10000:
        print(f"  drv+0x{off:04X} = {f:.4f}")

k32.CloseHandle(h)
