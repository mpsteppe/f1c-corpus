## EmptyFunction_004484f0 — Squared magnitude / dot product of mixed-precision components

**Summary:** Computes sum of squares of three structure components: float² at offset 0 + double² at offset 4 + float² at offset 12. Returns squared magnitude (dot product with self). Used in collision mesh edge length calculation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveTriangleEdgeSubdivisionForCollision (0044aae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | float component 0 — squared for magnitude |
| this | 0x4 | R | — | double component 1 — squared for magnitude |
| this | 0xC | R | — | float component 2 — squared for magnitude |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional computation
