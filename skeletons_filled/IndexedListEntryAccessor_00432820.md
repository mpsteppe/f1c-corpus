## IndexedListEntryAccessor_00432820 — LinkedIndexEntryStringGetter

**Summary:** Returns the first string from an indexed entry in a linked list. Validates index bounds, walks the list to the Nth node, and returns the entry's first string (or default application directory if null).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HTMLSeasonOutput (0046ee60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0x20)+0x4)+0x0) | 0x0 | R | — | First string field of the list entry |
| *(*(obj+0x20)+0x4) | 0x0 | R | — | Linked list node (pointer to entry data) |
| *(*(obj+0x20)+0x4) | 0x4 | R | — | Next node pointer in linked list |
| obj | 0x20 | R | — | Linked list head pointer |
| obj | 0x2C | R | — | Entry count (used for index bounds check) |
| this | 0x0 | R | — | Pointer to the containing structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Index a2 must be >= 0 and < entry count at *(this->field0 + 0x2C); else returns 0. If index > 0, walks linked list (next pointers at +4) until index reaches 0; if list ends prematurely, returns 0. Current node pointer must be non-null; entry data pointer must be non-null; first string must be non-null (defaults to byte_5EA438). All guards return 0 except the null-string case which returns the default path.
