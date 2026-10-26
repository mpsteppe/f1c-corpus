# Chain: Pit Selection State Machine — Tire/Strategy Slot Commentary

Seed: FUN_0041b3c0  |  System: docs/07-pit-system.md  |  Depth: 2  |  Functions: 11

---

## Overview

Manages pit strategy slot selection with commentary triggers. Called during pit stop decision-making when the AI or player selects a tire/repair strategy. Clamps parameters, generates random floats, selects position buckets, queues commentary IDs, and clears decision flags.

## Call Tree

```
FUN_0041b3c0 — Pit Selection State Machine  [trigger: pit strategy decision]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [initializes temp struct]
  +-- FUN_004f0050 — DistanceProjectionCalc  [position/distance bucket calc]
  |     +-- FUN_004e1970 — Effect Data Table Initialization
  +-- FUN_004d7c10 — Float Range Index Lookup  [lookup bucket index by float]
  +-- FUN_004d1ad0 — ScoringGateSelector  [selects scoring gate state]
  |     +-- FUN_004e1970 — Effect Data Table Initialization
  |     +-- FUN_004e3a50 [undocumented]
  +-- FUN_004189b0 — State-Checked Virtual Dispatch  [state-gated dispatch]
  +-- FUN_004189f0 — Array Search Returning Index  [searches commentary array]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_00418a20 — Boolean OR of Two Checks  [queue flag logic]
  |     +-- FUN_00587bcf — Free Wrapper (×2)
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion  [driver data read]
  +-- FUN_00418560 — InsertDriverTableEntry  [writes commentary entry to table]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc
  |     +-- FUN_00587b3e — Boolean-to-Int Conversion
  |     +-- FUN_00587bcf — Free Wrapper
```

## Key Actions

1. Clamps param_4, generates random float, computes position buckets
2. Case 0: selects top strategy slot, checks flags, assigns commentary IDs by bucket
3. Case 2: mid-strategy / deselect, clears queue flags
4. Case 3: commentary ID 0x83 (pit exit)
5. Case 5: player pit confirmed — IDs 0x7b-0x7d
6. Writes commentary/slot selection to driver data table via FUN_00418560

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| param_4 | Strategy index | Clamp + random | Position bucket |
| Bucket | computed bucket | Case switch (0,2,3,5) | Commentary IDs |
| Commentary ID | state + bucket | FUN_00418560 | Driver table entry |

## Notes

- 9 direct callees, mostly leaf utilities
- Interacts with docs/02-ai-system.md for driver data table lookups (FUN_004144f0, FUN_00418560)
- Commentary system uses hardcoded ID constants (0x7b-0x7d, 0x83, 0x204-0x217 range)
- Called during pit stop AI decision-making, not per-frame

---
