## LinkedListElementRemovalWithCleanup_00582b10 — LinkedListRemoveByValueWithCleanup

**Summary:** Removes a linked-list node by matching its data value against the first node's value. Searches through list, unlinks matching node, decrements count, and if the node's cleanup flag is set, calls SEH-guarded cleanup on its data before freeing node and data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketQueueReader (005805c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Node's data value (first DWORD of 12-byte node) — matched against for removal |
| obj | 0x8 | RW | 0 | Node's cleanup flag — set to 0 during removal to suppress re-cleanup |
| this | 0x0 | RW | — | Head pointer of linked list |
| this | 0x4 | RW | — | Tail pointer of linked list |
| this | 0x8 | RW | — | Current/iterator pointer (updated if removing head) |
| this | 0xC | R | — | Node count — decremented on removal |

**Written-by note (persistence):**
- obj 0x8: conditionally cleared to 0 during removal to prevent double-cleanup. External poke would be overwritten.
- this 0x0: conditionally updated if head node is removed. External poke survives.
- this 0x4: conditionally updated if tail node is removed. External poke survives.
- this 0x8: conditionally updated if removed node is at iterator position. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005867b0 | SEHGuardedFunctionWithExceptionHandling | Call cleanup callback on removed node's data before freeing |
| 00587bcf | FreeWrapper_7bcf | Free node memory and optionally data memory |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | Head pointer — if null, list empty, returns 0 immediately |

**Guard interpretation:** If head (*this) is NULL, returns 0 immediately (empty list). Otherwise proceeds to find and remove the node.
