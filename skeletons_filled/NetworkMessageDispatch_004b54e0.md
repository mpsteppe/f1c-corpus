## NetworkMessageDispatch_004b54e0 — Network Message Dispatch

**Summary:** Dispatches a network message (a2) by finding or allocating a matching node, then enqueues it with state data and calls threshold comparison. Manages a free list and an active singly-linked list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10)+0x0) | 0x368 | RW | 0 | Node message type field |
| *(*(this+0x10)+0x0) | 0x36C | RW | 18446744073709551615 | Node byte flag field (0xFF/-1) |
| *(*(this+0x10)+0x0) | 0x370 | RW | 18446744073658219970 | Node value field (initial: -51331646) |
| *(*(this+0x28)+0x0) | 0x368 | R | — | Matching node's message type (for comparison) |
| *(*(this+0x28)+0x0) | 0x36C | R | — | Matching node's byte flag (for comparison) |
| *(this+0x10) | 0x0 | R | — | Doubly-linked free list head |
| *(this+0x10) | 0x8 | RW | 0 | Free list node flag (cleared to 0) |
| *(this+0x20) | 0x0 | R | — | Active list head pointer |
| *(this+0x24) | 0x4 | RW | — | Active list entry next link |
| *(this+0x28) | 0x0 | R | — | Walk position node pointer |
| *(this+0x28) | 0x4 | R | — | Walk position node next link |
| this | 0x10 | R | — | Doubly-linked free list head pointer |
| this | 0x18 | RW | — | Temporary list head copy |
| this | 0x20 | RW | — | Active singly-linked list head |
| this | 0x24 | RW | — | Active singly-linked list tail |
| this | 0x28 | RW | — | Current walk position |
| this | 0x2C | R | — | Active list entry count |
| this | 0x30 | R | — | Float value copied to node at 0x370 |

**Written-by note (persistence):**
- *(*(this+0x10)+0x0) 0x368: Written with message type from a2; overwritten each dispatch.
- *(*(this+0x10)+0x0) 0x36C: Written to 0xFF then overwritten with flag from a2; per-call.
- *(*(this+0x10)+0x0) 0x370: Written with float from this+0x30; per-call.
- *(this+0x10) 0x8: Cleared to 0; persists until node reused.
- *(this+0x24) 0x4: Written with new entry link; persists in list.
- this 0x18: Written with copy of this+0x10; temporary, per-call.
- this 0x20: Written with new entry on first insert; persists.
- this 0x24: Written with new entry tail; persists.
- this 0x28: Written with current walk position; per-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd24 | dword_5ACD24 | R | D3DRenderDefaultColor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ba7a0 | DoublyLinkedListNodeRemoval | Remove node from free list for reuse |
| 004ba980 | sub_4BA980 | Initialize newly allocated node structure |
| 004bad70 | CollisionNodeListInsertion | Insert node into collision/dynamic list |
| 004bae20 | LinkedListRemoveByValue | Remove entry from temporary working list |
| 004fffa0 | ThunkWithStructInitSubCalls | Initialize or finalize node state |
| 004fffb0 | ZoneThresholdComparisonWithConditionalAction | Compare zone threshold with node float value |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 4-byte or 12-byte entry structures |

**Guard conditions:** If this+0x20 (active list head) is NULL, skip matching walk and go to LABEL_9 (create new node). Walk compares *(node+0x368) against message type and *(node+0x36C) against message byte flag; advances via next link. If no match found, falls through to LABEL_9 to reuse free node or allocate new one.
