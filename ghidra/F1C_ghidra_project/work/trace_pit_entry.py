import ctypes, struct, time, sys
pid=1800
k32=ctypes.windll.kernel32
h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4)
def r(a):
    k32.ReadProcessMemory(h,a,b,4,None)
    return struct.unpack('<I',b.raw)[0]

last_val = r(0x7CE258)
last_ses = r(0x7C56A4)
t0 = time.time()
print(f"t=0.0s val={last_val} ses={last_ses} — drive into pit lane now")
sys.stdout.flush()

for _ in range(600):
    v = r(0x7CE258)
    s = r(0x7C56A4)
    if v != last_val or s != last_ses:
        t = time.time() - t0
        print(f"*** t={t:.1f}s val={last_val}->{v} ses={last_ses}->{s}")
        sys.stdout.flush()
        last_val = v
        last_ses = s
    time.sleep(0.05)

k32.CloseHandle(h)
print("Stopped.")
