## DoublyLinkedListNodeRemoval_5090_00545090 — Remove linked list node from scene graph tree

**Summary:** Removes a doubly-linked list node (`a2`) from a list managed by `this`. Updates `prev->next` and `next->prev` pointers (offsets 436/440), and advances `this->head` (offset 0xF8) when the removed node was the head.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraphTreeDestructor (00544ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF8 | RW | — | Head pointer to doubly-linked list of child nodes |

**Written-by note (persistence):**
- this 0xF8: Conditional — written only when `this[62] == a2` (removed node is head). Set to `node->next`. Otherwise unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard on removal itself. Head update guarded by `this[62] == a2`: PASSES (head advances to `node->next`) when the removed node is the current head; BLOCKED (head unchanged) otherwise.
