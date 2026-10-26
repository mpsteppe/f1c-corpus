## ListIterationWithVTableDispatch_00498fb0 — Dual-list virtual method dispatch at 0x74

**Summary:** Iterates two linked lists, calling virtual method at vtable offset 0x74 on each node. Paired with LinkedListIterationVirtualCall_00498f80 (identical structure, different vtable slot). Part of render dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_7890 (00497890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x94)+0x0) | 0x74 | R | — | vtable slot 0x74 of interface at this+0x94; method dispatched per node |
| *(this+0x4C) | 0x74 | R | — | first-list head; vtable call uses offset 0x74 |
| *(this+0x94) | 0x0 | R | — | vtable pointer of struct at this+0x94 |
| this | 0x4C | R | — | first linked list head pointer |
| this | 0x50 | R | — | pointer to sub-container with second list |
| this | 0x94 | R | — | pointer to object providing dispatch vtable |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | returns next linked list node (traversal link) |

**Guard conditions:** none — always iterates both linked lists unconditionally
