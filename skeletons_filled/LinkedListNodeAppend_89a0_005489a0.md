## LinkedListNodeAppend_89a0_005489a0 — DoublyLinkedListNodeAppend

**Summary:** Allocates a new sound-buffer node (24 bytes) via OperatorNewNhMallocWrapper and SoundBufferAllocator, then appends it to the doubly-linked list tracked by this. Returns pointer to the new node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546450 (00546450), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x14) | 0x14 | RW | — | pNext forward pointer in linked list node |
| this | 0x2C | RW | — | pTail — pointer to last node in the list |
| this | 0x40 | R | — | pHead — pointer to first node in the list |

**Written-by note (persistence):**
- *(*(this+0x40)+0x14) 0x14: Written once when appending to non-empty list; external poke breaks list linkage
- this 0x2C: Written once when list was empty (now points to first node); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ab20 | SoundBufferAllocator | Initializes allocated 24-byte block as a sound buffer node |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation of 24 bytes for new node |

**Guard conditions:** If OperatorNewNhMallocWrapper returns NULL, result is 0 and no append occurs. If this[0x2C] (tail) is NULL, list is empty — new node becomes both head and tail (this[0x2C]=result, result[4]=0). Otherwise walks chain via offset 0x14 to find end, links new node bidirectionally.
