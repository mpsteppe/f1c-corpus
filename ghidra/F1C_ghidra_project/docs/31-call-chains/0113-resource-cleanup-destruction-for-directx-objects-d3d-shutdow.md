# Chain: Resource Cleanup/Destruction for DirectX Objects — D3D Shutdown

Seed: 0x00543bf0  |  System: docs/19-renderer.md  |  Depth: 3  |  Functions: 12

---

## Overview

Resource Cleanup is the DirectX 8 resource destruction cascade, called during device shutdown or game exit. No callers documented — likely invoked directly from D3D manager destructor. It enumerates and destroys all resource types: texture/surface nodes, vertex/index buffers, shader objects, child scene graph resources, and backing memory. The chain is a linear teardown where each callee handles a specific resource category.

## Call Tree

```
FUN_00543bf0 — Resource Cleanup/Destruction for DirectX Objects  [trigger: D3D shutdown]
  +-- FUN_00544ef0 — Scene Graph Tree Destructor
  |     +-- FUN_004b0170 — Empty Stub (vtable slot)  [leaf]
  |     +-- FUN_00545090 — Doubly-Linked List Node Removal  [leaf]
  |     +-- FUN_00557470 — Empty Stub  [leaf]
  |     +-- FUN_00587bcf — Free Wrapper  [memory free]
  +-- FUN_0054a240 — Destroy + Free  [leaf]
  +-- FUN_00545150 — 3D Sound Source Destructor
  |     +-- FUN_0054a770 — Scene Graph / Object Tree Cleanup
  |     +-- FUN_00560e50 — Multi-Field Object Destructor with Cleanup
  |     +-- FUN_005459d0 — LinkedListRemove  [leaf]
  |     +-- FUN_00587bcf — Free Wrapper  [memory free]
  |     +-- FUN_005452b0 — LinkedListRemove  [leaf]
  +-- FUN_005487e0 — Linked-List Walk with Exit Check
  |     +-- FUN_005469c0 — Decrement resource ref, release when zero
  +-- FUN_00544af0 — Audio/Network Stream Cleanup
  |     +-- 5 callees: node removal, buffer free, resource release
  +-- FUN_005454a0 — Destructor with Conditional Free
  |     +-- FUN_005455f0 — DoublyLinkedListRemove  [leaf]
  |     +-- FUN_0055d2e0 — Clear Byte Flag, Return 0  [leaf]
  |     +-- FUN_00557470 — Empty Stub  [leaf]
  |     +-- FUN_00587bcf — Free Wrapper  [memory free]
  +-- FUN_00560b30 — Conditional Free of Struct Field
  |     +-- FUN_00587bcf — Free Wrapper  [memory free]
  +-- FUN_00557280 — Cleanup Function (Free + Destructor)
  |     +-- FUN_00587bcf — Free Wrapper  [memory free]
  |     +-- FUN_004b0170 — Empty Stub (vtable slot)  [leaf]
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [memory free]
  +-- FUN_005519e0 — Doubly-Linked List Node Removal
  |     +-- FUN_00550ac0 — Calls FUN_00550f70, returns 0  [leaf]
  |     +-- FUN_00557470 — Empty Stub  [leaf]
  |     +-- FUN_00587bcf — Free Wrapper  [memory free]
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [leaf]
  +-- FUN_005593d0 — [data at 0x005593d0]  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00543bf0 — Resource Cleanup

**Trigger:** D3D device shutdown or game exit
**Called by:** No callers documented (likely from D3D manager destructor)
**Purpose:** Destroys DirectX resources: textures, surfaces, vertex buffers, shaders, allocations.

**Key actions:**
1. Calls FUN_00544ef0 — destroy scene graph tree (recursive node removal)
2. Calls FUN_0054a240 — destroy + free (leaf — likely base resource cleanup)
3. Calls FUN_00545150 — 3D sound source destructor (cross-system to audio)
4. Calls FUN_005487e0 — walk resource linked list with exit check
5. Calls FUN_00544af0 — audio/network stream cleanup
6. Calls FUN_005454a0 — destructor with conditional free
7. Calls FUN_00560b30 — conditional free of struct field
8. Calls FUN_00557280 — cleanup function (free + destructor)
9. Calls FUN_00587bcf — memory deallocation wrapper
10. Calls FUN_005519e0 — doubly-linked list node removal
11. Calls FUN_004b0170 — stub (vtable slot — COM-style Release)
12. Calls FUN_005593d0 — final cleanup stub

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Resource Cleanup | resource pointers | scene graph destructor | freed nodes |
| Resource Cleanup | sound source handles | 3D sound destructor | released audio |
| Resource Cleanup | vertex/index buffers | conditional free | released D3D buffers |
| Resource Cleanup | shader objects | free + destructor | released shaders |
| Resource Cleanup | all | memory deallocation | freed backing memory |

## Globals Written in This Chain

None directly — operates on resource handles passed through param chain.

## Notes

- FUN_00587bcf (Free Wrapper) appears 7 times across the cleanup chain — central memory deallocation thunk
- Cross-system handoffs: FUN_00545150 (3D sound), FUN_00544af0 (audio/network stream)
- FUN_004b0170 appears 3 times — COM-style stub for interface release
- Ordering matter: scene graph destroyed first, then buffers, then shaders, then memory

---
