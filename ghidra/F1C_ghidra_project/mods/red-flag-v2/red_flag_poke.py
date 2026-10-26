"""
red_flag_poke.py — live red flag via Python WriteProcessMemory (no DLL needed)

Usage:
  python red_flag_poke.py monitor <driver_idx>     # watch one driver's tire fields
  python red_flag_poke.py puncture <driver_idx>    # inject puncture on one AI
  python red_flag_poke.py puncture-all             # inject puncture on ALL AI
  python red_flag_poke.py retire-all               # DSQ all AI
  python red_flag_poke.py restart                  # trigger mini-restart
"""
import ctypes, ctypes.wintypes, struct, sys, time

PROC_NAME = "F1 Challenge Online.exe"
DRIVER_BASE = 0x005F0DEC
STRIDE = 0x48C0

TIRE_FL = 3568
TIRE_FR = 3816
TIRE_RL = 4064
TIRE_RR = 4312

FINISH_STATE = 0x4064
REASON_CODE = 0x4068
DRIVER_NAME = 0x4620   # null-terminated string in vehicle struct

VEHICLE_COUNT = 0x005C329C
VEHICLE_ARRAY = 0x007C54F0
PLAYER_VEHICLE = 0x007C54E8
RESTART_FLAG = 0x007CE25D
PIT_ENTRY = 0x007CE258
LAP_COUNT = 0x007D05A0
GAME_STATE = 0x007C569C

PROCESS_VM_RW = 0x0010 | 0x0020 | 0x0008  # VM_READ | VM_WRITE | VM_OPERATION

def open_proc():
    k32 = ctypes.windll.kernel32

    class PROCESSENTRY32W(ctypes.Structure):
        _fields_ = [
            ("dwSize",              ctypes.c_uint32),
            ("cntUsage",            ctypes.c_uint32),
            ("th32ProcessID",       ctypes.c_uint32),
            ("th32DefaultHeapID",   ctypes.c_void_p),     # ULONG_PTR
            ("th32ModuleID",        ctypes.c_uint32),
            ("cntThreads",          ctypes.c_uint32),
            ("th32ParentProcessID", ctypes.c_uint32),
            ("pcPriClassBase",      ctypes.c_long),
            ("dwFlags",             ctypes.c_uint32),
            ("szExeFile",           ctypes.c_wchar * 260),
        ]

    pe = PROCESSENTRY32W()
    pe.dwSize = ctypes.sizeof(PROCESSENTRY32W)

    h_snap = k32.CreateToolhelp32Snapshot(2, 0)
    if h_snap == -1 or h_snap is None:
        return None, None

    pid = None
    if k32.Process32FirstW(h_snap, ctypes.byref(pe)):
        while True:
            name = pe.szExeFile.lower()
            if PROC_NAME.lower() in name:
                pid = pe.th32ProcessID
                break
            if not k32.Process32NextW(h_snap, ctypes.byref(pe)):
                break
    k32.CloseHandle(h_snap)

    if not pid:
        return None, None

    h = k32.OpenProcess(PROCESS_VM_RW, False, pid)
    return h, pid

def read_int(h, addr):
    buf = ctypes.c_uint32()
    if ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), ctypes.byref(buf), 4, None):
        return struct.unpack('<i', buf.value.to_bytes(4, 'little'))[0]
    return None

def read_float(h, addr):
    buf = ctypes.c_uint32()
    if ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), ctypes.byref(buf), 4, None):
        return struct.unpack('<f', buf.value.to_bytes(4, 'little'))[0]
    return None

def read_string(h, addr, maxlen=64):
    buf = ctypes.create_string_buffer(maxlen)
    if ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), buf, maxlen, None):
        return buf.value.decode('ascii', errors='replace').split('\x00')[0]
    return None

def write_float(h, addr, val):
    data = struct.pack('<f', val)
    ctypes.windll.kernel32.WriteProcessMemory(h, ctypes.c_void_p(addr), data, 4, None)

def write_int(h, addr, val):
    data = struct.pack('<i', val)
    ctypes.windll.kernel32.WriteProcessMemory(h, ctypes.c_void_p(addr), data, 4, None)

