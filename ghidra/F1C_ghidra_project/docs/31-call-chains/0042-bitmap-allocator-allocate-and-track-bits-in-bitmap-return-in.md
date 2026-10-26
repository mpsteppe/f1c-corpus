# Chain 41: Bitmap Allocator — Allocate and track bits in bitmap, return index

Seed: FUN_0059b5c0  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 6 callees

---

## Overview

Memory/bitmap allocation utility. Allocates a range of bits in a bitmap, clears them, and returns the starting index. Uses linked-list destruction and free routines for cleanup. Called by renderer with D3DRS state pairs.

## Call Tree

```
FUN_0059b5c0 — Bitmap Allocator  [trigger: bitmap allocation request]
  +-- FUN_00581b30 — [undocumented]  [bitmap operation]
  +-- FUN_00583570 — List Destruction with COM Release  [cleanup list]
  |     +-- FUN_00587bcf — Free Wrapper  [free]
  |     +-- 2 additional leaf callees omitted
  +-- FUN_00586070 — [undocumented]  [utility]
  +-- FUN_00581880 — Linked List Destruction with VTable Release Call  [list cleanup]
  |     +-- FUN_00587bcf — Free Wrapper  [free]
  |     +-- 1 additional leaf callee omitted
  +-- FUN_00598c70 — Null Check with Virtual Dispatch  [vtable dispatch]
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [free memory]
```

## Step-by-Step Trace

### Level 0: FUN_0059b5c0 — Bitmap Allocator

**Trigger:** Bitmap allocation from renderer (D3DRS state pairs).
**Called by:** FUN_00586700 (D3DRS set state — first arg = D3DRS enum, docs/19).
**Purpose:** Allocates and tracks a range of bits in a bitmap; clears bits and returns index.

**Key actions:**
1. Clears target bits in bitmap
2. Returns allocated bit index
3. Cleanup path uses FUN_00583570, FUN_00581880 for list destruction

### Level 1: Key callees

**FUN_00583570 — List Destruction with COM Release** — Walks linked list and releases COM objects via vtable. Calls FUN_00587bcf for free.

**FUN_00581880 — Linked List Destruction with VTable Release Call** — Similar destruction pattern with vtable dispatch. Calls FUN_00587bcf.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059b5c0 | Bitmap state | Clear + allocate bits | Bit index |
| FUN_00581b30 | Bitmap data | Bit manipulation | Updated bitmap |

## Globals Written in This Chain

None.

## Notes

- Called from renderer D3DRS state set with render state pairs: (1, +0x34), (8, +0x38), etc. (docs/19)
- FUN_00587bcf appears as cleanup handler throughout

---
