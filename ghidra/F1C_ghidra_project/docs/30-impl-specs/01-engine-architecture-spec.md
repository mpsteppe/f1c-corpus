# Implementation Spec: Engine Architecture

Source: docs/01-engine-architecture.md  |  Functions: 416+  |  Date: 2026-07-15

---

## Overview

The Engine Architecture system is the game's lifecycle manager — a 7-state state machine (`Game::Enter → Setup → Init → Restart → Post[loop] → Post-session → Exit`) that orchestrates all subsystems. It runs once per frame during active gameplay (the `Game::Post` loop at ~60Hz), once at startup (states 1-4), and once at shutdown (state 7).

**Data structures owned:**
- `Game` struct (param_1) — at least 12 fields: state at +0x00, various saved mode flags at +0x14/+0x15/+0x20/+0x50/+0x54, UI list fields at +0x44..+0x50, option ID at +0xf4, camera index at +0x38, timer struct at +0xec/+0xf0/+0xf4
- Per-module structs: Sound, HWInput, VidMan, OnScreen, CamMan, Render, DynMan, OSMan — each owns its own state block (typically 0x68–0x100+ bytes)

**Global state owned/written by this system:**
- `DAT_007d00ec` (GameState) — 1-7, written by every state function
- `DAT_007c56a0` (SessionType initial) — set to 3 in FUN_0045b200
- `DAT_007c56b0` (version float) — ~1.025
- `DAT_007c56b4` (version string) — "ilya! _1011"
- `DAT_007ce2a0` — application instance handle
- Various module-restart globals: `DAT_007c5694/5698` (dynman counters), `DAT_008afe70` (vidman state)
- Per-module state arrays: `DAT_005ef9a0` (vehicle grid, stride 0x1230), `DAT_005ea500-558` (camera globals)

**Game loop order (per frame, in `FUN_0042d8a0`):**
1. Physics update (`FUN_004f9f00`)
2. State check — continue/exit/proceed/error
3. Timing updates (`FUN_004ba180`, `FUN_00463ca0`)
4. Vehicle update (`FUN_004b3b40`)
5. AI update (`FUN_00404460`)
6. Steward update — penalties, flags (`FUN_004d4580`)
7. Player/input update (`FUN_00455e50`, `FUN_0042c690`)
8. Scene/render update (`FUN_004b3ba0`, `FUN_004643c0`, `FUN_00463cd0`)
9. Timing/scoring (`FUN_004ba6c0`)
10. If continuing: camera, particles, render, on-screen (`FUN_0040ca30`, `FUN_004cfcc0`, `FUN_004b40a0`, `FUN_0049f070`)
11. Post-frame: physics post, sound post, vidman post, OS post, memory (`FUN_004f9f30`, `FUN_004c8b70`, `FUN_004fa7e0`, `FUN_004fcee0`, `FUN_004a1830`)

**Subsystem lifecycle per module (Sound, HWInput, VidMan, OnScreen, CamMan, Render, DynMan, OSMan):**
Each module implements up to 6 methods matching the game states:
- `Enter()` — state 1: allocate resources, detect hardware
- `Setup()` — state 2: configure, create devices
- `Init()` — state 3: full initialization, load data
- `Restart()` — state 4: reset for new session
- `Post()` — state 5: per-frame update
- `Exit()` — state 7: teardown, free

Several modules have stub implementations (log-only for Setup/Exit).

---

## Data Structures

### GameState (param_1 — game object)

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | int | State | 1-7, mirrors DAT_007d00ec |
| +0x14 | byte | InitFlag | Gate for race mode setup |
| +0x15 | byte | InitFlag2 | Secondary gate |
| +0x20 | int | StateCondition | Condition for save/restore |
| +0x44 | int* | UIListHead | UI item list head |
| +0x48 | int* | UIListTail | UI item list tail |
| +0x4c | int* | UICurrentItem | Current UI item |
| +0x50 | int | ItemCount | UI item count |
| +0x50 | int | Saved_DAT_007d2e44 | Saved during race setup |
| +0x54 | int | Saved_RaceMode | Saved from DAT_007d0410 |
| +0xf4 | int | OptionID | UI option identifier |
| +0xec | int | SharedValue | Thread-safe int (mutex-protected) |
| +0xf0 | HANDLE | MutexHandle | Win32 mutex for thread safety |
| +0xf4 | DWORD | MutexTimeout | Wait timeout ms |

