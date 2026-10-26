## RayTriangleIntersectionWithBarycentricCoordinate_004efbd0 — RayTriangleIntersectionWithBarycentric

**Summary:** Computes ray-triangle intersection distance using barycentric coordinates. Returns minimum ride height delta clamped at 0.025, or `this[3371]` (rest height) if no valid intersection found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapSplitTimeEvent (004bc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34AC | R | — | Rest ride height value returned when intersection behind or beyond 0.025 threshold |
| this | 0x34B0 | R | — | Ray direction/orientation vector component X (row 0 of 3x3 matrix) |
| this | 0x34B4 | R | — | Ray direction/orientation vector component Y (row 1 of 3x3 matrix) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] — Ray direction/orientation vector component Z (row 2 of 3x3 matrix) |
| this | 0x34BC | R | — | Orientation matrix row 3 (3x3 matrix stored row-major) |
| this | 0x34C0 | R | — | Orientation matrix row 4 |
| this | 0x34C4 | R | — | Orientation matrix row 5 |
| this | 0x34C8 | R | — | Orientation matrix row 6 |
| this | 0x34CC | R | — | Orientation matrix row 7 |
| this | 0x34D0 | R | — | Orientation matrix row 8 |
| this | 0x34D4 | R | — | Position offset X (translation component) |
| this | 0x34D8 | R | — | Position offset Y |
| this | 0x34DC | R | — | Position offset Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ec020 | F_3DVectorAddition | Adds two 3D vectors |
| 004ed710 | Vec3Add | Adds two 3D vectors (alternate impl) |
| 004ed750 | F_3DCrossProduct | Computes cross product of two 3D vectors |
| 004ed7b0 | F_33MatrixVectorMultiply | Multiplies 3x3 matrix by 3D vector |
| 004ef680 | RideHeightDelta | Computes ride height delta for suspension |
| 004efee0 | sub_4EFEE0 | Computes dot product or similar vector arithmetic |

**Guard conditions:** If intersection denominator `v14 == 0.0`, returns `this[3371]` (rest height). Clamps ray parameter: if `v23 < 0.0` (behind ray origin) returns rest height; if `v23 <= 0.025` returns `this[3371] - v23`; otherwise returns `this[3371] - 0.025`.
