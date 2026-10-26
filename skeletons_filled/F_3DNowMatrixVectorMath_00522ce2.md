## F_3DNowMatrixVectorMath_00522ce2 — 3DNow! composite transformation matrix from rotation, translation, and scale components

**Summary:** Composes a 4x4 transformation matrix from up to 6 optional input parameters: computes 3x3 inverse of rotation a3 (same algorithm as sub_522B5B), constructs identity + translation from a2, applies a4 parameter data, then optionally post-multiplies by a6 rotation and adds translation a7. Handles all null-pointer cases with identity matrix fallback. Accumulates results iteratively over all non-null inputs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 col 0-1 (accumulated transform) |
| this | 0x8 | R | — | Output matrix row 0 col 2-3 |
| this | 0x10 | R | — | Output matrix row 1 col 0-1 |
| this | 0x18 | R | — | Output matrix row 1 col 2-3 |
| this | 0x20 | R | — | Output matrix row 2 col 0-1 |
| this | 0x28 | R | — | Output matrix row 2 col 2-3 |
| this | 0x30 | R | — | Output matrix row 3 col 0-1 (translation accumulated) |
| this | 0x38 | R | — | Output matrix row 3 col 2-3 (translation + homogeneous) |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots may be written multiple times during composition; final result is the accumulated composite transform.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af8e0 | qword_5AF8E0 | R | ThreeDNowMatrixInitConst [DERIVED] |
| 005af8f0 | qword_5AF8F0 | R | SSEZeroThreshold [DERIVED] |
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (SIMD constant for inverse computation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Multiple null-pointer guards: `if (a4)` → identity fallback; `if (a3)` → compute 3x3 inverse vs extract a4 directly; `if (a2)` → apply translation vs pure inverse output; `if (a6)` → post-multiply rotation; `if (a7)` → add final translation. Each guard selects between alternative computation paths.