def write_byte(h, addr, val):
    data = struct.pack('<B', val)
    ctypes.windll.kernel32.WriteProcessMemory(h, ctypes.c_void_p(addr), data, 1, None)

def driver_addr(idx):
    return DRIVER_BASE + idx * STRIDE

def cmd_monitor(args):
    idx = int(args[0]) if args else 0
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    # Get vehicle pointer for this slot: VehiclePtrArray is at 0x007C54F0
    # Each slot: *(0x007C54F0 + idx*4) = vehicle ptr
    veh = read_int(h, VEHICLE_ARRAY + idx * 4)
    name = read_string(h, veh + DRIVER_NAME) if veh else "<?>"

    addr = driver_addr(idx)
    print(f"PID={pid}  Driver idx={idx} ({name})")
    print(f"  Driver block: 0x{addr:08X}  Vehicle: 0x{veh:08X}" if veh else "")
    print(f"{'Time':>8s} | {'FL':>8s}  {'FR':>8s}  {'RL':>8s}  {'RR':>8s} | callToBox  drvStatus")
    print("-" * 95)

    try:
        while True:
            t = time.time()
            fl = read_float(h, addr + TIRE_FL)
            fr = read_float(h, addr + TIRE_FR)
            rl = read_float(h, addr + TIRE_RL)
            rr = read_float(h, addr + TIRE_RR)
            c2b = read_int(h, addr + 0x01C8)
            ds = read_int(h, addr + 0x0204)

            def ff(v): return f"{v:8.4f}" if v is not None else "    None"
            def fi(v): return f"{v:5d}" if v is not None else " None"

            print(f"{t % 1000:8.3f} | {ff(fl)}  {ff(fr)}  {ff(rl)}  {ff(rr)} | {fi(c2b)} {fi(ds)}")
            time.sleep(0.5)
    except KeyboardInterrupt:
        pass
    finally:
        ctypes.windll.kernel32.CloseHandle(h)

def cmd_puncture(args):
    idx = int(args[0]) if args else 0
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    veh = read_int(h, VEHICLE_ARRAY + idx * 4)
    name = read_string(h, veh + DRIVER_NAME) if veh else "<?>"

    addr = driver_addr(idx)
    print(f"PID={pid}  Driver idx={idx}: {name}")
    if veh:
        print(f"  Vehicle: 0x{veh:08X}  Driver block: 0x{addr:08X}")
    print("Before:")
    print(f"  FL=0x{addr+TIRE_FL:08X}: {read_float(h, addr+TIRE_FL)}")
    print(f"  FR=0x{addr+TIRE_FR:08X}: {read_float(h, addr+TIRE_FR)}")
    print(f"  RL=0x{addr+TIRE_RL:08X}: {read_float(h, addr+TIRE_RL)}")
    print(f"  RR=0x{addr+TIRE_RR:08X}: {read_float(h, addr+TIRE_RR)}")

    print("Writing 0.77f to all 4 tires...")
    write_float(h, addr + TIRE_FL, 0.77)
    write_float(h, addr + TIRE_FR, 0.77)
    write_float(h, addr + TIRE_RL, 0.77)
    write_float(h, addr + TIRE_RR, 0.77)

    print("After (read-back):")
    print(f"  FL=0x{addr+TIRE_FL:08X}: {read_float(h, addr+TIRE_FL)}")
    print(f"  FR=0x{addr+TIRE_FR:08X}: {read_float(h, addr+TIRE_FR)}")
    print(f"  RL=0x{addr+TIRE_RL:08X}: {read_float(h, addr+TIRE_RL)}")
    print(f"  RR=0x{addr+TIRE_RR:08X}: {read_float(h, addr+TIRE_RR)}")

    ctypes.windll.kernel32.CloseHandle(h)

