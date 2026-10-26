## MenuActionDispatch_004b9da0 — Menu action dispatch by ID

**Summary:** Dispatches menu UI actions based on switch value. Stores action ID 0-8 at menu state field (0xF8C), or delegates to list/display cleanup routines for actions 9-13.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF8C | RW | — | Current menu action ID slot (actions 0-8) |
| this | 0x0 | R | — | Pointer to internal menu data block |

**Written-by note (persistence):**
- obj 0xF8C: overwritten per call for actions 0-8; does not persist across frames

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b9e04 | jpt_4B9DB0 | R | Jump table for switch dispatch |
| 004b9e1c | byte_4B9E1C | R | Padding or unreferenced data after table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b81a0 | SortedLinkedListInsert | Insert zero-valued node into sorted list (action 9) |
| 004b8360 | SpriteOverlayDisplayListCleanup | Clean up sprite overlay display list (action 10) |
| 004b8480 | LinkedListDestructor_8480 | Destroy linked list (action 11) |
| 004b84f0 | SortedListSeekByValue | Seek sorted list by value (action 12) |
| 004b85d0 | LinkedListPrioritySearchByFloatThreshold | Search list by float threshold (action 13) |

**Guard conditions:** None — all switch cases handled (0-13 + default). Always returns 1.
