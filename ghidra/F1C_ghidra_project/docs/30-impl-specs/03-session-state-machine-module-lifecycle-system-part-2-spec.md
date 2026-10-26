# Implementation Spec: Session State Machine & Module Lifecycle System (Part 2)

Source: docs/01-engine-architecture.md  |  Functions: ~416 (documented)  |  Date: 2026-07-15

---

## Overview

The engine architecture system manages the game's session lifecycle — a deterministic state machine (states 1-7) that controls initialization, restart, per-frame update, and teardown of all game subsystems. It lives primarily in `game.cpp` with supplementary modules in `dynman.cpp`, `sound.cpp`, `onscreen.cpp`, `hwinput.cpp`, `vidman.cpp`, `render.cpp`, `camera.cpp`, and `osman.cpp`.

The system runs on three timescales:
- **Init (one-shot):** Each module has Enter → Setup → Init phases called during game startup (state 1-3).
- **Per-frame (game loop):** Game::Post() (state 5) drives physics, AI, steward, input, render, and audio every frame.
- **On-event (session transitions):** Restart (state 4) resets all subsystems; Post-session (state 6) triggers cleanup; Exit (state 7) full teardown.

**Data structures owned:**
- Game object (param_1) — state field at [0] mirrored to DAT_007d00ec
- Vehicle dynamics array at DAT_005ef9a0 (stride 0x1230, max 104 entries)
- Scene array at DAT_008ac490 (stride 0x18c)
- Camera struct per CamMan (3 camera object slots + flag + index)
- Render state array (0x1a dwords)

**External interfaces:**
- Physics (docs/10, 18): called per-frame via FUN_004f9f00, FUN_004b3b40
- AI (docs/02): called per-frame via FUN_00404460
- Steward/penalties (docs/06): called per-frame via FUN_004d4580
- Video manager calls FUN_0053d400 (display mode), FUN_0054a1c0 (render state)
- Sound manager calls FUN_004c7ca0 (sound hardware init)
- Input manager calls DirectInput8Create, FUN_0044f4e0 (cursor), FUN_00455290 (control bindings)

---

## Data Structures

### GameStateMachine (param_1 — game object)
```
Offset  Field           Type    Notes
+0x00   State           int     Mirrored to DAT_007d00ec (1-7)
+0x20   Condition       int     State transition condition (1=continue, 4=exit, 5=proceed)
```

Total size: unknown (larger object, ~0x5c0+ bytes based on param_1 offsets used in state functions)

### CamManStruct (param_1 — camera manager)
```
+0x00   MAINVIEW scene node  ptr     Camera system root
+0x08   CurrentCamera        ptr     Set to 0 in Post
+0x18   CameraObj1           ptr     Released via vtable in Post
+0x1c   CameraObj2           ptr     Released via vtable in Post
+0x20   CameraObj3           ptr     Released via vtable in Post
+0x2e   Flag                 byte    Reset to 0 in Restart/Post
+0x38   CameraIndex          int     Set to -1 (none) in Restart
```

### RenderStateArray (param_1 — render context)
```
+0x00   RenderState[26]     int[26] 0x68 bytes filled with 0x01010101 on Restart
```

### DynManStruct (param_1 — dynamics manager)
```
+0x00   StateCounters       int[2]  Zeroed in Restart (DAT_007c5694/5698)
```

