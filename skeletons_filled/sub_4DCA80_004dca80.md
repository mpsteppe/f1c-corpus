## sub_4DCA80_004dca80 — Four-corner rectangle render from struct fields

**Summary:** Renders a four-corner rectangle by computing corner positions from struct fields (base X/Y, width/height offsets, corner deltas) and calling sub_553650 four times with mode 0-3 to draw each corner/segment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TwoFieldSetterUpdate (004dcd80), PositionComputationWithAlignment (004dcdd0), FieldSetterCall_cf20 (004dcf20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Enable flag / guard: if non-null, rendering proceeds |
| this | 0x8 | R | — | Base X position (component 2) |
| this | 0xC | R | — | Base Y position (component 3) |
| this | 0x10 | R | — | Z size or dimension (component 4) |
| this | 0x14 | R | — | Width offset added to X (component 5) |
| this | 0x18 | R | — | Height offset added to Y (component 6) |
| this | 0x1C | R | — | Parameter ID passed to sub_553650 (component 7) |
| this | 0x20 | R | — | Corner delta X (component 8, float) |
| this | 0x24 | R | — | Corner delta Y (component 9, float) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553650 | sub_553650 | Draw rectangle corner/segment with mode (0-3), position, and delta parameters |

**Guard conditions:** Checks `*(_DWORD *)this` (offset 0x0) for non-null. PASSES (renders all 4 corners) when non-null. BLOCKED (skips rendering) when null.
