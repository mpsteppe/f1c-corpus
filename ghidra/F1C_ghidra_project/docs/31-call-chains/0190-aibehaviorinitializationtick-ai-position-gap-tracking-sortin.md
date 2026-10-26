# Chain 189: AIBehaviorInitializationTick — AI Position/Gap Tracking + Sorting

Seed: FUN_004bf0a0  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 6 direct

---

## Overview

Initializes AI state arrays and computes gaps and positions between vehicles. Stores current time, resolves track data, computes per-vehicle distance/gap tracking, and re-sorts driver order. Called per-frame to maintain AI situational awareness.

## Call Tree

```
FUN_004bf0a0 — AIBehaviorInitializationTick  [per-frame AI state update]
  +-- FUN_004ba140 — Arithmetic/Comparison / Collision Proxy Field Setter  [stores current time]
  +-- FUN_004be760 — [unnamed — finish time predictor]  [predicts AI finish time from difficulty slider]
  +-- FUN_004be9e0 — Animation State Setter  [AI animation state update]
  +-- FUN_004bea10 — [unnamed — unidentified logic]  [AI state initialization]
  +-- FUN_0042ae90 — StateFlagsLookup  [reads AI state flags]
  +-- FUN_004bf390 — AI Driver Sorting / Priority  [sorting, 1 sub-callee]
        +-- FUN_004bc2f0 — [swap helper]  [swaps two driver positions]
```

## Step-by-Step Trace

### Level 0: FUN_004bf0a0 — AIBehaviorInitializationTick

**Trigger:** Called per-frame from the AI update loop.

**Called by:** AI system dispatch (callers.json shows 1 caller from docs/02-ai-system.md).

**Purpose:** Initializes AI state arrays, computes gaps and positions between vehicles. Core AI situational awareness update.

**Key actions:**
1. Stores current time via FUN_004ba140
2. Resolves track data for AI reference
3. Switch on EngineWearMode for initial gap computation mode
4. Zeroes local float array (0x68 elements) for per-vehicle state
5. Main vehicle loop: skips inactive vehicles, computes distance, tracks max gap
6. Stores time/gap data to each vehicle's AI struct
7. Calls FUN_004bf390 for re-sort (bubble-sort style driver ordering)

**Data passed to callees:** Current time, vehicle pointers, track data, gap/distance arrays

### Level 1: Callees

**FUN_004ba140 — Arithmetic/Comparison / Collision Proxy Field Setter**
- Leaf function (docs/17-physics-collision.md)
- Stores current simulation time to AI state
- Used as timestamp reference for gap computation

**FUN_004be760 — Finish Time Predictor**
- Leaf function (not in functions.json, referenced from AI doc)
- Predicts AI finish time based on difficulty slider: `slider * (1/120)`
- At slider=100 → parameter ≈ 0.833; slider=120 → parameter = 1.0
- Higher difficulty = tighter predicted finish times

**FUN_004be9e0 — Animation State Setter**
- Leaf function (docs/06-session-race-logic.md)
- Updates AI animation state (steering animation, driver model)
- Sets per-vehicle animation parameters

**FUN_004bea10 — Unidentified Logic**
- Leaf function (no metadata)
- Part of AI state initialization sequence
- Likely processes per-vehicle AI configuration

**FUN_0042ae90 — StateFlagsLookup**
- Leaf function (docs/06-session-race-logic.md)
- Reads AI state/flags from vehicle struct
- Returns state information used for gap computation branching

**FUN_004bf390 — AI Driver Sorting / Priority**
- 1 callee (FUN_004bc2f0 — swap helper)
- Bubble-sort-like algorithm for driver ordering
- Race: compares +0x403c (SeasonPoints) and +0x4098 (time)
- Non-race: compares +0x409c (gap)
- Calls FUN_004bc2f0 to swap positions when out of order

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Current time | simulation clock | Store via FUN_004ba140 | Time reference |
| Track data | track waypoints | Resolve | Track reference positions |
| Vehicle loop | VehicleCount × VehiclePtrArray | Compute distance/gap | Per-vehicle gap array |
| FUN_004be760 | difficulty slider | Predict finish time | Speed target per AI |
| FUN_004bf390 | vehicle data array | Bubble sort | Re-ordered driver positions |

## Globals Read

| Global | Name | Used by | Purpose |
|--------|------|---------|---------|
| DAT_007d01a0 | AIDifficultySlider | FUN_004be760 | Difficulty scaling |
| DAT_007cea5c | EngineWearMode | FUN_004bf0a0 | Gap computation mode |
| DAT_005c329c | VehicleCount | FUN_004bf0a0 | Loop bound |
| DAT_007c54f0 | VehiclePtrArray | FUN_004bf0a0 | Vehicle access |

## Notes

- 5 of 6 callees are leaf functions — flat dispatch
- FUN_004bf390 is the only callee with sub-callees (single swap function)
- The EngineWearMode switch affects how initial gaps are computed (affects AI spacing)
- EngineWearMode=0 → tighter gaps, EngineWearMode=2/3 → wider gaps
- The re-sort in FUN_004bf390 uses different criteria for race vs non-race sessions

---
