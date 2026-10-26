# F1 Challenge 99-02 — Architecture Manual

**The wiring diagram.** How subsystems connect, what runs when, what depends on what.

Built from: runtime traces (3,098 frames via Frida), 16,475 call edges, 8,048 named globals, 6,868 documented functions.

---

## 1. Thread Model

**Single-threaded.** Confirmed across 3,098 frames (pre-start + racing). All game logic, physics, AI, and rendering run on one thread (main thread).

Background threads (OS-level, not hooked):
- **Miles Sound System** — audio mixing via DirectSound callbacks
- **Network I/O** — Winsock async for multiplayer
- **Bink Video** — decode thread during cutscenes only

No synchronization primitives observed in game code. No mutexes, no critical sections between subsystems. Everything is single-pass per frame.

---

## 2. Frame Loop

Source: `game.cpp` — `FUN_0042d8a0` (MainLoop)

Entry chain: CRT `_start` → `FUN_0045b200` (GameMainEntry) → `FUN_0042d8a0` (MainLoop)

Loop runs while `GameState == 5` (RUNNING). Exits on `GameState == 1` (INIT) or `4` (EXIT).

### Execution Order (runtime-confirmed)

```
 1. SessionStateCheck        ×2       — check session validity
 2. FrameInit                          — reset per-frame state
 3. SessionStateCheck                  — post-init check
 4. SessionStateMachine                — pause handler (returns 4=exit, 5=continue)
    ─── subsystem updates ─────────────────────────────────
 5. ConditionalMultiPath               — dispatch based on game mode
 6. ConditionalStateUpdate             — race tick mode 2
 7. BufferReset              (1st)     — clear per-frame buffers
 8. MultiPhaseStateMachine             — multi-phase processing
 9. StewardUpdate                      — race steward + audio DSP
10. CollisionGlobalBroadcast           — broadphase collision + force feedback
11. PhysicsDispatchChain               — THE physics pipeline (see §4)
12. IterateVehicles                    — per-vehicle state updates
13. CollisionResponseStatus            — narrowphase collision resolution
14. TwoPathDispatch                    — race tick OR render path
15. BufferReset              (2nd)     — second clear
    ─── conditional (HUD enabled) ─────────────────────────
16. MainCameraDirectorUpdate           — camera system
17. WeatherParticleUpdate              — rain/spray particles
18. ScreenSaveCapture                  — screenshot capture
19. UIInitChain                        — UI overlay update
    ─── post-update ───────────────────────────────────────
20. FrameTimingPause                   — delta time computation
21. FrameTimingEnd                     — finalize timing
22. RenderTickUpdate                   — submit render commands
23. WindowsMessagePump                 — Sleep + message dispatch
```

### Frame Timing

| State | FPS | Calls/frame | Physics steps/frame |
|-------|-----|-------------|---------------------|
| Pre-start | ~200 | ~560 | 0 |
| Racing | ~113 | ~1,800 | 3–36 (avg 9.7) |

---

## 3. Subsystem Map

15 subsystems identified from documentation structure and source files.

### Core Systems (called every frame from main loop)

| Subsystem | Source files | Functions | Main loop entry |
|-----------|------------|-----------|-----------------|
| **Engine Core** | `game.cpp`, `osman.cpp`, `vidman.cpp` | 1,053 | GameMainEntry, WinMsgPump, ScreenSave |
| **Session/Race** | `steward.cpp`, `options.cpp` | 872 | SessionStateMachine, StewardUpdate, TwoPathDispatch |
| **Renderer** | `render.cpp`, `specialfx.cpp`, `vehgfx.cpp` | 482 | RenderTickUpdate, WeatherParticleUpdate, CameraDirector |
| **Collision** | — | 363 | CollisionGlobalBroadcast, CollisionResponseStatus |

### Physics Pipeline (called from PhysicsDispatchChain, step 11)