def cmd_puncture_all(args):
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    count = read_int(h, VEHICLE_COUNT)
    player = read_int(h, PLAYER_VEHICLE)

    if not count:
        print("ERROR: vehicle count null")
        ctypes.windll.kernel32.CloseHandle(h)
        return

    n = 0
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh or veh == player:
            continue
        addr = driver_addr(i)
        name = read_string(h, veh + DRIVER_NAME) if veh else "idx" + str(i)
        write_float(h, addr + TIRE_FL, 0.77)
        write_float(h, addr + TIRE_FR, 0.77)
        write_float(h, addr + TIRE_RL, 0.77)
        write_float(h, addr + TIRE_RR, 0.77)
        n += 1
        print(f"  [{n}] {name}: all 4 tires -> 0.77f")

    print(f"  Total: {n} AI punctured")
    ctypes.windll.kernel32.CloseHandle(h)

def cmd_retire_all(args):
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    count = read_int(h, VEHICLE_COUNT)
    player = read_int(h, PLAYER_VEHICLE)

    if not count:
        print("ERROR: vehicle count null")
        ctypes.windll.kernel32.CloseHandle(h)
        return

    n = 0
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh or veh == player:
            continue
        write_int(h, veh + FINISH_STATE, 3)
        write_int(h, veh + REASON_CODE, 5)
        n += 1

    print(f"  Retired (DSQ) {n} AI cars")
    ctypes.windll.kernel32.CloseHandle(h)

def cmd_restart(args):
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    laps = read_int(h, LAP_COUNT)
    print(f"  Current laps: {laps}, writing back {laps}")
    write_int(h, LAP_COUNT, laps)
    write_byte(h, RESTART_FLAG, 1)
    print(f"  Mini-restart triggered (byte_7CE25D=1)")
    ctypes.windll.kernel32.CloseHandle(h)

def cmd_read(args):
    """Read an arbitrary address: python red_flag_poke.py read <addr> [type: float|int]"""
    addr_str = args[0]
    ty = args[1] if len(args) > 1 else 'int'
    addr = int(addr_str, 16) if addr_str.startswith('0x') else int(addr_str)

    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    if ty == 'float':
        print(f"  0x{addr:08X} float: {read_float(h, addr)}")
    else:
        print(f"  0x{addr:08X} int: {read_int(h, addr)}")
    ctypes.windll.kernel32.CloseHandle(h)

def cmd_full_red_flag(args):
    """Full sequence: puncture → wait → retire → wait → restart"""
    import time as t

    h, pid = open_proc()
    if not h:
        print("ERROR: game not found")
        return

    count = read_int(h, VEHICLE_COUNT)
    player = read_int(h, PLAYER_VEHICLE)
    varr = read_int(h, VEHICLE_ARRAY)

    print(f"PID={pid}  Vehicles={count or '??'}")
    print("1. Injecting punctures on all AI...")

    n = 0
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh or veh == player:
            continue
        addr = driver_addr(i)
        write_float(h, addr + TIRE_FL, 0.77)
        write_float(h, addr + TIRE_FR, 0.77)
        write_float(h, addr + TIRE_RL, 0.77)
        write_float(h, addr + TIRE_RR, 0.77)
        n += 1
    print(f"  {n} AI punctured. Waiting 5s for AI to react...")

    for remaining in range(5, 0, -1):
        print(f"  {remaining}s...", end='\r')
        t.sleep(1)
    print()

    print("2. Retiring all AI (DSQ)...")
    n = 0
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh or veh == player:
            continue
        write_int(h, veh + FINISH_STATE, 3)
        write_int(h, veh + REASON_CODE, 5)
        n += 1
    print(f"  {n} AI retired.")

    print("3. Waiting for player to enter pits (read-back)...")
    print("   Polling pit_entry (0x007CE258)...")
    pit = 0
    waited = 0
    while not pit and waited < 60:
        pit = read_int(h, PIT_ENTRY)
        if pit != 1:
            t.sleep(1)
            waited += 1
            if waited % 5 == 0:
                print(f"  {waited}s... pit_entry={pit}, game_state={read_int(h, GAME_STATE)}")
            continue
    if pit == 1:
        print("  Player entered pits!")
    else:
        print("  Timeout waiting for pit entry.")

    laps = read_int(h, LAP_COUNT)
    print(f"4. Triggering restart (laps={laps})...")
    write_int(h, LAP_COUNT, laps)
    write_byte(h, RESTART_FLAG, 1)
    print("  Done. Restart triggered.")

    ctypes.windll.kernel32.CloseHandle(h)


