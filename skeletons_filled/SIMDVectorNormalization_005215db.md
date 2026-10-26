## SIMDVectorNormalization_005215db — 3DNow! vector slerp/interpolation with angle-dependent normalization

**Summary:** Computes dot product of input vectors a2 and a3, extracts sign and magnitude. If |dot| is below ~0.9999 threshold (0x3F7FFF58), computes sin via pfrsqrt(1-dot²) with Newton-Raphson refinement (F_3DVectorNormalize_8f00/sub_529700 helpers) and derives angle-based interpolation factors; otherwise uses simple (1-t, t) blend. Final result = (1-t_factor)*a2 + t_factor*a3 written to a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MMX3DNowVectorTransform (00521712), F_3DVectorBlend (0052179f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First half of output interpolated vector (xy) |
| this | 0x8 | R | — | Second half of output interpolated vector (zw) |

**Written-by note (persistence):**
- this 0x0: Written once at function end; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |
| 005af9e8 | qword_5AF9E8 | R | Unknown_QWord_Compare [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528f00 | F_3DVectorNormalize_8f00 | 3DNow! vector normalization helper (Newton-Raphson refinement step) |
| 00529700 | sub_529700 | 3DNow! helper for slerp/interpolation refinement (partial computation) |

**Guard conditions:** Checks `0x3F7FFF583F7FFF58LL >= v9` (is |dot| <= ~0.9999 threshold) via pfcmpge. BLOCKED (|dot| near 1.0, vectors nearly parallel): skips sin computation, uses simple lerp factors (t, 1-t). PASSES (|dot| small enough): enters full slerp path with reciprocal-sin computation and refined interpolation factors.
