## DoublyLinkedListAppend_6750_00496750 — DoublyLinkedListAppendWithFlag

**Summary:** Appends a node with value a2 to a doubly-linked list, allocating a 16-byte node (value + next + prev + byte). If a3 is non-zero, sets a flag byte at offset 0x24 to 1. Otherwise identical to the standard append pattern: links after tail, increments count, initializes head/secondary on first insertion. Returns a3. Part of a flagged doubly-linked list system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameObjectUpdateFrame (004661b0), DirectoryChangeHandler (0048e6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C0) | 0x4 | RW | — | Tail node's next pointer (at node+4); updated to new node on append |
| this | 0x24 | RW | 1 | BYTE flag; set to 1 when a3 is non-zero — marks list or object as "active/dirty" |
| this | 0x18BC | RW | — | List head pointer (first node); set on first append |
| this | 0x18C0 | RW | — | List tail pointer (last node); updated to new node on every append |
| this | 0x18C4 | RW | — | Secondary pointer (read cursor?); set on first append alongside head |
| this | 0x18C8 | R | — | Node count; incremented by 1 on each successful append |

**Written-by note (persistence):**
- *(this+0x18C0) 0x4: updated on every append — old tail's next set to new node; persists
- this 0x24: set to 1 when a3 != 0; may be set multiple times; persists
- this 0x18BC: conditionally set on first append; persists
- this 0x18C0: updated on every append; persists
- this 0x18C4: conditionally set on first append; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 16 bytes for a new list node |

**Guard conditions:** NULL value (a2) → BLOCKED (skip node creation and list update). Allocation failure → node becomes NULL pointer, still linked in.