RETIRED_FLAG = 0x4410
ACTIVE_FLAG  = 0x45F4

def cmd_retire_test(args):
    """Test proper retirement on one AI: set RetiredFlag+ActiveFlag+FinishState+ReasonCode"""
    idx = int(args[0]) if args else 1
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    player = read_int(h, PLAYER_VEHICLE)
    veh = read_int(h, VEHICLE_ARRAY + idx * 4)
    if not veh:
        print(f"ERROR: no vehicle at slot {idx}")
        ctypes.windll.kernel32.CloseHandle(h)
        return
    if veh == player:
        print("ERROR: that's the player car")
        ctypes.windll.kernel32.CloseHandle(h)
        return

    name = read_string(h, veh + DRIVER_NAME)
    print(f"PID={pid}  Target: [{idx}] {name}  veh=0x{veh:08X}")

    print("\nBEFORE:")
    print(f"  FinishState (+0x4064) = {read_int(h, veh + FINISH_STATE)}")
    print(f"  ReasonCode  (+0x4068) = {read_int(h, veh + REASON_CODE)}")
    print(f"  RetiredFlag (+0x4410) = {read_int(h, veh + RETIRED_FLAG) & 0xFF}")
    print(f"  ActiveFlag  (+0x45F4) = {read_int(h, veh + ACTIVE_FLAG) & 0xFF}")

    print("\nWriting retirement state...")
    write_int(h, veh + FINISH_STATE, 2)    # DNF
    write_int(h, veh + REASON_CODE, 6)     # puncture
    write_byte(h, veh + RETIRED_FLAG, 1)   # car to garage
    write_byte(h, veh + ACTIVE_FLAG, 0)    # driver removed

    print("\nAFTER (read-back):")
    print(f"  FinishState (+0x4064) = {read_int(h, veh + FINISH_STATE)}")
    print(f"  ReasonCode  (+0x4068) = {read_int(h, veh + REASON_CODE)}")
    print(f"  RetiredFlag (+0x4410) = {read_int(h, veh + RETIRED_FLAG) & 0xFF}")
    print(f"  ActiveFlag  (+0x45F4) = {read_int(h, veh + ACTIVE_FLAG) & 0xFF}")

    print(f"\n>>> Watch {name} in-game: car should go to pit garage, driver disappear.")
    print(">>> Check standings: should show DNF (puncture).")
    ctypes.windll.kernel32.CloseHandle(h)

def cmd_retire_status(args):
    """Show retirement state for all vehicles"""
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    count = read_int(h, VEHICLE_COUNT)
    player = read_int(h, PLAYER_VEHICLE)

    print(f"PID={pid}  Vehicles={count}")
    print(f"{'#':>2} {'Driver':24} {'FinSt':>5} {'Reason':>6} {'Retire':>6} {'Active':>6}")
    print("-" * 60)

    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh:
            continue
        name = read_string(h, veh + DRIVER_NAME) or "???"
        fs = read_int(h, veh + FINISH_STATE)
        rc = read_int(h, veh + REASON_CODE)
        rf = read_int(h, veh + RETIRED_FLAG) & 0xFF
        af = read_int(h, veh + ACTIVE_FLAG) & 0xFF
        tag = " *P*" if veh == player else ""
        print(f"{i:2} {name:24} {fs:5} {rc:6} {rf:6} {af:6}{tag}")

    ctypes.windll.kernel32.CloseHandle(h)

def cmd_undo_retire(args):
    """Undo retirement on one AI: clear all flags"""
    idx = int(args[0]) if args else 1
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    veh = read_int(h, VEHICLE_ARRAY + idx * 4)
    if not veh:
        print(f"ERROR: no vehicle at slot {idx}")
        ctypes.windll.kernel32.CloseHandle(h)
        return

    name = read_string(h, veh + DRIVER_NAME)
    print(f"Undoing retirement for [{idx}] {name}...")

    write_int(h, veh + FINISH_STATE, 0)
    write_int(h, veh + REASON_CODE, 0)
    write_byte(h, veh + RETIRED_FLAG, 0)
    write_byte(h, veh + ACTIVE_FLAG, 1)

    print("Done. Read-back:")
    print(f"  FinishState = {read_int(h, veh + FINISH_STATE)}")
    print(f"  ReasonCode  = {read_int(h, veh + REASON_CODE)}")
    print(f"  RetiredFlag = {read_int(h, veh + RETIRED_FLAG) & 0xFF}")
    print(f"  ActiveFlag  = {read_int(h, veh + ACTIVE_FLAG) & 0xFF}")
    ctypes.windll.kernel32.CloseHandle(h)