| Subsystem | Source files | Functions | Entry point |
|-----------|------------|-----------|-------------|
| **Vehicle Physics** | `hdvehicle.cpp`, `vehload.cpp` | 119 | VehiclePhysicsDispatcher |
| **Dynamics** | `dynman.cpp` | 325 | PhysicsStepFrame |
| **Tires** | `tire_manager.cpp` | 13 | WheelTireForceUpdate |
| **Engine Wear** | — | 14 | EngineStressSimulation |
| **Collision** (physics) | — | (shared) | ContactForceResolution |

### Game Logic (called from race tick path or conditionally)

| Subsystem | Source files | Functions | Trigger |
|-----------|------------|-----------|---------|
| **AI** | `ai_db.cpp` | 73 | AIMainUpdate (from PhysicsDispatchChain, ~31.7 Hz) |
| **Pit** | `pitcrew.cpp` | 29 | PitLaneLogic (from SessionTickUpdate) |
| **Weather** | `weather.cpp` | 7 | WeatherParticleUpdate (every frame) |
| **Track** | `searchgrid.cpp`, `camera.cpp` | 100 | CameraDirector, SessionStateCheck |

### Infrastructure

| Subsystem | Source files | Functions | Role |
|-----------|------------|-----------|------|
| **Math/Utility** | `util.cpp` | 2,969 | CRT, math, string ops — called by everything |
| **File I/O** | `config.cpp`, `plrfile.cpp`, `garage.cpp` | 339 | File loading, save/restore, binary search |
| **Audio/Network** | `sound.cpp`, `NetComm.cpp`, `LbMpeg.cpp` | 229 | Audio DSP, network messages, MPEG decode |

---

## 4. Physics Pipeline (runtime-confirmed)

Fixed timestep: **~1.16ms (~864 Hz)**. Variable sub-stepping: 3–36 per frame (avg 9.7).

```
PhysicsDispatchChain (FUN_0042c690)
│
├── VehiclePhysicsDispatcher (1st pass — 1 sub-step, prediction)
│     └── PhysicsStepFrame ×1
│
├── VehiclePhysicsDispatcher (2nd pass — N sub-steps, accumulator catch-up)
│     └── VehiclePhysicsIntegStep ×N
│           └── PhysicsStepFrame ×N
│                 ├── EngineStressSimulation
│                 ├── Anti-roll bar / suspension
│                 ├── Force accumulation (per wheel)
│                 ├── Rodrigues rotation matrix
│                 ├── Contact geometry transform
│                 ├── Contact force resolution
│                 └── Per-wheel integration finalize
│
└── AIMainUpdate ×22 (fires ~28% of frames, ~31.7 Hz per vehicle)
```

**Two-pass structure**: 1st pass runs 1 sub-step (prediction/setup). 2nd pass runs N sub-steps where N = accumulated_time / timestep. This is a standard fixed-timestep accumulator pattern used in real-time physics.

**AI runs FROM physics**, not from the main loop. AI update is triggered within PhysicsDispatchChain, fires roughly every 3.6 render frames. When it fires, it always processes all 22 vehicles.

### State-dependent behavior

| Game state | Physics | AI | Notes |
|------------|---------|-----|-------|
| Pre-start | OFF (returns immediately) | OFF | Only rendering + state checks |
| Racing | FULL (3-36 sub-steps) | ON (~31.7 Hz) | Peak CPU load |
| Paused | OFF | OFF | Delta time forced to 0.0 |

---

## 5. Cross-Subsystem Dependencies

### Call Graph (10,399 cross-subsystem edges)

```
Math/Utility ←──── 4,002 incoming calls (THE hub — CRT, math, strings)
Engine Core  ←──── 2,019 incoming calls (malloc/free wrappers, linked lists)
Session/Race ←──── 1,311 incoming calls (debug logging, state queries)
File I/O     ←────   699 incoming calls (string format, binary search)
Renderer     ←────   614 incoming calls (DirectX, texture creation)
```

Top cross-subsystem call pairs:

