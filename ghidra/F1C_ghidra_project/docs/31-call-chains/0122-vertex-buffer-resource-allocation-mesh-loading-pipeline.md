# Chain: Vertex Buffer Resource Allocation — Mesh Loading Pipeline

Seed: FUN_00543fa0  |  System: docs/19-renderer.md  |  Depth: 3  |  Functions: 27

---

## Overview

Mesh loading pipeline that allocates vertex buffer arrays from parsed mesh component data. Triggered during scene/resource loading when a mesh with vertex attributes needs GPU-ready vertex buffers. Reads linked-list mesh component chain, decomposes material format flags into stride/type descriptors, allocates per-vertex data structures for 4 attribute types (position, normal, texcoord, color), and registers them with the resource system.

## Call Tree

```
FUN_00543fa0 — Vertex Buffer Resource Allocation  [trigger: mesh load with vertex attributes]
  +-- FUN_00548e00 — Short Computation / Object Constructor  [allocates 0x210-byte vertex struct]
  +-- FUN_0054bd30 — SceneGraphRenderWalk  [walks scene node tree for component chain]
  |     +-- FUN_00587bcf — Free Wrapper  [heap deallocation]
  +-- FUN_00544d30 — Audio/Network Tree Walker  [walks linked list at +0x100/+0x104/+0x108]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_00545f50 — Audio Volume/Load Computation  [reads flags at +0x9c]
  +-- FUN_005487a0 — Linked-List Walk + Interlocked Dec  [refcount management]
  |     +-- FUN_00587bcf — Free Wrapper
  |     +-- FUN_0053ced0 — Doubly-Linked List Node Removal
  +-- FUN_00548810 — Linked List Accumulation  [accumulates vertex count]
  +-- FUN_00544740 [undocumented]
  +-- FUN_00545a10 — UI LinkedList Cleanup Iterator  [iterates format descriptor chain]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_00545a40 — Visible Object List Collection  [collects visible mesh components]
  |     +-- FUN_00587bcf — Free Wrapper (×2)
  |     +-- FUN_0053c9c0 — Bit Flag Array Update
  +-- FUN_00545bb0 — Scene Instance Collection  [collects instances per vertex format type]
  |     +-- FUN_00587bcf — Free Wrapper (×2)
  |     +-- FUN_0053c9c0 — Bit Flag Array Update
  +-- FUN_00557280 — Cleanup Function (Free + Destructor)  [destructor for temp buffers]
  |     +-- FUN_00587bcf — Free Wrapper
  |     +-- FUN_00557240 — Init Struct + Call Loop
  +-- FUN_00557240 — Init Struct + Call Loop  [zero-init of output vertex buffers]
  |     +-- FUN_00587bcf — Free Wrapper (×2)
  +-- FUN_00548850 — Indexed Linked List Search  [searches format list by type]
  +-- FUN_00486720 — Short Computation (Field Getter at +0x84)  [reads mesh field]
  +-- FUN_005414e0 — Field 0x13B0 Accessor  [reads scene object field]
  +-- FUN_0053ced0 — Doubly-Linked List Node Removal by Flag  [node cleanup]
  +-- FUN_0053c9c0 — Bit Flag Array Update  [updates allocator flags]
  +-- FUN_00587bcf — Free Wrapper (×19)  [heap deallocation for temp allocs]
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [no-op]
```

## Key Actions

1. Allocates 0x210-byte vertex buffer descriptor structs per component
2. Walks mesh component linked list (next ptr at +0x104, +0x108)
3. Decomposes material format flags at +0x9c into attribute type (position=0x100000, normal=0x400000, texcoord=0x800000)
4. Allocates per-vertex data arrays with stride based on format type
5. Writes format descriptors to struct at +0x10 with stride 0x10 (16 sub-elements)
6. Calls operator_new for each vertex buffer, zero-initializes

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Mesh component chain | +0x100 linked list | Walk +0x104/0x108 next ptrs | component list |
| Material flags | +0x9c uint | Type switch (1-7) | attribute type |
| Vertex descriptors | format flags | Alloc 0x210-byte structs | per-vertex arrays |
| Buffer allocation | descriptor | operator_new + zero-init | GPU-ready vertex buffers |

## Globals Written

None identified — all memory is heap-allocated per call.

## Notes

- 19 callees total; most are leaf utilities (memory free, linked-list ops, bitfield ops)
- Major complexity is the format type switch (6 cases) and stride calculation
- FUN_00587bcf (free) is called ~19 times — this is a cleanup-heavy function
- Cross-system handoffs: docs/20-math-utilities.md (utility callees), docs/06-session-race-logic.md (tree walkers)

---
