# Chain: AI Racing Line Path Following — Waypoint Interpolation and Node Triggering

Seed: FUN_004e9ca0  |  System: docs/18-physics-dynamics.md  |  Depth: 1-2  |  Functions: 12 callees

---

## Overview

Called per-frame per-AI-vehicle. Follows a racing-line waypoint path: computes distance to path, finds nearest segment, projects position via dot-product, walks path nodes forward updating position, triggers per-node events. If VCR recording active, records playback frames.

## Call Tree

```
FUN_004e9ca0 — AI Racing Line Path Following  [trigger: per-frame AI vehicle update]
  +-- FUN_004bc340 — AI path-following active check                  [leaf]
  +-- FUN_004efb20 — Position/velocity getter                        [leaf]
  +-- FUN_004d1140 — Path/waypoint data access                       [depth 1: HAS 0 callees]
  +-- FUN_00403640 — 3D vector math (distance, dot product)          [depth 1: HAS 0 callees]
  +-- FUN_004ef6c0 — AI physics helper (gap/speed)                   [depth 1: HAS 0 callees]
  +-- FUN_004e9600 — Path node walk/preprocessor                     [depth 1: HAS 0 callees]
  +-- FUN_004e9a40 — Segment projection/position updater             [leaf]
  +-- FUN_004e9bd0 — Node trigger handler                            [leaf]
  +-- FUN_0054fae0 — VCR playback frame record                       [leaf]
  +-- FUN_0054fb40 — VCR playback helper                             [leaf]
  +-- FUN_0054f7a0 — VCR recording state check                       [depth 1: HAS 0 callees]
  +-- FUN_00566e40 — Math utility (vector operations)                [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004e9ca0 — AI Racing Line Path Following

**Trigger:** Per-frame AI vehicle update. Called from AI subsystem tick.
**Called by:** Documented in docs/06-session-race-logic.md line 1792 as being called during race logic.
**Purpose:** Follow racing line waypoints: find nearest path segment, project position, advance along path.

**Key actions:**
1. Check AI path active via FUN_004bc340
2. Get current position via FUN_004efb20, path data via FUN_004d1140
3. If distance from path exceeds threshold: find nearest segment via FUN_00403640
4. Walk path nodes forward, project position onto segment via dot-product
5. Skip nodes until projection positive (ahead of current position)
6. If VCR active (DAT_008ad07c/80/84): record playback frames
7. Update stored path position at vehicle +0xd35/0xd36/0xd37
8. Iterate remaining segment chain calling per-node triggers

**Data passed to callees:** vehicle struct pointer, path data, position vectors.

### Level 1: Selected Callees

- **FUN_004d1140 (path/waypoint data access):** Accesses racing line path data from vehicle struct.
- **FUN_00403640 (3D vector math):** Distance and dot-product computation for path proximity.
- **FUN_004ef6c0 (AI physics helper):** Speed delta, gap calculations.
- **FUN_004e9600 (path node walk):** Walks path nodes, finds forward advancement.
- **FUN_0054f7a0 (VCR state check):** Checks DAT_008ad07c/80/84 for VCR recording active flags.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004e9ca0 | vehicle ptr, path data | waypoint follow | updated path position |
| FUN_00403640 | pos, path segment | dot product | nearest segment |
| FUN_004e9600 | path nodes | walk forward | current node index |
| FUN_004e9bd0 | node | trigger | per-node event |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008ad07c | VCR_Record0 | FUN_004e9ca0 | VCR frame recording |
| DAT_008ad080 | VCR_Record1 | FUN_004e9ca0 | VCR frame recording |
| DAT_008ad084 | VCR_Record2 | FUN_004e9ca0 | VCR frame recording |

## Notes

Chain depth is 1-2 for all callees. FUN_004e9600 is the only callee with any deeper chain potential, but call_graph.json shows it with 0 further callees.

---
