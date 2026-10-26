# Chain: AI Main Update / Race Phase State Machine — Per-Frame AI Behavior Dispatch

Seed: FUN_00424e70  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 15 direct callees

---

## Overview

FUN_00424e70 is the central AI tick function, called per physics frame by FUN_0042c690 (game loop). Gates on param_1[0xcb2] (AIActiveFlag, 0/1). Dispatches AI behavior for one vehicle based on behavior state at +0x1144: states 4/5 (pit window), 0/6 (follow), 1 (pursuit), 3 (pit entry), 2 (pit in), 7 (overtake). Calls 15 subfunctions covering waypoint steering (FUN_00426430), push lap logic (FUN_0042a180), ability/lap ratio update (FUN_00429470), overtaking probability (FUN_004a4110), steering angle control (FUN_00425670), speed state setting (FUN_004258c0), opponent proximity scan (FUN_0042a7d0), racing line gap computation (FUN_00425920), steering output (FUN_004270a0), target angle computation (FUN_00426100), steering correction (FUN_00426cf0), gear/shift logic (FUN_00426330), and state cleanup (FUN_00424c80, FUN_0042adb0). Mutates vehicle AI struct fields at offsets +0x1102-0x1157 (steering, brakes, flags) and +0x1144 (behavior state).

## Call Tree

```
FUN_00424e70 — AI Main Update / Race Phase State Machine  [trigger: per physics frame]
  +-- FUN_00426430 — AI Waypoint Steering  [computes steering angles to follow path]
  |     +-- FUN_004038e0 — Spatial Nearest-Neighbor Query  [find nearest waypoint]
  |     +-- FUN_00403aa0 — Spatial Tree Nearest-Neighbor Search  [waypoint increment]
  |     +-- FUN_004a46f0 — Indexed Field Setter  [racing line toggle]
  |     +-- FUN_004e8ce0 — TireForceSolver  [tire force lookup]
  |     +-- FUN_00424cd0 — AI Command/Message Queue  [braking zone dispatch]
  +-- FUN_0042a180 — AI Push Lap / Closing Gap  [push-lap ratio and aggression]
  |     +-- FUN_0042a110 — Force Pit Exit / Advance State  [pit decision]
  |     +-- FUN_004f1630 — Tire Name Accessor  [compound check]
  |     +-- FUN_004a4830 — Tire Compound Name/ID Mapping  [compound lookup]
  +-- FUN_00429470 — AI Ability / Lap Ratio / Push Lap Update  [lap quality]
  |     +-- FUN_004d1cf0 — Ring Buffer Access  [lap counter]
  |     +-- FUN_0042a3d0 — Pit Stop Decision & Tire Compound  [strategy]
  |     +-- FUN_004f1890 — Speed/Value Setter  [global mirror]
  |     +-- FUN_0042a6f0 — Post-Pit Cleanup / Exit  [pit state reset]
  |     +-- FUN_00429eb0 — Race-Phase Pit Entry Trigger  [paddock check]
  +-- FUN_0042ae00 — AIClearStateFlags  [clear state]
  +-- FUN_004a4110 — AI Overtaking / Aggression Probability  [pass decision]
  |     +-- FUN_0042add0 — AIDelegateCall  [delegate]
  |     +-- FUN_00426cc0 — Speed Delta Computation  [gap calc]
  |     +-- FUN_0042ae90 — StateFlagsLookup  [flag read]
  +-- FUN_00425670 — SteeringAngleController  [steering target]
  |     +-- FUN_004ef930 — Race Start/Countdown State  [start lights]
  +-- FUN_004258c0 — AI Speed/Overtaking State Setter  [state write]
  +-- FUN_0042a7d0 — Opponent Proximity Scan  [nearest rival]
  |     +-- FUN_004a4710 — Find Nearest Vehicle  [scan]
  +-- FUN_00425920 — AI Racing Line / Overtaking Gap  [gap profile]
  |     +-- FUN_0042a780 — AIComputePassScore  [score]
  |     +-- FUN_004e87e0 — Brake Thermal Model  [temp clamp]
  +-- FUN_004270a0 — AI Steering / Racing Line Controller  [steering output]
  |     [see Chain 67 for full subtree]
  +-- FUN_00426100 — AI Steering Target Angle  [target angle]
  |     +-- FUN_005894a0 — Float Function Pass-Through  [math]
  +-- FUN_00426cf0 — AI Steering Correction / Stability  [final steering]
  |     +-- FUN_00424750 — AI Difficulty Scalar  [difficulty]
  |     +-- FUN_004e8780 — SuspensionRatioClamp  [state read]
  |     +-- FUN_004e88b0 — vehicle struct access  [struct read]
  |     +-- FUN_0042b0e0 — AI Steering & Racing Line Correction  [correction]
  +-- FUN_00426330 — Physics Gear/Shift Logic  [gear selection]
  |     +-- FUN_004f62e6 — [PARTIAL] Unknown  [shift threshold]
  +-- FUN_00424c80 — AI Ring Buffer Field Init  [field zero]
  +-- FUN_0042adb0 — Session Cleanup Flag Clear  [flag clear]
```