PIT_STATE = 0x4040
AI_MODE   = 0x3450
SPEED_CAP = 0x453C

def cmd_pit_retire(args):
    """Trigger natural retirement: set PitState=2 + AIMode=1, game cascades the rest"""
    idx = int(args[0]) if args else 1
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    player = read_int(h, PLAYER_VEHICLE)
    veh = read_int(h, VEHICLE_ARRAY + idx * 4)
    if not veh:
        print(f"ERROR: no vehicle at slot {idx}")
        ctypes.windll.kernel32.CloseHandle(h)
        return
    if veh == player:
        print("ERROR: that's the player car")
        ctypes.windll.kernel32.CloseHandle(h)
        return

    name = read_string(h, veh + DRIVER_NAME)
    print(f"PID={pid}  Target: [{idx}] {name}  veh=0x{veh:08X}")

    print("\nBEFORE:")
    print(f"  PitState  (+0x4040) = {read_int(h, veh + PIT_STATE)}")
    print(f"  AIMode    (+0x3450) = {read_int(h, veh + AI_MODE)}")
    print(f"  SpeedCap  (+0x453C) = {read_float(h, veh + SPEED_CAP):.4f}")
    print(f"  FinishSt  (+0x4064) = {read_int(h, veh + FINISH_STATE)}")
    print(f"  RetiredFl (+0x4410) = {read_int(h, veh + RETIRED_FLAG) & 0xFF}")
    print(f"  ActiveFl  (+0x45F4) = {read_int(h, veh + ACTIVE_FLAG) & 0xFF}")

    print("\nWriting PitState=2, AIMode=1...")
    write_int(h, veh + PIT_STATE, 2)
    write_int(h, veh + AI_MODE, 1)

    print("\nAFTER (read-back):")
    print(f"  PitState  (+0x4040) = {read_int(h, veh + PIT_STATE)}")
    print(f"  AIMode    (+0x3450) = {read_int(h, veh + AI_MODE)}")

    print(f"\n>>> Watch {name}: should drive to pit and retire naturally.")
    print(">>> Game will set FinishState/RetiredFlag/ActiveFlag on its own.")
    ctypes.windll.kernel32.CloseHandle(h)

RACE_POS = 0x4060
QUAL_POS = 0x4058
LAPS_ADDR = 0x007D05A0

