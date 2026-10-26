## LinkedListDestructorWithInnerFree_00567a30 — linked list destructor with inner pointer free

**Summary:** Calls F_9PointerArrayCleanup first, then iterates linked list from this[9], freeing each node's data sub-pointer (if exists) and data, then node. Zeroes list head fields at offsets 0x24-0x30. Resource cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SubObjectDestructorChain (0040d9fc), FrontendScreenLoadingDisplayHandler (00476250), sub_4FE7C0 (004fe7c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x24) | 0x0 | R | — | data's sub-resource pointer (freed first if non-null) |
| this | 0x24 | RW | 0 | first node pointer (zeroed after cleanup) |
| this | 0x28 | RW | 0 | list head field 2 (zeroed after cleanup) |
| this | 0x2C | RW | 0 | list head field 3 (zeroed after cleanup) |
| this | 0x30 | RW | 0 | list head field 4 (zeroed after cleanup) |

**Written-by note (persistence):**
- this 0x24: unconditionally zeroed; external poke does not survive
- this 0x28: unconditionally zeroed; external poke does not survive
- this 0x2C: unconditionally zeroed; external poke does not survive
- this 0x30: unconditionally zeroed; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567f10 | F_9PointerArrayCleanup | cleanup array/list at this[0-8] |
| 00587bcf | FreeWrapper_7bcf | memory deallocation (free equivalent) |

**Guard conditions:** If this[9] == NULL → skip node iteration. Per node: if byte at node+8 == 0 → skip data cleanup. If data pointer *node == NULL → skip data cleanup. If *data (sub-pointer) == NULL → skip sub-free.
