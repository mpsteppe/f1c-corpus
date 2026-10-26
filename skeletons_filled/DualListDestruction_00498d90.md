## DualListDestruction_00498d90 — Dual Linked List Destruction

**Summary:** Iterates two linked lists and calls the virtual destructor (vtable[0] with arg 1) on each node, then returns the result of a final cleanup computation. Restores the vtable pointer at start.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FAILWRONGTRIAGE_8d70 (00498d70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x48) | 0x0 | R | — | Vtable pointer of first linked list node (called as destructor) |
| *(this+0x90) | 0x48 | R | — | Traversal field (next pointer) of second linked list node |
| this | 0x0 | RW | — | Vtable pointer of this object (restored to off_5AC9E8 at start) |
| this | 0x48 | RW | — | Head pointer of first linked list (iterated and consumed during destruction) |

**Written-by note (persistence):**
- this 0x0: Vtable restored at start for safe virtual call dispatch during destruction
- this 0x48: Updated as first list is traversed during destruction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac9e8 | off_5AC9E8 | R | Vtable restored to this for safe virtual destruction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | Gets next node pointer from current node in second linked list (traversal) |
| 00498f60 | ShortComputation_8f60 | Gets head of second linked list for iteration |

**Guard conditions:**
- First loop: `this[18] != 0` → continue iterating; loop ends when chain is exhausted (node's next pointer is 0)
- Second loop: `ShortComputation_8f60(this) != 0` → start iterating second list; loop continues via `StructFieldAccessor` until it returns 0
- Both loops check `v3 != NULL` / `v5 != NULL` before calling virtual destructor (safe guard)
