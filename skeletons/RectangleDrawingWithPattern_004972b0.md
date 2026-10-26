## RectangleDrawingWithPattern_004972b0 — DrawConcentricRectanglesWithBorder

**Summary:** Draws concentric rectangles inward from given bounds (a4-top, a5-bottom, a6-left, a7-right), repeated `a3` times. Each iteration draws four edges with alternating colors (v18/v19) for 3D bevel effect, then shrinks rectangle by 1px per side.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_7260 (00497260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494bf0 | DelegationWrapper | Wraps delegate call with rectangle bounds |
| 00494c20 | FloatVectorWithConditionalTransform | Draws a single edge (line segment) with color |
| 00495150 | GlobalAccessor_5150 | Returns global rendering context object |

**Guard conditions:** Parameter a3 (iteration count) — if ≤ 0, entire drawing loop is skipped. Inner loop also checks counter v20 > 0 before shrinking rectangle.
