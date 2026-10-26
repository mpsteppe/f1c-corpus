## EnhancedListCleanupWithSubObjectDelete_00565d50 — linked list destructor with sub-object cleanup

**Summary:** Frees entire linked list: frees sub-resource at data[81] if non-null, frees data if flag at node+8 set, frees each node, then zeroes list head's four fields. Part of directory/linked-list resource cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListDestructorWithChildCleanup (00565e20), sub_565EB0 (00565eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x144 | R | — | sub-resource within data to free if non-null |
| obj | 0x0 | R | — | node's data pointer |
| obj | 0x8 | R | — | flag whether data needs cleanup |
| this | 0x0 | RW | 0 | list head field 1 (zeroed after cleanup) |
| this | 0x4 | RW | 0 | list head field 2 (zeroed after cleanup) |
| this | 0x8 | RW | 0 | list head field 3 (zeroed after cleanup) |
| this | 0xC | RW | 0 | list head field 4 (zeroed after cleanup) |

**Written-by note (persistence):**
- this 0x0: unconditionally zeroed; external poke does not survive
- this 0x4: unconditionally zeroed; external poke does not survive
- this 0x8: unconditionally zeroed; external poke does not survive
- this 0xC: unconditionally zeroed; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | memory deallocation (free equivalent) |

**Guard conditions:** If `*a1 == NULL` → skip entire iteration. Per node: if byte at node+8 == 0 → skip data/sub-resource freeing. If data pointer `*v2 == NULL` → skip data/sub-resource freeing. If `v3[81] == NULL` → skip sub-resource free.
