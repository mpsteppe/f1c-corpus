"""Poll Coulthard (idx 3) every 0.5s to capture retirement transition."""
import ctypes, struct, time, sys

PROC_NAME = "F1 Challenge Online.exe"
VEHICLE_ARRAY = 0x007C54F0
DRIVER_NAME = 0x4620

def open_proc():
    import ctypes.wintypes
    PROCESS_ALL_ACCESS = 0x1F0FFF
    TH32CS_SNAPPROCESS = 0x00000002
    class PE(ctypes.Structure):
        _fields_ = [("dwSize", ctypes.c_ulong), ("cntUsage", ctypes.c_ulong),
                     ("th32ProcessID", ctypes.c_ulong), ("th32DefaultHeapID", ctypes.POINTER(ctypes.c_ulong)),
                     ("th32ModuleID", ctypes.c_ulong), ("cntThreads", ctypes.c_ulong),
                     ("th32ParentProcessID", ctypes.c_ulong), ("pcPriClassBase", ctypes.c_long),
                     ("dwFlags", ctypes.c_ulong), ("szExeFile", ctypes.c_char * 260)]
    snap = ctypes.windll.kernel32.CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)
    pe = PE(); pe.dwSize = ctypes.sizeof(PE)
    ctypes.windll.kernel32.Process32First(snap, ctypes.byref(pe))
    while True:
        if PROC_NAME.lower() in pe.szExeFile.decode(errors='ignore').lower():
            pid = pe.th32ProcessID
            ctypes.windll.kernel32.CloseHandle(snap)
            h = ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_ACCESS, False, pid)
            return h, pid
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

idx = int(sys.argv[1]) if len(sys.argv) > 1 else 3
veh = ri(h, VEHICLE_ARRAY + idx * 4)
name = rs(h, veh + DRIVER_NAME)
print(f"Polling [{idx}] {name} (veh=0x{veh:08X}) every 0.5s")
print(f"{'Time':>6} {'FinSt':>5} {'Reas':>4} {'Retire':>6} {'Active':>6} {'AIMode':>6} {'PitSt':>5} {'Speed':>8} {'SpCap':>7} {'X':>8} {'Z':>8}")
print("-" * 85)

prev = None
t0 = time.time()
try:
    while True:
        fs = ri(h, veh + 0x4064)
        rc = ri(h, veh + 0x4068)
        ret = ri(h, veh + 0x4410) & 0xFF
        act = ri(h, veh + 0x45F4) & 0xFF
        aim = ri(h, veh + 0x3450)
        pit = ri(h, veh + 0x4040)
        spd = rf(h, veh + 0x4440)
        cap = rf(h, veh + 0x453C)
        x = rf(h, veh + 0x1C)
        z = rf(h, veh + 0x24)
        
        cur = (fs, rc, ret, act, aim, pit)
        elapsed = time.time() - t0
        
        # Always print if state changed, or every 2s for position updates
        if cur != prev or int(elapsed * 2) % 4 == 0:
            marker = " <<<" if cur != prev and prev is not None else ""
            print(f"{elapsed:6.1f} {fs:5} {rc:4} {ret:6} {act:6} {aim:6} {pit:5} {spd:7.1f}m {cap:7.4f} {x:8.1f} {z:8.1f}{marker}")
            prev = cur
        
        time.sleep(0.5)
except KeyboardInterrupt:
    pass

ctypes.windll.kernel32.CloseHandle(h)
print("\nDone.")