### Per-Module State Structs

**Sound module (param_1):** No offsets documented — all delegated to FUN_004c7ca0 etc.

**HWInput module (param_1):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x000 | ptr | DirectInputDevice | vtable ptr, released on Exit |
| +0x2428 | byte | DeviceDetected | 0/1 based on controller scan |
| +0x1f98 | byte[] | ControllerScan | Device detection scan area |
| +0x665 | int | HapticFlag | Force feedback active flag |
| +0x6c4 | int | FeedbackHandle | -1 = uninitialized |

**CamMan module (param_1):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | ptr | MAINVIEW scene node | Camera scene node |
| +0x08 | ptr | CurrentCamera | Cleared to 0 on Post |
| +0x18 | ptr | CameraObj1 | Released on Post |
| +0x1c | ptr | CameraObj2 | Released on Post |
| +0x20 | ptr | CameraObj3 | Released on Post |
| +0x2e | byte | Flag | Camera flag, reset to 0 |
| +0x38 | int | CameraIndex | -1 = none |
| +0x2d | byte | InitFlag | Set during Init |
| +0xf5 | byte | AltControlMode | Alternate camera control |
| +0x3d | int | FreeCameraFlag | Free camera mode |
| +0x3f | float | ZoomClampMin | Camera zoom lower bound |
| +0x40 | float | ZoomClampMax | Camera zoom upper bound |

**Render module (param_1):** 0x68 bytes (26 ints) filled with 0x01010101 on Restart. No named offsets.

### ThreadSync (mutex-protected struct, used by FUN_00585770)

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xec | int | SharedValue | Value read under mutex |
| +0xf0 | HANDLE | MutexHandle | Win32 mutex, NULL = no mutex |
| +0xf4 | DWORD | WaitTimeout | ms timeout |

### TimerStruct (param_1 for FUN_005564b0)

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | int | ActiveFlag | 0 = timer disabled |
| +0x48 | int | TimerModeFlags | Bit 0 = QPC mode, Bit 1 = alternate timer |

### Linked List Container (param_1, used by FUN_005819c0)

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | int* | HeadPtr | Linked list head |
| +0x04 | int* | TailPtr | Linked list tail |
| +0x08 | int | Count | Node count |
| +0x0c | int | Capacity | Node capacity |

### MutexCreateStruct (param_1, used by FUN_00586560)

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x54 | HANDLE | MutexHandle | Win32 mutex handle |
| +0x5c | byte | MutexValidFlag | 1 = mutex exists |

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007d00ec | int | GameState | 1-7 state machine, written by all state functions |
| DAT_007c56a0 | int | SessionMode | Initialized to 3 in FUN_0045b200 |
| DAT_007c56b0 | float | VersionFloat | ~1.025 version identifier |
| DAT_007c56b4 | char* | VersionString | "ilya! _1011" version watermark |
| DAT_007c56ad | byte | InitFlag | Set to 0 in FUN_0045b200 |
| DAT_007ce2a0 | HANDLE | AppInstanceHandle | Win32 instance handle from param_1 |
| DAT_007c5694 | int | DynManCounter1 | DynMan state, zeroed in Restart |
| DAT_007c5698 | int | DynManCounter2 | DynMan state, zeroed in Restart |
| DAT_007c54dc | int | CurrentPlayerIndex | Copied from DAT_007c54e4 in DynMan::Restart |
| DAT_007c54e0 | ptr | PlayerVehiclePtrCopy | Copied from VehiclePtrArray[index] |
| DAT_008afe70 | int | VidManState | Set to 0 in VidMan::Init |
| DAT_007d0798 | float | TimeAccel | Time scale, set to 0.05 in race setup |
| DAT_005ea500-558 | various | CameraGlobals | Zeroed in CamMan::Init |
| DAT_007ce2d8 | HANDLE | AppMutexHandle | "F1 Challenge 99-02_APP_MUTEX" handle |
| DAT_007ce250 | int | FrameCounter | Options menu frame counter |
| DAT_007ce25c | int | ExitFlag | Options menu exit flag |

---

## Public API — Entry Points

### FUN_0045b200 — Game Main Entry / Init

