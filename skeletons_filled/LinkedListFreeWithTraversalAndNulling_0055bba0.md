## LinkedListFreeWithTraversalAndNulling_0055bba0 — LinkedListFreeTraverseAndNullHead

**Summary:** Traverses a singly-linked list starting at this[72], freeing each node via FreeWrapper_7bcf, then sets the head pointer to null. Nodes use offset 0x20 (field [8]) as next pointer. Part of resource cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArrayOfPointersCleanupWithFreeLoop (0055bf70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x120 | RW | 0 | Linked list head pointer (set to null after free) |
| this | 0x140 | R | — | Pointer used as next traversal cursor from list nodes |

**Written-by note (persistence):**
- this 0x120: set to 0 after list is freed. External poke does survive (head cleared once).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory |

**Guard conditions:** If this[72] (head) is null, returns immediately (nothing to free). Otherwise iterates: dereferences node[8] for next pointer before freeing current node; continues until next is null. Frees final tail node then nulls head.
