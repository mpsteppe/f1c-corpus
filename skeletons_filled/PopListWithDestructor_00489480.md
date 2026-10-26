## PopListWithDestructor_00489480 — ListPopFrontWithDestructor

**Summary:** Pops `count - index` items from front of linked list at offset 0x90. For each item, advances head to next (+140), calls destructor via vtable on the removed node, and decrements the count at offset 0x94.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIMenuItemCreator (00489600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x90) | 0x0 | R | — | Vtable of node being destroyed (for destructor call) |
| this | 0x90 | RW | — | Linked list head pointer (updated as nodes are popped) |
| this | 0x94 | RW | — | Item count in list (decremented by number of popped items) |
| this | 0x11C | R | — | Offset 0x8C from head — next pointer within node (140 = 0x8C) |
| this | 0x170 | R | — | Index threshold: items below this are not popped |

**Written-by note (persistence):**
- this 0x90: Updated every iteration as head advances to next node.
- this 0x94: Decremented by number of removed items at end.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If index (0x170) < 0, skips entirely. If count (0x94) <= index, no items to pop.
