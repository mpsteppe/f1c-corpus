## F_4x4MatrixMultiply_0050cbb6 — 4x4 Matrix Multiply

**Summary:** Multiplies two 4x4 matrices (a2 * a3) and stores result in a1. Handles aliasing (when a1 overlaps a2 or a3) by computing into a stack temporary then copying result.

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
- this 0x0-0x3C: all 16 elements written unconditionally with computed product; output buffer, ephemeral

**Globals referenced:** none

**Functions called:** none

**Guard conditions:** 
- if a1 == a2 (output aliases first input) OR a1 == a3 (output aliases second input): compute into stack temporary buffer first, then qmemcpy to a1. Otherwise compute directly into a1.
