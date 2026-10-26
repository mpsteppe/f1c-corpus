# Red Flag v2 — Race Restart with DNF Exclusion

Injected DLL that simulates a red flag restart in F1 Challenge 99-02.
Press NUMPAD0 during a race to trigger a red flag sequence.

## What it does

1. **5-second countdown** with beeps each second
2. All AI cars retired (FinishState=2, SpeedCap=0.35 ~110 km/h)
3. Grid positions locked to race positions at time of red flag
4. Pre-existing DNF cars assigned QualPos=198 (wraps to underground track waypoint)
5. Restart triggered via `0x007CE25D = 1`
6. After restart completes (GameState=5), active cars restored, DNFs re-retired

## Status: IN PROGRESS — DNF car visibility not fully solved

**Core red flag sequence works.** Grid reorder, countdown, restart all confirmed.

**DNF car visibility problem:** DNF cars still appear on track after restart.
QualPos=198 puts them underground on SOME tracks but not all. Scene graph
detach (vehicle+0x39A0=0) leaves them in "weird position" — frozen at last
physics state but visible.

**Current approach (rf29s.dll, UNTESTED):** Hook `call SceneRenderUpdate` at
0x42C409 in `DynMan_Restart`. Trampoline checks vehicle pointer against DNF
list — DNF cars skip the call entirely so their model never gets rebuilt.
Hook installed BEFORE restart trigger, removed after phase 3.

Formation lap is NOT enabled; restart goes directly to standing start.

## Files

| File | Purpose |
|------|---------|
| `rf29.c` | Current source |
| `rf29s.dll` | Latest DLL — hook approach (UNTESTED) |
| `rf29r.dll` | Previous — scene graph detach (cars in weird position) |
| `rf29i.dll` | Older — QualPos=99 only (visible on long straights) |
| `inject.bat` | Injector (currently points to rf29s.dll) |
| `rf29_log.txt` | Runtime log output |
| `rf29[a-h,j-q].dll` | Experimental versions (can be deleted) |
| `trace_retirement.js` | Frida: polls all AI vehicles at 100Hz during retirement |
| `trace_restart.js` | Frida: 200Hz, 35+ offsets, watches one car through restart |

## Key offsets used

All offsets are vehicle-struct-relative unless noted.

| Offset | Name | Values |
|--------|------|--------|
| +0x001C | PhysX | Physics body X (NOT what you see on screen) |
| +0x0020 | PhysY | Physics body Y (height) |
| +0x0024 | PhysZ | Physics body Z |
| +0x34F0 | RenderX | Scene graph render X (what you see) |
| +0x34F4 | RenderY | Scene graph render Y |
| +0x34F8 | RenderZ | Scene graph render Z |
| +0x39A0 | SceneVisibility | Scene graph visibility flag (0=hidden by ConditionalGate) |
| +0x4040 | PitState | 1=normal, 2=pitting |
| +0x4058 | QualPos | Grid slot; 1-48 valid, 99=safe max, 0=crash, 100+=wraps |
| +0x4060 | RacePosition | Current race position |
| +0x4064 | FinishState | 0=running, 2=DNF, 3=DSQ |
| +0x4068 | ReasonCode | 6=puncture (used for red flag retirement) |
| +0x4410 | RetiredFlag | 1=car in pit garage |
| +0x45F4 | ActiveFlag | 1=active/racing, 0=inactive |
| +0x453C | SpeedCap | 1.0=normal, 0.35=~110 km/h slowdown |

Global addresses:

| Address | Name |
|---------|------|
| 0x005C329C | VehicleCount |
| 0x007C54F0 | VehiclePtrArray |
| 0x007C54E8 | PlayerVehiclePtr |
| 0x007CE25D | RestartTrigger (write 1 to restart) |
| 0x007D05A0 | TotalLaps |
| 0x007C569C | GameState (4=restart-in-progress, 5=formation/grid) |

## Physics vs Render position (CRITICAL DISCOVERY)

Physics position (+0x1C/20/24) and render position (+0x34F0/F4/F8) are
**independent**. Writing PhysY does NOT move the visible car. Render
position is updated by `AIVehiclePathPositionTracking` (0x4EF7C0) per-frame
during formation. During natural retirement, car disappears because
ActiveFlag=0 stops the scene graph from updating.

## Restart internals (Frida-confirmed)

