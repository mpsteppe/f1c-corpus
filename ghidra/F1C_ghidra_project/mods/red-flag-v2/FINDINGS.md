# Red Flag v2 — Phase 1 Static Findings

Static (.c FACT-tier) trace via IDA decompile (2026-07-21). IDA MCP at :13337, game not running.

## Restart call chain (game.cpp / steward.cpp) — CORRECTED via IDA decompile

| Fn | Addr | Role |
|----|------|------|
| `GameMainEntry` | `0x0045b200` | **WinMain → main loop.** Calls `Game_Enter` → `Game_Setup` → `Game_Init` → `while(!Game_Restart) { GamePostMainLoop ... }`. When PostMainLoop returns 1: `Game_Post` → `Game_Setup` → goto `Game_Init`. |
| `GamePostMainLoop` | `0x0042d8a0` | **Per-frame pump.** Sets `*this=5`. Calls `sub_4A0FD0` each frame; when it returns ≠5, breaks loop. Returns 1 → restart chain. Returns 0 → keep running. |
| `sub_4A0FD0` | `0x004A0FD0` | **Options/menu state poller (the restart gate).** Returns `dword_7C569C` (normally 5). Returns 6 when restart requested. Read each frame by GamePostMainLoop. |
| `Game_Restart` | `0x0042d7a0` | **`__fastcall(Game* this)`.** Sets `*this=4`, runs full restart: 15 subsystem restarts (Sound, Steward, SpecialFX, HWInput, DynMan, CamMan, Render, OnScreen, VidMan, PlayerFile, HUD). Returns 0 (always). |
| `Steward_Restart` | `0x004d3cf0` | **`__fastcall(steward* this)`.** Case 7 (race): `this+0xAC = dword_7D05A0` (race lap count), `this+0x11C = dword_7D0894`. Fires `PreRacePresentation` state machine. |
| `Game_Init` | `0x0042d6b0` | Sets `*this=3`. Full init: Steward_Init, HWInput_Init, SpecialFX_Init, DynMan_Init, CamMan_Init, Sound_Init, Render_Init, OnScreen_Init, etc. NOT a gate — this is the init step. |
| `Game_Setup` | `0x0042d5d0` | Sets `*this=2`. Setup step: HWInput_Setup, Options_Setup, Steward_Setup, etc. |
| `Game_Enter` | `0x0042d370` | Sets `*this=1`. Enter step: OSMan_Enter, VidMan_Enter, Sound_Enter, file loading. |
| `NetComm slot load` | `0x0045fc50` | Reads `VehicleGridArray` (`0x005ef9a0`, stride `0x1230`, slot-indexed via veh `+0x40`, `-1`=empty). Grid placement. |

## [FACT] Restart-request flags — LOCATED + POKE-PROVED

`sub_4A0FD0` (0x4A0FD0) is the restart gate, polled each frame by `GamePostMainLoop`.
Four restart paths, returns 4/5/6 → `GamePostMainLoop` acts accordingly.

### Path 1: Mini-restart (byte_7CE25D) — POKE-PROVED, WORKS

`byte_7CE25D` at **`0x007CE25D`** — write `1` → `sub_4A0FD0` returns 4 →
`GamePostMainLoop` returns 0 → while-loop continues, `Game_Restart` fires next iteration
(state 4 cleanup, 15 subsystem restarts, then back to state 5 race). Game continues normally.

**Poke-proved 2026-07-21:** Flag consumed (1→0), state 5→4→5. User confirmed in-game:
race restarts successfully, no crash. This is the path to use for red flag mod.

### Path 2: Full restart chain (byte_7CE25E) — POKE-PROVED, CRASHES

`byte_7CE25E` at **`0x007CE25E`** — write `1` → `sub_4A0FD0` returns 6 →
`GamePostMainLoop` returns 1 → GameMainEntry calls `Game_Post` → `Game_Setup` (state 2)
→ `Game_Init` (state 3) → back to while-loop. Full re-init.

**Poke-proved 2026-07-21:** Flag consumed, state 5→6→2 confirmed. Game transitions to
Setup/pit-garage screen. **Crashes when user presses Race** — full chain skips
`Game_Restart` state-4 cleanup, leaving internal state broken.

Set by:
- `sub_4A0DB0` (0x4A0DB0): `byte_7CE25E = 1` — called by `SessionScoringUpdate` when race-end timer expires
- `SetRaceStateFlag` (0x4A0DE8): Same one-byte write, zero callers (likely dead / vtable path)

### Path 3: Pit-driven (dword_7CE264 + dword_7CE258)

`dword_7CE264` at **`0x007CE264`** must be `1` AND `dword_7CE258` at **`0x007CE258`** must be `1`.
When both true: `sub_4A0FD0` returns 6 → restart (same chain as Path 2, same crash risk).

