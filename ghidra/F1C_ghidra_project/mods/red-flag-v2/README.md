# red_flag_v2 — Red Flag Mod

Press NUMPAD0 in race: AI drivers receive tire punctures → pit → retire → player enters pits → mini-restart.

## Files

| File | Purpose |
|------|---------|
| `red_flag_poke.py` | Python live injector — WriteProcessMemory, no DLL needed |
| `red_flag_v2.c` | DLL version (compile with MinGW, inject with inject.exe) |
| `red_flag_v2.dll` | Compiled DLL |
| `monitor_puncture.py` | Older monitor script (use red_flag_poke.py instead) |
| `rf7.c` / `rf7.dll` | Earlier working prototype (NUMPAD0: slow+DSQ → restart) |
| `inject.bat` | Quick-launch for inject.exe |

## Quick Start (Python — no DLL)

```powershell
cd %USERPROFILE%\Desktop\f1c_ida_decompiled\mods\red_flag_v2
$py = "%USERPROFILE%\AppData\Local\Python\bin\python3.exe"

# Watch AI driver 1 live
& $py red_flag_poke.py monitor 1

# Inject puncture on driver 1
& $py red_flag_poke.py puncture 1

# Inject all AI
& $py red_flag_poke.py puncture-all

# Retire all AI (DSQ)
& $py red_flag_poke.py retire-all

# Full sequence: puncture-all → 5s wait → retire-all → wait pit → restart
& $py red_flag_poke.py redflag
```

## Memory Layout

### Driver block (per-slot, stride 0x48C0)
Base: `0x005F0DEC + slot * 0x48C0`

| Offset | Name | Type | Value |
|--------|------|------|-------|
| 3568 (0x0DF0) | tirePuncture_FL | float | 0.77f = punctured |
| 3816 (0x0EE8) | tirePuncture_FR | float | 0.77f = punctured |
| 4064 (0x0FE0) | tirePuncture_RL | float | 0.77f = punctured |
| 4312 (0x10D8) | tirePuncture_RR | float | 0.77f = punctured |
| 456 (0x01C8) | callToBox | int | 1 = called to box |
| 456 (0x0204) | driverStatus | int | status flag |
| 14180 (0x3764) | driverMemoryAddress | ptr | points to driver struct |

### Vehicle struct (per-vehicle, via VehiclePtrArray)
Array: `0x007C54F0` — array of vehicle pointers. `*(0x007C54F0 + slot*4)` = vehicle ptr.

| Offset | Name | Type | Value |
|--------|------|------|-------|
| 0x4620 | DriverName | char[64] | null-terminated name |
| 0x4064 | FinishState | int | 0=run 1=fin 2=DNF 3=DSQ |
| 0x4068 | ReasonCode | int | 5=gearbox failure |
| 0x0394 | wingDamage | float | 1.0=detached (overwritten every physics frame) |
| 0x453C | liveLapRatio | float | speed ratio, 0.1=slow |
| 0x32C8 | pitGate | int | >1 skips AI updates |

### Globals

| Address | Name | Type |
|---------|------|------|
| 0x005C329C | VehicleCount | int |
| 0x007C54E8 | PlayerVehiclePtr | ptr |
| 0x007CE25D | RestartFlag (mini) | byte |
| 0x007CE258 | PitEntryDetector | int |
| 0x007D05A0 | LapCount | int |
| 0x007C569C | GameState | int |

## What Works / What Doesn't

- **Tire puncture writes**: CONFIRMED — write 0.77f, read-back matches, persists (not frame-overwritten)
- **AI pit from puncture**: UNCONFIRMED — writes land, but in-game AI reaction not verified yet
- **F1CUI methodology**: `driverMemoryAddress - 4312` writes to RR tire. We use positive offsets from driver base since table documents them as `driverBase + 4312`.
- **callToBox / pittingStatus**: NOT USED by game code (no function writes/reads them for pit triggering)
- **veh+0x32C8=2**: Skips AI updates entirely (cars freeze)— do NOT use for pit behavior
- **veh+0x4064=1**: Pit request (game's own FUN_004beb10 writes this). Set to 3=DSQ for retirement.
- **veh+0x4040=2**: Pit lane state (used by cameras/UI)

## Build DLL

```powershell
& "C:\msys64\mingw32\bin\gcc.exe" -shared -o red_flag_v2.dll red_flag_v2.c -lkernel32 -O2
```

Inject:
```powershell
& "..\red-flag-dll\inject.exe" red_flag_v2.dll
```

## History

- `rf7.dll`: Phase1=slow+DSQ → Phase2=restart on pit entry → Phase3=clear. Working.
- `red_flag_v2.dll`: Original had wrong driver base (0x5F0DEC vs intended callToBox base), veh+0x32C8=2 killed AI. Multiple iterations.
- `red_flag_poke.py`: Python WriteProcessMemory approach — matches F1CUI methodology, much faster debug cycle.
