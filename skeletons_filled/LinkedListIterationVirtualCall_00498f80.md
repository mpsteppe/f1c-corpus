## LinkedListIterationVirtualCall_00498f80 — Dual-list virtual method dispatch

**Summary:** Iterates two linked lists of polymorphic objects, calling virtual method at vtable offset 0x70 (render/draw) on each node. Part of a render dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_7890 (00497890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x94)+0x0) | 0x70 | R | — | vtable slot of interface at this+0x94; method index 0x70 dispatched per node |
| *(this+0x4C) | 0x70 | R | — | first-list head pointer read; vtable call uses same offset |
| *(this+0x94) | 0x0 | R | — | first field of struct at this+0x94 — vtable pointer for dispatch |
| this | 0x4C | R | — | first linked list head pointer |
| this | 0x50 | R | — | pointer to sub-container that holds second linked list |
| this | 0x94 | R | — | pointer to object whose vtable provides dispatch offset 0x70 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | returns next node in linked list (traversal link) |

**Guard conditions:** none — always iterates both linked lists unconditionally
