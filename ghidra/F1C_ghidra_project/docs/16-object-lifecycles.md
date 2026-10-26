# Object Lifecycles

How major game objects are created, initialized, updated per frame, and destroyed.
Derived from call graph analysis (16,475 edges) and runtime traces (3,098 frames).

---

## Game Application Lifecycle

The top-level lifecycle, from process start to exit:

```
CRT _start
└── GameMainEntry (0x0045b200)
    ├── Config.ini Parser (0x00421cd0)      — load settings
    ├── NetComm::ParseCommandLine (0x00463160)
    ├── Game::Setup (0x0042d5d0)            — one-time resource allocation
    │   ├── PlayerFileLoad (0x004f9160)
    │   ├── Options::Setup / StewardInit (0x004a0eb0)
    │   ├── PlayerFile::Setup (0x004b1870)
    │   ├── HWInput::Setup (0x00455c60)     — DirectInput
    │   ├── Sound::Setup (0x004c8ab0)       — Miles Sound System
    │   ├── OnScreen::Setup (0x0049ef70)    — HUD
    │   ├── VidMan::Setup (0x004fa2f0)      — DirectX device
    │   ├── DynMan::Setup (0x0042c170)      — dynamics manager
    │   ├── SeasonInit (0x00463ef0)          — championship state
    │   └── SpecialFX::Setup (0x004ceec0)
    │
    ├── Game::Init (0x0042d6b0)             — per-session initialization
    │   ├── Replay::Init (0x004ba1f0)
    │   ├── VidMan::Init (0x004fa320)
    │   ├── HWInput::Init (0x00455d50)
    │   ├── SpecialFX::Init (0x004cf070)
    │   ├── DynMan::Init (0x0042c1a0)       — CREATES VEHICLES (see below)
    │   ├── CamMan::Init (0x0040c920)
    │   ├── Sound::Init (0x004c8ae0)
    │   ├── Render::Init (0x004b4030)
    │   └── OnScreen::Init (0x0049efa0)
    │
    ├── Game::Restart (0x0042d7a0)          — reset for new session
    │   ├── Sound::Restart (0x004c8b20)
    │   ├── StewardRestart (0x004a40f0)
    │   ├── RaceTimerReset (0x004a0fb0)
    │   ├── HWInput::Restart (0x00455da0)
    │   ├── CamMan::Restart (0x0040c9e0)
    │   ├── Render::Restart (0x004b4060)
    │   ├── OnScreen::Restart (0x0049f000)
    │   ├── VidMan::Restart (0x004fa640)
    │   ├── NetComm::Sync (0x00464290)
    │   ├── DynMan::Restart (0x0042c3b0)    — RESETS VEHICLES
    │   ├── PlayerFile::Restart (0x004b18d0)
    │   └── SpecialFX::Restart (0x004cfc90)
    │
    ├── MainLoop (0x0042d8a0)               — FRAME LOOP (see docs/22)
    │   └── ... (runs while GameState == 5)
    │
    └── Game::Exit (0x0042db20)             — cleanup + shutdown
```

### Subsystem Manager Pattern

Every subsystem follows the same 4-method lifecycle:
1. `::Setup()` — one-time allocation (called once at startup)
2. `::Init()` — per-session init (called when loading a track/session)
3. `::Restart()` — reset state (called when restarting session or loading new race)
4. Per-frame update — called from MainLoop every frame

Known managers:

| Manager | Setup | Init | Restart | Per-frame |
|---------|-------|------|---------|-----------|
| DynMan (dynamics) | 0x0042c170 | 0x0042c1a0 | 0x0042c3b0 | PhysicsDispatchChain |
| Sound | 0x004c8ab0 | 0x004c8ae0 | 0x004c8b20 | AudioDSPStateUpdate |
| CamMan (camera) | — | 0x0040c920 | 0x0040c9e0 | MainCameraDirectorUpdate |
| Render | — | 0x004b4030 | 0x004b4060 | RenderTickUpdate |
| VidMan (video) | 0x004fa2f0 | 0x004fa320 | 0x004fa640 | FrameInit/FrameEnd |
| OnScreen (HUD) | 0x0049ef70 | 0x0049efa0 | 0x0049f000 | UIInitChain |
| HWInput (input) | 0x00455c60 | 0x00455d50 | 0x00455da0 | ForceFeedbackInput |
| SpecialFX | 0x004ceec0 | 0x004cf070 | 0x004cfc90 | WeatherParticleUpdate |

