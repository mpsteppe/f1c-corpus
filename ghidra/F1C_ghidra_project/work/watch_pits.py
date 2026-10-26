import ctypes, struct, time
pid=1800;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4);rn=ctypes.create_string_buffer(64)

def r(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<I',b.raw)[0]
def name(veh):
    k32.ReadProcessMemory(h,veh+0x4620,rn,64,None)
    raw=rn.raw;null=raw.find(b'\x00')
    if null>=0: raw=raw[:null]
    return ''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()

print("Watching dword_7CE258 (pit entry). Drive into pit lane now...")
print("Press Ctrl+C to stop.")
last = r(0x7CE258)
phase = r(0x7C56A8)
player = r(0x7C54E8)
print(f"Initial: 7CE258={last}, Phase={phase}, PlayerSpeed={struct.unpack('<f',struct.pack('<I',r(player+0x2D4)))[0]:.0f}")

try:
    while True:
        v = r(0x7CE258)
        if v != last:
            print(f"*** 7CE258 CHANGED: {last} -> {v} ***")
            last = v
            if v == 1:
                print("PLAYER IN PIT LANE!")
                break
        time.sleep(0.1)
except KeyboardInterrupt:
    print("Stopped.")
k32.CloseHandle(h)
