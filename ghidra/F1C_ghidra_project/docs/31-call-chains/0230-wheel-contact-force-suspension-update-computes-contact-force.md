# Chain: Wheel Contact Force & Suspension Update — Computes contact forces for 2 axles, updates suspension

Seed: FUN_004e6d93  |  System: docs/18-physics-dynamics.md  |  Depth: 6  |  Functions: ~25

---

## Overview

FUN_004e6d93 computes wheel contact forces for front and rear axles, blends spring/damper forces from hub velocities, and accumulates per-wheel contact data into chassis-relative force/torque. Called each physics tick from the main vehicle dynamics loop. The chain includes force integration helpers (FUN_004f3190, FUN_004f68b0-6a50), engine wear simulation (FUN_004ee150), vertex buffer allocation (FUN_0054f830), and an unidentified best-fit selector (FUN_004dd7c0).

## Call Tree

```
FUN_004e6d93 — Wheel Contact Force & Suspension Update  [trigger: per-vehicle physics tick]
  +-- FUN_004f3190 — Polynomial Evaluator  [leaf]
  +-- FUN_004f68b0 — Tire Force/Torque Computation  [leaf]
  +-- FUN_004f6950 — QuadraticForceModel (suspension/tire)  [leaf]
  +-- FUN_004f69e0 — Linear Vehicle Parameter Evaluation  [leaf]
  +-- FUN_004f6a50 — Quadratic Force/Torque Curve Evaluation  [leaf]
  +-- FUN_0054b420 — Three-Field Copy (wheel contact reset)  [leaf]
  +-- FUN_004e9bd0 — 3x3 Matrix Transform with Translation  [leaf]
  +-- FUN_004ee150 — Engine Wear/Failure Simulation  [sub: 2]
  +-- FUN_0054f830 — Vertex/Particle Buffer Allocator  [sub: 4]
  |     +-- FUN_0054fa50 — Linked Node Destruction  [sub: 1]
  |     +-- FUN_00587bcf — Free Wrapper  [sub: 1]
  |     +-- FUN_0054eb20 — [PARTIAL] Unknown  [leaf]
  |     +-- FUN_0054eaf0 — Short Computation Struct Zero-Init  [leaf]
  +-- FUN_004dd7c0 — Best-Fit Selection  [sub: 5]
  |     +-- FUN_004dd4e0 — [PARTIAL] Unknown  [leaf]
  |     +-- FUN_0054c210 — Scene Graph Child Count  [leaf]
  |     +-- FUN_0054c230 — Linked List Indexed Accessor  [leaf]
  |     +-- FUN_0054e100 — PackedArrayTotalSize  [leaf]
  |     +-- FUN_0054e120 — PackedArrayIndexLookup  [leaf]
  +-- FUN_0059da3a — Call Wrapper  [sub: 1]
```

## Step-by-Step Trace

### Level 0: FUN_004e6d93 — Wheel Contact Force & Suspension Update

**Called by:** FUN_0059d9d7 (Wheel Contact Force wrapper), FUN_00464a10 (Post-loop processing)
**Purpose:** Computes contact forces for 2 axles (front/rear wheels), updates suspension positions, accumulates per-wheel contact data into chassis-relative force/torque.

**Key actions:**
1. Processes 2 wheel pairs: front (+0x13d0/0x14d8) and rear (+0x15e0/0x16e8)
2. Blends spring/damper forces from wheel hub velocities
3. Computes inverse suspension length at offset 0x3618/0x3710/0x3808/0x3900
4. Accumulates 4 wheel force contributions into chassis force (+0x3be8) and torque (+0x3bf0)
5. Iterates 12 contact patches (indices 0-11): sets contact point positions, checks wheel contact flags
6. For indices 8-11 (steering wheels): computes steer-angle-dependent contact offset
7. Calls force integration helpers (FUN_004f3190, FUN_004f68b0-6a50)
8. Resets wheel contact on lift-off (FUN_0054b420)
9. Accumulates chassis force (FUN_004e9bd0)
10. Updates engine wear (FUN_004ee150)
11. Exports contact positions (FUN_0054f830, 13 points)

**Data passed to callees:** Wheel struct pointers, chassis force/torque accumulators, suspension geometry

### Level 1: FUN_004f3190 — Polynomial Evaluator

**Called by:** FUN_004e6d93 (force integration)
**Purpose:** Evaluates 2nd or 3rd order polynomial at param_2, returning two outputs.

### Level 1: FUN_004ee150 — Engine Wear/Failure Simulation

**Called by:** FUN_004e6d93 (after force computation)
**Purpose:** Simulates engine wear and potential failure.

**Key actions:**
1. Updates wear accumulators
2. Checks failure thresholds
3. Sets DNF state on catastrophic failure

### Level 1: FUN_0054f830 — Vertex/Particle Buffer Allocator

**Called by:** FUN_004e6d93 (contact position export)
**Purpose:** Allocates vertex/particle buffer for contact visualization.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004e6d93 | Wheel hub velocities, suspension lengths | Spring/damper force blend | Chassis force (+0x3be8) + torque (+0x3bf0) |

## Globals Written in This Chain

None documented (operates on vehicle struct via param_1).

## Notes

- This is one of the most complex physics functions with 11 callees handling force models, wear, buffer allocation.
- Cross-system handoff: FUN_004ee150 (Engine Wear/Failure Simulation) goes to docs/10-vehicle-physics (docs/03-engine-wear-damage.md).
- The struct offsets used (0x13d0, 0x14d8, 0x15e0, 0x16e8, 0x3618, 0x3710, 0x3808, 0x3900) define the per-vehicle physics instance layout (docs/13-struct-offsets.md).

---