| Source | Target | Edges | Nature |
|--------|--------|-------|--------|
| Math/Utility | Engine Core | 879 | Utility calling memory management |
| Engine Core | Math/Utility | 737 | Core using math/string functions |
| Session/Race | Math/Utility | 726 | Race logic using CRT functions |
| Renderer | Math/Utility | 683 | Render pipeline using math |
| File I/O | Math/Utility | 474 | File parsing using string ops |
| Session/Race | Engine Core | 219 | Race logic using memory/list ops |
| Renderer | Engine Core | 223 | Renderer using memory management |
| Session/Race | File I/O | 165 | Race logic loading data files |
| File I/O | Session/Race | 162 | File I/O calling debug logging |

### Dependency Layers

```
Layer 0 (no dependencies):     Math/Utility, File I/O
Layer 1 (depends on L0):       Engine Core, Audio/Network
Layer 2 (depends on L0-1):     Collision, Dynamics, Renderer, Track
Layer 3 (depends on L0-2):     Vehicle Physics, Tires, Engine Wear
Layer 4 (depends on L0-3):     AI, Session/Race, Pit, Weather
Layer 5 (orchestrator):        Engine Core (game.cpp main loop)
```

Note: Engine Core appears at both Layer 1 (infrastructure: malloc/free/linked lists) and Layer 5 (orchestrator: game.cpp main loop). These are logically separate — infrastructure is passive utilities, orchestrator is the frame loop driver.

---

## 6. Global Ownership (shared mutable state)

80 globals written by 2+ subsystems — these are the coupling interfaces.

### Critical Shared State

| Global | Name | Writers | Readers | Role |
|--------|------|---------|---------|------|
| `DAT_007c54dc` | CurrentPlayerIndex | Engine Core, Session/Race, Track | 9 subsystems | Player vehicle selection |
| `DAT_005c329c` | VehicleCount | File I/O, Session/Race, Track | 11 subsystems | Total vehicles in session |
| `DAT_007d0410` | RaceMode | Engine Core, Session/Race, Track | 10 subsystems | Championship/single race mode |
| `DAT_007C5690` | InitStateFlag | Engine Core, File I/O, Session/Race, Track | AI, Engine Core, Session/Race | Initialization state machine |
| `DAT_007d00ec` | GameState | Session/Race, unknown | File I/O | Main state variable (1-7) |
| `DAT_008AFE90` | DeltaTime (raw) | Math/Utility, unknown | 9 subsystems | Per-frame timing |
| `DAT_008AFE98` | DeltaTime (clamped) | Math/Utility, unknown | 11 subsystems | Clamped to 0.5s max |

### Ownership Pattern

6,909 of 7,990 tracked globals have **no static writer** — they are set via:
- Config file parsing at startup
- Runtime initialization (constructor patterns)
- Indirect writes through pointers (not visible in static analysis)

This means ~87% of globals are effectively **read-only after initialization** — set once at startup, read throughout the frame loop. Only ~1,081 globals are actively written during gameplay.

---

## 7. Data Flow Per Frame

### Write-then-read order (runtime-confirmed)

