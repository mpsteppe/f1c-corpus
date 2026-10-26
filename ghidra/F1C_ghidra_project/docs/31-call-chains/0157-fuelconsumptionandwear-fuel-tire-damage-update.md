# Chain: FuelConsumptionAndWear — Fuel/Tire/Damage Update

Seed: FUN_004ed960  |  System: docs/03-engine-wear-damage.md  |  Depth: 3  |  Functions: 3

---

## Overview

Triggered per frame from Main Game Tick Update (`FUN_0042c690`). Handles fuel consumption, tire wear, brake wear, speed display updates, and 4 damage timer types (engine, gearbox, suspension, brake). Three callees: race phase check, race event sound dispatch, and tire brush model force solver.

## Call Tree

```
FUN_004ed960 — FuelConsumptionAndWear  [trigger: per-frame main game tick]
  +-- FUN_0041ac50 — RaceEventSoundDispatch  [3 callees — failure audio effects]
  |     +-- FUN_004144d0 — Random Init
  |     +-- FUN_004144f0 — State Check
  |     +-- FUN_00418560 — Audio Dispatch
  +-- FUN_004e8010 — TireBrushModelForceSolver  [2 callees — tire grip/loss]
  |     +-- FUN_005895a2 — Float Sqrt Lookup
  |     +-- FUN_004e8200 — Tire Force Apply
  +-- FUN_004d21d0 — RacePhaseCheck  [leaf — checks race phase state]
```

## Step-by-Step Trace

### Level 0: FUN_004ed960 — FuelConsumptionAndWear

**Trigger:** Called from FUN_0042c690 (Main Game Tick Update, docs/01)
**Called by:** FUN_0042c690 — main game tick update
**Purpose:** Handles fuel consumption, tire wear, engine damage timers.

**Key actions:**
1. Decreases fuel level at param_1[0xe5e] by flow * rate * delta; if empty: ReasonCode=9
2. Computes effective fuel mass: fuel_level * 0.75 + base_mass
3. If speed magnitude > threshold: applies tire wear (aggregates 4 wheel loads, wear factor clamped to 0.75 minimum)
4. Computes brake wear from brake bias + pedal input
5. Detects speed change > 0.01: updates display with random jitter
6. Runs 4 damage timers (engine/gearbox/suspension/brake):
   - Case 0 (engine): ReasonCode=1, random failure distribution
   - Case 1 (gearbox): ReasonCode=5, random gear damage
   - Case 2 (suspension): ReasonCode=2, sets +0x39ee flag
   - Case 3 (brake): ReasonCode=4, brake failure accumulator
   - Caps engine timer at 60.0 when EngineWearMode==3

**Struct offsets:** param_1[0xe5e] (FuelLevel), +0x4068 (ReasonCode), +0x39ee (SuspensionFailureFlag)

**Globals:** DAT_007d0c60 (TireWearMultiplier), DAT_007cea5c (EngineWearMode), DAT_008aae70, DAT_008aae74, DAT_008ab274

**Data passed to callees:** Vehicle struct with fuel/wear/damage state, delta time.

### Level 1: FUN_0041ac50 — RaceEventSoundDispatch

**Trigger:** Called when damage timer expires or failure occurs
**Purpose:** Dispatches race event sounds for mechanical failures.

**Key actions:**
1. Initializes random via FUN_004144d0
2. Checks state via FUN_004144f0
3. Dispatches audio via FUN_00418560

### Level 2: FUN_004144d0 — Random Init

**Trigger:** Called from RaceEventSoundDispatch
**Purpose:** Initializes random seed for sound variation.

### Level 2: FUN_004144f0 — State Check

**Trigger:** Called from RaceEventSoundDispatch
**Purpose:** Checks vehicle state for appropriate sound selection.

### Level 2: FUN_00418560 — Audio Dispatch

**Trigger:** Called from RaceEventSoundDispatch
**Purpose:** Dispatches audio effect for the failure type.

### Level 1: FUN_004e8010 — TireBrushModelForceSolver

**Trigger:** Called from FuelConsumptionAndWear for tire force computation
**Purpose:** Solves tire brush model forces for grip/loss calculation.

**Key actions:**
1. Calls FUN_005895a2 for floating-point sqrt lookup
2. Applies tire force via FUN_004e8200

### Level 1: FUN_004d21d0 — RacePhaseCheck

**Trigger:** Called from FuelConsumptionAndWear
**Purpose:** Checks current race phase to determine if wear/damage should be applied.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004ed960 | Fuel level, tire wear, damage timers | Decrement + clamp + check | Updated fuel/wear/damage |
| FUN_0041ac50 | Failure type | Random + dispatch | Audio effect |
| FUN_004e8010 | Tire contact data | Brush model solve | Tire grip force |
| FUN_004d21d0 | Race phase | Phase check | Wear enable/disable |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0c60 | TireWearMultiplier | FUN_004ed960 (reader) | Tire wear rate scaling |
| DAT_007cea5c | EngineWearMode | FUN_004ed960 (reader) | 0/2/3 mode for engine cap |
| DAT_008aae70 | RingBufferCounter | FUN_004ed960 (reader) | Ring buffer for random |

## Notes

- Three callees of seed: FUN_0041ac50 (3 callees), FUN_004e8010 (2 callees), FUN_004d21d0 (leaf)
- FUN_0041ac50 (RaceEventSoundDispatch) is also called from EngineStressSimulation (FUN_0043ef20) — shared failure-to-sound routing
- Damage timer expiry triggers ReasonCode changes that feed back into session scoring (DNF detection)
- Fuel flow rate, tire wear rate, damage timer durations, and failure thresholds are all `configurable`
- FUN_004e8010 (TireBrushModelForceSolver) shares FUN_005895a2 (sqrt lookup) with other physics functions

---

## Summary

| Chain | Seed | System | Depth | Functions | Top Callee |
|-------|------|--------|-------|-----------|------------|
| 145 | 0x004f0430 | docs/06 | 4 | 13 | FUN_004c73f0 (19 callees) |
| 146 | 0x0045f4a0 | docs/01 | 3 | 10 | FUN_00465460 (13 callees) |
| 147 | 0x004eb430 | docs/19 | 4 | 12 | FUN_004ebc60 (9 callees) |
| 148 | 0x004c6b60 | docs/06 | 4 | 10 | FUN_004bc9b0 (8 callees) |
| 149 | 0x004a6e50 | docs/07 | 4 | 10 | FUN_004a68b0 (10 callees) |
| 150 | 0x004ddf90 | docs/08 | 3 | 9 | FUN_005887b1 (5 callees) |
| 151 | 0x0040b710 | docs/09 | 3 | 8 | FUN_00541cd0 (2 callees) |
| 152 | 0x00424790 | docs/02 | 3 | 7 | FUN_00424cd0 (5 callees) |
| 153 | 0x0045d530 | docs/21 | 2 | 7 | all wrappers (1 callee each) |
| 154 | 0x0041ff10 | docs/20 | 3 | 6 | FUN_004c2990 (2 callees) |
| 155 | 0x004122c0 | docs/02 | 3 | 4 | FUN_004134d0 (2 callees) |
| 156 | 0x004ed960 | docs/03 | 3 | 3 | FUN_0041ac50 (3 callees) |
