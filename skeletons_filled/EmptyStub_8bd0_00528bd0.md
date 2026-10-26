## EmptyStub_8bd0_00528bd0 — SSEPolynomialApproximation

**Summary:** SSE SIMD polynomial approximation with coefficient table chain. Despite "EmptyStub" name, performs substantial computation: multiply-add polynomial evaluation across 13 XMM constants, integer shift/compare, conditional blend between two shuffle paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SSEVectorMatrixInit (0052087e), SSEMatrixConstructionFrom44Data (005208fe)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d9080 | xmmword_5D9080 | R | Xmmword_5D9080 [DERIVED] |
| 005d9090 | xmmword_5D9090 | R | SSE_Const_5D9090 [DERIVED] |
| 005d90a0 | xmmword_5D90A0 | R | SSERoundConstant [DERIVED] |
| 005d90b0 | xmmword_5D90B0 | R | CodecDummyGlobal [DERIVED] |
| 005d90c0 | xmmword_5D90C0 | R | SIMDPixelConst [DERIVED] |
| 005d90d0 | xmmword_5D90D0 | R | D3DColorXmmword [DERIVED] |
| 005d90e0 | xmmword_5D90E0 | R | SSE_Const_5D90E0 [DERIVED] |
| 005d90f0 | xmmword_5D90F0 | R | XMM_CropConst [DERIVED] |
| 005d9100 | xmmword_5D9100 | R | XMMConst_5D9100 [DERIVED] |
| 005d9110 | xmmword_5D9110 | R | SIMD_UnusedConstant [DERIVED] |
| 005d9120 | xmmword_5D9120 | R | SSEConstBlend [DERIVED] |
| 005d9130 | xmmword_5D9130 | R | SIMD_3DNowConst [DERIVED] |
| 005d9140 | xmmword_5D9140 | R | XMMWORD_5D9140 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** SSE packed compare `_mm_cmpneq_ps` of left-shifted integer v16 against zero (line 45). If non-zero (PASS path A): select polynomial result via `_mm_and_ps(v20, v19)`. If zero (PASS path B): select shuffled result via `_mm_andnot_ps(v20, v19)` followed by 177-shuffle. Final XOR blend combines selected path with masked input and shifted constants.
