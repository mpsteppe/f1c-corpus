## Quaternion3DMath_005219e1 — 3DNow! multi-quaternion composition with sign optimization and normalization

**Summary:** Processes up to 4 input quaternions (a5, a6, a7, a8): compares sum-vs-difference squared lengths to determine optimal sign flips (shortest path), negates selected inputs via XOR 0x80000000, computes negate-and-divide-by-squared-length of a6, performs quaternion multiplications with cross-term accumulation (pfadd/pfsub/pfmul/pfacc), normalizes intermediate results via >=1.0 guard with SquareRootApproximation and pfrcp refinement, and writes three output quaternions (a2, a3, a4).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af918 | qword_5AF918 | R | MMX_PackedConstant [DERIVED] |
| 005af928 | qword_5AF928 | R | CollisionSATWorkspace [DERIVED] |
| 005af938 | qword_5AF938 | R | MMX_3DNow_QuadConstant_1 [DERIVED] |
| 005af940 | qword_5AF940 | R | ThreeDNow_AndMask_Packed [DERIVED] |
| 005af948 | qword_5AF948 | R | SIMDCompareThreshold [DERIVED] |
| 005af950 | qword_5AF950 | R | SIMDQuadMask [DERIVED] |
| 005af970 | qword_5AF970 | R | VectorLengthSquaredThreshold [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |
| 005b06e0 | qword_5B06E0 | R | AABBTreeSplitData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00529000 | SquareRootApproximation | Reciprocal sqrt approximation (Newton-Raphson step) |
| 005295e0 | PackedFloatingPointMath | Component setup/expansion helper for 3DNow! quaternion arithmetic |
| 00529700 | sub_529700 | 3DNow! helper for normalization refinement (partial computation) |

**Guard conditions:** Multiple guards: (1) Byte mask from packsswb(pfcmpgt(sqsum_diff, sqsum_sum)) selects which input quaternions (a5, a7) to negate for shortest-path. (2) `pfcmpgt(pfacc(sqsum_s3d), pfacc(sqsum_s2d))` decides sign flip for a8. (3) Repeated `pfcmpge(component, 1.0)` guards skip sqrt/rcp normalization when component already >= 1.0. (4) `pfcmpge(|component|, 0x34000000)` guards against near-zero division in pfrcp refinement.
