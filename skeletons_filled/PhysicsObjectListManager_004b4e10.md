## PhysicsObjectListManager_004b4e10 — PhysicsObjectListDrainToFreePool

**Summary:** Drains all 4 collision object sub-lists: removes each node, frees type-1 buffers, reallocates node as free list entry and prepends to global free pool. Stores session time at offset 0x6C, resets sub-list metadata, sets enable flag to 1. Called from QuadrupleListCleanup and PitstopActionSet.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** QuadrupleListCleanup (004b46f0), PitstopActionSet (004b6940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x70) | 0x0 | R | — | Sub-list 0 head pointer (traversed to drain) |
| *(this+0x70) | 0x4 | RW | — | Sub-list 0 tail pointer (cleared during drain) |
| *(this+0x70) | 0x8 | R | — | Sub-list 0 anchor pointer (used for traversal) |
| *(this+0x70) | 0xC | R | — | Sub-list 0 count (decremented per node removed) |
| this | 0x0 | RW | 1 | Enable flag — set to 1 at end |
| this | 0x35 | RW | 0 | Metadata byte — zeroed during sub-list reset |
| this | 0x39 | RW | 0 | Metadata byte — zeroed during sub-list reset |
| this | 0x3D | RW | 0 | Metadata byte — zeroed during sub-list reset |
| this | 0x41 | RW | 0 | Metadata byte — zeroed during sub-list reset |
| this | 0x6C | RW | — | Session timestamp — set from dbl_8AFEA0 |
| this | 0x70 | RW | — | Sub-list 0 head pointer (zeroed during reset) |
| this | 0x74 | RW | — | Sub-list 1 head pointer (zeroed during reset) |
| this | 0x78 | RW | — | Sub-list 2 head pointer (zeroed during reset) |
| this | 0x7C | R | — | Sub-list 0 count (read but not zeroed) |

**Written-by note (persistence):**
- *(this+0x70) 0x4: cleared during drain (tail zeroed)
- this 0x0: set to 1 at end of function
- this 0x35, 0x39, 0x3D, 0x41: zeroed during metadata reset
- this 0x6C: written with session time
- this 0x70, 0x74, 0x78: zeroed during sub-list reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab700 | dword_8AB700 | RW | FreeListHead — new free nodes prepended here |
| 008ab704 | dword_8AB704 | W | FreeListTailPtr — set if list was empty |
| 008ab708 | dword_8AB708 | W | GlobalAllocPoolNode — set if list was empty |
| 008ab70c | dword_8AB70C | RW | FreeNodeCount — incremented per node recycled |
| 008afea0 | dbl_8AFEA0 | R | SessionTime — stored at this+0x6C |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bac20 | ShortComputation_ac20 | Allocate/initialize new free list node buffer |
| 00587bcf | FreeWrapper_7bcf | Free removed node's data buffer (if type-1) and node struct |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new 12-byte node struct for free list |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x70 | == | 0 | Sub-list 0 head — if null, inner drain loop skipped for that list |

**Guard interpretation:** Each sub-list is processed unconditionally (4 iterations). If sub-list head at 0x70 is null (empty list), the inner drain loop for that list is skipped. Non-null lists are fully drained: all nodes removed, buffers freed (type-1), node structs freed and replaced with free list entries.
