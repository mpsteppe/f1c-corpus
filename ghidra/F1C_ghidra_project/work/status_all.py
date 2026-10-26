import ctypes, struct

pid = 5492
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10 | 0x20 | 0x8, False, pid)
b4 = ctypes.create_string_buffer(4)
b80 = ctypes.create_string_buffer(80)

def ru32(a):
    k32.ReadProcessMemory(h, a, b4, 4, None)
    return struct.unpack('<I', b4.raw)[0]
def wu32(a, v):
    k32.WriteProcessMemory(h, a, struct.pack('<I', v), 4, None)
def rstr(a, n=64):
    k32.ReadProcessMemory(h, a, b80, n, None)
    raw = b80.raw
    null = raw.find(b'\x00')
    if null >= 0: raw = raw[:null]
    return ''.join(chr(b) if 32 <= b < 127 else '' for b in raw)

print("=== All vehicles ===")
for slot in range(0, 8):
    veh = ru32(0x007C54F0 + slot * 4)
    if veh < 0x10000:
        print(f"  slot {slot}: NULL")
        continue
    name = rstr(veh + 0x4620, 64).strip()
    state = ru32(veh + 0x4064)
    reason = ru32(veh + 0x4068)
    pit = ru32(0x005F073C + slot * 0x48C0)
    player = " [YOU]" if veh == ru32(0x007C54E8) else ""
    print(f"  slot {slot}: {name} finish={state} reason={reason} pit={pit}{player}")

k32.CloseHandle(h)
