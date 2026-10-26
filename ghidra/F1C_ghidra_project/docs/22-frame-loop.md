# Frame Loop Sequence

Source: `D:\dev\F1_1999_2002\Source\game.cpp` — `FUN_0042d8a0`

**Runtime-confirmed** via Frida traces: 98 frames pre-start + 3,000 frames active racing (22 vehicles, 26.6 seconds).

## Overview

The game uses a single-threaded main loop in `game.cpp`. Each iteration is one frame. The loop runs while game state is `5` (RUNNING); it exits on state `1` (INIT/restart) or `4` (EXIT).

Entry: `FUN_0045b200` (Game Main Entry) → `FUN_0042d8a0` (Main Loop).

## Per-Frame Call Sequence (runtime-confirmed)

```
do {
  1. FUN_00461cd0  — SessionStateCheck ×2
  2. FUN_004f9f00  — FrameInit
  3. FUN_00461cd0  — SessionStateCheck (post-init)
  4. FUN_004a0fd0  — SessionStateMachine / PauseHandler
                     returns: 4=exit, 5=continue, 6=error

  ── Per-frame subsystem updates ──────────────────────────

  5. FUN_004ba180  — ConditionalMultiPathDispatcher
  6. FUN_004ba150  — ConditionalStateUpdate
                     └→ FUN_004b9a00 (RaceTickMode2)
  7. FUN_004b3b40  — BufferReset (first call)
  8. FUN_00404460  — MultiPhaseProcessingStateMachine
  9. FUN_004d4580  — StewardUpdate
                     └→ FUN_00448330 (AudioDSPStateUpdate)
 10. FUN_00455e50  — CollisionGlobalBroadcast
                     └→ FUN_0044f150 (ForceFeedbackInput)
 11. FUN_0042c690  — PhysicsDispatchChain
                     (empty in pre-start; active during racing)
 12. FUN_004b3ba0  — IterateVehicles
                     └→ FUN_00461cd0 (SessionStateCheck) ×N per vehicle
 13. FUN_00463cd0  — CollisionResponseStatus
 14. FUN_004ba6c0  — TwoPathDispatch
                     └→ FUN_00461cd0 (SessionStateCheck)
                     mode 1 → FUN_004b9890 (RaceTickAdvance)
                     mode 2 → FUN_004b9a00 (render path)
 15. FUN_004b3b40  — BufferReset (second call)

  ── Conditional block (HUD enabled) ──────────────────────

 16. FUN_0040ca30  — MainCameraDirectorUpdate
 17. FUN_004cfcc0  — WeatherParticleUpdate
                     └→ FUN_004b9a00 (RaceTickMode2)
 18. FUN_004b40a0  — ScreenSaveCapture
 19. FUN_0049f070  — UIInitChain

  ── OR (HUD disabled / paused) ───────────────────────────

 16. FUN_004cfcc0  — WeatherParticleUpdate (only)

  ── Post-update ──────────────────────────────────────────

 20. FUN_004fa7e0  — FrameTimingPause (delta time, PAUSED text)
                     └→ FUN_005544c0 (GameStateSetViaVtable) ×~200
                     └→ FUN_005564b0 (QPCWrapperModeDispatch) ×~26
 21. FUN_004f9f30  — FrameTimingEnd
 22. FUN_004c8b70  — RenderTickUpdate
 23. FUN_004a1830  — WindowsMessagePump (Sleep for frame pacing)
                     └→ FUN_00461cd0 (SessionStateCheck)

} while (state != 1);
```

## Runtime Confirmation

Two traces captured 2026-07-15:
1. **Pre-start trace** — 98 frames, practice session, 22 vehicles, pre-start state
2. **Racing trace** — 3,000 frames, 26.6 seconds of active racing, 22 vehicles

### Per-Frame Call Counts

| Function | Pre-start | Racing | Notes |
|----------|-----------|--------|-------|
| SessionStateCheck | ~30 | ~30 | Main loop + IterateVehicles (×N) + TwoPathDispatch + WinMsgPump |
| GameStateSetViaVtable | ~201 | ~201 | VTable dispatch during render/timing — NOT "setting" game state |
| QPCWrapperModeDispatch | ~26 | ~26 | QueryPerformanceCounter timer queries |
| PhysicsStepFrame | 0 | ~9.7 | Variable sub-stepping: 3–36 per frame (avg 9.7) |
| VehiclePhysicsDispatcher | 0 | 2 | Two passes: 1st = 1 sub-step, 2nd = N sub-steps |
| AIMainUpdate | 0 | 0 or 22 | Fires in 28% of frames; always 22 calls (one per vehicle) |
| RaceTickMode2 | 2 | 2 | ConditionalStateUpdate + WeatherParticleUpdate |
| BufferReset | 2 | 2 | Called twice per frame (confirmed) |
| All other main loop functions | 1 | 1 | Exactly once per frame |