### HWInputStruct (param_1 — hardware input, size ~0x2428+)
```
+0x1f98 InputDeviceArray   byte[0x21][0xb]  Controller detection array
+0x2428 DeviceDetected     byte    0 or 1, set during Restart
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007d00ec | int | GameState | Current game state (1-7) — written by state machine functions |
| DAT_007c56b0 | float | VersionFloat | Set to ~1.025 in Game::Main |
| DAT_007c56b4 | char[16] | VersionString | "ilya! _1011" watermark |
| DAT_007c56ad | byte | Flag | Cleared in Game::Main |
| DAT_007c56a0 | int | SessionMode | Set to 3 in Game::Main |
| DAT_007ce2a0 | ptr | AppInstanceHandle | Application handle stored in Game::Main |
| DAT_007c5694 | int | DynManCounter1 | Zeroed in DynMan::Restart |
| DAT_007c5698 | int | DynManCounter2 | Zeroed in DynMan::Restart |
| DAT_007c5690 | int | InitStateFlag | Set to 1 in Options::Setup special mode |
| DAT_007ce250 | int | FrameCounter | Incremented in Options menu loop |
| DAT_007ce25c | int | ExitFlag | Exit signal in Options menu |
| DAT_007ce260 | int | OptionsModeFlag | Guards options menu entry |
| DAT_007ce264 | int | OptionsSubMode | Sub-mode selector for options |
| DAT_005ccfe4 | int | OptionsSubFlag | Sub-mode exit flag |
| DAT_007ce2d8 | ptr | AppMutexHandle | Created by OSMan::Enter (CreateMutexA) |
| DAT_007d13a0 | int | InputModeFlag | 1 = use input device (HWInput) |
| DAT_007d1ffc | int | AudioQualityLevel | Input restart check (HWInput) |
| DAT_007ce2dc | ptr | DirectInputDevice | DirectInput device pointer |
| DAT_005ec4a4 | char[] | InputConfigPath | Input config file path |
| DAT_007ce2a0 | ptr | DirectInputInstance | DirectInput instance handle |
| DAT_005ef9a0 | int[] | VehicleGridArray | Vehicle dynamics array, stride 0x1230, max 104 |
| DAT_008afe70 | int | VidManState | Set to 0 in VidMan::Init |
| DAT_008afe74 | int | VidManConfig | Video manager config |
| DAT_008afe64 | ptr | DisplayDeviceHandle | Released in VidMan::Exit |
| DAT_008afe88 | ptr | SceneHandle | Scene handle, zeroed in Post |
| DAT_008afea8 | double | VidManTimerA | Reset in VidMan::Restart |
| DAT_008afeac | double | VidManTimerB | Reset in VidMan::Restart |
| DAT_008afe84 | int | VidManFlag | Reset in VidMan::Restart |
| DAT_005ea500 | int | CameraGlobal1 | Zeroed in CamMan::Init |
| DAT_005ea504 | int | CameraGlobal2 | Zeroed in CamMan::Init |
| DAT_005ea508 | int | CameraGlobal3 | Zeroed in CamMan::Init |
| DAT_005ea550 | int | CameraGlobal4 | Zeroed in CamMan::Init |
| DAT_005ea554 | int | CameraGlobal5 | Zeroed in CamMan::Init |
| DAT_005ea558 | int | CameraGlobal6 | Zeroed in CamMan::Init |
| DAT_007cf65c | int | DisplayMode | Display mode configuration |
| DAT_007cfb90 | int | RenderMode | Render mode (1/2/3) |
| DAT_007cfbfc | int | DisplayWidth | Screen width |
| DAT_007cfc20 | int | DisplayHeight | Screen height |
| DAT_007d032c | int | DisplayFormat | Display pixel format |
| DAT_007ce5d0 | char[] | SceneFilePath | Current scene file path |

---

## Public API — Entry Points

### Game::Main Entry — FUN_0045B200

**Inferred signature:** `int GameMain(int param_1)`
**Called from:** WinMain / CRT startup — one-shot at application launch
**Called by (from callers.json):** Not called from within game code (top-level entry point)

**What it does:**
1. Sets globals: DAT_007c56b0 = 1.025f, DAT_007c56b4 = "ilya! _1011", DAT_007c56ad = 0, DAT_007c56a0 = 3
2. Stores param_1 (HINSTANCE) in DAT_007ce2a0
3. Calls initializers in sequence:
   - FUN_00423070 — config/cmdline parsing
   - FUN_00421cd0 — config.ini loader
   - FUN_004d7a00 — session/race init
   - FUN_004a0d50 — UI init
   - FUN_004b17f0 — networking init
   - FUN_00463160 — NetComm cmdline
4. Enters game state machine loop:
   - FUN_0042d370 (Game::Enter, state 1)
   - FUN_0042d5d0 (Game::Setup, state 2)
   - Loop: FUN_0042d6b0 (Init, state 3) → FUN_0042d7a0 (Restart, state 4) → FUN_0042d8a0 (Post loop, state 5) → FUN_0042da30 (Post cleanup, state 6) → back to Setup
5. On exit: calls FUN_0042db20 (Game::Exit, state 7)

**Side effects:**
- Writes: Version globals, AppInstanceHandle
- Drives entire game lifecycle

---

### Game::Enter — FUN_0042D370

**Inferred signature:** `int GameEnter(GameObject* this)`
**Called from:** Game::Main — state machine state 1
**Called by:** FUN_0045b200

**What it does:**
1. Sets `this[0] = 1` (state 1)
2. Loads season .gdb file (default F1_2002.gdb)
3. Scans `*.rcd` and `*.pit` files from SeasonDir (DAT_005ec3d8)
4. Calls: FUN_004c8a20 (track loader), FUN_00455bf0 (player loader), FUN_004b0170, FUN_0049ef40, FUN_00463e20

**Side effects:**
- Loads game database files
- Initializes track, player, and sound subsystems at entry level

---

### Game::Setup — FUN_0042D5D0

**Inferred signature:** `int GameSetup(GameObject* this)`
**Called from:** Game state machine state 2
**Called by:** FUN_0045b200

**What it does:**
1. Sets `this[0] = 2`
2. Gate: if FUN_004a0eb0 (steward init) returns nonzero → abort (return 1)
3. Calls subsystem setups in order: HWInput::Setup, Sound::Setup, OnScreen::Setup, VidMan::Setup
4. Gate: if FUN_004b1870 (replay/Bink) returns nonzero → abort (return 1)
5. Calls: SpecialFX::Setup, sound (FUN_004d36d0), game (FUN_0042c170), FUN_00463ef0

**Side effects:**
- Initializes all major game subsystems
- Abort returns 1 if steward init or replay setup fails

---

### Game::Init — FUN_0042D6B0

**Inferred signature:** `int GameInit(GameObject* this)`
**Called from:** Game state machine state 3
**Called by:** FUN_0045b200

**What it does:**
1. Sets `this[0] = 3`
2. Calls FUN_004ba1f0 (replay/load state init)
3. Calls FUN_004fa320 (VidMan::Init) — if non-zero, abort (return 1)
4. Calls all subsystem inits in sequence:
   - Sound::Init, physics init, file paths, timers, HWInput::Init
   - Special effects, game state (DynMan::Init), CamMan::Init, OnScreen::Init
   - Render::Init, pit UI, HUD/menu init
5. Returns 0

**Side effects:**
- Full initialization of renderer, physics, AI, input
- VidMan::Init failure causes abort with return 1

---

### Game::Restart — FUN_0042D7A0

**Inferred signature:** `int GameRestart(GameObject* this)`
**Called from:** Game state machine state 4
**Called by:** FUN_0045b200 (loop)

**What it does:**
1. Sets `this[0] = 4`
2. Calls 19 subsystem restart/init functions:
   - NetComm (FUN_00464290), Sound::Restart, Steward, RaceTimer
   - Session, HWInput::Restart, CamMan::Restart, Render::Restart
   - OnScreen::Restart, replay, VidMan::Restart, OSMan
3. Returns 0

**Side effects:**
- Full subsystem restart — all modules get their state reset

---

### Game::Post (Main Loop) — FUN_0042D8A0

**Inferred signature:** `int GamePost(GameObject* this)`
**Called from:** Game state machine state 5 — called every frame
**Called by:** FUN_0045b200 (main loop)

**What it does:**
Each iteration:
1. FUN_004f9f00 — physics update
2. FUN_00461cd0 — state check:
   - 1 = continue
   - 4 = exit
   - 5 = proceed to next state
   - 6 = error
3. FUN_004ba180, FUN_00463ca0 — timing updates
4. FUN_004b3b40 — vehicle update
5. FUN_00404460 — AI update
6. FUN_004d4580 — steward update (penalties, flags)
7. FUN_00455e50, FUN_0042c690 — player/input update
8. FUN_004b3ba0, FUN_004643c0, FUN_00463cd0 — scene/render update
9. FUN_004ba6c0 — timing/scoring
10. If continuing (state==1): FUN_0040ca30, FUN_004cfcc0, FUN_004b40a0, FUN_0049f070
11. FUN_004f9f30, FUN_004c8b70, FUN_004fa7e0, FUN_004fcee0, FUN_004a1830 — post-frame

**Side effects:**
- Drives all per-frame game logic: physics, AI, steward, rendering, audio

---

### Game::Post (Post-Session Cleanup) — FUN_0042DA30

**Inferred signature:** `int GamePostSession(GameObject* this)`
**Called from:** Game state machine state 6

**What it does:**
- Sets DAT_007c56a0 = 3 (session type → Practice3)
- Calls steward cleanup (FUN_004d4600)
- Calls results processing (FUN_004bdde0, FUN_004ba740)

**Side effects:**
- Cleans up session state, processes race results

---

### Game::Exit — FUN_0042DB20

**Inferred signature:** `int GameExit(GameObject* this)`
**Called from:** Game state machine state 7

**What it does:**
1. Sets `this[0] = 7`
2. Calls full teardown sequence:
   - Sound::Exit, render shutdown, string cleanup (×2)
   - HWInput::Exit, game vars cleanup, OnScreen::Exit
   - VidMan::Exit, UI manager, game state machine, session cleanup

**Side effects:**
- Full resource deallocation

---

### DynMan::Restart — FUN_0042C3B0

**Inferred signature:** `void DynManRestart(DynManStruct* this)`
**Called from:** Game lifecycle — during state machine transition

**What it does:**
1. Zeroes DynMan counters at DAT_007c5694/5698
2. Calls FUN_004333e0 (AI settings reload)
3. Iterates all vehicles (DAT_005c329c count), calls FUN_004c6d90 per vehicle
4. Calls FUN_00410890 (post-processing)
5. Copies player index: DAT_007c54dc = DAT_007c54e4; DAT_007c54e0 = VehiclePtrArray[DAT_007c54e4]

**Side effects:**
- Refreshes AI settings and all vehicle state

---

### DynMan::Init — FUN_0042C1A0

**Inferred signature:** `void DynManInit(DynManStruct* this)`
**Called from:** Game state machine Init phase

**What it does:**
1. Iterates VehicleGridArray (DAT_005ef9a0, stride 0x1230, max 104)
2. If RaceMode != 4 (championship): sets grid entry at +0x364 to slot index+1
3. Branches on InitStateFlag (DAT_007c5690):
   - If 0: loads config via FUN_004b1520, then race or practice init path
   - If 1 and RaceMode==4 and SessionType 1-4 (practice): calls grid setup
4. Iterates VehicleCount calling FUN_004c6c40 per vehicle
5. If CurrentVehicleIndex valid (0-0x67): calls FUN_004336f0

**Globals:** DAT_007d0410 (RaceMode), DAT_007c56a4 (SessionType), DAT_007c5690 (InitStateFlag), DAT_005c329c (VehicleCount), DAT_007c54e4 (CurrentVehicleIndex), DAT_005ef9a0 (VehicleGridArray)

---

### DynMan::Post — FUN_0042C9F0

**Inferred signature:** `void DynManPost(DynManStruct* this)`
**Called from:** Game Post phase

**What it does:**
1. Iterates all vehicles (VehicleCount) calling FUN_004c6e80 per vehicle
2. Calls FUN_0043e230, FUN_0042bd60, FUN_0040fb30

---

### Main Game Tick — FUN_0042C690

**Inferred signature:** `void GameTick(GameObject* this)`
**Called from:** Game::Post per-frame update

**What it does:**
- Gate: ScoringGate != 2
- Computes target tick time, caps at 0xC9 ticks
- Loop: every 10 ticks runs AI per vehicle, repair, physics
- Every 400 ticks: AI update on human vehicles
- Every 50 ticks: vehicle tick, safety checks
- If player AIState==0: calls FUN_004bccc0 (player input)
- If DAT_007cbf24 != 0: calls FUN_00451720

**Side effects:** Drives per-tick AI, repair, physics updates

---

### OSMan::Enter — FUN_004A18D0

**Inferred signature:** `int OSManEnter(ptr this)`
**Called from:** Game lifecycle (one-shot at startup)

**What it does:**
1. Creates mutex named "F1 Challenge 99-02_APP_MUTEX" via CreateMutexA
2. If GetLastError == ERROR_ALREADY_EXISTS: return 1 (another instance running)
3. Stores handle in DAT_007ce2d8, returns 0

---

### VidMan::Enter — FUN_004FA000

**Inferred signature:** `int VidManEnter(ptr this)`
**Called from:** Game lifecycle

**What it does:**
1. Starts timer via FUN_00568be0(1)
2. Tests Direct3D device; if fails, return 1
3. Reads device name from player file; if no device, copies "No Device"
4. Compares device name with current device:
   - On match: calls render init chain
   - On mismatch: launches 3DCONFIG.EXE via CreateProcessA, returns 1

---

### VidMan::Init — FUN_004FA320

**Inferred signature:** `int VidManInit(ptr this)`
**Called from:** Game::Init (state 3)

**What it does:**
1. Sets DAT_008afe70 = 0
2. Configures display mode from DAT_007cf65c, resolution from DAT_007cfbfc/DAT_007cfc20
3. Branches on DAT_007cfb90 (render mode 1/2/3) → sets D3D render states
4. Resolves scene file path from SceneArray, strips directory
5. Loads scene via FUN_0053c800, season path from SeasonDir + SeasonName
6. Calls scene init; if 0 → loads placeholder scene, returns 0

---

## Internal Call Graph

```
GameMain (FUN_0045b200)
  +-- FUN_00423070 — Config/cmdline parse
  +-- FUN_00421cd0 — Config.ini loader
  +-- FUN_004d7a00 — Session/race init
  +-- FUN_004a0d50 — UI init
  +-- FUN_004b17f0 — Networking init
  +-- FUN_00463160 — NetComm cmdline
  +-- State Machine Loop:
        +-- Game::Enter (FUN_0042D370) [state 1]
        |     +-- FUN_004c8a20 — track loader
        |     +-- FUN_00455bf0 — player loader
        +-- Game::Setup (FUN_0042D5D0) [state 2]
        |     +-- FUN_004a0eb0 — steward init (gate)
        |     +-- FUN_00455c60 — HWInput::Setup
        |     +-- FUN_004c8ab0 — Sound::Setup
        |     +-- FUN_0049ef70 — OnScreen::Setup
        |     +-- FUN_004fa2f0 — VidMan::Setup
        |     +-- FUN_004b1870 — replay/Bink setup (gate)
        +-- Game::Init (FUN_0042D6B0) [state 3]
        |     +-- FUN_004fa320 — VidMan::Init (gate)
        |     +-- FUN_004c8ae0 — Sound::Init
        |     +-- FUN_00455d50 — HWInput::Init
        |     +-- FUN_0040c920 — CamMan::Init
        |     +-- FUN_0042c1a0 — DynMan::Init
        |     +-- FUN_0049efa0 — OnScreen::Init
        |     +-- FUN_004b4030 — Render::Init
        |     +-- (+ 6 more subsystem inits)
        +-- Game::Restart (FUN_0042D7A0) [state 4]
        |     +-- FUN_00464290 — NetComm
        |     +-- FUN_004c8b20 — Sound::Restart
        |     +-- FUN_004a40f0 — steward restart
        |     +-- FUN_004a0fb0 — race timer
        |     +-- FUN_00455da0 — HWInput::Restart
        |     +-- FUN_0040c9e0 — CamMan::Restart
        |     +-- FUN_004b4060 — Render::Restart
        |     +-- FUN_0049f000 — OnScreen::Restart
        |     +-- FUN_004fa640 — VidMan::Restart
        |     +-- (+ more subsystem restarts)
        +-- Game::Post (FUN_0042D8A0) [state 5, per-frame loop]
        |     +-- FUN_004f9f00 — physics update
        |     +-- FUN_00461cd0 — state check
        |     +-- FUN_004b3b40 — vehicle update
        |     +-- FUN_00404460 — AI update
        |     +-- FUN_004d4580 — steward update
        |     +-- FUN_0042c690 — per-tick (10-tick AI/repair loop)
        |     |     +-- FUN_004ee2d0 — brake physics
        |     |     +-- FUN_004ed810 — force computation
        |     |     +-- FUN_004bccc0 — player input (if AIState==0)
        |     +-- (+ render, audio, timing)
        +-- Game::PostSession (FUN_0042DA30) [state 6]
        |     +-- FUN_004d4600 — steward cleanup
        |     +-- FUN_004bdde0 — results processing
        |     +-- FUN_004ba740 — scoring
        +-- Game::Exit (FUN_0042DB20) [state 7]
              +-- FUN_004c8d00 — Sound::Exit
              +-- FUN_00455f00 — HWInput::Exit
              +-- FUN_0042ca70 — DynMan::Exit
              +-- FUN_0049f120 — OnScreen::Exit
              +-- FUN_004fad00 — VidMan::Exit
              +-- FUN_004a1930 — OSMan::Exit
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 1.025f | FUN_0045b200 | Version float |
| "ilya! _1011" | FUN_0045b200 | Version string watermark |
| 0xC9 (201) | FUN_0042c690 | Max tick count cap |
| 10 ticks | FUN_0042c690 | AI/repair update interval |
| 400 ticks | FUN_0042c690 | Human vehicle AI update interval |
| 50 ticks | FUN_0042c690 | Vehicle tick / safety check interval |
| 0x1230 (4656) | DynMan::Init | Stride of VehicleGridArray |
| 104 (0x68) | DynMan::Init | Max grid entries |
| 0x01010101 | Render::Restart | Default render state fill value |
| 0x1a (26) | Render::Restart | Render state array size in dwords |
| 0x18c (396) | VidMan::Init | Stride of SceneArray |
| "F1 Challenge 99-02_APP_MUTEX" | OSMan::Enter | Named mutex for singleton enforcement |
| 0x58 ('X') | Render::ScreenSave | Screenshot key scancode |
| 3DCONFIG.EXE | VidMan::Enter | External config launcher |
| States 1-7 | game.cpp | Game state machine values |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_007d00ec (GameState) — from docs/12 — state machine current state
- DAT_007c56a4 (SessionType) — from docs/12 — determines session branch in VidMan::Restart
- DAT_007c569c (SessionType5) — from docs/12 — server mode gate for HWInput
- DAT_007d0410 (RaceMode) — from docs/12 — championship vs single race branching
- DAT_008ab6e4 (ScoringGate) — from docs/12 — gates main tick execution
- DAT_005c329c (VehicleCount) — from docs/12 — iteration limit
- DAT_007c54e4 (CurrentVehicleIndex) — from docs/12 — player index
- DAT_007c54f0 (VehiclePtrArray) — from docs/12 — vehicle pointer array
- DAT_008ac48c (CurrentSceneIndex) — from docs/12 — scene file index
- DAT_008ac490 (SceneArray) — from docs/12 — scene file array
- DAT_007ce254 (DisableHUDFlag) — from docs/12 — HUD visibility gate
- DAT_005ec3d8 (SeasonDir) — from docs/12 — season data path
- DAT_005ec428 (SeasonName) — from docs/12 — season name string
- DAT_007cf080 (WeatherMode) — from docs/12 — weather-dependent rendering
- FUN_004f9f00 — from docs/18 — physics update
- FUN_00404460 — from docs/02 — AI update
- FUN_004d4580 — from docs/06 — steward update
- FUN_004ee2d0 — from docs/10 — brake physics