**Inferred signature:** `int GameMain(int hInstance)`
**Called from:** WinMain / CRT startup
**Called by (from callers.json):** Not in callers.json (top-level entry point)

**What it does:**
1. Sets global version/watermark: `DAT_007c56b0=1.025f`, `DAT_007c56b4="ilya! _1011"`, `DAT_007c56ad=0`, `DAT_007c56a0=3`
2. Stores param_1 in `DAT_007ce2a0` (app handle)
3. Calls in order: config/cmdline parsing, config.ini loader, session/race init, UI init, networking init, NetComm cmdline
4. Enters game state machine loop:
   - `FUN_0042d370` (Game::Enter → state 1)
   - `FUN_0042d5d0` (Game::Setup → state 2) — loops back on abort
   - `FUN_0042d6b0` (Game::Init → state 3)
   - `FUN_0042d7a0` (Game::Restart → state 4)
   - `FUN_0042d8a0` (Game::Post loop → state 5) — per-frame main loop
   - `FUN_0042da30` (Game::Post-session → state 6) — cleanup between sessions
   - Back to Setup for next session
5. On final exit: `FUN_0042db20` (Game::Exit → state 7)

**Side effects:**
- Writes: DAT_007c56b0, DAT_007c56b4, DAT_007c56ad, DAT_007c56a0, DAT_007ce2a0
- Calls full subsystem lifecycle

### FUN_0042d370 — Game::Enter() (state 1)

**Inferred signature:** `int Game_Enter(GameState* this)`
**Called from:** Game main loop, state transition 7→1

**What it does:**
1. Loads season .gdb file (default F1_2002.gdb)
2. Scans `*.rcd` and `*.pit` files from `DAT_005ec3d8` directory
3. Calls track loader, player loader, string buffer, on-screen enter, game setup

**Key constants:** Default season file "F1_2002.gdb"

**Side effects:**
- Loads file data from disk
- Calls: FUN_004c8a20, FUN_00455bf0, FUN_004b0170, FUN_0049ef40, FUN_00463e20

### FUN_0042d5d0 — Game::Setup() (state 2)

**Inferred signature:** `int Game_Setup(GameState* this)`
**Called from:** Game main loop

**What it does:**
1. Sets `*param_1 = 2`
2. Gate: if `FUN_004a0eb0` (steward init) returns nonzero → abort early (return 1)
3. Calls in sequence: HWInput::Setup, Sound::Setup, OnScreen::Setup, VidMan::Setup
4. Gate: if `FUN_004b1870` (replay/Bink) returns nonzero → abort (return 1)
5. Calls: SpecialFX::Setup, FUN_004d36d0, FUN_0042c170, FUN_00463ef0

**Side effects:**
- Subsystem initializations
- Returns 0 on success, 1 on abort (retriggers Setup)

### FUN_0042d6b0 — Game::Init() (state 3)

**Inferred signature:** `int Game_Init(GameState* this)`
**Called from:** Game main loop after Setup

**What it does:**
1. Sets `*param_1 = 3`
2. Calls replay/load state init (`FUN_004ba1f0`)
3. Calls VidMan::Init (`FUN_004fa320`) — if non-zero return, abort with error code 1
4. Calls in sequence: sound init, physics, file paths, timers, hardware input, special effects, game state, replay, on-screen display, HUD, pit UI, menu

**Side effects:**
- Writes: DAT_008afe70 = 0 (vidman state)
- On abort: returns 1 (triggers re-init)

### FUN_0042d7a0 — Game::Restart() (state 4)

**Inferred signature:** `int Game_Restart(GameState* this)`
**Called from:** Game main loop after Init

**What it does:**
1. Sets `*param_1 = 4`
2. Calls 19 subsystem restart functions: NetComm, Sound, Steward, RaceTimer, Session, HWInput, CamMan, Render, OnScreen, replay, VidMan, OSMan
3. Returns 0

**Side effects:**
- Resets all subsystem state for new session
- Writes: DAT_007c5694=0, DAT_007c5698=0 (dynman counters)

### FUN_0042d8a0 — Game::Post() Main Loop (state 5)

**Inferred signature:** `int Game_Post(GameState* this)`
**Called from:** Game main loop, each frame while state==5

