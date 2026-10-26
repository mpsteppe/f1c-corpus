## LinkedListAppend_a270_0054a270 — Append node to doubly linked list tail

**Summary:** Appends a node to the tail of a doubly linked list (head at this+0x100, prev/next links at node+0x100/+0x104). If list is non-empty, walks to tail via node+0x104 next pointers; if empty, sets head to new node. Sets prev pointer of new node to old tail (or 0) and next to 0. Returns old head (or new node if list was empty).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A790 (0055a790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x204)+0x104) | 0x104 | RW | — | Tail node's next pointer; linked to newly appended node |
| this | 0x100 | RW | — | Head of doubly linked list; set on first append |
| this | 0x204 | R | — | Pointer to sub-structure containing list state |

**Written-by note (persistence):**
- *(*(this+0x204)+0x104) 0x104: written once per append when list is non-empty (old tail's next set to new node); overwritten each append
- this 0x100: written once on first append (set to new node); unchanged on subsequent appends

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x100]` (head) is non-null → walk to tail via node+0x104 next pointers, then link node after tail. If null → set head to new node directly. The new node's prev (+0x100) and next (+0x104) are always initialized to 0.