def cmd_redflag2(args):
    """Red flag v2: retire all AI (proper DNF), countdown, save positions, restart, clear"""
    countdown = int(args[0]) if args else 10
    h, pid = open_proc()
    if not h:
        print(f"ERROR: {PROC_NAME} not found")
        return

    count = read_int(h, VEHICLE_COUNT)
    player = read_int(h, PLAYER_VEHICLE)
    laps = read_int(h, LAPS_ADDR)
    if laps <= 0 or laps > 200:
        laps = 10
    print(f"PID={pid}  Vehicles={count}  Laps={laps}")

    # Save positions and existing finish states
    saved_pos = {}
    saved_qual = {}
    saved_fs = {}
    saved_rc = {}
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh:
            continue
        saved_pos[i] = read_int(h, veh + RACE_POS)
        saved_qual[i] = read_int(h, veh + QUAL_POS)
        saved_fs[i] = read_int(h, veh + FINISH_STATE)
        saved_rc[i] = read_int(h, veh + REASON_CODE)

    # Phase 1: Retire all AI (proper DNF)
    print("\n=== PHASE 1: RED FLAG — retiring all AI ===")
    retired = 0
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh or veh == player:
            continue
        if saved_fs[i] != 0:
            continue  # already DNF/finished, skip
        write_int(h, veh + FINISH_STATE, 2)     # DNF
        write_int(h, veh + REASON_CODE, 6)      # puncture
        write_byte(h, veh + RETIRED_FLAG, 1)    # car to garage
        write_byte(h, veh + ACTIVE_FLAG, 0)     # driver removed
        name = read_string(h, veh + DRIVER_NAME) or "???"
        retired += 1
        print(f"  Retired [{i}] {name}")
    print(f"  {retired} cars retired")

    # Phase 2: Countdown
    print(f"\n=== PHASE 2: {countdown}s countdown ===")
    import winsound
    winsound.Beep(1200, 100)
    for sec in range(countdown, 0, -1):
        print(f"  T-{sec}")
        # Hold retirement flags each second
        for i in range(min(count, 26)):
            veh = read_int(h, VEHICLE_ARRAY + i * 4)
            if not veh or veh == player:
                continue
            if saved_fs[i] != 0:
                continue
            write_int(h, veh + FINISH_STATE, 2)
            write_byte(h, veh + RETIRED_FLAG, 1)
            write_byte(h, veh + ACTIVE_FLAG, 0)
        if sec <= 5:
            winsound.Beep(800, 80)
        time.sleep(1)

    # Phase 3: Swap DNF cars to end of array, reduce VehicleCount, restart
    # DynMan_Restart loops VehiclePtrArray[0..VehicleCount-1] calling
    # SceneRenderUpdate per slot. By moving DNFs past the count boundary,
    # they never get grid-placed.
    print("\n=== PHASE 3: hiding DNF cars from restart + setting grid order ===")

    # Identify DNF indices and build new array order: active cars first, DNFs last
    active_indices = []
    dnf_indices = []
    orig_ptrs = []
    for i in range(count):
        orig_ptrs.append(read_int(h, VEHICLE_ARRAY + i * 4))
    for i in range(min(count, 26)):
        if saved_fs.get(i, 0) != 0:
            dnf_indices.append(i)
        else:
            active_indices.append(i)

    if dnf_indices:
        # Build reordered array: active cars first, then DNFs
        new_order = active_indices + dnf_indices
        for new_slot, old_idx in enumerate(new_order):
            write_int(h, VEHICLE_ARRAY + new_slot * 4, orig_ptrs[old_idx])

        reduced_count = len(active_indices)
        write_int(h, VEHICLE_COUNT, reduced_count)
        print(f"  Moved {len(dnf_indices)} DNF cars past VehicleCount boundary ({count} -> {reduced_count})")
        for idx in dnf_indices:
            name = read_string(h, orig_ptrs[idx] + DRIVER_NAME) or "???"
            print(f"    DNF: [{idx}] {name}")

    # Set QualPos = saved race positions for ALL cars (including DNFs for consistency)
    print("  Setting grid order...")
    for orig_idx in range(min(count, 26)):
        veh = orig_ptrs[orig_idx] if dnf_indices else read_int(h, VEHICLE_ARRAY + orig_idx * 4)
        if not veh:
            continue
        pos = saved_pos.get(orig_idx, 0)
        if pos > 0:
            write_int(h, veh + QUAL_POS, pos)
            name = read_string(h, veh + DRIVER_NAME) or "???"
            print(f"  [{orig_idx}] {name}: QualPos = {pos}")

    write_int(h, LAPS_ADDR, laps)

    if dnf_indices:
        # Hold VehicleCount at reduced value in tight loop spanning restart.
        # Game_Restart subsystems may restore it; we overwrite every ms.
        import threading
        hold_count = [True]
        def hold_vehicle_count():
            while hold_count[0]:
                write_int(h, VEHICLE_COUNT, reduced_count)
                time.sleep(0.001)
        t = threading.Thread(target=hold_vehicle_count, daemon=True)
        t.start()
        print(f"  Holding VehicleCount={reduced_count} (background thread)")

    write_byte(h, RESTART_FLAG, 1)
    winsound.Beep(600, 300)
    print("  Restart triggered")

    # Phase 4: Wait for restart, then restore array + VehicleCount + re-retire DNFs
    print("\n=== PHASE 4: waiting for restart... ===")
    t0 = time.time()
    while time.time() - t0 < 15:
        gs = read_int(h, 0x007C569C)
        if gs == 5:
            print(f"  Restart state detected (gs=5) at {time.time()-t0:.1f}s")
            break
        time.sleep(0.1)

    # Keep holding for 2 more seconds to ensure DynMan_Restart loop is done
    time.sleep(2)

    if dnf_indices:
        hold_count[0] = False
        t.join()
        print(f"  Stopped holding VehicleCount")

        # Restore original pointer array and count
        for i in range(count):
            write_int(h, VEHICLE_ARRAY + i * 4, orig_ptrs[i])
        write_int(h, VEHICLE_COUNT, count)
        print(f"  Restored VehicleCount to {count} and original pointer order")

        # Re-retire DNF cars
        for idx in dnf_indices:
            veh = orig_ptrs[idx]
            write_int(h, veh + FINISH_STATE, saved_fs[idx])
            write_int(h, veh + REASON_CODE, saved_rc.get(idx, 0))
            write_byte(h, veh + RETIRED_FLAG, 1)
            write_byte(h, veh + ACTIVE_FLAG, 0)
            name = read_string(h, veh + DRIVER_NAME) or "???"
            print(f"  Re-retired [{idx}] {name} (FS={saved_fs[idx]}, Ret=1, Act=0)")

    print("  Verifying post-restart state...")
    for i in range(min(count, 26)):
        veh = read_int(h, VEHICLE_ARRAY + i * 4)
        if not veh:
            continue
        name = read_string(h, veh + DRIVER_NAME) or "???"
        qp = read_int(h, veh + QUAL_POS)
        rp = read_int(h, veh + RACE_POS)
        fs = read_int(h, veh + FINISH_STATE)
        rf = read_int(h, veh + RETIRED_FLAG) & 0xFF
        af = read_int(h, veh + ACTIVE_FLAG) & 0xFF
        print(f"  [{i:2}] {name:24} Q={qp:2} R={rp:2} FS={fs} Ret={rf} Act={af}")

    winsound.Beep(300, 300)
    print("\n=== DONE ===")
    ctypes.windll.kernel32.CloseHandle(h)

