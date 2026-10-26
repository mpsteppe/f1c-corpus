## DoublyLinkedListNodeRemoval_19e0_005519e0 — DoublyLinkedListNodeUnlinkAndFree

**Summary:** Unlinks a node from a doubly linked list by updating prev/next pointers, updates head pointer if removing the head node, then calls cleanup callback and frees the node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x118 | RW | — | Linked list head pointer (this[70]) — updated if a2 was head |

**Written-by note (persistence):**
- this 0x118: Written conditionally (when a2 == this[70]); external poke overwritten on head removal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00550ac0 | CallWrapperReturning0 | Cleanup callback before node deletion |
| 00557470 | EmptyStub_7470 | Stub called before free (debug/sentinel) |
| 00587bcf | FreeWrapper_7bcf | Deallocate node memory |

**Guard conditions:** 
- a2[11] (prev) == 0: skip prev->next update. PASS when non-null (link prev forward).
- a2[12] (next) == 0: skip next->prev update. PASS when non-null (link next backward).
- a2 != this[70]: head pointer unchanged. PASS when equal (update head to next).