```
Frame N:
  ┌─────────────────────────────────────────────┐
  │ 1. State management                         │
  │    WRITES: GameState, SessionType, RacePhase │
  │    READS:  previous frame's state            │
  ├─────────────────────────────────────────────┤
  │ 2. Steward / Rules                          │
  │    WRITES: penalty flags, steward state      │
  │    READS:  vehicle positions, lap counts     │
  ├─────────────────────────────────────────────┤
  │ 3. Collision broadphase                      │
  │    WRITES: contact pairs, force feedback     │
  │    READS:  vehicle bounding volumes          │
  ├─────────────────────────────────────────────┤
  │ 4. Physics (N sub-steps)                     │
  │    WRITES: vehicle position, velocity,       │
  │            tire forces, engine state          │
  │    READS:  contact pairs, track surface,     │
  │            input commands                     │
  ├─────────────────────────────────────────────┤
  │ 5. AI (~every 3.6 frames)                    │
  │    WRITES: AI throttle/brake/steer commands   │
  │    READS:  vehicle positions, track data,    │
  │            race state                         │
  ├─────────────────────────────────────────────┤
  │ 6. Vehicle iteration                         │
  │    WRITES: per-vehicle state flags            │
  │    READS:  physics output                    │
  ├─────────────────────────────────────────────┤
  │ 7. Collision narrowphase                     │
  │    WRITES: collision response forces          │
  │    READS:  updated positions from physics    │
  ├─────────────────────────────────────────────┤
  │ 8. Race tick                                 │
  │    WRITES: lap counts, positions, timing      │
  │    READS:  vehicle state, steward output     │
  ├─────────────────────────────────────────────┤
  │ 9. Camera + Weather + UI                     │
  │    WRITES: camera matrix, particle state      │
  │    READS:  player vehicle position            │
  ├─────────────────────────────────────────────┤
  │ 10. Render                                   │
  │    READS:  everything above (read-only pass)  │
  │    WRITES: frame buffer (DirectX)             │
  ├─────────────────────────────────────────────┤
  │ 11. Timing + Message pump                    │
  │    WRITES: delta time, frame counter          │
  │    READS:  QPC timer                          │
  └─────────────────────────────────────────────┘
```

### The Update Contract

Physics writes vehicle state → Renderer reads it. Never the reverse. This is the fundamental invariant: **physics is authoritative for all vehicle state**.

AI reads vehicle positions from the PREVIOUS physics pass and writes commands that the NEXT physics pass will consume. AI is always one physics cycle behind — this is intentional lag to avoid feedback loops.

The steward (race rules) runs BEFORE physics so that penalties and flags are applied before physics integration. This means a black flag takes effect immediately on the next physics step.

---

## 8. Initialization Sequence

From `game.cpp` — `FUN_0045b200` (GameMainEntry):

```
GameMainEntry
  ├── PlayerFileLoad          — load player profile
  ├── StewardInit             — initialize race steward
  ├── ReplayBinkSetup         — initialize replay/video
  ├── HWInput::Setup          — DirectInput initialization
  ├── Sound::Setup            — Miles Sound System init
  ├── CameraManager::Setup    — camera system init
  └── MainLoop                — enter frame loop
```

Restart path (`FUN_0042d7a0` — Game::Restart):
```
Game::Restart
  ├── Sound::Restart
  ├── StewardRestart
  ├── RaceTimerReset
  ├── HWInput::Restart
  ├── CameraManager::Restart
  └── [return to MainLoop]
```

---

## 9. Original Source Layout

