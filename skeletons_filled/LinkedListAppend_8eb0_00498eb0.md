## LinkedListAppend_8eb0_00498eb0 — Linked List Append With Child Linking

**Summary:** Appends a node a2 to the linked list rooted at this+0x4C. Also iterates a2's child list (at a2+0x90 linked via offset 0x8C) and sets parent back-links. Increments node counter and calls a multi-region accumulation function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetInitCall (004975b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xD8)+0x8C) | 0x8C | RW | — | Next-pointer field in linked list nodes; used for traversal and append |
| this | 0x4 | R | — | First parameter passed to MultiRegionOffsetAccumulationWithVTableDispatch |
| this | 0xC | R | — | Third parameter passed to MultiRegionOffsetAccumulationWithVTableDispatch |
| this | 0x4C | RW | — | Head pointer of the linked list; set to a2 when list was empty |
| this | 0x5C | R | — | Node counter incremented on each append |
| this | 0xD8 | R | — | Pointer to an object whose linked list (via offset 0x8C) is traversed for the append |

**Written-by note (persistence):**
- *(*(this+0xD8)+0x8C) 0x8C: Updated during traversal; last node's next pointer set to a2. Persists until list restructured.
- this 0x4C: Written when node appended to empty list (becomes head); persists until all nodes removed.

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004869e0 | MultiRegionOffsetAccumulationWithVTableDispatch | Accumulates values across multiple offset regions with vtable dispatch using this[3] and this[1] |

**Guard conditions:**
- `this[19] == 0` → list empty: set head to a2 (PASSES: first node)
- `this[19] != 0` → traverse 0x8C chain to end, append a2 (PASSES: existing list, append)