## Step-by-Step Trace

### Level 0: FUN_00424e70 — AI Main Update / Race Phase State Machine

**Trigger:** Per physics frame, called by FUN_0042c690 (game loop)
**Called by:** FUN_0042c690 (game loop dispatch)
**Purpose:** Central AI behavior tick for one vehicle

**Key actions:**
1. Gate check: param_1[0xcb2] (AIActiveFlag) must be 0 or 1
2. Behavior state machine at +0x1144: reads current state, dispatches to sub-controllers
3. Pit exit block: heading computation, lap push logic, ability update
4. Race phase transition block: detects phase change, decrements timer
5. Phase 4 (parked): computes steering with random offset

**Data passed to callees:** param_1 (AI vehicle struct pointer) passed to all subfunctions

### Level 1: Key Callees

**FUN_00426430 — AI Waypoint Steering**
- Reads current waypoint from param_1[0x10d5] and target zone from [0x1154]
- Falls back to FUN_004038e0 if no waypoint
- Computes lateral deviation [0x110a] and desired heading
- Sets braking zone level [0x111a] (0-3) from speed thresholds
- Toggles racing line variant via FUN_004a46f0
- Writes 7 waypoint lookahead indices to [0x10d6]..[0x10dc]

**FUN_00429470 — AI Ability / Lap Ratio / Push Lap Update**
- Gets vehicle type via FUN_004d1cf0
- Computes LiveLapRatio = min(QualiAbility + delta, RaceAbility + delta)
- Push lap: random chance based on RaceAbility
- Pit check: tire-lap counter vs current lap via FUN_0042a110

**FUN_004a4110 — AI Overtaking / Aggression Probability**
- Computes probability of overtaking based on aggression
- Delegates via FUN_0042add0
- Reads speed delta via FUN_00426cc0

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00424e70 | param_1[0xcb2] | Gate check | Continue/abort |
| FUN_00426430 | Waypoint index [0x10d5] | Path following | Steering angle at [0x110a] |
| FUN_00429470 | QualiAbility [0x1130] | min+delta | LiveLapRatio [0x114f] |
| FUN_004a4110 | Aggression stats | Probability calc | Overtake decision |
| FUN_004270a0 | Steering limits [0x1105/6] | Steering control | Final steering [0x1103] |
| FUN_00425920 | AIFollowTarget [0x4438] | Gap chain scan | Overtaking gap |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005c329c | VehicleCount | (indirect via pit logic) | Vehicle count update |
| DAT_007c54f0 | VehiclePtrArray | (indirect) | Vehicle pointer array |

## Notes

- All 15 callees are called unconditionally each tick — no early-out dispatch
- FUN_004270a0 (steering controller) is documented as Chain 67 below
- FUN_00426430 (waypoint steering) is the most complex callee with 5 sub-callees
- FUN_00425920 (racing line gap) chains up to 20 hops chasing AIFollowTarget
- Many DOT_0059xxxx globals are tuning constants for steering gain, braking thresholds, speed deadzones

---
