## F_4x4TransformationMatrixConstructor_0052401f — 3DNow! construct 4x4 transform from scale, rotation, and translation

**Summary:** Builds composite 4x4 transformation matrix: starts with diagonal scale matrix from parameter a2 (repeated at a1[0], a1[2] high, a1[5]), then if a4 (rotation) is non-null, computes 3x3 adjugate/inverse rotation matrix (same pattern as sub_522B5B) and optionally applies a3 translation by subtraction + matrix multiply. Finally applies a5 additive translation if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 col 0-1 (scale + rotation components) |
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
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (SIMD constant for inverse computation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Three null-pointer guards: `if (a4)` → compute 3x3 rotation matrix; nested `if (a3)` → subtract a3 translation from result then apply matrix multiply; `if (a5)` → add final translation to result row 3.
