# Chain: MainGameTickUpdate — Per-frame update loop for all vehicles and systems

Seed: FUN_0042c690  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 14

---

## Overview

Central per-frame game tick — runs every ~10 game ticks (with periodic AI/repair/physics updates at 50/400 tick intervals). Gated by ScoringGate (DAT_008ab6e4) — when == 2, tick is skipped entirely (multiplayer optimization). Computes target tick count (capped at 0xC9 = 201 ticks/frame to prevent spiral of death). Iterates all vehicles, updating AI state, physics (brake/tire/suspension via FUN_004ee2d0), fuel consumption, wear, and steering. If player AIState == 0, dispatches player input. If DAT_007cbf24 flag set, runs additional processing via FUN_00451720.

## Call Tree

```
FUN_0042c690 — MainGameTickUpdate  [trigger: per-frame, every ~10 ticks, gated by ScoringGate]
  +-- FUN_00424e70 — AIMainUpdate  [race phase state machine per vehicle, 15 callees]
  |     +-- [subtree: AI state machine with 15 leaves — docs/02]
  +-- FUN_00410980 — LoopWithConditionalSkip  [iteration wrapper, 3 callees]
  |     +-- [subtree: 3 leaf callees — docs/20]
  +-- FUN_004eb430 — ParticleEffectUpdateDispatch  [updates particle effects, 13 callees]
  |     +-- [subtree: 13 leaf/docs callees — docs/19]
  +-- FUN_004ee2d0 — VehicleDynamicsUpdate  [brake/tire/suspension physics, 13 callees]
  |     +-- [subtree: 13 physics callees — docs/18]
  +-- FUN_004ed960 — FuelConsumptionAndWear  [fuel burn + engine wear, 3 callees]
  |     +-- [subtree: 3 callees — docs/03]
  +-- FUN_0042caa0 — AILateralForceComputation  [lateral force for AI — leaf, docs/02]
  +-- FUN_004f1c40 — VehicleYawRotationRecovery  [yaw correction controller, 8 callees]
  |     +-- [subtree: 8 dynamics callees — docs/18]
  +-- FUN_004ed810 — WheelTireForceUpdate  [4-wheel loop — leaf, docs/06]
  +-- FUN_004bccc0 — PlayerInput  [undocumented]
  +-- FUN_004d5960 — DebugLogInit  [debug logging setup, 2 callees]
  +-- FUN_004d59b0 — SetupBitfieldEncoding  [bitfield encoding, 1 callee]
  +-- FUN_004e4930 — VehiclePhysicsModeDispatcher  [mode dispatch, 5 callees]
  +-- FUN_00451720 — DriverInputController  [player input handler — leaf, docs/10]
  +-- FUN_004109d0 — PerVehicleCameraUpdate  [camera update per vehicle, 4 callees]
```

## Step-by-Step Trace

### Level 0: FUN_0042c690 — MainGameTickUpdate

**Trigger:** Per-frame from main game loop; runs every ~10 game ticks (50/400 tick intervals for specific subsystems)
**Called by:** FUN_004b8ae0 (from callers.json — state trigger check in load/init)
**Purpose:** Central per-tick update driving AI, physics, particles, fuel, wear, and player input for all vehicles.

**Key actions:**
1. **Gate:** If ScoringGate (DAT_008ab6e4) == 2: skip entirely (multiplayer optimization)
2. Compute target tick time — caps at 0xC9 (201) ticks maximum per frame to prevent spiral-of-death
3. Loop every 10 ticks: runs AI per vehicle (FUN_00424e70), repair/state, physics (FUN_004ee2d0)
4. Every 50 ticks: vehicle tick + safety checks (FUN_004ed810, FUN_004e4930)
5. Every 400 ticks: AI update on human vehicles (FUN_00424e70 with longer interval)
6. If player AIState == 0: dispatches player input (FUN_004bccc0)
7. If DAT_007cbf24 != 0: calls FUN_00451720 (driver input controller)
8. Updates particle effects (FUN_004eb430), fuel/wear (FUN_004ed960)
9. Per-vehicle camera update (FUN_004109d0)