### Frame Timing

| Metric | Pre-start | Racing |
|--------|-----------|--------|
| Thread | Single (TID 32488) | Single (TID 32488) |
| Avg frame time | ~5ms | ~8.9ms |
| Effective FPS | ~200 | ~113 |
| Total function calls/frame | ~560 | ~1,800 |

### Physics Sub-Stepping (racing trace)

The physics engine uses a **fixed-timestep accumulator** pattern:

| Metric | Value |
|--------|-------|
| Physics timestep | ~1.16ms (~864 Hz) |
| Sub-steps per frame | 3–36 (variable, depends on frame delta) |
| Average sub-steps | 9.7 |
| Most common | 6, 7, 9, 10, 12 |
| Frames with physics | 2,372 / 3,001 (79%) |
| Frames without physics | 629 (21% — menu overlay, loading, transition) |
| Total PhysicsStepFrame calls | ~22,978 in 26.6s |

Physics dispatch structure per frame:
```
PhysicsDispatchChain
  → VehiclePhysicsDispatcher (1st pass: 1 sub-step)
  → VehiclePhysicsDispatcher (2nd pass: N sub-steps, accumulator catch-up)
    → PhysicsStepFrame × N
      → EngineStressSimulation
      → Anti-roll bar / suspension
      → Force accumulation per wheel
      → Rodrigues rotation matrix
      → Contact geometry + force resolution
```

### AI Update Pattern (racing trace)

AI does **not** run every frame. It runs at a lower tick rate (~31.7 Hz per vehicle):

| Metric | Value |
|--------|-------|
| Frames with AI | 835 / 3,001 (28%) |
| AI calls when active | 22 (one per vehicle, always) |
| Double-update frames | 8 (44 calls — rare, possibly catch-up) |
| Effective AI rate | ~31.7 Hz per vehicle |
| AI fires every | ~3.6 render frames |
| AI called FROM | PhysicsDispatchChain (not main loop directly) |

### Findings vs Static Analysis

| Prediction | Result |
|------------|--------|
| Single-threaded main loop | **CONFIRMED** — only thread 32488 across 3,098 frames |
| Call order matches game.cpp | **CONFIRMED** — exact match |
| BufferReset called twice | **CONFIRMED** |
| Physics empty at pre-start | **CONFIRMED** — PhysicsDispatchChain returns immediately |
| Physics active during racing | **CONFIRMED** — variable sub-stepping, fixed timestep ~864 Hz |
| Physics double-pass in race mode | **CONFIRMED** — two VehiclePhysicsDispatcher calls per frame |
| IterateVehicles loops per vehicle | **CONFIRMED** — 22 SessionStateCheck calls = 22 vehicles |
| ForceFeedbackInput from main loop | **CORRECTED** — called FROM CollisionGlobalBroadcast, not directly |
| AudioDSPStateUpdate standalone | **CORRECTED** — called FROM StewardUpdate, not directly |
| AI runs every frame | **CORRECTED** — runs ~28% of frames (~31.7 Hz), FROM PhysicsDispatchChain |

## Subsystem Execution Order

1. **State management** — check session state, handle pause
2. **Steward/rules** — race steward logic + audio DSP state
3. **Collision broadcast** — global collision + force feedback input
4. **Physics** — vehicle physics dispatch chain (empty when not racing)
5. **Vehicle iteration** — per-vehicle state checks (N × SessionStateCheck)
6. **Collision response** — post-physics collision resolution
7. **Race tick / session tick** — two-path dispatch (race logic or render)
8. **Camera** — camera director update
9. **Weather** — particle effects + race tick mode 2
10. **Frame timing** — delta time, VTable dispatch ×200, QPC ×26
11. **Render** — final render tick
12. **Message pump** — Windows message processing + Sleep

## Key Timing Variables

| Global | Type | Purpose |
|--------|------|---------|
| `DAT_008afe90` | double | Delta time per frame (raw) |
| `DAT_008afe98` | double | Delta time per frame (clamped to 0.5 max) |
| `DAT_008afea0` | double | Session elapsed time (accumulated) |
| `DAT_008afea8` | double | Total elapsed time (wall clock) |
| `DAT_008afe84` | int | Frame counter (increments each frame) |

Delta time computation (from `FUN_004fa7e0`):
- Raw delta from `FUN_00556730` (QueryPerformanceCounter wrapper)
- If not paused: `session_time += delta`, clamped to 0.5s max
- If paused: delta forced to 0.0

