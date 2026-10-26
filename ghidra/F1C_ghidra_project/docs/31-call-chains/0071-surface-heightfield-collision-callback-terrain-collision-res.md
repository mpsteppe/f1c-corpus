# Chain: Surface Heightfield Collision Callback — Terrain Collision Response

Seed: FUN_00404250  |  System: docs/18-physics-dynamics.md  |  Depth: 2  |  Functions: 6 callees

---

## Overview

FUN_00404250 is a collision callback for terrain surface heightfield queries. Not called by any known function (0 callers in callers.json — likely invoked via function pointer/callback mechanism). Computes gravity-corrected contact force from DAT_0059e43c minus track grip (DAT_008afee8 + DAT_008afeec), propagates force to all physics nodes via FUN_004fb260, calls physics pipeline (FUN_004faf60 — AI relative positioning, FUN_004047d0 — element update, FUN_004046b0 — waypoint processing, FUN_00404790 — short computation), and queries terrain surface for each node via FUN_004038e0 (spatial nearest-neighbor with plane test). Reads surface friction properties from material pointer (offset +0x43 -> +0x124), blends between two materials if on boundary, stores material index at +0x4a.

## Call Tree

```
FUN_00404250 — Surface Heightfield Collision Callback  [trigger: collision callback]
  +-- FUN_004fb260 — Linear Interpolation + Position Update  [force propagation]
  +-- FUN_004faf60 — AI Opponent Relative Positioning  [physics pipeline step 1]
  +-- FUN_004047d0 — Counted Loop Call to Element Update  [element update]
  +-- FUN_004046b0 — Waypoint-Like Struct Processing  [waypoint processing]
  +-- FUN_00404790 — Short Computation  [computation utility]
  +-- FUN_004038e0 — Spatial Nearest-Neighbor Query  [terrain surface query per node]
```

## Step-by-Step Trace

### Level 0: FUN_00404250 — Surface Heightfield Collision Callback

**Trigger:** Collision system callback — invoked during terrain collision pass
**Called by:** Unknown (0 callers in graph — likely function pointer/callback)
**Purpose:** Compute terrain surface contact response and propagate to physics nodes

**Key actions:**
1. Computes gravity-corrected contact force from DAT_0059e43c minus grip (DAT_008afee8 + DAT_008afeec)
2. Propagates force to all physics nodes via FUN_004fb260
3. For each physics node: queries terrain surface via FUN_004038e0
4. Reads surface friction properties from material pointer (offset +0x43 -> +0x124)
5. Blends between two materials if on boundary
6. Stores material index at +0x4a

### Level 1: Key Callees

**FUN_004fb260 — Linear Interpolation + Position Update**
- Performs linear interpolation and updates node positions
- Propagates the contact force through the physics node tree

**FUN_004038e0 — Spatial Nearest-Neighbor Query with Plane Test**
- Finds nearest surface element for a given 3D position
- Uses spatial tree with plane-based culling
- Reads node position at +0x94/0x98/0x9c and normal at +0xa4/+0xac

**FUN_004faf60 — AI Opponent Relative Positioning**
- Computes relative positions between vehicles
- Part of the physics pipeline step sequence

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Force | DAT_0059e43c - grip | Gravity correction | Contact force |
| Propagation | Contact force | FUN_004fb260 | Node force update |
| Surface query | Node position | FUN_004038e0 | Terrain surface data |
| Material | Pointer +0x43 | Read +0x124 | Friction properties |
| Blend | Two materials | Boundary test | Blended material |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008afee8 | TrackGripValue | (read by) | Track grip for force calc |
| DAT_008afeec | TrackGripComparison | (read by) | Grip comparison value |
| DAT_0059e43c | PhysicsConstant1 | (read by) | Gravity reference |

## Notes

- Zero callers in call graph — invoked via function pointer table, not direct call
- Material blending occurs when vehicle is on boundary between two surfaces
- 6 physics pipeline callees called in sequence for each node
- FUN_004038e0 is a spatial query shared with AI path following (Chain 62)

---
