import ctypes, struct, time
pid = 18532
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x20 | 0x8 | 0x10, False, pid)

b = ctypes.create_string_buffer(4)
def r(a): k32.ReadProcessMemory(h, a, b, 4, None); return struct.unpack('<I', b.raw)[0]
def rf(a): k32.ReadProcessMemory(h, a, b, 4, None); return struct.unpack('<f', b.raw)[0]
def wf(a, v): k32.WriteProcessMemory(h, a, struct.pack('<f', v), 4, None)
def wu(a, v): k32.WriteProcessMemory(h, a, struct.pack('<I', v), 4, None)

veh = r(0x7C54F0 + 1*4)  # Schumacher slot 1
print(f"Schumacher veh=0x{veh:08X}")

# Write ALL damage fields in burst
print("Writing damage burst:")
damage_fields = [
    (0x0394, 1.0, 'rear wing'),
    (0x15FC, 1.0, 'aero damage'),
]
for off, val, name in damage_fields:
    before = rf(veh + off)
    wf(veh + off, val)
    after = rf(veh + off)
    print(f"  +0x{off:04X} ({name}): {before:.4f} -> {after:.4f}")

# Also set finish+reason
wu(veh + 0x4064, 3)
wu(veh + 0x4068, 5)
print(f"  FinishState=3, ReasonCode=5")

# Rapid re-write loop (try to beat overwrite)
print("Rapid writes for 2s...")
for i in range(200):
    wf(veh + 0x0394, 1.0)
    time.sleep(0.01)

print(f"Final: wing={rf(veh+0x0394):.4f} finish={r(veh+0x4064)}")
k32.CloseHandle(h)
print("Spectate Schumacher — does he pit?")
