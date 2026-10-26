# Chain: Collision Geometry Operation Selector — Multi-Phase Collision Pipeline Dispatch

Seed: FUN_0044bb60  |  System: docs/17-physics-collision.md  |  Depth: 4  |  Functions: 6

---

## Overview

Dispatches a multi-phase collision/geometry pipeline based on operation type (param_1=0,1,2). Reads global geometry handle DAT_008afe88; if 0, skips to finalize. Operations: 0=transform only, 1=transform+update+finalize, 2=full pipeline (push→transform→update→apply→pop→finalize). Each phase calls dedicated sub-functions: geometry transform (FUN_0044acb0), contact response update (FUN_00449700), sweep-and-prune AABB detection (FUN_004497e0), matrix stack ops (FUN_004492b0 push, FUN_00449340 pop, FUN_0044b370 apply).

## Call Tree

```
FUN_0044bb60 — Collision Geometry Operation Selector  [dispatches collision pipeline phase]
  |
  +-- FUN_0044acb0 — Geometry Transform  [docs/19-renderer: animation playback sequence]
  |     +-- [11 sub-callees including FUN_005452f0, FUN_00545340, FUN_0054c210, 
  |          FUN_0054c230, FUN_0054e190, FUN_0054e240, FUN_00547370, 
  |          FUN_004ce860, FUN_004ce8d0, FUN_004dd9f0, FUN_0044aae0]
  |     +-- FUN_0044aae0 — Recursive Triangle Edge Subdivision for Collision  [docs/17]
  |           +-- FUN_004484c0 — Vec3Subtract
  |           +-- FUN_004484f0 — Empty Function
  |           +-- FUN_00448480 — Weighted Average Interpolation
  |           +-- FUN_004493a0 — Resizable Container
  |
  +-- FUN_00449700 — Collision Contact Response  [docs/18: update contact forces]
  |     +-- FUN_00448da0 — CollisionTreeTraversal  [docs/17]
  |     +-- FUN_00448de0 — Physics Tree Mass Propagation  [docs/18]
  |     +-- FUN_00448480 — Weighted Average Interpolation  [apply contact impulse]
  |
  +-- FUN_004497e0 — Sweep-and-Prune AABB Overlap Detection  [docs/17: finalize]
  |     +-- FUN_005890aa — Sort  [docs/20]
  |     +-- FUN_004491c0 — SATEdgeSeparationTest  [docs/17]
  |     |     +-- FUN_00448f00 — Triangle Edge Half-Plane Computation
  |     |     +-- FUN_00448fc0 — SAT Separating Axis Test
  |     |     +-- FUN_00449000 — 2D Line Segment Intersection
  |     +-- FUN_00587bcf — Free Wrapper  [heap free]
  |
  +-- FUN_004492b0 — CollisionShapeInit (Push Matrix)  [docs/18: matrix stack push]
  |     +-- FUN_00449340 — PhysicsBufferFree (shape sub-init)
  |
  +-- FUN_0044b370 — Bezier Patch Tessellation (Apply Matrix)  [docs/19: matrix application]
  |     +-- [12 sub-callees including FUN_004492b0, FUN_004492d0, FUN_004493a0,
  |          FUN_00448ee0, FUN_00449340, FUN_00449700, FUN_0044b110,
  |          FUN_0044b040, FUN_0044af20, FUN_0044af60, FUN_00449a80, FUN_00587bcf]
  |
  +-- FUN_00449340 — PhysicsBufferFree (Pop Matrix)  [docs/18: matrix stack pop]
        +-- FUN_00587bcf — Free Wrapper  [heap free]
        +-- FUN_00448570 — PhysicsSubComponentDestroy  [docs/17: pre-free cleanup]
```

## Step-by-Step Trace

### Level 0: FUN_0044bb60 — Collision Geometry Operation Selector

**Trigger:** Called from collision pipeline to process geometry operations
**Called by:** No callers in call_graph.json (likely called via dispatch from collision update loop)
**Purpose:** Dispatches collision/geometry operations on global geometry handle DAT_008afe88.

**Key actions:**
1. Reads DAT_008afe88 (global collision geometry handle)
2. If handle == 0: calls FUN_004497e0 (finalize only), returns
3. param_1 == 0: FUN_0044acb0 (transform only)
4. param_1 == 1: FUN_0044acb0 + FUN_00449700 + FUN_004497e0
5. param_1 == 2: push + transform + update + apply + pop + finalize (full pipeline)

**Globals read:** DAT_008afe88 (CollisionGeometryHandle)

### Level 1: Geometry Transform (FUN_0044acb0)

**FUN_0044acb0 — Geometry Transform / Animation Playback Sequence** [docs/19-renderer.md]
- 11 sub-callees:
  - FUN_005452f0 — Audio/Network Node Count
  - FUN_00545340 — LinkedListNodeFinder
  - FUN_0054c210 — Scene Graph Child Count
  - FUN_0054c230 — Linked List Indexed Accessor
  - FUN_0054e190 — Camera Distance Getter
  - FUN_0054e240 — Array Index Read
  - FUN_00547370 — String Copy with Offset
  - FUN_004ce860 — String List Lookup (string table traversal)
  - FUN_004ce8d0 — Indexed Pointer Accessor (stride 0x6c)
  - FUN_004dd9f0 — Unidentified logic
  - FUN_0044aae0 — Recursive Triangle Edge Subdivision (3+ sub-callees)

### Level 1: Contact Response (FUN_00449700)

**FUN_00449700 — Collision Contact Response** [docs/18-physics-dynamics.md]
- FUN_00448da0 — CollisionTreeTraversal (docs/17)
- FUN_00448de0 — Physics Tree Mass Propagation (docs/18)
- FUN_00448480 — Weighted Average Interpolation (applies contact impulse)

### Level 1: Sweep-and-Prune (FUN_004497e0)

**FUN_004497e0 — Sweep-and-Prune AABB Overlap Detection** [docs/17-physics-collision.md]
- FUN_005890aa — Sort routine (docs/20)
- FUN_004491c0 — SAT Edge Separation Test (docs/17)
  - FUN_00448f00: Triangle Edge Half-Plane Computation
  - FUN_00448fc0: SAT Separating Axis Test
  - FUN_00449000: 2D Line Segment Intersection
- FUN_00587bcf — Free Wrapper

### Level 1: Matrix Stack (FUN_0044b370)

**FUN_0044b370 — Bezier Patch Tessellation / Apply Matrix** [docs/19-renderer.md]
- 12 sub-callees including shape ops (push/pop/alloc), color packing, SAT face gather, Gaussian elimination for HAT polygon surface fit

## Globals Read

| Global | Name | Read by |
|--------|------|---------|
| DAT_008afe88 | CollisionGeometryHandle | FUN_0044bb60 |

## Notes

- This is the central dispatch for the collision geometry pipeline
- Cross-system: docs/17-collision → docs/19-renderer (FUN_0044acb0, FUN_0044b370), docs/18-dynamics (FUN_00449700, FUN_004492b0, FUN_00449340)
- Full pipeline (mode 2) processes 6 stages: push→transform→update→apply→pop→finalize
- FUN_0044b370 (Bezier tessellation) has 12 sub-callees — the deepest subtree

---
