## LinkedListNodeRemovalWithCleanupCallback_00582eb0 — LinkedListRemoveByValueFreeData

**Summary:** Removes a linked-list node by matching its data value against the first node's value. Unlinks node, decrements count, and if cleanup flag is set, frees the node's data via FreeWrapper_7bcf before freeing the node itself. Similar to 582B10 but without SEH callback invocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), NetworkAccept (00580190)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Node's data value (first DWORD of 12-byte node) — matched against for removal |
| obj | 0x8 | RW | 0 | Node's cleanup flag — cleared during removal to suppress double-free |
| this | 0x0 | RW | — | Head pointer of linked list |
| this | 0x4 | RW | — | Tail pointer of linked list |
| this | 0x8 | RW | — | Current/iterator pointer (updated if removing head) |
| this | 0xC | RW | — | Node count — decremented on removal |

**Written-by note (persistence):**
- obj 0x8: conditionally cleared to 0 during removal. External poke overwritten.
- this 0x0: conditionally updated if head node is removed. External poke survives.
- this 0x4: conditionally updated if tail node is removed. External poke survives.
- this 0x8: conditionally updated if removed node is at iterator position. External poke survives.
- this 0xC: decremented on removal. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free node memory and optionally data memory if flag was set |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | Head pointer — if null, list empty, returns 0 immediately |

**Guard interpretation:** If head (*this) is NULL, returns 0 immediately (empty list). Otherwise proceeds to find and remove matching node.
