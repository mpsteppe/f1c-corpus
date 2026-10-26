## IndexedEntryAccessor_00432930 — IndexedListEntryStringGetterAlt

**Summary:** Returns the first string from an indexed entry in a linked list, using different offsets (count at 0x3C, list head at 0x30). Validates index bounds, walks the list to the Nth node, and returns the entry's first string or default path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExtensionStripperForAllListEntries (0046f170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0x30)+0x4)+0x0) | 0x0 | R | — | First string field of the list entry |
| *(*(obj+0x30)+0x4) | 0x0 | R | — | Linked list node (pointer to entry data) |
| *(*(obj+0x30)+0x4) | 0x4 | R | — | Next node pointer in linked list |
| obj | 0x30 | R | — | Linked list head pointer (different offset from sibling) |
| obj | 0x3C | R | — | Entry count (used for index bounds check) |
| this | 0x0 | R | — | Pointer to the containing structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Index a2 must be >= 0 and < entry count at *(this->field0 + 0x3C); else returns 0. If index > 0, walks linked list (next pointers at +4) until index reaches 0; if list ends prematurely, returns 0. Current node must be non-null; entry data must be non-null; first string must be non-null (defaults to byte_5EA438). All guards return 0 except null-string case which returns default path.
