"""Trace Hakkinen (idx 2) + grid order during restart."""
import ctypes, ctypes.wintypes, struct, time, sys

PROC_NAME = "F1 Challenge Online.exe"
VEHICLE_ARRAY = 0x007C54F0
VEHICLE_COUNT = 0x005C329C
PLAYER_VEHICLE = 0x007C54E8

PROCESS_ALL_ACCESS = 0x1F0FFF
TH32CS_SNAPPROCESS = 0x00000002

class PE(ctypes.Structure):
    _fields_ = [("dwSize", ctypes.c_ulong), ("cntUsage", ctypes.c_ulong),
                 ("th32ProcessID", ctypes.c_ulong), ("th32DefaultHeapID", ctypes.POINTER(ctypes.c_ulong)),
                 ("th32ModuleID", ctypes.c_ulong), ("cntThreads", ctypes.c_ulong),
                 ("th32ParentProcessID", ctypes.c_ulong), ("pcPriClassBase", ctypes.c_long),
                 ("dwFlags", ctypes.c_ulong), ("szExeFile", ctypes.c_char * 260)]

def open_proc():
    snap = ctypes.windll.kernel32.CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)
    pe = PE(); pe.dwSize = ctypes.sizeof(PE)
    ctypes.windll.kernel32.Process32First(snap, ctypes.byref(pe))
    while True:
        if PROC_NAME.lower() in pe.szExeFile.decode(errors='ignore').lower():
            pid = pe.th32ProcessID
            ctypes.windll.kernel32.CloseHandle(snap)
            return ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_ACCESS, False, pid), pid
        if not ctypes.windll.kernel32.Process32Next(snap, ctypes.byref(pe)):
            break
    ctypes.windll.kernel32.CloseHandle(snap)
    return None, None

def ri(h, addr):
    buf = (ctypes.c_char * 4)()
    br = ctypes.c_ulong(0)
    ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), buf, 4, ctypes.byref(br))
    return struct.unpack('<i', buf)[0]

def rf(h, addr):
    buf = (ctypes.c_char * 4)()
    br = ctypes.c_ulong(0)
    ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), buf, 4, ctypes.byref(br))
    return struct.unpack('<f', buf)[0]

def rs(h, addr):
    buf = (ctypes.c_char * 64)()
    br = ctypes.c_ulong(0)
    ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), buf, 64, ctypes.byref(br))
    return buf.value.decode(errors='ignore')

h, pid = open_proc()
if not h:
    print("Game not found"); sys.exit(1)

idx = 2  # Hakkinen
veh = ri(h, VEHICLE_ARRAY + idx * 4)
name = rs(h, veh + 0x4620)

f = open("mods/red_flag_v2/trace_output.txt", "w", buffering=1)

def log(msg):
    print(msg, flush=True)
    f.write(msg + "\n")

log(f"Tracing [{idx}] {name} (veh=0x{veh:08X})")
log(f"{'Time':>6} {'GS':>2} {'FinSt':>5} {'Reas':>4} {'Ret':>3} {'Act':>3} {'QP':>3} {'RP':>3} {'Spd':>7}")
log("-" * 50)

prev = None
t0 = time.time()
try:
    while time.time() - t0 < 45:
        gs = ri(h, 0x007C569C)
        fs = ri(h, veh + 0x4064)
        rc = ri(h, veh + 0x4068)
        ret = ri(h, veh + 0x4410) & 0xFF
        act = ri(h, veh + 0x45F4) & 0xFF
        qp = ri(h, veh + 0x4058)
        rp = ri(h, veh + 0x4060)
        spd = rf(h, veh + 0x4440)

        cur = (gs, fs, rc, ret, act, qp, rp)
        elapsed = time.time() - t0
        if cur != prev:
            log(f"{elapsed:6.1f} {gs:2} {fs:5} {rc:4} {ret:3} {act:3} {qp:3} {rp:3} {spd:7.1f}")
            prev = cur
        time.sleep(0.05)
except KeyboardInterrupt:
    pass

# Final grid dump
log("\n=== FINAL GRID ===")
count = ri(h, VEHICLE_COUNT)
cars = []
for i in range(min(count, 26)):
    v = ri(h, VEHICLE_ARRAY + i * 4)
    if not v: continue
    n = rs(h, v + 0x4620) or '???'
    q = ri(h, v + 0x4058)
    r = ri(h, v + 0x4060)
    fst = ri(h, v + 0x4064)
    ret2 = ri(h, v + 0x4410) & 0xFF
    act2 = ri(h, v + 0x45F4) & 0xFF
    cars.append((r, n, q, fst, ret2, act2))
cars.sort()
for r, n, q, fst, ret2, act2 in cars:
    log(f"  P{r:<2} {n:24} Q={q:2} FS={fst} Ret={ret2} Act={act2}")

f.close()
ctypes.windll.kernel32.CloseHandle(h)
