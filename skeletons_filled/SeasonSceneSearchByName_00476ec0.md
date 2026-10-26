## SeasonSceneSearchByName_00476ec0 — SeasonSceneNameMatcher

**Summary:** Searches a linked list of season scene nodes for one whose name string matches a filtered path obtained via `ConditionalDispatch_40b0`. Performs byte-by-byte comparison and stores match index at offset 0x174.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonSceneInitialization (00477720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x4) | 0x0 | R | — | first byte of name from first list node's value |
| *(*(this+0xF0)+0x4) | 0x1 | R | — | second byte of name from first list node's value |
| *(this+0xF0) | 0x4 | R | — | name string pointer from first list node |
| obj | 0xA0 | R | — | unknown field in dispatch result object |
| this | 0x0 | R | — | vtable pointer (virtual call at offset 160) |
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF8 | RW | — | linked list traversal cursor |
| this | 0xFC | R | — | unknown |
| this | 0x174 | RW | — | match result index |

**Written-by note (persistence):**
- this 0xF8: set to list head at start, updated each iteration; persists until next search
- this 0x174: set to loop index on match, remains unchanged if no match; persists until next search

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c40b0 | ConditionalDispatch_40b0 | resolves game filter path to a structure containing name data at offset 124 |

**Guard conditions:** `dword_7CE64C` resolved string must produce non-null dispatch result; `this[60]` (offset 0xF0) must be non-null; `*this[60]` (first node value) must be non-null; byte-by-byte comparison fails (v11 != 0) → continue to next node; match found (v11 == 0) → store index and return
