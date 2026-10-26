# Chain: Z-Sorted Render Traversal — Scene Render Pass

Seed: 0x004b9000  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 15

---

## Overview

Z-Sorted Render Traversal is the core scene rendering entry point. Called with no documented callers (likely invoked directly from the main render loop), it performs a two-pass traversal of a Z-ordered render object linked list: opaque pass first, then transparent pass. Each pass iterates render nodes, performs occlusion testing, sets up render state, issues draw calls, and manages sub-element rendering for both opaque and alpha-blend materials. The chain covers visibility computation, occlusion culling, mesh drawing, state management, and post-processing.

## Call Tree

```
FUN_004b9000 — Z-Sorted Render Traversal  [trigger: per-frame scene render]
  +-- FUN_004b72a0 — Linked List Traversal with Filter  [visibility test per object]
  |     +-- FUN_004b50c0 — [general utility — leaf]
  +-- FUN_005001d0 — FieldCompareConstant  [occlusion test 1 — leaf]
  +-- FUN_005001f0 — Float Comparison Check  [occlusion test 2 — leaf]
  +-- thunk_FUN_00500170 — Short Computation  [ray cast? — leaf]
  +-- FUN_004b5380 — Linked list compare floats  [Z-buffer clear? — leaf]
  +-- FUN_00566db0 — State Check + Lookup Wrapper  [mesh draw]
  |     +-- FUN_00535390 — Audio/Stream Buffer Read  [leaf]
  |     +-- FUN_00587f64 — String Format Wrapper  [leaf]
  +-- FUN_004b4450 — Wrapper + Pass-Through  [setup state]
  |     +-- FUN_004b4460 — Small Struct Zero-Init  [leaf]
  +-- FUN_004b44a0 — File Operation Open + Write  [submit draw]
  |     +-- FUN_00566e20 — Resource Lookup Dispatcher
  |     +-- FUN_00566c00 — File Write with Backend Dispatch
  +-- FUN_004b4360 — Read, conditionally scale  [visibility query — leaf]
  +-- FUN_004b54e0 — Network Message Dispatch  [transparent draw]
  +-- FUN_004fffb0 — Zone/Threshold Comparison  [culled draw — leaf]
  +-- FUN_004b5460 — List Walk with User Cancel Check  [completion check opaque — leaf]
  +-- FUN_004b54a0 — Linked-List Validation Walk  [completion check transparent — leaf]
  +-- FUN_004b5630 — Collision Filter/AABB Cull  [background]
  +-- FUN_004b5760 — Linked List Iterator with State Update  [post-processing — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004b9000 — Z-Sorted Render Traversal

**Trigger:** Per-frame scene render, invoked from main render loop
**Called by:** No callers documented (likely called directly from render pipeline)
**Purpose:** Traverses Z-ordered linked list of renderable objects, calls draw for each visible mesh at current depth.

**Key actions:**
1. Pre-computes visibility array (104 entries) via FUN_004b72a0(param_2) where param_2 is current Z/depth value
2. Filters objects below ground or occluded via FUN_005001d0/FUN_005001f0
3. Manages cursor pointer at param_1+0x71c through doubly-linked list (head=+0x714, tail=+0x718)
4. Computes cursor index (count from head)
5. **Opaque pass** — for each node: draw call (FUN_00566db0), state setup (FUN_004b4450), submit draw (FUN_004b44a0)
6. For sub-elements: visibility query (FUN_004b4360), checks category 0x20000000 → dispatch sub-type 0 (culled, FUN_004fffb0) or 1-6 (transparent, FUN_004b54e0)
7. Checks completion via FUN_004b5460(), advances cursor, max 64 iterations
8. **Transparent pass** — resets cursor, same loop with different occlusion checks (FUN_005001f0/FUN_004b54a0)
9. Calls background (FUN_004b5630) and post-processing (FUN_004b5760)

**Data passed to callees:** render node pointers, Z/depth value, visibility array

### Level 1: FUN_004b72a0 — Linked List Traversal with Filter

**Trigger:** Called per-object to determine visibility
**Purpose:** Tests visibility of a render object at given depth
**Key actions:** Iterates linked list comparing against Z threshold, calls FUN_004b50c0

### Level 1: FUN_00566db0 — Mesh Draw

**Trigger:** Called per render node during opaque pass
**Purpose:** Dispatches mesh draw call
**Key actions:** State check then delegates to FUN_00535390 (audio/stream buffer read — possibly for animated textures) and FUN_00587f64 (string format wrapper)

### Level 1: FUN_004b5630 — Collision Filter/AABB Cull

**Trigger:** Called at end of render traversal for background
**Purpose:** Background/sky rendering with AABB culling

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Z-Sorted Traversal | param_2 (Z depth) | visibility computation | visibility array |
| Z-Sorted Traversal | param_1+0x714 (list head) | cursor walk | current node |
| Z-Sorted Traversal | node sub-type | category check | opaque/transparent dispatch |
| Z-Sorted Traversal | completion signal | FUN_004b5460 check | loop exit |

## Globals Written in This Chain

None directly — operates on render struct param_1 and render node linked list.

## Notes

- FUN_004b4360 is in docs/20-math-utilities but handles visibility query in render context
- FUN_004b54e0 is in docs/21-audio-network-internals — this is likely a render-to-texture or overlay that routes through network/audio dispatch
- Two-pass design (opaque then transparent) is standard for correct alpha blending
- Max 64 iterations prevents infinite loop on corrupted linked list

---
