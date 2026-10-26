## UtilityFunction_6400_00486400 — LinkedListNodeUnlink

**Summary:** Unlinks a specific node from a singly-linked list. Handles head-removal and mid-list removal, detaches the node by zeroing its next pointer, and decrements a node counter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIListManagementHandler (0048a3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | RW | 0 | next-pointer (offset 0x8C) within a linked list node; zeroed on removal to detach node |
| this | 0x90 | RW | — | linked list head pointer; updated when removing head node |
| this | 0x94 | R | — | node counter (decremented on successful removal) |
| this | 0x11C | R | — | pointer to linked list node used as traversal base |

**Written-by note (persistence):**
- *(this+0x11C) 0x8C: conditionally set to 0 (only on the removed node); external writes before unlink survive on other nodes
- this 0x90: conditionally updated when head node is removed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[36] (offset 0x90, list head) != NULL → if null, returns 0 immediately (BLOCKED). If head == a2, unlinks head. Otherwise walks nodes via next-pointer at node+0x8C; if traversal reaches null before finding a2, returns 0 (BLOCKED). On match, unlinks a2 by bypassing it in predecessor's next pointer and detaches a2's own next pointer.
