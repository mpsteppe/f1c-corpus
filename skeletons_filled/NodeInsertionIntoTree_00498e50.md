## NodeInsertionIntoTree_00498e50 — Linked List Node Insertion

**Summary:** Inserts a node (a2) into a linked list maintained within the object. Handles both empty list (initializes head and tail) and existing list (traverses with FieldGetter_8e30 then walks the 0x48 chain to append). Increments node counter and stores a back-link.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492710 (00492710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | First parameter passed to ShortComputation_a9c0 |
| this | 0x8 | R | — | Second parameter passed to ShortComputation_a9c0 |
| this | 0xC | R | — | Third parameter passed to ShortComputation_a9c0 |
| this | 0x10 | R | — | Fourth parameter passed to ShortComputation_a9c0 |
| this | 0x48 | RW | — | Head pointer of the linked list (set to a2 when list was empty) |
| this | 0x50 | RW | — | Tail pointer of the linked list (set to a2 when list was empty) |
| this | 0x58 | R | — | Node counter incremented on each insertion |

**Written-by note (persistence):**
- this 0x48: Written when node inserted into empty list (becomes head); persists until all nodes removed
- this 0x50: Written when node inserted into empty list (becomes tail); persists until all nodes removed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498e30 | FieldGetter_8e30 | Gets the list head or starting node for traversal; determines if list is empty |
| 0049a9c0 | ShortComputation_a9c0 | Performs computation using 4 fields (this[1]–this[4]) during insertion |

**Guard conditions:**
- `FieldGetter_8e30(this) == 0` → list empty: set this[18]=a2 (head) and this[20]=a2 (tail) (PASSES: first node)
- `FieldGetter_8e30(this) != 0` → list non-empty: traverse 0x48 chain to end, append a2 (PASSES: existing list, append)