**What it does (per-frame sequence):**
1. `FUN_004f9f00` — physics update (integrates vehicle dynamics)
2. `FUN_00461cd0` — state check: 1=continue, 4=exit, 5=proceed, 6=error
3. `FUN_004ba180`, `FUN_00463ca0` — timing updates
4. `FUN_004b3b40` — vehicle update (per-vehicle physics state)
5. `FUN_00404460` — AI update (per-vehicle AI logic)
6. `FUN_004d4580` — steward update (penalties, flags, rules enforcement)
7. `FUN_00455e50`, `FUN_0042c690` — player/input update (read input, map to actions)
8. `FUN_004b3ba0`, `FUN_004643c0`, `FUN_00463cd0` — scene/render update
9. `FUN_004ba6c0` — timing/scoring update
10. If continuing (state==1): `FUN_0040ca30` (camera), `FUN_004cfcc0` (particles), `FUN_004b40a0` (render), `FUN_0049f070` (on-screen HUD)
11. Post-frame: `FUN_004f9f30` (physics post), `FUN_004c8b70` (sound post), `FUN_004fa7e0` (vidman post), `FUN_004fcee0`, `FUN_004a1830` (OS post / memory)

**Side effects:**
- Reads/writes all game globals (SessionType, RacePhase, etc.)
- Drives all per-frame simulation

### FUN_0042da30 — Game::Post() Session Cleanup (state 6)

**Inferred signature:** `int Game_PostSession(GameState* this)`
**Called from:** Game main loop, state 5→6 transition

**What it does:**
1. Sets `DAT_007c56a0 = 3` (session mode → Practice3)
2. Calls steward cleanup (`FUN_004d4600`)
3. Calls results processing (`FUN_004bdde0`, `FUN_004ba740`)

**Side effects:**
- Finalizes session results and standings

### FUN_0042db20 — Game::Exit() (state 7)

**Inferred signature:** `void Game_Exit(GameState* this)`
**Called from:** Game main loop on final exit

**What it does:**
1. Sets `*param_1 = 7`
2. Calls in order: Sound::Exit, render shutdown, string buffers (×2), HWInput::Exit, DynMan::Exit, replay cleanup, OnScreen::Exit, VidMan::Exit, UI manager, game state cleanup, session cleanup

**Side effects:**
- Full subsystem teardown
- Releases all OS resources

### FUN_0042c690 — Main Game Tick (Per-Frame Physics/AI Tick)

**Inferred signature:** `void Game_Tick(GameState* this)`
**Called from:** Game::Post loop (state 5), step 7

**What it does:**
1. Gate: if ScoringGate (`DAT_008ab6e4`) == 2 → return early
2. Computes target tick time, caps at 0xC9 (201) ticks
3. Loop: every 10 ticks runs AI per vehicle, repair, physics
4. Every 400 ticks: AI update on human vehicles
5. Every 50 ticks: vehicle tick, safety checks
6. If player AIState==0: calls player input (`FUN_004bccc0`)
7. If `DAT_007cbf24 != 0`: calls `FUN_00451720`

**Key constants:**
- 10 = ticks between AI/physics iterations
- 0xC9 = max ticks per frame
- 400 = ticks between human-vehicle AI updates
- 50 = ticks between vehicle safety checks

### FUN_0040cce0 — CamMan::Post()

**Inferred signature:** `void CamMan_Post(CameraManager* this)`
**Called from:** Game::Post loop per frame

**What it does:**
1. Clears `this->CurrentCamera` (+0x08) to 0
2. Calls `FUN_004083e0` (camera transform update)
3. Releases 3 camera objects at +0x18, +0x1c, +0x20 via vtable dispatch(1), then nulls them
4. Sets flag at +0x2e to 0

### FUN_004b87c0 — LoadingPhase1

**Inferred signature:** `void LoadingPhase1(LoadState* this)`
**Called from:** Scene/loading manager

**What it does:**
1. Computes elapsed time, sets loading active flag
2. Loop over vehicles: load texture, copy state
3. Calls audio init (`FUN_004d8840`), sets ready flag
4. Seeds RNG with loading time
5. Loads chunks until total >= duration

### FUN_00404890 — Race Mode Setup

**Inferred signature:** `void RaceModeSetup(GameState* this)`
**Called from:** Game state machine during pre-race

