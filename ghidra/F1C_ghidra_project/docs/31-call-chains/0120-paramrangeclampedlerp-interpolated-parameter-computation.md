# Chain: ParamRangeClampedLerp — Interpolated Parameter Computation

Seed: 0x0049f530  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 5

---

## Overview

ParamRangeClampedLerp computes a clamped interpolated parameter with global scaling. Called by 0x0049cfc0 (unknown collision/physics dispatcher), it selects a parameter range based on case (0-4), reads base values from globals, applies linear transform scaling, clamps the result, and calls three posting functions to propagate the interpolated value. Used for physics parameter tuning at runtime.

## Call Tree

```
FUN_0049f530 — ParamRangeClampedLerp  [trigger: physics parameter interpolation request]
  +-- FUN_0049b8d0 — Speed Multiplier  [parameter lookup — leaf]
  +-- FUN_00447bb0 — TireFrictionCurveEval  [parameter lookup]
  |     +-- FUN_00447ab0 — TrigTableLookup  [interpolation factor from adjacent curve — leaf]
  +-- FUN_0049ed00 — Field Setter + Trigger
  |     +-- FUN_0049ed30 — UI Sparkle Effect
  +-- FUN_0049ed10 — Conditional Call (if *param_1 non-zero)
  |     +-- FUN_00553700 — [data at 0x00553700 — leaf]
  +-- FUN_0049ed20 — Conditional Audio Call
  |     +-- FUN_00553700 — [data at 0x00553700 — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0049f530 — ParamRangeClampedLerp

**Trigger:** Called from collision/physics dispatcher (0x0049cfc0) during physics parameter update
**Called by:** 0x0049cfc0 (unknown — ParamRangeClampedLerp dispatcher)
**Purpose:** Computes clamped interpolated parameter with global scaling.

**Key actions:**
1. Bounds check: param_1 ∈ [0, 4] and param_3 != 0.0
2. Switch on param_1 (cases 0-4):
   - case 0: min=0, max=10000, fVar3 from FUN_0049b8d0() — speed multiplier
   - case 1: min=120, max=280, fVar3 = DAT_007c91b4 - DAT_005acafc
   - case 2: min=120, max=280, fVar3 = DAT_007c9174 - DAT_005acafc
   - case 3: min=-3, max=100, fVar3 = DAT_007c919c
   - case 4: min=0, max=12, fVar3 from FUN_00447bb0() — tire friction curve eval
3. Additional scaling:
   - case 1-2: fVar3 = (fVar3 - DAT_0059eac0) * DAT_0059eab8 - DAT_0059eab0
   - case 3-4: fVar3 = fVar3 * DAT_005acb10
4. Clamps fVar3 between min and max
5. Stores range (max-min) at param_2+0x20
6. Calls FUN_0049ed00, FUN_0049ed10, FUN_0049ed20 with interpolated values

**Data passed to callees:** case index, parameter range, interpolated value

### Level 1: FUN_0049b8d0 — Speed Multiplier

**Trigger:** Called for case 0 parameter lookup
**Purpose:** Returns speed multiplier scalar for interpolation range

### Level 1: FUN_00447bb0 — TireFrictionCurveEval

**Trigger:** Called for case 4 parameter lookup
**Purpose:** Evaluates tire friction curve to get parameter base value
**Key actions:** Delegates to FUN_00447ab0 (trig table lookup) for interpolation factor from adjacent curve entry

### Level 1: FUN_0049ed00 — Field Setter + Trigger

**Trigger:** Called with interpolated value to set output field
**Purpose:** Sets field at param_2 offset and triggers UI sparkle effect (FUN_0049ed30)

### Level 1: FUN_0049ed10 / FUN_0049ed20 — Conditional Call (Audio)

**Trigger:** Called to post-process interpolated value
**Purpose:** Conditional call — if *param_1 non-zero, calls FUN_00553700 (audio/system callback)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Case dispatch | param_1 (0-4) | switch + global reads | base value fVar3 |
| Linear transform | fVar3 | scale by global coefficients | transformed value |
| Clamp | transformed value | clamp to [min, max] | final parameter |
| Post | final parameter | three posting functions | output fields + side effects |

## Globals Written in This Chain

- `DAT_007c91b4` — parameter base (case 1, read)
- `DAT_007c9174` — parameter base (case 2, read)
- `DAT_007c919c` — parameter base (case 3, read)
- `DAT_005acafc` — shared offset subtractor (cases 1,2, read)
- `DAT_0059eac0`, `DAT_0059eab8`, `DAT_0059eab0` — linear transform coefficients (read)
- `DAT_005acb10` — multiplier (cases 3,4, read)

## Notes

- All globals are readable — this is a `configurable` moddability function
- Cases 1-2 share the same min/max range (120-280) but different base value sources
- FUN_00553700 called from both FUN_0049ed10 and FUN_0049ed20 — shared audio/system callback
- FUN_0049ed30 (UI Sparkle Effect) is cross-system handoff to renderer/UI

---