- `dword_7CE258` is set to `1` by `PitStateUpdateMachine` (0x4A6E50) when vehicle state==2 + proximity detected + player not DNF — i.e., player enters pits.
- `dword_7CE264` normally `0`; set to `2` by command-line `-skipoptions`. Must be explicitly set to `1` for this path.

### Path 4: Hotkey/menu (Y-press)

When `byte_7CE254 == 1` (paused): `sub_485B90` processes input → returns 3 → return 6.
When `byte_7CE254 == 0`: `word_7CB21C` hotkey table checked → sets `dword_7C569C = 6`,
calls `MainMenuTransition`. Same full restart chain as Path 2.
**Live trace confirmed:** Y-press triggered `ScoringGateCheck` + state 5→4→5 (Path 1 mini-restart), not the full chain.

## [FACT] Restart gate (sub_4A0FD0) return values

| Return | Condition | Effect |
|--------|-----------|--------|
| 4 | `byte_7CE25D == 1` | Mini-restart: `Game_Restart` cleanup, continue race |
| 5 | Normal | Keep running |
| 6 | `byte_7CE25E == 1` or hotkey | Full chain: `Game_Post→Setup→Init`, **crashes** |

## [FACT] Game* base

`dword_7C569C` at **`0x007C569C`** — the Game object. All Game methods receive `&dword_7C569C` as `this`.

Game state machine (Game+0 = state):
| Value | State | Function |
|-------|-------|----------|
| 1 | Enter | `Game_Enter` (0x42d370) |
| 2 | Setup | `Game_Setup` (0x42d5d0) |
| 3 | Init | `Game_Init` (0x42d6b0) |
| 4 | Restart | `Game_Restart` (0x42d7a0) |
| 5 | Running | `GamePostMainLoop` (0x42d8a0) |

## Lap count — CONFIRMED via IDA

`DAT_007d05a0` at **`0x007D05A0`** confirmed in `Steward_Restart` case 7:
```c
*(_DWORD *)(this + 0xAC) = dword_7D05A0;  // steward+0xAC = race lap count
*(_DWORD *)(this + 0x11C) = dword_7D0894;
StateMachineInitializer(this, "PreRacePresentation");
```

Write `DAT_007d05a0` before triggering restart to set remaining laps.

## Grid order

- `VehicleGridArray` `0x005ef9a0`, stride `0x1230`, indexed by vehicle slot id (`veh+0x40`), `-1` = empty. Team/slot-indexed — may not map 1:1 to finishing order (risk noted in plan).

## [CRITICAL BUG] AI retire: FinishState=2 does NOT stop AI driving

### Root cause (2026-07-21, Opus trace of raw .c FACT-tier source)

`VehicleControlEnabled` at **`0x004a6db0`** is the gate that decides whether an AI car
keeps driving each tick. The decisive check (line 25 of source):

```c
if (FinishState != 1 && FinishState != 3)  // keep driving
    → calls FUN_004d21d0 (RacePhase check) → returns true = vehicle active
```

**FinishState=2 (DNF) is NOT in the disable condition.** The game only stops AI driving
for values 1 (finished) and 3 (DSQ). Writing `veh+0x4064 = 2` lands in memory but the
AI tick loop ignores it — car keeps driving normally.

This explains why `ai_pit_retire` logs showed "retired 21 AI cars" but nothing happened
in-game: the writes landed, but the game never checked for value 2.

### Fix

Write **`veh+0x4064 = 3`** (DSQ) instead of `2` (DNF). Value 3 hits the disable check
in VehicleControlEnabled → AI car stops driving immediately.

If final results should show DNF (not DSQ): write `3` first to stop driving, then after
the mini-restart flip to `2` for display purposes.

### Source evidence

File: `analysis_pipeline/analyzed/0x004a6db0__FUN_004a6db0.c`
```c
bool __fastcall FUN_004a6db0(int *param_1)
{
  // ... suspension/tire checks (0x834, 0x874, 0x95c, etc.) ...
  
  if (((DAT_007ce814 != 0) || (!bVar2)) &&
     ((*(int *)(iVar1 + 0x4064) != 1 && (*(int *)(iVar1 + 0x4064) != 3)))) {
    cVar3 = FUN_004d21d0();        // RacePhase >= 5 check
    return cVar3 != '\0';          // true = vehicle keeps driving
  }
  return false;                    // FinishState 1 or 3 → stop driving
}
```

Also: no function in the entire binary writes `veh+0x4064 = 2`. The game only ever
writes values 0 (reset) and 1 (finished). Value 2 (DNF) appears to be set only by
the scoring/results system after a race ends, not during active racing.

## Next live steps (need game in race)

1. ~~**Poke-prove the fix:** write `veh+0x4064 = 3` on one AI car → confirm it stops driving~~ **DONE** — DSQ does NOT stop AI. See error below.
2. ~~Poke-prove: write `DAT_007d05a0 = N` → observe lap count honored on restart~~ **DONE** — works
3. ~~Build rf6.c with FinishState=3 fix~~ **DONE** — rf7.c is current working version
4. ~~Test full red flag sequence: hotkey → AI stops → mini-restart~~ **DONE** — rf7.dll works

