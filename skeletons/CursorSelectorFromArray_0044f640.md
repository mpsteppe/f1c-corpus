## CursorSelectorFromArray_0044f640 — Select and activate cursor by index

**Summary:** Selects a loaded cursor from the handle array by index, sets it as the active Windows cursor via SetCursor, and stores the selected index. Returns 1 on success, 0 if index is out of range or handle is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44F4E0 (0044f4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | R | — | Cursor image count — validates selection range |
| this | 0xAC | RW | — | Currently selected cursor index |

**Written-by note (persistence):**
- this 0xAC: set unconditionally on successful selection; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2b0 | SetCursor | R | Windows SetCursor import — activates the chosen cursor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKED if a2 < 0 OR a2 >= this[42] (count at 0xA8) OR handle at this[5*a2+12] is null → returns 0. PASSES on valid index with non-null handle.
