## DestructorWithMultipleConditionalFrees_00499ce0 — DestructorWithMultipleConditionalFrees

**Summary:** Destructor that sets the vtable pointer (offset 0x00), recursively destroys a tree node via TreeNodeRecursiveDestructor, frees a linked list at offset 0x6C via LinkedListFree, then conditionally frees up to 10 pointer fields (offsets 0x10 through 0x58, step 0x08) via FreeWrapper_7bcf if non-NULL.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalFree_9cc0 (00499cc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5ACAAC |
| this | 0x10 | R | — | pointer field conditionally freed |
| this | 0x18 | R | — | pointer field conditionally freed |
| this | 0x20 | R | — | pointer field conditionally freed |
| this | 0x28 | R | — | pointer field conditionally freed |
| this | 0x30 | R | — | pointer field conditionally freed |
| this | 0x38 | R | — | pointer field conditionally freed |
| this | 0x40 | R | — | pointer field conditionally freed |
| this | 0x48 | R | — | pointer field conditionally freed |
| this | 0x50 | R | — | pointer field conditionally freed |
| this | 0x58 | R | — | pointer field conditionally freed |

**Written-by note (persistence):**
- this 0x0: vtable pointer set once; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acaac | off_5ACAAC | R | VTable_5ACAAC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499da0 | TreeNodeRecursiveDestructor | recursively destroy child tree nodes |
| 0049af30 | LinkedListFree | free linked list at this+27 (offset 0x6C) |
| 00587bcf | FreeWrapper_7bcf | free wrapper for individual pointer fields |

**Guard conditions:** Each pointer field from this[4] (0x10) through this[22] (0x58) checked non-NULL before FreeWrapper_7bcf call. If NULL, skip free for that field. All checks independent and sequential.
