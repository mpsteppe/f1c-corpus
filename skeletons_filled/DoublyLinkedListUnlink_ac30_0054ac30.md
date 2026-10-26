## DoublyLinkedListUnlink_ac30_0054ac30 — Unlink node from doubly linked list

**Summary:** Removes a node from a doubly linked list (prev at node+0x140, next at node+0x10, head at this+0x204). Updates prev node's next pointer to skip the removed node, updates next node's prev pointer to skip it. If removed node is the head, updates head to the next node. Returns 0. Used during scene graph cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraph (0054a770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | RW | — | Head of doubly linked list; updated if unlinked node is head |

**Written-by note (persistence):**
- this 0x204: updated if the unlinked node is the list head (set to node's next); otherwise unchanged

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If node's prev (node+0x140) is null → skip prev->next update (node is head). If node's next (node+0x10) is null → skip next->prev update (node is tail). If `this[0x204] == node` (node is head) → advance head to node's next; if node had no next, list becomes empty (head = 0).
