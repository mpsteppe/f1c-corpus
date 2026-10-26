## sub_4CD3E0_004cd3e0 — singly-linked list node unlink/remove

**Summary:** `__thiscall` list-management helper: removes the node `a2` from a singly-linked list whose head is stored at this[0x90] and whose `next` link lives at node+0x8C. Handles both the head case (head advanced to node->next) and interior nodes (previous node's `next` spliced to the target's `next`), clears the removed node's `next`, decrements the element count at this[0x94], and returns the removed node (or null if not found / empty list).

**Called by:** sub_4D41CD (004d41cd), sub_4D6750 (004d6750), sub_4D67D0 (004d67d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | RW | 0 | `next` link field of the removed node; zeroed to detach it from the list |
| this | 0x90 | RW | — | Head pointer of the singly-linked node list; reassigned to skip the node when it is the head |
| this | 0x94 | R | — | Element count of the list; decremented once per successful unlink |
| this | 0x11C | R | — | Traversal read of the `next` chain (head+0x8C flattened); walked until the target or end-of-list (null) is reached |

**Written-by note (persistence):**
- *(this+0x11C) 0x8C: Written (zeroed) only when a matching node is actually unlinked — conditional on the target being found; a poke survives as long as that node is not removed.
- this 0x90: Written only in the head-removal branch (head = head->next); unchanged when removing interior nodes or when no match. A poke survives unless the head node itself is removed.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No-op (returns immediately) if the head this[0x90] is null. If head == a2 → head is advanced past the node, node->next cleared, count decremented. Else walk: if a node's next == a2 → that link is spliced past the target, target's next cleared, count decremented. If the walk reaches a null next without finding a2 → returns null/unchanged, no count change and no field writes. Count (this[0x94]) is decremented only on an actual unlink.
