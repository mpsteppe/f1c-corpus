# Chain: SuspensionAndWheelPhysics — Per-frame vehicle suspension, tire force, and chassis integration

Seed: FUN_004e5f60  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 28

---

## Overview

Called per-frame from the main game tick. Integrates all 4-corner suspension forces, tire brush model forces (longitudinal/lateral/aligning), chassis weight transfer, steering geometry, aero downforce, and engine wear into the vehicle rigid body. Reads setup parameters from param_2/param_3 (vehicle setup structs), writes forces and positions to param_1 (vehicle state struct). Uses fuel multiplier (DAT_007d0b64) for fuel mass computation. Writes final body position/rotation at +0x1c/0x20/0x24.

## Call Tree

```
FUN_004e5f60 — SuspensionAndWheelPhysics  [trigger: per-frame from main game tick]
  +-- FUN_004d7880 — TireBrandLookup  [returns tire brand index]
  +-- FUN_004f1a60 — LoopWithConditionalSubCall  [loop dispatch — leaf]
  +-- FUN_004d7570 — TireDataLookup  [returns tire parameter data]
  +-- FUN_004d6ae0 — VehicleSuspensionForceHelper  [suspension force helper — leaf]
  +-- FUN_004e2540 — WheelSuspensionTireStateInit  [per-corner state init]
  |     +-- FUN_004e09e0 — TireModelInitSub  [per-corner tire model sub-init]
  +-- FUN_004a5330 — PitPartStateCopy  [cross-system: docs/07 →]
  |     +-- FUN_004d7880 — TireBrandLookup
  |     +-- FUN_004d7570 — TireDataLookup
  |     +-- FUN_004a57f0 — PitPartInit [docs/07]
  |     +-- FUN_004a5820 — PitPartArrayInit [docs/07]
  |     +-- FUN_004a5890 — PitPartCommit [docs/07]
  |     +-- (2 more pit part callees)
  +-- FUN_004f6850 — RandomOffsetCalculator  [leaf]
  +-- FUN_004f6880 — BiasValueComputation  [leaf]
  +-- FUN_004f68b0 — TireForceTorqueComputation  [leaf]
  +-- FUN_004f6950 — QuadraticForceModel  [leaf]
  +-- FUN_004f69e0 — LinearVehicleParameterEvaluation  [leaf]
  +-- FUN_004f6a50 — QuadraticForceTorqueCurveEvaluation  [leaf]
  +-- FUN_004f3190 — PolynomialEvaluation  [returns 2 outputs — leaf]
  +-- FUN_0042ed00 — SessionStateIndexedLookup  [reads session state — leaf]
  +-- FUN_0054b420 — ThreeFieldCopy  [leaf]
  +-- FUN_004dd7c0 — BestFitSelection  [spatial selection]
  |     +-- FUN_004dd4e0 — SpatialQuery [docs/20]
  |     +-- FUN_0054c210 — ActiveSourceCount [docs/19]
  |     +-- FUN_0054c230 — SourceIteration [docs/19]
  |     +-- FUN_0054e100 — ResourceGet [docs/19]
  |     +-- FUN_0054e120 — ResourceGet2 [docs/19]
  +-- FUN_004e9bd0 — 3x3MatrixTransformWithTranslation  [leaf]
  +-- FUN_004ee150 — EngineWearFailureSimulation  [docs/10, also called elsewhere]
  |     +-- FUN_0053ac70 — WearCheckSub [docs/03]
  |     +-- FUN_004b3ce0 — FailureRollSub [docs/03]
  +-- FUN_0059d9d7 — CallWrapper  [leaf — docs/20]
  +-- FUN_0054f830 — VertexParticleBufferAllocator  [renderer — docs/19]
  |     +-- FUN_0054fa50 — AllocSub [docs/19]
  |     +-- FUN_00587bcf — Free [docs/09]
  |     +-- FUN_0054eb20 — BufferRealloc [docs/19]
  |     +-- (1 more buffer callee)
  +-- FUN_0059da3a — CallWrapper  [leaf — docs/20]
  +-- _rand — CRT random
```

14 additional leaf callees omitted.

## Step-by-Step Trace

### Level 0: FUN_004e5f60 — SuspensionAndWheelPhysics

**Trigger:** Per-frame from main game tick (FUN_0042c690)
**Called by:** Main tick dispatcher
**Purpose:** Main suspension/wheel physics integration — 4 corners, tire forces, chassis forces.

**Key actions:**
1. Reads 4 suspension corner states from param_1+0x8b8 (stride 0x4a words, 0x128 bytes)
2. Copies to local work buffer, applies velocity/steering corrections from param_3+0x54a..0x564
3. Applies PID-style correction for steering/lean targets
4. Computes 4-corner chassis load distribution (matrix at +0x3674, stride 0x3e)
5. Computes tire forces: slip angles, friction circle, longitudinal/lateral/aligning per corner
6. Reads brake bias from param_2+0xcc4, computes per-corner brake force
7. Computes fuel mass from DAT_007d0b64 (FuelMult) × param_3+0x674 × DAT_007d01e8
8. Writes steering angle, caster/camber angles, gear ratio, final drive
9. Computes differential/anti-roll from param_2+0xcf8/0xd38
10. Reads spring rates from param_3+0x684/0x1374
11. Front/rear wing downforce at +0x3a30/+0x3a44
12. Computes pushrod/rocker geometry for 13 hardpoints
13. Calls FUN_004ee150 for engine wear simulation
14. Writes body position at param_1+0x1c/0x20/0x24

