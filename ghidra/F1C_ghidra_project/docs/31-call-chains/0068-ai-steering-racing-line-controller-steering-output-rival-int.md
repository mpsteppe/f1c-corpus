# Chain: AI Steering / Racing Line Controller — Steering Output & Rival Interaction

Seed: FUN_004270a0  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 8 callees

---

## Overview

FUN_004270a0 computes per-frame steering output and brake force for one AI vehicle. Called by FUN_00424e70 (AI Main Update) as part of the AI tick. Iterates 5 path/rival candidates at struct stride +0x11, computes cost ratios (lateral/longitudinal gap), sorts into priority order, and dispatches through a rivalry state machine (normal, passing, side-by-side, fall back, defend). Reads path segments via FUN_00403aa0/FUN_004039c0 (spatial tree queries), computes lateral gap, accumulates brake, and determines overtake/defend state. Writes final steering to param_1[0x1103], filtered copy to [0x1102], brake active flag at +0x4579. Uses DAT_0059xxxx globals for thresholds.

## Call Tree

```
FUN_004270a0 — AI Steering / Racing Line Controller  [trigger: per AI tick]
  +-- FUN_00403aa0 — Spatial Tree Nearest-Neighbor Search  [path segment resolve]
  |     +-- FUN_004038e0 — Spatial Nearest-Neighbor Query  [exhaustive fallback]
  +-- FUN_004039c0 — BVH Nearest-Neighbor Query  [alternate path resolve]
  +-- FUN_00423ca0 — Short Computation / Steering Torque  [segment handling 1]
  +-- FUN_00423db0 — Short Computation  [segment handling 2]
  +-- FUN_00423b10 — Vehicle Dynamics Force  [segment handling 3]
  +-- FUN_0042a740 — Track Parameter Minimum Clamp  [set throttle]
  +-- FUN_0042af70 — Overtaking / Passing Decision  [vehicle-facing state dispatch]
  |     +-- FUN_004f1c20 — Replay/AI State Check  [state check]
  |     +-- FUN_0042ae60 — Server Session Gate Check  [network check]
  +-- FUN_004fae70 — Signed Index Table Lookup  [sqrtf for brake computation]
```

## Step-by-Step Trace

### Level 0: FUN_004270a0 — AI Steering / Racing Line Controller

**Trigger:** Per AI tick, called by FUN_00424e70 (AI Main Update)
**Called by:** FUN_00424e70
**Purpose:** Compute steering output, brake force, and per-rival driving state

**Key actions:**
1. Reads param_1[0x10d5] (current vehicle ptr) and [0x115b] (flag byte)
2. Initializes steering limits [0x1105]/[0x1106] from track-speed
3. Main loop (0..4): iterates 5 path/rival candidates
4. For each rival: state machine at param_1[(rivalIdx + 0x263) * 7]
5. Computes cost ratio = lateral_ahead / longitudinal_gap
6. Brake computation via sqrt(FUN_004fae70) of speed-based target
7. Writes final steering to [0x1103], brake flag to +0x4579

### Level 1: Key Callees

**FUN_00403aa0 — Spatial Tree Nearest-Neighbor Search**
- Finds nearest waypoint node to vehicle position
- Walks primary (+0x10c) and secondary (+0x110) linked lists
- Returns closest node pointer (docs/17-physics-collision.md)

**FUN_0042af70 — Overtaking / Passing Decision**
- Compares two AI drivers for overtaking outcome
- Checks SeasonPoints, driver numbers, DRS/ERS conditions
- Sets +0x117f target, steering direction (2=right, else=left)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Path resolve | Vehicle position | FUN_00403aa0 | Path segment index |
| Rival loop | 5 candidates | Cost ratio sort | Priority order |
| State machine | Rival state | Per-state dispatch | Driving mode |
| Brake | Speed target | sqrt(FUN_004fae70) | Brake force |
| Output | Computed values | Write to struct | param_1[0x1103], +0x4579 |

## Globals Written in This Chain

None directly — reads DAT_0059xxxx globals for thresholds but doesn't write globals.

## Notes

- All 8 callees are relatively small leaf functions
- FUN_00403aa0 uses a spatial tree with primary/secondary linked lists; FUN_004039c0 is alternative BVH query
- FUN_00423ca0/db0/b10 are short computations for segment handling (undocumented)
- Steering limits [0x1105]/[0x1106] are track-speed dependent
- Brake active flag at +0x4579 is cleared at top of frame and set when braking

---
