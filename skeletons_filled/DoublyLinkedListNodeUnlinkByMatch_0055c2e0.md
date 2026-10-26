## DoublyLinkedListNodeUnlinkByMatch_0055c2e0 — DoublyLinkedListUnlinkByPointer

**Summary:** Finds a node by pointer match (a2) in a doubly-linked list (head at this[1350]) and unlinks it by updating prev/next pointers. If the removed node is head, advances head to next. Part of resource/linked list cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCascadeCleanup (005539f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1538)+0x1C) | 0x20 | RW | — | Next pointer of previous node (updated to skip removed) |
| *(*(this+0x1538)+0x20) | 0x1C | RW | — | Prev pointer of next node (updated to skip removed) |
| *(*(this+0x1538)+0x20) | 0x20 | R | — | Next pointer of node to remove (used for relinking) |
| *(this+0x1538) | 0x1C | R | — | Prev pointer of target node |
| *(this+0x1538) | 0x20 | R | — | Next pointer of target node |
| this | 0x1518 | RW | — | List head pointer (updated if head is removed) |

**Written-by note (persistence):**
- *(*(this+0x1538)+0x1C) 0x20: updated during unlink. External poke survives.
- *(*(this+0x1538)+0x20) 0x1C: updated during unlink. External poke survives.
- this 0x1518: set to next node if head is removed. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If head (this[1350]) is null, returns immediately. Walks list comparing each node pointer to a2; if not found, returns 0. On match: sets prev->next = node->next; sets next->prev = node->prev; if head was removed, head = node->next. Returns pointer to removed node.