**Calls into:**
- docs/19-renderer.md: FUN_0053d400 (display mode), FUN_0054a1c0 (render state), FUN_00546010 (scene init)
- docs/21-audio-network-internals.md: FUN_004c8ab0 (Sound::Setup), FUN_004c8b20 (Sound::Restart)
- docs/02-ai-system.md: FUN_00404460 (AI update)
- docs/06-session-race-logic.md: FUN_004d4580 (steward update)
- docs/07-pit-system.md: FUN_0045bdf0 (clear display)
- docs/10-vehicle-physics.md: FUN_004ee2d0 (brake physics)
- docs/18-physics-dynamics.md: FUN_004f9f00 (physics update)

**Called by:**
- WinMain / CRT startup: FUN_0045b200 (Game::Main entry)

---

## Reimplementation Notes

1. **State machine ordering is critical:** The 7-state machine (1→2→3→4→5→6→2...) must be implemented as a deterministic state machine. State 5 (Post loop) polls for a state change signal, then transitions to state 6 (cleanup), which loops back to state 2. On exit signal, state 7 (Exit) is final.

2. **Gate/abort pattern:** Game::Setup and Game::Init both have gate checks that return 1 (abort) on failure. The caller (Game::Main loop) must handle aborts by re-entering the state. This is NOT an exception — it returns a status code.

