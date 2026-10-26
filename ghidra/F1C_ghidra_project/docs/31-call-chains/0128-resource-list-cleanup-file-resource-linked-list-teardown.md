# Chain: Resource List Cleanup — File Resource Linked-List Teardown

Seed: FUN_00404d50  |  System: docs/08-file-formats.md  |  Depth: 2  |  Functions: 10

---

## Overview

Clears a resource linked list and enumerates directory entries for cleanup. Called during resource manager shutdown or reset. Frees each linked-list node, resets head/tail pointers, then enumerates directory entries and processes each through registration callback.

## Call Tree

```
FUN_00404d50 — Resource List Cleanup  [trigger: resource manager reset/shutdown]
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [heap deallocation per node]
  |     +-- FUN_0058aa6f — heap deallocation
  +-- FUN_00565dc0 — Allocate Struct with Default Values  [dir enum init]
  +-- FUN_00565f80 [undocumented — dir enum step]
  +-- FUN_00565f50 — Linked List Pop Front  [pop next file entry]
  +-- FUN_005662d0 — Directory Entry Iterator  [iterates dir entries]
  +-- FUN_00565f20 — Linked List Node Peek  [peek next entry]
  +-- FUN_00565e20 — Linked-List Destructor with Child Cleanup  [tears down dir list]
  |     +-- FUN_00587bcf — Free Wrapper
  |     +-- FUN_00566650 — String Copy with Buffer Realloc
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_00404e60 — Linked-List Node Insertion  [registers entry name]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc
```

## Key Actions

1. Sets +0x24 byte flag
2. If flag non-zero: walks linked list at +0x40, frees each element via FUN_00587bcf
3. Resets head/tail pointers to NULL
4. Calls filesystem enumeration (FUN_00565dc0, FUN_005662d0, FUN_00565f20)
5. Processes each entry name via FUN_00404e60 (registration/insertion)

## Notes

- 8 direct callees, 2 with sub-callees (depth 2)
- Linked-list node structure at +0x40: typical {data, next, prev}
- Uses file system directory enumeration APIs (Win32 FindFirst/FindNext wrappers)
- FUN_00587bcf (free) called for each node in the list

---
