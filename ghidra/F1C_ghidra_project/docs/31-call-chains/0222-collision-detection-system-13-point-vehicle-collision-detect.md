# Chain: Collision Detection System — 13-Point Vehicle Collision Detection

Seed: 0x004ea970  |  System: docs/10-vehicle-physics.md  |  Depth: 1  |  Functions: 8

---

## Overview

Called from renderer/effect dispatch (0x004e9620) during physics step. Implements 13-point collision detection between vehicles: transforms collision points by orientation matrix, tests wheel-by-wheel overlap with all other vehicles, computes distance-based repulsion, applies collision response (friction, restitution), reports contacts, and calculates damage. All 8 callees are leaf helpers.

## Call Tree

```
0x004ea970 — Collision Detection System  [trigger: per-frame physics collision pass]
  +-- 0x0054fa90 — contact getter
  +-- 0x004ea010 — [undocumented collision helper]
  +-- 0x00410b80 — [undocumented physics helper]
  +-- 0x00547390 — [undocumented physics helper]
  +-- 0x004ed420 — damage calculation
  +-- 0x005694e0 — [undocumented math util]
  +-- 0x0041ad80 — penalty/contact reporting
  +-- 0x0054fae0 — [undocumented]
```

## Step-by-Step Trace

### Level 0: 0x004ea970 — Collision Detection System

**Trigger:** Called per physics frame from effect dispatch (0x004e9620)
**Called by:** 0x004e9620 (renderer/effect dispatch, docs/19-renderer.md)
**Purpose:** 13-point collision detection with wheel overlap and response

**Key actions:**
1. Iterates 13 collision points, transforms by orientation matrix
2. Checks all other vehicles via wheel-by-wheel overlap test
3. Computes distance-based repulsion with normalized vector
4. Applies collision response: relative velocity, friction, restitution
5. Calls 0x0041ad80 for penalty/contact reporting
6. Calls 0x004ed420 for damage calculation

**Data passed to callees:** vehicle struct pointers, collision point data, contact manifold

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x004ea970 | 13 collision points | Transform by matrix | world-space points |
| 0x004ea970 | all vehicles | Wheel overlap test | contact pairs |
| 0x004ea970 | contact pairs | Repulsion + response | collision forces |
| 0x004ed420 | impact data | Damage calc | damage values |
| 0x0041ad80 | contact data | Penalty report | steward notification |

## Globals Written in This Chain

None — collision forces applied to vehicle physics structs

## Notes

- All 8 callees are leaf functions
- Collision response is distance-based with restitution model
- Damage calculation (0x004ed420) feeds into engine wear/failure system
---
