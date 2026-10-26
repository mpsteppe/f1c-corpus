## PositionComputationWithAlignment_004dcdd0 — Compute position with 9-point alignment

**Summary:** Sets object Z/size field at +0x10, then computes X/Y position fields at +0x08 and +0x0C using one of 9 alignment modes (0-8) relative to anchor point (a2, a3) and object dimensions (width at +0x14, height at +0x18), then renders via sub_4DCA80.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DTextRenderingWithScissorRectangle (0049b370), ShortComputation_f070 (0049f070), sub_4DCBA0 (004dcba0), sub_4DCEE0 (004dcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Computed X position (this[2]) — set based on alignment mode |
| this | 0xC | RW | — | Computed Y position (this[3]) — set based on alignment mode |
| this | 0x10 | RW | — | Z/size value (this[4]) — set to a4 each call |
| this | 0x14 | R | — | Object width (this[5]) — used for alignment offset calculations |
| this | 0x18 | R | — | Object height (this[6]) — used for alignment offset calculations |

**Written-by note (persistence):**
- this 0x8: written each call; survives until overwritten by next call
- this 0xC: written each call; survives until overwritten by next call
- this 0x10: written each call to a4; survives until overwritten by next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004dcebc | jpt_4DCDE4 | R | Jump table for alignment mode dispatch (cases 0-8) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dca80 | sub_4DCA80 | Render four-corner rectangle using computed position fields |

**Guard conditions:** None — function always executes. Alignment mode `a5` (0-8) selects position computation formula; default case (unrecognized mode) renders without changing position.
