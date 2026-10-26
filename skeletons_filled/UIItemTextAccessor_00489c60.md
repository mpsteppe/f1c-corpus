## UIItemTextAccessor_00489c60 — Get item text by index

**Summary:** Walks linked list to node at index a2, returns string pointer at offset 0xA0. Returns byte_5EA438 default if index out of range or string null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BA20 (0046ba20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | next node link pointer in linked list |
| *(this+0x11C) | 0xA0 | R | — | string text field of list node |
| this | 0x90 | R | — | this[36] — linked list head pointer |
| this | 0x94 | R | — | this[37] — total items count (upper bound for index) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 (index) must be >= 0 AND < this[0x94]; otherwise returns byte_5EA438. List head (this[0x90]) must be non-null; returns byte_5EA438 if traversal fails or target string is null.
