## ConditionalSingleStoreWithIteration_0049a1c0 — LazyInitListHeadOrIterateAndSet

**Summary:** If `a2` is zero, returns -1. If the list head at offset 0x00 is NULL, stores `a2` as the head (lazy initialization) and returns 0. If the head already exists, iterates through the list via sub_499E00 (walking a node chain) and calls FieldSetterAt0x68 on the traversed node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493060 (00493060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | linked list head pointer; read for iteration, written when NULL (lazy init) |

**Written-by note (persistence):**
- this 0x0: written once if NULL (lazy init); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499df0 | FieldSetterAt0x68 | setter called on iterated node |
| 00499e00 | sub_499E00 | linked list traversal/accessor for next node |

**Guard conditions:** a2 checked zero — if 0, return -1. *this (offset 0x00) checked NULL — if NULL, store a2 as list head and return 0 (lazy init path). If non-NULL, iterate via sub_499E00 chain until NULL, then call FieldSetterAt0x68.
