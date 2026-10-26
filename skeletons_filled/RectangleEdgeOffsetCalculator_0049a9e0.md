## RectangleEdgeOffsetCalculator_0049a9e0 — RectangleRelativeOffsetCalculator

**Summary:** Computes the offset of a rectangle (a2,a3)-(a4,a5) relative to a reference point stored at offsets 0x04 (y) and 0x0C (x). Stores the four relative edge values at offsets 0x14-0x20. Returns the relative bottom edge.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492710 (00492710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | reference Y coordinate |
| this | 0xC | R | — | reference X coordinate |
| this | 0x14 | RW | — | relative left edge (a2 - ref_x) |
| this | 0x18 | RW | — | relative top edge (a3 - ref_y) |
| this | 0x1C | RW | — | relative right edge (a4 - ref_x) |
| this | 0x20 | RW | — | relative bottom edge (a5 - ref_y, also returned) |

**Written-by note (persistence):**
- this 0x14: computed from a2 - ref_x; external poke survives
- this 0x18: computed from a3 - ref_y; external poke survives
- this 0x1C: computed from a4 - ref_x; external poke survives
- this 0x20: computed from a5 - ref_y; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line arithmetic, no branches.