**What it does:**
1. Calls load screen setup (`FUN_00404850`)
2. If `this->StateCondition` (+0x20) != 1: sets init pending flags, returns
3. Saves `DAT_007d2e44` into `this+0x50`, sets `DAT_007d2e44=1`
4. Saves `DAT_007d0410` (RaceMode) into `this+0x54`, sets `DAT_007d0410=2`
5. Clamps RaceMode between `DAT_007d0418` and `DAT_007d041c`
6. Sets `DAT_007d0798` (time acceleration) = 0.05

### FUN_004049d0 — Race Mode Teardown

**Inferred signature:** `void RaceModeTeardown(GameState* this)`
**Called from:** Game state machine post-race

**What it does:**
1. Guard: `this->InitFlag` (+0x14) != 0 AND `this->StateCondition` (+0x20) == 1
2. Restores `DAT_007d2e44` and `DAT_007d0410` from backups
3. Clamps restored RaceMode
4. Resets camera flag, calls `FUN_00408450(0.1f)`

### FUN_0045b200 sub-calls (module lifecycle registration functions)

Each module (Sound, HWInput, VidMan, OnScreen, CamMan, Render, DynMan, OSMan) has Enter/Setup/Init/Restart/Post/Exit methods. Most are thin wrappers around debug logging + delegation to subsystem-specific initialization functions. The notable functional ones are:

- **FUN_004c8a20 (Sound::Enter):** Tests sound hardware (`FUN_004c82c0`), falls back to alternate path (`FUN_004c82f0`), configures sound with display handle, initializes audio mixer, initiates 2 audio channels.
- **FUN_00455bf0 (HWInput::Enter):** Hides cursor, initializes control bindings (43 string names), conditionally initializes input device if `DAT_007d13a0==1`.
- **FUN_004fa000 (VidMan::Enter):** Tests Direct3D device, reads device name from player file, compares against current device, launches 3DCONFIG.EXE on mismatch.
- **FUN_004fa320 (VidMan::Init):** Sets display mode/resolution, branches on render mode (1/2/3), resolves scene file path, loads scene.
- **FUN_0042c3b0 (DynMan::Restart):** Zeroes dynman counters, reloads AI settings, refreshes all vehicles, copies player index.
- **FUN_0042c1a0 (DynMan::Init):** Handles vehicle grid setup (stride 0x1230, max 104), session-dependent init paths, per-vehicle UI setup.

---

## Internal Call Graph

