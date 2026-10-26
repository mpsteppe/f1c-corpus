#!/usr/bin/env python3
"""
live_audit.py — Read documented globals/offsets against live game process.
Reports PASS/FAIL/INFO for each claim. Run while in-game on track.
"""
import struct, ctypes, ctypes.wintypes, subprocess, sys

# ── process attach ─────────────────────────────────────────────────────────────
def find_pid():
    r = subprocess.run(
        ['tasklist','/FI','IMAGENAME eq F1 Challenge Online.exe','/FO','CSV','/NH'],
        capture_output=True, text=True)
    for line in r.stdout.splitlines():
        if 'F1 Challenge' in line:
            return int(line.split(',')[1].strip().strip('"'))
    return None

pid = find_pid()
if not pid:
    print("ERROR: F1 Challenge Online.exe not running"); sys.exit(1)

h = ctypes.windll.kernel32.OpenProcess(0x1F0FFF, False, pid)
if not h:
    print("ERROR: OpenProcess failed — run as admin"); sys.exit(1)

def rd4(addr):
    buf = ctypes.create_string_buffer(4); n = ctypes.c_size_t()
    ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), buf, 4, ctypes.byref(n))
    return buf.raw

def rdi(addr): return struct.unpack('<i', rd4(addr))[0]
def rdu(addr): return struct.unpack('<I', rd4(addr))[0]
def rdf(addr): return struct.unpack('<f', rd4(addr))[0]
def rds(addr, n=64):
    buf = ctypes.create_string_buffer(n); sz = ctypes.c_size_t()
    ctypes.windll.kernel32.ReadProcessMemory(h, ctypes.c_void_p(addr), buf, n, ctypes.byref(sz))
    return buf.raw.split(b'\x00')[0].decode('latin-1', errors='replace')

PASS = "PASS"; FAIL = "FAIL"; INFO = "INFO"; WARN = "WARN"

results = []

def check(name, addr, read_fn, doc_claim, validator=None, note=""):
    try:
        val = read_fn(addr)
        if validator:
            ok = validator(val)
            status = PASS if ok else FAIL
        else:
            status = INFO
        results.append((status, name, hex(addr), val, doc_claim, note))
    except Exception as e:
        results.append((FAIL, name, hex(addr), f"ERR:{e}", doc_claim, note))

# ── 1. Core session globals ────────────────────────────────────────────────────
check("SessionType",    0x007C56A4, rdi, "int32; 0=none 1=practice 2=qual 7=race",
      lambda v: v in range(0, 10), "key global")
check("GameState",      0x007D00EC, rdi, "int32; game state machine",
      lambda v: -1 < v < 100)
check("RaceActiveFlag", 0x007D0308, rdi, "int32; nonzero = race active",
      lambda v: v >= 0)
check("VehicleCount",   0x005C329C, rdi, "int32; 1–26 vehicles in session",
      lambda v: 0 <= v <= 26)

# ── 2. Player vehicle pointer ──────────────────────────────────────────────────
check("PlayerVehiclePtr", 0x007C54E8, rdu, "ptr; nonzero = player vehicle base",
      lambda v: v > 0x400000)

player_ptr = rdu(0x007C54E8)
vp_ok = player_ptr > 0x400000

# ── 3. Vehicle array ──────────────────────────────────────────────────────────
check("VehiclePtrArray[0]", 0x007C54F0, rdu, "ptr; first vehicle in array",
      lambda v: v > 0x400000 or v == 0)