3. **Subsystem lifecycle convention:** Every major subsystem follows the Enter→Setup→Init→Restart→Post→Exit lifecycle with 6 functions at matching names. Stubs (log-only) are common for subsystems that need no work at a given phase.

4. **The per-tick function FUN_0042C690** runs within Game::Post and implements its own sub-loop. It runs AI every 10 ticks, human-vehicle AI every 400 ticks, and safety checks every 50 ticks. This is a time-sliced update pattern, not a per-frame pattern.

5. **Vehicle grid array (DAT_005ef9a0):** Stride 0x1230 (4656 bytes) with 104 max entries. Entry +0x364 is the grid position index. This is separate from VehiclePtrArray (DAT_007c54f0) — it's a grid/layout array indexed by team ID.

6. **OSMan::Enter mutex:** The string "F1 Challenge 99-02_APP_MUTEX" is exactly that. The Win32 API CreateMutexA is used, and ERROR_ALREADY_EXISTS is checked. No security descriptor is used.

7. **VidMan::Enter device detection mismatch:** If the saved device name doesn't match the detected device, 3DCONFIG.EXE is launched via CreateProcessA and the function returns 1. This is the only place in the engine where an external EXE is launched.

8. **Camera manager CamMan::Init** calls FUN_00544f50("MAINVIEW") to get the root camera node. The string "MAINVIEW" is hardcoded — this must exist as a named camera in the scene system.

---

## Completeness

- Full specs written: 20 major entry points / ~416 documented functions
- Thunks/empty stubs omitted: ~50 (log-only trace functions, simple wrappers)
- Confidence: high — architecture is well-understood and consistent across all subsystems

---