**Data passed to callees:** param_1 (vehicle state), param_2 (setup/config), param_3 (physics state)

### Level 1: FUN_004a5330 — PitPartStateCopy

**Trigger:** Called from SuspensionAndWheelPhysics fuel system section
**Called by:** FUN_004e5f60
**Purpose:** Copies pit part states (tire compounds, brake discs, suspension replacements) between vehicle setup and active state.

**Key actions:**
1. Calls FUN_004d7880 (tire brand lookup)
2. Calls FUN_004d7570 (tire data lookup)
3. Iterates pit part array via FUN_004a57f0/FUN_004a5820/FUN_004a5890
4. Copies selected part state to vehicle's active configuration

**Data passed down:** Vehicle pointer, pit part selection indices

### Level 1: FUN_004dd7c0 — BestFitSelection

**Trigger:** Called from SuspensionAndWheelPhysics during spatial/best-fit phase
**Called by:** FUN_004e5f60
**Purpose:** Spatial selection or scoring algorithm to find best-fit entity.

**Key actions:**
1. Calls FUN_004dd4e0 (spatial query)
2. Iterates active sources via FUN_0054c210 (count) and FUN_0054c230 (iterate)
3. Retrieves resources via FUN_0054e100/FUN_0054e120

### Level 1: FUN_004ee150 — EngineWearFailureSimulation

**Trigger:** Called from SuspensionAndWheelPhysics final integration section
**Called by:** FUN_004e5f60 (and elsewhere — brake/fade model at 0x00430a50)
**Purpose:** Simulates engine component wear and random failures.

**Key actions:**
1. Calls FUN_0053ac70 (wear probability check)
2. Calls FUN_004b3ce0 (failure mode roll)
3. Updates engine health state in vehicle struct

### Level 1: FUN_004e2540 — WheelSuspensionTireStateInit

**Trigger:** Called from SuspensionAndWheelPhysics per-corner
**Called by:** FUN_004e5f60
**Purpose:** Initializes per-wheel suspension and tire state for one corner.

**Key actions:**
1. Sets suspension state fields from caller-supplied params
2. Calls FUN_004e09e0 for tire model sub-init

### Level 1: FUN_0054f830 — VertexParticleBufferAllocator

**Trigger:** Called from SuspensionAndWheelPhysics for particle/visual output
**Called by:** FUN_004e5f60
**Purpose:** Allocates vertex/particle buffer for tire spray/particle effects.

**Key actions:**
1. Allocates buffer via FUN_0054fa50
2. Reallocates via FUN_0054eb20 if needed
3. Frees old buffer via FUN_00587bcf

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004e5f60 | param_1+0x8b8 (4 corner states) | Copy to work buffer, apply corrections | Work buffer |
| FUN_004e5f60 | param_2+0xbf0/0xbf8/0xc04 (weight transfer) | Compute 4-corner load distribution | Load at +0x3674 |
| FUN_004e5f60 | Tire model params (param_2+0x1b8/param_3+0x1400) | Slip angle + friction circle | Forces at +0x35ac |
| FUN_004e5f60 | param_2+0xcc4 (brake bias) | Per-corner brake force | +0x3784/+0x3594 |
| FUN_004e5f60 | DAT_007d0b64 × param_3+0x674 × DAT_007d01e8 | Fuel mass computation | Fuel mass |
| FUN_004e5f60 | param_2+0x1440 (final drive) | Primary inertia + gear ratio | +0x3960/+0x1038 |
| FUN_004e5f60 | param_2+0xcf8/0xd38 (diff/anti-roll) | Heave/roll stiffness | +0x3974 |
| FUN_004e5f60 | param_2+0x1338/0x1378 (wing settings) | Front/rear downforce | +0x3a30/+0x3a44 |
| FUN_004ee150 | Engine wear state | Wear probability + failure roll | Engine health updates |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0b64 | FuelMult | (read by FUN_004e5f60) | Fuel consumption multiplier |

## Notes

- FUN_004e5f60 has 21 callees — the 7 most complex subtrees documented above, 14 leaf callees omitted
- FUN_004a5330 (PitPartStateCopy) is a cross-system call into docs/07-pit-system.md
- FUN_0054f830 (VertexParticleBufferAllocator) is a cross-system call into docs/19-renderer.md (particle effects)
- FUN_004ee150 (EngineWearFailureSimulation) also called by brake temperature model FUN_00430a50
- 8 random values generated via FUN_0042ed00 for SCR/traction control noise
- Final body position written at param_1+0x1c/0x20/0x24

---
