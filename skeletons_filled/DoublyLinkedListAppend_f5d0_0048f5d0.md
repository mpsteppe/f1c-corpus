## DoublyLinkedListAppend_f5d0_0048f5d0 — DoublyLinkedListNodeAppend

**Summary:** Appends a new node containing data pointer and byte flag to a doubly linked list. Allocates 16-byte node via OperatorNewNhMallocWrapper, initializes node fields (data, next=0, prev=0, flag), updates head/tail/cursor pointers, and increments element count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectNameComparison (00477280), GameFilterSetup (00477830), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF0 | RW | — | linked list head pointer (first node) |
| this | 0xF4 | RW | — | linked list tail pointer (last node) |
| this | 0xF8 | RW | — | linked list cursor / iterator pointer |
| this | 0xFC | R | — | linked list element count |

**Written-by note (persistence):**
- this 0xF0: set to new node if list was empty
- this 0xF4: set to new node unconditionally (new tail)
- this 0xF8: set to new node if list was empty
- list count incremented unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | allocate 16-byte node structure |

**Guard conditions:**
- if (a2 == 0) → BLOCKED (return, nothing to append)
- if (allocation fails → v4 = 0, node is null)
- if (list head is non-null) → link new node after tail: tail->next = new, new->prev = tail
- if (list head is null) → this is first node: head = new, cursor = new
- Always: tail = new, count++