---

## Vehicle Lifecycle

### Allocation

Vehicles are allocated during `DynMan::Init` (0x0042c1a0), called from `Game::Init`.

```
DynMan::Init (0x0042c1a0)
├── AIDriverCountSetup (0x004bfd90)      — determines how many AI + player vehicles
├── SortDriverInitOrder (0x004c01a0)      — sort grid positions
├── BuildActiveVehicleArray (0x0042bc80)  — fills DAT_007c54f0 (VehiclePtrArray)
├── SetPlayerVehicleIndex (0x0042bbd0)    — sets DAT_007c54dc (CurrentPlayerIndex)
├── SetPlayerVehiclePtr (0x0042bc40)      — sets DAT_007c54e8 (PlayerVehiclePtr)
├── VehgenScnLoader (0x004c6c40)          — loads vehgen.scn scene files
│   ├── VehicleGraphicsLoader (0x004dfce0)
│   └── SetDriverName (0x004c6980)
├── LoadAIDriverNames (0x004336f0)        — from config
└── PlayerNameSetup (0x004326e0)
```

Other paths that call `BuildActiveVehicleArray`:
- `PlayerFileInit` (0x004b0540) — loading a saved game
- `LoadVehicleEntries` (0x004b70b0) — loading from race entry list
- `ProcessDriverEntries` (0x004b8da0) — parsing driver data
- `MultiplayerSessionJoin` (0x0046de10) — joining multiplayer

### Initialization (per-vehicle)

Vehicle physics initialization happens through `SceneRenderUpdate` (0x004c6d90), called from `DynMan::Restart`:

```
DynMan::Restart (0x0042c3b0)
└── SceneRenderUpdate (0x004c6d90) — iterates all vehicles
    ├── AIDriverStructInit (0x00424790)     — zero AI state fields
    ├── VehicleArrayBufferAlloc (0x004bb810) — allocate per-vehicle buffers
    ├── LargeConfigPhysics (0x004e45b0)     — THE vehicle physics setup
    │   ├── WheelStateReset (0x004e4790)
    │   ├── TireModelInit (0x0043e050)      — tire constants + friction curves
    │   │   ├── SessionStructInit (0x0042e320)
    │   │   ├── TireModelDataInit (0x004f34e0) — zero-init tire arrays
    │   │   ├── SvmHdvParser (0x004f4270)      — parse .svm/.hdv vehicle files
    │   │   │   ├── VehicleDamageModel (0x004f24f0) — PHYSICAL section
    │   │   │   ├── PerWheelBrakeSuspension (0x004f2c60) — per-wheel data
    │   │   │   └── ... +21 more sub-calls
    │   │   ├── SuspensionBodyAlloc (0x00438da0)
    │   │   ├── VehicleSessionInit (0x0043c250) — lifetime variables
    │   │   └── BrakeBiasSetup (0x00438cc0)
    │   ├── SuspensionAndWheelPhysics (0x004e5f60)
    │   └── TireBrushModelSolver (0x004e8010)
    └── SessionTickUpdate (0x004c6b60)
```

### Per-Frame Update (during racing)

From the main loop (runtime-confirmed):

