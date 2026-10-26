# Chain: Render Dispatch with Iteration — Surface Rendering Pipeline

Seed: 0x004993d0  |  System: docs/19-renderer.md  |  Depth: 3  |  Functions: 8

---

## Overview

Render dispatch that iterates render nodes, sets up render target, transforms coordinates, and dispatches draw calls. Triggered per-frame during render pass when a render target is active. Output: rendered surface with all draw items committed.

## Call Tree

```
0x004993d0 — Render Dispatch with Iteration  [trigger: per-frame render pass]
  +-- 0x00491300 — Multi-Short Struct Writer  [sets up render area, leaf]
  +-- 0x00490920 — Accessor  [flush, 1 sub-call]
  |     +-- 0x004906e0 — Custom Memory Pool Allocator Init  [docs/21]
  +-- 0x00491cf0 — LinkedList: Follow +0x1c Pointer  [iterates render item list, leaf]
  +-- 0x00495150 — Global Accessor  [compute coord transform, leaf]
  +-- 0x00494a30 — 10-Param Forwarder  [dispatch, 1 sub-call]
  |     +-- 0x00543250 — Clipped Render Region  [docs/19, 2 sub-calls]
  +-- 0x00491d10 — Linked List Field Reader  [secondary list iterator, leaf]
  +-- 0x004b0170 — Empty Stub (vtable slot)  [cleanup, leaf]
  +-- 0x00486320 — Struct Field Accessor (+0x8C)  [post-render accessor, leaf]
```

## Step-by-Step Trace

### Level 0: 0x004993d0 — Render Dispatch with Iteration

**Trigger:** Per-frame render pass, called when render target is active.
**Called by:** 0x00498fe0 via FUN_00486320 iterator (indirect).
**Purpose:** Render dispatch — iterates render nodes, performs surface operations.

**Key actions:**
1. Checks param_1[0x13] (render target) — null check gate
2. If non-null: sets up render area via FUN_00491300
3. Flushes pipeline via FUN_00490920
4. Iterates render item list via FUN_00491cf0
5. For each: transforms coordinates, checks positive dimensions, calls FUN_00495150 (compute) + FUN_00494a30 (dispatch)
6. Iterates secondary list calling vtable+0x44 on each
7. Calls FUN_004b0170 cleanup

**Data passed to callees:** Render context pointer, render target handle, coordinate data.

### Level 1: Key Sub-functions

**0x00490920 — Accessor**
Flushes render state. Calls FUN_004906e0 (memory pool allocator init) for temporary allocations.

**0x00494a30 — 10-Param Forwarder**
Dispatches to clipped render region. Forwards coordinates to FUN_00543250 for actual draw.

**0x00543250 — Clipped Render Region**
2 sub-calls. Sets up clipped render region in D3D. Handles viewport clipping, scissor rect setup.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004993d0 | render ctx, target | check target | render path |
| FUN_00491300 | render target | setup area | area configured |
| FUN_00490920 | render ctx | flush | pipeline flushed |
| FUN_00491cf0 | render ctx | iterate list | render items |
| FUN_00494a30 | coords, ctx | dispatch to D3D | draw calls submitted |

## Globals Written in This Chain

None documented — all data passed through render context pointers and D3D handles.

## Notes

Chain spans docs/19-renderer.md (primary) and docs/21-audio-network-internals.md (memory pool). The secondary list iteration suggests two types of render items (possibly 2D UI over 3D scene). The stub at 0x004b0170 indicates a virtual dispatch/vtable cleanup slot.

---