**Data passed to callees:** vehicle array pointer (DAT_007c54f0), tick count, per-vehicle struct pointers (stride ~0x4900)

### Level 1: Key callees (10+ callees — document 5 most complex)

**FUN_00424e70 — AIMainUpdate (15 callees)**
**Called by:** FUN_0042c690 (every 10 ticks for AI vehicles, every 400 ticks for human)
**Purpose:** Race phase state machine for AI vehicles — manages AI behavior per phase (practice/quali/race).
**Subtree:** 15 children — too many to detail. See docs/02-ai-system.md for full tree.
**Key subsystems:** AI strategy selection, path following, opponent detection, steering computation.

**FUN_004ee2d0 — VehicleDynamicsUpdate (13 callees)**
**Called by:** FUN_0042c690 (every physics tick = every 10 game ticks)
**Purpose:** Full vehicle dynamics update — brake forces, tire slip curves, suspension forces.
**Cross-system handoff:** docs/18-physics-dynamics.md
**Key subsystems:** Brake model (threshold-based), brush tire model, suspension spring/damper integration.

**FUN_004eb430 — ParticleEffectUpdateDispatch (13 callees)**
**Called by:** FUN_0042c690 (per-frame)
**Purpose:** Updates all active particle effects — exhaust smoke, tire debris, brake dust.
**Cross-system handoff:** docs/19-renderer.md
**Leaves:** 13 leaf particles/effect update functions.

**FUN_004f1c40 — VehicleYawRotationRecovery (8 callees)**
**Called by:** FUN_0042c690 (per physics tick)
**Purpose:** Yaw/rotation controller that stabilizes vehicle rotation — applies corrective torque based on angular velocity error.
**Cross-system handoff:** docs/18-physics-dynamics.md

**FUN_004e4930 — VehiclePhysicsModeDispatcher (5 callees)**
**Called by:** FUN_0042c690 (every 50 ticks)
**Purpose:** Dispatches per-vehicle physics update based on current mode (race/pit/out).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Gate | ScoringGate (DAT_008ab6e4) | == 2 check | skip/allowed |
| Tick cap | current tick count | min(ticks, 0xC9) | max 201 ticks |
| Loop 10 | vehicle count | iterate | AI + physics per vehicle |
| AI Update | vehicle struct | state machine | AI behavior for tick |
| Physics | vehicle struct | brake/tire/suspension | forces applied |
| Fuel/Wear | vehicle struct | fuel consumption | remaining fuel, wear |
| Particles | scene state | update dispatch | particle positions/effects |
| Camera | vehicle struct | view target | camera follow position |

## Globals Read in This Chain

| Global | Name | Used by | Purpose |
|--------|------|---------|---------|
| DAT_008ab6e4 | ScoringGate | FUN_0042c690 | Skip gate (== 2 = skip) |
| DAT_007c54f0 | VehiclePtrArray | All callees | Vehicle iteration |
| DAT_007cbf24 | Unknown flag | FUN_0042c690 | Gates FUN_00451720 |
| DAT_008acf9c | TotalRaceLaps | FUN_00424e70 | AI race logic |
| DAT_007c56a4 | SessionType | FUN_00424e70 | AI behavior |
| DAT_007c56a8 | RacePhase | FUN_00424e70 | AI phase selection |
| DAT_007cea5c | EngineWearMode | FUN_004ed960 | Wear mode |

## Notes

- FUN_004bccc0 (PlayerInput) is NOT FOUND in functions.json — undocumented or Ghidra artifact
- The 10-tick interval means physics runs at effectively 6 Hz minimum (60 FPS / 10), but the tick cap prevents spiral-of-death when frame rate drops
- FUN_004ee2d0 (VehicleDynamicsUpdate, 13 callees) is the deepest subtree — documented separately in docs/18 as the primary vehicle physics entry point
- The AI update frequency (400 ticks = ~6.7 seconds at 60 FPS) for human vehicles means AI opponents use cheaper logic for the player's car

---
