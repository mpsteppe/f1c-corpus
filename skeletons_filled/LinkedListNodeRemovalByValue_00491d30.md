## LinkedListNodeRemovalByValue_00491d30 — Remove linked list node by value match

**Summary:** Removes first node from singly-linked list whose first DWORD matches the value parameter. Updates head/tail/cached-end pointers, decrements count, optionally frees node data payload.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourcePoolNodeAllocDealloc (00490940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x0 | R | — | Node value/key field (first DWORD, compared against a2) |
| *(obj+0x4) | 0x4 | R | — | Node next pointer |
| *(obj+0x4) | 0x8 | RW | 0 | Node flag byte (controls whether node data is freed on removal) |
| obj | 0x4 | RW | — | List tail pointer (this[1]) |
| this | 0x0 | RW | — | List head pointer |
| this | 0x4 | RW | — | List tail pointer |
| this | 0x8 | RW | — | Cached iterator/end pointer |
| this | 0xC | R | — | List node count |

**Written-by note (persistence):**
- *(obj+0x4) 0x8: conditional, cleared when a3==0 (force-clear); if a3!=0, unchanged by this function
- obj 0x4: conditional, set to previous node (or next node) when removed node is tail
- this 0x0: conditional, set to next node when removed node is head
- this 0x4: conditional, set to previous node when removed node is tail
- this 0x8: conditional, updated when removed node matches cached iterator position

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees node allocation and optionally its data payload |

**Guard conditions:** Returns 0 (failure) if a2 is null or list head is null. Walks nodes via next pointer at offset +0x4, returns 0 if value not found (no node match). On match, unlinks node and returns 1 (success).
