# Chain: CameraTransformComputation — Camera Position/Shake Update

Seed: FUN_0040b710  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 8

---

## Overview

No tracked callers in call_graph (callers=0 — likely called via camera system vtable). Reads player vehicle position, applies random/angle transforms, camera shake, and rendering position updates. All callees are camera math utilities — transformation helpers and projection setup functions.

## Call Tree

```
FUN_0040b710 — CameraTransformComputation  [trigger: per-frame camera update, no tracked callers]
  +-- FUN_0040c780 — ScoringGateConditionCheck  [1 callee]
  |     +-- FUN_004b9cf0 — Float Value Return
  +-- FUN_00541cd0 — UtilityFunctionDualDispatch  [2 callees]
  |     +-- FUN_00541db0 — Handler Last 3 Args
  |     +-- FUN_00541d10 — Handler First 3 Args
  +-- FUN_004084a0 — ShortComputationFloatGlobalReader  [leaf]
  +-- FUN_00456060 — TwoFieldAccessor  [leaf — reads +0x38/+0x3c]
  +-- FUN_00456080 — ShortComputationTwoFieldAccessor  [leaf]
  +-- FUN_00542050 — CameraProjectionSetup  [leaf]
  +-- FUN_005423c0 — TwoFieldSetterPlusCall  [leaf]
  +-- FUN_00542680 — ConditionalFloatSetter  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0040b710 — CameraTransformComputation

**Trigger:** No tracked callers in call_graph — likely called from camera system per-frame update
**Called by:** Unknown (callers.json has no entries)
**Purpose:** Reads player vehicle position, computes camera transform with shake, random, and angle components.

**Key actions:**
1. Computes pointer into vehicle array at stride 0xd0 from param_1+0xc
2. Reads player vehicle position from DAT_007c54e0+0x58/0x5c/0x60
3. Calls FUN_0040c780 for scoring gate condition check
4. Calls FUN_004084a0 for random/angle components
5. Calls FUN_00541cd0 for dual dispatch transform
6. Calls rendering position updates (FUN_00456060, FUN_00456080)
7. Calls camera projection setup (FUN_00542050, FUN_005423c0, FUN_00542680)

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), _DAT_0059e65c (camera shake multiplier)

**Data passed to callees:** Vehicle array pointer (stride 0xd0), camera transform struct.

### Level 1: FUN_0040c780 — ScoringGateConditionCheck

**Trigger:** Called from camera transform for gate/trigger check
**Purpose:** Checks scoring gate condition for camera response.

### Level 2: FUN_004b9cf0 — Float Value Return

**Trigger:** Called from scoring gate check
**Purpose:** Returns float value from vehicle/scoring data.

### Level 1: FUN_00541cd0 — UtilityFunctionDualDispatch

**Trigger:** Called from camera transform
**Purpose:** Dispatches to two handler functions (first 3 args, last 3 args).

### Level 1: FUN_004084a0 — ShortComputationFloatGlobalReader

**Trigger:** Called from camera transform
**Purpose:** Short computation reading float globals for random/angle.

### Level 1: FUN_00456060/00456080 — TwoFieldAccessors

**Trigger:** Called from camera transform
**Purpose:** Read two struct fields at +0x38/+0x3c for rendering position.

### Level 1: FUN_00542050 — CameraProjectionSetup

**Trigger:** Called from camera transform
**Purpose:** Sets up camera projection matrix.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0040b710 | PlayerVehiclePtr, shake multiplier | Transform chain | Updated camera transform |
| FUN_0040c780 | Scoring state | Gate check | Condition result |
| FUN_00541cd0 | Arg groups | Dual dispatch | Two transform results |
| FUN_00542050 | Camera struct | Projection setup | Projection matrix |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007c54e0 | PlayerVehiclePtr | FUN_0040b710 (reader) | Pointer to player vehicle |
| _DAT_0059e65c | CameraShakeMultiplier | FUN_0040b710 (reader) | Shake intensity |

## Notes

- All callees are leaf functions or simple dispatchers — maximum depth is 2 (seed → callee → callee)
- 6 of 8 callees have call_count=0 (no further callees themselves)
- The two non-leaf callees (FUN_0040c780 with 1 callee, FUN_00541cd0 with 2 callees) are simple pass-throughs
- Despite low complexity, the function plays a critical role in camera positioning per frame

---
