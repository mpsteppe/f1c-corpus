## LinkedListByteBufferInsert_00549250 — LinkedByteBufferNodeInsert

**Summary:** Inserts node `a2` into a doubly-linked list (next at offset 0x6C, prev at offset 0x68). Bit 4 of a2's first byte selects the head pointer source (this[0]+0x128 vs *a2). Handles first-insertion and subsequent-append based on this[0xF4] flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListWalkWithDispatch (005492b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0x128)+0x6C)+0x6C) | 0x6C | RW | — | pNext — forward pointer at offset 0x6C in linked list node |
| *(obj+0x128) | 0x6C | R | — | Head/first node pointer in the chain |
| obj | 0x128 | R | — | Pointer to chain head (selected when a2 bit 4 is set) |
| this | 0x0 | R | — | Base pointer whose deref plus 0x128 yields chain head reference |
| this | 0xF4 | RW | — | List initialization flag — non-null when list has at least one node |

**Written-by note (persistence):**
- *(*(*(obj+0x128)+0x6C)+0x6C) 0x6C: Written once per append to link previous tail to new tail; external poke breaks list linkage
- this 0xF4: Written once on first insertion; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Bit 4 (0x4) of a2's first byte selects head source: if set, head is `*(this[0] + 0x128)`; otherwise head is `*a2`. If this[0xF4] is NULL (first insertion), stores head into this[0xF4] and initializes a2's prev/next to 0. If non-null (list exists), walks chain via offset 0x6C to find tail and appends a2 bidirectionally.
