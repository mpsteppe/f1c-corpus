## DoublyLinkedListAppend_90b0_005490b0 — DoublyLinkedNodeAppend

**Summary:** Appends node `a2` to a linked list rooted at this[0xEC]. Handles both empty and non-empty lists, updates next (offset 0x4C) and prev (offset 0x48) pointers, zeros fields at offsets 0x44. Returns previous tail or 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArithmeticComparison_9170 (00549170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x138)+0x4C) | 0x4C | RW | — | pNext — forward pointer in the linked list node |
| this | 0xEC | RW | — | Head pointer of the linked list |
| this | 0x138 | R | — | Intermediate pointer to container struct |

**Written-by note (persistence):**
- *(*(this+0x138)+0x4C) 0x4C: Written once per append to link tail to new node; external poke breaks list linkage
- this 0xEC: Written once when list was empty; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0xEC] (head pointer) must be non-null for append-to-existing-tail path. If NULL, a2 becomes the new head (this[0xEC] = a2) and its prev/next/sibling fields at offsets 0x44, 0x48, 0x4C are zeroed. Otherwise walks chain via offset 0x4C to find tail, links new node bidirectionally, and zeros its extra fields.
