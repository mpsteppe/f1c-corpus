## UIItemNameSetter_00489c10 — Set item text at index

**Summary:** Walks linked list to node at index a2, copies string a3 into item's text buffer via StringCopyWithBufferRealloc. Returns 1 on success, 0 if index out of range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BA20 (0046ba20), sub_475150 (00475150), sub_47C360 (0047c360), UITextInputHandler (004896c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | next node link pointer in linked list |
| this | 0x90 | R | — | this[36] — linked list head pointer |
| this | 0x94 | R | — | this[37] — total items count (upper bound for index) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string buffer into item's text member |

**Guard conditions:** a2 (index) must be >= 0 AND < this[0x94] (item count); otherwise returns 0 without modification. a3 can be null — falls back to byte_5EA438.
