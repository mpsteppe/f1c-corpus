## UtilityFunction_7160_00487160 — CombinedXYOffsetLookup

**Summary:** Reads both X and Y offsets at index a2 from linked list via LinkedListIndexedFieldReader. If index exceeds boundary and guard flag (0xC8) is zero, returns 0 (failure). On success, writes base+X to a3 and base+Y to a4 and returns 1. Combines functionality of sub_487060 (Y) and sub_4870E0 (X).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475A90 (00475a90), F_2DRectangleDrawingWithOutline (00475d90), UITextBoxRendererWithScrollbar (004883d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | base X offset (this[1]) added to looked-up X value |
| this | 0xC | R | — | base Y offset (this[3]) added to looked-up Y value |
| this | 0xC8 | R | — | guard flag — must be set when index exceeds boundary; if zero, function fails |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049adb0 | ShortComputation_adb0 | get boundary/count from this+28 |
| 0049aec0 | LinkedListIndexedFieldReader | read indexed X and Y values from linked list |

**Guard conditions:** If a2 >= boundary (ShortComputation_adb0) AND this[50] (guard at 0xC8) is zero → return 0 (blocked). If LinkedListIndexedFieldReader fails → return 0 (blocked). Both guard conditions must pass for successful lookup.
