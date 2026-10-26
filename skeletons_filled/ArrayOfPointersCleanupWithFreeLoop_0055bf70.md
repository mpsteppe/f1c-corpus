## ArrayOfPointersCleanupWithFreeLoop_0055bf70 — PointerArrayFreeWithLinkedListCleanup

**Summary:** Iterates an array of pointers (this[2] onward), calling LinkedListFreeWithTraversalAndNulling on each, then freeing the pointer itself via FreeWrapper_7bcf and nulling the slot. Part of global resource cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GlobalResourceCleanup (0053c4d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Array count (number of pointers to free) |
| this | 0x8 | RW | 0 | First pointer slot in array (head of slot list) |

**Written-by note (persistence):**
- this 0x8: set to 0 after each slot is freed. External poke does not survive (cleared during cleanup).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | No-op stub before free |
| 0055bba0 | LinkedListFreeWithTraversalAndNulling | Free linked list inside each slot |
| 00587bcf | FreeWrapper_7bcf | Free slot pointer itself |

**Guard conditions:** If this[1] (count) <= 0, returns immediately (nothing to free). Otherwise loops count times, freeing each slot's linked list then the slot itself, nulling each pointer after free.