## Race Tick Path (FUN_004ba6c0 → FUN_004b9890)

When `*param_1 == 1` (race mode), the two-path dispatch calls:

1. `FUN_004b9870` — update race timing buffer
2. `FUN_004b9890` — **RaceTickAdvance**: the per-tick race logic dispatcher

RaceTickAdvance calls through `FUN_004b8ae0` (StateTriggerCheck), which dispatches:
- `FUN_0042c690` — physics chain (second pass in race mode)
- `FUN_004c8b70` — render tick (from race path)
- `FUN_004c6b60` — **SessionTickUpdate** (the deep session logic)

### SessionTickUpdate (FUN_004c6b60) calls:

| Function | Purpose |
|----------|---------|
| FUN_004bb8e0 | Vehicle setup/state |
| FUN_004d1180 | Steward dispatch |
| FUN_004bc9b0 | Pit lane logic |
| FUN_004ef7c0 | Telemetry recording |
| FUN_004e9600 | Suspension state |
| FUN_004f1c00 | Vehicle dynamics |
| FUN_004a5e60 | Session transition |
| FUN_004a5e80 | Session transition (alt) |
| FUN_0040d100 | GameStateBranchDispatch |
| FUN_00424b20 | AI logic |
| FUN_004efa40 | Race event processing |

## Physics Chain (FUN_0042c690) — Runtime Confirmed

The physics dispatch chain during active racing (runtime-confirmed):

```
FUN_0042c690 (PhysicsDispatchChain)
  → FUN_004e4930 (VehiclePhysicsDispatcher) — 1st pass, 1 sub-step
  → FUN_004e4930 (VehiclePhysicsDispatcher) — 2nd pass, N sub-steps (accumulator)
    → FUN_00441650 (VehiclePhysicsIntegrationStep) × N
      → FUN_00441600 (PhysicsStepFrame) × N
        → FUN_0043ef20 (EngineStressSimulation)
        → FUN_00438130 (Anti-roll bar / suspension)
        → FUN_00438690 (Force accumulation per wheel)
        → FUN_0056bde0 (Rodrigues rotation matrix)
        → FUN_005692a0 (Contact geometry transform)
        → FUN_00569410 (Contact force resolution)
        → FUN_00441450 (Per-wheel integration finalize)
  → FUN_00424e70 (AIMainUpdate) × 22 — fires ~28% of frames, from within physics chain
```

**Two-pass physics** confirmed at runtime:
- 1st VehiclePhysicsDispatcher: always 1 sub-step (initialization/prediction pass)
- 2nd VehiclePhysicsDispatcher: N sub-steps where N = accumulated time / timestep (3–36, avg 9.7)
- Fixed timestep: ~1.16ms (~864 Hz)

**State-dependent behavior:**
- Pre-start: PhysicsDispatchChain returns immediately (no sub-calls)
- Racing: Full physics pipeline with variable sub-stepping + AI updates

## Thread Model (runtime-confirmed)

**Single-threaded.** All 98 frames ran on thread 32488. No secondary threads observed in trace.

Background threads (not captured by function hooks):
- Audio mixing thread (Miles Sound System — runs via DirectSound callbacks)
- Network I/O thread (if multiplayer)
- Video decode thread (Bink — only during cutscenes)

## Answered Questions (from racing trace)

1. **Physics tick rate**: ~864 Hz fixed timestep (1.16ms). Variable 3–36 sub-steps per frame via accumulator pattern. **ANSWERED.**
2. **AI update frequency**: Does NOT fire every frame. Fires in 28% of frames (~31.7 Hz per vehicle), always processing all 22 vehicles at once. Called FROM PhysicsDispatchChain. **ANSWERED.**
3. **Frame pacing**: WinMsgPump calls Sleep for frame pacing. Racing at ~113 FPS vs ~200 FPS at pre-start — physics load is primary cost. **ANSWERED.**
4. **Physics double-pass**: YES — two VehiclePhysicsDispatcher calls per frame. 1st pass does 1 sub-step, 2nd pass does N sub-steps (accumulator catch-up). **ANSWERED.**

## Remaining Open Questions

1. **AI tick rate source**: What determines the ~31.7 Hz rate? Fixed timer, or tied to physics accumulator overflow?
2. **629 zero-physics frames**: What triggers physics skip? Menu overlay? Loading? Or frame-rate limiter?
3. **Double AI frames (8/3001)**: What triggers the rare 44-call frames? Catch-up mechanism?
4. **Other game states**: Qualifying, formation lap, pit stop — do subsystem rates differ?
