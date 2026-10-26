## DoublyLinkedListUnlink_0053c630 — DoublyLinkedListUnlink_1E4_1E8

**Summary:** Unlinks a node from the global doubly-linked list (offsets 0x1E4/0x1E8) by splicing out its prev/next connections. Updates head pointer (dword_8B8F28) if removing the first node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010), MutexSemaphoreCleanup (005461b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E4) | 0x1E8 | RW | — | Previous node's next pointer (patches around removed node) |
| *(this+0x1E8) | 0x1E4 | RW | — | Next node's prev pointer (patches around removed node) |
| this | 0x1E4 | R | — | Current node's prev pointer |
| this | 0x1E8 | R | — | Current node's next pointer |

**Written-by note (persistence):**
- *(this+0x1E4) 0x1E8: conditional — set to this->next when prev exists; persists
- *(this+0x1E8) 0x1E4: conditional — set to this->prev when next exists; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | RW | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks prev pointer (offset 0x1E4): if non-null, patches prev->next to skip this node. Checks next pointer (offset 0x1E8): if non-null, patches next->prev to skip this node. Checks if this node is the list head (dword_8B8F28): if so, advances head to this->next.
