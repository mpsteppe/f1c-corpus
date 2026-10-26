import ctypes, struct, os
pid = 1800
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10, False, pid)
b4 = ctypes.create_string_buffer(4)

def r(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<I', b4.raw)[0]
def rf(a): k32.ReadProcessMemory(h, a, b4, 4, None); return struct.unpack('<f', b4.raw)[0]

player = r(0x7C54E8)
DRV = 0x5F0DEC
STR = 0x48C0

print("=== BASELINE: No pit request active ===")
print(f"  Player veh=0x{player:08X}")
print(f"  Session={r(0x7C56A4)} State={r(0x7C569C)} Phase={r(0x7C56A8)} Active={r(0x7D0308)}")
print(f"  VCount={r(0x5C329C)}")
print(f"  dword_7CE258={r(0x7CE258)} dword_7CE254={r(0x7CE254)}")

# Globals
print("\n--- Restart/pit globals ---")
for addr, name in [
    (0x7CE25D, "mini_restart_flag"),
    (0x7CE25E, "full_restart_flag"),
    (0x7CE258, "pit_entry_global"),
    (0x7CE264, "skip_restart"),
    (0x7CE254, "paused_flag"),
    (0x7CE814, "qualy_dsq_enabled"),
    (0x7D05A0, "lap_count"),
    (0x7CEC38, "pit_window_timer"),
]:
    print(f"  {name:25s} = {r(addr)} (0x{r(addr):08X})")

# Vehicle struct — critical pit region
print("\n--- Vehicle pit substruct (0x402C-0x4090) ---")
for off in range(0x402C, 0x4090, 4):
    v = r(player + off)
    f = rf(player + off)
    print(f"  +0x{off:04X} = 0x{v:08X} int={v:12d} float={f:.4f}")

# Vehicle struct — AI/pit behavior
print("\n--- AI/pit behavior region ---")
for off, name in [
    (0x4510, "behavior_state"),
    (0x443C, "safety_follow"),
    (0x44A8, "queue_ptr"),
    (0x44B0, "queue_count"),
    (0x453C, "liveLapRatio", True),
    (0x44F4, "baseSpeed", True),
    (0x02D4, "actualSpeed", True),
    (0x09A8, "carConditions"),
    (0x32C8, "pit_gate_32C8"),
    (0x4070, "damageFlags"),
    (0x1180, "PitStopFlag"),
    (0x3D60, "this3928"),
]:
    is_float = len(name) > 1 and name[1] is True
    if is_float:
        f = rf(player + off)
        print(f"  +0x{off:04X} {name:25s} = {f:.4f}")
    else:
        v = r(player + off)
        print(f"  +0x{off:04X} {name:25s} = 0x{v:08X} ({v})")

# Driver block
print("\n--- Driver block ---")
for off, name in [
    (0x01C8, "callToBox", True),
    (0x0204, "driverStatus", True),
    (0x0188, "nextChosenTires"),
    (0x12C4, "pittingStatus", True),
    (0x06B4, "position"),
    (0x06BC, "plannedPosition"),
    (0x06D8, "lapNumber"),
    (0x06B1, "DNF_DSQ"),
    (0x1290, "nextStintFuel", True),
    (0x1418, "penalties0"),
    (0x141C, "penalties1"),
    (0x1420, "penalties2"),
]:
    is_float = len(name) > 1 and name[1] is True
    if is_float:
        f = rf(DRV + off)
        print(f"  drv+0x{off:04X} {name:25s} = {f:.4f}")
    else:
        v = r(DRV + off)
        print(f"  drv+0x{off:04X} {name:25s} = {v} (0x{v:08X})")

print(f"\n  VehiclePitFlags = {r(0x5F073C + 0*STR)}")

k32.CloseHandle(h)
