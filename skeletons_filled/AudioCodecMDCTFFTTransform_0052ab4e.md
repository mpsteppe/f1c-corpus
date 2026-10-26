## AudioCodecMDCTFFTTransform_0052ab4e — Audio Codec MDCT/FFT Butterfly Transform (MMX)

**Summary:** Performs an 8-point radix-2 MDCT/FFT butterfly transform on packed 16-bit audio data using MMX SIMD instructions. Two-pass: first computes 16 frequency-domain outputs via fixed-point multiply-accumulate with precomputed twiddle constants, then post-processes and quantizes to 8-bit PCM via lookup table. Part of the audio codec pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderingBranchOnDAT005d79dc (0052855a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input sample pair 0 (a1[0]: 4 packed 16-bit shorts = 2 complex values) |
| this | 0x10 | R | — | input sample pair 2 (a1[2], read in butterfly stage 1) |
| this | 0x20 | R | — | input sample pair 4 (a1[4], read via v6 = _m_pmullw(a1[4], a2[4])) |
| this | 0x30 | R | — | input sample pair 6 (a1[6], read via v107 = _m_pmullw(a1[6], a2[6])) |
| this | 0x40 | R | — | input sample pair 8 (a1[8], read via v17 = _m_pmullw(a1[8], a2[8])) |
| this | 0x50 | R | — | input sample pair 10 (a1[10], read via v106 = _m_pmullw(a1[10], a2[10])) |
| this | 0x60 | R | — | input sample pair 12 (a1[12], read via v7 = _m_pmullw(a1[12], a2[12])) |
| this | 0x70 | R | — | input sample pair 14 (a1[14], read via v104 = _m_pmullw(a1[14], a2[14])) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b0b98 | qword_5B0B98 | R | Qword_CompressionTable [DERIVED] |
| 005b0ba0 | qword_5B0BA0 | R | AudioCodec_QWord_5B0BA0 [DERIVED] |
| 005b0ba8 | qword_5B0BA8 | R | SIMD_MADD_QWordA [DERIVED] |
| 005b0bb0 | qword_5B0BB0 | R | AudioMixConst [DERIVED] |
| 005b0bb8 | qword_5B0BB8 | R | PackedShortMulConst1 [DERIVED] |
| 005b0bc0 | qword_5B0BC0 | R | FixedPointMultiplyConst [DERIVED] |
| 005b0bc8 | qword_5B0BC8 | R | AudioMixWorkspace [DERIVED] |
| 005b0bd0 | qword_5B0BD0 | R | MMXConstQword [DERIVED] |
| 005b0bd8 | qword_5B0BD8 | R | PixelBlendFactor [DERIVED] |
| 005b0be0 | qword_5B0BE0 | R | AudioCodecStruct [DERIVED] |
| 005b0be8 | qword_5B0BE8 | R | AudioMixCoeffs [DERIVED] |
| 005b0bf0 | qword_5B0BF0 | R | Unknown_QWord_MMX [DERIVED] |
| 005b0bf8 | qword_5B0BF8 | R | ShortMultiplyConstLo [DERIVED] |
| 005b0c00 | qword_5B0C00 | R | SSE_Matrix_MultConst [DERIVED] |
| 005b0c08 | qword_5B0C08 | R | MMX_PackedConst_5B0C08 [DERIVED] |
| 005b0c10 | qword_5B0C10 | R | SIMDPackedMultiplyConst [DERIVED] |
| 005b0c18 | qword_5B0C18 | R | ShortMultiplyConstHi [DERIVED] |
| 005b0c20 | qword_5B0C20 | R | SSE_Matrix_AddConst [DERIVED] |
| 005b0c28 | qword_5B0C28 | R | AudioDecodeBuffer [DERIVED] |
| 005b0c30 | qword_5B0C30 | R | SIMD64MatrixCoeff [DERIVED] |
| 005b0c38 | qword_5B0C38 | R | Qword_SSE_Const [DERIVED] |
| 005b0c40 | qword_5B0C40 | R | SIMD_MADD_QWordB [DERIVED] |
| 005b0c48 | qword_5B0C48 | R | MMXConstQword2 [DERIVED] |
| 005b0c50 | qword_5B0C50 | R | AudioMixConst2 [DERIVED] |
| 005b0c58 | qword_5B0C58 | R | JPEG_HuffmanTable_5B0C58 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — unconditional transform. Both passes execute fully: first pass runs 2 iterations (v117=2) of 8-element butterfly with constant twiddle factors, second pass runs 8 iterations (v118=8) of post-processing with rounding (add 0x2000000020000, arithmetic shift right 18) and 8-bit lookup table quantization into output buffer at a5.