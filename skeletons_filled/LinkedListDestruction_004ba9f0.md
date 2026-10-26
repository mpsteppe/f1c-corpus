## LinkedListDestruction_004ba9f0 — Full linked list destructor

**Summary:** Walks a singly-linked list freeing each node and optionally freeing its attached data. Zeroes all list bookkeeping fields (head, tail, current, count) to empty state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | Node next pointer (traversal) |
| obj | 0x0 | R | — | Node data pointer (freed conditionally) |
| obj | 0x8 | R | — | Node free-data flag (non-zero = free data) |
| this | 0x0 | RW | 0 | List head pointer (zeroed after destruction) |
| this | 0x4 | RW | 0 | List tail pointer (zeroed after destruction) |
| this | 0x8 | RW | 0 | List current/iterator pointer (zeroed after) |
| this | 0xC | RW | 0 | List node count (zeroed after destruction) |

**Written-by note (persistence):**
- this 0x0-0xC: all zeroed after destruction; list becomes empty

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Empty stub (no-op before data free) |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** Iterates while head != NULL. Per-node: frees data only if node+0x8 flag is non-zero and data pointer is non-null.
