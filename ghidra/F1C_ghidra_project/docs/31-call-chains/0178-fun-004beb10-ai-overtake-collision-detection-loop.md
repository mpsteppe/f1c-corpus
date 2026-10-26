# Chain 177: FUN_004beb10 — AI Overtake / Collision Detection Loop

Seed: FUN_004beb10  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 6

---

## Overview

Core AI per-frame function — iterates vehicles, checks overlap/collision conditions, triggers position swaps. Accumulates timing delta, computes position gaps, checks distance via FUN_004bea10. Classifies collisions: 0 = clean overtake (increment position, call FUN_004bf390), 1 = contact (sound + severity), 2 = heavy contact. Called from the session frame tick loop.

## Call Tree

```
FUN_004beb10 — AI Overtake / Collision Detection Loop  [called by: per-frame session tick]
  +-- FUN_004bf0a0 — AI Behavior Initialization / Tick (6 callees)
  |     +-- FUN_004ba140 — [undocumented]
  |     +-- FUN_004be760 — [undocumented]
  |     +-- FUN_004be9e0 — [undocumented]
  |     +-- FUN_004bea10 — [undocumented] distance check
  |     +-- FUN_0042ae90 — [undocumented]
  |     +-- FUN_004bf390 — AI Driver Sorting / Priority
  |           +-- FUN_004bc2f0 — [undocumented]
  +-- FUN_004bea10 — [undocumented] distance check  [leaf]
  +-- FUN_004bef60 — AI Collision / Out-of-Bounds Check
  |     +-- FUN_0042aeb0 — [undocumented]
  +-- FUN_004bf390 — AI Driver Sorting / Priority  [also called from FUN_004bf0a0]
  |     +-- FUN_004bc2f0 — [undocumented]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [leaf]
  +-- FUN_004bf4f0 — [undocumented] no-collision handler
        +-- FUN_004bf390 — AI Driver Sorting / Priority (re-sort)
```

## Step-by-Step Trace

### Level 0: FUN_004beb10 — AI Overtake / Collision Detection Loop

**Trigger:** Per-frame session tick
**Called by:** FUN_0046bf10
**Purpose:** Detects overtakes and collisions between AI vehicles, updates positions

**Key actions:**
1. Initializes from globals, checks formation lap
2. Accumulates param_1[0xd5] += param_1[0xd4] (timing delta)
3. Main vehicle loop: updates position delta via FUN_004bea10 (distance check)
4. Collision classification: 0=clean overtake (FUN_004bf390), 1=contact (sound+severity), 2=heavy contact
5. If no collisions: calls FUN_004bf4f0 → re-sort via FUN_004bf390
6. Calls FUN_004b33b0 for progress bar update

### Level 1: FUN_004bf0a0 — AI Behavior Initialization / Tick

**Purpose:** Initializes AI state arrays, computes gaps and positions

**Key actions:**
1. Stores current time, resolves track data
2. Switch on EngineWearMode for initial gap
3. Zeroes local float array (0x68 elements)
4. Main vehicle loop: skips inactive, computes distance, tracks max gap
5. Calls FUN_004bf390 for driver re-sort

### Level 1: FUN_004bef60 — AI Collision / Out-of-Bounds Check

**Purpose:** Determines collision type for a vehicle

**Key actions:**
1. If not race session: returns 0
2. Checks 4 slot active flags at +0x834
3. If vehicle state == 2: returns 2 (disabled)
4. If EngineWearMode==3: position rank check
5. Computes left/right force factors, stores in ring buffer

### Level 1: FUN_004bf390 — AI Driver Sorting / Priority

**Purpose:** Bubble-sort-like algorithm for driver ordering

**Key actions:**
1. Iterates VehicleCount times
2. Race: compares +0x403c rank and +0x4098 time
3. Non-race: compares +0x409c gap

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Accumulator | param_1[0xd4] | param_1[0xd5] += param_1[0xd4] | timing delta |
| Distance | vehicle positions | FUN_004bea10 | overlap/distance |
| Collision type | flags + state | FUN_004bef60 | 0/1/2 type |
| Overtake | clean pass | FUN_004bf390 | updated position |
| Re-sort | no collision | FUN_004bf4f0 → 004bf390 | driver reorder |

## Notes

- FUN_004bf390 is called from 3 different paths in this chain (direct, via FUN_004bf0a0, via FUN_004bf4f0)
- Accumulator offsets +0xd4/+0xd5 observed in struct offset tracking (docs/13)
- FUN_004bef60 reads EngineWearMode (DAT_007cea5c) for collision severity modulation
- 5 of 6 callees reference vehicle struct offsets at +0x403c (SeasonPoints), +0x4098, +0x409c

---
