## StaticInitBulk_004a8b80 — BulkDestructorCleanup

**Summary:** Bulk destructor/cleanup for a large object (~4680 DWORDs). Calls DoubleListCleanup, frees arrays of two-pointer structs in loops (36-byte stride), calls ShortComputation_4370 on many short fields, frees multi-pointer structs, then walks a linked list at the head freeing each node and its payload, finally zeroing the first 4 DWORDs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x4 | R | — | linked list node next pointer |
| obj | 0x0 | R | — | linked list head pointer (start of walk) |
| obj | 0x8 | R | — | in-use flag per node (byte) |
| this | 0x0 | RW | 0 | list head, cleared to 0 after walk |
| this | 0x4 | RW | 0 | second head DWORD, cleared after cleanup |
| this | 0x8 | RW | 0 | third DWORD, cleared after cleanup |
| this | 0xC | RW | 0 | fourth DWORD, cleared after cleanup |

**Written-by note (persistence):**
- this 0x0: cleared to 0 unconditionally after freeing linked list; not persistent
- this 0x4: cleared to 0 unconditionally; not persistent
- this 0x8: cleared to 0 unconditionally; not persistent
- this 0xC: cleared to 0 unconditionally; not persistent

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004aa1b0 | FreeTwoPointers | R | callback used by ArrayDestructorIterator to free 36-byte two-pointer structs |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401030 | ArrayDestructorIterator | iterates array of elements calling FreeTwoPointers for each |
| 00414370 | ShortComputation_4370 | short-field computation/cleanup helper (called on ~200 offsets) |
| 004aa170 | MultiPointerFree_a170 | frees up to 3 pointers in a struct |
| 004aa1b0 | FreeTwoPointers | frees two pointers in a 36-byte struct |
| 004c1700 | DoubleListCleanup | cleans up double-linked list at this+4678 |

**Guard conditions:** Only guard: checks `*this` (head pointer) is non-null before walking linked list. If null, skips entire linked-list free loop. Blocked: head is null. Passes: head is non-null, walks list by following offset+4 next pointers, frees each node.
