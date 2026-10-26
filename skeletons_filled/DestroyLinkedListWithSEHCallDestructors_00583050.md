## DestroyLinkedListWithSEHCallDestructors_00583050 — LinkedListDestroyWithVirtualDestructor_2

**Summary:** Destroys a singly-linked list by walking each flagged node and calling a virtual destructor (vtable entry at offset 0x4, arg=1) on its data before freeing the node. Zeros all list fields after destruction. Code identical to SEHProtectedLinkedListDestruction_00582f60 but with a different SEH handler.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x4 | R | — | Second vtable entry of data — virtual destructor/release called with arg=1 |
| *(obj+0x0) | 0x0 | R | — | Node's data pointer — first DWORD of 12-byte node |
| *(obj+0x4) | 0x4 | R | — | Node's next pointer — second DWORD of 12-byte node |
| obj | 0x0 | R | — | Node's first field (data pointer) |
| obj | 0x8 | R | — | Flag byte — non-zero means call virtual destructor on data before freeing |
| this | 0x0 | RW | 0 | Head pointer of linked list |
| this | 0x4 | RW | 0 | Tail pointer of linked list |
| this | 0x8 | RW | 0 | Current/iterator pointer |
| this | 0xC | RW | 0 | Node count |

**Written-by note (persistence):**
- this 0x0: cleared to 0 at end.
- this 0x4: cleared to 0 at end.
- this 0x8: cleared to 0 at end.
- this 0xC: cleared to 0 at end.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ce08 | SEH_583050 | R | SEH handler registration for exception protection |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free each node after processing |

**Guard conditions:** Checks *this (head pointer, offset 0x0) — non-null enters loop, null skips to zeroing fields.
