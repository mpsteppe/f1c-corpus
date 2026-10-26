## DoublyLinkedListAppend_5a80_00495a80 — DoublyLinkedListAppend

**Summary:** Appends a node to the tail of a doubly-linked list. First unlinks the node from its current list (via DoublyLinkedListNodeUnlink), zeroes its next/prev pointers, then walks to the list tail and splices the node in. If list is empty, sets head and tail to the new node. Part of generic doubly-linked list management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_7890 (00497890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x78)+0x64) | 0x64 | RW | — | Next pointer of a node during tail traversal (walking list to find last node) |
| this | 0x14 | RW | — | List head pointer (first node); written when appending to empty list |
| this | 0x18 | RW | — | List tail pointer (last node); updated to new node on each append |
| this | 0x78 | R | — | Pointer to cached/sentinel node used as traversal starting point |

**Written-by note (persistence):**
- *(*(this+0x78)+0x64) 0x64: updated on each append — old tail's next pointer set to new node; persists
- this 0x14: conditionally set on first append to empty list; persists
- this 0x18: updated to new node on every successful append; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495a20 | DoublyLinkedListNodeUnlink | Remove node from any existing list before re-appending |

**Guard conditions:** NULL target node (a2) → return immediately (BLOCKED). Empty list (head at 0x14 is NULL) → short-circuit: set head and tail to new node, skip traversal.
