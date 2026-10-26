## TwoFieldSetterUpdate_004dcd80 — Update two position fields and re-render

**Summary:** Sets two object fields at offsets +0x14 and +0x18 with provided parameters (a2, a3), then triggers a re-render via sub_4DCA80 (four-corner rectangle render).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DTextRenderingWithScissorRectangle (0049b370), ShortComputation_f070 (0049f070), FloatToIntConversionDispatch (004dcda0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Width/offset X field (this[5]); updated to a2 each call |
| this | 0x18 | RW | — | Height/offset Y field (this[6]); updated to a3 each call |

**Written-by note (persistence):**
- this 0x14: written each call to a2; persists until overwritten by next call
- this 0x18: written each call to a3; persists until overwritten by next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dca80 | sub_4DCA80 | Render four-corner rectangle using updated fields |

**Guard conditions:** None — function executes unconditionally.
