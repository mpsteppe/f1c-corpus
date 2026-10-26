## DoublyLinkedListNodeRemoval_d3a0_0053d3a0 — DoublyLinkedListUnlink_86C_870

**Summary:** Unlinks a node from the global registry doubly-linked list (offsets 0x86C/0x870, head at dword_8B8E20). Patches neighbor pointers, updates head if removing first node, and zeros the node's own link fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCompareLinkedListSearch (0053d130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x86C) | 0x870 | RW | — | Previous node's next pointer (patches around removed node) |
| *(this+0x870) | 0x86C | RW | — | Next node's prev pointer (patches around removed node) |
| this | 0x86C | RW | 0 | Current node's prev pointer (cleared after unlink) |
| this | 0x870 | RW | 0 | Current node's next pointer (cleared after unlink) |

**Written-by note (persistence):**
- *(this+0x86C) 0x870: conditional — set to this->next when prev exists; persists
- *(this+0x870) 0x86C: conditional — set to this->prev when next exists; persists
- this 0x86C: conditionally zeroed on unlink; persists until re-link
- this 0x870: conditionally zeroed on unlink; persists until re-link

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e20 | dword_8B8E20 | RW | EntryRegistryHead [DERIVED] (also: ` â€” global linked list head (entry registry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks prev pointer (offset 0x86C): if non-null, patches prev->next to skip this node. Checks next pointer (offset 0x870): if non-null, patches next->prev to skip this node. Checks if this node is the list head (dword_8B8E20): if so, advances head to this->next.
