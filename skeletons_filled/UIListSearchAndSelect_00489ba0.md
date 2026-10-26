## UIListSearchAndSelect_00489ba0 — Search linked list and select item

**Summary:** Searches linked list by string comparison (sub_588410) against node text at offset 0xB0. On match, calls UIListSelectionHandler to set selection and update display. Returns 0 on success, -1 if not found or null inputs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475150 (00475150), sub_47BF30 (0047bf30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | next node link pointer in linked list |
| this | 0x90 | R | — | this[36] — linked list head pointer |
| this | 0x140 | R | — | unknown — not directly referenced in this function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489ab0 | UIListSelectionHandler | selects item at found index (calls display update) |
| 00588410 | sub_588410 | string comparison — returns 0 on match (used in `!sub_588410(v6, a2)` to break loop) |

**Guard conditions:** a2 (search string) must be non-null; this[0x90] (head pointer) must be non-null. If either null, returns -1 immediately. If traversal reaches end without match, returns -1.
