# Chain: VehicleSetupInit — Vehicle Setup / Physics Tick Trigger

Seed: FUN_004f0430  |  System: docs/06-session-race-logic.md  |  Depth: 4  |  Functions: 13

---

## Overview

Triggered per-vehicle from two separate callers — mode-dispatched render/physics init (`FUN_0040f300`) and per-vehicle camera update iterator (`FUN_004109d0`). Seeds initial vehicle setup (suspension geometry, brake/TCS/ABS factors) on first call, then per-frame effects update every 16 frames. The most complex sub-branch is the Vehicle Physics Time Step (`FUN_004c73f0`, 19 callees), which integrates wheel velocities, updates vehicle orientation, drives suspension, and manages gear state. Supporting chains handle audio sample dispatch, vehicle sound triggers, camera FOV adjustment, and vibration state.

## Call Tree

```
FUN_004f0430 — VehicleSetupInit  [trigger: mode-dispatched init or per-vehicle camera update]
  +-- FUN_004c73f0 — Vehicle Physics Time Step  [19 callees — main physics tick]
  |     +-- FUN_004b2420 — Orientation Integrator  [rotates vehicle body]
  |     +-- FUN_004b2a80 — Steering Angle Compute  [clamps to [-1,1]]
  |     +-- FUN_004e24a0 — SuspensionParamUpdate  [per-wheel suspension (also called directly)]
  |     +-- FUN_004e2230 — VibrationStateMachine  [vibration/sound trigger]
  |     +-- 15 additional leaf callees omitted
  +-- FUN_004b9ac0 — AudioSampleDispatchByState  [5 callees]
  |     +-- FUN_004b72a0 — Visibility Lookup
  |     +-- FUN_005000c0 — Audio Playback
  |     +-- 3 additional leaf callees omitted
  +-- FUN_004f12e0 — VehicleSoundTrigger  [3 callees]
  |     +-- FUN_004f0f40 — Sound Sequence Resolve
  |     +-- FUN_004f1120 — Sound Trigger Enqueue
  |     +-- FUN_004f87c0 — HUD Element Config
  +-- FUN_004f0d20 — CameraFOVByProximity  [3 callees]
  |     +-- FUN_004d1140 — Distance Computation
  |     +-- FUN_004efb20 — World Position Get
  |     +-- FUN_004e2ca0 — FOV Set
  +-- FUN_00446fd0 — CollisionPositionTransform  [2 callees]
  |     +-- FUN_004361d0 — Transform Math
  |     +-- FUN_0056c740 — Buffer Operation
  +-- 13 additional leaf callees omitted
```

## Step-by-Step Trace

### Level 0: FUN_004f0430 — VehicleSetupInit

**Trigger:** Called from FUN_0040f300 (Mode-Dispatched Render/Physics Call) and FUN_004109d0 (Per-Vehicle Camera Update Iterator)
**Called by:** FUN_0040f300 (mode-dispatched render/physics init), FUN_004109d0 (per-vehicle camera update)
**Purpose:** Initializes vehicle setup and runs per-frame effects update every 16 frames.

**Key actions:**
1. Case 0 (player): full wheel/suspension setup, brake/TCS/ABS factors
2. Cases 1-2: partial setup with steering wobble randomization
3. Case 3 (replay): load from replay data
4. Post-switch: calls per-frame effects update every 16 frames
5. Dispatches to 18 callees including physics update, audio, camera, collision

**Data passed to callees:** Vehicle struct pointer (param_1) containing suspension, wheel, and setup configuration.

### Level 1: FUN_004c73f0 — Vehicle Physics Time Step

**Trigger:** Called from FUN_004f0430 as main physics per-frame update
**Purpose:** Integrates wheel velocities, updates orientation, drives suspension per frame.

**Key actions:**
1. Computes delta time from param_1+0x48b8 accumulator
2. Computes steering angle from FUN_004b2a80, clamps to [-1, 1]
3. Stores steering in param_1+0x1040
4. Iterates 4 wheels (stride 0x4a from +0x8c0): computes wheel torque from param_1+0x1044 (engine), applies throttle/brake per wheel
5. Updates vehicle rotation matrix via orientation integration
6. Mode check at param_1[13000] (0x32C8): case 2 writes per-wheel throttle, updates gear ratios; case 3 directly applies wheel torques
7. Updates gear shift indicator at +0x105d

