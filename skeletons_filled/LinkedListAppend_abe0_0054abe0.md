## LinkedListAppend_abe0_0054abe0 — Append node to doubly linked list (second variant)

**Summary:** Appends a node to the tail of a doubly linked list (head at this+0x204, next at node+0x10, prev at node+0x140). If list is non-empty, walks to tail via node+0x10 next pointers; if empty, sets head to new node. Initializes new node's prev to old tail (or 0) and next to 0. Returns old head (or new node if list was empty). Similar to LinkedListAppend_a270 but with different link offsets.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_54A870 (0054a870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x214)+0x10) | 0x10 | RW | — | Tail node's next pointer; linked to newly appended node |
| this | 0x204 | RW | — | Head of doubly linked list; set on first append |
| this | 0x214 | R | — | Pointer to sub-structure containing list state |

**Written-by note (persistence):**
- *(*(this+0x214)+0x10) 0x10: written once per append when list is non-empty (old tail's next set to new node); overwritten each append
- this 0x204: written once on first append (set to new node); unchanged on subsequent appends

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x204]` (head) is non-null → walk to tail via node+0x10 next pointers, then link node after tail. If null → set head to new node directly. New node's prev (+0x140) set to old tail (or 0) and next (+0x10) set to 0.