## [ERROR] VehicleControlEnabled analysis was wrong

The other LLM's claim that `VehicleControlEnabled` at 0x4A6DB0 controls whether AI
keeps driving is **wrong** for the main AI loop.

`VehicleControlEnabled` is called only by:
- `AIStateMachineWithModeDispatch` (0x4A5D10) — red flag state handler
- `PitStateUpdateMachine` (0x4A6E50) — pit state machine

It is **NOT called by AIMainUpdate** (0x424E70), which is the per-frame AI driver.
The main AI loop only checks `veh+0x32C8 > 1` to skip AI updates.

**Actual behavior:** write `veh+0x4064 = 3` (DSQ) → car slows to ~43kmh crawl but
keeps driving. Black flag is shown but car remains on track.

## Working rf7.dll — 3-phase red flag

`mods/red_flag_v2/rf7.dll` — inject with `mods/red-flag-dll/inject.exe`
- **NUMPAD0** to trigger in race
- Phase 1 (5s): write DSQ + slow to all AI every 50ms. High beep.
- Phase 2: set laps=10, trigger mini-restart (0x007CE25D=1). Low beep.
- Phase 3 (3s): re-apply DSQ after restart. Long beep when done.
- Log: rf7_log.txt next to DLL

## Pending features

- **Grid position ordering:** Read live positions from driver block (+0x06B4),
  reorder grid array (0x5EF9A0, stride 0x48C0) before restart. Grid entry +0x00 = -1
  to leave slot empty. **Grid writes during race CRASH game** — need to find
  safe write window.
- **Vehicle count:** Reduce by DNF count
- **Pit garage:** `driverStatus` at driver+0x0204 (float values, need decoding)

## Player pit detection — resolved

**`dword_7CE258` at `0x007CE258`** is the pit entry trigger. Set to 1 by:
- `PitStateUpdateMachine` (0x4A6E50) — AI pit entry
- `sub_4F1FE0` (0x4F222F) — player pit entry path

Detects when vehicle physically crosses pit lane entry line. Only works in SessionType==7
(race). Does NOT trigger in practice/test day (SessionType==0).

**Pit request (ENTER key):** Does NOT set any vehicle/driver memory field.
Audio 0x002A (PWS_CHANGEPIT01) plays but not through commentary queue.
No memory-observable side effect.

## Pit state: veh+0x4040 (pitSubst+20)

| Value | Meaning |
|-------|---------|
| 0 | Player (never changes) |
| 1 | AI normal racing |
| 2 | AI in pit lane (observed on Raikkonen retirement) |

## Wing damage: veh+0x0394

Float 0.0-1.0. Raikkonen had 0.88 → AI auto-pit order.
Overwritten every frame by `VehicleDynamicsForceAccumulatorIntegration` (0x438130).
Must persist via tick-loop.

## Audio events

| ID | Name | Use |
|----|------|-----|
| 0x0083 | PWS_RED01.mp2 | "Session red flagged" |
| 0x002A | PWS_CHANGEPIT01 | "Pit request acknowledged" |

Controller base: `0x005EA618`. Queue: `+0x864`. Event table: `0x005BF9A0`.

## 2026-07-21: Python WriteProcessMemory approach (red_flag_poke.py)

### Tire puncture offsets — CONFIRMED WORKING (write + read-back)

Using F1CUI table offsets (doc/26) as POSITIVE from driver block base `0x005F0DEC`:

| Tire | Offset from `0x5F0DEC + i*0x48C0` | Read-back confirmed |
|------|------|-----|
| FL   | +3568 (0x0DF0) | yes, 0.77f persists |
| FR   | +3816 (0x0EE8) | yes, 0.77f persists |
| RL   | +4064 (0x0FE0) | yes, 0.77f persists |
| RR   | +4312 (0x10D8) | yes, 0.77f persists |

**Key finding:** These are POSITIVE offsets from driver block, not negative (F1CUI formula `driverMemoryAddress - 4312` gives different address — `driverMemoryAddress` at `driver+0x3764` may resolve to different pointer).

Tire puncture values PERSIST — game does NOT overwrite them each frame (unlike wing damage at `veh+0x0394`).

### Driver name: `veh+0x4620` — CONFIRMED

Reading from vehicle struct at `VehiclePtrArray[slot] + 0x4620` returns correct driver name (e.g. "Michael Schumacher (2001)", "Matias").

### Vehicle pointer array: `0x007C54F0` — CONFIRMED

`*(0x007C54F0 + slot*4)` = vehicle pointer. Slot 0 = player.

### AI pit reaction from puncture: UNCONFIRMED

Writes land at correct offsets with 0.77f but in-game AI pit response not yet verified.
