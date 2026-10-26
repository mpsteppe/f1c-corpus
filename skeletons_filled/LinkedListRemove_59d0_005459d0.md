## LinkedListRemove_59d0_005459d0 — Doubly-linked node removal (head at 0x15C, prev/next at 0x30/0x34)

**Summary:** Removes node `a2` from a doubly-linked list with prev/next pointers at offsets 0x30 and 0x34. Updates `prev->next` and `next->prev`, and advances `this->head` (offset 0x15C) if the removed node was head.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundSourceDestructor (00545150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15C | RW | — | Head of doubly-linked list |

**Written-by note (persistence):**
- this 0x15C: Conditional — written only when `this[87] == a2` (removed node is head). Set to `node->next`. Otherwise unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard on removal itself. Head update guarded by `this[87] == a2`: PASSES (head advances to `node->next`) when removing head; BLOCKED (head unchanged) otherwise.
