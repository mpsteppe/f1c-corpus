"""
monitor_puncture.py — live monitor for a single AI driver's tire puncture fields

Usage: python monitor_puncture.py <driver_index> [--hz 2]

Reads the 4 tire puncture floats from driver block for the given AI index.
Run BEFORE injecting DLL to see baseline, then trigger red flag to see changes.
"""
import ctypes, ctypes.wintypes, struct, sys, time, os

PROC_NAME = "F1 Challenge Online.exe"
DRIVER_BASE = 0x005F0DEC
STRIDE = 0x48C0

TIRE_FL = 3568
TIRE_FR = 3816
TIRE_RL = 4064
TIRE_RR = 4312

FINISH_STATE_OFF = 0x4064
REASON_CODE_OFF = 0x4068
CALLTOBOX_OFF = 0x01C8
POSITION_OFF = 0x06B4

PROCESS_VM_READ = 0x0010

def open_proc():
    k32 = ctypes.windll.kernel32
    h = k32.CreateToolhelp32Snapshot(2, 0)  # TH32CS_SNAPPROCESS
    if h == -1:
        return None
    pe = ctypes.c_uint32()
    pe.value = ctypes.sizeof(type('', (), {'dwSize': ctypes.c_uint32, 'cntUsage': ctypes.c_uint32,
        'th32ProcessID': ctypes.c_uint32, 'th32DefaultHeapID': ctypes.c_ulong,
        'th32ModuleID': ctypes.c_uint32, 'cntThreads': ctypes.c_uint32,
        'th32ParentProcessID': ctypes.c_uint32, 'pcPriClassBase': ctypes.c_long,
        'dwFlags': ctypes.c_uint32, 'szExeFile': ctypes.c_char * 260})())
    setattr(pe, 'dwSize', ctypes.sizeof(pe))
    ctypes.memset(ctypes.addressof(pe), 0, ctypes.sizeof(pe))
    pe.dwSize = ctypes.sizeof(pe)

    if not k32.Process32First(h, ctypes.byref(pe)):
        k32.CloseHandle(h)
        return None

    pid = None
    while True:
        name = pe.szExeFile.decode('ascii', errors='ignore').lower()
        if name == PROC_NAME.lower():
            pid = pe.th32ProcessID
            break
        if not k32.Process32Next(h, ctypes.byref(pe)):
            break
    k32.CloseHandle(h)

    if not pid:
        return None

    handle = k32.OpenProcess(PROCESS_VM_READ, False, pid)
    return handle, pid

def read_float(handle, addr):
    buf = ctypes.c_uint32()
    k32 = ctypes.windll.kernel32
    if k32.ReadProcessMemory(handle, ctypes.c_void_p(addr), ctypes.byref(buf), 4, None):
        return struct.unpack('<f', buf.value.to_bytes(4, 'little'))[0]
    return None

def read_int(handle, addr):
    buf = ctypes.c_uint32()
    k32 = ctypes.windll.kernel32
    if k32.ReadProcessMemory(handle, ctypes.c_void_p(addr), ctypes.byref(buf), 4, None):
        return buf.value
    return None

def main():
    if len(sys.argv) < 2:
        print("Usage: python monitor_puncture.py <driver_index> [--hz N]")
        print("  driver_index 0 = first AI (skip player)")
        print("  Reads from driver block at 0x5F0DEC + idx * 0x48C0")
        sys.exit(1)

    driver_idx = int(sys.argv[1])
    hz = 2
    if '--hz' in sys.argv:
        hz = int(sys.argv[sys.argv.index('--hz') + 1])

    addr_addr = DRIVER_BASE + driver_idx * STRIDE

    result = open_proc()
    if not result:
        print(f"ERROR: {PROC_NAME} not found. Is the game running?")
        sys.exit(1)

    handle, pid = result
    print(f"Monitoring driver index {driver_idx} at 0x{addr_addr:08X}")
    print(f"Tire puncture fields (positive offsets from driver block):")
    print(f"  FL: 0x{addr_addr:08X} + {TIRE_FL} = 0x{addr_addr + TIRE_FL:08X}")
    print(f"  FR: 0x{addr_addr:08X} + {TIRE_FR} = 0x{addr_addr + TIRE_FR:08X}")
    print(f"  RL: 0x{addr_addr:08X} + {TIRE_RL} = 0x{addr_addr + TIRE_RL:08X}")
    print(f"  RR: 0x{addr_addr:08X} + {TIRE_RR} = 0x{addr_addr + TIRE_RR:08X}")
    print(f"Other fields:")
    print(f"  position: +0x06B4 = 0x{addr_addr + POSITION_OFF:08X}")
    print(f"  callToBox: +0x01C8 = 0x{addr_addr + CALLTOBOX_OFF:08X}")
    print()
    print(f"{'Time':>8s} | {'FL':>8s} {'FR':>8s} {'RL':>8s} {'RR':>8s} | pos  callToBox")
    print("-" * 80)

    try:
        while True:
            t = time.time()

            fl = read_float(handle, addr_addr + TIRE_FL)
            fr = read_float(handle, addr_addr + TIRE_FR)
            rl = read_float(handle, addr_addr + TIRE_RL)
            rr = read_float(handle, addr_addr + TIRE_RR)
            pos = read_int(handle, addr_addr + POSITION_OFF)
            c2b = read_int(handle, addr_addr + CALLTOBOX_OFF)

            def fmt_float(v):
                return f"{v:8.4f}" if v is not None else "    None"

            def fmt_int(v):
                return f"{v:3d}" if v is not None else "None"

            print(f"{t % 1000:8.3f} | {fmt_float(fl)} {fmt_float(fr)} {fmt_float(rl)} {fmt_float(rr)} | {fmt_int(pos)} {fmt_int(c2b)}")

            time.sleep(1.0 / hz)
    except KeyboardInterrupt:
        pass
    finally:
        ctypes.windll.kernel32.CloseHandle(handle)

if __name__ == '__main__':
    main()