COMMANDS = {
    'monitor': (cmd_monitor, "<driver_idx> — live watch one driver's tire fields"),
    'puncture': (cmd_puncture, "<driver_idx> — inject on one driver with read-back"),
    'puncture-all': (cmd_puncture_all, "— inject punctures on ALL AI"),
    'retire-all': (cmd_retire_all, "— DSQ all AI (veh+0x4064=3)"),
    'restart': (cmd_restart, "— trigger mini-restart"),
    'redflag': (cmd_full_red_flag, "— full sequence: puncture->retire->restart"),
    'read': (cmd_read, "<addr> [float|int] — read any address"),
    'retire-test': (cmd_retire_test, "<idx> — test proper retirement (RetiredFlag+DNF)"),
    'retire-status': (cmd_retire_status, "— show retirement state for all vehicles"),
    'undo-retire': (cmd_undo_retire, "<idx> — undo retirement on one AI"),
    'pit-retire': (cmd_pit_retire, "<idx> — trigger natural pit retirement (PitState+AIMode)"),
    'redflag2': (cmd_redflag2, "[countdown_sec] — red flag v2: DNF retire + restart"),
}

def main():
    if len(sys.argv) < 2 or sys.argv[1] not in COMMANDS:
        print("Usage: python red_flag_poke.py <command> [args]")
        print()
        for name, (fn, help_txt) in sorted(COMMANDS.items()):
            print(f"  {name:18s} {help_txt}")
        print()
        print("Examples:")
        print("  python red_flag_poke.py monitor 0           # watch first AI driver")
        print("  python red_flag_poke.py puncture 0          # inject on first AI")
        print("  python red_flag_poke.py read 0x007D05A0     # read current lap count")
        sys.exit(1)

    cmd = sys.argv[1]
    args = sys.argv[2:]
    fn, _ = COMMANDS[cmd]
    fn(args)

if __name__ == '__main__':
    main()
