# Chain: Suspension Force Computation — Vehicle Suspension Force Application

Seed: FUN_00447780  |  System: docs/18-physics-dynamics.md  |  Depth: 2  |  Functions: 7 callees

---

## Overview

FUN_00447780 computes and applies suspension forces for a vehicle. Called by FUN_004ef5a0 (vehicle unload/reload, docs/06-session-race-logic.md). Processes double-precision suspension data: copies 6 double values per entry from param_2 into array at offset 0x15b0 (stride 0x244). Mode determined by param_1+0x1e14: 0 (front+rear average), 1 (all 4 wheels), 2 (rear only). Computes force via dot product of suspension geometry at offsets 0x2c/0x44/0x5c, scales by 1/corner load (offset 0x2a per wheel, stride 0x464), clamps with min(0x1e430)/max(0x1ec70), iterates wheels to find max brake torque, and applies via FUN_00447e00 and FUN_004471f0. Callees include position/lap state update (FUN_00447e00), suspension vibration (FUN_004471f0), generic math (FUN_00569280, FUN_005692a0), rotation matrix computation (FUN_0056bde0 — 3×3 from axis-angle via Rodrigues formula), inertia tensor transform (FUN_00569410), and physics object free (FUN_00441450).

## Call Tree

```
FUN_00447780 — Suspension Force Computation  [trigger: vehicle physics tick]
  +-- FUN_00447e00 — Position/Lap State Update  [applies force to wheel station]
  +-- FUN_004471f0 — Suspension Vibration  [vibration/damper computation]
  +-- FUN_00569280 — Copy 6 Dwords to Struct  [generic array copy]
  +-- FUN_0056bde0 — 3x3 Rotation Matrix (axis-angle)  [Rodrigues formula]
  +-- FUN_005692a0 — Quadric/Tensor Math  [double precision tensor ops]
  +-- FUN_00569410 — Inertia Tensor World-Space Transform  [inertia transform]
  +-- FUN_00441450 — Physics SubObject Free  [memory/state cleanup]
```

## Step-by-Step Trace

### Level 0: FUN_00447780 — Suspension Force Computation

**Trigger:** Vehicle physics tick, called by FUN_004ef5a0
**Called by:** FUN_004ef5a0 (vehicle unload/reload, docs/06-session-race-logic)
**Purpose:** Compute and apply suspension forces from geometry and corner loads

**Key actions:**
1. Copies 6 double values from param_2 to array at +0x15b0 (stride 0x244 per entry)
2. Reads mode at param_1+0x1e14: 0=front+rear avg, 1=all wheels, 2=rear only
3. Computes force via dot product of suspension geometry (0x2c, 0x44, 0x5c)
4. Scales by 1/corner load (offset 0x2a per wheel, stride 0x464)
5. Clamps with min/max limits
6. Iterates all wheels to find max brake torque
7. Applies forces via FUN_00447e00 and FUN_004471f0

### Level 1: Key Callees

**FUN_0056bde0 — 3x3 Rotation Matrix (axis-angle)**
- Rodrigues' rotation formula: computes 3×3 rotation matrix from axis-angle input
- Pure double-precision math (docs/20-math-utilities.md)

**FUN_00447e00 — Position/Lap State Update**
- Applies computed suspension force to wheel station
- Updates position/lap state for the wheel

**FUN_004471f0 — Suspension Vibration**
- Computes vibration/damper effects for suspension
- Handles secondary damping response

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Data copy | param_2 | 6 doubles per entry | Array at +0x15b0 |
| Mode | +0x1e14 | Select 0/1/2 | Processing mode |
| Force | Geometry offsets | Dot product | Suspension force |
| Scale | Corner load | 1/corner_load | Normalized force |
| Clamp | Min/max limits | Clamp values | Bounded force |
| Apply | Force | FUN_00447e00/471f0 | Wheel force applied |

## Globals Written in This Chain

None — operates on struct data directly. No global writes.

## Notes

- Double-precision throughout (chassis/suspension uses high precision)
- Three processing modes: 0 averages front+rear, 1 processes all 4 individually, 2 processes rear only
- FUN_0056bde0 is a major math utility (docs/20-math-utilities.md) — also used in many other physics contexts
- Linked list at +0x3ec with stride 0x119 for 4-wheel processing

---
