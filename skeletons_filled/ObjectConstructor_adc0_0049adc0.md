## ObjectConstructor_adc0_0049adc0 — LinkedIntPairNodeConstructor

**Summary:** Allocates and initializes a linked list node storing a pair of 16-bit values. Allocates a word pair buffer for a2/a3, then a 12-byte node linking to it. Appends to tail of existing list or starts new list. Returns 1 on success, 0 on allocation failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492A40 (00492a40), sub_493060 (00493060), IndexedListEntryWrite (0049ae40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | List head pointer |
| this | 0x4 | RW | — | Current/tail node pointer |
| this | 0x8 | RW | — | Tail pointer (used for append) |
| this | 0xC | R | — | Node count (incremented) |

**Written-by note (persistence):**
- this 0x0: written if head was NULL (first node, sets head = node)
- this 0x4: always set to new node each call; external poke overwritten
- this 0x8: written if head was NULL (first node, tail = node)
- this 0xC: incremented each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Deallocation on allocation failure path |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation for word pair buffer and node |

**Guard conditions:** First OperatorNewNhMallocWrapper(4) returns NULL → BLOCKED: calls FreeWrapper_7bcf(0) and returns 0. If first alloc succeeds but second (12-byte node) returns NULL, returns 0 but node is leaked.
