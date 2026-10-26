## RGBAColorSpaceConversion_005289e0 — RGBAColorSpaceDecodeSSE

**Summary:** Decode RGBA color from compressed/encoded format using SSE SIMD. Performs channel bit masking, dequantization via coefficients, polynomial approximation, and conditional blend between two decode paths based on zero-comparison.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** QuaternionConstructionTransform (0051febe)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Input packed color data (a1[0], first __m128 of 4 RGBA channels) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8f30 | xmmword_5D8F30 | R | Xmm_SSE_ColorXform [DERIVED] |
| 005d8f40 | xmmword_5D8F40 | R | SIMDColorConvMask [DERIVED] |
| 005d8f50 | xmmword_5D8F50 | R | SIMDColorMask [DERIVED] |
| 005d8f60 | xmmword_5D8F60 | R | ColorTransformCoeff4 [DERIVED] |
| 005d8f70 | xmmword_5D8F70 | R | TexelDecodeCoefficients [DERIVED] |
| 005d8f80 | xmmword_5D8F80 | R | Unknown_XMM_Filter [DERIVED] |
| 005d8f90 | xmmword_5D8F90 | R | SIMDColorMask [DERIVED] |
| 005d8fa0 | dword_5D8FA0 | R | BitMergeMask [DERIVED] |
| 005d8fb0 | xmmword_5D8FB0 | R | BitmaskOverflowTable [DERIVED] |
| 005d8fc0 | xmmword_5D8FC0 | R | Xmmword_3DNowMatrixMask [DERIVED] |
| 005d8fd0 | xmmword_5D8FD0 | R | SSE_ColorSpaceMatrix [DERIVED] |
| 005d8fe0 | xmmword_5D8FE0 | R | PolyCoeff0 [DERIVED] |
| 005d8ff0 | xmmword_5D8FF0 | R | DCTBiasOffset [DERIVED] |
| 005d9000 | xmmword_5D9000 | R | SSEDecodeBias [DERIVED] |
| 005d9010 | xmmword_5D9010 | R | DCTTransformCoeff [DERIVED] |
| 005d9020 | xmmword_5D9020 | R | SIMDColorUnpackConst [DERIVED] |
| 005d9030 | xmmword_5D9030 | R | DequantizeCoeff [DERIVED] |
| 005d9040 | xmmword_5D9040 | R | CodecCoefficientBase [DERIVED] |
| 005d9050 | xmmword_5D9050 | R | D3DVertexChannelMask [DERIVED] |
| 005d9060 | xmmword_5D9060 | R | ColorChannelBitMasks [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** SSE packed compare `_mm_cmpneq_ps` of intermediate decode value against zero (line 52). If any channel non-zero: select path A (polynomial decode via coefficients, store to a2). If zero: select path B (alternate decode via different coefficient set, store to a3). Final XOR blending with masked input.