**Data passed to callees:** Vehicle physics struct with wheel states, engine torque, orientation matrix.

### Level 2: FUN_004b2420 — Orientation Integrator

**Trigger:** Called from Vehicle Physics Time Step
**Purpose:** Updates vehicle body rotation matrix from angular velocity.

**Key actions:**
1. Reads angular velocity from vehicle struct
2. Integrates orientation using delta time
3. Outputs updated 3x3 rotation matrix

### Level 2: FUN_004b2a80 — Steering Angle Compute

**Trigger:** Called from Vehicle Physics Time Step
**Purpose:** Computes steering angle from input.

**Key actions:**
1. Reads steering input from vehicle struct
2. Clamps to [-1.0, 1.0] range
3. Returns computed steering angle

### Level 2: FUN_004e24a0 — SuspensionParamUpdate

**Trigger:** Called from Vehicle Physics Time Step (also direct from seed)
**Purpose:** Updates per-wheel suspension parameters.

**Key actions:**
1. Calls FUN_005670d0 for force/param update
2. Calls FUN_00567340 for buffer copy

### Level 2: FUN_004e2230 — VibrationStateMachine

**Trigger:** Called from Vehicle Physics Time Step
**Purpose:** Manages vibration state, triggers sound effects.

**Key actions:**
1. Reads current vibration state
2. Calls FUN_005506a0 for vibration/sound trigger

### Level 1: FUN_004b9ac0 — AudioSampleDispatchByState

**Trigger:** Called from FUN_004f0430 for audio dispatch
**Purpose:** Dispatches audio samples based on vehicle state.

**Key actions:**
1. Looks up visibility via FUN_004b72a0
2. Checks state flags via FUN_005001d0/FUN_005001f0
3. Plays audio via FUN_005000c0/FUN_00500210

### Level 1: FUN_004f12e0 — VehicleSoundTrigger

**Trigger:** Called from FUN_004f0430 for sound events
**Purpose:** Triggers vehicle-specific sounds.

**Key actions:**
1. Resolves sound sequence via FUN_004f0f40
2. Enqueues sound trigger via FUN_004f1120
3. Configures HUD element via FUN_004f87c0

### Level 1: FUN_004f0d20 — CameraFOVByProximity

**Trigger:** Called from FUN_004f0430, per-frame effects update
**Purpose:** Sets camera FOV based on other driver proximity.

**Key actions:**
1. If driver index differs from player vehicle: computes distance via FUN_004d1140
2. Gets world position via FUN_004efb20
3. If below threshold: sets FOV from DAT_007cf83c via FUN_004e2ca0

### Level 1: FUN_00446fd0 — CollisionPositionTransform

**Trigger:** Called from FUN_004f0430 for collision setup
**Purpose:** Transforms collision position data.

**Key actions:**
1. Calls FUN_004361d0 for transform math
2. Calls FUN_0056c740 for buffer operation

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004f0430 | Vehicle struct, mode (0-3) | Case switch setup + effects | Updated vehicle config |
| FUN_004c73f0 | delta, steering, engine torque | Wheel iteration, orientation | Integrated velocity, rotation |
| FUN_004b2a80 | Steering input | Clamp to [-1,1] | Clamped angle |
| FUN_004e24a0 | Suspension params | Force/param update | Updated suspension |
| FUN_004f0d20 | Driver index, proximity threshold | Distance comparison | Updated FOV |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007cf83c | FOVThreshold | FUN_004f0d20 (reader) | Proximity-based FOV threshold |

## Notes

- FUN_004c73f0 is the most complex callee with 19 sub-callees (only top-5 documented above, 15 leaf callees omitted)
- The seed has 18 callees total; 5 most-complex sub-trees documented above, 13 leaf/simple callees omitted
- SuspensionParamUpdate (FUN_004e24a0) appears both as a direct callee and inside the physics time step
- FUN_004f0d20 (CameraFOVByProximity) is itself a separate documented function in docs/06 with its own 3 callees
- The vibration/sound chain (FUN_004e2230 → FUN_005506a0) is cross-system to audio

---
