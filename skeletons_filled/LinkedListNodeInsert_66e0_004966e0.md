## LinkedListNodeInsert_66e0_004966e0 — DoublyLinkedListNodeAppend

**Summary:** Appends a node containing value a2 to a doubly-linked list. Allocates a 16-byte node (value + 4/8/12: next, prev, byte), initializes it, links it after the tail, updates tail pointer, and increments the count. If list is empty, initializes head, tail, and a secondary pointer to the new node. Part of a generic doubly-linked list with counted nodes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WrapperReturn0 (0048e6a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18DC | RW | — | List head pointer (first node); set on first append |
| this | 0x18E0 | RW | — | List tail pointer (last node); updated to new node on every append |
| this | 0x18E4 | RW | — | Secondary pointer (current/read cursor?); set on first append alongside head |
| this | 0x18E8 | R | — | Node count; incremented by 1 on each successful append |

**Written-by note (persistence):**
- this 0x18DC: conditionally set on first append; persists
- this 0x18E0: updated on every append; persists
- this 0x18E4: conditionally set on first append; persists
- this 0x18E8: incremented on every append; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 16 bytes for a new list node |

**Guard conditions:** NULL value (a2) → return immediately (BLOCKED). Allocation failure → node becomes NULL pointer, linked into list as a dead entry.