```
GameMain (FUN_0045b200)  [called from WinMain]
  +-- FUN_00423070 — config/cmdline parsing
  +-- FUN_00421cd0 — config.ini loader
  +-- FUN_004d7a00 — session/race init
  +-- FUN_004a0d50 — UI init
  +-- FUN_004b17f0 — networking init
  +-- FUN_00463160 — NetComm cmdline
  +-- Game State Machine Loop:
        +-- FUN_0042d370 — Game::Enter (state 1)
        |     +-- FUN_004c8a20 — Sound::Enter
        |     +-- FUN_00455bf0 — HWInput::Enter
        |     +-- FUN_004b0170 — string buffer init
        |     +-- FUN_0049ef40 — OnScreen::Enter
        |     +-- FUN_00463e20 — game setup init
        +-- FUN_0042d5d0 — Game::Setup (state 2)
        |     +-- FUN_004a0eb0 — steward/options init [gate]
        |     +-- FUN_00455c60 — HWInput::Setup
        |     +-- FUN_004c8ab0 — Sound::Setup
        |     +-- FUN_0049ef70 — OnScreen::Setup
        |     +-- FUN_004fa2f0 — VidMan::Setup
        |     +-- FUN_004b1870 — PlayerFile::Setup [gate]
        |     +-- FUN_004cf070 — SpecialFX::Setup
        |     +-- FUN_0042c170 — DynMan::Setup
        +-- FUN_0042d6b0 — Game::Init (state 3)
        |     +-- FUN_004ba1f0 — replay init
        |     +-- FUN_004fa320 — VidMan::Init [abort on fail]
        |     +-- FUN_004c8ae0 — Sound::Init
        |     +-- FUN_00455d50 — HWInput::Init
        |     +-- FUN_0049efa0 — OnScreen::Init
        |     +-- FUN_0042c1a0 — DynMan::Init
        |     +-- FUN_004b4030 — Render::Init
        |     +-- FUN_0040c920 — CamMan::Init
        |     +-- FUN_004a40e0 — PitUI init
        |     +-- FUN_004cf070 — SpecialFX::Init
        |     +-- FUN_004bdc10 — search grid
        +-- FUN_0042d7a0 — Game::Restart (state 4)
        |     +-- FUN_00464290 — NetComm restart
        |     +-- FUN_004c8b20 — Sound::Restart
        |     +-- FUN_004a40f0 — steward restart
        |     +-- FUN_004a0fb0 — race timer restart
        |     +-- FUN_00455da0 — HWInput::Restart
        |     +-- FUN_0040c9e0 — CamMan::Restart
        |     +-- FUN_004b4060 — Render::Restart
        |     +-- FUN_0049f000 — OnScreen::Restart
        |     +-- FUN_004fa640 — VidMan::Restart
        |     +-- FUN_0042c3b0 — DynMan::Restart
        |     +-- FUN_004c01a0 — grid init
        +-- FUN_0042d8a0 — Game::Post loop (state 5) [per frame]
        |     +-- FUN_004f9f00 — physics integrate
        |     +-- FUN_00461cd0 — state check gate
        |     +-- FUN_004ba180 — timing A
        |     +-- FUN_00463ca0 — timing B
        |     +-- FUN_004b3b40 — vehicle update
        |     +-- FUN_00404460 — AI update
        |     +-- FUN_004d4580 — steward update
        |     +-- FUN_00455e50 — player/input
        |     +-- FUN_0042c690 — game tick (AI/repair/physics every N ticks)
        |     +-- FUN_004b3ba0 — scene update
        |     +-- FUN_004643c0 — render update
        |     +-- FUN_004ba6c0 — timing/scoring
        |     +-- [if continuing] FUN_0040ca30 — camera
        |     +-- [if continuing] FUN_004cfcc0 — particles
        |     +-- [if continuing] FUN_004b40a0 — screenshot handler
        |     +-- [if continuing] FUN_0049f070 — on-screen HUD
        |     +-- FUN_004f9f30 — physics post
        |     +-- FUN_004c8b70 — sound post
        |     +-- FUN_004fa7e0 — vidman post
        |     +-- FUN_004a1830 — OS post / memory cleanup
        +-- FUN_0042da30 — Game::Post-session (state 6)
        |     +-- FUN_004d4600 — steward cleanup
        |     +-- FUN_004bdde0 — results processing
        |     +-- FUN_004ba740 — replay cleanup
        +-- FUN_0042db20 — Game::Exit (state 7)
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
| 1.025f | FUN_0045b200 | Version float stored in DAT_007c56b0 |
| 0x0C9 (201) | FUN_0042c690 | Max ticks per frame (cap) |
| 10 | FUN_0042c690 | Ticks between AI/physics iterations |
| 400 | FUN_0042c690 | Ticks between human-vehicle AI updates |
| 50 | FUN_0042c690 | Ticks between vehicle safety checks |
| 0.05 | FUN_00404890 | Time acceleration default (DAT_007d0798) |
| 3 | FUN_0045b200 | SessionMode initial value (FUN_0045b200) |
| 2 | FUN_0042c690 | ScoringGate skip value (DAT_008ab6e4) |
| 0x1b0 | FUN_00465300 | Message node allocation size |
| 0x68 | FUN_004b4060 | Render state bytes to fill (26 ints) |
| 0x01010101 | FUN_004b4060 | Render default fill pattern |
| 0x1230 | FUN_0042c1a0 | Vehicle grid array stride |
| 104 (0x68) | FUN_0042c1a0 | Max vehicle count |
| 0x5C | FUN_00586560 | SECURITY_ATTRIBUTES nLength |
| 43 | FUN_00455bf0 | Number of control binding strings |
| 0xB7 | FUN_004a18d0 | ERROR_ALREADY_EXISTS for mutex |
| 0x1f400 (128KB) | FUN_0059B490 | Max buffer growth (math utility) |
| 0x1f | FUN_0059964a | Size rounding mask (+32 bytes) |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007c56a4` (SessionType) — from steward/session, gates render state and game flow
- `DAT_007c56a8` (RacePhase) — from session, checked in VidMan::Restart
- `DAT_007d0410` (RaceMode) — from game, gates championship handling
- `DAT_008ab6e4` (ScoringGate) — from scoring, gates tick execution
- `DAT_007cebc4` (FormationLap) — from game, gates race start
- `DAT_007c569c` (SessionType5) — server mode gate for HWInput
- `DAT_007d1ffc` (AudioQualityLevel) — from audio, gates audio mixer call in HWInput
- `DAT_005c329c` (VehicleCount) — from steward, loop bound for per-vehicle ops
- `DAT_007c54e4` (CurrentVehicleIndex) — from game, used in DynMan
- `DAT_007c54f0` (VehiclePtrArray) — from game, used in DynMan
- `DAT_008ac48c` (CurrentSceneIndex) — from setup, used in VidMan::Init
- `DAT_008ac490` (SceneArray) — from setup, used in VidMan
- `DAT_007ce254` (DisableHUDFlag) — from UI, gates render state