```
PhysicsDispatchChain (0x0042c690)           — step 11 in frame loop
├── VehiclePhysicsDispatcher (0x004e4930)   — 1st pass (1 sub-step)
├── VehiclePhysicsDispatcher (0x004e4930)   — 2nd pass (N sub-steps)
│   └── VehiclePhysicsIntegStep (0x00441650) × N
│       └── PhysicsStepFrame (0x00441600) × N
│           ├── EngineStressSimulation (0x0043ef20)
│           ├── SuspensionForces (0x00438130)
│           ├── WheelForceAccumulation (0x00438690)
│           ├── RotationMatrix (0x0056bde0)
│           ├── ContactGeometry (0x005692a0)
│           ├── ContactForceResolution (0x00569410)
│           └── PerWheelFinalize (0x00441450)
└── AIMainUpdate (0x00424e70) × 22          — fires ~28% of frames

IterateVehicles (0x004b3ba0)                — step 12 in frame loop
└── SessionStateCheck (0x00461cd0) × 22     — one per vehicle
```

### Vehicle Struct Layout (key offsets)

| Offset | Size | Field | Set by |
|--------|------|-------|--------|
| +0x0000 | ptr | vtable? | constructor |
| +0x002C | int | config entry | VehicleFieldAccessor (0x00432810) |
| +0x0048 | 4 | player index DC | SetPlayerVehicleIndex |
| +0x00E8 | 4 | player index E8 | SetPlayerVehicleIndex |
| +0x162C | ptr | suspension body array | TireModelInit |
| +0x48C0 | — | stride between vehicles | confirmed via runtime |

Vehicle array: `DAT_007c54f0` (VehiclePtrArray), max 103 vehicles.
Player vehicle: `DAT_007c54e8` (PlayerVehiclePtr).
Count: `DAT_005c329c` (VehicleCount).

### Destruction / Cleanup

`VehicleSubsystemCleanup` (0x00424010) — called during session teardown.

No explicit destructor pattern observed — vehicles live in a pre-allocated array and are reset via `DynMan::Restart` rather than individually destroyed.

---

## Session Lifecycle

### Session State Machine

```
GameState flow (DAT_007d00ec):
  1 (INIT) → 2 (MENU) → 3 (LOADING) → 4 (SETUP) → 5 (RUNNING) → back to 1 or 4

SessionType (DAT_007c56a4):
  0-5 = Practice variants
  6   = Qualifying
  7   = Race

RacePhase (DAT_007c56a8):
  0 = PRE_START → 1 = FORMATION → 2 = GREEN_FLAG → 3 = RACING
  4 = CAUTION → 5 = RED_FLAG → 6 = CHECKERED → 7 = POST_RACE → 8 = DONE
```

### Session Initialization Chain

```
Game::Init
└── DynMan::Init (0x0042c1a0)
    ├── AIDriverCountSetup — count vehicles
    ├── BuildActiveVehicleArray — populate vehicle array
    └── VehgenScnLoader — load vehicle scene data

Game::Restart
├── DynMan::Restart (0x0042c3b0)
│   ├── AI settings load (0x004333e0)
│   └── SceneRenderUpdate (0x004c6d90) — per-vehicle init
└── SessionDataLoad (0x004d3cf0)
    ├── CameraDirectorReset (0x0040da30)
    ├── SessionTypeLookup (0x0042ce30)
    └── ... +17 more sub-calls
```

### Per-Frame Session Logic

From `TwoPathDispatch` (step 14 in frame loop):
- Mode 1 (race): calls `RaceTickAdvance` (0x004b9890)
- Mode 2 (render): calls `RaceTickMode2` (0x004b9a00)

```
RaceTickAdvance (0x004b9890)
└── StateTriggerCheck (0x004b8ae0)
    ├── ConditionalMultiPath — dispatch by mode
    ├── WeatherParticleUpdate — weather system
    ├── StewardUpdate — race steward
    ├── CollisionGlobalBroadcast — collision
    ├── PhysicsDispatchChain — physics (2nd call in race mode)
    ├── CameraDirectorUpdate — camera
    ├── RenderTickUpdate — render
    └── WindowsMessagePump — frame end
```

`SessionTickUpdate` (0x004c6b60) — deep session logic per race tick:

