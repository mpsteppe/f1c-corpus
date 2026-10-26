## F_33MatrixVectorMultiply_004ed7b0 — 3x3 matrix * vector multiply

**Summary:** Multiplies a 3x3 matrix (9 floats at `this`) by input vector `a2`, stores result in `a3`. Pure math utility for rigid-body transforms.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleGeometryProximityTest (004ed420), RayTriangleIntersectionWithBarycentricCoordinate (004efbd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | matrix row 0, column 0 |
| this | 0x4 | R | — | matrix row 0, column 1 |
| this | 0x8 | R | — | matrix row 0, column 2 |
| this | 0xC | R | — | matrix row 1, column 0 |
| this | 0x10 | R | — | matrix row 1, column 1 |
| this | 0x14 | R | — | matrix row 1, column 2 |
| this | 0x18 | R | — | matrix row 2, column 0 |
| this | 0x1C | R | — | matrix row 2, column 1 |
| this | 0x20 | R | — | matrix row 2, column 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always performs full matrix-vector multiply.