# ── 4. Player vehicle struct fields (if ptr valid) ────────────────────────────
if vp_ok:
    p = player_ptr
    check("veh+0x4064 FinishState",  p+0x4064, rdi, "int32; 0=run 1=fin 2=DNF 3=DSQ",
          lambda v: v in (0,1,2,3))
    check("veh+0x4068 ReasonCode",   p+0x4068, rdi, "int32; 0=none 1=engine 2=gearbox 5=brakes 6=accident",
          lambda v: 0 <= v <= 9)
    check("veh+0x4028 (ctrl surface)", p+0x4028, rdf, "float; per-frame control input (NOT engine health)",
          lambda v: -2.0 <= v <= 2.0, "confirmed frame-written, not health")
    check("veh+0x3D64 WearAccum",    p+0x3D64, rdf, "float; tire wear accumulator, game-computed",
          lambda v: -1100.0 <= v <= 2.0)
    check("veh+0x3ab0",              p+0x3ab0, rdf, "float; unknown, changes while driving",
          None, "observed changing in burnout trace")
    check("veh+0x3abc",              p+0x3abc, rdf, "float; unknown, same pattern as 3ab0",
          None)

    # F1CUI claimed tire puncture offsets — now SUSPECTED WRONG
    check("veh+0xDF0 (F1CUI tirePuncture_FL?)", p+0xDF0, rdf,
          "double[0] F1CUI claims tirePuncture_FL — SUSPECT (caused camera shake)",
          lambda v: -1000.0 < v < 1000.0, "WARN: may be camera/control field")
    check("veh+0x0EE8 (F1CUI tirePuncture_FR?)", p+0xEE8, rdf,
          "F1CUI tirePuncture_FR — SUSPECT", None, "WARN")

    # Tire wear channels from docs/13 (suspect)
    check("veh+0x8CC TireWearCh0?", p+0x8CC, rdf,
          "docs/13: TireWearChannels[0] stride 0x128 — UNVERIFIED",
          None, "read as float4; may be wrong type/offset")
    check("veh+0x9F4 TireWearCh1?", p+0x9F4, rdf,
          "docs/13: TireWearChannels[1]", None)
    check("veh+0xB1C TireWearCh2?", p+0xB1C, rdf,
          "docs/13: TireWearChannels[2]", None)
    check("veh+0xC44 TireWearCh3?", p+0xC44, rdf,
          "docs/13: TireWearChannels[3]", None)

    # Tire sub-struct starts (F1CUI stride 0xF8 from base)
    check("veh+0x48b8 TireTemp?",   p+0x48b8, rdf,
          "docs/13: TireTemp/UnknownTime — UNVERIFIED", None)

# ── 5. Physics globals ─────────────────────────────────────────────────────────
check("TireWearMultiplier", 0x007D0C60, rdf, "float; global wear mult from .hdv",
      lambda v: 0.0 <= v <= 10.0)
check("flt_7CF3C8 RaceClock",  0x007CF3C8, rdf, "float; race elapsed time (>0 when racing)",
      lambda v: v >= 0.0)

# ── 6. Known string probes ─────────────────────────────────────────────────────
try:
    s = rds(0x5C316C, 16)
    ok = s == "Engine"
    results.append((PASS if ok else FAIL, "str@0x5C316C", "0x5c316c",
                    repr(s), '"Engine" (reason code name table)', ""))
except: pass
try:
    s = rds(0x5C3164, 16)
    ok = s == "Gearbox"
    results.append((PASS if ok else FAIL, "str@0x5C3164", "0x5c3164",
                    repr(s), '"Gearbox"', "ledger said code5=gearbox; IDA says code2=gearbox"))
except: pass

# ── print ──────────────────────────────────────────────────────────────────────
ctypes.windll.kernel32.CloseHandle(h)

W = 28
print(f"\n{'='*80}")
print(f"  F1C Live Audit  |  pid={pid}  |  PlayerVehiclePtr={hex(player_ptr)}")
print(f"{'='*80}")
print(f"{'STATUS':<6}  {'NAME':<38}  {'ADDR':<12}  {'VALUE'}")
print(f"{'-'*80}")

counts = {PASS:0, FAIL:0, INFO:0, WARN:0}
for status, name, addr, val, doc, note in results:
    tag = WARN if note.startswith("WARN") else status
    counts[tag] = counts.get(tag,0) + 1
    vstr = f"{val:.4f}" if isinstance(val, float) else str(val)
    print(f"{tag:<6}  {name:<38}  {addr:<12}  {vstr}")
    if note and not note.startswith("WARN"):
        print(f"         note: {note}")

print(f"\n{'-'*80}")
print(f"  PASS={counts[PASS]}  FAIL={counts[FAIL]}  WARN={counts[WARN]}  INFO={counts[INFO]}")
print()

# ── corrections log ────────────────────────────────────────────────────────────
failures = [(n,a,v,d,nt) for s,n,a,v,d,nt in results if s==FAIL]
if failures:
    print("CORRECTIONS NEEDED:")
    for n,a,v,d,nt in failures:
        print(f"  [{a}] {n}: got={v}, doc claimed: {d}")