| Call | Purpose |
|------|---------|
| 0x004bb8e0 | State reset on session condition |
| 0x004d1180 | Steward dispatch (session type check) |
| 0x004bc9b0 | Jump start / grid penalty detection |
| 0x004ef7c0 | AI vehicle path position tracking |
| 0x004e9600 | Suspension state update |
| 0x004f1c00 | Conditional buffer call |
| 0x004a5e60 | State/phase setter |
| 0x004a5e80 | Object state clear |
| 0x0040d100 | GameStateBranchDispatch |
| 0x00424b20 | AI logic (camera/frustum init) |
| 0x004efa40 | Vehicle climb adjust |

### Session Transition

`GameStateBranchDispatch` (0x0040d100) routes to:
- `ViewCameraModeDispatch` (0x00409440) — camera mode selection
- `GameActionStateMachine` (0x0040cde0) — action dispatch

`GameStateDispatchChain` (0x0040d240) handles:
- Camera view assignment (in-car vs chase)
- Camera target update on player change
- AI out-of-track events
- Player vehicle index changes
- Race state transitions

---

## AI Driver Lifecycle

### Initialization

AI drivers are initialized as part of vehicle init:

```
DynMan::Init
├── AIDriverCountSetup (0x004bfd90)
├── LoadAIDriverNames (0x004336f0)
└── ...

DynMan::Restart
└── SceneRenderUpdate
    └── AIDriverStructInit (0x00424790) — per-vehicle AI state zero
```

### Per-Frame Update

AI runs at ~31.7 Hz (not every frame), from within `PhysicsDispatchChain`:

```
AIMainUpdate (0x00424e70) × 22 vehicles
├── AIBehaviorInitTick (0x004bf0a0)
├── AITickUpdate (0x004bf4f0)
├── AICommandDispatcher (0x00424cd0)
└── AIStateUpdate (0x004a5d10)
```

AI reads vehicle positions from the previous physics pass and writes throttle/brake/steer commands for the next physics pass. Always one cycle behind — prevents feedback loops.

---

## Track / Scene Lifecycle

### Loading

Track data is loaded during session init, before vehicles:

```
Game::Init → DynMan::Init
└── VehgenScnLoader (0x004c6c40) — loads vehgen.scn
    ├── SceneDataParser (0x004c5690)
    ├── VehicleGraphicsLoader (0x004dfce0)
    └── SceneFileWriter (0x004ddf90)
```

Track configuration:
- `SearchGrid` (0x004bdc10) — spatial acceleration structure
- `SeasonRacesFinder` (0x004c5840) — season/championship track list

### Per-Frame Update

Track-related per-frame work happens in:
- `MainCameraDirectorUpdate` (0x0040ca30) — camera follows vehicle on track
- `WeatherParticleUpdate` (0x004cfcc0) — track surface conditions
- `CollisionGlobalBroadcast` (0x00455e50) — vehicle-track collision

---

## Timing Object Lifecycle

### Initialization

Timing globals are set during `Game::Restart`:
```
RaceTimerReset (0x004a0fb0) — zeros all timing globals
```

### Per-Frame Update

```
FrameTimingPause (0x004fa7e0) — step 20 in frame loop
├── Read QueryPerformanceCounter via FUN_00556730
├── Compute raw delta time → DAT_008afe90
├── If not paused: session_time += delta, clamp to 0.5s → DAT_008afe98
├── If paused: delta = 0.0
├── Accumulate session time → DAT_008afea0
├── Accumulate wall time → DAT_008afea8
└── Increment frame counter → DAT_008afe84

FrameTimingEnd (0x004f9f30) — step 21 in frame loop
```

### Key Timing Globals

| Global | Type | Written by | Read by |
|--------|------|-----------|---------|
| DAT_008afe90 | double | FrameTimingPause | 9 subsystems |
| DAT_008afe98 | double | FrameTimingPause | 11 subsystems (most used) |
| DAT_008afea0 | double | FrameTimingPause | Session/Race, AI |
| DAT_008afea8 | double | FrameTimingPause | AI, Collision, Session |
| DAT_008afe84 | int | FrameTimingPause | Engine Core |

DAT_008afe98 (clamped delta) is the most widely read global in the engine — 11 subsystems use it. This is the primary time source for all gameplay updates.
