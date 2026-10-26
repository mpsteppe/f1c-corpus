## DoublyLinkedListNodeRemovalWithArrayCleanup_005478b0 — Remove linked list node and free its array

**Summary:** Unlinks node a2 from doubly linked list (rooted at this+0x28 via prev[22]/next[23] at offsets 0x58/0x5C), updates head pointer at this+0x28 if removing head, then frees the array allocation at a2 (with 96-byte stride count prefix at a2[-4]) calling EmptyStub_7470 on each element in reverse. Decrements this+0xC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544740 (00544740), AudioNetworkStreamCleanup (00544af0), ReferenceCountedResourceRelease (005469c0), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | node count (decremented on removal) |
| this | 0x28 | RW | — | linked list head pointer (updated if removing head) |

**Written-by note (persistence):**
- this 0xC: decremented on each node removal
- this 0x28: updated if head node removed; persists as new head

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | stub cleanup callback per array element |
| 00587bcf | FreeWrapper_7bcf | free the array allocation (at a2-4, including count prefix) |

**Guard conditions:** Unconditionally unlinks a2 from linked list using prev (a2+0x58) and next (a2+0x5C) pointers. Always frees array allocation. Only condition: if this+0x28 == a2, update head to a2's next. Array element count is read from *(a2-4); if >= 0, calls EmptyStub_7470 on each element in reverse order before freeing the block.