1. GameState transitions: 7 (race) → 4 (restart prep) → 5 (formation)
2. At gs=4, ALL retirement state wiped in ONE tick: FinishState→0, ReasonCode→0, RetiredFlag→0, PitState→2
3. `DynMan_Restart` (0x42C3B0) loops VehiclePtrArray, calls `SceneRenderUpdate` (0x4C6D90) per vehicle
4. `SceneRenderUpdate` calls `VehicleRespawnReset` then `AIDriverStructInit` — rebuilds car model
5. Formation code overwrites car positions at ~60fps, winning any race condition with DLL writes

## Natural retirement sequence (Frida trace, Hakkinen crash Monza)

| Time | Field | Change |
|------|-------|--------|
| T+0.0s | ReasonCode | 0→6 |
| T+4.0s | ActiveFlag | 1→0 (visual kill switch) |
| T+10.2s | PhysZ, FinishState, RetiredFlag, RacePos | All set simultaneously |

ActiveFlag=0 is THE visual kill switch. No render position write needed.

## Hook mechanism (rf29s.dll)

- **Call site:** 0x42C409 = `E8 xx xx xx xx` (call SceneRenderUpdate) inside DynMan_Restart
- **Trampoline:** VirtualAlloc'd executable page with x86 machine code
- **Logic:** push eax/edx, loop g_dnf_ptrs comparing ecx (vehicle ptr), if match: ret 4 (skip), else: jmp SceneRenderUpdate
- **Install:** Before restart trigger (end of phase 1)
- **Remove:** After phase 3 completes (10s after restart)
- **Risk:** If trampoline has bugs, game crashes during restart. Previous test at QualPos=122 with hook active DID crash.

## QualPos exploration results

| QualPos | Result |
|---------|--------|
| 0 | Crash (array underflow) |
| 1-48 | Valid grid positions |
| 99 | Safe max (oph.dll). Car behind grid, visible on long straights. |
| 100 | Wraps around track waypoints, car shifted |
| 110 | Cars turned around, middle of track |
| 198 | Inconsistent: underground once, mid-road once, crash once |
| 500 | Wraps fully back to valid position (modulo waypoint count) |

## Failed approaches (14 total)

1. ActiveFlag=1 + coordinate teleport — formation overwrites position at 60fps
2. PitState=2 + AIMode=1 during formation — AI on rails, ignores pit commands
3. VehicleCount reduction — restart subsystems restore it
4. VehicleCount tight-loop hold at 1ms — still restored
5. SceneRenderUpdate hook (skip struct init) — car model still placed by formation code
6. Hook + position hold with ActiveFlag=1 — formation wins at 60fps vs 50ms writes
7. QualPos=0 — works but crashes (array underflow)
8. QualPos=32 — cars visible ~60m behind grid
9. QualPos=122 — crash (with hook active)
10. Underground teleport PhysY=-10000 with ActiveFlag=0 — physics != render
11. Underground teleport PhysY=-10000 with ActiveFlag=1+SpeedCap=0 — still no render sync
12. QualPos=198 render Y teleport (rf29p) — formation overwrites render Y every frame
13. ActiveFlag=0 hammering at 10ms for 10s (rf29q) — formation sets ActiveFlag=1 at 60fps, wins
14. Scene graph detach vehicle+0x39A0=0 (rf29r) — cars frozen in weird position, not hidden

## DNF detection

Checks BOTH `FinishState != 0` AND `RetiredFlag != 0` to catch cars mid-retirement
cascade (e.g. car driving to pit but not yet fully DNF'd).

## Build

```bash
i686-w64-mingw32-gcc -shared -O2 -o rf29s.dll rf29.c -lwinmm
```

## Usage

1. Start a race in F1 Challenge
2. Wait for a DNF or desired moment
3. Run `inject.bat`
4. Press NUMPAD0 to trigger red flag
5. Watch countdown, cars slow down, restart occurs
6. After restart, DNF cars should be invisible (if hook works)

## Next steps

1. **TEST rf29s.dll** — hook approach, never tested yet
2. If hook crashes: verify trampoline bytecode, check call convention (does SceneRenderUpdate use ecx as this? Does it have stack args?)
3. If hook works but cars still visible: hook timing may be wrong, SceneRenderUpdate may not be the only place models are rebuilt
4. Alternative approach: trace what EXACTLY the game does differently for naturally-retired cars vs DLL-retired cars during restart. Use trace_restart.js with a car that retired naturally BEFORE red flag, compare its offsets to a DLL-retired car.
5. Nuclear option: find the render loop's "should I draw this vehicle" check and patch it to skip DNF vehicles
