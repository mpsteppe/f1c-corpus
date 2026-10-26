import ctypes, struct, time, sys
# Quick burst test: DSQ all AI + mini-restart
pid = int(sys.argv[1]) if len(sys.argv) > 1 else 19880
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x20 | 0x8 | 0x10, False, pid)

def ru32(a):
    b = ctypes.create_string_buffer(4)
    k32.ReadProcessMemory(h, a, b, 4, None)
    return struct.unpack('<I', b.raw)[0]
def wu32(a, v):
    k32.WriteProcessMemory(h, a, struct.pack('<I', v), 4, None)
def wf32(a, v):
    k32.WriteProcessMemory(h, a, struct.pack('<f', v), 4, None)

print("DSQ all AI...")
count = ru32(0x5C329C)
player = ru32(0x7C54E8)
retired = 0
for i in range(count):
    veh = ru32(0x7C54F0 + i * 4)
    if not veh or veh < 0x10000 or veh == player:
        continue
    if ru32(veh + 0x4064) != 0:
        continue
    wu32(veh + 0x4064, 3)   # DSQ
    wu32(veh + 0x4068, 5)   # gearbox
    wf32(veh + 0x453C, 0.1)  # slow
    wu32(0x5F073C + i * 0x48C0, 3)  # pit flag
    retired += 1
print(f"  {retired} AI DSQ'd")

print("Wait 3s...")
time.sleep(3)

print("Mini-restart: laps=10 + flag")
wu32(0x7D05A0, 10)
wu32(0x7CE25D, 1)
print("Done. Observe!")
k32.CloseHandle(h)
