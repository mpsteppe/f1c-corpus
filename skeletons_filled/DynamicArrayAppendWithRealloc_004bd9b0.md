## DynamicArrayAppendWithRealloc_004bd9b0 — DynamicArrayAppendWithRealloc

**Summary:** Appends integer to a dynamic array; when capacity is exhausted, grows by +8 slots (reallocates, copies old elements, frees old buffer), then stores new element and increments count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NestedLoopRangeTraversal (004be1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | capacity of dynamic array (in elements) |
| this | 0x1C | R | — | current element count |
| this | 0x20 | RW | — | pointer to heap-allocated int buffer |

**Written-by note (persistence):**
- this 0x18: increased by 8 on reallocation; external poke overwritten on next growth
- this 0x20: updated to new allocation on growth; external poke (pointer) invalidated on realloc

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees old buffer during reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocates new buffer with increased capacity |

**Guard conditions:** reallocation triggered only when count == capacity; append always succeeds (unconditional after potential realloc)
