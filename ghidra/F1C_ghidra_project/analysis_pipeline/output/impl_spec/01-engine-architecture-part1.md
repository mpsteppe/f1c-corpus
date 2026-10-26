# Engine Architecture - Session State Machine, Module Lifecycles
## game.cpp - Full Session State Machine (9 functions)
### game.cpp — Full Session State Machine (9 functions)

Source: `game.cpp`. The game session lifecycle is a state machine with states
stored in `param_1[0]` (Game object) and mirrored to global `DAT_007d00ec`.

| State | Function | Name | Description |
|-------|----------|------|-------------|
| 1 | FUN_0042d370 | Game::Enter() | Load .gdb, .rcd, .pit files, track, player |
| 2 | FUN_0042d5d0 | Game::Setup() | Vehicle setup, steward setup, track load |

### FUN_0042d5d0 — Game::Setup()

Game state machine state 2. Initializes game subsystems after Enter().

**Key logic:**
- Sets param_1[0] = 2 (state)
- Gate: if FUN_004a0eb0 (steward init) returns nonzero → abort early (return 1)
- Calls HWInput::Setup, Sound::Setup, OnScreen::Setup, VidMan::Setup in sequence
- Gate: if FUN_004b1870 (replay/Bink) returns nonzero → abort (return 1)
- Calls SpecialFX::Setup, FUN_004d36d0 (sound), FUN_0042c170 (game), FUN_00463ef0

**Calls:** FUN_004f9160 (player file load), FUN_004a0eb0 (steward init), FUN_004b1870 (replay/Bink setup), FUN_00455c60 (HWInput::Setup), FUN_004c8ab0 (Sound::Setup), FUN_0049ef70 (OnScreen::Setup), FUN_004fa2f0 (VidMan::Setup)
| 3 | FUN_0042d6b0 | Game::Init() | AI DB init, weather, steward init, physics |
| 4 | FUN_0042d7a0 | Game::Restart() | Restart — calls 19 subsystem restarts (see below) |
| 5 | FUN_0042d8a0 | Game::Post() (loop) | Main physics/AI/steward update loop |

### FUN_0042D7A0 — Game::Restart()

Game module restart — state 4 in game lifecycle. Sets internal state to 4, then calls restart on all subsystems.

**Key logic:**
- Sets param_1[0] = 4 (Restart phase)
- Profile entry trace (source: game.cpp)
- Calls 19 subsystem restart/init functions: NetComm (FUN_00464290), Sound (FUN_004c8b20), Steward (FUN_004a40f0), RaceTimer (FUN_004a0fb0), Session (FUN_004d3cf0), HWInput (FUN_00455da0), CamMan (FUN_0040c9e0), Render (FUN_004b4060), OnScreen (FUN_0049f000), replay (FUN_004ba460), VidMan (FUN_004fa640), OSMan (FUN_004a1830), and scene rendering
- Returns 0

**Calls:** FUN_004c8b20 (Sound::Restart), FUN_004a40f0 (steward), FUN_004a0fb0 (race timer), FUN_00455da0 (HWInput::Restart), FUN_0040c9e0 (CamMan::Restart), FUN_004b4060 (Render::Restart), FUN_0049f000 (OnScreen::Restart), FUN_004fa640 (VidMan::Restart), FUN_00464290 (NetComm, docs/21)
| 6 | FUN_0042da30 | Game::Post() (post-session) | Cleanup, results, steward cleanup |
| 7 | FUN_0042db20 | Game::Exit() | Full teardown |

#### FUN_0042cf10 — Multiplayer Vehicle Placement / State Transition

Handles vehicle grid placement for multiplayer race sessions. Transitions:
- States 2/3/4 → practice setup (FUN_004c01a0)
- State 4→5 → quali start
- State 5→6 → race start (formation lap if `DAT_007cebc4` or `DAT_007d0410==4`)
- State 6→7 → post-race

Calls FUN_004bc320/330 (vehicle placement per car, looped by DAT_005c329c),
FUN_004c6f10 (grid setup), FUN_00462e20/FUN_00462a10 (formation lap logic).

**Globals:**
- `DAT_007d00ec` = current game state (clamped between DAT_007d00f4 and DAT_007d00f8)
- `DAT_007cebc4` = formation lap enabled flag
- `DAT_007d0410` = race mode (4 = ?)

#### FUN_0042d260 — Game File Loader

Loads tire brands (FUN_004d7660), scenes (FUN_004c52c0), vehicles (FUN_004c3d80).
Checks DAT_008ac488 (scene count ≥1) and DAT_008ac390 (vehicle count ≥1).

#### FUN_0042d370 — Game::Enter()

Loads season .gdb file (default F1_2002.gdb), scans `*.rcd` and `*.pit` files
from DAT_005ec3d8 directory. Calls FUN_004c8a20 (track loader), FUN_00455bf0
(player loader), FUN_004b0170, FUN_0049ef40, FUN_00463e20.

#### FUN_0042d8a0 — Game::Post() Main Loop

The core game loop. Each iteration:
1. FUN_004f9f00 — physics update
2. FUN_00461cd0 — state check (1=continue, 4=exit, 5=proceed, 6=error)
3. FUN_004ba180, FUN_00463ca0 — timing updates
4. FUN_004b3b40 — vehicle update
5. FUN_00404460 — AI update
6. FUN_004d4580 — steward update (penalties, flags)
7. FUN_00455e50, FUN_0042c690 — player/input update
8. FUN_004b3ba0, FUN_004643c0, FUN_00463cd0 — scene/render update
9. FUN_004ba6c0 — timing/scoring
10. If continuing (state==1): FUN_0040ca30, FUN_004cfcc0, FUN_004b40a0, FUN_0049f070
11. FUN_004f9f30, FUN_004c8b70, FUN_004fa7e0, FUN_004fcee0, FUN_004a1830 — post-frame

#### FUN_0042da30 — Game::Post() Post-Session

Sets `_DAT_007c56a0 = 3` (session type → Practice3) at end. Calls steward
cleanup (FUN_004d4600), results processing (FUN_004bdde0, FUN_004ba740).

---

## dynman.cpp - Dynamics Manager (6 functions)
### dynman.cpp — Dynamics Manager (6 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_0042c130 | DynMan::Enter() | Log + FUN_0042bd60 |
| FUN_0042c170 | DynMan::Setup() | Log only (empty) |
| FUN_0042c1a0 | DynMan::Init() | Log + FUN_0040fe50 + vehicle grid setup (max 104, stride 0x1230 in DAT_005ef9a0) + FUN_004b1520 (track config) + FUN_004c01a0 (grid) + FUN_0042bc80 + physics init (FUN_004f9480 per vehicle) + FUN_004326e0 + player init (FUN_004336f0) |
### FUN_0042c3b0 — DynMan::Restart()

Resets dynman state, reloads AI settings, refreshes all vehicles.

**Key logic:**
- Logs entry, zeroes DAT_007c5694/5698 (dynman state counters)
- Calls FUN_004333e0 (AI settings reload)
- Iterates all vehicles (DAT_005c329c count), calls FUN_004c6d90 per vehicle
- Calls FUN_00410890 (post-processing)
- Copies player index: DAT_007c54dc = DAT_007c54e4, DAT_007c54e0 = VehiclePtrArray[DAT_007c54e4]

**Calls:** FUN_004333e0 (AI settings), FUN_004c6d90 (per-vehicle reset), FUN_00410890

**Moddability:** hardcoded
| FUN_0042c9f0 | DynMan::Post() | Log + FUN_004c6e80 per vehicle + FUN_0043e230 + FUN_0042bd60 + FUN_0040fb30 |
### FUN_0042ca70 — DynMan::Exit()

Debug-logging-only stub. Logs "Entered DynMan::Exit()" when debug flag enabled. No cleanup.

**Key logic:**
- Calls FUN_004d7a50(2) to check debug logging at source line 955
- If enabled, writes "Entered DynMan::Exit()" to debug buffer via FUN_004d7aa0
- No state changes or resource deallocation

**Calls:** FUN_004d7a50 (debug gate), FUN_004d7aa0 (debug log write)


**New globals:**
- `DAT_005ef9a0` — vehicle dynamics array (stride 0x1230, max 104)
- `DAT_007c5690` — dedicated server flag
- `DAT_007c5694` / `DAT_007c5698` — dynman state
- `DAT_007c54dc` / `DAT_007c54e0` — player index/pointer copies

## sound.cpp - Sound Manager (6 functions)
### sound.cpp — Sound Manager (6 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_004c8a20 | Sound::Enter() | Log + FUN_004c82c0/82f0/83b0/8560 + FUN_004c8900(DAT_007cf380) + FUN_004184f0 + FUN_004116c0(0/1) |

### FUN_004c8a20 — Sound::Enter()

Sound module initialization — first call in sound lifecycle.

**Key logic:**
- Debug log entry
- If FUN_004c82c0 returns 0 → calls FUN_004c82f0 (fallback path)
- Calls FUN_004c83b0, FUN_004c8560, FUN_004c8900(DAT_007cf380) — configures sound with display handle
- Calls FUN_004184f0 (audio mixer)
- Initiates two channels via FUN_004116c0(0) and FUN_004116c0(1)
| FUN_004c8ab0 | Sound::Setup() | Log only |
| FUN_004c8ae0 | Sound::Init() | Profile trace + FUN_004c7ca0 |
| FUN_004c8b20 | Sound::Restart() | Log + FUN_004c8630 + FUN_004c7dd0 + FUN_004186a0 |

### FUN_004C8AE0 — Sound::Init()

Sound module init — delegates to sound hardware init with profile logging.

**Key logic:**
- Profile entry trace (source: sound.cpp)
- Calls FUN_004c7ca0 (sound hardware initialization)

**Calls:** FUN_004c7ca0 (sound hardware init)
| FUN_004c8ca0 | Sound::Post() | Log + FUN_004c8180 + FUN_004c7e80 + FUN_004c8a10 + FUN_00418a60 |
| FUN_004c8d00 | Sound::Exit() | Log + FUN_00411740(0/1) + FUN_00418900 + FUN_004c8630 + FUN_004c8350 |

## onscreen.cpp - OnScreen Manager (6 functions)
### onscreen.cpp — OnScreen Manager (6 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_0049ef40 | OnScreen::Enter() | Log only |
### FUN_0049ef70 — OnScreen::Setup()

Empty setup stub. Logs entry only.

**Key logic:**
- Logs entry via FUN_004d7aa0, no other operations

**Moddability:** hardcoded
| FUN_0049efa0 | OnScreen::Init() | Log + FUN_004d8220 + FUN_0049ca00 (cockpit LEDs) + FUN_0045bbe0 + FUN_0049b0a0 |
### FUN_0049f000 — OnScreen::Restart()

Resets on-screen display state. Clears display buffers, resets active flag and sub-state.

**Key logic:**
- Calls FUN_0045bdf0 twice (clear display buffers, docs/07)
- Calls FUN_0049f150(0) (reset display layer)
- Sets param_1+4 = 1 (active flag), param_1+8 = 0 (sub-state)
- Calls FUN_004d82a0 (buffer flush)

**Calls:** FUN_0045bdf0 (clear display), FUN_0049f150 (display layer reset), FUN_004d82a0 (buffer flush)
| FUN_0049f0d0 | OnScreen::Post() | Log + FUN_004d8720 + FUN_0049d150 + FUN_0049b1c0 |

### FUN_0049f0d0 — OnScreen::Post()

OnScreen display manager post-update tick. Called each frame after state transitions.

**Key logic:**
- Debug log entry
- Calls FUN_004d8720 (session state tick)
- Calls FUN_0049d150 (HUD/overlay update)
- Calls FUN_0049b1c0 (display element update)

**Calls:** FUN_004d8720 (session state), FUN_0049d150 (HUD update), FUN_0049b1c0 (display elements)
| FUN_0049f120 | OnScreen::Exit() | Log only |

## hwinput.cpp - Hardware Input Manager (6 functions)
### hwinput.cpp — Hardware Input Manager (6 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_00455bf0 | HWInput::Enter() | Profile trace + cursor hide + control bind init + conditional input device |
| FUN_00455c60 | HWInput::Setup() | Log (if not server) + DirectInput8Create + FUN_0044ee10/4fa60/4fbe/533a0 |

### FUN_00455BF0 — HWInput::Enter()

Hardware input manager entry — hides cursor, initializes control bindings.

**Key logic:**
- Profile entry trace (source: hwinput.cpp)
- Calls FUN_0044f4e0 (cursor initialization)
- Loops ShowCursor(0) until cursor fully hidden
- Calls FUN_00455290 (control binding setup, 43 string names)
- If DAT_007d13a0 (input mode flag) == 1, calls FUN_004f8ae0 (input device init)
- Returns 0

**Calls:** FUN_0044f4e0 (cursor init), FUN_00455290 (control binding), FUN_004f8ae0 (input device)

**Globals:** DAT_007d13a0 (input mode flag)
| FUN_00455d50 | HWInput::Init() | Log (if not server) + FUN_004532d0/533a0/53560 |
| FUN_00455da0 | HWInput::Restart() | Log (if not server) + FUN_0044f680/4f0a0 + FUN_0044ff50 if DAT_007d1ffc + controller detection (param_1+0x1f98, max 0x21, stride 0xb) |
| FUN_00455e70 | HWInput::Post() | Log (if not server) + FUN_0044f070(1) + FUN_004526c0 if param_1[0x665] + FUN_0044fbe0×2 + FUN_0044efe0 + release DirectInput |
### FUN_00455f00 — HWInput::Exit()

Shuts down hardware input subsystem. Releases DirectInput device, cleans up force feedback.

**Key logic:**
- Logs entry
- Calls FUN_0044fbe0 ×2, FUN_0044f5f0, FUN_0044efe0 (DirectInput cleanup)
- Releases DirectInput via vtable call, zeroes param_1
- If DAT_007d13a0 == 1: calls FUN_004f8c90 (force feedback cleanup), sets param_1[0x6c4] = -1

**Calls:** FUN_0044fbe0, FUN_0044f5f0, FUN_0044efe0, FUN_004f8c90

**Moddability:** hardcoded

**New globals:**
- `DAT_007d13a0` — input mode flag (1 = ?)
- `DAT_007d1ffc` — input restart flag
- `DAT_007ce2a0` — DirectInput instance handle
- `DAT_007ce2dc` — DirectInput device
- `DAT_005ec4a4` — input config

## vidman.cpp - Video Manager (6 functions)
### vidman.cpp — Video Manager (6 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_004fa000 | VidMan::Enter() | Log + FUN_00568be0(1) + device detection + if no device: "No Device" + if mismatch: launch 3DCONFIG.EXE via CreateProcessA |
### FUN_004fa2f0 — VidMan::Setup()

Debug-logging-only stub. Returns 0 (success).

**Key logic:**
- Logs "Entered VidMan::Setup()" via FUN_004d7aa0 when debug enabled
- Returns 0 unconditionally
- No actual video setup

**Calls:** FUN_004d7a50 (debug gate), FUN_004d7aa0 (debug log write)
| FUN_004fa320 | VidMan::Init() | Log + display setup (FUN_0053d400/430/410) + FUN_00551fb0 + FUN_0054a1c0 (render state) + FUN_004c55b0 (settings) + scene file load + FUN_00546010 (scene init) + error: "CUBE error loading scene file" |

### FUN_004fa320 — VidMan::Init()

Video manager initialization. Sets up display, render state, and loads scene file.

**Key logic:**
- Sets DAT_008afe70 = 0; configures display mode (FUN_0053d400) with DAT_007cf65c
- Sets display resolution from DAT_007cfbfc (width) and DAT_007cfc20 (height)
- Branches on DAT_007cfb90 (render mode: 1, 2, or 3) → calls FUN_0054a1c0 to set D3D render states
- Resolves scene file path from DAT_008ac48c (current scene index) into SceneArray (DAT_008ac490, stride 0x18c); strips directory to get scene name
- Loads scene via FUN_0053c800; also loads season path from DAT_005ec3d8 + DAT_005ec428
- Calls FUN_00546010(&DAT_008afe88, scenePath, 0) — scene init; if 0 → loads placeholder scene, returns 0
- Error handler prints "CUBE error loading scene file %s: %s"

**Calls:** FUN_0053d400 (display mode), FUN_0054a1c0 (render state), FUN_004c55b0 (settings), FUN_00546010 (scene init), FUN_0053c800 (scene load), FUN_00546230 (scene manager)
| FUN_004fa640 | VidMan::Restart() | Log + FUN_0042d210(0) (pause) + session-specific render state (FUN_0054a200) + race session: formation lap check + FUN_004f9fc0/8f10/9f70 |
| FUN_004fac00 | VidMan::Post() | Profile trace + scene release + render state reset + scene path cleanup |
| FUN_004fad00 | VidMan::Exit() | Log + FUN_00494900 + FUN_0055c040 + FUN_004a1830×2 + FUN_004a14e0 + FUN_0053d4c0 if DAT_008afe64 |

### FUN_004FAC00 — VidMan::Post()

Video manager post-frame — releases scene handle, resets render state, cleans scene path.

**Key logic:**
- Profile entry trace (source: vidman.cpp)
- Calls FUN_004f8ea0 (post-render operations)
- Releases scene via FUN_005461b0(DAT_008afe88), zeros DAT_008afe88
- Resets render state via FUN_0053d400(0)
- Extracts directory from current scene path: indexes SceneArray (DAT_008ac490, stride 0x18c) by CurrentSceneIndex (DAT_008ac48c), strips filename leaving directory
- Calls FUN_0053c900 with extracted directory path

**Calls:** FUN_004f8ea0 (post-render), FUN_005461b0 (scene release), FUN_0053d400 (render state reset), FUN_0053c900 (directory op)

**Globals:** DAT_008afe88 (scene handle), DAT_008ac48c (CurrentSceneIndex), DAT_008ac490 (SceneArray)

**New globals:**
- `DAT_007cf65c` — display mode
- `DAT_007cfb90` — render mode (1/2/3)
- `DAT_007cfbfc` — display width
- `DAT_007cfc20` — display height
- `DAT_007d032c` — display format
- `DAT_007ce5d0` — scene file path
- `DAT_008afe88` — scene handle
- `DAT_008afe70` — vidman state
- `DAT_008afe74` — vidman config
- `DAT_008afe64` — display device handle

## render.cpp - Render Manager (4 functions)
### render.cpp — Render Manager (4 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_004b4030 | Render::Init() | Log only |
| FUN_004b4060 | Render::Restart() | Log + zero 0x1a dwords (render state array) |
| FUN_004b40a0 | (screenshot handler) | Checks for key 0x58 ('X'), saves screen via FUN_00551fd0, displays "Screen Saved" |
### FUN_004b4170 — Render::Post()

Empty post-frame stub. Logs entry only.

**Key logic:**
- Logs entry via FUN_004d7aa0, no other operations

**Moddability:** hardcoded

## camera.cpp - Camera Manager (3 functions)
### camera.cpp — Camera Manager (3 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_0040c920 | CamMan::Init() | Log + FUN_00544f50("MAINVIEW") + clear camera globals (DAT_005ea500–558) + FUN_0040c240/3b0/520 + FUN_0040c140 + FUN_0054a200(0x20,1) |
### FUN_0040c9e0 — CamMan::Restart()

Resets camera manager state. Calls system state init, clears current camera index and flag.

**Key logic:**
- Calls FUN_00408290 (system state init, docs/19)
- Sets param_1+0x38 = -1 (camera index = none)
- Sets param_1+0x2e = 0 (camera flag reset)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2e | Flag | Reset to 0 |
| +0x38 | CameraIndex | Set to -1 (none) |

**Calls:** FUN_00408290 (state init, docs/19)
| FUN_0040cce0 | CamMan::Post() | Log + param_1+8=0 + FUN_004083e0 + release 3 camera objects (param_1+0x18/0x1c/0x20) |

### FUN_0040cce0 — CamMan::Post()

Camera manager post-update. Releases temporary camera objects and resets state.

**Key logic:**
- Clears param_1+0x08 (current camera pointer) to 0
- Calls FUN_004083e0 (camera transform update)
- Releases 3 camera objects at param_1+0x18, +0x1c, +0x20 via vtable dispatch(1) then nulls them
- Sets param_1+0x2e (flag) to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | CurrentCamera | Pointer, cleared to 0 |
| +0x18 | CameraObj1 | Released via vtable |
| +0x1c | CameraObj2 | Released via vtable |
| +0x20 | CameraObj3 | Released via vtable |
| +0x2e | Flag | Set to 0 |

**Calls:** FUN_004083e0 (camera transform)

**Camera struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | MAINVIEW scene node |
| +0x08 | current camera |
| +0x18 | camera object 1 |
| +0x1c | camera object 2 |
| +0x20 | camera object 3 |
| +0x2e | flag |
| +0x38 | camera index (-1 = none) |

## osman.cpp - OS Manager (2 functions)
### osman.cpp — OS Manager (2 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_004a18d0 | OSMan::Enter() | Log + CreateMutexA("F1 Challenge 99-02_APP_MUTEX") + check GetLastError for existing instance |
| FUN_004a1930 | OSMan::Exit() | Profile trace + CloseHandle(mutex) |

### FUN_004A1930 — OSMan::Exit()

OS manager exit — releases application singleton mutex handle.

**Key logic:**
- Profile entry trace (source: osman.cpp)
- Calls CloseHandle(DAT_007ce2d8) — releases "F1 Challenge 99-02_APP_MUTEX"

**Calls:** CloseHandle (Win32 API)

**Globals:** DAT_007ce2d8 (mutex handle)

**Moddability:** hardcoded

**New global:** `DAT_007ce2d8` — mutex handle

## options.cpp - Options Manager (1 function)
### options.cpp — Options Manager (1 function)

| Function | Name | Content |
|----------|------|---------|
| FUN_004a0eb0 | Options::Setup() | Log + if DAT_007ce260==0: menu loop (FUN_004f9f00, FUN_004537b0, FUN_00485b90, FUN_004186f0, FUN_004f9ad0, FUN_00404b60) + if DAT_007ce264!=0: check DAT_005ccfe4 + else: DAT_007c5690=1 |

**New globals:**
- `DAT_007ce260` — options mode flag
- `DAT_007ce264` — options sub-mode
- `DAT_007ce250` — frame counter
- `DAT_007ce25c` — exit flag
- `DAT_005ccfe4` — options sub-flag

## searchgrid.cpp - Scene Extent Calculator (1 function)
### searchgrid.cpp — Scene Extent Calculator (1 function)

**FUN_004bdc10** — Iterates scene nodes, gets bounding boxes (FUN_004dd550),
computes min/max extents. Stores at:
- param_1+0x924 = min x
- param_1+0x928 = scale x (1 / (max_x - min_x))
- param_1+0x92c = min z
- param_1+0x930 = scale z (1 / (max_z - min_z))

Error if no extents found ("Could not get extents of scene").

---

## FUN_0042ce30 — Session Type Name Lookup

Source: session/UI module. Maps session type ID (0–7) to display name. Two formats controlled by param_2 flag.

**Mapping (param_2 == 0, short names):**
| ID | Name |
|----|------|
| 0 | TestDay |
| 1 | Practice1 |
| 2 | Practice2 |
| 3 | Practice3 |
| 4 | Practice4 |
| 5 | Qualify |
| 6 | Warmup |
| 7 | (empty/race) |
| default | Unknown |

**Mapping (param_2 != 0, long names):**
| ID | Name |
|----|------|
| 0 | Test Day |
| 1 | Practice 1 |
| 2 | Practice 2 |
| 3 | Practice 3 |
| 4 | Practice 4 |
| 5 | Qualify |
| 6 | Warmup |
| 7 | (race) |

**Calls:** None (pure switch-table)

**Globals:** None

**Moddability:** No — display name lookup only. Confirms session IDs: 0=TestDay, 1-4=Practice, 5=Qualify, 6=Warmup, 7=Race.

---

## FUN_004216f0 — Config Directory Path Registration

Source: config/module init. Registers all game directory paths and sets default config values. Called during game initialization.

