## UIListManagementHandler_0048a3c0 — List filter/transform manager

**Summary:** Filters and transforms linked list items by comparing strings against default path. Mode a2 determines filter direction (shorter/longer/lexicographic). Builds new linked list of matching items, sets head and count if empty, selects first match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47C360 (0047c360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | RW | — | this[36] — linked list head, written with new list if previously null |
| this | 0x94 | RW | — | this[37] — item count, preserved via local copy v28, written only if head was null |
| this | 0x168 | RW | 0 | this[90] — selection index, used as loop counter and selection tracker |

**Written-by note (persistence):**
- this 0x90: written once, only if previous head was null (set to new list head v25)
- this 0x94: written once, only if previous head was null (set to original count v28)
- this 0x168: written multiple times during processing (loop variable), then decremented; final value used for selection

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0048a634 | jpt_48A496 | R | jump table for switch on a2 mode (0-3) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004863c0 | ShortComputation_63c0 | gets list node pointer by index for iteration |
| 00486400 | UtilityFunction_6400 | creates/allocs new list node or copies existing item |
| 00489920 | UIScreenTextAccessor | gets text string from current screen/list item |
| 00489970 | UITextFormatHelper | formats/extracts path component from text |
| 00489ab0 | UIListSelectionHandler | selects item at tracked index after list build |
| 00566650 | StringCopyWithBufferRealloc | copies string buffer into item's text member |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory (called via utility functions) |
| 00587ece | sub_587ECE | returns string length for comparison |
| 00588410 | sub_588410 | string comparison (returns <0, 0, >0) |

**Guard conditions:** this[0x94] (item count) must be > 0 to enter processing loop. If head (this[0x36]) is non-null after loop, skips setting new head and count.
