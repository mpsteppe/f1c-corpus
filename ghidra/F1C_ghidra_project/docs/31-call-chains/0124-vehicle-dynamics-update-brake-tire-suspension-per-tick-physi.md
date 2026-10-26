# Chain: Vehicle Dynamics Update (Brake/Tire/Suspension) — Per-Tick Physics Step

Seed: FUN_004ee2d0  |  System: docs/18-physics-dynamics.md  |  Depth: 3  |  Functions: 20

---

## Overview

Large (3735-byte) brake/tire/suspension physics integration function. Called per vehicle per physics tick from the main game tick update (FUN_0042c690). Computes brake torque from pressure thresholds, tire slip forces via brush model, suspension spring/damper forces, and collision effects. Writes results into vehicle struct fields and triggers particle effects.

## Call Tree

```
FUN_004ee2d0 — Vehicle Dynamics Update (Brake/Tire/Suspension)  [trigger: per-vehicle per-tick by FUN_0042c690]
  +-- FUN_004e9630 — PositionChangeMonitor  [tracks position delta for collision detection]
  |     +-- FUN_004e8010 — Tire Brush Model Force Solver  [computes brush-model forces]
  +-- FUN_004fd7e0 — 1D Table Lookup with Lerp  [lookup brake curve table]
  |     +-- FUN_004e8b80 — AerodynamicForceCalc  [aero force component]
  +-- FUN_004472b0 — Tire Slip/Force Calculation  [computes lateral/longitudinal slip forces]
  |     +-- FUN_004e8010 — Tire Brush Model Force Solver
  |     +-- FUN_004e8b80 — AerodynamicForceCalc
  |     +-- FUN_004e8ce0 — TireForceSolver
  |     +-- FUN_004e3d00 — Wheel Spring/Damper Force and Steering
  +-- FUN_004e16f0 — Particle Effect World Transform  [transform for particle spawn]
  |     +-- FUN_004e1970 — Effect Data Table Initialization
  +-- FUN_004ed750 — 3D Cross Product  [vector math utility]
  +-- FUN_004ce380 — Float Comparison with Constants Table  [threshold checks]
  +-- FUN_004ce3e0 — CollisionEffectDispatch  [triggers collision sounds/particles]
  |     +-- FUN_004e8010 — Tire Brush Model Force Solver
  |     +-- FUN_004e8b80 — AerodynamicForceCalc
  |     +-- FUN_004ce930 — ParticleCollisionEffect (DualType)
  +-- FUN_004ce8f0 — Float Triple Zero Check  [checks if all 3 components are ~0]
  +-- FUN_004ce930 — ParticleCollisionEffect (DualType)  [spawns collision particles]
  |     +-- FUN_004e8010 — Tire Brush Model Force Solver
  +-- FUN_004ee230 — ThrottleBrakeOverride  [dynamic force override for throttle/brake]
  +-- FUN_0044c4c0 — 3D to Screen Projection  [projects world pos to screen]
  |     +-- FUN_004e8b80 — AerodynamicForceCalc
  |     +-- FUN_0044c620 — Collision State Init
  +-- FUN_004b9ce0 — Delegation  [pass-through to replay time getter]
  |     +-- FUN_004e1970 — Effect Data Table Initialization
  +-- FUN_004cce90 — scoring/standings access  [reads race position data]
```

## Key Actions

1. Reads brake pressure input, applies threshold checks (DAT_005AD220, DAT_005AD224, DAT_005AD228)
2. Computes brake torque via 1D table lookup (FUN_004fd7e0) with linear interpolation
3. Computes tire slip forces via brush model (FUN_004e8010, FUN_004e8b80, FUN_004e8ce0)
4. Computes suspension spring/damper per wheel (FUN_004e3d00)
5. Compares track grip (DAT_008AFEEC vs DAT_008AFEE8) for grip-dependent behavior
6. Triggers collision effects (particles, sounds) via FUN_004ce3e0
7. Projects 3D world position to screen via FUN_0044c4c0

## Globals Read

- `DAT_005AD220` — BrakeForceThreshold
- `DAT_005AD224` — BrakePressureThreshold
- `DAT_005AD228` — BrakeForceThreshold1
- `DAT_008AFEEC` — TrackGripComparison
- `DAT_005ACEB8` — SuspensionOffsetConstant

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Brake pedal input | Threshold compare + table lookup | Brake torque |
| Tire slip ratio | Brush model solver | Lateral/longitudinal forces |
| Suspension deflection | Spring/damper calc | Wheel forces |
| Track grip comparison | Gating branch | Grip-adjusted forces |

## Notes

- 13 callees, 6 with sub-callees (depth 2-3)
- Heavy reuse of FUN_004e8010 (brush model) and FUN_004e8b80 (aero force) across multiple branches
- Functions.json categorizes this as game_logic: False despite reading vehicle struct offsets — it's pure physics
- Configurable via brake thresholds, grip constants, scale factors (DAT_ globals)

---
