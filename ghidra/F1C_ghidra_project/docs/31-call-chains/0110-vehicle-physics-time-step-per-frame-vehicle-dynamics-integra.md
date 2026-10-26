# Chain: Vehicle Physics Time Step — Per-Frame Vehicle Dynamics Integration

Seed: 0x004c73f0  |  System: docs/18-physics-dynamics.md  |  Depth: 3  |  Functions: 8+11 leaf

---

## Overview

Vehicle Physics Time Step is the per-frame entry point for a single vehicle's dynamics. Called from the game's main physics loop (callers: 0x004f0430, 0x004f03e0), it integrates wheel velocities, updates vehicle orientation, and drives the suspension model. It reads delta time from a per-vehicle accumulator, computes steering input, iterates all 4 wheels applying throttle/brake torque, updates the rotation matrix, and manages gear shift state. The chain branches into orientation math, per-wheel suspension force computation, and a subsystem state machine for wheel activation/deactivation.

## Call Tree

```
FUN_004c73f0 — Vehicle Physics Time Step  [trigger: per-frame per-vehicle physics tick]
  +-- FUN_004b2420 — Arithmetic/Comparison  [short-to-float conversion]
  +-- FUN_00566e40 — EulerToRotationMatrix  [math utility — leaf]
  +-- FUN_004e23d0 — 3x3 Matrix Transform  [math utility — leaf]
  +-- FUN_004b2a80 — Bitfield to Float Conversion  [steering angle decode — leaf]
  +-- FUN_004e24a0 — SuspensionParamUpdate  [per-wheel suspension force]
  |     +-- FUN_005670d0 — 3x3 Rotation Matrix from Euler Angles  [leaf]
  |     +-- FUN_00567340 — buffer copy  [leaf]
  +-- FUN_004b28f0 — Scaled Byte/Short Read  [per-wheel torque — leaf]
  +-- FUN_004b2580 — Short Vector to Float with Scale  [leaf]
  +-- FUN_004b26d0 — Float Truncation (x3)  [leaf]
  +-- FUN_004b2800 — Short-to-Float Vector Unpack  [leaf]
  +-- FUN_004b2980 — Bitfield Extract → Scale  [leaf]
  +-- FUN_004b29f0 — Short Computation (Bitfield Extract → Float)  [leaf]
  +-- FUN_004f1650 — Vehicle Setup Data Copy  [leaf]
  +-- FUN_004f17a0 — Effect Parameter Setter  [leaf]
  +-- FUN_004e17c0 — Subsystem state machine  [activate/deactivate]
  |     +-- FUN_004e0d00 — LazyInitCallback  [activate]
  |     +-- FUN_004e0d70 — Conditional Resource Release  [deactivate — leaf]
  |     +-- FUN_004e0e20 — ArrayEntryCleanup  [wheel activate]
  |     +-- FUN_004e0e70 — SubslotCleanup  [wheel deactivate]
  +-- FUN_004f17d0 — Matrix/Vector Setup  [leaf]
  +-- FUN_004e2230 — VibrationStateMachine
  |     +-- FUN_005506a0 — vibration/sound trigger  [leaf]
  +-- FUN_004b2ad0 — Bit Test at +0x30  [leaf]
  +-- FUN_004e0ed0 — Audio/Sound Effect Controller
  +-- FUN_0059d6ff — Flag Set with Boolean-to-Float Conversion  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004c73f0 — Vehicle Physics Time Step

**Trigger:** Called per-frame per-vehicle from main physics loop (callers 0x004f0430, 0x004f03e0)
**Called by:** 0x004f0430 (unknown — main physics distributor), 0x004f03e0 (color data apply)
**Purpose:** Main vehicle physics per-frame update — integrates wheel velocities, updates orientation, drives suspension.

**Key actions:**
1. Reads delta time from param_1+0x48b8 (per-vehicle accumulator)
2. Computes steering angle via FUN_004b2a80 (bitfield-to-float), clamps to [-1, 1], stores at param_1+0x1040
3. Iterates 4 wheels (stride 0x4a from +0x8c0): computes wheel torque from param_1+0x1044 (engine), applies throttle/brake per wheel
4. Updates vehicle rotation matrix via FUN_004b2420/FUN_004e23d0 (orientation integration)
5. Mode check at param_1[13000] (0x32C8): if 2 → writes per-wheel throttle to +0x35bc (stride 0x3e), updates gear ratios; if 3 → directly applies wheel torques
6. Updates gear shift indicator at +0x105d

**Data passed to callees:** param_1 (vehicle struct pointer), wheel index, torque values

### Level 1: FUN_004e24a0 — SuspensionParamUpdate

**Trigger:** Called per-wheel from Vehicle Physics Time Step
**Purpose:** Computes per-wheel suspension force parameters

**Key actions:**
1. Calls FUN_005670d0 → computes 3x3 rotation matrix from Euler angles for suspension geometry
2. Calls FUN_00567340 → copies buffer (wheel contact data)

### Level 1: FUN_004e17c0 — Subsystem state machine

**Trigger:** Called from Vehicle Physics Time Step to manage subsystem activation
**Purpose:** Activates/deactivates vehicle subsystems (per-wheel)

**Key actions:**
1. FUN_004e0d00 — lazy init / activate callback
2. FUN_004e0d70 — conditional resource release (deactivate path)
3. FUN_004e0e20 — wheel-specific array entry cleanup (activate)
4. FUN_004e0e70 — wheel subslot cleanup (deactivate)

### Level 1: FUN_004e2230 — VibrationStateMachine

**Trigger:** Called per-frame from Vehicle Physics Time Step
**Purpose:** Manages vibration/force-feedback state for wheel

**Key actions:**
1. Calls FUN_005506a0 — triggers vibration/sound event based on wheel state

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Vehicle Physics Time Step | param_1+0x48b8 (delta time) | read accumulator | frame dt |
| Vehicle Physics Time Step | param_1+0x1044 (engine) | compute wheel torque | per-wheel torque |
| Vehicle Physics Time Step | mode at +0x32C8 | switch 2/3 | gear ratio update or direct torque |
| Vehicle Physics Time Step | bitfield at +0x30 | FUN_004b2ad0 test | state flag check |

## Globals Written in This Chain

None directly written — operates on per-vehicle struct param_1 throughout.

## Notes

- Chain is predominantly leaf functions (11 of 19 callees are leaves) — this is a hot path where most computation is done in self-contained math utilities
- FUN_004e0ed0 (Audio/Sound Effect Controller) is a cross-system handoff to audio subsystem at depth 1
- FUN_00566e40 (EulerToRotationMatrix) in docs/18 is a math utility despite being in physics-dynamics doc
- The per-wheel stride 0x4a from offset +0x8c0 means each wheel block is 74 bytes

---
