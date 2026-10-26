## UIListItemByIndex_00489a10 — Linked-list item string by index

**Summary:** Walks linked list starting from this[0x90] head pointer, following next-node links at offset 0x8C for a2 steps, returns string pointer at offset 0xB0 from target node. Returns byte_5EA438 default if string field null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BA20 (0046ba20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | next node link pointer in linked list |
| *(this+0x11C) | 0xB0 | R | — | string/text data field of list node |
| this | 0x90 | R | — | linked list head pointer (first node) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 (index) must be >= 0; list head (this[0x90]) must be non-null. If either fails, returns 0. If traversal reaches null before index, returns 0.
