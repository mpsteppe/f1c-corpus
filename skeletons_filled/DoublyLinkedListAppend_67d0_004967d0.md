## DoublyLinkedListAppend_67d0_004967d0 — DoublyLinkedListAppend_18CC

**Summary:** Appends a node containing value a2 to a doubly-linked list (offsets 0x18CC-0x18D8). Allocates a 16-byte node, initializes it, links after tail, updates tail pointer, increments count. On empty list, initializes head and secondary pointer. Third variant of the doubly-linked list append pattern, differing only in base offsets from the list head struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18CC | RW | — | List head pointer (first node); set on first append |
| this | 0x18D0 | RW | — | List tail pointer (last node); updated to new node on every append |
| this | 0x18D4 | RW | — | Secondary pointer (read cursor?); set on first append alongside head |
| this | 0x18D8 | R | — | Node count; incremented by 1 on each successful append |

**Written-by note (persistence):**
- this 0x18CC: conditionally set on first append; persists
- this 0x18D0: updated on every append; persists
- this 0x18D4: conditionally set on first append; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 16 bytes for a new list node |

**Guard conditions:** NULL value (a2) → return immediately (BLOCKED). Allocation failure → node becomes NULL pointer, still linked in.
