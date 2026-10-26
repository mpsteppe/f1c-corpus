## StateUpdateWithDecrement_00489560 — SelectionIndexDecrementByStep

**Summary:** Calls notification method (+44) with arg 1, decrements counter at 0x14C by step at 0x164, clamps to minimum 0, then calls sub_489D00 and FloatToIntConversion to update visual state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollbarThumbDragHandler (0048a650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual +44 — notification callback (change handler) |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0x14C | RW | — | Counter/selection index (decremented by step) |
| this | 0x164 | R | — | Step size for decrement |

**Written-by note (persistence):**
- this 0x14C: Written conditionally — set to result of decrement, clamped >= 0.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489d00 | sub_489D00 | Refresh/update scroll list visual state |
| 00489e90 | FloatToIntConversion | Convert internal float position to int |

**Guard conditions:** None — unconditional operation.
