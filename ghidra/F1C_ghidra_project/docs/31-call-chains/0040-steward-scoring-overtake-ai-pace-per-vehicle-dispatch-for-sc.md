# Chain 39: Steward: Scoring/Overtake/AI Pace — Per-vehicle dispatch for scoring, physics, rendering

Seed: FUN_004cdb20  |  System: docs/06-session-race-logic.md  |  Depth: 2  |  Functions: 13 callees

---

## Overview

Triggered during steward update per frame. Dispatches per-vehicle scoring, AI pace, physics, and rendering operations across multiple case branches (0-0xD). Cases include 2D screen position computation for HUD, formation lap culling, pit limiter alpha rendering, physics constraint integration, and cleanup.

## Call Tree

```
FUN_004cdb20 — Steward: Scoring/Overtake/AI Pace  [trigger: steward per-frame update]
  +-- FUN_004b9ce0 — Delegation  [delegates to sub-handler]
  |     +-- FUN_004b8790 — sub-handler
  +-- FUN_004cb5a0 — Array Element Removal (Swap-Out)  [removes stale entries]
  +-- FUN_004c9c70 — FindDriversInRange  [finds nearby drivers]
  +-- FUN_004cbdd0 — Ray-Sphere Intersection  [proximity test]
  +-- FUN_004cbf50 — 3D AABB Overlap Test with Sliding Response  [collision check]
  +-- FUN_004ccb30 — Particle/Effect Physics  [updates particle effects]
  +-- FUN_0040c870 — Short Computation  [camera ptr lookup]
  +-- FUN_004cc500 — Particle/Effect Billboard Quad Setup  [renders billboards]
  +-- FUN_00558c60 — Texture Layer Flag Set  [sets texture flags]
  +-- FUN_00558cb0 — Array Element Flag Set with Bounds Check  [flags array]
  +-- FUN_00558cf0 — Bounds-Checked Array Write (0x80 stride)  [writes array]
  +-- FUN_00558dc0 — Pixel Attribute Write to Texture  [writes pixel data]
  +-- FUN_005881f0 — [PARTIAL] Unknown  [unidentified utility]
```

## Step-by-Step Trace

### Level 0: FUN_004cdb20 — Steward: Scoring/Overtake/AI Pace

**Trigger:** Per-frame steward update.
**Called by:** FUN_004cfcc0 (update particle — called from renderer particle system, docs/19).
**Purpose:** Dispatches per-vehicle scoring, AI pace, physics.

**Key actions:**
1. Cases 0-5: computes 2D screen position, alpha fade, renders name/distance HUD
2. Cases 6-7: formation lap culling
3. Case 8: pit limiter alpha with corona layers
4. Case 0xC: physics constraint, velocity integration
5. Case 0xD: cleanup

### Level 1: Key callees

**FUN_004ccb30 — Particle/Effect Physics** — Updates particle physics simulation. Leaf function.

**FUN_004cbf50 — 3D AABB Overlap Test with Sliding Response** — Collision overlap check with response. Leaf.

**FUN_004b9ce0 — Delegation** — Delegates to sub-handler FUN_004b8790. Simple wrapper.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004cdb20 | Vehicle array | Dispatch by case | Per-vehicle state updates |
| FUN_004c9c70 | Vehicle positions | Find nearby drivers | Driver list |
| FUN_004ccb30 | Particle data | Physics update | Updated particle state |
| FUN_004cc500 | Billboard data | Quad setup | Rendered billboard |

## Globals Written in This Chain

None directly.

## Notes

- Called from renderer particle system (FUN_004cfcc0, docs/19)
- Case dispatch includes both rendering (HUD, billboards) and physics (constraint solve)
- No moddability — internal steward logic

---
