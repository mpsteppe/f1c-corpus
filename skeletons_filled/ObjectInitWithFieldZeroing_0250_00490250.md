## ObjectInitWithFieldZeroing_0250_00490250 — WidgetListInit

**Summary:** Initializes a UI widget list object: calls base init, zeroes five state fields, and sets vtable pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer |
| this | 0xE0 | RW | 0 | Linked list head pointer |
| this | 0xE4 | RW | 0 | Linked list node count/tail pointer |
| this | 0xE8 | RW | 0 | Linked list field |
| this | 0xEC | RW | 0 | Linked list field |
| this | 0xF0 | RW | 0 | Linked list field |

**Written-by note (persistence):**
- this 0x0: Once — set to vtable pointer; persists.
- this 0xE0-0xF0: Once — zeroed at init; overwritten on subsequent modifications.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac760 | off_5AC760 | R | VTable_WidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | Base/sub-object initialization routine |

**Guard conditions:** None — unconditional.
