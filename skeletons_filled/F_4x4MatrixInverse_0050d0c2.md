## F_4x4MatrixInverse_0050d0c2 — 4x4 Matrix Inverse

**Summary:** Computes inverse of 4x4 matrix using cofactor/adjugate method. Computes determinant via 3x3 sub-determinants; if non-zero (checked via ArithmeticComparison_a88f), writes inverse to a1 and returns a1. Otherwise returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix element [0][0] |
| this | 0x4 | RW | — | Output matrix element [0][1] |
| this | 0x8 | RW | — | Output matrix element [0][2] |
| this | 0xC | RW | — | Output matrix element [0][3] |
| this | 0x10 | RW | — | Output matrix element [1][0] |
| this | 0x14 | RW | — | Output matrix element [1][1] |
| this | 0x18 | RW | — | Output matrix element [1][2] |
| this | 0x1C | RW | — | Output matrix element [1][3] |
| this | 0x20 | RW | — | Output matrix element [2][0] |
| this | 0x24 | RW | — | Output matrix element [2][1] |
| this | 0x28 | RW | — | Output matrix element [2][2] |
| this | 0x2C | RW | — | Output matrix element [2][3] |
| this | 0x30 | RW | — | Output matrix element [3][0] |
| this | 0x34 | RW | — | Output matrix element [3][1] |
| this | 0x38 | RW | — | Output matrix element [3][2] |
| this | 0x3C | RW | — | Output matrix element [3][3] |

**Written-by note (persistence):**
- this 0x0-0x3C: all 16 elements written conditionally (only if matrix is invertible); output buffer, ephemeral

**Globals referenced:** none

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a88f | ArithmeticComparison_a88f | Compares reciprocal determinant against zero to determine if matrix is singular |

**Guard conditions:** 
- if a2 (determinant output pointer) is non-NULL: write determinant value to *a2.
- if 1.0/determinant passes ArithmeticComparison_a88f (non-singular): compute inverse = adjugate * (1/det), write all 16 elements to a1, return a1.
- if singular (determinant near zero): skip inverse computation, return 0.