**Registered paths (via FUN_00566650):**
1. `Config.ini`
2. `SeasonData\`
3. `Audio\`
4. `Audio\Vehicle\`
5. `Options\Anim\`
6. `Options\Flags\`
7. `Audio\Options\`
8. `Options\`
9. `Replays\`
10. `Movies\`
11. `Circuits\`
12. `Vehicles\`
13. `Drivers\`
14. (empty)
15. `Save\`
16. `Audio\Music\`
17. (empty — Dev path?)
18. (empty — Dev path?)
19. `DevFiles\CamEd\`
20. `School\`
21. `Audio\Commentary\`
22. (empty — Dev path?)

**Default config settings:**
| Offset | Value | Field |
|--------|-------|-------|
| +0xb8 | 0 | (int) |
| +0xbc | 0 | (int) |
| +0xc0 | 0 | (int) |
| +0xc8 (200) | 1 | (bool) |
| +0xcc | 0 | (int) |
| +0xd0 | 0 | (int) |
| +0xd4 | 0 | (byte) |
| +0xd8 | 1 | (int) |
| +0xdc | 1 | (int) |
| +0xd6 | 0 | (byte) |
| +0xe0 | 0 | (int) |
| +0xd5 | 1 | (byte) |
| +0xe4 | 1 | (int) |
| +0xc4 | 0x16 (22) | (int) |
| +0xe8 | 0xbf800000 (-1.0) | (float, disabled) |

**Calls:** FUN_00566650 (path registry)

**Moddability:** No — config directory setup only.

---

## FUN_0040ddf0 — Cinematic Event State Machine

Source: camera/cinematic module. Manages cinematic event lifecycle (pit exit, race start, finish). State machine: -1/0/1 = idle, 2-5 = active cinematic.

**States:**
| State | Meaning |
|-------|---------|
| -1, 0, 1 | Idle — no cinematic playing |
| 2–5 | Cinematic active — checks if still playing via FUN_0040d4c0 |

When cinematic finishes (FUN_0040d4c0 returns 0): resets counter at param_1[0x26]=0, param_1[0x27]=0, transitions to state 2 (loops back to wait for next completion).

**Calls:** FUN_005679c0 (string search), FUN_0040d4c0 (cinematic check)

**Moddability:** No — camera cinematic system.

---

## FUN_0045b200 — Game Main Entry / Initialization

Source: game module. Top-level game initialization and main loop entry point. Sets up all subsystems then enters the game state machine loop.

**Key logic:**
- Sets `DAT_007c56b0` = 0x3f8353f8 (version float ~1.025)
- Sets `DAT_007c56b4` = "ilya! _1011" (version/watermark string)
- Sets `DAT_007c56ad` = 0
- Sets `DAT_007c56a0` = 3 (session mode)
- Stores param_1 in `DAT_007ce2a0` (application handle)
- Calls initializers in order:
  1. FUN_00423070 (config/cmdline parsing)
  2. FUN_00421cd0 (config.ini loader)
  3. FUN_004d7a00 (session/race init)
  4. FUN_004a0d50 (UI init)
  5. FUN_004b17f0 (networking init)
  6. FUN_00463160 (NetComm cmdline)
- Enters game state machine loop documented in game.cpp (9 functions):
  - FUN_0042d370 (Game::Enter) → FUN_0042d5d0 (Game::Setup)
  - Loops: FUN_0042d6b0 (Init) → FUN_0042d7a0 (Restart) → FUN_0042d8a0 (Post loop) → FUN_0042da30 (Post cleanup) → back to Setup
- On exit: calls FUN_0042db20 (Game::Exit)

**Globals used:**
- `DAT_007c56b0` — version float
- `DAT_007c56b4` — version string "ilya! _1011"
- `DAT_007c56ad` — flag
- `DAT_007c56a0` — session mode
- `DAT_007ce2a0` — application instance handle

**Calls:** FUN_00423070, FUN_00421cd0, FUN_004d7a00, FUN_004a0d50, FUN_004b17f0, FUN_00463160, FUN_0042d370, FUN_0042d5d0, FUN_0042d6b0, FUN_0042d7a0, FUN_0042d8a0, FUN_0042da30, FUN_0042db20

**Moddability:** No — top-level game loop entry.

---

## FUN_0047e960 — Game Options UI Constructor (Allowed/Disallowed/Normal/Time Scaled)

Source: options/settings UI. Creates UI list entries for various game options based on option ID (param_2). Handles:

- **IDs 0x1e4–0x1ee (484–494):** Simple Allow/Disallow options — 2 entries
- **ID 0x1f2 (498):** 2 entries (Normal/???)
- **IDs 499–500:** 8 entries including Normal, 5 detail levels, and seasonal options
- **ID 0x1f5 (501):** 4 entries: Normal, Time Scaled, Selected Season, and one more

**Key logic:**
- Calls FUN_00488b00 to init UI list
- Clears linked list at param_1[0x11] (item list head)
- For each option: calls FUN_00486f30(name, 0xffffffff) to add entry
- Stores param_2 in param_1[0x3d]

**Struct offsets:**
| Offset | Field |
|--------|-------|
| +0x44 (0x11) | UI item list head |
| +0x48 (0x12) | UI item list tail |
| +0x4c (0x13) | Current item |
| +0x50 (0x14) | Item count |
| +0xec (0x3b) | (zero on init) |
| +0xf0 (0x3c) | -1 (end marker) |
| +0xf4 (0x3d) | Option ID |

**Calls:** FUN_00488b00 (UI list init), FUN_00486f30 (add entry), FUN_00587bcf (free)

**Moddability:** No — UI option list builder only.

---

## FUN_00404cc0 — QuickRace / Game Mode Lookup

Source: `game.cpp` or mode selector. Matches input string against 5 game mode names to return mode ID.

**Key logic:**
- Iterates `PTR_PTR_005be6c4` (5 entries, array of mode-name string pointers)
- Calls `FUN_00588410(param_1, name)` for each
- If match found: returns index (0-4)
- If no match: returns 0 (default)

**Calls:** FUN_00588410 (string compare)

**Moddability:** No — game mode string matching only.

---

## FUN_00404f30 — Main Menu Transition

Source: `menu.cpp` or game flow. Transitions to MAIN MENU state.

**Key logic:**
- Calls `FUN_004a0250()` + `FUN_004a03f0()` (menu setup)
- Checks condition via `FUN_00404f10()`:
  - If true: calls `FUN_00497940("MAIN MENU", 0xffffffff)` to load main menu screen
- Calls `FUN_004049d0()` (post-setup)

**Calls:** FUN_004a0250, FUN_004a03f0, FUN_00404f10, FUN_00497940, FUN_004049d0

**Moddability:** No — game flow state transition only.

---

## Pause Menu String Tables (3 functions)

### FUN_004541d0 — PAUSE String Copier

Source: `pause_ui.cpp`. Copies pause menu string by ID to output buffer. Two string tables:

- **IDs 0–0x59 (0–89):** `s_PAUSE_005c4890` — pause-related strings, stride 0x10
- **IDs 0x80–0xD7 (128–215):** `s__EMPTY__005c4e30` — empty/placeholder strings, stride 0x10
- Returns success flag (bit 0 = 1) or failure (0)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0xc88 | Entry count (max) |
| +0xc8c | Current ID |

### FUN_00455200 — PAUSE String Pointer Getter

Simpler variant of FUN_004541d0. Returns pointer to string in same two tables by ID:
- IDs 0–0x59: from `s_PAUSE_005c4890`
- IDs 0x80–0xD7: from `s__EMPTY__005c4e30`
- Default: returns pointer to `DAT_005ea438` (empty string)

### FUN_00455240 — EMPTY String Pointer Getter

Returns pointer from `s__EMPTY__005c44b0` table (stride 9) by ID 0–0x6D. Default: empty string.

**Moddability:** No — UI string table lookups only.

---

## FUN_00404890 — Race Mode Setup / Pre-Race Init

Source: game.cpp. Saves current RaceMode, sets up race session mode and time scale.

**Key logic:**
- Calls FUN_00404850() (load screen/setup)
- If param_1+0x20 != 1: sets flags +0x14=1, +0x15=0 (init pending), returns
- Saves DAT_007d2e44 into param_1+0x50, sets DAT_007d2e44=1
- Saves DAT_007d0410 (RaceMode) into param_1+0x54, sets DAT_007d0410=2
- Clamps DAT_007d0410 between DAT_007d0418 and DAT_007d041c
- Calls FUN_004a0d90() and FUN_0040d360(1,0xf)
- Sets DAT_007d0798 (time acceleration) = 0.05

**Struct offsets:** +0x14 (InitFlag), +0x15 (InitFlag2), +0x20 (StateCondition), +0x50 (Saved_DAT_007d2e44), +0x54 (Saved_RaceMode)

**Calls:** FUN_00404850, FUN_004a0d90, FUN_0040d360

**Moddability:** partial — DAT_007d0798 time scale

---

## FUN_004049d0 — Race Mode Teardown / Post-Race Restore

Source: game.cpp. Restores previous RaceMode after race.

**Key logic:**
- Guard: +0x14 != 0 AND +0x20 == 1
- Restores DAT_007d2e44 and DAT_007d0410 from backups
- Clamps restored RaceMode
- Sets DAT_005ea53e=0, calls FUN_00408450(0.1f)
- If DAT_0059e440 < DAT_007cf380: calls FUN_004c8630

**Struct offsets:** +0x14 (WasInitialized), +0x20 (StateCondition), +0x50 (Saved_DAT_007d2e44), +0x54 (Saved_RaceMode)

**Calls:** FUN_00408450, FUN_004c8630

**Moddability:** no — pure save/restore

---

## FUN_0042c690 — Main Game Tick Update

Source: game_tick.cpp. Per-frame update loop, runs every 10 game ticks with periodic AI/repair/steering updates.

**Key logic:**
- Gate: ScoringGate != 2
- Computes target tick time, caps at 0xC9 ticks
- Loop: every 10 ticks runs AI per vehicle, repair, physics
- Every 400 ticks: AI update on human vehicles
- Every 50 ticks: vehicle tick, safety checks
- If player AIState==0: calls FUN_004bccc0 (player input)
- If DAT_007cbf24 != 0: calls FUN_00451720

**Calls:** FUN_00424e70, FUN_00410980, FUN_004eb430, FUN_004ee2d0, FUN_004ed960, FUN_0042caa0, FUN_004f1c40, FUN_004ed810, FUN_004bccc0, FUN_004d5960, FUN_004d59b0, FUN_004e4930, FUN_00451720, FUN_004109d0

**Moddability:** central game tick

---

## FUN_0045f2b0 — Session UI Element Renderer

Source: session.cpp. Renders named UI element for current player.

**Key logic:**
- If SessionType 7: copies player name from vehicle struct
- Calls FUN_004b33b0(4,2,len,0xff,alpha,1) — create UI element
- Calls FUN_0057a680/FUN_0057a6a0/FUN_0057a690 for render

**Calls:** FUN_004b33b0, FUN_0057a680, FUN_0057a6a0, FUN_0057a690

**Moddability:** session-dependent UI text

---

## FUN_00470040 — Screen/Menu Navigation Controller

Source: session.cpp. Switches screen state based on RaceMode.

**Key logic:**
- If screen data non-null:
- RaceMode 3 or 5: toggle flag, call FUN_00487010(0/1) then FUN_00566650
- Else: set default state

**Calls:** FUN_00487010, FUN_00566650

**Moddability:** screen selection by RaceMode

---

## FUN_004707c0 — Race Mode Screen Setup

Source: session.cpp. Initializes screen view by RaceMode.

**Key logic:**
- Sets +0x324 to RaceMode float
- If DAT_007d122c == 0: default screen via FUN_00487010
- Else: build path from DAT_005c6e50

**Calls:** FUN_00487010, FUN_0058815f, FUN_0048b810

**Moddability:** screen path by config value

---

## FUN_00470960 — Session/Setup Screen Setup

Source: session.cpp. Initializes setup screen.

**Key logic:**
- Sets +0x324, +800 pointer to DAT_007ceaa4 config
- Calls FUN_00487010, builds path, loads screen
- If session active: calls FUN_00477280

**Calls:** FUN_00487010, FUN_0058815f, FUN_0048b810, FUN_00477280

**Moddability:** setup screen via DAT_007ceaa4

---

## FUN_00471440 — Mode-Specific Screen Setup

Source: session.cpp. Loads screen indexed by RaceMode from config array.

**Key logic:**
- Index = RaceMode * 9 into DAT_007cee88 array
- Calls FUN_00487010, builds path, loads screen

**Calls:** FUN_00487010, FUN_0058815f, FUN_0048b810

**Moddability:** screen by index into config array

---

## FUN_00471dc0 — Transmission/AI Difficulty Screen Setup

Source: session.cpp. Loads screen based on transmission type.

**Key logic:**
- Sets +800 pointer to DAT_007d1fd8 (transmission config)
- Calls FUN_00487010 with transmission type

**Calls:** FUN_00487010, FUN_0058815f, FUN_0048b810

**Moddability:** screen via DAT_007d1fd8

---

## FUN_004b87c0 — LoadingPhase1

Source: engine_architecture.cpp. First phase of loading screen.

**Key logic:**
- Computes elapsed time, sets loading active flag
- Loop over vehicles: load texture, copy state
- Calls FUN_004d8840 (audio init), sets ready flag
- Seeds RNG with loading time, loads chunks until total >= duration

**Calls:** FUN_004b7a00, FUN_00566e20, FUN_004e3a50, FUN_004e1970, FUN_004ef5a0, FUN_004b86e0, FUN_004d8840, FUN_00408420, FUN_004b8ae0

**Moddability:** medium — loading flow controlled by DAT_005acd1c

---

## FUN_004b8940 — LoadingPhase2

Source: engine_architecture.cpp. Second phase — restores vehicle states after load.

**Key logic:**
- Seeds RNG with scaled time, loads chunks
- Restores vehicle states from +0x734 array
- Restores textures and appearance variants
- Calls FUN_00411120 (finalize), releases time handle

**Calls:** FUN_00408450, FUN_004b8ae0, FUN_004b86e0, FUN_004ef5a0, FUN_004e19a0, FUN_004e0ed0, FUN_004e3a50, FUN_004c7aa0, FUN_00411120, FUN_004c8dc0, FUN_00566db0

**Moddability:** medium — loading time scaling

---

## FUN_00434460 — Car Selection State Machine

Source: car_select_ui.cpp. Cycles through player car selection states: idle → countdown → selected → done.

**Key logic:**
- State 0: generate initial selection via FUN_00434820
- State 1: countdown, decrement timer, transition to 2 when expired
- State 2: selection confirmed, call FUN_00435240 for continue check
- State 5: completion, return 1
- Default (other states): check input, scan for available vehicles, store index

**Calls:** FUN_00434820, FUN_00435240, FUN_004d8760, FUN_00418b90, FUN_00434d60, FUN_0040c910

**Moddability:** hookable

---

## FUN_0045f030 — Mouse Input Handler

Source: input_mouse.cpp. Processes mouse button events (scancodes 0x1002-0x1005 mapped to buttons 1-4). Checks time threshold _DAT_0059f114 against param_1+900 timer. Reads DAT_007cb218/DAT_007cb21c scancode array. Dispatches via switch.

**Key logic:**
- Guard: timer at +900 >= _DAT_0059f114 and DAT_007ce254 == 0
- Maps: 0x1002→1, 0x1003→2, 0x1004→3, 0x1005→4
- Dispatches to action handler

**Globals:** DAT_007cb218, DAT_007cb21c, DAT_007ce254, _DAT_0059f114

---

## FUN_0042ec00 — Message String Formatter

Source: message.cpp. Formats message string using DAT_005ec4cc (MessageBuffer). Selects format string DAT_005c3738 or DAT_005c3734 based on param_1+4 flag. Calls FUN_00423a00 for string lookup. Falls back to copying default if not found.

**Key logic:**
- Checks param_1+4 flag (0=normal, 1=alternate format)
- Looks up message in string table via FUN_00423a00
- On miss: copies raw string from table
- Calls FUN_0058815f with output buffer param_2 and format template

**Globals:** DAT_005ec4cc (MessageBuffer), DAT_005c3738, DAT_005c3734, DAT_005c3730

**Calls:** FUN_00423a00, FUN_0058815f

---

## FUN_0040be70 — Keyboard Input Action Mapper

Source: input.cpp. Maps keyboard scancodes to game actions. Reads scancode array at DAT_007cb21c with DAT_007cb218 entries. Maps keys: 0x4a=upshift, 0x4e=downshift, 0x9c=lookback, 199=scene/ghost toggle, 0xc9=pause, 0xd1=brake bias adjust, 0xd2=steering assist toggle. Checks player vehicle arcade flag at +0x344c.

**Key logic:**
- Returns 0 if +0x24 flag set (input locked)
- Iterates DAT_007cb218 times over DAT_007cb21c scancode array
- Switch on scancode values:
  - 0x4a: upshift via FUN_0040d290(1)
  - 0x4e: downshift via FUN_0040d290(0)
  - 0x9c: look back via FUN_0040d340
  - 199: toggle scene/ghost mode (checks FUN_0040c720(4))
  - 0xc9: pause (checks arcade flag at player+0x344c)
  - 0xd1: brake bias adjust
  - 0xd2: steering assist toggle
- Sets +0x2c flag when action triggered

**Globals:** DAT_007cb218 (scancode count), DAT_007cb21c (scancode array), DAT_007c54e0 (PlayerVehiclePtr), DAT_007cfe88

**Calls:** FUN_0040d290, FUN_0040d340, FUN_0040c720, FUN_0040cde0

**Moddability:** scancode mapping table at DAT_007cb21c

---

## FUN_00465300 ? Message Dispatch Node Allocator

Source: likely message.cpp. Allocates 0x1b0-byte message nodes and routes to target lists.

**Key logic:**
- Checks type field: >> 0x1d == 1 (system message)
- Sub-type check: >> 0x12 & 0x3f == 0 or 7
- Entity index: & 0xff, must be < 0x68 (104 max)
- Special path for type 1/sub 0/7: calls FUN_00464b40 directly
- General path: allocates 0x1b0 bytes via FUN_004b3a90, enqueues to target list
- Two target lists: input/sensor (+0x6c) or physics (+0x7c), selected by type flag

**Calls:** FUN_00464b40, FUN_004b3a90

**Moddability:** hookable

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00452b10 � Game Object Slot Lookup

Source: Unknown. Matches an object address against ~50 known game global addresses and stores reference.

**Key logic:**
- Compares param_2 against list of DAT_007cxxxx global addresses
- Stores matching address in param_1[7], writes param_3 to *(match + 8)
- If no match: returns -1 and sets param_1[0] to 0
- Calls FUN_00452740(0x59, 0) after successful match (likely sound or event trigger)
- Used for runtime object lookup/dispatch in the game engine

**Calls:** FUN_00452740

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00465d70 � Recursive Linked List Merge Sort

Source: Unknown. Sorts a singly-linked list of game objects using recursive merge sort with priority table.

**Key logic:**
- Finds list midpoint via traversal
- Recursively sorts both halves
- Merges using comparison key: first uint of each node
- Key format: top 3 bits (type, 4=special), bits 12-17 (sub-type, 0/1=special), low 8 bits (priority)
- Comparison uses 104-entry table at DAT_007cd2ac+0xe410
- Special entries (type 4, sub-type 0/1) sort first regardless of value

**Globals:**
- DAT_007cd2ac � base address for sort priority table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00466350 � Camera Yaw/Zoom Controller

Source: Unknown. Controls camera rotation (yaw) and zoom based on player input and game mode.

**Key logic:**
- Early exit if param_1[0x3b] (camera mode flag) is 0
- Gets mouse delta via FUN_00498730, FUN_00498880
- Reads input via FUN_00542420 (joystick/mouse axes)
- Camera flags: +0xf5 (alternate control mode), param_1[0x3d] (free camera)
- Two branches based on DAT_007d0398 (photo/free camera flag):
  - Normal mode: clamps zoom/offset to param_1[0x3f]/[0x40] range
  - Photo mode: wraps yaw with modular arithmetic (DAT_0059e888 = 360�)
- Computes final position with fsin/fcos on yaw angle � distance
- Calls FUN_00541cd0 to set camera transform

**Globals:**
- DAT_007d0398 � photo/free camera mode flag

**Calls:** FUN_00498730, FUN_00498880, FUN_00542420, FUN_00541cd0, FUN_0054b3f0

**Moddability:** configurable (DAT_007d0398)

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00413820 � Cascading Threshold Level Mapper

Source: Unknown. Maps an integer value to a discrete level (0-17) through cascading threshold comparisons.

**Key logic:**
- Requires param_2==0 and param_4==0
- Compares param_3 against threshold globals (DAT_0059e420 through DAT_0059e788)
- Returns level: 0-17 based on which threshold range param_3 falls in
- Stores result in param_1+8, calls FUN_00414180 for secondary value at +0xc
- Thresholds progress from small (DAT_0059e420 � 1.0) upward

**Calls:** FUN_00414180

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00410f60 � Command Dispatch with Array Lookup

Source: Unknown. Dispatches commands (6-bit opcode) to indexed arrays with 0x318/0x328 stride elements.

**Key logic:**
- Extracts 6-bit opcode from *param_2 >> 0x12: cases 1-6
- Each case: validates index, indexes into different arrays in param_1
- Arrays at different base offsets (param_1+0x2c, +0x38, +0x44, +0x50, +0x5c, +0x68)
- Stride 0x318 (792) or 0x328 (808) per element
- On hit: calls FUN_0054b4d0 with 6 extracted float parameters

**Calls:** FUN_0054b4d0

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004c6810 � Recursive Linked List Merge Sort (Float Comparator)

Source: Unknown. Sorts singly-linked list by float key using recursive merge sort.

**Key logic:**
- Same pattern as FUN_00465d70 but compares float at (node_value + 4)
- KEY FUNCTION for comparison: FUN_004c5d30
- Returns merged list head

**Calls:** FUN_004c5d30

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004c2e20 � Recursive Linked List Merge Sort (Float Field Compare)

Source: Unknown. Sorts singly-linked list by float at second field using merge sort.

**Key logic:**
- Same merge sort pattern as FUN_004c6810
- Compares *(float*)(*node + 4) for sorting order

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0045f4a0 — Input Command Dispatch to Entities

Source: unknown. Distributes input commands from input buffer to all active game entities.

**Key logic:**
- Gets input state buffer, loops while input available
- For each entity in list: skips self and checks mode
- If mode != 3 or AI-controlled skip condition passed: dispatches command
- Checks input flags: bit 28, bit 5, byte value
- Second pass for active input state: dispatches per-entity lookups and sub-commands

**Calls:** FUN_004b3b30, FUN_004b3af0, FUN_00461440, FUN_00462310, FUN_00461530, FUN_004614c0, FUN_00462250, FUN_00465300, FUN_00461470, FUN_00462300, FUN_00465460, FUN_00465c30, FUN_004b0170, FUN_0057a730

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_0040c3b0 — Module Asset Path Resolver

Source: Unknown. Resolves a full file path to a module-relative asset path by extracting filename and stripping extension, then loads via module virtual-dispatch.

**Key logic:**
- Checks if module COM object at param_1+0x20 exists; allocates 0x18-byte object if not (FUN_0040b560)
- Reads global `DAT_008ac48c * 0x18c + DAT_008ac490` as module path string pointer
- Extracts filename from path (walks backwards from end to find backslash)
- Strips file extension (removes everything after last '.')
- Replaces the extensionless filename into the path string
- Calls `(**(code **)(**(int **)(param_1 + 0x20) + 4))(modified_path)` to load asset

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x20 | ModuleObject | COM-like module interface pointer |

**Globals:**
- `DAT_008ac48c` — module list index
- `DAT_008ac490` — module list base pointer
- `DAT_005be880` — unknown string constant

**Calls:** FUN_0040b560 (module object allocation)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004bd7f0 — Object Cleanup (Thunk Target FUN_004bd800)

Source: unknown | Confidence: high (Memory/Cleanup pattern)
Clears a 9-element int array/struct and frees non-null sub-pointers at indices 2, 5, 8.

**Key logic:**
- If param_1[2] != 0: calls FUN_00587bcf (free) on it, sets to 0
- Zeroes param_1[0] through param_1[7] (9 int fields total)
- If param_1[5] != 0: calls FUN_00587bcf (free), sets to 0
- If param_1[8] != 0: calls FUN_00587bcf (free), sets to 0
- Pattern matches C++ array-of-struct cleanup or VECTOR-like container destructor

**Calls:** FUN_00587bcf (memory free/dealloc, per docs/08)

**Used by system:** docs/01-engine-architecture.md — generic memory/object cleanup; called when an owning object is destroyed

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00551800 — Conditional Entity Call on Non-Null

Source: unknown | Confidence: high
Conditionally calls FUN_005514a0 if param_1 is non-null. Guard pattern for entity/object method call.

**Key logic:**
- If param_1 != 0: calls FUN_005514a0() with no args
- Null check before dispatch; protects against stale/invalid object pointers

**Calls:** FUN_005514a0 (Flag update with cascade, per decompiled_full_index)

**Used by system:** docs/01-engine-architecture.md — entity lifecycle guard

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_005564b0 — QueryPerformanceCounter Wrapper with Mode Dispatch

Source: unknown | Confidence: high (Timer/Perf pattern)
Timer read function with two modes: direct QPC or alternate timer. Reads param_1 flags at +0x48 (param_1[0x12]).

**Key logic:**
- If *param_1 (flag) == 0: returns 0 immediately (timer not initialized)
- If param_1[0x12] & 1: calls QueryPerformanceCounter, writes HighPart/LowPart to param_2/param_3
- If param_1[0x12] & 2: calls FUN_0055687b(param_2, param_3) (alternate timer source)
- Returns 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00  | ActiveFlag | int | 0 = timer disabled |
| +0x48  | TimerModeFlags | int | bit 0 = QPC mode, bit 1 = alternate mode |

**Calls:** QueryPerformanceCounter (Win32 API), FUN_0055687b (timer finalize/read, per docs/06)

**Used by system:** docs/01-engine-architecture.md — performance timing subsystem

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055be60 — Global Call with Fixed Argument

Calls FUN_00555e50 with param_1 and global DAT_008b8f28. Simple dispatch wrapper.

**Globals:**
- `DAT_008b8f28` — unknown context/state pointer

**Calls:** FUN_00555e50 (unknown)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00561a41 — 2D Array Fill with Stride Support

Source: unknown | Confidence: high (Data fill pattern)
Fills a 2D array/matrix region with constant value. Supports negative stride for reverse fill.

**Key logic:**
- param_6 = starting column offset, param_8 = base pointer (int array)
- param_7 = fill value, param_2 = row count
- Loop: writes param_7 at current position, advances pointer by 1 + stride
- If param_1 >= 0: advances by param_5 extra elements per row
- Row advance (param_1) can be negative (backward fill)
- This supports both regular grid fill and irregular patterns

**Used by system:** docs/01-engine-architecture.md — generic array/table initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00563a30 — Query with Context + Cleanup

Source: unknown | Confidence: high (Engine/Call pattern)
Reads context pointer from param_1 + 0x94, dispatches query, then calls cleanup wrapper.

**Key logic:**
- Reads *(param_1 + 0x94) as context argument
- Calls FUN_00564110(param_3, param_4, context_ptr) — query function
- Calls FUN_005648c0() — cleanup wrapper (→ FUN_005648d0)
- Returns FUN_00564110 result

**Calls:** FUN_00564110 (unknown query), FUN_005648c0 (call wrapper → FUN_005648d0)

**Used by system:** docs/01-engine-architecture.md — query/lookup with context and cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005648c0 — Single Function Call Wrapper

Source: unknown | Confidence: high (Engine/Call pattern)
Calls FUN_005648d0 with *param_1. Simple indirection wrapper.

**Key logic:**
- Reads *param_1 (dereference)
- Calls FUN_005648d0(*param_1)
- No return

**Calls:** FUN_005648d0 (target function — unknown)

**Used by system:** docs/01-engine-architecture.md — indirect call wrapper

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0057a990 — Free Callback Registered Cleanup

Source: unknown | Confidence: high (Memory/Free pattern)
Calls FUN_00587b3e to register/unregister a cleanup callback at label address 0x0057a9a0. Deferred execution pattern.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0057a9a0)
- FUN_00587b3e is MSVC _atexit-like — registers function pointer for deferred/during-unwind execution
- The label address points to inline cleanup code

**Calls:** FUN_00587b3e (deferred function registration, _atexit-like)

**Used by system:** docs/01-engine-architecture.md — atexit-style cleanup registration

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b820 — Object Init with Copy (Socket Close Helper)

Source: unknown | Confidence: high (DataStructure / network pattern)
Calls FUN_00587370 on param_2, returns param_1 untouched. Used as socket close/clenaup wrapper.

**Key logic:**
- Calls FUN_00587370(param_2) — mutex-protected send/close operation
- Returns param_1 (this pointer, pass-through)
- Referenced in network setup/teardown context (per docs/21)

**Calls:** FUN_00587370 (mutex-protected send/close, per docs/21)

**Used by system:** docs/21-audio-network-internals.md — network socket close wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005819c0 — Linked List Destroy with Vtable Destructor Call

Source: unknown | Confidence: high (Memory/Cleanup pattern)
Walks a singly-linked list, calls virtual destructor on each node's data, frees nodes, resets list head/tail/count.

**Key logic:**
- piVar2 = *param_1 (head pointer)
- Loop: while piVar2 != NULL
  - piVar1 = piVar2[1] (next node pointer)
  - If piVar2[2] != 0 (flag byte) AND *piVar2 != NULL (data pointer):
    - Calls vtable destructor: (**(code**)(**(int**)*piVar2 + 4))(1)
    - (vtable at *data_ptr, destructor at vtable+4, called with arg 1)
  - Calls FUN_00587bcf(piVar2) (free node)
  - piVar2 = piVar1 (advance)
- After loop: zeros param_1[0..3] (head, tail, count, capacity)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00  | HeadPtr | int* | Linked list head |
| +0x04  | TailPtr | int* | Linked list tail |
| +0x08  | Count | int | Node count |
| +0x0c  | Capacity | int | Node capacity |

**Calls:** FUN_00587bcf (memory free/dealloc, per docs/08)

**Used by system:** docs/01-engine-architecture.md — generic linked list container destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585770 — Thread-Safe Int Read with Mutex

Source: unknown | Confidence: high (Threading pattern)
Reads an int from struct at +0xec under mutex protection. Handles abandoned mutex (WAIT_ABANDONED = 0x80).

**Key logic:**
- puVar3 = pointer to param_1 + 0xec (target value)
- If mutex handle at param_1+0xf0 is NULL: returns 0 (no mutex available)
- Else: calls WaitForSingleObject(mutex, param_1+0xf4 [timeout])
  - Returns 0 (NULL pointer) if wait failed OR if abandoned (0x80 == WAIT_ABANDONED)
- Reads value at *puVar3 into uVar1
- Calls ReleaseMutex(mutex)
- Returns uVar1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xec  | SharedValue | int | Value read under mutex |
| +0xf0  | MutexHandle | HANDLE | Win32 mutex |
| +0xf4  | WaitTimeout | DWORD | ms timeout for WaitForSingleObject |

**Calls:** WaitForSingleObject, ReleaseMutex (Win32 API)

**Used by system:** docs/01-engine-architecture.md — thread-safe data read

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586560 — Mutex Create/Replace Wrapper

Source: unknown | Confidence: high (System/Threading pattern)
Closes existing mutex handle at +0x54 if +0x5c flag is set, then creates new unnamed mutex.

**Key logic:**
- If *(param_1 + 0x5c) != 0 (flag indicates existing mutex):
  - Calls CloseHandle(*(param_1 + 0x54))
  - If CloseHandle succeeds: sets +0x54 to 0
- Sets up SECURITY_ATTRIBUTES (nLength=12, no descriptor, inheritable)
- Calls CreateMutexA(NULL, FALSE, NULL) — unnamed mutex, not initially owned
- Stores handle at param_1 + 0x54
- If handle non-null: sets flag at param_1 + 0x5c to 1
- Returns flag value (0=failure, 1=success)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x54  | MutexHandle | HANDLE | Win32 mutex handle |
| +0x5c  | MutexValidFlag | byte | 1 = mutex exists |

**Calls:** CloseHandle, CreateMutexA (Win32 API)

**Used by system:** docs/01-engine-architecture.md — thread synchronization mutex management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587a60 — Free Callback Registered Cleanup (2)

Source: unknown | Confidence: high (Memory/Free pattern)
Identical pattern to FUN_0057a990 — registers cleanup callback via FUN_00587b3e at address 0x00587a70.

**Key logic:**
- Calls FUN_00587b3e(&LAB_00587a70)
- Register cleanup function for deferred execution (atexit-like)

**Calls:** FUN_00587b3e (deferred function registration, _atexit-like)

**Used by system:** docs/01-engine-architecture.md — atexit-style cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a323 — Atomic LOCK/UNLOCK with Indirect Call

Source: unknown | Confidence: medium (decompilation degraded — unrecoverable jumptable)
Performs LOCK() / UNLOCK() atomic operations around an indirect function call.

**Key logic:**
- Calls LOCK() — atomic memory barrier / mutex acquire
- Calls UNLOCK() — atomic memory barrier / mutex release
- Indirect call through UNRECOVERED_JUMPTABLE (jumptable not recovered by Ghidra)
- Purpose: thread-safe indirection wrapper, but exact target unknown

**Used by system:** docs/01-engine-architecture.md — synchronization wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058afd8 — TLS Offset Getter (+12)

Source: unknown | Confidence: high (Threading pattern)
Returns Thread Local Storage pointer offset by 12 bytes.

**Key logic:**
- Calls FUN_0058e0c7() — TLS value retrieval with init (per decompiled_full_index)
- Returns TLS_base + 0xc
- Used to access thread-local data at offset 12

**Calls:** FUN_0058e0c7 (TLS value retrieval, per decompiled_full_index)

**Used by system:** docs/01-engine-architecture.md — thread-local storage access

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058ef48 — Conditional Free if Handle Not -1

Source: unknown | Confidence: high (Memory/Cleanup pattern)
Calls FUN_00596888 only if param_1 != -1 (INVALID_HANDLE_VALUE guard).

**Key logic:**
- If param_1 != -1: calls FUN_00596888(param_1, param_2)
- -1 is typically INVALID_HANDLE_VALUE in Win32
- Guard prevents cleanup on invalid/null handle

**Calls:** FUN_00596888 (cleanup/release function — unknown)

**Used by system:** docs/01-engine-architecture.md — resource cleanup with handle validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059964a — Buffer Allocation with Size Rounding

Source: unknown | Confidence: medium (Mem/Alloc pattern — degraded decompilation uses unaff_EBP)
Allocates buffer with size rounded up to next multiple of 32, plus 2 bytes. Uses operator_new.

**Key logic:**
- Calls FUN_0058a5d8 (stack probe / SEH init)
- Reads request size from *(unaff_EBP + 8) (stack variable)
- Rounds up: uVar2 = size | 0x1f (round to next 32)
- If rounded size > 0xfffffffd (overflow): uses original size
- Adds 2 bytes padding: uVar2 = uVar2 + 2
- Overflow guard: if uVar2 < 0, set to 0
- Allocates via operator_new(uVar2)
- Stores result at *(unaff_EBP + 8)
- Calls FUN_005996ae (buffer size management/post-process)

**Calls:** FUN_0058a5d8 (stack probe/SEH init), operator_new (malloc), FUN_005996ae (buffer size management, per decompiled_full_index)

**Used by system:** docs/01-engine-architecture.md — memory allocation utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a728 — Exception Cleanup with Destructor Call

Source: unknown (likely MSVC CRT) | Confidence: high (Except pattern)
C++ exception cleanup function: flushes buffer, calls destructor, restores SEH.

**Key logic:**
- Calls FUN_0058a5d8 (stack probe/SEH init)
- Sets vtable to PTR_FUN_005b9d28
- Calls FUN_005993af(1) — buffer flush / refcount operation
- Calls exception::~exception(this) — destructor on the exception object
- Restores ExceptionList (SEH epilogue)

**Globals:**
- `PTR_FUN_005b9d28` — exception vtable pointer

**Calls:** FUN_0058a5d8 (stack probe), FUN_005993af(1) (buffer flush, per docs/20), exception::~exception (MSVC exception destructor)

**Used by system:** docs/01-engine-architecture.md — C++ exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059af17 — C++ Exception Throw Wrapper

Source: unknown (MSVC CRT) | Confidence: high (Except pattern)
Wraps a C++ exception throw: calls FUN_0059af50 to prepare, then __CxxThrowException_8.

**Key logic:**
- Calls FUN_0059af50(param_1) — exception object setup
- Calls __CxxThrowException_8(local_20, &DAT_005bb890) — MSVC throw with throw info block
- Does not return (throw terminates execution)

**Calls:** FUN_0059af50 (exception prep), __CxxThrowException_8 (MSVC throw)

**Used by system:** docs/01-engine-architecture.md — C++ exception throwing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c40a — SEH Unwind Handler (Free Field)

Source: unknown (MSVC CRT) | Confidence: high (Sys/Unwind pattern)
SEH unwind handler — frees a field from the stack frame during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x5c) (stack frame local)
- Calls FUN_00587bcf() to free the memory
- SEH unwind cleanup action: releases allocated memory when exception propagates through this frame

**Calls:** FUN_00587bcf (memory free/dealloc)

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c582 — SEH Unwind Handler (Free Field at EBP-0x24)

Source: MSVC CRT | Confidence: high
SEH unwind handler — frees a stack frame local during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x24)
- Calls FUN_00587bcf() to free
- Part of C++ object constructor/prologue with allocated member

**Calls:** FUN_00587bcf (memory free/dealloc)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c68e — SEH Unwind Handler (Free Field at EBP+8)

Source: MSVC CRT | Confidence: high
SEH unwind handler — frees an argument or local during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + 8) (stack argument or local)
- Calls FUN_00587bcf() to free
- Part of function that takes an allocated parameter

**Calls:** FUN_00587bcf (memory free/dealloc)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c812 — SEH Unwind Handler (Call FUN_00581880)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_00581880 during exception unwinding.

**Key logic:**
- Calls FUN_00581880() — linked list or buffer cleanup
- Part of a function with C++ object construction on stack

**Calls:** FUN_00581880 (unknown cleanup)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c956 — SEH Unwind Handler (Call FUN_00581c20)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_00581c20 during exception unwinding.

**Key logic:**
- Calls FUN_00581c20() — cleanup function
- Part of function with stack-allocated C++ objects

**Calls:** FUN_00581c20 (unknown cleanup)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cb88 — SEH Unwind Handler (Call FUN_00583050)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_00583050 during exception unwinding.

**Key logic:**
- Calls FUN_00583050() — cleanup function
- Part of function with stack-allocated C++ objects

**Calls:** FUN_00583050 (unknown cleanup)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cd48 — SEH Unwind Handler (Call FUN_005833e0)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_005833e0 during exception unwinding.

**Key logic:**
- Calls FUN_005833e0() — cleanup function
- Part of function with stack-allocated C++ objects

**Calls:** FUN_005833e0 (unknown cleanup)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cf03 — SEH Unwind Handler (Call FUN_005833e0, duplicate)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_005833e0 during exception unwinding. Same target as Unwind_0059cd48.

**Key logic:**
- Calls FUN_005833e0() — cleanup function
- Shares cleanup target with Unwind_0059cd48 (same function, different frame)

**Calls:** FUN_005833e0 (unknown cleanup)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d070 — SEH Unwind Handler (Call FUN_0047aa60)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_0047aa60 during exception unwinding.

**Key logic:**
- Calls FUN_0047aa60() — cleanup function (renderer/UI domain)
- Part of renderer/UI function with stack-allocated objects

**Calls:** FUN_0047aa60 (unknown cleanup — in renderer address range)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d1e8 — SEH Unwind Handler with Exception Cleanup

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_00599796 with frame-local and global DAT_008d42d8.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x10) (stack local)
- Calls FUN_00599796(local_ptr, &DAT_008d42d8) — paired cleanup with static descriptor
- Part of function with C++ auto object requiring cleanup

**Globals:**
- `DAT_008d42d8` — cleanup descriptor/type info block

**Calls:** FUN_00599796 (cleanup with type descriptor)

**Used by system:** docs/01-engine-architecture.md — SEH unwind with C++ destructor dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d427 — SEH Unwind Handler (Call FUN_00598c70)

Source: MSVC CRT | Confidence: high
SEH unwind handler — calls FUN_00598c70 during exception unwinding.

**Key logic:**
- Calls FUN_00598c70() — cleanup function (locale/CRT related)
- Part of function with locale/stream stack objects needing cleanup

**Calls:** FUN_00598c70 (unknown cleanup — likely locale/stream)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d6ff — Flag Set with Boolean-to-Float Conversion

Source: unknown | Confidence: high (GameLogic pattern)
Sets a byte flag at EBX+0x1065 and writes 0.0 or 1.0 (0x3f800000) at EBX+0x3584 based on flag value.

**Key logic:**
- Writes in_AL (boolean byte) to *(unaff_EBX + 0x1065)
- If in_AL == 0: writes 0 to *(unaff_EBX + 0x3584)
- If in_AL != 0: writes 1.0f (0x3f800000) to *(unaff_EBX + 0x3584)
- Calls FUN_004c7774() — post-update callback/notification
- Boolean-to-float conversion: enables/disables a feature with float parameter

**Struct offsets:**
| Offset | Field (suggested) | Type | Notes |
|--------|-------------------|------|-------|
| +0x1065 | BoolFlag | byte | Toggle flag |
| +0x3584 | FloatParam | float | 0.0 or 1.0 |

**Calls:** FUN_004c7774 (post-update callback — unknown)

**Used by system:** docs/01-engine-architecture.md — game logic flag toggling

**Moddability:** configurable (controls float parameter via boolean)

<!-- target: docs/20-math-utilities.md -->

## FUN_00461f90 — Conditional Network/System Dispatch

Source: unknown | Confidence: high (game_logic)
Checks value at *param_1 + 0x1b79c; if non-zero, calls FUN_00563e70 and potentially FUN_00563df0.

**Key logic:**
- If *(int*)(*param_1 + 0x1b79c) != 0:
  - Calls FUN_00563e70() — query/status check
  - If non-zero: calls FUN_00563df0() — dispatch action

**Calls:** FUN_00563e70 (query), FUN_00563df0 (action dispatch)

**Used by system:** docs/01-engine-architecture.md — conditional system dispatch

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004bd800 — Struct Cleanup (9 fields)

Same as FUN_004bd7f0. Frees sub-pointers at indices 2, 5, 8. Zeroes all 9 fields. [PARTIAL — identical to FUN_004bd7f0 at +0x10 bytes]

<!-- target: docs/20-math-utilities.md -->

## FUN_00581820 — Linked List Destroy + CloseHandle

If flag at param_1+0x18 (6th field) set: calls CloseHandle(param_1[4]). Walks linked list at *param_1, frees inner data and nodes via FUN_00587bcf. Zeros 4 list fields.

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586000 — Linked-List Node Append

Allocates 0xc-byte node via operator_new. Sets *node=param_2, [1]=0, flag at +8=param_3. Appends to tail of param_1 list. Increments count at param_1[3]. Returns combined status.

<!-- target: docs/20-math-utilities.md -->

## FUN_00551810 — Conditional Dispatch by Flag

Source: unknown | Confidence: high
Conditionally calls FUN_00551210 if param_1 (flag/pointer) is non-null.

**Key logic:**
- If param_1 != 0: call FUN_00551210
- Else: return immediately
- Used for conditional execution gated by a flag or pointer validity

**Calls:** FUN_00551210 — (lookup needed)

**Used by system:** docs/01-engine-architecture.md — engine dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00556510 — Performance Counter Timer with Scaling

Source: unknown | Confidence: high
Wraps QueryPerformanceCounter to compute elapsed time as float with scaling.

**Key logic:**
- Reads 64-bit counter from param_1[8..9] (previous timestamp, two uint32s)
- Calls FUN_005564b0 (QPC wrapper) to get new timestamp into local_1c/local_18
- Stores new timestamp back to param_1[8..9]
- Computes elapsed: (new_high - old_high - borrow) * scale + (new_low - old_low) / freq
  where borrow = 1 if new_low < old_low (64-bit subtraction)
- Scale factor from param_1[2] (double), frequency from param_1[0] (uint32)
- Returns float10 (x87 extended precision)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Frequency | uint32 | Performance counter frequency |
| +0x08 | ScaleFactor | double | Multiplier for elapsed high part |
| +0x20 | TimestampLow | uint32 | Previous counter low |
| +0x24 | TimestampHigh | uint32 | Previous counter high |

**Calls:** FUN_005564b0 — QPC wrapper returning 64-bit timestamp

**Used by system:** docs/01-engine-architecture.md — engine timing subsystem

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00558cf0 — Bounds-Checked Array Write (0x80 stride)

Source: unknown | Confidence: high
Writes a value into an array slot with stride 0x80, bounds-checked against a count field.

**Key logic:**
- Reads count from param_1 + 0x2c (array length cap)
- If param_2 (index) < count: writes param_3 to array_base + param_2 * 0x80 + 0xc
- Array base at param_1 + 0x34 (pointer to buffer)
- Stride 0x80 = 128 bytes per slot; offset 0xc within slot for the data field
- If index out of bounds: no-op (silent guard)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x2c | SlotCount | int32 | Number of slots in array |
| +0x34 | SlotArray | int32* | Pointer to array with 0x80 stride |

**Used by system:** docs/01-engine-architecture.md — data container management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055bf70 — Array of Pointers Cleanup with Free Loop

Source: unknown | Confidence: high
Iterates an array of pointers, calling cleanup and free on each non-null entry, then nulls them.

**Key logic:**
- Reads count from param_1 + 0x4 (element count)
- Loops i = 0 to count-1:
  - Calls FUN_0055bba0 (linked-list free) on each array entry structure
  - Reads pointer at param_1 + 8 + i*4
  - If non-null: calls FUN_00557470 (no-op stub) then FUN_00587bcf (free wrapper)
  - Nulls the pointer
- After loop: param_1[2..] all zero

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | ElementCount | int32 | Number of elements in pointer array |
| +0x08 | PointerArray[0] | int32* | Start of pointer array |

**Calls:**
- FUN_0055bba0 — Linked-list free with traversal
- FUN_00557470 — No-op stub
- FUN_00587bcf — Free wrapper (calls FUN_0058aa6f)

**Used by system:** docs/01-engine-architecture.md — object destruction/cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00566cc0 — Conditional Dispatch Based on Flag

Source: unknown | Confidence: high
Dispatches to one of two function paths based on a flag at param_1[4].

**Key logic:**
- If param_1[4] == 0: calls FUN_00587ca0(param_2, param_3, *param_1)
  — FUN_00587ca0 is file read char-by-char (IO)
- If param_1[4] != 0: calls FUN_005351d0(param_3)
  — FUN_005351d0 is arithmetic/comparison

**Calls:**
- FUN_00587ca0 — File read until newline (IO)
- FUN_005351d0 — Arithmetic/comparison (math_util)

**Used by system:** docs/01-engine-architecture.md — entity dispatch / mode routing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00568c60 — Timer Reset Using QueryPerformanceCounter

Source: unknown | Confidence: high
Resets a performance counter timer, optionally re-querying the system counter.

**Key logic:**
- If *param_1 (timer enabled flag) != 0:
  - Checks byte flag at param_1 + 0x12 bit 0: if set, queries QueryPerformanceCounter
  - Stores new QPC timestamp in param_1[6..7]
  - Zeros accumulated time: param_1[0xc..0xd] = 0
  - Zeros elapsed time: param_1[0xa..0xb] = 0
  - Copies new timestamp to last-sample: param_1[8..9] = param_1[6..7]
  - Zeros other accumulators: param_1[4..5] = 0
- If disabled: no-op

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Enabled | int32 | Non-zero = timer active |
| +0x48 | FlagByte | byte | Bit 0 = re-query QPC on reset |
| +0x18 | CurrentLow | uint32 | QPC low part |
| +0x1c | CurrentHigh | uint32 | QPC high part |
| +0x20 | LastLow | uint32 | Previous sample low |
| +0x24 | LastHigh | uint32 | Previous sample high |
| +0x28 | AccumLow | uint32 | Accumulated time low |
| +0x2c | AccumHigh | uint32 | Accumulated time high |
| +0x10 | OtherAccum0 | int32 | Zeroed on reset |
| +0x14 | OtherAccum1 | int32 | Zeroed on reset |

**Calls:** QueryPerformanceCounter (Win32 API)

**Used by system:** docs/01-engine-architecture.md — engine timing / profiling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0056d880 — Zero-Fill Arrays and Call Init Routine Repeatedly

Source: unknown | Confidence: high
Zero-fills a series of 8-byte blocks then calls an initialization routine multiple times.

**Key logic:**
- Outer loop: iterates through param_2[] pointers (count = param_3)
- Inner loop: zero-fills each pointer's buffer with param_3 elements of 8 bytes each
- After zero-fill: calls FUN_00568fb0 on each param_2 pointer, *param_1 times
- Two-stage init: memory clear first, then repeated init calls

**Calls:** FUN_00568fb0 — (init routine, called *param_1 times per element)

**Used by system:** docs/01-engine-architecture.md — data structure initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a4c0 — VTable Destructor Then Null Pointer

Source: unknown | Confidence: high
Calls two virtual destructor methods on an object via vtable, then nulls the pointer.

**Key logic:**
- If *param_1 (object pointer) is non-null:
  - Calls virtual method at vtable+0x4c (likely first-phase destructor)
  - Calls virtual method at vtable+0x44(1) (likely second-phase/deleting destructor)
  - Sets *param_1 = 0 (null the pointer)
- Standard C++ deletion pattern: ~dtor() then operator delete()

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ObjectPtr | void* | Pointer to object with vtable |

**Used by system:** docs/01-engine-architecture.md — object lifecycle management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057aa10 — Single Function Call Wrapper

Source: unknown | Confidence: high
Wrapper that simply forwards to FUN_004b3db0.

**Key logic:**
- Calls FUN_004b3db0 with no arguments
- Returns void

**Calls:** FUN_004b3db0 — (lookup needed)

**Used by system:** docs/01-engine-architecture.md — engine call dispatch

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00581a20 — Handle Close + Linked-List Destruction with VTable Release

Source: unknown | Confidence: high
Closes a Win32 handle, then iterates a linked list calling virtual destructors and freeing each node.

**Key logic:**
- If flag at param_1[6] (byte) != 0: calls CloseHandle on param_1[4], nulls the handle
- Walks linked list starting from *param_1:
  - For each node: reads next pointer, checks if data pointer (*piVar2) is non-null and flag byte is set
  - If valid: calls virtual destructor at vtable+4 (method index 1) with argument 1
  - Calls FUN_00587bcf (free) on the node
- Zeros all fields in param_1[0..3]

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ListHead | void* | Linked list head pointer |
| +0x10 | Handle | HANDLE | Win32 handle to close |
| +0x18 | HandleFlag | byte | Non-zero = handle active |

**Calls:**
- CloseHandle (Win32 API)
- FUN_00587bcf — Free wrapper

**Used by system:** docs/01-engine-architecture.md — object destruction / resource cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583650 — Single Function Call Wrapper

Source: unknown | Confidence: high
Forwarding wrapper that calls FUN_004b0170.

**Key logic:**
- Calls FUN_004b0170 with no arguments

**Calls:** FUN_004b0170 — (lookup needed)

**Used by system:** docs/01-engine-architecture.md — engine dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585860 — Single Field Setter (Returns 1)

Source: unknown | Confidence: high
Writes a value to offset +0x60 in a struct and returns 1.

**Key logic:**
- param_1 + 0x60 = param_2 (field write, 4 bytes)
- Always returns 1 (success indicator)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x60 | SomeField | int32/ptr | Written with param_2 |

**Used by system:** docs/01-engine-architecture.md — entity property setter

**Moddability:** configurable — field write, caller provides value

<!-- target: docs/01-engine-architecture.md -->

## FUN_005865c0 — Create Mutex via Win32 API

Source: unknown | Confidence: high
Creates a Win32 mutex with SECURITY_ATTRIBUTES, closing any existing handle first.

**Key logic:**
- If flag at param_1 + 0x24 is set: calls CloseHandle on existing handle at param_1 + 0x1c, nulls it
- Sets up SECURITY_ATTRIBUTES: nLength=0xc, NULL descriptor, bInheritHandle=TRUE
- Calls CreateMutexA(NULL, FALSE, NULL) — unnamed mutex, not initially owned
- Stores returned handle at param_1 + 0x1c
- Sets flag at param_1 + 0x24 to 1 on success
- Returns the flag (0=fail, 1=success)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1c | MutexHandle | HANDLE | Stored mutex handle |
| +0x24 | MutexActive | byte | Non-zero = mutex created |

**Calls:** CreateMutexA, CloseHandle (Win32 API)

**Used by system:** docs/01-engine-architecture.md — threading / synchronization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005870e0 — Field Reset with Sub-Call

Source: unknown | Confidence: high
Resets several struct fields to default/empty values after calling a sub-routine.

**Key logic:**
- Calls FUN_00587500 (sub-init/cleanup)
- Sets param_1 + 0x14 = -1 (0xffffffff, sentinel)
- Sets param_1 + 0x10 = 0
- Sets param_1 + 0x18 = 0 (byte)
- Sets param_1 + 0x19 = 0 (byte)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | FieldA | int32 | Reset to 0 |
| +0x14 | Sentinel | int32 | Reset to -1 |
| +0x18 | Flag1 | byte | Reset to 0 |
| +0x19 | Flag2 | byte | Reset to 0 |

**Calls:** FUN_00587500 — (sub-routine, called first)

**Used by system:** docs/01-engine-architecture.md — struct initialization/reset

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587a90 — Single Function Call Wrapper

Source: unknown | Confidence: high
Forwarding wrapper that calls FUN_00599958.

**Key logic:**
- Calls FUN_00599958 with no arguments

**Calls:** FUN_00599958 — (lookup needed)

**Used by system:** docs/01-engine-architecture.md — engine dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a331 — SEH Unwind Handler (RtlUnwind)

Source: unknown | Confidence: high
MSVC SEH unwind handler that calls RtlUnwind to perform stack unwinding.

**Key logic:**
- Saves current ExceptionList
- Calls RtlUnwind(param_1, 0x58a359, param_2, NULL)
- Clears ExceptionFlags bit 1 (0xfffffffd mask)
- Restores ExceptionList from saved pointer
- Standard MSVC exception handler pattern

**Calls:** RtlUnwind (NTDLL API)

**Used by system:** docs/01-engine-architecture.md — SEH / exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058b59f — GetSystemTimeAsFileTime to 64-bit Tick

Source: unknown | Confidence: high
Converts GetSystemTimeAsFileTime to a 64-bit tick value stored in a global.

**Key logic:**
- Calls GetSystemTimeAsFileTime to get 100-ns intervals since Jan 1, 1601
- Uses __allmul to combine dwHighDateTime * 0x100000000 + dwLowDateTime into 64-bit
- Stores result in global DAT_008d3ec0 (64-bit system timestamp)

**Globals:**
- `DAT_008d3ec0` — 64-bit system timestamp tick (new global)

**Calls:** GetSystemTimeAsFileTime (Win32 API), __allmul (MSVC CRT)

**Used by system:** docs/01-engine-architecture.md — system time retrieval

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058ef5f — Increment Wrapper Around Call Loop

Source: unknown | Confidence: high
Increments a counter and loops calling a function until it returns false.

**Key logic:**
- Increments *param_1 (counter at pointer)
- Calls FUN_0058ef2e(param_2) returning a value
- Calls FUN_00589bf3 on that value (check/condition test)
- Loops while condition returns non-zero
- Returns the last value from FUN_0058ef2e

**Calls:**
- FUN_0058ef2e — (lookup needed)
- FUN_00589bf3 — (lookup needed, condition test)

**Used by system:** docs/01-engine-architecture.md — engine dispatch / polling loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00595a61 — Critical Section Enter with Lazy Init

Source: unknown | Confidence: high
Enters a Win32 critical section selected by hash of a key, initializing it lazily on first use.

**Key logic:**
- Computes hash: slot = param_1 & 0x1f, array_idx = param_1 >> 5
- Address: DAT_008d4920[array_idx] + slot * 0x24 (stride 0x24 per CS)
- If CS initialized flag at +0x08 == 0:
  - Calls FUN_0058dfea(0x11) (lock/disable interrupts?)
  - Re-checks flag to avoid race condition
  - Calls InitializeCriticalSection at +0x0c
  - Increments flag
  - Calls FUN_0058e04b(0x11) (unlock)
- Enters the critical section via EnterCriticalSection

**Globals:**
- `DAT_008d4920` — Array of critical section structures (stride 0x24 per entry)

**Struct layout (per slot at DAT_008d4920 + idx * stride + slot * 0x24):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x08 | InitFlag | int32 | 0 = uninitialized |
| +0x0c | CriticalSection | CRITICAL_SECTION | Win32 CS object |

**Calls:**
- InitializeCriticalSection, EnterCriticalSection (Win32 API)
- FUN_0058dfea(0x11) — pre-lock function
- FUN_0058e04b(0x11) — post-unlock function

**Used by system:** docs/01-engine-architecture.md — threading / synchronization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005986ec — Single Function Call Wrapper

Source: unknown | Confidence: high
Forwarding wrapper that calls FUN_00587b3e with a static address.

**Key logic:**
- Calls FUN_00587b3e(&LAB_005986f8) — passes address of nearby code/data

**Calls:** FUN_00587b3e — Boolean-to-int conversion helper (math_util)

**Used by system:** docs/01-engine-architecture.md — engine dispatch

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059cf0b — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00586170 as cleanup.

**Key logic:**
- Calls FUN_00586170 with no arguments

**Calls:** FUN_00586170 — (cleanup handler)

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d07b — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_0047aa60 as cleanup.

**Key logic:**
- Calls FUN_0047aa60 with no arguments

**Calls:** FUN_0047aa60 — math_util (short computation)

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d1f8 — SEH Unwind Release Locale Refcount

Source: unknown | Confidence: high
SEH unwind handler that releases a locale object reference count.

**Key logic:**
- Reads locale pointer from stack EBP-0x10
- Calls FUN_00599796(localePtr, DAT_008d43c8) — locale refcount decrement

**Globals:**
- `DAT_008d43c8` — locale management structure

**Calls:** FUN_00599796 — locale refcount release

**Used by system:** docs/01-engine-architecture.md — SEH / locale management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d43c — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00599d17 as cleanup.

**Key logic:**
- Calls FUN_00599d17 with no arguments

**Calls:** FUN_00599d17 — (cleanup handler)

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d7b5 — Single Function Call Wrapper

Source: unknown | Confidence: high
Forwarding wrapper that calls FUN_0043fffb.

**Key logic:**
- Calls FUN_0043fffb with no arguments

**Calls:** FUN_0043fffb — (lookup needed)

**Used by system:** docs/01-engine-architecture.md — engine dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d240 — Game State Dispatch Chain

Source: unknown | Confidence: high
Chains multiple game state/system calls in sequence.

**Key logic:**
- Calls FUN_0042bbd0(param_1) — game state logic
- Calls FUN_0040c7a0() — game state logic
- Calls FUN_0040c650(param_1) — references game state
- Calls FUN_0040d090() — math_util (short computation)
- Calls FUN_0041a0c0(param_1) — game state logic
- Calls FUN_004d8760(1, 0) — unidentified logic

**Calls:** Multiple game state functions (per triage index)

**Used by system:** docs/01-engine-architecture.md — game state management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a781 — Exception Object Constructor (Copy String)

Source: unknown | Confidence: high
MSVC exception object constructor — copies string data and sets up vtable.

**Key logic:**
- Calls FUN_0058a5d8 (SEH prolog)
- Gets string from stack offset +8
- Calls FUN_0059bf56(iVar2) — copy string data
- Reads character from string +0xc
- Increments refcount via FUN_005993af(0)
- Calls FUN_0059a9ca(string+0xc, 0, DAT_005b9c38) — locale-aware string init
- Sets vtable to PTR_FUN_005b9d28 (exception vtable)
- SEH epilog

**Calls:**
- FUN_0058a5d8 — SEH prolog
- FUN_0059bf56 — string copy helper
- FUN_005993af — refcount increment
- FUN_0059a9ca — string/encoding setup
- DAT_005b9c38 — locale constant

**Used by system:** docs/01-engine-architecture.md — exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c698 — SEH Unwind with Field Free

Source: unknown | Confidence: high
SEH unwind handler that frees a struct field pointer from the stack.

**Key logic:**
- Reads pointer from stack EBP+8
- Calls FUN_00587bcf (free wrapper) on it

**Calls:** FUN_00587bcf — Free wrapper

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c81a — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_005818e0 as cleanup.

**Key logic:**
- Calls FUN_005818e0 with no arguments

**Calls:** FUN_005818e0 — (cleanup handler)

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c964 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_0047a800 as cleanup.

**Key logic:**
- Calls FUN_0047a800 with no arguments

**Calls:** FUN_0047a800 — math_util (short computation)

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050fdf3 — OS Version Detection (GetVersionEx)

Source: unknown | Confidence: high
Detects Windows version and CPU feature support via GetVersionExA.

**Key logic:**
- Calls GetVersionExA (OSVERSIONINFOA)
- Checks dwPlatformId: 1=Win9x, 2=NT
- Win9x: checks for IE4+ (build >= 0x55d)
- WinNT: calls IsProcessorFeaturePresent for features 6, 7, 10
- Feature 10 (SSE): checks via FUN_0050fd4e bit 3
- Returns feature flag or 0

**Calls:** GetVersionExA, IsProcessorFeaturePresent, FUN_0050fd4e, FUN_0050fd16

**Used by system:** docs/01-engine-architecture.md — platform detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005502c0 — Destructor with Conditional Free + Flag Clear

Source: unknown | Confidence: medium
Destructor/cleanup method. Frees a sub-object if allocated, then resets flag field.

**Key logic:**
- Checks if `*(int *)(param_1 + 0x54) != 0` — sub-object pointer exists
- If set: calls FUN_00542e50 (unknown, 36-line function), then checks pointer again
- If pointer still non-null: calls FUN_00557470 (empty no-op stub), then FUN_00587bcf (free/operator delete)
- Zeroes the pointer at `param_1 + 0x54`
- Sets `*(byte *)(param_1 + 4) = 0` — flag/boolean field clear
- Returns 0

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x04 | unknown | byte | Flag/state field, cleared to 0 |
| +0x54 | unknown | int | Pointer to sub-object, conditionally freed |

**Calls:**
- FUN_00542e50 — unknown (methodology doc, 36 lines)
- FUN_00557470 — empty no-op stub (triage index line 6346, docs/20)
- FUN_00587bcf — free/operator delete (docs/09, docs/19, docs/21)

**Used by system:** docs/01-engine-architecture.md — destructor for a game engine object with dynamically allocated sub-resource

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00551830 — Wide-String Comparison Walking Linked List

Source: unknown | Confidence: high
Traverses a linked list of nodes, comparing wide-character (UTF-16) strings against a search key. Returns matching node or null.

**Key logic:**
- Reads linked list head from `*(int *)(param_1 + 0x13c)` — list root pointer
- Iterates via `next` pointer at offset +0x24
- For each node: reads string pointer from `*(int *)(iVar2 + 0x1c) + 0x1c` — wide string at inner offset +0x1c
- Performs wide-character comparison (2-byte per char) by iterating through pairs of bytes
- Comparison logic: returns negative/zero/positive like `wcscmp`
- On match (iVar4 == 0): returns node pointer
- On mismatch: follows +0x24 next pointer
- Returns 0 if list exhausted

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x13c | unknown | int | Linked list head pointer |

**Called by:** Lookup/search within a collection of named objects

**Used by system:** docs/01-engine-architecture.md — generic linked-list search with wide-string key matching, likely resource/asset lookup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00553db0 — Struct Init with Default Values

Source: unknown | Confidence: high
Initializes 8 contiguous fields in a struct starting at offset +0x20.

**Key logic:**
- Sets `*(int *)(param_1 + 0x20) = 7` — primary field, likely count/type/mode
- Sets 7 fields at offsets +0x24, +0x30, +0x28, +0x2c, +0x34, +0x38, +0x3c to 0
- Note: +0x20 is set to 7, but offsets are not strictly sequential (gaps at +0x28 sequential but +0x30 after +0x24)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x20 | unknown | int | Set to 7 — default mode/count |
| +0x24 | unknown | int | Zeroed |
| +0x28 | unknown | int | Zeroed |
| +0x2c | unknown | int | Zeroed |
| +0x30 | unknown | int | Zeroed |
| +0x34 | unknown | int | Zeroed |
| +0x38 | unknown | int | Zeroed |
| +0x3c | unknown | int | Zeroed |

**Used by system:** docs/01-engine-architecture.md — struct initialization, likely constructor helper for an engine object

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055bff0 — Array Slot Check + Conditional Call

Source: unknown | Confidence: medium
Checks if array slot occupied; if so, dispatches render call and records slot index.

**Key logic:**
- Checks `param_1[param_2 + 2] != 0` — slot at index param_2 allocated
- If occupied: calls FUN_0055bd20 (render command matching, docs/19)
- If FUN_0055bd20 returns 0: stores `*param_1 = param_2`, returns 0
- Otherwise returns 0xffffffff (-1)

**Calls:**
- FUN_0055bd20 — render command matching and dispatch (docs/19)

**Used by system:** docs/01-engine-architecture.md — render slot manager

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055f060 — GlobalMemoryStatus Wrapper

Source: unknown | Confidence: high
Thin wrapper around Win32 GlobalMemoryStatus. Info-only call.

**Key logic:**
- Sets `_MEMORYSTATUS.dwLength = 32`
- Calls `GlobalMemoryStatus(&local_20)`
- Result discarded

**Calls:**
- GlobalMemoryStatus — Win32 kernel32 API

**Used by system:** docs/01-engine-architecture.md — system memory check during init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00564930 — Accumulator with Realloc on Growth

Source: unknown | Confidence: medium
Accumulates size value and reallocates buffer when accumulated size exceeds current allocation.

**Key logic:**
- Reads current accumulated size at `*(int *)(param_1 + 4)` and addend at `*(int *)(param_1 + 0xc)`
- Adds them: `newSize = oldSize + addend`
- Stores new accumulated size back at +0x04
- Calls FUN_0058b5d4(current_buffer, elem_size * newSize) — realloc with new total size
- Stores result back at +0x14

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | accumSize | int | Current accumulated count |
| +0x08 | elemSize | int | Size per element |
| +0x0c | addend | int | Amount to add |
| +0x14 | buffer | int | Pointer to allocated buffer |

**Calls:**
- FUN_0058b5d4 — memory reallocation wrapper (docs/06)

**Used by system:** docs/01-engine-architecture.md — dynamic buffer growth

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00568cb0 — QPC Timestamp Read Wrapper

Source: unknown | Confidence: high
Conditionally reads QPC timestamp into two output parameters.

**Key logic:**
- Checks `*param_1 != 0` AND `(*(byte *)(param_1 + 0x12) & 1) != 0`
- If both true: QueryPerformanceCounter, writes HighPart/LowPart
- Always returns 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | enabled | int | Master enable flag |
| +0x12 | flags | byte | Bit 0 enables timestamp capture |

**Calls:**
- QueryPerformanceCounter — Win32 kernel32 API

**Used by system:** docs/01-engine-architecture.md — conditional QPC timestamp for profiling/timing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0056ead0 — Linear Search with Large Struct Stride

Source: unknown | Confidence: high
Linear search through array of 0x244-byte structs, comparing key string to each element.

**Key logic:**
- Count from `*param_1`, base from `param_1[1]`
- Stride 0x244 (580 bytes) per element
- FUN_00588410 (byte strcmp) on param_2 vs each element start
- Match returns `index * 0x244 + base`
- Returns 0 if no match

**Calls:**
- FUN_00588410 — byte string compare (docs/06)

**Used by system:** docs/01-engine-architecture.md — string-keyed object registry lookup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a4f0 — Virtual Function Dispatch with Stack Frames

Source: unknown | Confidence: medium
Complex virtual dispatch with SEH prologue/epilogue, multiple vtable calls, stack frame copy, flag manipulation.

**Key logic:**
- Reads byte at (stack_param + 0x2b) into flags
- Calls FUN_00585860 (field setter)
- Reads byte from same location again
- Calls vtable+0x68 virtual method on `*param_1`
- Copies 12 dwords stack→local array
- Calls FUN_00585030 (allocation wrapper)
- Calls vtable+0xc0 virtual method
- Clears `*(byte *)(*param_1 + 0x5d) = 0`
- Calls FUN_00584ff0 (string copy)

**Calls:**
- FUN_00585860 — field setter (triage index)
- FUN_00585030 — allocation wrapper (triage index)
- FUN_00584ff0 — string copy (triage index)

**Used by system:** docs/01-engine-architecture.md — virtual dispatch with marshaling, likely command handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057aa70 — Cleanup Wrapper with SEH

Source: unknown | Confidence: high
Thin wrapper calling FUN_00587b3e with a structured exception handler address.

**Key logic:**
- Calls `FUN_00587b3e(&LAB_0057aa80)` — passes address of SEH handler block
- FUN_00587b3e performs boolean-to-int conversion (returns (FUN_00587ac0() != 0) - 1)

**Calls:**
- FUN_00587b3e — boolean-to-int conversion wrapper (triage index)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup wrapper, likely called during exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00583660 — Float Set with Timing Call

Source: unknown | Confidence: high
Sets a float/uint field and calls timer reset function.

**Key logic:**
- Sets `*param_1 = param_2` — stores incoming value
- Calls `FUN_00568c60()` — timer reset using QueryPerformanceCounter (triage index)

**Calls:**
- FUN_00568c60 — timer reset using QPC (triage index line 6519)

**Used by system:** docs/01-engine-architecture.md — sets a value and resets timer, likely for timeout or interval tracking

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585bf0 — Iterate Triggers via Vtable, Call Handlers per Tick

Source: unknown | Confidence: medium
Iterates through trigger/event objects, calls per-tick handlers, dispatches events through virtual dispatch chain.

**Key logic:**
- Calls virtual method at `*param_1 + 200` (vtable offset 200 = 0xC8) — likely pre-tick/setup
- Calls virtual at `+0x1c` — returns trigger ID/count context (uVar2)
- Calls virtual at `+0xa4` — returns iteration count (iStack_4)
- Loop 0..count-1:
  - Calls virtual at `+0xac`(index, context) — predicate check
  - If true:
    - Calls FUN_005871c0 (dual query into two output params)
    - Calls FUN_00585cc0 (struct field getter at +0x78)
    - Reads value at `*piVar3` — dispatch table/handler pointer
    - Calls FUN_00587220 (struct field getter at +0x10)
    - Calls FUN_005871f0 (read field at offset 0x14)
    - Calls virtual at `(dispatch_table + 0x34)`(index, param) — handler dispatch
    - Calls FUN_004b0170 (destructor)
- Calls virtual at `+0x20`(context) — post-tick/cleanup
- Calls virtual at `+0xcc` — finalize
- Returns 1

**Calls:**
- FUN_005871c0 — dual query into two output params (triage index)
- FUN_00585cc0 — struct field getter at +0x78 (triage index)
- FUN_00587220 — struct field getter at +0x10 (triage index)
- FUN_005871f0 — read field at offset 0x14 (triage index)
- FUN_004b0170 — destructor (triage index)

**Used by system:** docs/01-engine-architecture.md — trigger/event tick dispatch loop, core engine tick processing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586620 — Node Destruction with Virtual Call

Source: unknown | Confidence: high
Conditionally calls virtual destructor on an active object node.

**Key logic:**
- Checks if `(char)param_1[2] != '\0'` (flag at offset +0x08)
- AND `*param_1 != NULL` (object pointer exists)
- If both true: dereferences object's vtable and calls destructor at slot 0 (first virtual method) with argument 1
- Otherwise no-op

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | objectPtr | int* | Pointer to object with vtable |
| +0x08 | activeFlag | byte | Flag controlling destruction |

**Used by system:** docs/01-engine-architecture.md — conditional node destruction with vtable dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587b7f — Init Wrapper Calling 3 Subroutines

Source: unknown | Confidence: medium
Initialization function that calls three subroutines and stores a global result.

**Key logic:**
- Calls FUN_00587b97 — init CRT float conversion function pointers (triage index)
- Sets global `DAT_008d3e44 = FUN_0058bca6()` — stores result of unknown function
- Calls FUN_0058bc56 — calls FUN_0059508d(0x10000, 0x30000) (triage index)

**Globals:**
- `DAT_008d3e44` — not in docs/12; written with return value from FUN_0058bca6

**Calls:**
- FUN_00587b97 — init CRT float conversion function pointers (triage index line 6748)
- FUN_0058bca6 — unknown (methodology doc, 23 lines)
- FUN_0058bc56 — calls FUN_0059508d(0x10000, 0x30000) (triage index)

**Used by system:** docs/01-engine-architecture.md — initialization sequence, likely CRT/subsystem startup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00588f66 — Batch Function Call over Varargs

Source: unknown | Confidence: medium
Iterates over varargs list and calls same function for each argument.

**Key logic:**
- param_1 = function target (code pointer or data to pass)
- param_2 = count of additional arguments on stack
- Iterates param_2 times, reading next dword from stack for each iteration
- Calls `FUN_0058fcb0(param_1, arg)` for each argument
- FUN_0058fcb0 is a strncpy-style function (docs/20)

**Algorithm family:** Batch dispatch

**Calls:**
- FUN_0058fcb0 — strncpy replacement, copies N chars and null-terminates (docs/20)

**Used by system:** docs/01-engine-architecture.md — batch function call over varargs, likely for bulk initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058b75f — Mutex Unlock Wrapper

Source: unknown | Confidence: high
Thin wrapper calling FUN_0058e04b with parameter 9.

**Key logic:**
- Calls `FUN_0058e04b(9)` — CritSect leave wrapper (triage index line 6852)
- Parameter 9 likely identifies a specific critical section index

**Calls:**
- FUN_0058e04b — CriticalSection leave (triage index line 6852)

**Used by system:** docs/01-engine-architecture.md — mutex/critical section unlock for slot/index 9

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059373e — Struct Matching with Bit Flags + strcmp

Source: unknown | Confidence: medium
Compares two structs for compatibility using multiple criteria: pointer identity, strcmp, and bit flag checks.

**Key logic:**
- Reads field at `*(int *)(param_1 + 4)` from both structs
- If first field is null or its string at +8 is empty → returns 1 (match)
- If both struct IDs match (same pointer at +4): jumps to flag check
- Otherwise: calls `_strcmp(name1+8, name2+8)` — string comparison of names at offset +8
  - If strings match: proceeds to flag check
  - If strings differ: returns 0 (no match)
- Flag check at LAB_0059376f:
  - `*param_2 & 2 == 0` OR `*param_1 & 8 != 0` — type flag compatibility
  - `*param_3 & 1 == 0` OR `*param_1 & 1 != 0` — user flag 1 compatibility  
  - `*param_3 & 2 == 0` OR `*param_1 & 2 != 0` — user flag 2 compatibility
  - If all pass → returns 1 (match), else returns 0

**Used by system:** docs/01-engine-architecture.md — compatibility matching with name + flag check, likely resource/object matching

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00595ac0 — File Critical Section Leave

Source: unknown | Confidence: high
Leaves a critical section for a file handle, using index into a file handle table (DAT_008d4920).

**Key logic:**
- Computes index into file handle table: `param_1 >> 5` (divide by 32) selects table chunk
- `(param_1 & 0x1f) * 0x24` — selects slot within chunk (0x24 = 36 byte stride)
- Offset +0xc within the slot points to the CRITICAL_SECTION
- Calls `LeaveCriticalSection(slot + 0xc)`

**Globals:**
- `DAT_008d4920` — file handle table (docs/08 file I/O)

**Calls:**
- LeaveCriticalSection — Win32 kernel32 API

**Used by system:** docs/01-engine-architecture.md — file I/O critical section unlock, paired with file lock

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059871b — Cleanup Wrapper

Source: unknown | Confidence: high
Thin wrapper similar to FUN_0057aa70, calling FUN_00587b3e with SEH handler address.

**Key logic:**
- Calls `FUN_00587b3e(&LAB_00598727)` — boolean-to-int conversion with SEH handler block

**Calls:**
- FUN_00587b3e — boolean-to-int conversion wrapper (triage index)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup wrapper, twin to FUN_0057aa70

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_005996ae — Buffer Size Management with Copy

Source: unknown | Confidence: low (register variables unaff_ESI/EBP/EDI — partial decompilation)
Buffer management function handling size tracking, data copy, and null termination.

**Key logic:**
- Reads buffer size from `*(uint *)(unaff_ESI + 8)` — current buffer capacity
- If capacity > 0:
  - `uVar2 = min(unaff_EDI, capacity)` — limit copy size
  - Calls `FUN_0058cc00(dest+1, src, uVar2)` — memmove-style copy
- Calls FUN_005993af(1) — reference count decrement and conditional free
- Sets destination pointer: `*(src_ptr) = buffer_ptr + 1`
- Writes null terminator at start of buffer
- Sets field +0xc = unaff_EDI (total size)
- If capacity <= requested size: updates EDI to capacity
- Sets field +0x08 = uVar2 (new capacity)
- Writes null at position src_ptr + new_capacity

**Calls:**
- FUN_0058cc00 — memmove backward/forward copy (triage index)
- FUN_005993af — reference count decrement and conditional free (triage index line 7365)

**Used by system:** docs/01-engine-architecture.md — buffer resize/management with reference counting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a7de — Destructor with SEH + VTable Reset

Source: unknown | Confidence: low (register variable unaff_EBP — partial decompilation)
Destructor with SEH prologue, vtable reset, exception handling, and base class destruction.

**Key logic:**
- Calls FUN_0058a5d8() — SEH handler init (triage index line 6798)
- Sets up exception handler frame on stack
- Sets vtable of `this` to `&PTR_FUN_005b9d28` — resets to base class vtable
- Calls FUN_005993af(1) — reference count decrement and conditional free
- Sets SEH cookie to -1 (end of handler)
- Calls `exception::~exception(this)` — base class destructor
- Restores ExceptionList from stack frame

**Calls:**
- FUN_0058a5d8 — SEH handler init (triage index)
- FUN_005993af — reference count decrement and conditional free (triage index)
- exception::~exception — MSVC exception base class destructor

**Used by system:** docs/01-engine-architecture.md — derived exception object destructor with SEH

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059afff — Exception Throw Wrapper

Source: unknown | Confidence: high
Thin wrapper that prepares and throws a C++ exception using MSVC runtime.

**Key logic:**
- Calls `FUN_0059b038(param_1)` — object init with vtable (triage index line 7047)
- Calls `__CxxThrowException_8(local_20, &DAT_005bb9b8)` — MSVC C++ exception throw
- Does not return (NORETURN)

**Calls:**
- FUN_0059b038 — object init with vtable (triage index)
- __CxxThrowException_8 — MSVC CRT exception throw

**Used by system:** docs/01-engine-architecture.md — C++ exception throw helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c43c — SEH Unwind with Field Free

Source: unknown | Confidence: low (register variable unaff_EBP)
SEH unwind handler that frees a field stored on the stack frame.

**Key logic:**
- Calls `FUN_00587bcf(*(undefined4 *)(unaff_EBP + -0x14))` — free object at stack offset -0x14

**Calls:**
- FUN_00587bcf — free/operator delete (docs/09, 19, 21)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup for stack-allocated object

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c5a8 — SEH Unwind Free Object at +8

Source: unknown | Confidence: low (register variable unaff_EBP)
SEH unwind handler that frees an object at stack frame offset +8.

**Key logic:**
- Calls `FUN_00587bcf(*(undefined4 *)(unaff_EBP + 8))` — free object at stack offset +8

**Calls:**
- FUN_00587bcf — free/operator delete

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c6a2 — SEH Unwind Free Object at +8

Source: unknown | Confidence: low (register variable unaff_EBP)
SEH unwind handler identical to FUN_0059c5a8.

**Key logic:**
- Calls `FUN_00587bcf(*(undefined4 *)(unaff_EBP + 8))` — free object at stack offset +8

**Calls:**
- FUN_00587bcf — free/operator delete

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup (duplicate of 0059c5a8)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cbc0 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler calling vtable pointer set.

**Key logic:**
- Calls `FUN_0057bc70()` — single vtable pointer set (triage index line 6618)

**Calls:**
- FUN_0057bc70 — single vtable pointer set (triage index)

**Used by system:** docs/01-engine-architecture.md — SEH unwind vtable reset

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cd6b — SEH Unwind with Field Free

Source: unknown | Confidence: low (register variable unaff_EBP)
SEH unwind handler freeing object at stack offset -0x10.

**Key logic:**
- Calls `FUN_00587bcf(*(undefined4 *)(unaff_EBP + -0x10))` — free at stack offset -0x10

**Calls:**
- FUN_00587bcf — free/operator delete

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cf19 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler delegating to linked list destroy.

**Key logic:**
- Calls `FUN_005833e0()` — walk linked list, call destructor, free nodes (triage index line 6651)

**Calls:**
- FUN_005833e0 — walk linked list, call destructor, free nodes (triage index)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup for linked list

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d086 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler calling small destructor helper.

**Key logic:**
- Calls `FUN_0047aa60()` — math_util short computation / small destructor (triage index line 1640)

**Calls:**
- FUN_0047aa60 — small destructor (triage index)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d444 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler calling null check with virtual dispatch.

**Key logic:**
- Calls `FUN_00598c70()` — null check with virtual dispatch (triage index line 6953)

**Calls:**
- FUN_00598c70 — null check with virtual dispatch / error handling (triage index)

**Used by system:** docs/01-engine-architecture.md — SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d948 — Global Flag Setter via Function Call

Source: unknown | Confidence: medium
Reads a value from a function call and writes it to a global data structure at fixed offset.

**Key logic:**
- Calls `FUN_0049bad0()` — returns byte value (math_util short computation)
- Writes result to `*(byte *)(DAT_005c7530 + 0x80)` — global struct field at offset +0x80
- Calls `FUN_004dbac3()` — unknown

**Globals:**
- `DAT_005c7530` — not in docs/12; used as base pointer for global data struct

**Calls:**
- FUN_0049bad0 — math_util short computation (triage index line 2216)
- FUN_004dbac3 — unknown

**Used by system:** docs/01-engine-architecture.md — global state setter, likely game mode flag or configuration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005519e0 — Doubly-Linked List Node Removal

Source: unknown | Confidence: high
Removes a node from a doubly-linked list, updates list head if needed, then calls cleanup functions and frees the node.

**Key logic:**
- If node's prev pointer (param_2+0x2c) is non-null: updates prev's next (param_2+0x30 → prev+0x30)
- If node's next pointer (param_2+0x30) is non-null: updates next's prev (param_2+0x2c → next+0x2c)
- If node == list head (param_1+0x118): updates head to node's next
- Calls FUN_00550ac0 (math_util, cleanup/update)
- Calls FUN_00557470 (release/unload resource)
- Calls FUN_00587bcf (free/deallocate node)

**Struct offsets (param_1 — list container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x118 | ListHead | int* | Pointer to first node in linked list |

**Struct offsets (param_2 — node):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x2c | PrevNode | int* | Previous node in doubly-linked list |
| +0x30 | NextNode | int* | Next node in doubly-linked list |

**Calls:**
- FUN_00550ac0 — math_util (13 lines, cleanup/update)
- FUN_00557470 — release/unload resource
- FUN_00587bcf — memory free/deallocation

**Used by system:** docs/01-engine-architecture.md — Generic linked list manager; likely used by resource/system object lifecycle.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00553de0 — Struct Zero-Init Constructor

Source: unknown | Confidence: high
Initializes an object/struct by calling two init functions then zeroing 9 fields.

**Key logic:**
- Calls FUN_0053c2a0 (short math_util, 3 lines — parent constructor)
- Calls FUN_00553db0 (subsystem init)
- Zeros fields at indices: param_1[0], [9], [10], [0xd], [0xb], [0xc], [0xe], [0xf], [0x10]
- Byte offsets: 0, 0x24, 0x28, 0x34, 0x2c, 0x30, 0x38, 0x3c, 0x40
- Returns param_1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | field_0 | int | Zeroed |
| +0x24 | field_24 | int | Zeroed |
| +0x28 | field_28 | int | Zeroed |
| +0x2c | field_2c | int | Zeroed |
| +0x30 | field_30 | int | Zeroed |
| +0x34 | field_34 | int | Zeroed |
| +0x38 | field_38 | int | Zeroed |
| +0x3c | field_3c | int | Zeroed |
| +0x40 | field_40 | int | Zeroed |

**Calls:**
- FUN_0053c2a0 — math_util (3 lines, parent constructor)
- FUN_00553db0 — subsystem init

**Used by system:** docs/01-engine-architecture.md — Object initialization. The parent init + subsystem init + zero pattern is a C++ constructor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c2e0 — Doubly-Linked List Node Unlink by Match

Source: unknown | Confidence: high
Searches a singly-linked list with prev/next pointers (doubly-linked) at list head param_1+0x1518. Finds the node matching param_2 pointer, unlinks it.

**Key logic:**
- Reads list head from param_1 + 0x1518
- Walks forward via next pointer at +0x20, comparing each node to param_2
- If node's prev (+0x1c) non-null: updates prev's next to node's next
- If node's next (+0x20) non-null: updates next's prev to node's prev
- If head == node: updates head to node's next
- Does NOT free the node (caller's responsibility)

**Struct offsets (param_1 — list container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1518 | ListHead | int* | Head of doubly-linked list |

**Struct offsets (node):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1c | PrevNode | int* | Previous node |
| +0x20 | NextNode | int* | Next node |

**Used by system:** docs/01-engine-architecture.md — Generic linked list manager for engine subsystems.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00563e80 — Index-Bounds Checked Array Read

Source: network subsystem | Confidence: high
Reads from a global array with index bounds checking. Returns 0 if index out of range.

**Key logic:**
- If param_2 >= 0: calls FUN_00563e70() to get array size/count
- If param_2 < array_size: calls FUN_005648b0() to get array base pointer, returns value at that index
- Returns 0 on out-of-bounds

**Calls:**
- FUN_00563e70 — math_util, returns pointer/array size value
- FUN_005648b0 — math_util, returns array base pointer (linear interpolation pattern)

**Used by system:** docs/01-engine-architecture.md — Bounds-checked accessor; likely used by network/socket or resource array.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00564960 — Aligned Memory Copy from Struct Buffer

Source: unknown | Confidence: high
Copies data from source to destination in 4-byte chunks, handling remaining bytes. Uses a global buffer pointer from FUN_005648b0.

**Key logic:**
- Gets destination pointer via FUN_005648b0() (global buffer)
- Reads size from `*(extraout_ECX + 8)` — 4-byte size field from struct
- Copies `size >> 2` dwords (4-byte chunks)
- Copies `size & 3` remaining bytes byte-by-byte

**Calls:** FUN_005648b0 — math_util, returns buffer/pointer

**Used by system:** docs/01-engine-architecture.md — Memory copy utility with global buffer destination; likely used for packet/buffer deserialization.

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0056eb30 — Linear Search in Struct Array by String

Source: unknown | Confidence: high
Iterates an array of 0x48-byte struct entries, matching the first field (string pointer) against param_2 via string compare. Returns pointer to matching entry or 0.

**Key logic:**
- If element count at param_1+0x18 > 0: iterate stride 0x48
- At each element: if first element pointer (at base+offset) != 0, compare via FUN_00588410(param_2, *element_string_ptr)
- On match: returns `param_1+0x1c + index * 0x48` (pointer to the matching struct)
- Returns 0 on no match

**Struct offsets (param_1 — array container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | ElementCount | int | Number of entries |
| +0x1c | ElementArray | byte* | Array of 0x48-byte entries |

**Per-element offset:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | NamePtr | char* | Pointer to string for comparison |

**Calls:** FUN_00588410 — string compare (docs/06, 75 lines)

**Used by system:** docs/01-engine-architecture.md — Named resource lookup by string in a flat array.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a570 — Byte Field Setter at Offset +0x5d

Source: unknown | Confidence: high
Sets a single byte field at `**(param_1 + 0x5d)` via double indirection.

**Key logic:**
- Reads `*param_1` to get inner struct pointer
- Writes param_2 (byte) to inner struct + 0x5d
- Double indirection suggests param_1 is a handle/pointer-wrapper

**Struct offsets (param_1 — wrapper ptr):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | InnerPtr | int* | Pointer to actual struct |

**Inner struct offset:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x5d | field_5d | byte | Written directly from param_2 |

**Used by system:** docs/01-engine-architecture.md — Game logic byte setter via handle.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057aaf0 — Stack Buffer Copy + Predicate Call

Source: unknown | Confidence: high
Copies 12 dwords (48 bytes) from param_1 to a stack buffer, then calls a predicate function. Returns whether predicate succeeds.

**Key logic:**
- Zeros first word of *param_2
- Sets up stack buffer (12 dwords = 48 bytes at auStack_40)
- Sets puStack_10 to param_2 (likely callback context)
- Copies 12 dwords from param_1 to stack buffer (forwarding game state / packet data)
- Calls FUN_0057abb0 (248 bytes, large predicate/processing function)
- Returns result of predicate (0 = success, non-0 = failure)

**Calls:** FUN_0057abb0 — large predicate/processing function (248 bytes, SEH-protected)

**Used by system:** docs/01-engine-architecture.md — Buffer copy then predicate; likely a security check or validation wrapper.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057bc70 — Single VTable Pointer Set

Source: unknown | Confidence: high
Sets the vtable pointer for an object.

**Key logic:**
- Writes `*param_1 = &PTR_LAB_005b8a00` — sets vtable to address at 0x005b8a00
- This is a C++ constructor initializing the virtual function table

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — C++ constructor initializer setting vtable pointer.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00583690 — Single Function Call Wrapper (Timer Delta)

Source: unknown | Confidence: high
Trivial wrapper around FUN_00568cf0 (high-res timer delta).

**Key logic:**
- Calls FUN_00568cf0() — reads and updates high-resolution timer
- Returns void (caller uses side effect of timer state update)

**Calls:** FUN_00568cf0 — high-res timer delta with state update (timer math)

**Used by system:** docs/01-engine-architecture.md — Frame timing call wrapper.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585cd0 — Thread-Safe Write with Mutex

Source: threading/synchronization | Confidence: high
Writes a value to a shared buffer with mutex-based thread safety. Handles mutex acquisition with timeout.

**Key logic:**
- Checks if mutex handle at param_1+0x5b8 is valid
- If valid: calls WaitForSingleObject(mutex, timeout_at_param_1+0x5bc)
- If wait succeeds (return 0) or returns WAIT_TIMEOUT (0x80): writes param_2 to target at param_1+0x5b4
- If wait fails (other return value): does not write (target stays as null pointer)
- Releases mutex with ReleaseMutex if it was acquired

**Struct offsets (param_1 — thread-safe buffer):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x5b4 | WriteTarget | undefined4* | Address to write to (defaults to param_1+0x5b4) |
| +0x5b8 | MutexHandle | HANDLE | Win32 mutex handle |
| +0x5bc | WaitTimeout | DWORD | Timeout in ms for WaitForSingleObject |

**Globals:** none

**Calls:** WaitForSingleObject, ReleaseMutex (Win32 API)

**Used by system:** docs/01-engine-architecture.md — Thread-safe data write with mutex synchronization.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00587230 — Counter Increment/Decrement by Flag

Source: unknown | Confidence: high
Increments or decrements a byte counter at param_1+0x19 based on param_2 flag.

**Key logic:**
- Reads current counter at param_1 + 0x19
- If param_2 != 0 (true/set): increments counter by 1
- If param_2 == 0 (false/clear) AND counter != 0: decrements by 1
- Clamped to byte range; no wrap protection on increment

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x19 | Counter | byte | Reference counter or state flag |

**Used by system:** docs/01-engine-architecture.md — Reference counting or state toggle based on boolean flag.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058924c — Byte Buffer Swap (In-Place)

Source: unknown | Confidence: high
Swaps two byte buffers in-place, element by element.

**Key logic:**
- If param_1 == param_2: no-op (same buffer)
- Loop: for param_3 bytes: swap param_1[i] with param_2[i]
- Byte-by-byte swap using temporary

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — General purpose in-place byte buffer swap utility.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0058b8ad — Semaphore Release (Slot 9)

Source: synchronization | Confidence: high
Releases semaphore slot 9 via FUN_0058e04b.

**Key logic:**
- Calls FUN_0058e04b(9) — release semaphore or critical section (slot 9)

**Calls:** FUN_0058e04b — semaphore/critsec release (typically pairs with acquire)

**Used by system:** docs/01-engine-architecture.md — Thread synchronization primitive release.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058d7f4 — Char-by-Char String Processing with Terminator Check

Source: unknown | Confidence: high
Processes a string character-by-character, calling a handler function for each char. Stops on -1 sentinel or when count exhausted.

**Key logic:**
- Loop: while param_2 > 0
- Decrements param_2, reads next char from param_1, increments param_1
- Calls FUN_0058d78e(char_value, param_3, param_4) for each character
- If *param_4 == -1 (sentinel/terminator): stop immediately
- Continues until param_2 characters processed or sentinel hit

**Calls:** FUN_0058d78e — char processing/handler function

**Used by system:** docs/01-engine-architecture.md — Iterative character processing with early-termination sentinel.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058f8eb — Multi-Field Free (7 Allocations)

Source: memory manager | Confidence: high
Frees 7 pointer fields at offsets +0xc through +0x24 from a struct, checking for a sentinel value.

**Key logic:**
- If param_1 == 0: no-op (null check)
- Checks if *(param_1 + 0xc) != &DAT_008d41cc (sentinel address)
- If not sentinel: calls FUN_0058aa6f on each of 7 fields at +0xc, +0x10, +0x14, +0x18, +0x1c, +0x20, +0x24
- FUN_0058aa6f is a memory deallocation/cleanup function

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c..+0x24 | FreeablePtrs[7] | void* | 7 pointers freed if not sentinel |

**Calls:** FUN_0058aa6f — memory deallocation (called 7 times)

**Used by system:** docs/01-engine-architecture.md — Cleanup of multi-field allocation block.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059379b — SEH-Aware Virtual Call Dispatch Loop

Source: runtime/exception | Confidence: high
SEH-protected virtual function call dispatch loop over a try block index table. Iterates from current state to target state, calling handler functions.

**Key logic:**
- Installs SEH handler (puStack_8 = &LAB_0058895c, puStack_c = &DAT_005b9940)
- Loop: starts from iVar2 = *(param_1 + 8), iterates until iVar2 == param_4
- Each step: reads next index from table at *(param_3 + 8) + iVar2 * 8
- Validates index range: if < 0 or >= *(param_3 + 4), calls FUN_00593cfd (error/exception)
- If handler function at table+4+iVar2*8 non-null: calls __CallSettingFrame_12(handler, param_1, 0x103)
- Updates *(param_1 + 8) = final iVar2
- Restores ExceptionList

**Struct offsets:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| param_1+8 | CurrentState | int | Try block state index |
| param_3+4 | MaxIndex | int | Table upper bound |
| param_3+8 | IndexTable | int* | Array of indices (stride 8) |

**Calls:** FUN_00593cfd — error/exception handler for out-of-range, __CallSettingFrame_12

**Used by system:** docs/01-engine-architecture.md — MSVC exception handling virtual call dispatch (C++ try/catch block iteration).

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059875f — Free Callback Registered Cleanup

Source: initialization/cleanup | Confidence: high
Registers a cleanup callback via the atexit-like registration system.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0059876b) — registers address of LAB_0059876b as cleanup callback
- This is an MSVC _atexit-style registration for module cleanup

**Calls:** FUN_00587b3e — deferred function/callback registration (MSVC _atexit-like)

**Used by system:** docs/01-engine-architecture.md — Module cleanup registration.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598de3 — Memory Copy from ID Lookup

Source: unknown | Confidence: high
Copies 6 dwords from a global data array (looked up by ID 0xffffffff) to output buffer.

**Key logic:**
- Calls FUN_0059942b(0xffffffff) — looks up data entry by ID (special: -1 = default?)
- Copies 6 dwords (24 bytes) from returned buffer to param_1
- Stride: 6 consecutive ints copied

**Calls:** FUN_0059942b — data lookup/initializer by ID (reads globals DAT_005b9cd8, DAT_005b9cdc, DAT_008d5a6c)

**Used by system:** docs/01-engine-architecture.md — Data copy by resource ID lookup.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a81b — C++ Exception Throw Wrapper

Source: runtime | Confidence: high
Prepares and throws a C++ exception using MSVC __CxxThrowException. Takes one argument and wraps it in an exception record.

**Key logic:**
- Calls FUN_0059a854(param_1) — prepare exception object
- Calls __CxxThrowException_8(local_20, &DAT_005bb668) — throw with exception record and type info
- Does not return (noreturn)

**Calls:**
- FUN_0059a854 — exception object preparation
- __CxxThrowException_8 — MSVC C++ exception throw

**Used by system:** docs/01-engine-architecture.md — C++ exception throwing utility wrapper.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059b038 — Object Init with VTable

Source: runtime | Confidence: high
C++ constructor initializer: calls a setup function then sets vtable pointer.

**Key logic:**
- Calls FUN_0059ae7d(param_2) — base/child initialization
- Sets *param_1 = &PTR_LAB_005b9d8c (vtable for this class)

**Calls:** FUN_0059ae7d — base class constructor

**Used by system:** docs/01-engine-architecture.md — C++ object constructor.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c446 — SEH Unwind: Free Object at EBP-0x14

Source: runtime | Confidence: high
SEH unwind handler: frees a local object at EBP-0x14 during stack unwinding.

**Key logic:**
- Reads pointer from `*(unaff_EBP + -0x14)` (local variable slot)
- Calls FUN_00587bcf (memory free/deallocation)

**Calls:** FUN_00587bcf — memory free

**Used by system:** docs/01-engine-architecture.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c5b2 — SEH Unwind: Free Object at EBP+8

Source: runtime | Confidence: high
SEH unwind handler: frees an object at EBP+8 during stack unwinding.

**Key logic:**
- Reads pointer from `*(unaff_EBP + 8)` (parameter slot)
- Calls FUN_00587bcf (memory free)

**Calls:** FUN_00587bcf — memory free

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c6ac — SEH Unwind: Free Object at EBP+8

Source: runtime | Confidence: high
SEH unwind handler: frees an object at EBP+8 during stack unwinding. Identical pattern to Unwind_0059c5b2.

**Key logic:**
- Reads pointer from `*(unaff_EBP + 8)` (parameter slot)
- Calls FUN_00587bcf (memory free)

**Calls:** FUN_00587bcf — memory free

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c83e — SEH Unwind: Call FUN_00581a80

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_00581a80 as cleanup during stack unwinding.

**Key logic:**
- Calls FUN_00581a80() — pool/resource cleanup

**Calls:** FUN_00581a80 — pool/resource cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c988 — SEH Unwind: Call FUN_005822b0

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_005822b0 as cleanup during stack unwinding.

**Key logic:**
- Calls FUN_005822b0() — pool/resource cleanup

**Calls:** FUN_005822b0 — pool/resource cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cbe0 — SEH Unwind: Call FUN_005834c0

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_005834c0 as cleanup during stack unwinding.

**Key logic:**
- Calls FUN_005834c0() — pool/resource cleanup

**Calls:** FUN_005834c0 — pool/resource cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cd80 — SEH Unwind: Call FUN_005834c0

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_005834c0 as cleanup during stack unwinding. Same target as Unwind_0059cbe0.

**Key logic:**
- Calls FUN_005834c0() — pool/resource cleanup

**Calls:** FUN_005834c0 — pool/resource cleanup function

**Used by system:** docs/01-engine-architecture.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cf21 — SEH Unwind: Call FUN_00586170

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_00586170 as cleanup during stack unwinding.

**Key logic:**
- Calls FUN_00586170() — pool/resource cleanup

**Calls:** FUN_00586170 — pool/resource cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d091 — SEH Unwind: Call FUN_0047aa60

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_0047aa60 as cleanup during stack unwinding.

**Key logic:**
- Calls FUN_0047aa60() — pool/resource cleanup function (0x0047XXXX range = game logic/UI)

**Calls:** FUN_0047aa60 — game logic cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d224 — SEH Unwind: Conditional Call FUN_00598aea

Source: runtime | Confidence: high
SEH unwind handler: conditionally calls FUN_00598aea based on a flag at EBP-0x10.

**Key logic:**
- Checks flag at `*(uint *)(unaff_EBP + -0x10) & 1`
- If bit 0 set: calls FUN_00598aea() — cleanup function
- Otherwise: no-op

**Calls:** FUN_00598aea — cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler with condition flag.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d45c — SEH Unwind: Call FUN_0059a9c2

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_0059a9c2 as cleanup during stack unwinding.

**Key logic:**
- Calls FUN_0059a9c2() — cleanup function

**Calls:** FUN_0059a9c2 — cleanup function

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup handler.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d963 — Single Function Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper around FUN_004bffa4.

**Key logic:**
- Calls FUN_004bffa4() — no local logic

**Calls:** FUN_004bffa4 — target function (0x004B range = game logic)

**Used by system:** docs/01-engine-architecture.md — Call dispatch wrapper.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00407dd0 — Short Computation / Linked List Walker with Progress Callback

Source: unknown | Confidence: high
Walks a singly-linked list from head, calling a progress callback for each node. Uses a current-pointer at +0x20.

**Key logic:**
- Reads list head from param_1 + 0x18, stores as current in param_1 + 0x20
- If head non-null and *head non-zero: loop
  - Calls FUN_00406640(param_2) — progress/callback function
  - If current becomes 0: stop
  - Advances to next node (current + 4 = next pointer)
  - Stops if next is null or *next == 0

**Struct offsets (param_1 — list container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | ListHead | int* | Head of linked list |
| +0x20 | CurrentPtr | int* | Current walk position |

**Calls:** FUN_00406640 — progress/callback function

**Used by system:** docs/01-engine-architecture.md — Lock-step linked list traversal with per-node callback.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b6c0 — Short Computation / Index Search in Struct Array

Source: unknown | Confidence: high
Linear search for a pointer value in an array of 0xd0-byte structs. Returns index or -1.

**Key logic:**
- If count at param_1+0x10 > 0: start from base at param_1+0xc, stride 0xd0
- Compare each entry against param_2 pointer
- On match: return current index
- If index >= count: return -1
- Returns -1 if count <= 0

**Struct offsets (param_1 — array container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | ElementArray | byte* | Array of 0xd0-byte entries |
| +0x10 | ElementCount | int | Number of entries |

**Used by system:** docs/01-engine-architecture.md — Pointer-based lookup in 0xd0-byte stride array.

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0040fd70 — Short Computation / VTable Init + Thunk

Source: unknown | Confidence: high
C++ constructor initializer: sets vtable and calls a thunk.

**Key logic:**
- Sets *param_1 = &PTR_LAB_0059e720 (vtable pointer)
- Calls thunk_FUN_00568f20() — thunk to struct initializer

**Calls:** thunk_FUN_00568f20 — struct initializer thunk

**Used by system:** docs/01-engine-architecture.md — C++ constructor with vtable setup.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418c10 — Memory Allocation / Nested Pointer Free with Conditional Dealloc

Source: memory manager | Confidence: high
Multi-level pointer cleanup: frees 8 inner pointers (4 groups of 2), then frees main allocation, conditional on param_2.

**Key logic:**
- If param_1[2] (flag byte) is non-zero and *param_1 non-null:
  - Calls FUN_00414d70() — pre-cleanup
  - Frees 8 pointers in 4 groups of 2, each at offsets: +0x2b→+0x26, +0x21→+0x1c, +0x17→+0x12, +0xd→+0x8 (each group counting down 2 with -5 stride)
  - Frees *param_1 (inner alloc)
  - Frees param_1 (outer alloc)
- If (param_2 & 1) != 0: also frees param_1 (caller-owned)

**Calls:** FUN_00414d70, FUN_00587bcf (×9+)

**Used by system:** docs/01-engine-architecture.md — Deep cleanup of nested allocation struct.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004562c0 — Short Computation / Destructor with VTable Reset

Source: unknown | Confidence: high
Destructor: resets vtable, conditionally frees member and self.

**Key logic:**
- Sets *param_1 = &PTR_FUN_0059efcc (vtable reset to base)
- If param_1[1] != 0: frees via FUN_00587bcf
- If (param_2 & 1) != 0: frees param_1 (self) via FUN_00587bcf

**Calls:** FUN_00587bcf (conditional ×2)

**Used by system:** docs/01-engine-architecture.md — C++ destructor with conditional self-delete.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461440 — References Global State / Session Flag Check

Source: steward/session | Confidence: high
Checks a session/state field and a global flag, returns boolean.

**Key logic:**
- If *(param_1 + 0x3fc4) is 1 or 2 AND DAT_007d1074 is non-zero: return 1
- Otherwise: return 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x3fc4 | StateMode | int | Checked for value 1 or 2 |

**Globals:**
- `DAT_007d1074` — global flag (near DAT_007d00ec GameState range)

**Used by system:** docs/01-engine-architecture.md — Session/state check: returns true if state is 1 or 2 and global flag active.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00462140 — Short Computation / Refresh Flag Clear

Source: track/scene | Confidence: high
Checks and clears a global refresh flag, returning whether it was set.

**Key logic:**
- If DAT_007cd2a0 != 0: clear it to 0, return 1 (was pending refresh)
- Otherwise: return 0

**Globals:**
- `DAT_007cd2a0` — track/scene refresh flag (0 = no refresh needed)

**Used by system:** docs/01-engine-architecture.md — Refresh/tick flag poll-clear.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00465430 — Short Computation / Player Control Set

Source: game logic | Confidence: high
Sets player control state via two function calls.

**Key logic:**
- Calls FUN_00464e90(param_2) — lookup/get handle by player ID
- Calls FUN_00464a60(result) — set control state

**Calls:**
- FUN_00464e90 — lookup by player/vehicle index
- FUN_00464a60 — set control state

**Used by system:** docs/01-engine-architecture.md — Player control state setter.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00466d60 — Short Computation / Object Init + VTable

Source: game logic/UI | Confidence: high
Initializes an object: calls setup function, zeros fields, sets vtable.

**Key logic:**
- Calls FUN_0048c070(param_2) — setup/init
- Zeros 5 fields: param_1[199], [0xcb], [0xcc], [0xca], [0xc9]
- Sets *param_1 = &PTR_FUN_0059f438 (vtable)

**Calls:** FUN_0048c070 — setup function

**Used by system:** docs/01-engine-architecture.md — C++ object constructor.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0046a530 — Short Computation / Destructor VTable Reset + Free

Source: game logic | Confidence: high
Destructor: resets vtable, frees member at +0x174, calls cleanup.

**Key logic:**
- Sets *param_1 = &PTR_FUN_0059f938 (vtable reset)
- If param_1[0x5d] (+0x174) non-null: frees via FUN_00587bcf
- Calls FUN_00489440() — cleanup

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x174 | FreeablePtr | Freed via FUN_00587bcf |

**Calls:** FUN_00587bcf, FUN_00489440

**Used by system:** docs/01-engine-architecture.md — C++ destructor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046fd00 — Short Computation / Object Init with VTable + Field

Source: game logic | Confidence: high
Constructor: calls setup, stores a byte field, sets vtable.

**Key logic:**
- Calls FUN_00487220(0, 0) — init
- Writes param_2 (byte) to param_1 + 0x39
- Sets *param_1 = &PTR_FUN_005a00f0 (vtable)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x39 | ConfigByte | byte field from param_2 |

**Calls:** FUN_00487220 — init function

**Used by system:** docs/01-engine-architecture.md — C++ constructor with configuration.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004715d0 — Short Computation / Object Init with Globals

Source: game logic | Confidence: high
Constructor: calls parent init, sets vtable and multiple field values including global references.

**Key logic:**
- Calls FUN_00466d60(1) — parent constructor
- Sets *param_1 = &PTR_FUN_005a0f00 (vtable)
- Sets param_1[199] = &DAT_007ce850 (global reference)
- Sets fields: [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0xed
- Calls FUN_00486f30(&PTR_DAT_005be704, -1) — register UI/text handle
- Calls FUN_00486f30(&DAT_005c32c8, -1) — register UI/text handle
- Calls FUN_004670e0() — finalize

**Globals:**
- `DAT_007ce850` — stored in param_1[199]
- `PTR_DAT_005be704` — UI/text handle
- `DAT_005c32c8` — UI/text handle (near VehicleCount)

**Calls:** FUN_00466d60, FUN_00486f30 (×2), FUN_004670e0

**Used by system:** docs/01-engine-architecture.md — C++ constructor for a UI/game object with global references.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004733a0 — References Global State / Object Constructor

Source: game logic | Confidence: high
Constructor: calls parent init, sets vtable, stores global reference and config values.

**Key logic:**
- Calls FUN_00466d60(1) — parent constructor
- Sets *param_1 = &PTR_FUN_005a27c0 (vtable)
- Sets param_1[199] = &DAT_007d02e4 (global reference)
- Sets fields: [0xc9]=3, [0xca]=0, [0xcb]=3, [0xcc]=3, [0xcd]=0x10e (270)
- Registers 4 UI/text handles: one PTR_DAT_005be704 + three DAT_005c32c8

**Globals:**
- `DAT_007d02e4` — global reference stored in object
- `PTR_DAT_005be704` — UI/text handle
- `DAT_005c32c8` — UI/text handle (near VehicleCount)

**Calls:** FUN_00466d60, FUN_00486f30 (×4)

**Used by system:** docs/01-engine-architecture.md — C++ constructor for UI/game element.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478200 — Short Computation / Game Command Dispatch

Source: game logic | Confidence: high
Dispatches command 0x16 through the game command interface.

**Key logic:**
- Calls virtual method at (*DAT_007cd8c0)+0x1c with argument 0x16 (command ID)
- If result non-null: stores at param_1 + 0xe0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xe0 | CommandResult | Result from dispatch |

**Globals:**
- `DAT_007cd8c0` — game command dispatch interface pointer

**Used by system:** docs/01-engine-architecture.md — Game command dispatch (0x16) via interface.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a9e0 — Unidentified / UI Object Init

Source: UI/game logic | Confidence: high
Constructor: calls setup, initializes many fields to -1 (sentinel) or 0, sets vtable.

**Key logic:**
- Calls FUN_00485e30() — setup/init
- Sets 11 fields to 0xFFFFFFFF (-1): param_1[0x39] through [0x40], [0x44], [0x45], [0x46]
- Sets *param_1 = &PTR_FUN_005a66e0 (vtable)
- Sets 4 fields to 0: param_1[0x38], [0x41], [0x42], [0x43]

**Calls:** FUN_00485e30

**Used by system:** docs/01-engine-architecture.md — UI object constructor with sentinel initialization.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485570 — Short Computation / Destructor with VTable

Source: UI | Confidence: high
Destructor: resets vtable, calls cleanup, conditionally frees self.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005ab340 (vtable reset)
- Calls FUN_00487250() — cleanup
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1)

**Calls:** FUN_00487250, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md — C++ destructor.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00485eb0 — Unidentified / Multi-Struct Destructor

Source: UI/resource manager | Confidence: high
Complex destructor that frees 5 individual pointers, then destroys 3 linked lists with per-node cleanup.

**Key logic:**
- Sets vtable reset
- Calls FUN_00486080() — base cleanup
- Frees 5 individual pointers at [0x30], [0x2e], [0x2c], [0x2a], [0x28] if non-null
- Destroys linked list at [0x1c]: walks nodes, frees *node if flag at node[2] set, frees node
- Destroys linked list at [0x15]: walks nodes, frees *node via FUN_00414370+FUN_00587bcf if non-null, frees node
- Destroys linked list at [0x11]: walks nodes, frees **node then *node then node if non-null, frees node
- Zeros all list head/tail/count fields
- Calls FUN_0049a990() — final cleanup

**Calls:** FUN_00486080, FUN_00587bcf (×many), FUN_00414370, FUN_0049a990

**Used by system:** docs/01-engine-architecture.md — Large resource manager destructor with 3 linked lists.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00487720 — Short Computation / State Value Transform

Source: unknown | Confidence: medium
Transforms a state value from FUN_00486720 with special-case handling.

**Key logic:**
- Calls FUN_00486720() — get state
- If result == 1 or result == 3: return 1
- Otherwise: return (result - 3) & 0xffffff00

**Calls:** FUN_00486720 — state getter

**Used by system:** docs/01-engine-architecture.md — State normalization utility.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489f40 — Unidentified / Clamped Index Computation

Source: UI | Confidence: medium
Computes a clamped index based on range boundaries and optional constraints.

**Key logic:**
- If count at param_1+0x158 > 0 AND param_2 in range (param_1+4, param_1+8):
  - Reads floor value from param_1+0x14c
  - Computes from-float to int (iVar2 = __ftol())
  - Clamps to floor minimum
  - If param_3 != 0 (clamped mode):
    - Computes alternative_max = param_1+0x164 - 1 + floor
    - If alternative_max < iVar2: iVar2 = alternative_max
    - If iVar2 >= param_1+0x94: iVar2 = param_1+0x94 - 1
  - Returns clamped iVar2

**Calls:** __ftol (CRT float-to-long)

**Used by system:** docs/01-engine-architecture.md — UI scrollbar/list index computation.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048c9d0 — Short Computation / VTable Set Only

Source: UI | Confidence: high
Trivial vtable setter for a C++ object.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005ac044 (vtable)

**Used by system:** docs/01-engine-architecture.md — C++ empty constructor / vtable init.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048d6a0 — Short Computation / VTable Init + Call

Source: UI | Confidence: high
Constructor: sets vtable, calls setup function.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005ac280 (vtable)
- Calls FUN_00488b30() — setup/init

**Calls:** FUN_00488b30

**Used by system:** docs/01-engine-architecture.md — C++ constructor.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00498560 — Unidentified / String Copy to Struct Buffer

Source: UI/text | Confidence: high
Copies a string to a struct field at a computed offset using safe string copy.

**Key logic:**
- If param_2 non-null:
  - Computes string length (null-terminated scan, max 0x7FFFFFFF)
  - If string non-empty: copies to local_40 via _strncpy with max 0x3f (63)
  - Calls FUN_00566810() — get destination buffer
  - If buffer valid: zeros first byte
  - Copies char by char from local_40 to computed address: pcVar3 + (param_1 + 0x1518 - (int)local_40)
  - This effectively writes to param_1 + 0x1518 (destination field)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1518 | StringField | String destination (via strncpy) |

**Calls:** FUN_00566810, _strncpy

**Used by system:** docs/01-engine-architecture.md — Safe string copy to struct field.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a150 — Short Computation / Linked List Nth Element

Source: unknown | Confidence: high
Walks a linked list to get the Nth element with bounds check.

**Key logic:**
- Reads head from param_1 + 8
- If count at param_1 + 0xc < param_2: return 0 (out of bounds)
- If param_2 > 0: walk forward param_2 times via next at +0x24
- Return pointer at that position

**Struct offsets (param_1 — list container):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | ListHead | Linked list head |
| +0x0c | ElementCount | Count / max index |
| Node+0x24 | NextPtr | Next node pointer |

**Used by system:** docs/01-engine-architecture.md — Linked list indexed accessor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0ad0 — Short Computation / Command Dispatch (0x1b) + Standings

Source: game logic | Confidence: high
Dispatches game command 0x1b, on success calls standings display.

**Key logic:**
- Calls virtual at (*DAT_007cd8c0)+0x1c with arg 0x1b (command ID)
- If non-null: calls FUN_0046a560() — standings display

**Globals:**
- `DAT_007cd8c0` — game command dispatch interface

**Calls:**
- Virtual dispatch through DAT_007cd8c0+0x1c
- FUN_0046a560 — standings display (docs/06)

**Used by system:** docs/01-engine-architecture.md — Game command 0x1b (standings/show) dispatch.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004a1b70 — Short Computation / Conditional Path Registry

Source: file system | Confidence: high
Conditionally calls path registry function based on global flag.

**Key logic:**
- If DAT_007ce2e8 != 0: calls FUN_004a1dc0(param_1) — path/setup operation

**Globals:**
- `DAT_007ce2e8` — conditional flag

**Calls:** FUN_004a1dc0 — path/setup operation

**Used by system:** docs/01-engine-architecture.md — Conditional path/setup dispatch.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004b2100 — Unidentified Logic / Linked List Destructor

Source: resource manager | Confidence: high
Destroys a singly-linked list with per-node cleanup.

**Key logic:**
- Walks linked list starting from *param_1
- For each node: saves next pointer, if flag at node[2] non-zero and node data non-null:
  - Frees *data+4, then frees data
- Frees node
- Zeros head/tail/count/size fields (param_1[0..3])

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Head | Linked list head |
| +0x04 | Tail | Linked list tail |
| +0x08 | Count | Node count |
| +0x0c | Size | Element size |

**Per-node offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Data | Node data pointer |
| +0x04 | Next | Next node pointer |
| +0x08 | FreeFlag | If non-zero, free data |

**Calls:** FUN_00587bcf (×many)

**Used by system:** docs/01-engine-architecture.md — Linked list resource manager destructor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7e80 — Unidentified Logic / Double-Linked List Destroy with Virtual Call

Source: resource manager | Confidence: high
Destroys a linked list container that holds objects, calling virtual destructor (via vtable+0) on each, then frees the container.

**Key logic:**
- Gets list container at param_1 + 0xc
- Two passes over linked list at *container:
  - For each node: if flag set and data non-null: calls virtual destructor (*(*data))(1)
  - Frees node
  - Zeros container head/tail/count/size
- Second pass: same thing again (iterate and destroy)
- Frees container pointer itself
- Zeros param_1+0xc

**Calls:** FUN_00587bcf (×many), virtual destructor at vtable+0

**Used by system:** docs/01-engine-architecture.md — Resource container destruction with object cleanup.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004dc320 — Short Computation / Callback Registration

Source: initialization | Confidence: high
Registers a callback via atexit-like system.

**Key logic:**
- Calls FUN_00587b3e(&LAB_004dc330) — register label address as cleanup callback

**Calls:** FUN_00587b3e — callback registration (MSVC _atexit-like)

**Used by system:** docs/01-engine-architecture.md — Module cleanup callback registration.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004dd000 — Short Computation / Two-Call Sequence

Source: unknown | Confidence: high
Calls two functions in sequence.

**Key logic:**
- Calls FUN_004dcd10()
- Calls FUN_004dcf80()

**Calls:** FUN_004dcd10, FUN_004dcf80

**Used by system:** docs/01-engine-architecture.md — Init sequence wrapper.

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f23b0 — Short Computation / Callback Registration

Source: initialization | Confidence: high
Registers a cleanup callback at LAB_004f23c0.

**Key logic:**
- Calls FUN_00587b3e(&LAB_004f23c0) — register callback

**Calls:** FUN_00587b3e — callback registration (MSVC _atexit-like)

**Used by system:** docs/01-engine-architecture.md — Cleanup registration.

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f9160 — Utility Function / Global Index Setter

Source: game logic | Confidence: high
Sets global index and value based on validation against a limit.

**Key logic:**
- Calls FUN_0055bfc0() — get max index
- If param_1 < max_index: sets DAT_008afe6c = param_1, DAT_008afe68 = FUN_0055bfd0(param_1)

**Globals:**
- `DAT_008afe6c` — current index
- `DAT_008afe68` — value at that index

**Calls:** FUN_0055bfc0, FUN_0055bfd0

**Used by system:** docs/01-engine-architecture.md — Global index/value setter with bounds check.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0052e5b0 — Short Computation / Callback Registration

Source: initialization | Confidence: high
Registers callback via atexit-like system.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0052e5c0)

**Calls:** FUN_00587b3e — callback registration

**Used by system:** docs/01-engine-architecture.md — Cleanup registration.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055bde0 — Unidentified Logic / Linked List Indexed Traversal

Source: data structure | Confidence: high
Walks a linked list to the Nth element. Returns the node at index param_2.

**Key logic:**
- If param_2 < count at param_1+0x11c:
  - Starts from head at param_1+0x120
  - Walks via next at +0x20, counting up to param_2
  - Returns node at that position
- If param_2 >= count: returns 0

**Struct offsets (param_1 — list container):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x11c | Count | List count |
| +0x120 | Head | List head pointer |

**Used by system:** docs/01-engine-architecture.md — Linked list indexed node accessor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a820 — Short Computation / Thunk to FUN_00585810

Source: unknown | Confidence: high
Trivial thunk: calls FUN_00585810.

**Key logic:**
- Calls FUN_00585810() — no local logic

**Calls:** FUN_00585810 — target function

**Used by system:** docs/01-engine-architecture.md — Call dispatch thunk.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583270 — Unidentified Logic / Linked List Destructor with VTable Cleanup

Source: resource manager | Confidence: high
Destroys a linked list calling virtual destructor on each node's data.

**Key logic:**
- Walks linked list at *param_1
- For each node: if flag at node[2] set and data non-null:
  - Calls virtual method at *(*data) with arg 3 (destructor/release)
  - Frees data
- Frees node
- Zeros head/tail/count/size

**Calls:** FUN_00587bcf, virtual destructor at vtable+0(3)

**Used by system:** docs/01-engine-architecture.md — Resource list destructor with virtual cleanup.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059aaa3 — Short Computation / Callback Registration

Source: initialization | Confidence: high
Registers a callback via atexit-like system.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0059aaaf) — register label

**Calls:** FUN_00587b3e — callback registration

**Used by system:** docs/01-engine-architecture.md — Cleanup registration.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c620 — SEH Unwind: Free at EBP+8

Source: runtime | Confidence: high
SEH unwind handler: frees object at EBP+8.

**Key logic:**
- Calls FUN_00587bcf(*(unaff_EBP+8))

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cc88 — SEH Unwind: Thunk to FUN_00582f60

Source: runtime | Confidence: high
SEH unwind handler: thunk to FUN_00582f60.

**Key logic:**
- Calls FUN_00582f60() — pool/cleanup function

**Calls:** FUN_00582f60

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d358 — MSVC Exception Handler Unwind with DAT_008d4400

Source: runtime | Confidence: high
SEH unwind handler: calls FUN_00599796 with object and global data.

**Key logic:**
- Calls FUN_00599796(*(unaff_EBP-0x10), &DAT_008d4400) — cleanup with global context

**Calls:** FUN_00599796

**Used by system:** docs/20-math-utilities.md — SEH exception cleanup with global data.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004df030 — Unidentified Logic / Struct Build + Dispatch

Source: unknown | Confidence: medium
Builds a local parameter struct and dispatches based on a condition flag.

**Key logic:**
- Sets local_24=1, local_20=param_2, local_1c...local_4 = 0 (parameter block)
- If *(param_1 + 0x18) != 0: calls FUN_004dedb0(&local_24) — dispatch with block

**Calls:** FUN_004dedb0 — parameter block dispatch

**Used by system:** docs/01-engine-architecture.md — Parameterized dispatch call.

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_005504d0 — Indexed Array Lookup with Bounds Check

Source: unknown | Confidence: medium
Indexed lookup into 0x94-byte stride array with bounds checking. Returns pointer to element data.

**Key logic:**
- Checks param_3 < *(param_1 + 0xa4) (element count)
- Computes base = *(param_1 + 0xa8) + param_3 * 0x94 (stride = 148 bytes)
- If *(base + 0x48) > 1: issues sub-array lookup
  - If param_2 == 0xffffffff: returns *(base + 0x8c)
  - Else: validates param_2 < *(base + 0x50), index into sub-array at *(base + 0x4c) with stride 4, * 0x60 + *(base + 0x8c)
- Else: checks *(base + 0x90) && DAT_008b6ac4 → calls FUN_00551dd0 (flag bit clear), returns *(base + 0x8c)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xa4 | int | Element count |
| +0xa8 | pointer | Array base (stride 0x94) |

**Globals:**
- DAT_008b6ac4 — undocumented global, gates flag manipulation

**Calls:**
- FUN_00551dd0 — flag/bit manipulation

**Used by system:** docs/01-engine-architecture.md — indexed resource/object lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00553fa0 — State Field Set with Chained Init

Source: unknown | Confidence: high
Sets state field on struct, calls two init functions.

**Key logic:**
- *param_1 = param_2 (assign state)
- FUN_00553fc0(0) — init A
- FUN_00554610(0) — init B

**Calls:**
- FUN_00553fc0 — init function (docs/20-math-utilities.md)
- FUN_00554610 — render resource init (docs/19-renderer.md)

**Used by system:** docs/01-engine-architecture.md — engine module init

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00561e00 — Two-Step Init Call

Source: unknown | Confidence: high
Calls two initialization subroutines.

**Key logic:**
- FUN_00561ed0() — first init step
- FUN_00561e30() — second init step

**Calls:**
- FUN_00561ed0 — unknown init
- FUN_00561e30 — unknown init

**Used by system:** docs/01-engine-architecture.md — engine module init sequence

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00563ec0 — Switch Param Store + Global Set

Source: unknown | Confidence: medium
Stores params into struct, sets global, calls refresh.

**Key logic:**
- Empty switch on param_4 (cases 0,1,2,default — no-ops)
- *(param_1+0x80) = param_3
- *(param_1+0x84) = param_2
- DAT_008d46b4 = param_1
- FUN_00564a00() — refresh/update

**Globals:**
- DAT_008d46b4 — undocumented global pointer

**Calls:** FUN_00564a00 — update/refresh

**Used by system:** docs/01-engine-architecture.md — entity/engine configuration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00568d90 — Performance Counter Diff with Scaling

Source: unknown | Confidence: medium
Computes scaled time difference from performance counter values.

**Key logic:**
- Reads counter values from param_1[6],[7],[10],[0xb]
- Calls FUN_00568cb0 to get current time reference
- Computes: ((elapsed_hi - start_hi - borrow) * scale_double) + (elapsed_lo / freq) + offset_double
- Returns float10 result

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| [0] | uint | Frequency (denominator for low part) |
| [2] | double | Scale multiplier |
| [4] | double | Offset constant |
| [6] | uint | Start time low |
| [7] | uint | Start time high |
| [10] | uint | Elapsed threshold |
| [11] | uint | Adjust value |

**Calls:** FUN_00568cb0 — current time read

**Used by system:** docs/01-engine-architecture.md — timing/performance measurement

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0056ec00 — Batch Processing Loop, 3 Passes

Source: unknown | Confidence: high
Iterates 3 different counts, calls different process function per pass.

**Key logic:**
- Pass 1: iterates *(param_1+8) times, calls FUN_0056cf70()
- Pass 2: iterates *(param_1+0x10) times, calls FUN_0056d020()
- Pass 3: iterates *(param_1+0x18) times, calls FUN_0056d2d0()

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | int | Count for pass 1 |
| +0x10 | int | Count for pass 2 |
| +0x18 | int | Count for pass 3 |

**Calls:**
- FUN_0056cf70 — process pass 1
- FUN_0056d020 — process pass 2
- FUN_0056d2d0 — process pass 3

**Used by system:** docs/01-engine-architecture.md — batch update pipeline

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a580 — VTable Call via Offset 0x6c

Source: unknown | Confidence: high
Calls virtual method at vtable offset +0x6c on object.

**Key logic:**
- (**(code**)(*(int*)*param_1 + 0x6c))() — indirect vtable call

**Used by system:** docs/01-engine-architecture.md — virtual dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005836a0 — Large Structure Zero-Initialization

Source: unknown | Confidence: high
Zero-initializes large struct (0x48 words + extras).

**Key logic:**
- Zeroes param_1[0..7] (8 int fields)
- Loop: 0x3f iterations zeroing ints (63 more dwords = 252 bytes)
- Zeroes trailing short + byte
- param_1[0x48] = 0 (last field)

**Used by system:** docs/01-engine-architecture.md — large engine struct constructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585d20 — Mutex-Protected Pointer Read + Release

Source: unknown | Confidence: high
Reads shared value under mutex, releases mutex.

**Key logic:**
- Checks *(param_1+0x5b8) handle for NULL
- WaitForSingleObject(handle, *(param_1+0x5bc))
- If wait fails: nulls pointer
- Reads *puVar3 (value at param_1+0x5b4)
- ReleaseMutex(handle)
- Returns value

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x5b4 | undefined4 | Shared value |
| +0x5b8 | HANDLE | Mutex handle |
| +0x5bc | DWORD | Timeout (ms) |

**Calls:** WaitForSingleObject, ReleaseMutex (Win32 API)

**Used by system:** docs/01-engine-architecture.md — thread-safe shared state read

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_0058aa6f.

**Key logic:**
- Single jmp instruction to FUN_0058aa6f (operator delete / heap free)
- Used throughout codebase as memory deallocator

**Calls:** FUN_0058aa6f — heap deallocation function

**Used by system:** docs/01-engine-architecture.md — memory free wrapper (called from ~200+ locations)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a42f — SEH Exception Handler Trampoline Setup

Source: unknown | Confidence: medium
SEH setup with virtual method dispatch.

**Key logic:**
- SEH prologue (ExceptionList manipulation)
- Calls FUN_0058e0c7()
- Virtual method call via vtable+0x10
- SEH epilogue

**Calls:** FUN_0058e0c7 — unknown

**Used by system:** docs/01-engine-architecture.md — exception handler setup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058b903 — Semaphore-Guarded Query Call

Source: unknown | Confidence: medium
Resource lock, query function, resource unlock.

**Key logic:**
- Acquires resource lock
- Calls FUN_0058b92a()
- Releases resource lock

**Calls:** FUN_0058b92a — query function

**Used by system:** docs/01-engine-architecture.md — synchronization wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058d82c — Int Peek from Pointer

Source: unknown | Confidence: high
Reads int value at offset from stack pointer.

**Key logic:**
- Returns *(int*)((char*)&param_1 + 4)
- Dereferences pointer to get int value

**Used by system:** docs/01-engine-architecture.md — low-level memory access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593839 — Multi-Arg Rendering Dispatch with Layout

Source: unknown | Confidence: medium
Rendering dispatch with layout parameter setup.

**Key logic:**
- Sets up render state from multiple parameters
- Calls render function at PTR_005bd9f8 via 4-arg vtable dispatch
- Handles layout positioning arguments

**Calls:**
- Renders via function pointer PTR_005bd9f8

**Used by system:** docs/01-engine-architecture.md — UI/text rendering dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598775 — Vtable Fixup with Destructor

Source: unknown | Confidence: medium
Sets vtable pointer, calls destructor.

**Key logic:**
- *param_1 = &PTR_FUN_005b7e44 (vtable assignment)
- FUN_00598aea() — destructor/cleanup

**Calls:** FUN_00598aea — destructor/cleanup

**Used by system:** docs/01-engine-architecture.md — object lifecycle management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059977e — Cleanup Wrapper

Source: unknown | Confidence: high
Thunk: FUN_00587b3e(FUN_0047aa60)

**Key logic:**
- Calls FUN_00587b3e with FUN_0047aa60 as argument
- FUN_0047aa60 is an empty stub (no-op)

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/01-engine-architecture.md — cleanup delegation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599e66 — VTable Pointer Setter

Source: unknown | Confidence: high
Sets vtable pointer on object.

**Key logic:**
- *param_1 = &PTR_FUN_005b8e64
- Returns param_1

**Used by system:** docs/01-engine-architecture.md — object construction helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059b07a — Single Function Call Wrapper

Source: unknown | Confidence: high
Thunk: FUN_00587b3e(FUN_0047aa60)

**Key logic:**
- Calls FUN_00587b3e(FUN_0047aa60)
- FUN_0047aa60 is empty stub (no-op)

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/01-engine-architecture.md — cleanup delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c45a — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind handler calling FUN_00587bcf.

**Key logic:**
- MSVC exception handler trampoline
- Calls FUN_00587bcf(param_1) — free memory
- Returns to exception handling system

**Calls:** FUN_00587bcf — operator delete wrapper

**Used by system:** docs/20-math-utilities.md — exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c5c6 — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind handler calling FUN_00587bcf.

**Key logic:**
- MSVC exception handler trampoline
- Calls FUN_00587bcf — free memory

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c6c0 — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind handler calling FUN_00587bcf.

**Key logic:**
- MSVC exception handler trampoline
- Calls FUN_00587bcf — free memory

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c846 — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler calling FUN_00581ad0.

**Key logic:**
- MSVC exception handler trampoline
- Calls FUN_00581ad0() — cleanup

**Calls:** FUN_00581ad0 — cleanup function

**Used by system:** docs/01-engine-architecture.md — exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c9a0 — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler calling FUN_0047aa60 (empty stub).

**Key logic:**
- MSVC exception handler trampoline
- Calls FUN_0047aa60() — no-op

**Calls:** FUN_0047aa60 — empty stub

**Used by system:** docs/01-engine-architecture.md — exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cc00 — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind handler calling FUN_00583570.

**Calls:** FUN_00583570

**Used by system:** docs/20-math-utilities.md — exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cd88 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler calling FUN_005819c0.

**Calls:** FUN_005819c0

**Used by system:** docs/01-engine-architecture.md — exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cf3d — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind handler calling FUN_005861e0.

**Calls:** FUN_005861e0

**Used by system:** docs/20-math-utilities.md — exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d0a7 — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind handler calling FUN_0047aa60 (empty stub).

**Calls:** FUN_0047aa60 — empty stub

**Used by system:** docs/20-math-utilities.md — exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d248 — SEH Unwind Handler with Flag Check

Source: unknown | Confidence: medium
Conditional SEH unwind based on flag bit.

**Key logic:**
- Checks flag bit 0 on param_2
- If set: calls FUN_00598aea() — cleanup logic

**Calls:** FUN_00598aea — conditional cleanup

**Used by system:** docs/01-engine-architecture.md — conditional exception cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d470 — SEH Unwind with ~Exception Destructor

Source: unknown | Confidence: medium
SEH unwind cleaning up exception object.

**Key logic:**
- MSVC exception handler trampoline
- Calls destructor on exception object then FUN_00587bcf

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md — exception object cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d984 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thunk to FUN_004e9537.

**Key logic:**
- Unconditional jmp to FUN_004e9537

**Calls:** FUN_004e9537

**Used by system:** docs/01-engine-architecture.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005505a0 — Linked-List Animation Timer Decrement

Source: unknown | Confidence: medium
Decrements timer values in animation-linked structs for a given vehicle element.

**Key logic:**
- Guards: param_2 != 0, param_3 <= param_2+0xa4 (element count check)
- Calculates element base at param_2+0xa8 + param_3*0x94 (per-element stride 0x94)
- Only processes if element+0x48 > 1 (active count check)
- Walks linked list from param_1+0x204
- For each list node: if node matches param_2 (vehicle pointer at node-0xc), subtracts per-element timer value from stored timer
- Inner loop iterates iVar6 elements at stride 0x40 (16 ints per element)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x204 | AnimationListHead | int* | Linked list head pointer |
| +0x10 | NextNode | int* | Linked list next pointer (node stride) |
| +0x118 | ElementCount | int | Number of sub-elements in node |
| +0x11c | ElementBase | int* | Base of per-element data |
| -0xC (relative to element base) | VehicleMatchPtr | int | Vehicle pointer for matching |

**Calls:** None directly (pure struct manipulation)

**Used by system:** docs/01-engine-architecture.md — animation framework timer management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005997a1 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00598815() with no arguments.

**Key logic:**
- Single call to FUN_00598815
- No return value manipulation

**Calls:**
- FUN_00598815 — Target function

**Used by system:** docs/01-engine-architecture.md — call wrapper/glue

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00585d70 — Thread-Safe String Read with Mutex

Source: unknown | Confidence: high
Thread-safe string read from a shared buffer with mutex protection.

**Key logic:**
- Acquires mutex at param_1+0x618 via WaitForSingleObject (5ms timeout)
- If wait succeeds (not 0x102 ERROR_TIMEOUT, not 0xFFFFFFFF):
  - Reads uVar4 from param_1+0x5c4 (message/event code)
  - Sets param_1+0x5c4 = 0 (consumes event)
  - If param_2 != 0: copies string from param_1+0x5c8 into param_2 (self-relocating copy)
  - Sets param_1+0x5c8[0] = 0 (clears buffer)
  - Releases mutex
- Returns uVar4 (event code or 0)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x618 | BufferMutex | HANDLE | Protection mutex |
| +0x5C4 | EventCode | uint | Message/event identifier |
| +0x5C8 | StringBuffer | char[] | Shared string buffer |

**Calls:**
- WaitForSingleObject — Win32 API
- ReleaseMutex — Win32 API

**Used by system:** docs/01-engine-architecture.md — thread-safe inter-thread communication

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586a00 — Single Function Call Wrapper

Source: unknown | Confidence: high
Passthrough wrapper that calls FUN_00587510().

**Key logic:**
- Single call to FUN_00587510() with no argument modification
- No return value manipulation

**Calls:**
- FUN_00587510 — Target function

**Used by system:** docs/01-engine-architecture.md — call wrapper/glue

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587310 — Binary Packet Field Parser with Offset Math

Source: unknown | Confidence: medium
Parses a binary packet header, extracting fields into a struct at specific offsets.

**Key logic:**
- Reads first ushort from param_2 (packet header)
- If ushort == 0: returns 0 (empty/invalid)
- If ushort > 0xB: calls FUN_00587510(param_2+1, ushort-0xB) — validates body length
- Extracts 3 fields from the packet body:
  - param_1+0x10 = *(uint*)(param_2+1 + (ushort-0xB)) — field at relative offset
  - param_1+0x14 = *(uint*)(param_2+1 + (ushort-7)) — field at ushort-7
  - param_1+0x18 = *(byte*)(param_2+1 + (ushort-3)) — field at ushort-3
- Returns success flag with upper byte = 1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | Field1 | uint | Parsed from packet |
| +0x14 | Field2 | uint | Parsed from packet |
| +0x18 | Field3 | byte | Parsed from packet |

**Calls:**
- FUN_00587510 — Validation function

**Used by system:** docs/01-engine-architecture.md — binary protocol/data parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058957a — Interrupt Dispatch

Source: unknown | Confidence: high
Dispatches a CPU interrupt (__cintrindisp2).

**Key logic:**
- Calls __cintrindisp2() — compiler interrupt dispatch intrinsic
- Used for structured exception handling or callback dispatch

**Calls:** __cintrindisp2 — compiler interrupt dispatch

**Used by system:** docs/01-engine-architecture.md — SEH/interrupt dispatch

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0058d839 — Pointer Advance + Read-Back

Source: unknown | Confidence: high
Advances an int pointer by 8 bytes, returns the value before advancement as 64-bit.

**Key logic:**
- *param_1 = *param_1 + 8 — advance pointer by 8 bytes
- Returns *(int64*)(*param_1 - 8) — read-back the 64-bit value at previous position
- Iteration helper for reading 8-byte values from a buffer

**Calls:** None

**Used by system:** docs/01-engine-architecture.md — buffer iteration helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00590440 — Short-in-Range Check Against Static Table

Source: unknown | Confidence: high
Checks if a short value is present in a static lookup table.

**Key logic:**
- Iterates static table DAT_005e7204 to DAT_005e7217 (20 bytes = 10 shorts)
- Compares param_1 against each entry
- Returns 0 if found, 1 if not found (inverse logic)

**Calls:** None

**Used by system:** docs/01-engine-architecture.md — validation/range check utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005938b4 — SEH Wrapper Around CRT Function Call

Source: unknown | Confidence: medium
SEH-guarded wrapper that sets up TLS values then calls a function.

**Key logic:**
- Sets up SEH handler (pushes ExceptionList stack frame)
- Calls FUN_0058e0c7() three times (TLS value retrieval)
- Sets TLS[+0x6c] = param_1 and TLS[+0x70] = param_3
- Calls FUN_0058a3b6(param_2, param_4, param_5, param_6, param_7)
- SEH cleanup via FUN_00593981() then restores ExceptionList

**Calls:**
- FUN_0058e0c7 — TLS value retrieval
- FUN_0058a3b6 — Target function
- FUN_00593981 — SEH cleanup/destroy

**Used by system:** docs/01-engine-architecture.md — SEH-guarded function call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598794 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00598e2e(0) — dispatches a function with argument 0.

**Key logic:**
- Single call to FUN_00598e2e with parameter 0
- No return value manipulation

**Calls:**
- FUN_00598e2e — Target function

**Used by system:** docs/01-engine-architecture.md — call wrapper/glue

**Moddability:** hardcoded

Source: unknown | Confidence: medium
Routes to one of two lookup functions based on a flag.

**Key logic:**
- If param_1[4] (index 4) == 0: calls FUN_0058ace6(*param_1) — string-based lookup
- Else: calls FUN_00535550() — alternate lookup path

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0 | ResourceKey | undefined4 | Key/identifier for lookup |
| +0x10 | LookupModeFlag | undefined4 | 0 = primary path, else = secondary |

**Calls:**
- FUN_0058ace6 — Resource lookup (primary)
- FUN_00535550 — Resource lookup (secondary/fallback)

**Used by system:** docs/20-math-utilities.md — dispatcher with dual lookup path

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057adc0 — Free Callback Registration

Source: unknown | Confidence: high
Registers a cleanup callback function.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0057add0) — register callback address for later cleanup
- LAB_0057add0 is a nearby code label (the callback target)

**Calls:**
- FUN_00587b3e — Callback registration

**Used by system:** docs/01-engine-architecture.md — cleanup/finalization registration

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057c950 — Thread-Safe Linked-List Lookup with Mutex + Data Copy

Source: unknown | Confidence: high
Thread-safe lookup in a linked list protected by a mutex. Searches by index, copies found data.

**Key logic:**
- If param_4 (index) is NULL: returns early with header info (param_1+0x910 written to param_2, param_2[1]= -1)
- Acquires mutex at param_1+0xad8 via WaitForSingleObject with timeout from param_1+0xadc
- Validates index: -1 < param_4 < puVar3[3] (list size)
- Walks linked list: follows [1] (next pointer) for iVar4 steps
- If node found and *piVar1 != 0: calls FUN_004b3db0 (data copy/retrieval), copies 4 dwords to param_2
- Releases mutex via ReleaseMutex

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x910 | HeaderField | uint16 | Written to param_2[2] |
| +0xAD8 | ListMutex | HANDLE | Protection mutex |
| +0xADC | MutexTimeout | DWORD | Wait timeout in ms |
| +0xAC8 | ListBase | int* | Linked list head + size struct |

**Calls:**
- WaitForSingleObject — Win32 API
- ReleaseMutex — Win32 API
- FUN_004b3db0 — Data copy/retrieval

**Used by system:** docs/01-engine-architecture.md — thread-safe container access

**Moddability:** hardcoded

## FUN_00558e10 — Pixel Write to Texture Buffer

Source: unknown | Confidence: medium
Writes pixel color data into a texture/surface buffer at computed offset.

**Key logic:**
- Guard: param_1+0x4c must equal 1 (surface type or format check)
- Guard: param_1+0x20 must be negative (byte sign check)
- Calls FUN_00558d10(0) — clear/reset
- Computes pixel address from:
  - param_2 * 0x80 + 4 (row offset, 128-byte stride)
  - Multiplied by param_1+0x24 (width factor)
  - Plus param_3 (column offset)
  - Total * 0x40 (64-byte pixel stride)
  - Added to surface base at param_1+0x50→+0x20
- Writes param_4, param_5, param_6, param_7 at offsets 0, 4, 8, 0x18 (color channels or pixel components)

**Calls:**
- FUN_00558d10(0) — clear/reset

**Used by system:** docs/19-renderer.md — texture/surface pixel manipulation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055c7d0 — Input State Query Wrapper

Source: unknown | Confidence: high
Reads an input state value via a driver/device function call.

**Key logic:**
- Calls FUN_0055c450(param_1+0x13ec, 0, &local_4) — queries input device state
- Returns local_4 (the queried value)
- Offset 0x13ec from param_1 is large — likely a per-player input device struct

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x13EC | InputDeviceHandle | int | Handle/ptr to input device |

**Calls:**
- FUN_0055c450 — Input state query function

**Used by system:** docs/01-engine-architecture.md — input handling layer

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055fe30 — Dual Field Cleanup with Null Checks

Source: unknown | Confidence: high
Cleans up two fields in a struct, freeing memory via different deallocation paths.

**Key logic:**
- If param_1+0x10 != 0: calls FUN_00587d02 and sets to 0 (specialized cleanup)
- If param_1+0x128 != 0: calls FUN_00587bcf (generic free) and sets to 0
- Uses two distinct free paths suggesting different allocation types

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | CleanupField1 | int* | Freed via FUN_00587d02 |
| +0x128 | CleanupField2 | int* | Freed via FUN_00587bcf |

**Calls:**
- FUN_00587d02 — Free/deallocate (specialized)
- FUN_00587bcf — Free/deallocate (generic)

**Used by system:** docs/01-engine-architecture.md — object cleanup/destructor helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00561ed0 — Tick Count Comparison, Handle Inactivity Timeout

Source: unknown | Confidence: high
Checks elapsed time via GetTickCount, triggers timeout functions and increments a counter on prolonged inactivity.

**Key logic:**
- Guards: param_1+4 must not be -1 (initialized check)
- If 300000ms (5 min) elapsed since param_1+0xd8 timestamp OR timestamp is 0 OR timer rolled over (DVar2 < uVar1): calls FUN_00562ac0 (timeout handler)
- If 30000ms (30s) elapsed AND param_1+0xe8 > 0: calls FUN_00562ac0, increments counter at param_1+0xe8, resets to 0 if > 10

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x4 | InitFlag | int | -1 = uninitialized |
| +0xD8 | LastActivityTick | uint | Last activity timestamp (ms) |
| +0xE8 | IdleCounter | char | Consecutive idle intervals counter |

**Globals:** GetTickCount() — Win32 API

**Calls:**
- FUN_00562ac0 — Timeout/activity handler

**Used by system:** docs/01-engine-architecture.md — idle/timeout detection in game loop

**Moddability:** hardcoded (thresholds 300000ms, 30000ms, cap at 10)

<!-- target: docs/01-engine-architecture.md -->

## FUN_00564270 — Singleton/Global Accessor with Fallback Alloc

Source: unknown | Confidence: medium
Retrieves a singleton value with lazy initialization fallback.

**Key logic:**
- Calls FUN_005647d0() — attempts to get existing singleton pointer
- If non-null: returns *pointer (dereferences)
- If null: calls FUN_00564690() (allocate), then FUN_00564780() (register), returns result

**Calls:**
- FUN_005647d0 — Singleton/global getter
- FUN_00564690 — Singleton/global allocator
- FUN_00564780 — Singleton/global registrar

**Used by system:** docs/01-engine-architecture.md — singleton management pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005649d0 — Call Chain Wrapper

Source: unknown | Confidence: high
Two-call sequence wrapper: calls FUN_00564890() then FUN_00564960(param_1).

**Key logic:**
- Sequential call pattern — likely prepare-then-execute
- No return value manipulation

**Calls:**
- FUN_00564890 — Prepare/setup call
- FUN_00564960 — Primary operation call

**Used by system:** docs/01-engine-architecture.md — call chain glue

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00550620 — Scrolling Data Offset Across Linked Entries

Source: unknown | Confidence: medium
Iterates linked list at param_1+0x204, conditionally adds a value from a data table entry to matched elements.

**Key logic:**
- Guard: returns if param_2 == 0, or param_3 exceeds count at param_2+0xa4
- Computes table row: `row = *(param_2 + 0xa8) + param_3 * 0x94` — index into data table with stride 0x94
- Guard: returns if row's count field at +0x48 <= 1
- Walks linked list at param_1+0x204 (nodes linked via +0x10 next pointer)
- For each node: if node+0x118 (count) > 0, iterates array at node+0x11c, stride 64 bytes per element
  - Compares element ID at +0x04 against param_2
  - On match: adds row value at +0x50 to element value at +0x34 (conditional: if current < value, adds them; otherwise just stores value)
- No return value — modifies linked list elements in place

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x204 | LinkedListHead | pointer | Linked list, nodes via +0x10 next |

**Struct offsets (param_2 — data table):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xa4 | TableCount | int | Upper bound for param_3 index |
| +0xa8 | TableBase | pointer | Base of data array, stride 0x94 |
| +0x48 | RowActiveCount | int | Per-row active element count |
| +0x50 | RowValue | int | Value to add to matched elements |

**Calls:** none (pure logic, no sub-calls)

**Used by system:** docs/01-engine-architecture.md — data scrolling/iteration over linked structures

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00551f80 — Conditional Free with Bink Close

Source: unknown | Confidence: high
Conditional resource cleanup: closes Bink video, calls no-op stub, frees memory.

**Key logic:**
- If param_1 != 0 (non-null pointer):
  - Calls `FUN_00551ce0` (BinkClose — audio/video library wrapper)
  - Calls `FUN_00557470` (no-op stub)
  - Calls `FUN_00587bcf` (heap memory deallocation) with param_1
- Returns otherwise with no action

**Calls:**
- FUN_00551ce0 — BinkClose, closes Bink video/audio stream
- FUN_00557470 — no-op stub (empty function, likely placeholder)
- FUN_00587bcf — heap memory free

**Used by system:** docs/01-engine-architecture.md — resource cleanup for Bink-backed object

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005544c0 — Game State Setting via Virtual Dispatch

Source: unknown | Confidence: high
Maps input parameter (0, 1, 2) to state values (1, 3, 2) and dispatches to global virtual device with parameter ID 0xd (13). Stores the input value.

**Key logic:**
- Early returns if param_2 == -1 or param_2 matches current stored state at param_1[0xe] (no change)
- Maps param_2: 0→1, 1→3, 2→2; other values skip to store step
- Calls through global virtual device: `(**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0, *param_1, 0xd, mappedValue)`
  - DAT_008b89a0: global game state device
  - +0xfc: vtable slot 63 (set state parameter)
  - 0xd: state parameter ID (13)
- Stores param_2 to param_1[0xe] (offset +0x38) for change detection

**Globals:**
- `DAT_008b89a0` — global game state device object (virtual dispatch)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x38 | CurrentState | int | Cached state value for change detection |

**Calls:** none direct — virtual dispatch through DAT_008b89a0

**Used by system:** docs/01-engine-architecture.md — game state machine; maps logical state values to device state IDs

**Moddability:** hookable — state dispatch via global virtual device

<!-- target: docs/20-math-utilities.md -->

## FUN_005592b0 — Doubly-Linked List Node Removal by Pointer

Source: unknown | Confidence: high
Walks a doubly-linked list, finds a node by pointer address, unlinks and frees it.

**Key logic:**
- Loads head node from param_1 + 0x148
- Walks list forward via next pointer at +0x68
- Compares each node address against param_2 (pointer match)
- On match:
  - Unlinks: adjusts prev node's next (+0x68) and next node's prev (+0x64)
  - If matched node is head: updates head to node's next
  - Calls FUN_005574b0 (complex sub-element cleanup)
  - Calls FUN_00557470 (no-op stub)
  - Calls FUN_00587bcf (heap free) on matched node
- Decrements count at param_1+0x144; if reaches 0, clears head (+0x148)
- Returns 0 on success; loops until match or null

**Struct offsets (param_1 — list container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x144 | NodeCount | int | Running total, decremented on removal |
| +0x148 | HeadPtr | pointer | Head of doubly-linked list |

**Struct offsets (node):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x64 | Prev | pointer | Previous node |
| +0x68 | Next | pointer | Next node |

**Calls:**
- FUN_005574b0 — complex sub-element cleanup at matched node
- FUN_00557470 — no-op stub
- FUN_00587bcf — heap memory free

**Used by system:** docs/01-engine-architecture.md — data structure management, doubly-linked list node removal

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055c7f0 — Key Event Dispatch to Sub-Handlers

Source: unknown | Confidence: high
Input event dispatcher. Maps object state to handler ID, dispatches key events (0x200000) to sub-handlers based on mapped state.

**Key logic:**
- Reads identifier from param_1+0x1544, maps via `FUN_0055c650` (integer-to-ID switch dispatch) to local_8
- Passes local_8 through `FUN_0055c450` (key-to-values mapper) for validation
- If param_2 == 0x200000 (key event constant):
  - If mapped state == 0x20: calls `FUN_0055c7d0` which reads field at param_1+0x13ec and maps through FUN_0055c450, returns result
  - If mapped state == 0x10: calls `FUN_0055c7b0` which reads field at param_1+0x13e8 and maps through FUN_0055c450, returns result
- Returns 0xffffffff (-1) if no match or param_2 != 0x200000

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1544 | ControlID | int | Control/binding identifier |
| +0x13e8 | BindingValueA | int | Read when state==0x10 |
| +0x13ec | BindingValueB | int | Read when state==0x20 |

**Calls:**
- FUN_0055c650 — integer-to-ID mapping with switch dispatch
- FUN_0055c450 — key/ID to values mapper (477 bytes, complex switch)
- FUN_0055c7d0 — sub-handler for state 0x20, reads +0x13ec
- FUN_0055c7b0 — sub-handler for state 0x10, reads +0x13e8

**Used by system:** docs/01-engine-architecture.md — input handling; dispatches key events to bound actions

**Moddability:** hookable — maps control bindings to actions

<!-- target: docs/19-renderer.md -->

## FUN_00568f20 — Multi-Field Pointer Cleanup with Null Checks

Source: unknown | Confidence: high
Frees multiple allocated sub-objects via FUN_00587bcf with null checks. Zeros adjacent fields.

**Key logic:**
- If *param_1 (field at +0x00) non-null: frees via FUN_00587bcf, sets to 0
- Zeros fields at +0x224, +0x228, +0x22c (indices 0x89, 0x8a, 0x8b)
- If field at +0x230 (index 0x8c) non-null: frees, sets to 0
- Zeros field at +0x234 (index 0x8d)
- If field at +0x238 (index 0x8e) non-null: frees, sets to 0
- Zeros field at +0x23c (index 0x8f)
- If field at +0x240 (index 0x90) non-null: frees, sets to 0
- No return value

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x000 | PrimaryPtr | pointer | Freed if non-null |
| +0x224 | Field_0x224 | int | Zeroed (count/capacity?) |
| +0x228 | Field_0x228 | int | Zeroed |
| +0x22c | Field_0x22c | int | Zeroed |
| +0x230 | SubBufferA | pointer | Freed if non-null |
| +0x234 | Field_0x234 | int | Zeroed |
| +0x238 | SubBufferB | pointer | Freed if non-null |
| +0x23c | Field_0x23c | int | Zeroed |
| +0x240 | SubBufferC | pointer | Freed if non-null |

**Calls:**
- FUN_00587bcf — heap memory free (called up to 4 times)

**Used by system:** docs/01-engine-architecture.md — object cleanup/destructor helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0056f060 — Batch Iteration with Counter

Source: unknown | Confidence: high
Loops *param_1 times calling a physics transform update function each iteration.

**Key logic:**
- Reads iteration count from *param_1 (dereferenced pointer)
- Loops count times, calling FUN_0056a150 each iteration
- No other logic — pure batch iteration

**Calls:**
- FUN_0056a150 — copy struct fields + 3x3 matrix×vector multiply (physics transform update)

**Used by system:** docs/01-engine-architecture.md — batch physics transform updates for N objects

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0057adf0 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper — unconditionally calls FUN_00599958.

**Key logic:**
- Calls FUN_00599958 (object constructor with SEH + vtable init)
- Returns void

**Calls:**
- FUN_00599958 — object constructor with SEH frame and vtable initialization (docs/08)

**Used by system:** docs/01-engine-architecture.md — call stub / constructor wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057d5d0 — Structured Memory Copy with Header Prepend

Source: unknown | Confidence: medium
Copies structured data from source object into output buffer with a computed header. Includes a buffer validation step.

**Key logic:**
- Reads source pointer from param_1+0x14
- Computes byte count from param_1+0x24: `(field & 7) != 0 + (field >> 3)` — bit-field to byte count with round-up
- Writes header at *param_2: byte count as short at offset +0, unknown value from FUN_0053d880 at offset +2
- Copies source data to output (4-byte chunks + trailing bytes)
- Calls FUN_00587580 (buffer query: return ptr+size if valid) on param_2 and param_1
- Appends additional data from param_2 to output (second copy pass)
- Returns CONCAT31(..., 1)

**Struct offsets (param_1 — source object):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14 | SourceDataPtr | pointer | Pointer to source data |
| +0x24 | BitField | uint | Encoded size: lower 3 bits flag + shifted value |

**Calls:**
- FUN_0053d880 — short computation (returns small int written to header)
- FUN_00587580 — buffer query: validate/return ptr+size

**Used by system:** docs/01-engine-architecture.md — data serialization with header construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00582310 — CloseHandle Wrapper

Source: unknown | Confidence: high
Conditional Win32 CloseHandle wrapper. Checks enable flag before closing.

**Key logic:**
- If byte flag at param_1+0x18 is non-zero:
  - Calls `CloseHandle(*(HANDLE *)(param_1 + 0x10))`
  - If successful (non-zero return): zeros the handle field at +0x10

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | Win32Handle | HANDLE | Handle to close |
| +0x18 | CloseEnabled | byte | Flag: non-zero = allow close |

**Calls:**
- CloseHandle — Win32 API kernel32.dll

**Used by system:** docs/01-engine-architecture.md — system resource handle cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583d40 — Mutex-Protected Data Read with Timed Wait

Source: unknown | Confidence: high
Reads a byte of data protected by a per-entry mutex with configurable timeout.

**Key logic:**
- Computes entry pointer: `param_1 + 0x0c + param_2 * 0x28` (stride 40 bytes per entry)
- Loads mutex handle from entry+0x04
- If mutex handle is null: returns 0
- Calls `WaitForSingleObject(mutex, *(DWORD*)(entry + 0x08))` with timeout from entry+0x08
  - If wait fails (non-zero) AND error is not WAIT_TIMEOUT (0x80): returns 0
- Reads data byte from entry+0x00
- Calls `ReleaseMutex(mutex)` to release
- Returns read data byte

**Struct offsets (per entry, stride 0x28):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | DataByte | byte | Protected value being read |
| +0x04 | MutexHandle | HANDLE | Win32 mutex |
| +0x08 | TimeoutMs | DWORD | WaitForSingleObject timeout |

**Calls:**
- WaitForSingleObject — Win32 API (kernel32)
- ReleaseMutex — Win32 API (kernel32)

**Used by system:** docs/01-engine-architecture.md — thread-safe data access with mutex

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585de0 — QueueUserAPC Async Procedure Call

Source: unknown | Confidence: high
Queues an Asynchronous Procedure Call (APC) to a thread via Win32 QueueUserAPC.

**Key logic:**
- Calls `QueueUserAPC(FUN_0041a160, *(HANDLE *)(param_1 + 4), param_1)`
  - APC function: FUN_0041a160
  - Thread handle: from param_1+4
  - Context parameter: param_1 itself
- Returns void

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | ThreadHandle | HANDLE | Target thread handle for APC |

**Calls:**
- QueueUserAPC — Win32 API (kernel32)
- FUN_0041a160 — APC callback procedure

**Used by system:** docs/01-engine-architecture.md — async thread communication via APC

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586a10 — Bounded Memory Copy with Size Validation

Source: unknown | Confidence: high
Copies data from validated buffer to destination with minimum size check. Returns status code.

**Key logic:**
- Gets min size from `FUN_0053d880()` (short computation, returns a threshold)
- If param_2 < min size: returns 4 (insufficient size)
- Calls `FUN_00587580` (buffer validation: return ptr+size if valid)
- If buffer valid:
  - Copies param_2 bytes from source to dest (4-byte dword chunks + trailing bytes)
  - If param_3 non-null: stores actual copied size in *param_3
  - Returns 0 (success)
- Returns 1 (buffer invalid)

**Return codes:**
| Code | Meaning |
|------|---------|
| 0 | Success |
| 1 | Buffer validation failed |
| 4 | param_2 below minimum size threshold |

**Calls:**
- FUN_0053d880 — short computation (returns minimum size threshold)
- FUN_00587580 — buffer query: validate and return ptr+size

**Used by system:** docs/01-engine-architecture.md — safe memory copy with validation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587370 — Copy Buffer Header Fields + Call Init

Source: unknown | Confidence: high
Copies header fields from source to destination, calls sub-buffer initialization. Returns destination pointer.

**Key logic:**
- Calls `FUN_00587620(param_2 + 4)` — buffer write/init on source+4
- Copies fields from param_2 (source) to param_1 (dest):
  - +0x10, +0x14: two dwords (32-bit values)
  - +0x18, +0x19: two bytes
- Returns param_1 (dest pointer)

**Struct offsets (param_1/param_2 — buffer header):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | SubBuffer | bytes | Initialized via FUN_00587620 |
| +0x10 | Field_0x10 | uint | Copied from source |
| +0x14 | Field_0x14 | uint | Copied from source |
| +0x18 | Field_0x18 | byte | Copied from source |
| +0x19 | Field_0x19 | byte | Copied from source |

**Calls:**
- FUN_00587620 — buffer write/init with parameters (buffer management)

**Used by system:** docs/01-engine-architecture.md — buffer header copying and sub-buffer init

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587c03 — operator new(uint) → __nh_malloc Wrapper

Source: CRT (Visual Studio 2003 Release) | Confidence: high
MSVC C++ operator new — allocates memory via __nh_malloc.

**Key logic:**
- Calls `__nh_malloc(param_1, 1)` — no-throw malloc with size param_1
- Returns allocated pointer (or null on failure)

**Calls:**
- `__nh_malloc` — MSVC CRT internal malloc (no-throw, returns null on failure)

**Used by system:** docs/01-engine-architecture.md — C++ memory allocation (used throughout codebase)

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_005905dd — Hex String to Int Parser

Source: unknown | Confidence: high
Parses a hexadecimal string to integer. Handles digits 0-9, letters A-F and a-f.

**Key logic:**
- Iterates input string char by char until null terminator
- Char conversion:
  - 'a'-'f': subtract 0x27 (39) to get value 10-15
  - 'A'-'F': subtract 7 (after '@' check) to get value 10-15
  - Other chars (including '0'-'9'): used as-is (ASCII value, but char conversion handles it — '0' through '9' map to 0-9 naturally due to how the arithmetic works out)
- Accumulates: `result = (result - 3) * 16 + charValue` (the -3 offset may be a Ghidra decompilation artifact)

**Calls:** none (pure logic)

**Algorithm family:** string parsing — hex to int

**Used by system:** docs/01-engine-architecture.md — config/string parsing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00593981 — Exception Frame Data Setup

Source: CRT / MSVC runtime | Confidence: medium
SEH exception handler frame initialization. Copies frame data, registers handlers, validates exception code.

**Key logic:**
- Copies frame data: `*(esi - 4) = *(ebp - 0x28)`
- Gets handler via `FUN_0058e0c7()`, sets field at +0x6c from frame
- Gets handler again via `FUN_0058e0c7()`, sets field at +0x70 from frame
- Validates exception block at *unaff_EDI:
  - Check 1: `*edi == 0xe06d7363` (0x1f928c9d = negated MSVC exception code E06D7363)
  - Check 2: `edi[4] == 3` (exception type/version)
  - Check 3: `edi[5] == 0x19930520` (exception magic/date stamp)
  - Check 4: `*(ebp - 0x24) == 0` (some flag)
  - Check 5: `*(ebp - 0x2c) != 0` (some pointer is non-null)
- If all checks pass: calls `__abnormal_termination()` then `FUN_00593bbd()`

**Calls:**
- FUN_0058e0c7 — SEH handler lookup/registration (called twice)
- __abnormal_termination — MSVC CRT terminate handler
- FUN_00593bbd — exception handler body

**Used by system:** docs/01-engine-architecture.md — MSVC exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_005987f0 — Locale Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00598a41 with fixed arguments (0, 1).

**Key logic:**
- Calls `FUN_00598a41(0, 1)` unconditionally
- Returns void

**Calls:**
- FUN_00598a41 — locale/encoding function

**Used by system:** docs/01-engine-architecture.md — locale initialization/setup call

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_005997ab — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00587b3e with a code pointer argument.

**Key logic:**
- Calls `FUN_00587b3e(&LAB_005997b7)` — passes address of code label
- Returns void

**Calls:**
- FUN_00587b3e — function taking code pointer

**Used by system:** docs/01-engine-architecture.md — call stub

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a2d0 — Locale Encoding Check

Source: unknown | Confidence: medium
Validates locale encoding conversion. Checks field and calls conversion function.

**Key logic:**
- Reads field from param_1+0x50
- If field is 0: returns 0 (failure)
- If field is non-zero: calls `FUN_0059bb00(field, param_2, 0, param_3 * 2)` 
  - If conversion returns 0: returns param_1 (success)
  - If conversion returns non-zero: returns 0 (failure)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x50 | EncodingObj | pointer | Locale encoding object |

**Calls:**
- FUN_0059bb00 — locale/encoding conversion function

**Used by system:** docs/01-engine-architecture.md — locale/character encoding validation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a8bc — Sub-Call + Conditional Free

Source: unknown | Confidence: high
Calls a sub-function, then conditionally frees param_1 based on flag bit.

**Key logic:**
- Calls `FUN_0059a86c()` — sub-function call
- If param_2 has bit 0 set: calls `FUN_00587bcf(param_1)` — free memory
- Returns param_1 unchanged

**Calls:**
- FUN_0059a86c — sub-function
- FUN_00587bcf — heap memory free (conditional)

**Used by system:** docs/01-engine-architecture.md — cleanup helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059b390 — Dual-Pointer Free

Source: unknown | Confidence: high
Frees two pointers stored in an array/struct.

**Key logic:**
- Frees `*param_1` (first pointer, at +0x00)
- Frees `param_1[2]` (third element, at +0x08)
- Both freed via FUN_00587bcf

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | PointerA | pointer | Freed via FUN_00587bcf |
| +0x08 | PointerC | pointer | Freed via FUN_00587bcf |

**Calls:**
- FUN_00587bcf — heap memory free (twice)

**Used by system:** docs/01-engine-architecture.md — simple dual-pointer cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c482 — SEH Unwind with Field Free

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — frees local variable at EBP-0x2c.

**Key logic:**
- Reads pointer from `unaff_EBP - 0x2c` (caller's stack frame local)
- Frees it via `FUN_00587bcf`
- No return manipulation (standard SEH unwind cleanup)

**Calls:**
- FUN_00587bcf — heap memory free

**Used by system:** docs/01-engine-architecture.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c5da — SEH Unwind Free Object at +8

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — frees pointer at EBP+8 (first stack parameter).

**Key logic:**
- Reads pointer from `unaff_EBP + 8` (caller's first stack argument)
- Frees it via `FUN_00587bcf`

**Calls:**
- FUN_00587bcf — heap memory free

**Used by system:** docs/01-engine-architecture.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c6d4 — SEH Unwind Free Object at +8 (Duplicate)

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — identical pattern to FUN_0059c5da. Frees pointer at EBP+8.

**Key logic:**
- Reads pointer from `unaff_EBP + 8` (caller's first stack argument)
- Frees it via `FUN_00587bcf`

**Calls:**
- FUN_00587bcf — heap memory free

**Used by system:** docs/01-engine-architecture.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c9d0 — SEH Unwind Cleanup Call

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls FUN_0047aa60.

**Key logic:**
- Calls FUN_0047aa60 (cleanup/object destructor)

**Calls:**
- FUN_0047aa60 — cleanup function

**Used by system:** docs/01-engine-architecture.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cf53 — SEH Unwind Cleanup Call

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls FUN_00586210.

**Key logic:**
- Calls FUN_00586210

**Calls:**
- FUN_00586210 — cleanup/teardown function

**Used by system:** docs/01-engine-architecture.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d0bd — SEH Unwind Cleanup Call (dup)

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls FUN_0047aa60 (same as FUN_0059c9d0).

**Key logic:**
- Calls FUN_0047aa60

**Calls:**
- FUN_0047aa60 — cleanup function

**Used by system:** docs/01-engine-architecture.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059dad5 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004e513e unconditionally.

**Key logic:**
- Calls FUN_004e513e

**Calls:**
- FUN_004e513e — target function

**Used by system:** docs/01-engine-architecture.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004066c0 — Mutex-Protected Value Read with Timeout

Source: unknown | Confidence: high
Reads a value protected by a mutex with configurable timeout. Returns -1 on failure.

**Key logic:**
- Checks mutex handle at param_1+0x50; if null returns -1
- Calls `WaitForSingleObject(mutex, *(DWORD*)(param_1+0x54))` with timeout
- If wait succeeds (0) or times out (0x80): reads value from param_1+0x4c
- If mutex handle non-null after wait: calls ReleaseMutex
- Returns read value, or -1 on failure

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x4c | Value | uint | Protected value to read |
| +0x50 | MutexHandle | HANDLE | Win32 mutex |
| +0x54 | TimeoutMs | DWORD | Wait timeout in ms |

**Calls:**
- WaitForSingleObject — Win32 API
- ReleaseMutex — Win32 API

**Used by system:** docs/01-engine-architecture.md — thread-safe value read

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d850 — Object Release with Vtable Call

Source: unknown | Confidence: high
Frees sub-object via virtual method, zeros field, calls cleanup.

**Key logic:**
- Calls FUN_00540760
- If param_1[0x43f] (sub-object) non-null: calls its virtual method at +8, stores result in *param_1, zeros param_1[0x43f]
- Returns 0

**Calls:**
- FUN_00540760
- (indirect virtual) sub-object vtable+8

**Used by system:** docs/01-engine-architecture.md — object release

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005410f0 — Guarded Virtual Decrement

Source: unknown | Confidence: medium
If guard passes, calls virtual method and optionally decrements counter.

**Key logic:**
- If param_2 non-null and param_2+0x18 non-null: calls virtual method +0x30
- Stores result in *param_1
- If result == 0: decrements param_2+0x0c

**Calls:**
- (indirect virtual) vtable+0x30

**Used by system:** docs/01-engine-architecture.md — guarded refcount

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00546370 — Array Cleanup with Dual Free

Source: unknown | Confidence: high
Frees array of sub-objects (stride 0x94). Two-pointer cleanup per entry.

**Key logic:**
- If param_1+0xa8 non-null:
  - Iterates count at +0xa4: for each entry (stride 0x94):
    - Frees pointer at +0x4c from base
    - Frees pointer at +0x90 from base (with FUN_00557470 no-op stub first)
  - Frees the allocation block itself (with reference count decrement)
- Zeros param_1+0xa8

**Calls:**
- FUN_00587bcf — heap free (multiple)
- FUN_00557470 — no-op stub

**Used by system:** docs/01-engine-architecture.md — cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00547400 — Guarded Call with Status

Source: unknown | Confidence: high
Calls FUN_00548620 if param_1 non-null, returns -1 on failure.

**Key logic:**
- If param_1 != 0: calls FUN_00548620(param_1). If non-zero: returns -1
- Returns 0

**Calls:**
- FUN_00548620

**Used by system:** docs/01-engine-architecture.md — guarded call

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00548eb0 — Multi-List Free with Traversal

Source: unknown | Confidence: high
Frees 5 linked lists of objects at +0xe8, +0xf0, +0xf8, +0xfc, +0xec with different traversal strides.

**Key logic:**
- For each of 4 lists (stride variants at +0xe8, +0xf0, +0xf8, +0xfc): walks linked list using next pointer at node+0x14 or +0x34, frees each node via FUN_004b0170 + FUN_00587bcf
- Fifth list at +0xec uses different stride (+0x4c) and custom FUN_00549110 instead of FUN_004b0170
- Zeros all list heads after cleanup

**Calls:**
- FUN_004b0170 — pre-free callback
- FUN_00587bcf — heap free
- FUN_00549110 — custom per-node cleanup (5th list)

**Used by system:** docs/01-engine-architecture.md — multi-list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0056cf10 — Quad-Pointer Free

Source: unknown | Confidence: high
Frees 4 pointers with null checks.

**Key logic:**
- Checks and frees param_1[0], [1], [2], [3] via FUN_00587bcf
- Zeros each after freeing

**Calls:**
- FUN_00587bcf (up to 4 times)

**Used by system:** docs/01-engine-architecture.md — cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ae7d — C++ Object Constructor with Vtable

Source: unknown | Confidence: medium
C++ object constructor with SEH frame, copies field from source, sets vtable.

**Key logic:**
- SEH prologue: FUN_0058a5d8
- Calls FUN_0059bf56(iVar2) with source parameter
- Copies byte from iVar2+0xc to extraout_ECX+3
- Calls FUN_005993af(0) and FUN_0059a9ca(iVar2+0xc, 0, DAT_005b9c38)
- Sets vtable to PTR_FUN_005b9d7c
- Returns constructed object pointer

**Globals:**
- DAT_005b9c38 — setup constant

**Calls:**
- FUN_0058a5d8 — SEH init
- FUN_0059bf56 — source setup
- FUN_005993af — init
- FUN_0059a9ca — field init

**Used by system:** docs/01-engine-architecture.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00554510 — Enum-to-ID Mapping with VTable Notify

Source: unknown | Confidence: medium
Maps an enum parameter (0/1/2) to a notification ID (0x01/0x03/0x02) and dispatches via a virtual method on global DAT_008b89a0. Guards against no-op when param matches current state.

**Key logic:**
- Early return if param_2 == -1 (no change)
- Early return if param_2 == param_1[0xf] (already set to this value)
- Maps param_2 to uVar1: 0→1, 1→3, 2→2 (else returns without dispatch)
- Calls virtual method at vtable+0xFC on *DAT_008b89a0 with arguments: DAT_008b89a0, *param_1, 0x0E, uVar1
- Stores param_2 at param_1[0xf] (state tracking)

**Globals:**
- `DAT_008b89a0` — game state virtual device (vtable dispatch at +0xFC, docs/08)

**Calls:**
- Virtual call at (*DAT_008b89a0 + 0xFC) — state notification dispatcher (docs/08)

**Used by system:** docs/01-engine-architecture.md — state management / UI notification

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00559330 — Small Struct Init with Parent Call

Source: unknown | Confidence: medium
Initializes a small struct (0x20 bytes) by calling parent init and zeroing three fields.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor / subsystem init, docs/06)
- Sets byte at *param_1 = 0
- Sets dword at param_1+0x14 = 0
- Sets dword at param_1+0x18 = 0
- Sets dword at param_1+0x1C = 0
- Returns param_1

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | unknown | byte | Cleared |
| +0x14 | unknown | int32 | Cleared |
| +0x18 | unknown | int32 | Cleared |
| +0x1C | unknown | int32 | Cleared |

**Calls:**
- FUN_0053c2a0 — parent constructor / subsystem init (docs/06)

**Used by system:** docs/01-engine-architecture.md — object construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055ca40 — Enum-to-VTable-Call Mapper (3 Cases)

Source: unknown | Confidence: medium
Maps enum param_2 (1/2/4) to vtable call argument (0x100/2/3) and dispatches through a stored vtable pointer at param_1[0x440]. Stores result.

**Key logic:**
- If param_2 == 1: uVar1 = 0x100
- Else if param_2 == 2: uVar1 = 2
- Else if param_2 == 4: uVar1 = 3; else return (no-op for other values)
- Calls virtual method at vtable+0x94 on object at param_1[0x440] with arguments: (int*)param_1[0x440], uVar1, param_3
- Stores return value in *param_1

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | unknown | undefined4 | Result stored here |
| +0x1100 (0x440*4) | unknown | undefined4 | Pointer to object with vtable at +0x94 |

**Calls:**
- Virtual call at vtable+0x94 on object at param_1[0x440] — dispatch with mapped ID

**Used by system:** docs/01-engine-architecture.md — engine dispatch / event mapping

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00560b30 — Conditional Free of Struct Field

Source: unknown | Confidence: high
Conditionally frees a heap-allocated object stored at param_1+0x1AC if non-null, then zeroes the pointer.

**Key logic:**
- Checks if *(param_1 + 0x1AC) != 0
- If non-null: calls FUN_00587bcf (memory free) on the pointer
- Then sets *(param_1 + 0x1AC) = 0 (nulls pointer)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x1AC | unknown | int32 (pointer) | Heap-allocated resource, freed if non-null |

**Calls:**
- FUN_00587bcf — memory free / deallocation

**Used by system:** docs/01-engine-architecture.md — resource cleanup / destructor helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00561f60 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_00562ac0 with no additional logic.

**Key logic:**
- Calls FUN_00562ac0()
- Returns void

**Calls:**
- FUN_00562ac0 — target function (unknown, no doc entry found)

**Used by system:** docs/01-engine-architecture.md — dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a660 — Dual Virtual Dispatch Wrapper

Source: unknown | Confidence: medium
Calls two virtual methods on an object obtained via *param_1, then returns 1.

**Key logic:**
- Dereferences *param_1 to get a base object pointer
- Calls virtual method at vtable+0x74 on that object (no args)
- Calls virtual method at vtable+0x9C on that object (args: 0, 0)
- Returns 1

**Calls:**
- Virtual call at vtable+0x74 — first dispatch (unknown purpose)
- Virtual call at vtable+0x9C — second dispatch (unknown purpose, with args 0,0)

**Used by system:** docs/01-engine-architecture.md — engine dispatch / initialization sequence

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057ae70 — Single Function Call Wrapper (to constructor)

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_00599958, an object constructor with SEH + vtable init.

**Key logic:**
- Calls FUN_00599958()
- Returns void

**Calls:**
- FUN_00599958 — Entity constructor with SEH + vtable init (docs/08)

**Used by system:** docs/01-engine-architecture.md — entity construction / initialization chain

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057d660 — Buffer Unpack with Size Check + Byte/Word Copy

Source: unknown | Confidence: medium
Unpacks a buffer of ushort values into a destination buffer. Checks header size field against computed packed size, copies aligned dwords then trailing bytes, and calls a cleanup function.

**Key logic:**
- Reads param_2+0x24: extracts bit[2:0] flag and shift-right-3 for base count
- Computes uVar1 = ((*(uint*)(param_2+0x24) & 7) != 0) + (*(uint*)(param_2+0x24) >> 3)
- If *param_1 (header count) matches computed uVar1:
  - Sets puVar3 = param_1 + 2 (start of data after header)
  - Reads destination pointer from param_2+0x14
  - Loop 1: copies uVar1/4 dwords (4 bytes each from 2-byte source words)
  - Loop 2: copies uVar1 & 3 remaining bytes (1 byte from 1-char aligned source)
- Calls FUN_00587510 on ((uint)*param_1 + (int)(param_1+2), param_1[1])

**Struct offsets (param_2):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x14 | unknown | undefined4* (pointer) | Destination buffer address |
| +0x24 | unknown | uint | Packed count: bit[2:0] flag, bits[3:] count |

**Calls:**
- FUN_00587510 — cleanup/advance function (not yet documented)

**Used by system:** docs/01-engine-architecture.md — data serialization / buffer unpacking

**Algorithm family:** Bitwise unpacking

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00582340 — VTable Call with Flag Check

Source: unknown | Confidence: medium
Conditionally calls a virtual method if a flag byte and a pointer are both non-null.

**Key logic:**
- Checks param_1[2] (byte at offset +8) != 0
- Checks *param_1 (pointer at +0) != null
- If both true: calls virtual method at vtable+4 on *param_1 with argument 1
- Otherwise returns without action

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | unknown | int* | Object pointer with vtable at +0 |
| +0x08 | unknown | byte | Flag/guard byte enabling dispatch |

**Used by system:** docs/01-engine-architecture.md — conditional dispatch / state machine

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_005840d0 — Mutex Wait with 1ms Timeout + Release

Source: unknown | Confidence: high
Waits on a Win32 mutex (1ms timeout) and releases it if the wait succeeded without error.

**Key logic:**
- Reads HANDLE from param_1+0xD4
- Calls WaitForSingleObject(hMutex, 1) — 1ms timeout
- If return value != WAIT_ABANDONED (0x102) and != INVALID_HANDLE_VALUE (-1) and handle != NULL:
  - Calls ReleaseMutex(hMutex)
- Returns void

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0xD4 | unknown | HANDLE | Win32 mutex handle |

**Win32 API calls:**
- WaitForSingleObject — wait on mutex with 1ms timeout
- ReleaseMutex — release the mutex

**Used by system:** docs/01-engine-architecture.md — thread synchronization / lock helper

**Moddability:** hardcoded (mutex handle stored in struct)

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585e10 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_00598815 (entity constructor).

**Key logic:**
- Calls FUN_00598815()
- Returns void

**Calls:**
- FUN_00598815 — Entity constructor (docs/08)

**Used by system:** docs/01-engine-architecture.md — entity construction / initialization chain

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586a80 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_0053d880 (render iterator).

**Key logic:**
- Calls FUN_0053d880()
- Returns void

**Calls:**
- FUN_0053d880 — render iterator (used in render_setup.cpp, docs/19)

**Used by system:** docs/01-engine-architecture.md — dispatch wrapper / render iteration

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587430 — Single Function Call Wrapper (to constructor)

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_00599958 (entity constructor with SEH + vtable init).

**Key logic:**
- Calls FUN_00599958()
- Returns void

**Calls:**
- FUN_00599958 — Entity constructor with SEH + vtable init (docs/08)

**Used by system:** docs/01-engine-architecture.md — entity construction

**Moddability:** hookable

<!-- target: docs/08-file-formats.md -->

## FUN_0058bbd2 — Lock Release by Index (CritSect leave #9)

Source: unknown | Confidence: high
Calls FUN_0058e04b(9) which releases critical section index 9.

**Key logic:**
- Calls FUN_0058e04b with argument 9
- Returns void

**Calls:**
- FUN_0058e04b(9) — CritSect leave for critical section #9 (docs/20)

**Used by system:** docs/01-engine-architecture.md — thread synchronization / critical section release

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593bbd — SEH-Wrapped Render Dispatch Call

Source: unknown | Confidence: medium
Sets up an SEH frame and conditionally calls FUN_0058a323 if param_1 is valid and its vtable pointer is non-null.

**Key logic:**
- Sets puStack_c = DAT_005b9978 (constant data)
- Sets puStack_10 = LAB_0058895c (exception handler address)
- Saves ExceptionList to local_14
- If param_1 != 0 AND *(int*)(*(int*)(param_1+0x1C)+4) != 0:
  - Sets local_8 = 0
  - Sets ExceptionList = &local_14 (installs SEH frame)
  - Calls FUN_0058a323(*(param_1+0x18), iVar1) — atomic lock/unlock with indirect call
- Restores ExceptionList from local_14

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x18 | unknown | undefined4 | First argument to FUN_0058a323 |
| +0x1C | unknown | int* | Points to vtable entry (checked at +4) |

**Calls:**
- FUN_0058a323 — atomic LOCK/UNLOCK with indirect call (docs/20, triage: Sync/Lock)
- ExceptionList — SEH handler registration

**Used by system:** docs/01-engine-architecture.md — render dispatch with SEH protection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005987ff — Callback Registration (atexit-style)

Source: unknown | Confidence: high
Registers LAB_0059880b via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0059880b)

**Calls:** FUN_00587b3e (callback registration)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005997d5 — Callback Registration (atexit-style)

Source: unknown | Confidence: high
Registers LAB_005997e1 via FUN_00587b3e.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a336 — Conditional Free with Flag Check

Source: unknown | Confidence: high
Calls FUN_00599be5, conditionally frees param_1.

**Calls:** FUN_00599be5, FUN_00587bcf

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a8d8 — Callback Chain Iteration

Source: unknown | Confidence: high
Walks linked list at +0x1C, calls each callback with 3 args.

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059b530 — Grow Dynamic Element Array

Source: unknown | Confidence: high
Grows element array, copies old data, zeroes new, frees old.

**Calls:** operator_new, FUN_00587bcf

**Algorithm family:** Dynamic array growth

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c48c — SEH Unwind: Free Object at -0x2C

Source: unknown | Confidence: high
Frees pointer at EBP-0x2C.

**Calls:** FUN_00587bcf

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cc1e — SEH Unwind: Free at -0x1C

Source: unknown | Confidence: high
Frees pointer at EBP-0x1C.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ce00 — SEH Unwind (Call FUN_005819c0)

Source: unknown | Confidence: high
Calls FUN_005819c0.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059daef — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004e4fb0.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005507d0 — Refcount Decrement / Resource Release Wrapper

Source: unknown | Confidence: medium
Single function call wrapper. Decrements reference count or releases resource through FUN_0053b4a0.

**Key logic:**
- Calls FUN_0053b4a0 with no arguments
- Used as a callback in resource manager destructor to decrement refcounts of array elements (stride 0x2c)

**Calls:** FUN_0053b4a0 (refcount decrement / resource release — resource manager context)

**Used by system:** docs/01-engine-architecture.md — resource manager destructor

<!-- target: docs/20-math-utilities.md -->

## FUN_00554610 — State Parameter Setter with Virtual Device Notify

Source: unknown | Confidence: medium
Store-if-changed setter with notification through DAT_008b89a0 virtual device.

**Key logic:**
- Compares param_2 with current value at param_1[0xc] (offset +0x30)
- If unchanged: return immediately
- If changed and param_2 == 0: notifies via vtable+0xf4(DAT_008b89a0, *param_1, 0), stores 0
- If changed and param_2 != 0: extracts value from *(param_2+0x54)+0x14, notifies via vtable+0xf4, stores param_2
- The third argument to the vtable call differs based on zero vs non-zero: for zero, direct 0; for non-zero, indirect value lookup through param_2+0x54

**Globals:**
- `DAT_008b89a0` — virtual device object used for state dispatch

**Calls:** DAT_008b89a0 vtable+0xf4 (state parameter setter notification)

**Used by system:** docs/01-engine-architecture.md — game state parameter binding system

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055687b — RDTSC Timestamp Read

Source: unknown | Confidence: high
Read CPU timestamp counter (RDTSC) and store high/low parts to output params.

**Key logic:**
- Executes `rdtsc` instruction — reads 64-bit timestamp counter into EDX:EAX
- Stores low 32 bits (EAX) to *param_4
- Stores high 32 bits (EDX) to *param_3
- Returns CONCAT44(param_2, in_EAX) — original input EAX preserved through return

**Calls:** None

**Used by system:** docs/06-session-race-logic.md — timestamp for hash table finalization; docs/01-engine-architecture.md — performance timing

<!-- target: docs/20-math-utilities.md -->

## FUN_0055cdf0 — Triple Vtable Query and Store

Source: unknown | Confidence: medium
Queries three values from a subsystem object via vtable dispatch, stores last result to *param_1.

**Key logic:**
- Gets subsystem object from param_1[0x440] (offset +0x1100 in large struct)
- First query: vtable+0x98 on subsystem with (2, param_1+0x516) → stores to *param_1
- Second query: vtable+0x98 on subsystem with (3, param_1+0x526) → stores to *param_1 (overwrites)
- Third query: vtable+0xa4 on subsystem with (param_1+0x536) → stores to *param_1 (final value)
- Only the last result persists in *param_1; earlier writes are intermediate

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1100 | int* | subsystem/device pointer with vtable |
| +0x2058 | - | buffer for query result (param_1+0x516) |
| +0x2098 | - | buffer for query result (param_1+0x526) |
| +0x20d8 | - | buffer for query result (param_1+0x536) |

**Calls:** subsystem vtable+0x98 (query by ID into buffer), subsystem vtable+0xa4 (direct query into buffer)

**Used by system:** docs/01-engine-architecture.md — entity query/dispatch system

<!-- target: docs/20-math-utilities.md -->

## FUN_00579fc0 — Callback Registration for Cleanup Routine

Source: unknown | Confidence: medium
Register a cleanup callback block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e with address of LAB_00579fd0 (cleanup code block)
- No other logic — pure registration wrapper
- Part of atexit-style or shutdown callback registration system

**Calls:** FUN_00587b3e (callback registration/dispatch)

**Used by system:** docs/01-engine-architecture.md — cleanup/shutdown registration system

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a690 — Virtual Method Dispatch (vtable+100)

Source: unknown | Confidence: high
Dispatches virtual method at vtable offset 100 (0x64) on object pointed to by *param_1.

**Key logic:**
- Reads object pointer from *param_1
- Reads vtable pointer from that object
- Calls method at vtable offset 100 (0x64 — slot 25)
- No arguments passed besides implicit this
- Thin wrapper for virtual dispatch — likely used as callback or adapter

**Calls:** virtual method at vtable+0x64 on *param_1 object

**Used by system:** docs/01-engine-architecture.md — polymorphic dispatch adapter

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057ae80 — Callback Registration for Cleanup Routine

Source: unknown | Confidence: medium
Register a cleanup callback block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e with address of LAB_0057ae90 (cleanup code block)
- No other logic — pure registration wrapper
- Same pattern as FUN_00579fc0 with different cleanup target

**Calls:** FUN_00587b3e (callback registration/dispatch)

**Used by system:** docs/01-engine-architecture.md — cleanup/shutdown registration system

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00582360 — Win32 Mutex Create/Recreate

Source: unknown | Confidence: high
Create or recreate a Win32 mutex for thread synchronization.

**Key logic:**
- If existing mutex handle at param_1+0x10 is active (flag at param_1+0x18 set): closes it via CloseHandle, zeros handle
- Creates new mutex via CreateMutexA with default security (inheritable) and no name
- Stores handle at param_1+0x10
- Sets flag at param_1+0x18 to 1 on success
- Returns flag value (success indicator)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x10 | HANDLE | mutex handle |
| +0x18 | byte | active flag |

**Calls:** CloseHandle, CreateMutexA (Win32 API)

**Used by system:** docs/01-engine-architecture.md — thread synchronization

<!-- target: docs/01-engine-architecture.md -->

## FUN_00584c70 — Thread-Safe Call with Mutex

Source: unknown | Confidence: high
Thread-safe execution protected by Win32 mutex with timeout.

**Key logic:**
- Waits on mutex at param_1+0x554 with timeout from param_1+0x558
- If wait succeeds (WAIT_OBJECT_0 or WAIT_ABANDONED_0): calls FUN_00586000(param_2, 0)
- Returns result of FUN_00586000
- Releases mutex via ReleaseMutex before returning
- Returns false if no mutex handle or wait fails

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x554 | HANDLE | mutex handle |
| +0x558 | DWORD | wait timeout (ms) |

**Calls:** WaitForSingleObject, ReleaseMutex (Win32 API), FUN_00586000 (protected operation)

**Used by system:** docs/01-engine-architecture.md — thread-safe operation dispatch

<!-- target: docs/20-math-utilities.md -->

## FUN_00586c90 — Counter Increment with Cap Check

Source: unknown | Confidence: medium
Increment a counter, return overflow flag.

**Key logic:**
- Reads counter from *param_1, increments by 1
- Stores incremented value back
- Returns (incremented < 6) as boolean in upper byte, value in lower 3 bytes
- Acts as a bounded counter that saturates/is checked at threshold 6

**Algorithm family:** Bounded counter — increment with limit check

**Used by system:** docs/01-engine-architecture.md — state machine step counter or retry limiter

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587440 — Callback Registration for Cleanup Routine

Source: unknown | Confidence: medium
Register a cleanup callback block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e with address of LAB_00587450 (cleanup code block)
- Same pattern as FUN_00579fc0 and FUN_0057ae80 with different cleanup target

**Calls:** FUN_00587b3e (callback registration/dispatch)

**Used by system:** docs/01-engine-architecture.md -- cleanup/shutdown registration system

<!-- target: docs/08-file-formats.md -->

## FUN_0058a5f7 -- N-Time Callback Loop with SEH

Source: unknown | Confidence: high
Execute a callback function param_3 times, protected by SEH frame.

**Key logic:**
- Sets up SEH exception handler frame (ExceptionList manipulation)
- Loops param_3 times, calling (*param_4)() each iteration
- Decrements param_3 each iteration, exits when < 0
- Sets SEH cookie to 0xffffffff and calls FUN_0058a65f (SEH cleanup/epilog)
- Restores original ExceptionList before return

**Calls:** (*param_4)() -- caller-provided callback, FUN_0058a65f (SEH cleanup/epilog)

**Used by system:** docs/01-engine-architecture.md -- SEH-protected batch callback execution

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058bc4d -- Critical Section Leave (Slot 9)

Source: unknown | Confidence: high
Release critical section for slot/index 9.

**Key logic:**
- Calls FUN_0058e04b(9) -- release critical section at index 9

**Calls:** FUN_0058e04b (indexed critical section release)

**Used by system:** docs/01-engine-architecture.md -- thread synchronization

<!-- target: docs/20-math-utilities.md -->

## FUN_00593c24 -- SEH Frame Offset Calculation Helper

Source: unknown | Confidence: medium
Compute adjusted offset for SEH exception handling frame lookup.

**Key logic:**
- iVar1 = param_2[1] (secondary offset/mode flag)
- iVar2 = *param_2 + param_1 (base address + function entry offset)
- If iVar1 >= 0: adds *(*(iVar1 + param_1) + param_2[2]) + iVar1 (indirect table lookup based on try-block index)
- Returns adjusted offset for SEH frame navigation

**Calls:** None -- pure address arithmetic

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH exception handling

<!-- target: docs/01-engine-architecture.md -->

## FUN_00597218 -- Lazy-Init Singleton with Flag Guard

Source: unknown | Confidence: high
One-time initialization of a subsystem, guarded by DAT_008d5a4c flag.

**Key logic:**
- Checks DAT_008d5a4c global flag
- If 0 (uninitialized): calls FUN_00596e40(0xfffffffd) and sets flag to 1
- If already 1: no-op (guard prevents double init)

**Globals:**
- `DAT_008d5a4c` -- init guard flag

**Calls:** FUN_00596e40 (subsystem initialization with parameter -3/0xfffffffd)

**Used by system:** docs/01-engine-architecture.md -- lazy singleton initialization

<!-- target: docs/20-math-utilities.md -->

## FUN_00599232 -- Conditional Delegate Call with Null Guard

Source: unknown | Confidence: medium
Call delegate with null guard; zero out this if call fails or delegate missing.

**Key logic:**
- Checks if *(param_1 + 0x50) (delegate) is null -> zeroes param_1
- If delegate exists: calls FUN_0059bb00(delegate, param_2, 0, param_3)
  - Returns non-zero: keeps param_1 unchanged
  - Returns zero: zeroes param_1 (failure path)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x50 | int* | delegate/interface pointer |

**Calls:** FUN_0059bb00 (delegate dispatch with context params)

**Used by system:** docs/01-engine-architecture.md -- conditional dispatch with fallback

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599802 -- Callback Registration for Cleanup Routine

Source: unknown | Confidence: medium
Register cleanup callback block at LAB_0059980e via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e with address of LAB_0059980e

**Calls:** FUN_00587b3e (callback registration)

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a371 -- Sub-call + Conditional Free

Source: unknown | Confidence: high
Call FUN_00599d17 then conditionally free param_1 based on param_2 bit 0.

**Key logic:**
- Calls FUN_00599d17() (destructor/cleanup)
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1) to free memory
- Returns param_1 (unchanged pointer)

**Calls:** FUN_00599d17, FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md -- conditional cleanup

<!-- target: docs/20-math-utilities.md -->

## FUN_0059db09 -- Flag/State Setter with 3 Special-Case Values

Source: unknown | Confidence: medium
Set state at offset +0xb6c; values 1,2,3 all write byte 0, others write int value.

**Key logic:**
- If in_EAX == 1: writes byte 0 to param_1+0xb6c
- If in_EAX == 2: writes byte 0 to param_1+0xb6c
- If in_EAX == 3: writes byte 0 to param_1+0xb6c
- Otherwise: writes in_EAX as int to param_1+0xb6c
- Then calls FUN_004e23ad (notification/update)
- Values 1,2,3 treated as "clear" regardless of actual meaning

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xb6c | int | state/flag field (byte for values 1-3, int otherwise) |

**Calls:** FUN_004e23ad (notification/update after state change)

**Used by system:** docs/01-engine-architecture.md -- state management with special reset semantics

<!-- target: docs/20-math-utilities.md -->

## FUN_00405630 -- Struct Init with VTable Dispatch and Zero Fill

Source: unknown | Confidence: medium
Initialize struct fields, call vtable method, zero fill array range.

**Key logic:**
- Sets +0x1c = -1, +0x20..+0x2c = 0
- Calls FUN_0052d990() (subsystem init)
- Calls vtable+4 on object at param_1+0x34
- Zeros 11 dwords at +0x44 through +0x70

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1c | int | -1 sentinel |
| +0x20..+0x2c | int | zeroed |
| +0x34 | int* | vtable object |
| +0x44..+0x70 | int[11] | zeroed array |

**Calls:** FUN_0052d990, vtable+4 method

**Used by system:** docs/01-engine-architecture.md -- struct initialization subsystem

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00408050 -- Linked List Node Search by ID + Operation

Source: unknown | Confidence: medium
Walk a linked list searching for a node matching param_2, then execute callback.

**Key logic:**
- Returns 0 if param_2 == -1
- Gets head pointer from param_1+0x18 as param_1+0x20 (current)
- Walks linked list: compares each node's +0x5c field to param_2
- If match found: calls FUN_00406a90(param_3, param_4), returns 1
- Returns 0 if list exhausted without match

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x18 | int* | list head pointer |
| +0x20 | int* | current traversal pointer |

**Calls:** FUN_00406a90 (operation on matched node)

**Used by system:** docs/01-engine-architecture.md -- linked list search with dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_00408de0 -- Conditional Subsystem Call with Parameter

Source: unknown | Confidence: low
Conditionally call subsystem functions based on state flags.

**Key logic:**
- If param_1+8 non-zero:
  - Calls FUN_00541ca0(param_2)
  - If param_2 == 0 and param_1+0xc non-null: calls FUN_00543440 with parameters from +0x1c, +0x20 and string constant

**Calls:** FUN_00541ca0, FUN_00543440

**Used by system:** docs/01-engine-architecture.md -- conditional dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040c070 -- Random State Machine with Timer and Trigger

Source: unknown | Confidence: medium
Timer-based state trigger with random outcome selection and dispatch.

**Key logic:**
- Returns 0 if flag at param_1+0x24 set
- Decrements param_1+0x3c by elapsed time from FUN_0040c780()
- When counter below ZeroThreshold (DAT_0059e440):
  - Calls FUN_0040cd60() (get previous state)
  - Randomly selects outcome (0,3,4,5) via _rand()
  - Calls FUN_0040cde0(outcome, 1) twice if outcome changed
  - 1-in-3 chance: calls FUN_0040d290(1)
  - Calls FUN_0040d360 from param_1+0x30, +0x34
  - Returns 1 (triggered)

**Globals:**
- `DAT_0059e440` (ZeroThreshold) -- timer expiry threshold

**Calls:** FUN_0040c780 (elapsed time), _rand, FUN_0040cd60, FUN_0040cde0, FUN_0040d290, FUN_0040d360

**Used by system:** docs/01-engine-architecture.md -- timer-driven random state machine

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040d980 -- Global Data Struct Init with File Paths

Source: unknown | Confidence: medium
Initialize a structure with file/path constant references and flags.

**Key logic:**
- Calls FUN_00434860 and FUN_00567a00 (subsystem inits)
- Sets fields [1..4] to global data pointers (DAT_005ea510, DAT_005ea618, DAT_005eb978, DAT_005ec6d0 — path/string constants)
- Sets *param_1 = 0 (root path/prefix)
- Calls FUN_00567f10() (path init continuation)
- Sets fields [0x21..0x27] to 0 (indexes/counters)
- Sets byte at +0x28*4 to 0x7c (124, max count/threshold)
- Sets field [0x25] = -1 (sentinel)

**Calls:** FUN_00434860, FUN_00567a00, FUN_00567f10

**Used by system:** docs/08-file-formats.md -- file path/data structure initialization

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040e990 -- Struct Init with Float Constants and Sub-calls

Source: unknown | Confidence: medium
Initialize struct fields with float constants and call geometry/math functions.

**Key logic:**
- Sets +0x08 = param_2 (short), +0x1c = 1, +0x20 = param_3
- Prepares local float constants (0.5, 0.2, 1.2, 0.5) and calls FUN_00459950 and FUN_00459990 with IEEE float hex constants
- If param_4 != 0: calls FUN_0040e770(param_4, 0)

**Calls:** FUN_00459950, FUN_00459990, FUN_0040e770

**Used by system:** docs/18-physics-dynamics.md -- physical parameter initialization with floating-point constants

<!-- target: docs/20-math-utilities.md -->

## FUN_00418df0 -- Linked List Destructor with Conditional Cleanup

Source: unknown | Confidence: high
Free all nodes in a linked list, conditionally freeing inner buffers.

**Key logic:**
- Calls FUN_004190c0() (pre-cleanup)
- Walks linked list starting at param_1+0x1a0
- For each node: if byte flag at node[2] is non-zero AND *node is non-null: frees *node via FUN_00587bcf
- Frees node itself via FUN_00587bcf
- Zeros the four list head fields at +0x1a0..+0x1ac

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1a0 | int* | linked list head |
| +0x1a4 | int | zeroed after cleanup |
| +0x1a8 | int | zeroed after cleanup |
| +0x1ac | int | zeroed after cleanup |

**Calls:** FUN_004190c0, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- linked list resource destruction

<!-- target: docs/20-math-utilities.md -->
## thunk_FUN_004201e0 at 004203d0 -- Thunk to FUN_004201e0

Source: unknown | Confidence: high
Thunk -- direct jmp to FUN_004201e0. No local logic.

**Key logic:**
- Calls FUN_004201e0() and returns

**Calls:** FUN_004201e0 (target function)

**Used by system:** docs/20-math-utilities.md -- call alias/thunk

<!-- target: docs/01-engine-architecture.md -->

## FUN_00421a50 -- Dual Call Wrapper

Source: unknown | Confidence: high
Calls two functions with the same parameter.

**Key logic:**
- Calls FUN_00421890(param_1)
- Calls FUN_00566650(param_1)

**Calls:** FUN_00421890, FUN_00566650

**Used by system:** docs/01-engine-architecture.md -- dispatch wrapper

<!-- target: docs/20-math-utilities.md -->

## FUN_00454d30 -- Parameter Lookup with Fallback

Source: unknown | Confidence: medium
Try two lookup methods: named parameter then numeric ID, store result.

**Key logic:**
- Attempts FUN_00454350(param_1, &param_3, param_3) -- named lookup
  - If found: sets *param_2=1, param_2[1]=param_3, returns 1
- Falls back to FUN_004541d0(param_1, &param_3) -- numeric lookup
  - If found: sets *param_2=0, param_2[1]=param_3, returns 1
- Returns 0 if both fail

**Calls:** FUN_00454350, FUN_004541d0

**Used by system:** docs/08-file-formats.md -- config parameter lookup with name/ID fallback

<!-- target: docs/20-math-utilities.md -->
## thunk_FUN_00458020 at 00457cf0 -- Resource Cleanup with Conditional Free

Source: unknown | Confidence: medium
Free resource at adjusted pointer, zero out array fields.

**Key logic:**
- If *param_1 != 0: frees(*param_1 - 4) (adjusted allocation pointer), zeros *param_1
- Zeros param_1[1..6] (7 dwords zeroed)

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md -- resource cleanup utility

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0045bf60 -- Callback Registration for Cleanup

Source: unknown | Confidence: medium
Register cleanup callback at LAB_0045bf70 via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0045bf70)

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/01-engine-architecture.md -->

## FUN_0045d500 -- Guarded Init Call

Source: unknown | Confidence: medium
Call init function if global flag is zero.

**Key logic:**
- If DAT_007ce260 == 0: calls FUN_0045d240()
- One-shot init guard

**Globals:**
- `DAT_007ce260` -- init guard flag

**Calls:** FUN_0045d240

**Used by system:** docs/01-engine-architecture.md -- guarded initialization

<!-- target: docs/20-math-utilities.md -->

## FUN_00466080 -- Call Wrapper

Source: unknown | Confidence: high
Forward param_1 to FUN_00566650.

**Key logic:**
- Calls FUN_00566650(param_1)

**Calls:** FUN_00566650

**Used by system:** docs/01-engine-architecture.md -- dispatch wrapper

<!-- target: docs/08-file-formats.md -->

## FUN_0046af00 -- Dual Call Wrapper

Source: unknown | Confidence: high
Call two functions in sequence, return 0.

**Key logic:**
- Calls FUN_0046ae60()
- Calls FUN_00489ab0(0, 1)
- Returns 0

**Calls:** FUN_0046ae60, FUN_00489ab0

**Used by system:** docs/01-engine-architecture.md -- init/dispatch wrapper

<!-- target: docs/01-engine-architecture.md -->

## FUN_0046da20 -- Dispatch Chain with VTable Calls

Source: unknown | Confidence: medium
Call multiple initialization functions via direct calls and vtable dispatch.

**Key logic:**
- Calls FUN_0042d210(1)
- Calls vtable+0x1c on param_1[0x10] with arg 0x1e
- Calls FUN_0046bf10(1)
- Calls FUN_004d2450()
- Calls vtable+0x38 on *param_1 with arg 1
- Returns 0

**Calls:** FUN_0042d210, vtable+0x1c, FUN_0046bf10, FUN_004d2450, vtable+0x38

**Used by system:** docs/01-engine-architecture.md -- initialization dispatch chain

<!-- target: docs/01-engine-architecture.md -->

## FUN_0046fe50 -- Conditional UI/Subsystem Dispatch

Source: unknown | Confidence: medium
Call setup functions, conditionally dispatch to FUN_00477280.

**Key logic:**
- Calls FUN_0048fec0() and FUN_00490160(1)
- Checks DAT_007cd8c0 vtable+0x1c(0xd) for resource availability
- If resource available: calls FUN_00477280(param_1)
- Returns 0

**Globals:**
- `DAT_007cd8c0` -- manager object with vtable

**Calls:** FUN_0048fec0, FUN_00490160, vtable+0x1c, FUN_00477280

**Used by system:** docs/01-engine-architecture.md -- conditional UI dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_00471860 -- Object Constructor with VTable and Field Init

Source: unknown | Confidence: medium
Construct object with vtable, init UI-style fields and data references.

**Key logic:**
- Calls FUN_00466d60(1)
- Sets vtable pointer to PTR_FUN_005a12c0
- Sets param_1[199] = DAT_007ce7cc (UI data reference)
- Sets fields [0xc9..0xcc] = 1, 0, 1, 1 (flags)
- Sets field [0xcd] = 0xf2 (242, threshold/constant)
- Calls FUN_00486f30 twice with global data refs and -1
- Calls FUN_004670e0()

**Calls:** FUN_00466d60, FUN_00486f30, FUN_004670e0

**Used by system:** docs/01-engine-architecture.md -- UI/display object construction

<!-- target: docs/01-engine-architecture.md -->

## FUN_00473b90 -- Conditional Init with Global Ref Setup

Source: unknown | Confidence: medium
Check resource, conditionally dispatch, set global string reference.

**Key logic:**
- Checks DAT_007cd8c0 vtable+0x1c(0xb)
- If available: calls FUN_00477280(param_1)
- Sets *(param_1+800) = DAT_007d0474 (string/UI reference)
- Sets *(param_1+0x31c) = 0x116 (278, constant)
- Returns 0

**Globals:**
- `DAT_007cd8c0`, `DAT_007d0474`

**Calls:** vtable+0x1c, FUN_00477280

**Used by system:** docs/01-engine-architecture.md -- conditional dispatch with setup

<!-- target: docs/01-engine-architecture.md -->

## FUN_00475040 -- VTable Setter with Sub-call

Source: unknown | Confidence: high
Set vtable pointer and call FUN_00487250.

**Key logic:**
- Sets *param_1 = PTR_FUN_005a42c0 (vtable)
- Calls FUN_00487250()

**Calls:** FUN_00487250

**Used by system:** docs/01-engine-architecture.md -- object constructor

<!-- target: docs/01-engine-architecture.md -->

## FUN_004773a0 -- Bounds Check with Position Query

Source: unknown | Confidence: medium
Get position via FUN_00498880, check against 4 boundary values, test with FUN_0048ea60.

**Key logic:**
- Gets position (local_8 X, local_4 Y) from FUN_00498880
- If param_2 != 0 and position within bounds (X: param_1+0x120..+0x124, Y: param_1+0x140..+0x144):
  - Calls FUN_0048ea60(X, Y) for hit test
  - Returns 1 if hit
- Returns 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x120 | int | X min bound |
| +0x124 | int | X max bound |
| +0x140 | int | Y min bound |
| +0x144 | int | Y max bound |

**Calls:** FUN_00498880, FUN_0048ea60

**Used by system:** docs/01-engine-architecture.md -- UI hit test / bounds check

<!-- target: docs/01-engine-architecture.md -->

## FUN_00478320 -- Resource Query and Stored Setup

Source: unknown | Confidence: medium
Query resource by ID 0x12, store result, call setup.

**Key logic:**
- Queries DAT_007cd8c0 vtable+0x1c(0x12)
- If non-null: stores at param_1+0xe0, calls FUN_00478390()
- Returns 0

**Globals:**
- `DAT_007cd8c0`

**Calls:** vtable+0x1c, FUN_00478390

**Used by system:** docs/01-engine-architecture.md -- resource binding

<!-- target: docs/01-engine-architecture.md -->

## FUN_004798e0 -- VTable Setter with Float Params

Source: unknown | Confidence: high
Set vtable pointer after calling FUN_00466980 with -1.0f and 1.0f constants.

**Key logic:**
- Calls FUN_00466980(0xbf800000=-1.0f, 0x3f800000=1.0f)
- Sets *param_1 = PTR_FUN_005a5430 (vtable)

**Calls:** FUN_00466980

**Used by system:** docs/01-engine-architecture.md -- object constructor with range init

<!-- target: docs/01-engine-architecture.md -->

## FUN_00479ed0 -- Call + Flag Set

Source: unknown | Confidence: high
Call FUN_0047abb0, set byte flag at +0x100 to 0.

**Key logic:**
- Calls FUN_0047abb0()
- Sets *(param_1+0x100) = 0

**Calls:** FUN_0047abb0

**Used by system:** docs/01-engine-architecture.md -- init/reset

<!-- target: docs/01-engine-architecture.md -->

## FUN_0047bae0 -- Bounded Counter Update

Source: unknown | Confidence: high
Add value to counter with clamping: non-negative with upper bound.

**Key logic:**
- If param_2 < 0: subtracts from counter, clamps to 0 minimum, calls FUN_0047bd90
- If param_2 >= 0: adds to counter, clamps to max-1 via FUN_0047bc90(), calls FUN_0047bd90

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xec | int | counter value |

**Calls:** FUN_0047bd90 (update after change), FUN_0047bc90 (get max bound)

**Used by system:** docs/01-engine-architecture.md -- bounded counter management

<!-- target: docs/01-engine-architecture.md -->

## FUN_0047e940 -- Conditional Call Wrapper

Source: unknown | Confidence: high
Call FUN_00566650 if param_1 non-zero.

**Key logic:**
- If param_1 != 0: calls FUN_00566650()

**Calls:** FUN_00566650

**Used by system:** docs/01-engine-architecture.md -- conditional dispatch wrapper

<!-- target: docs/01-engine-architecture.md -->

## FUN_00485660 -- Destructor with Conditional Free

Source: unknown | Confidence: medium
VTable set, call FUN_00487250, conditionally free.

**Key logic:**
- Sets *param_1 = PTR_FUN_005aafd0 (vtable)
- Calls FUN_00487250()
- If (param_2 & 1): calls FUN_00587bcf(param_1)

**Calls:** FUN_00487250, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- destructor

<!-- target: docs/20-math-utilities.md -->

## FUN_00486f30 -- Linked List Insert with Node Allocation

Source: unknown | Confidence: medium
Allocate linked list nodes and insert into doubly-linked list.

**Key logic:**
- If param_3 < 1 (append mode):
  - Allocates 8-byte data node, initializes (*node=0, [1]=-1)
  - Calls FUN_00566650(param_2) to set data
  - Allocates 12-byte list node (data ptr, next ptr, flag byte=1)
  - Appends to end of doubly-linked list at param_1+0x44
  - Increments count at param_1+0x50
- If param_3 >= 1 (find mode):
  - Walks to param_3-th node, sets cursor at param_1+0x4c
  - If node exists and has data: calls FUN_00566650(param_2)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x44 | int* | list head |
| +0x48 | int* | list tail |
| +0x4c | int* | cursor |
| +0x50 | int | count |

**Calls:** operator_new, FUN_00566650

**Used by system:** docs/01-engine-architecture.md -- linked list data structure

<!-- target: docs/01-engine-architecture.md -->

## FUN_004879e0 -- Init Dispatch with VTable Check

Source: unknown | Confidence: medium
Conditional dispatch chain with vtable method check.

**Key logic:**
- Calls FUN_004874e0()
- If non-zero: calls FUN_00487760(1), FUN_00487960(), vtable+0x98()
- If vtable method returns 0: calls FUN_00486600(), returns 0
- Returns -1

**Calls:** FUN_004874e0, FUN_00487760, FUN_00487960, vtable+0x98, FUN_00486600

**Used by system:** docs/01-engine-architecture.md -- init dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_00488f90 -- VTable Set with Flag

Source: unknown | Confidence: high
Calls FUN_00485e30, sets vtable, sets byte flag at +0xE4 to 1.

**Key logic:**
- Calls FUN_00485e30()
- Sets *param_1 = PTR_FUN_005abcd0
- Sets byte at (param_1+0x39*4) = 1

**Calls:** FUN_00485e30

**Used by system:** docs/01-engine-architecture.md -- object constructor

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048b4e0 -- VTable Setter + Sub-call

Source: unknown | Confidence: high
Set vtable pointer, call FUN_00485eb0.

**Key logic:**
- *param_1 = PTR_FUN_005abed0
- Calls FUN_00485eb0()

**Calls:** FUN_00485eb0

**Used by system:** docs/01-engine-architecture.md -- object constructor

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048cc20 -- Linked List Size Calc with Max Tracking

Source: unknown | Confidence: medium
Walk linked list, compute max width/height from node data.

**Key logic:**
- Initializes +0x32c = 5, +0x330 = 5 (min width/height)
- Walks linked list starting at param_1+0x31c
- For each node with data: adds +2 to width from data+0x1c, tracks max in +0x32c
- Tracks max height from data+0x20 in +0x330

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x31c | int* | linked list head |
| +0x324 | int* | cursor |
| +0x32c | int | max computed width |
| +0x330 | int | max computed height |

**Used by system:** docs/01-engine-architecture.md -- UI/list layout computation

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048e0b0 -- Destructor with Conditional Free

Source: unknown | Confidence: high
Call FUN_0048e0d0, conditionally free param_1 based on param_2 bit 0.

**Key logic:**
- Calls FUN_0048e0d0()
- If (param_2 & 1): FUN_00587bcf(param_1)

**Calls:** FUN_0048e0d0, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- destructor

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048faf0 -- Decrement Counter with Clamp

Source: unknown | Confidence: high
Subtract value from counter at +0x168, clamp to >= 0.

**Key logic:**
- If param_2 < 0: uses stored value at +0x178 as default decrement
- Subtracts from counter at +0x168, clamps to 0 minimum
- Calls FUN_0048f870()

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x168 | int | counter |
| +0x178 | int | default decrement value |

**Calls:** FUN_0048f870

**Used by system:** docs/01-engine-architecture.md -- counter management

<!-- target: docs/01-engine-architecture.md -->

## FUN_004902c0 -- Linked List Destructor with VTable Notification

Source: unknown | Confidence: high
Free linked list nodes with vtable+0(1) notification on each.

**Key logic:**
- Sets vtable to PTR_FUN_005ac760
- Walks linked list at param_1[0x38]
- For each node with flag[3] set and data: calls vtable method at offset 0 on *data(1)
- Frees each node
- Zeros list head fields
- Calls FUN_00485eb0()

**Calls:** vtable+0, FUN_00587bcf, FUN_00485eb0

**Used by system:** docs/01-engine-architecture.md -- destructor with notification

<!-- target: docs/20-math-utilities.md -->

## FUN_00491e10 -- Conditional Resource Cleanup

Source: unknown | Confidence: high
Free internal buffer and optionally self.

**Key logic:**
- If flag at param_1[2] set and *param_1 non-null: frees *param_1
- If param_2 & 1: frees param_1 itself

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- resource cleanup

<!-- target: docs/01-engine-architecture.md -->

## FUN_00495060 -- Guarded Subsystem Release

Source: unknown | Confidence: high
If DAT_007cde1c non-null, call FUN_00554d70 to release.

**Key logic:**
- If DAT_007cde1c != 0: calls FUN_00554d70(DAT_007cde1c)

**Globals:**
- `DAT_007cde1c` -- subsystem instance pointer

**Calls:** FUN_00554d70

**Used by system:** docs/01-engine-architecture.md -- guarded subsystem release

<!-- target: docs/20-math-utilities.md -->

## FUN_004975b0 -- Set + Init Call

Source: unknown | Confidence: high
Set field at +0x40 to param_1, call FUN_00498eb0.

**Key logic:**
- *(param_2+0x40) = param_1
- Calls FUN_00498eb0(param_2)

**Calls:** FUN_00498eb0

**Used by system:** docs/01-engine-architecture.md -- setter with notification

<!-- target: docs/20-math-utilities.md -->

## FUN_00499140 -- Constructor with VTable and Sub-init

Source: unknown | Confidence: high
Call FUN_00498d20, set vtable.

**Key logic:**
- Calls FUN_00498d20(param_2)
- Sets *param_1 = PTR_FUN_005aca30

**Calls:** FUN_00498d20

**Used by system:** docs/01-engine-architecture.md -- object constructor

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d480 -- Local Buffer + Subsystem Call

Source: unknown | Confidence: low
Prepare 16-byte buffer, call FUN_0049c670, then call FUN_00553070 with data.

**Key logic:**
- Creates 16-byte local buffer
- Calls FUN_0049c670(local_buffer, 0xf)
- Calls FUN_00553070(local_buffer, 4, 0x15, value from param_1+0x10 offset 0x54)

**Calls:** FUN_0049c670, FUN_00553070

**Used by system:** docs/01-engine-architecture.md -- data prep and dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_0049ed10 -- Guarded Call

Source: unknown | Confidence: high
If *param_1 non-zero, call FUN_00553700.

**Key logic:**
- If *param_1 != 0: calls FUN_00553700()

**Calls:** FUN_00553700

**Used by system:** docs/01-engine-architecture.md -- guarded dispatch

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1e20 -- Triple Dispatch Wrapper

Source: unknown | Confidence: high
Call FUN_00566650 three times with different params, then FUN_004a1b70.

**Key logic:**
- Calls FUN_00566650(param_1), FUN_00566650(param_2), FUN_00566650(param_3)
- Calls FUN_004a1b70()

**Calls:** FUN_00566650, FUN_004a1b70

**Used by system:** docs/01-engine-architecture.md -- triple dispatch wrapper

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004b19b0 -- VTable + Patterned Field Init

Source: unknown | Confidence: high
Set vtable pointer and pattern 0, -1, 0, -1.

**Key logic:**
- [1]=0, [2]=-1, [3]=0, [4]=-1
- *param_1 = PTR_LAB_005acc20

**Used by system:** docs/01-engine-architecture.md -- object construction

<!-- target: docs/19-renderer.md -->

## FUN_004b3d50 -- Callback Registration

Source: unknown | Confidence: high
Register LAB_004b3d60 via FUN_00587b3e.

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9870 -- Call Wrapper

Source: unknown | Confidence: high
Call FUN_004b7a90.

**Calls:** FUN_004b7a90

**Used by system:** docs/01-engine-architecture.md -- dispatch wrapper

<!-- target: docs/01-engine-architecture.md -->

## FUN_004ba740 -- Guarded Dispatch with State Check

Source: unknown | Confidence: medium
Check global DAT_007d005c and *param_1, conditionally call init, then call cleanup.

**Key logic:**
- If DAT_007d005c != 0 and *param_1 == 1: calls FUN_004b9880()
- Calls FUN_004b97e0()
- Sets byte flag at param_1+4 = 0

**Globals:**
- `DAT_007d005c`

**Calls:** FUN_004b9880, FUN_004b97e0

**Used by system:** docs/01-engine-architecture.md -- stateful dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_004baeb0 -- Linked List Destructor with Callback

Source: unknown | Confidence: high
Walk linked list, call FUN_004b0170 then free each node.

**Key logic:**
- Walks linked list from *param_1
- For each node: if flag[2] set and *node non-null: calls FUN_004b0170 then FUN_00587bcf
- Frees node itself
- Zeros list head fields

**Calls:** FUN_004b0170, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- resource destruction

<!-- target: docs/20-math-utilities.md -->

## FUN_004c1820 -- Linked List Node Removal with Cleanup

Source: unknown | Confidence: high
Find node by ID match, remove from doubly-linked list, free resources.

**Key logic:**
- Calls FUN_004c2850 for target ID
- Walks linked list from *param_1 matching *node == ID
- Updates prev/next pointers and tail/head references
- Decrements count at param_1[3]
- If node has flag[2] set and data: calls FUN_004c0b10 then frees data
- Frees node, returns 1

**Calls:** FUN_004c2850, FUN_004c0b10, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- linked list node removal

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004c82c0 -- Init with Status Check

Source: unknown | Confidence: medium
Call init functions, store global result, return success indicator.

**Key logic:**
- Calls FUN_004c8350()
- Sets DAT_008ac4c4 = FUN_004c7c10()
- Returns (DAT_008ac4c4 == 0)

**Globals:**
- `DAT_008ac4c4` -- init status

**Calls:** FUN_004c8350, FUN_004c7c10

**Used by system:** docs/01-engine-architecture.md -- init with status check

<!-- target: docs/01-engine-architecture.md -->

## FUN_004c8f80 -- VTable Dispatch with Negation

Source: unknown | Confidence: medium
Set field, call transform function, negate value, dispatch vtable method.

**Key logic:**
- If param_2 non-zero: sets param_1[1]=param_2, calls FUN_0054b950, negates float, calls vtable+4
- Returns 1 if param_2 was non-zero, else 0

**Calls:** FUN_0054b950, vtable+4

**Used by system:** docs/01-engine-architecture.md -- object dispatch

<!-- target: docs/20-math-utilities.md -->

## FUN_004d22c0 -- Field Setter with Init

Source: unknown | Confidence: low
Set flag, float from global, copy field, call FUN_0042d140.

**Key logic:**
- Sets byte at +0xc1 = 0
- Sets float at +0xb0 = _DAT_008afea0
- Copies int from param_2+0xc to param_1+0xb4
- Calls FUN_0042d140()

**Calls:** FUN_0042d140

**Used by system:** docs/01-engine-architecture.md -- init/setup

<!-- target: docs/08-file-formats.md -->

## FUN_004d7d90 -- Call Wrapper

Source: unknown | Confidence: high
Call FUN_004d7ad0.

**Calls:** FUN_004d7ad0

**Used by system:** docs/01-engine-architecture.md -- dispatch wrapper

<!-- target: docs/01-engine-architecture.md -->

## FUN_004d8950 -- Batch VTable Dispatch and Cleanup

Source: unknown | Confidence: high
Iterate arrays of interface pointers, call vtable+0(1) on each, zero them.

**Key logic:**
- Iterates 25 slots at param_1+0x10: if non-null, calls vtable+0(1) and zeros
- Iterates 3 slots at param_1+0x74: same pattern
- Checks two single slots at +0xc and +0xd8: same pattern

**Calls:** vtable+0 method

**Used by system:** docs/01-engine-architecture.md -- interface cleanup/destroy

<!-- target: docs/01-engine-architecture.md -->

## FUN_004db550 -- UI Layout Dispatch with Data Prep

Source: unknown | Confidence: medium
Conditional dispatch based on DAT_007d0474, compute and dispatch layout values.

**Key logic:**
- If DAT_007d0474 == 0: calls FUN_0049b950() else FUN_0049b900()
- Prepares values 0x14 (20) and 10 as layout parameters
- Calls FUN_004db6f0, FUN_004db9a0, FUN_004db7f0 with computed values

**Globals:**
- `DAT_007d0474` -- UI mode flag

**Calls:** FUN_0049b950, FUN_0049b900, FUN_0049b8f0, FUN_004db6f0, FUN_004db9a0, FUN_0049b7a0, FUN_004db7f0

**Used by system:** docs/01-engine-architecture.md -- UI layout dispatch

<!-- target: docs/17-physics-collision.md -->

## FUN_004dfb60 -- Init with Dual Call

Source: unknown | Confidence: medium
Call init, zero fields, call FUN_004dfa50 twice.

**Key logic:**
- Calls FUN_004dfb00()
- Zeros fields at +0x120, +0x10c, +0x110
- Calls FUN_004dfa50() twice

**Calls:** FUN_004dfb00, FUN_004dfa50

**Used by system:** docs/01-engine-architecture.md -- init with dual finalize

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f8ae0 -- Dual Source Acquire with Fallback

Source: unknown | Confidence: medium
Acquire value from primary source, fallback to secondary.

**Key logic:**
- Calls FUN_004f8b50(), stores to *param_1
- If zero: calls FUN_004f8c70(), stores to *param_1
- Returns *param_1

**Calls:** FUN_004f8b50, FUN_004f8c70

**Used by system:** docs/01-engine-architecture.md -- resource acquisition with fallback

<!-- target: docs/01-engine-architecture.md -->

## FUN_004f9240 -- Multi-Table Coordinate Search

Source: unknown | Confidence: medium
Search multiple coordinate tables for matching 4-int tuple.

**Key logic:**
- Iterates DAT_008afe6c tables
- For each table: iterates entries via FUN_004f9190/FUN_004f91b0
- Compares 4 values (param_1..param_4) against each entry
- Returns entry index on match, -1 if no match found

**Globals:**
- `DAT_008afe6c` -- table count

**Calls:** FUN_004f9150, FUN_004f9160, FUN_004f9190, FUN_004f91b0

**Used by system:** docs/01-engine-architecture.md -- multi-table coordinate lookup

<!-- target: docs/01-engine-architecture.md -->

## FUN_004fc650 -- String Copy with Ring Buffer
Source: unknown | Confidence: medium
Copy two strings into ring buffer with offset addressing.

**Key logic:**
- If DAT_0083ee60 < 0x3ff: increments ring buffer counter and offset
- Computes string lengths at offsets +0x50 and +0x84
- Calls FUN_004b33b0 with computed values
- Copies strings to ring buffer at computed offsets

**Globals:**
- `DAT_008aae64` -- ring buffer offset
- `DAT_0083ee60` -- ring buffer counter

**Calls:** FUN_004b33b0

**Used by system:** docs/01-engine-architecture.md -- ring buffer string logging

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0050a8f5 -- VTable Setter with Sub-init (Type 1)
Source: unknown | Confidence: high
Call FUN_00507496(param_2, 0x20, 1), set vtable to PTR_FUN_005adbd8.

**Calls:** FUN_00507496

**Used by system:** docs/01-engine-architecture.md -- vtable constructor

<!-- target: docs/01-engine-architecture.md -->

## FUN_0050b3d1 -- VTable Setter with Sub-init (Type 3)
Source: unknown | Confidence: high
Call FUN_00507496(param_2, 0x20, 3), set vtable to PTR_FUN_005add3c.

**Calls:** FUN_00507496

**Used by system:** docs/01-engine-architecture.md -- vtable constructor

<!-- target: docs/20-math-utilities.md -->

## FUN_00511457 -- State Counter with Dispatch
Source: unknown | Confidence: medium
Check state counter, dispatch to processing or reset.

**Key logic:**
- If param_1[0x5e] == 0: calls FUN_005110fc()
- If counter matches computed index: sets up fields, calls vtable+4, resets counter
- Otherwise: dispatches through param_1[5]+0x14
- Increments counter mod 8

**Calls:** FUN_005110fc, vtable+4, vtable+0x14

**Used by system:** docs/01-engine-architecture.md -- state machine dispatch

<!-- target: docs/20-math-utilities.md -->

## FUN_005161dd -- Linked List Node Alloc and Insert
Source: unknown | Confidence: medium
Allocate 0x78-byte node via FUN_00515f23, init fields, insert into linked list.

**Key logic:**
- If param_2 != 1: calls vtable+0 for error dispatch
- Allocates 0x78-byte node via FUN_00515f23
- Initializes: [0]=0, [1]=param_5, [2]=param_4, [3]=param_6, byte at +0x22=0, byte[8]=param_3
- Copies [9] from source+0x40 (tail), inserts node at tail

**Calls:** FUN_00515f23, vtable+0

**Used by system:** docs/01-engine-architecture.md -- linked list node creation

<!-- target: docs/01-engine-architecture.md -->

## FUN_00517963 -- Resource Reset with Counter
Source: unknown | Confidence: medium
Reset resource fields, set counter from flag.

**Key logic:**
- If param_1 non-null and *(param_1+0x1c) non-null: zeros [0x14], [8], [0x18]
- Sets *counter_var = (flag[3]!=0 ? 7 : 0) & 7
- Calls FUN_0052765a with data
- Returns 0 or -2 if invalid

**Calls:** FUN_0052765a

**Used by system:** docs/01-engine-architecture.md -- resource reset

<!-- target: docs/19-renderer.md -->

## FUN_0051eb6e -- Object Setup with Bounds Check
Source: unknown | Confidence: medium
Allocate object, setup callbacks, validate size bounds.

**Key logic:**
- Allocates via vtable dispatch: FUN_0051ea90 callback, data labels
- Validates param_1[0x19] > 4: error dispatch if exceeded
- Validates param_1[0x15] > 0x100: error dispatch if exceeded
- Calls FUN_0051e2ba, FUN_0051e3e7, conditionally FUN_0051ea5a

**Calls:** vtable dispatch, FUN_0051e2ba, FUN_0051e3e7, FUN_0051ea5a

**Used by system:** docs/01-engine-architecture.md -- object setup/validation

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0052d9d0 -- Destructor with Conditional Free
Source: unknown | Confidence: high
Call FUN_0052d9b0, conditionally free param_1.

**Key logic:**
- Calls FUN_0052d9b0()
- If (param_2 & 1): FUN_00587bcf(param_1)

**Calls:** FUN_0052d9b0, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- destructor

<!-- target: docs/08-file-formats.md -->
## AVIFileRelease at 00534ae6 -- Import Trampoline
Source: unknown | Confidence: high
Indirect jump to AVIFileRelease. VFW import trampoline.

**Key logic:**
- Indirect jmp to AVIFileRelease (Video for Windows API)

**Used by system:** docs/08-file-formats.md -- AVI import trampoline

<!-- target: docs/01-engine-architecture.md -->

## FUN_00536160 -- Buffer Copy with Size Tracking
Source: unknown | Confidence: high
Copy min(src_size, dst_size) bytes between buffers with size accounting.

**Key logic:**
- Computes copy size = min(*(param_1+0x10), *(source+0x14))
- Copies data in dwords then residual bytes
- Advances both src and dst pointers
- Updates all 4 size fields: +0xc (dst consumed), +0x14 (total), +0x10 (dst remaining), source+0x14 (src remaining)
- If source empty: resets source buffer pointer to base

**Used by system:** docs/01-engine-architecture.md -- buffered I/O data transfer

<!-- target: docs/01-engine-architecture.md -->

## FUN_0053ac70 -- Empty Stub with Flag Check
Source: unknown | Confidence: high
Returns immediately if (param_2 & 4) != 0. Otherwise returns.

**Key logic:**
- If (param_2 & 4): returns early
- Otherwise: returns
- Effective no-op regardless of path

**Used by system:** docs/01-engine-architecture.md -- empty stub

<!-- target: docs/01-engine-architecture.md -->

## FUN_0053c140 -- Call Wrapper
Source: unknown | Confidence: high
Call FUN_00556220.

**Calls:** FUN_00556220

**Used by system:** docs/01-engine-architecture.md -- dispatch wrapper

<!-- target: docs/01-engine-architecture.md -->

## FUN_0053cac0 -- Object Allocation with Init
Source: unknown | Confidence: medium
Allocate 0x30-byte object, initialize, validate.

**Key logic:**
- Allocates 0x30 bytes via operator_new
- If success: calls FUN_005473d0() for init, stores result to *param_1
- Calls FUN_00547400(0) for validation
- Returns -1 if validation passed, 0 if failed

**Calls:** operator_new, FUN_005473d0, FUN_00547400

**Used by system:** docs/01-engine-architecture.md -- object allocation

<!-- target: docs/20-math-utilities.md -->

## FUN_00541670 -- VTable Dispatch with Field Check
Source: unknown | Confidence: medium
If flag at param_1[0x4f6] set, dispatch through vtable+200 with param_2.

**Key logic:**
- If param_1[0x4f6] (offset +0x13d8) non-zero: calls vtable+200 on object at param_1[0x440] with args (0x8b, param_2)
- Stores result to *param_1

**Calls:** vtable+200 dispatch

**Used by system:** docs/01-engine-architecture.md -- vtable dispatch

<!-- target: docs/01-engine-architecture.md -->

## FUN_00543440 -- Render/Draw Operation with Clipping
Source: unknown | Confidence: medium
Call coordinate transform, conditionally dispatch draw with size check.

**Key logic:**
- Transforms 2 coords via FUN_00543540
- If width>0 and height>0: calls FUN_005404d0 (draw) with all params
- Clears bit 10 in flag at param_1+0x18

**Calls:** FUN_00543540, FUN_005404d0

**Used by system:** docs/19-renderer.md -- 2D draw with clipping

<!-- target: docs/01-engine-architecture.md -->

## FUN_005469c0 -- Reference Counted Resource Release
Source: unknown | Confidence: medium
Decrement resource reference and release when zero.

**Key logic:**
- Decrements ref counts at +0x84 and +0x88
- When +0x88 reaches 0: iterates active resources at +0xa8, decrements each resource's reference
- When resource ref hits 0: iterates sub-elements calling FUN_005502c0, frees via FUN_005478b0
- Sets completion flags

**Calls:** FUN_005502c0, FUN_005478b0

**Used by system:** docs/01-engine-architecture.md -- ref-counted resource cleanup

<!-- target: docs/01-engine-architecture.md -->

## FUN_005474d0 -- Resource/Object Creation with Config
Source: unknown | Confidence: medium
Allocate and configure resource object with name/callback setup.

**Key logic:**
- Checks for existing object via FUN_00548890; increments refcount if found
- Allocates 0xc4-byte object via FUN_00546250
- Registers via FUN_00546330
- Allocates packed array (stride 0x94 + 4 header)
- Conditionally calls FUN_0054fc10 and FUN_00546f30 based on param_5/param_6 string flags
- Sets flags and init status

**Calls:** FUN_00548890, operator_new, FUN_00546250, FUN_00546330, FUN_0054fb90, FUN_00547100, FUN_0054fc10, FUN_00546f30, FUN_00546f70, FUN_00547670

**Used by system:** docs/01-engine-architecture.md -- resource creation

<!-- target: docs/20-math-utilities.md -->

## FUN_005568d0 -- Callback Registration
Source: unknown | Confidence: high
Register LAB_005568e0 via FUN_00587b3e.

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055c060 -- Call Wrapper
Source: unknown | Confidence: high
Call FUN_0055be60().

**Calls:** FUN_0055be60

**Used by system:** docs/01-engine-architecture.md -- dispatch wrapper

<!-- target: docs/08-file-formats.md -->

## FUN_00566d30 -- Conditional Alloc/Init Dispatch
Source: unknown | Confidence: medium
Branch on param_1[4]: call alloc or init, return success.

**Key logic:**
- If param_1[4] == 0: calls FUN_00587f64(*param_1, 0)
- Else: calls FUN_00535390(0)
- Returns (result == 0)

**Calls:** FUN_00587f64, FUN_00535390

**Used by system:** docs/01-engine-architecture.md -- conditional dispatch

<!-- target: docs/20-math-utilities.md -->

## FUN_0057aa20 -- Callback Registration
Source: unknown | Confidence: high
Register LAB_0057aa30 via FUN_00587b3e.

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583aa0 -- Close Handle Pair Wrapper
Source: unknown | Confidence: high
Close two Win32 handles with active flags.

**Key logic:**
- If flag at +0x24 set: close handle at +0x1c via CloseHandle, zero handle
- If flag at +0x14 set: close handle at +0xc via CloseHandle, zero handle

**Calls:** CloseHandle (Win32 API)

**Used by system:** docs/01-engine-architecture.md -- handle cleanup

<!-- target: docs/01-engine-architecture.md -->

## FUN_005871c0 -- Dual Query into Two Output Params
Source: unknown | Confidence: high
Query two values and store to output pointers.

**Key logic:**
- Calls FUN_00563e70() → *param_1
- Calls FUN_0053d880() → *param_2
- Returns 0

**Calls:** FUN_00563e70, FUN_0053d880

**Used by system:** docs/01-engine-architecture.md -- dual value query

<!-- target: docs/20-math-utilities.md -->
## __fclose_lk at 00587d33 -- MSVC __fclose_lk
Source: unknown | Confidence: high
MSVC CRT internal file close with lock. Closes file handle, frees buffer, handles temp file cleanup.

**Key logic:**
- Checks _flag for open/read/write bits (0x83)
- Flushes via FUN_0058a05a
- Frees buffer via __freebuf
- Closes file descriptor via FUN_0058c331
- Deletes temp file if _tmpfname set
- Sets _flag = 0

**Calls:** FUN_0058a05a, __freebuf, FUN_0058c331, FUN_0058aa6f

**Used by system:** docs/08-file-formats.md -- CRT file I/O

<!-- target: docs/20-math-utilities.md -->
## __setjmp3 at 0058a7ec -- MSVC __setjmp3
Source: unknown | Confidence: high
MSVC CRT setjmp implementation — saves register state and exception handler chain.

**Key logic:**
- Saves EBP, EBX, EDI, ESI, ESP, return address
- Sets magic number 0x56433230
- Saves ExceptionList for SEH chain
- If param_2 > 1: copies up to 6 additional params from stack

**Calls:** None (pure register save)

**Used by system:** docs/20-math-utilities.md -- MSVC CRT setjmp

<!-- target: docs/20-math-utilities.md -->
## __startOneArgErrorHandling at 0058dc57 -- MSVC CRT Error Handler
Source: unknown | Confidence: high
MSVC CRT startOneArgErrorHandling — convert float to double, invoke error handler.

**Key logic:**
- Converts ST0 float to double
- Calls FUN_00596175 with param_2, local buffer, and param_3
- Returns original ST0 value

**Calls:** FUN_00596175

**Used by system:** docs/20-math-utilities.md -- MSVC CRT math error handling

<!-- target: docs/20-math-utilities.md -->

## FUN_0059982f -- Callback Registration
Source: unknown | Confidence: high
Register LAB_0059983b via FUN_00587b3e.

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059b086 -- Callback Registration
Source: unknown | Confidence: high
Register FUN_00599796 via FUN_00587b3e.

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md -- cleanup registration

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c730 -- SEH Unwind Cleanup
Source: unknown | Confidence: high
SEH unwind: free at EBP-0x10.

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059ce7e -- C++ Unwind Helper Thunk
Source: unknown | Confidence: high
Thunk to FUN_00585f30.

**Calls:** FUN_00585f30

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d524 -- C++ Unwind Helper Thunk
Source: unknown | Confidence: high
Thunk to FUN_0059a9c2.

**Calls:** FUN_0059a9c2

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

## FUN_00554660 — Float State Setter with Change Notification

Source: unknown | Confidence: high
Conditional float state setter. Compares new value to current stored value; dispatches notification via vtable only on change.

**Key logic:**
- Compares param_2 to param_1[0x10] (current stored float value)
- If different: updates param_1[0x10] = param_2, then calls vtable dispatch
- Dispatch: (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0, *param_1, 0x13, param_1[0x10])
  - DAT_008b89a0 is global state manager/device with virtual dispatch table
  - +0xfc = notification/event method offset in vtable
  - 0x13 = notification ID (parameter 3)
  - param_1[0x10] = new float value as payload

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | uint32 | Object ID/handle, passed as notification target |
| +0x40 (0x10 * 4) | float | Current state value, compared and updated |

**Globals:**
- DAT_008b89a0 — state manager / device dispatch table (vtable +0xfc = notification sender)

**Calls:** vtable dispatch at DAT_008b89a0+0xfc (state change notification)

**Used by system:** docs/01-engine-architecture.md — state management with change detection pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00556900 — Add Float to Animation Channels

Source: unknown | Confidence: high
Iterates animation channel linked list and adds a float value to all active (flagged) channels.

**Key logic:**
- Starts from *(*(param_1+0x110)+0x28) — linked list head
- Walks list via next pointer at +0x5c
- For each node: reads channel data pointer at +0x54
- Checks *(channel+0x18) & 0x400 — flag test for active/affected channel
- If flag set: adds param_2 to *(channel+0x38) (float accumulator/offset at +0x38)

**Struct offsets (param_1):**
| Offset | Indirect | Type | Notes |
|--------|----------|------|-------|
| +0x110 | -> +0x28 | int* | Linked list head pointer |
| +0x5c | (node) | int* | Next node link |
| +0x54 | (node) | int* | Channel data pointer |
| +0x18 | (channel) | uint32 | Flag field — 0x400 = active channel |
| +0x38 | (channel) | float | Float accumulator/offset value |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — animation system, float offset addition across animation channels

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005507e0 — Struct Init with Vtable Zero

Source: unknown | Confidence: high
Initializes a struct by calling base init, then zeroing fields at +0x0, +0x20, +0x24, +0x28.

**Key logic:**
- Calls FUN_0053c2a0() (base struct/object init, short computation)
- Sets *param_1 = 0 (first byte zeroed)
- Sets *(param_1+0x20) = 0
- Sets *(param_1+0x24) = 0
- Sets *(param_1+0x28) = 0
- Returns param_1 pointer

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | unknown | byte | Zeroed |
| +0x20 | unknown | uint32 | Zeroed |
| +0x24 | unknown | uint32 | Zeroed |
| +0x28 | unknown | uint32 | Zeroed |

**Calls:** FUN_0053c2a0 (base init/short computation, docs/20)

**Used by system:** docs/01-engine-architecture.md — memory/object init pattern (cctor with vtable setup)

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0055ce50 — Set UI Text Fields via Vtable Calls

Source: unknown | Confidence: high
Sets three text string fields through vtable dispatch on a UI manager object.

**Key logic:**
- Accesses param_1[0x440] (pointer to manager with vtable)
- Calls vtable method at +0x94 with ID 2, buffer at param_1+0x516
- Calls vtable method at +0x94 with ID 3, buffer at param_1+0x526
- Calls vtable method at +0xa0 with buffer at param_1+0x536
- Results stored in *param_1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1100 | int* | Manager/object ptr with vtable |
| +0x516 | char[16] | Text buffer 1 (field ID 2) |
| +0x526 | char[16] | Text buffer 2 (field ID 3) |
| +0x536 | char[16] | Text buffer 3 |

**Calls:** vtable dispatch at manager+0x94, manager+0xa0 (text field setters)

**Used by system:** docs/01-engine-architecture.md — UI text update via virtual dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00560b90 — Conditional Free of Field

Source: unknown | Confidence: high
Conditionally frees pointer at param_1+4.

**Key logic:**
- If *(param_1+4) != 0: free via FUN_00587bcf()

**Calls:** FUN_00587bcf (memory free, docs/20)

**Used by system:** docs/01-engine-architecture.md — cleanup pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00579ff0 � Single Function Call Wrapper

Source: unknown | Confidence: high
Delegates directly to FUN_00599958.

**Key logic:**
- Calls FUN_00599958() � resource scan/refresh function (docs/08)

**Calls:** FUN_00599958 (resource scan/refresh, docs/08)

**Used by system:** docs/01-engine-architecture.md � call wrapper/refresh trigger

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a730 � Two-Step Init Sub-Call

Source: unknown | Confidence: high
Two-step init: calls list dispatch then queue APC.

**Key logic:**
- FUN_00585320(param_1) � linked-list walk with dispatch per node
- FUN_00585de0(0) � QueueUserAPC async procedure call with arg 0

**Calls:**
- FUN_00585320 � list iteration with dispatch (docs/20)
- FUN_00585de0 � queue APC call (docs/20)

**Used by system:** docs/01-engine-architecture.md � entity init sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057db80 � Two-Field Equality Check

Source: unknown | Confidence: high
Compares two struct fields against given values. Returns 1 if both match.

**Key logic:**
- Checks *(param_1+4) == param_3 (int comparison)
- Checks *(param_1+2) == param_2._2_2_ (short comparison)
- Returns 1 if both equal, 0 otherwise

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � lookup/find predicate

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00582720 � Mutex Create/Replace Wrapper

Source: unknown | Confidence: high
Closes existing mutex handle if flag set, then creates new unnamed mutex via CreateMutexA.

**Key logic:**
- If *(param_1+0x28) flag set: CloseHandle(*(param_1+0x20)), zero on success
- Set SECURITY_ATTRIBUTES: nLength=0xc, lpSecurityDescriptor=0, bInheritHandle=1
- CreateMutexA(&local_c, 0, 0) � unnamed, not initially owned
- Store handle at *(param_1+0x20), set flag at *(param_1+0x28)=1 on success
- Returns flag value (0 if mutex creation failed)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | HANDLE | Mutex handle, closed then replaced |
| +0x28 | byte | Flag: non-zero = handle is open/valid |

**Calls:** CloseHandle (Win32), CreateMutexA (Win32)

**Used by system:** docs/01-engine-architecture.md � thread sync object lifecycle

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00584dd0 � Mutex-Protected Dispatch Call

Source: unknown | Confidence: high
Acquires mutex at param_1+0x570, dispatches FUN_00586000 with param_2, releases mutex.

**Key logic:**
- Checks mutex handle at *(param_1+0x570) non-null
- WaitForSingleObject(mutex, timeout at *(param_1+0x574))
- If WAIT_OBJECT_0 or WAIT_ABANDONED: call FUN_00586000(param_2, 0) � list node append
- If mutex valid: ReleaseMutex()
- Returns result

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x570 | HANDLE | Mutex handle |
| +0x574 | DWORD | Wait timeout ms |

**Calls:** WaitForSingleObject, ReleaseMutex (Win32), FUN_00586000 (list append, docs/20)

**Used by system:** docs/01-engine-architecture.md � thread-safe dispatch with mutex

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585f30 � Handle Close with Flag Check

Source: unknown | Confidence: high
Conditionally closes a handle, then calls cleanup function.

**Key logic:**
- If *(param_1+0x58) flag set: CloseHandle(*(param_1+0x50)), zero on success
- Calls FUN_00583650() � function call wrapper

**Calls:** CloseHandle (Win32), FUN_00583650 (call wrapper, docs/20)

**Used by system:** docs/01-engine-architecture.md � handle cleanup in thread/object destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587460 � Array/Struct Alloc with Count + Init

Source: unknown | Confidence: high
Allocates array of param_2 elements. Zeros head/tail/count, calls allocator, stores capacity.

**Key logic:**
- Zero param_1[0], [1], [2] (head, tail, count)
- If param_2 > 0: call FUN_005874d0(param_2, param_1)
- Store param_1[1] = param_2 (capacity)

**Calls:** FUN_005874d0 � operator new with result check (docs/20)

**Used by system:** docs/01-engine-architecture.md � container allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a677 � N-Time Callback Loop with SEH

Source: unknown | Confidence: high
Executes a callback function pointer param_3 times, wrapped in SEH frame.

**Key logic:**
- Sets up SEH frame (ExceptionList = &local_14)
- Sets puStack_c = &DAT_005b8ca8 (SEH filter)
- Sets puStack_10 = &LAB_0058895c (SEH handler)
- Loop param_3 iterations: decrement, if <0 break, call (*param_4)()
- Restores ExceptionList

**Algorithm family:** MSVC SEH � callback repeater with exception protection

**Calls:** (*param_4)() � user-supplied callback function pointer

**Used by system:** docs/01-engine-architecture.md � timed/repeated callback with SEH protection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593c50 � CRT __CallSettingFrame@12

Source: MSVC CRT | Confidence: high
MSVC __CallSettingFrame � SEH notification helper. Notifies NLG (Non-Local Goto) handler, calls function pointer, then notifies again.

**Key logic:**
- pcVar1 = __NLG_Notify1(param_3) � get handler for notification code
- (*pcVar1)() � call the handler
- If param_3 == 0x100: param_3 = 2 (convert to unwind code)
- __NLG_Notify1(param_3) � send second notification

**Algorithm family:** MSVC CRT � SEH frame setup/notification

**Calls:** __NLG_Notify1 (MSVC NLG runtime), function pointer dispatch

**Used by system:** docs/01-engine-architecture.md � MSVC exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598a41 � Vtable/Cctor Init

Source: unknown | Confidence: high
C++ constructor/initializer. Sets up vtable pointers, calls init functions, manages SEH frame.

**Key logic:**
- FUN_0058a5d8() � SEH handler init
- Sets vtable pointer in ECX register area
- If *(EBP+0xc) != 0:
  - *extraout_ECX = &DAT_005b9bb8 (vtable)
  - extraout_ECX[10] = 0
  - extraout_ECX[1] = &PTR_FUN_005b9bb4 (secondary vtable)
  - Sets init flags
- Sets vtable at computed offset: *(*(extraout_ECX+4)+extraout_ECX) = &PTR_LAB_005b9bac
- FUN_0059a8fa() � vtable/constructor helper (docs/18)
- Restores ExceptionList

**Calls:**
- FUN_0058a5d8 � SEH handler init (docs/20)
- FUN_0059a8fa � vtable/constructor helper (docs/18)

**Algorithm family:** MSVC C++ � constructor with vtable setup and SEH protection

**Used by system:** docs/01-engine-architecture.md � C++ object construction with SEH

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599822 � Single Function Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_00599e66 with argument 0.

**Key logic:**
- Calls FUN_00599e66(0) � vtable pointer setter with null arg

**Calls:** FUN_00599e66 � vtable pointer setter/constructor (docs/20)

**Used by system:** docs/01-engine-architecture.md � call wrapper/constructor stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a980 � Double Linked List Free

Source: unknown | Confidence: high
Frees two singly-linked lists at param_1+0x18 and param_1+0x1c. Each node is freed via FUN_00587bcf.

**Key logic:**
- FUN_0059a8d8(0) � callback chain iteration with null
- Walk list at param_1+0x18: save next (*puVar2), free node (FUN_00587bcf), advance to saved next
- Zero param_1+0x18 (list head)
- Walk list at param_1+0x1c: same pattern
- Zero param_1+0x1c

**Calls:**
- FUN_0059a8d8 � callback chain iteration (docs/20)
- FUN_00587bcf � memory free (docs/20)

**Used by system:** docs/01-engine-architecture.md � linked list cleanup/destructor

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->
