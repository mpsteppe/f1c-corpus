## F_3DNowBarycentricInterpolationWithNormalization_00521079 — 3DNow! barycentric triangle interpolation with per-region normalization

**Summary:** Computes barycentric coordinates from three edge vectors constructed from a2 vertex data, determines which of four triangle regions the point falls in via packed comparison masks, then for each region normalizes the interpolated result (pfrsqrt + Newton-Raphson + 0.5 scale) and blends vertex attributes (a2[1], a2[3], a2[4]) with sign-flip XOR (0x8000000000000000) into output a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First half of output interpolated + normalized vector (xy) |
| this | 0x8 | R | — | Second half of output interpolated + normalized vector (zw) |

**Written-by note (persistence):**
- this 0x0: Written once; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af8f0 | qword_5AF8F0 | R | SSEZeroThreshold [DERIVED] |
| 005af920 | qword_5AF920 | R | MMXSignFlipConst [DERIVED] |
| 005af968 | qword_5AF968 | R | ThreeDNow_Constant_5AF968 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Four-way branch via packed comparison mask in v13. `(v13 & 1) != 0` enters inner region block. Within that: `(v13 & 0xFF00FF00) == 0xFF00FF00` selects third region; `(v13 & 0x10000) != 0` selects second; else first inner region. When `(v13 & 1) == 0`: outer region selected. Each region uses different edge (v6, v7, v11, or v10) for normalization and different vertex-data blend formula.