**Calls into:**
- docs/18-physics-dynamics.md: FUN_004f9f00 (physics integrate), FUN_004f9f30 (physics post)
- docs/02-ai-system.md: FUN_00404460 (AI update)
- docs/06-session-race-logic.md: FUN_004d4580 (steward update), FUN_004a0fb0 (race timer)
- docs/19-renderer.md: FUN_004b3ba0, FUN_004b40a0, FUN_004b4060
- docs/21-audio-network-internals.md: FUN_004c8b70 (sound post), FUN_00464290 (NetComm), FUN_004c8d00 (Sound::Exit), FUN_004c8b20 (Sound::Restart)
- docs/09-track-system.md: FUN_004cfcc0 (particles)
- docs/07-pit-system.md: FUN_004a40f0 (steward), FUN_004a40e0 (pit UI)

**Called by:**
- docs/20-math-utilities.md: Various utility functions (FUN_0057a730 etc.) call into engine architecture for dispatch
- Win32 CRT startup code

---

## Reimplementation Notes

1. **Game state machine ordering is critical:** Subsystem lifecycle must be called in EXACT order documented. Setup → Init → Restart → Post must not be reordered as later subsystems depend on earlier ones (e.g., VidMan::Init must complete before DynMan::Init reads scene handles).

2. **State machine loops until abort cleared:** Game::Setup (state 2) returns 1 if steward init fails — the main loop re-calls Setup until it returns 0.

3. **State 5 (Post) is NOT a simple loop:** It processes ONE frame and returns. The outer loop in FUN_0045b200 is responsible for calling it repeatedly. Each call processes state, runs physics/AI/render, and either continues (state stays 5), exits (transition to 6→7), or proceeds to next session.

4. **ScoringGate skip (DAT_008ab6e4 == 2):** When ScoringGate is 2, the per-frame tick (`FUN_0042c690`) is completely skipped. This is a multiplayer/network mode optimization.

5. **Render state fill pattern:** `FUN_004b4060` fills render state with 0x01010101, not 0. This is intentional — 0x01010101 is a known MSVC debug pattern for uninitialized data.

6. **Options menu is synchronous:** `FUN_004a0eb0` contains its own while-loop that processes frame timing, input, and rendering INLINE. It does not return until the menu exits.

7. **Camera objects are reference-counted:** The three camera objects at +0x18/+0x1c/+0x20 are released via vtable dispatch(1) every frame in CamMan::Post(), then nulled. The flag `1` likely means "release".

8. **Thread synchronization uses Win32 mutexes:** Mutex handles at known offsets (+0x54, +0xf0, +0x20) with flags at +0x5c/+0x28. Pattern: CloseHandle old → CreateMutexA → store handle. Timeout stored at +0xf4.

9. **Window procedure not in doc:** The main message pump/window procedure is not in this subsystem — it's likely in WinMain or a UI module. This doc covers the game state machine only.

10. **Module logging pattern:** Many module lifecycle functions follow: `FUN_004d7a50(traceGate)` → `FUN_004d7aa0(logMsg)`. These are debug-only and can be omitted in reimplementation unless debug tracing is desired.

---

## Completeness

- Full specs written: ~30 / ~416 total documented functions
- Thunks/empty stubs omitted: ~386 (mostly tiny wrappers, SEH unwind handlers, log-only stubs)
- Confidence: high (all major entry points and state transitions documented)

---
