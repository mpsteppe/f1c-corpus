import ctypes, struct, time

pid = 20592
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x20 | 0x8 | 0x10, False, pid)
b4 = ctypes.create_string_buffer(4)
bn = ctypes.create_string_buffer(64)

def ru32(a):
    k32.ReadProcessMemory(h, a, b4, 4, None)
    return struct.unpack('<I', b4.raw)[0]
def wu32(a, v):
    k32.WriteProcessMemory(h, a, struct.pack('<I', v), 4, None)
def wf32(a, v):
    k32.WriteProcessMemory(h, a, struct.pack('<f', v), 4, None)
def name(veh):
    k32.ReadProcessMemory(h, veh + 0x4620, bn, 64, None)
    raw = bn.raw; null = raw.find(b'\x00')
    if null >= 0: raw = raw[:null]
    return ''.join(chr(c) if 32 <= c < 127 else '' for c in raw).strip()

count = ru32(0x5C329C)
player = ru32(0x7C54E8)
retired = 0

print(f"Vehicles: {count}, Player: 0x{player:08x}")
print("=" * 50)

for i in range(count):
    veh = ru32(0x7C54F0 + i * 4)
    if not veh or veh < 0x10000:
        continue
    if veh == player:
        n = name(veh)
        fs = ru32(veh + 0x4064)
        print(f"[{i:2d}] {n:35s} (YOU) finish={fs} -- SKIP")
        continue
    
    n = name(veh)
    fs = ru32(veh + 0x4064)
    
    if fs != 0:
        print(f"[{i:2d}] {n:35s} finish={fs} -- already out, skip")
        continue
    
    # Slow + retire
    wu32(veh + 0x4064, 2)   # DNF
    wu32(veh + 0x4068, 5)   # gearbox
    wu32(0x5F073C + i * 0x48C0, 3)  # pit flag
    wf32(veh + 0x453C, 0.1)  # slow
    retired += 1
    print(f"[{i:2d}] {n:35s} RETIRED (finish=2, reason=5, ratio=0.1)")

print(f"\nRetired {retired} AI cars")
print("Wait ~5s for effect, then mini-restart...")

k32.CloseHandle(h)
