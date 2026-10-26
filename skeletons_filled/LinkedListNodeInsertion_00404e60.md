## LinkedListNodeInsertion_00404e60 — StringLinkedListAppend

**Summary:** Allocates a string copy of the input, creates a linked list node containing it, and appends the node to the tail of the list stored at offsets 0x40-0x4C of the target object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | RW | — | linked list head pointer (set on first insertion) |
| obj | 0x44 | RW | — | linked list tail pointer (updated on each append) |
| obj | 0x48 | RW | — | linked list current-pointer or end (updated) |
| obj | 0x4C | RW | — | linked list node count (incremented on each insertion) |
| this | 0x0 | R | — | pointer to target object containing the list |

**Written-by note (persistence):**
- obj 0x40: set once on first insertion; unchanged on subsequent appends
- obj 0x44: updated each insertion to new tail
- obj 0x48: read/written during list management
- obj 0x4C: incremented each insertion

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | allocates/copies a string with buffer reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocator for node and string allocations |

**Guard conditions:** Checks if string copy allocation succeeds (v5 non-null). PASSES: allocates 12-byte list node, links into tail of list. BLOCKED: if string copy allocation fails, node not created; if 12-byte node allocation fails, node not linked.
