## DecrementCounterVirtualCall_00489500 — SelectionIndexDecrement

**Summary:** Calls notification method (+44) with arg 1, decrements counter at 0x14C by 1, then calls sub_489D00 and FloatToIntConversion to update visual state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollbarThumbDragHandler (0048a650), UIScrollListUpdate (0048a8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual +44 — notification callback (change handler) |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0x14C | R | — | Counter/selection index being decremented |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489d00 | sub_489D00 | Refresh/update scroll list visual state |
| 00489e90 | FloatToIntConversion | Convert internal float position to int |

**Guard conditions:** None — unconditional operation.
