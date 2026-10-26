## LinkedListRemove_005452b0 — Doubly-linked list node removal (head at offset 0x108)

**Summary:** Removes node `a2` from a doubly-linked list with prev/next pointers at offsets 0x48 and 0x4C. Updates `prev->next` and `next->prev`, and advances `this->head` (offset 0x108) if the removed node was head.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundSourceDestructor (00545150), ArithmeticComparison_9170 (00549170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x108 | RW | — | Head pointer of doubly-linked list |

**Written-by note (persistence):**
- this 0x108: Conditional — written only when `this[66] == a2` (removed node is head). Set to `node->next`. Otherwise unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard on removal itself. Head update guarded by `this[66] == a2`: PASSES (head advances to `node->next`) when removing the current head; BLOCKED (head unchanged) otherwise.