From assert strings: `D:\dev\F1_1999_2002\Source\`

| Source file | Subsystem | Functions | Address range |
|------------|-----------|-----------|---------------|
| `game.cpp` | Engine Core | 9 | 0x0042cf10–0x0042dbcb |
| `dynman.cpp` | Dynamics | 6 | 0x0042c130–0x0042ca70 |
| `hdvehicle.cpp` | Vehicle Physics | 5 | 0x00439210–0x0043da10 |
| `tire_manager.cpp` | Tires | 7 | 0x004d5ee0–0x004d7880 |
| `steward.cpp` | Session/Race | 6 | 0x004d0110–0x004d4600 |
| `ai_db.cpp` | AI | 2 | 0x004024f0–0x004040a0 |
| `NetComm.cpp` | Audio/Network | 17 | 0x0045d890–0x00464290 |
| `camera.cpp` | Track/Camera | 3 | 0x0040c920–0x0040cce0 |
| `sound.cpp` | Audio | 6 | 0x004c8a20–0x004c8d00 |
| `render.cpp` | Renderer | 3 | 0x004b4030–0x004b4170 |
| `specialfx.cpp` | Renderer | 10 | 0x004ca480–0x004d001d |
| `vidman.cpp` | Engine Core | 7 | 0x004f9310–0x004fad7d |
| `plrfile.cpp` | File I/O | 5 | 0x004b0770–0x004b194b |
| `config.cpp` | File I/O | 1 | 0x00421cd0–0x00422bdf |
| `pitcrew.cpp` | Pit | 3 | 0x004a2010–0x004a2a90 |
| `weather.cpp` | Weather | 1 | 0x004fe820–0x004fea97 |
| `hwinput.cpp` | Input | 6 | 0x00455bf0–0x00455f00 |
| `vehload.cpp` | Vehicle Physics | 3 | 0x004f3240–0x004f4270 |
| `vehgfx.cpp` | Renderer | 2 | 0x004ddf90–0x004e07f6 |
| `LbMpeg.cpp` | Audio | 3 | 0x0052da30–0x0052e2e8 |

Only ~55 source files identified from assert strings. The remaining ~6,800 functions have no source file attribution — they are the anonymous bulk in `decompiled_full/`.

---

## 10. Recreation Order

Based on the dependency layers and coupling analysis:

### Phase 1: Foundation (no game dependencies)
1. **Math/Utility** — CRT replacements, vector/matrix math, string operations
2. **File I/O** — config file parsing, binary data loading, player file format

### Phase 2: Core Infrastructure
3. **Engine Core (infrastructure)** — memory management, linked lists, debug logging
4. **Audio/Network** — Miles Sound System wrapper, network message dispatch

### Phase 3: Physics Pipeline
5. **Dynamics** — rigid body integration, contact resolution, constraint solver
6. **Collision** — broadphase + narrowphase, contact geometry
7. **Vehicle Physics** — suspension, steering, vehicle-specific physics
8. **Tires** — tire model, force curves, wear simulation
9. **Engine Wear** — stress simulation, reliability model

### Phase 4: Game Logic
10. **Track** — track surface data, search grid, camera system
11. **AI** — driver behavior, path planning, command dispatch
12. **Session/Race** — race state machine, steward, lap counting, scoring
13. **Pit** — pit lane logic, pit stop sequence
14. **Weather** — weather state machine, particle effects

### Phase 5: Presentation
15. **Renderer** — DirectX 8 rendering pipeline, scene graph, special effects
16. **Engine Core (orchestrator)** — game.cpp main loop, frame timing

### Key insight for recreation
The physics pipeline (Phase 3) is the hardest and most critical part. It contains:
- 325 dynamics functions with LDL^T factorization, constraint solvers
- ~864 Hz fixed timestep with accumulator pattern
- Two-pass dispatch (prediction + integration)
- Tight coupling between tires, suspension, and contact resolution

Everything else is comparatively straightforward — state machines, data loading, rendering. The physics is where the simulation fidelity lives.

---

## 11. Key Addresses (quick reference)

| Address | Name | Role |
|---------|------|------|
| `0x0045b200` | GameMainEntry | Top-level entry after CRT init |
| `0x0042d8a0` | MainLoop | Frame loop (game.cpp) |
| `0x0042c690` | PhysicsDispatchChain | Physics pipeline entry |
| `0x004e4930` | VehiclePhysicsDispatcher | Per-vehicle physics |
| `0x00441600` | PhysicsStepFrame | Single physics timestep |
| `0x00424e70` | AIMainUpdate | AI entry (from physics chain) |
| `0x004a0fd0` | SessionStateMachine | Pause/state handler |
| `0x004c6b60` | SessionTickUpdate | Deep session logic |
| `0x004c8b70` | RenderTickUpdate | Render submission |
| `0x004a1830` | WindowsMessagePump | Frame pacing + messages |
| `0x004fa7e0` | FrameTimingPause | Delta time computation |

### Key Globals

| Address | Name | Type |
|---------|------|------|
| `DAT_007d00ec` | GameState | int (1-7) |
| `DAT_007c56a4` | SessionType | int (0-7) |
| `DAT_007c56a8` | RacePhase | int (0-7) |
| `DAT_008afe90` | DeltaTime (raw) | double |
| `DAT_008afe98` | DeltaTime (clamped) | double |
| `DAT_008afe84` | FrameCounter | int |
| `DAT_007c54e8` | PlayerVehiclePtr | ptr |
| `DAT_005c329c` | VehicleCount | int |
