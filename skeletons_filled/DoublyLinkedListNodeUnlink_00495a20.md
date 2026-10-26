## DoublyLinkedListNodeUnlink_00495a20 — DoublyLinkedListUnlink

**Summary:** Unlinks a node from a doubly-linked list. Walks the list from head (offset 0x14) following next pointers (offset 0x64) to locate the target node, then splices it out by updating adjacent nodes' prev/next pointers and adjusting list head/tail (offsets 0x14, 0x18) if needed. Part of the generic doubly-linked list management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DoublyLinkedListAppend_5a80 (00495a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x78) | 0x64 | R | — | Next pointer read from a list node during traversal to locate target |
| this | 0x14 | RW | — | List head pointer (first node); updated if unlinking head |
| this | 0x18 | RW | — | List tail pointer (last node); updated if unlinking tail |

**Written-by note (persistence):**
- this 0x14: conditionally written when the removed node was the head (no prev node); persists externally
- this 0x18: conditionally written when the removed node was the tail (no next node); persists externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** NULL target node (a2) → return immediately (BLOCKED). Empty list (head at 0x14 is NULL) → return. Target not found in traversal → return without unlinking (BLOCKED).
