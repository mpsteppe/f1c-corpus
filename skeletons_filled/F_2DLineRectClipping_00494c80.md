## F_2DLineRectClipping_00494c80 — Clip line segment against axis-aligned rectangle

**Summary:** Clips a 2D line segment against a rectangle (width/height taken from a struct). Returns true if the clipped line has non-zero length and is visible.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatVectorWithConditionalTransform (00494c20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Line start point X coordinate |
| this | 0x4 | RW | — | Line start point Y coordinate |
| this | 0xC | R | — | Line end point X coordinate |
| this | 0x10 | R | — | Line end point Y coordinate |

**Written-by note (persistence):**
- this 0x0: conditional, updated when clipping moves the line start X to rectangle boundary
- this 0x4: conditional, updated when clipping moves the line start Y to rectangle boundary

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0 (line clipped away/not visible) if the line falls outside the rectangle in both X and Y directions. Rectangle bounds computed from a1+28 (width) and a1+32 (height). Final visibility determined by non-zero difference between start and end points.
