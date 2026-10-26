## F_32PointMDCTAudioTransform_00531b50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioMixerFloatingPointTo16BitPCMConversion (00531830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x140 | RW | — | [LLM] |
| this | 0x180 | RW | — | [LLM] |
| this | 0x1C0 | RW | — | [LLM] |
| this | 0x200 | RW | — | [LLM] |
| this | 0x240 | RW | — | [LLM] |
| this | 0x280 | RW | — | [LLM] |
| this | 0x2C0 | RW | — | [LLM] |
| this | 0x300 | RW | — | [LLM] |
| this | 0x340 | RW | — | [LLM] |
| this | 0x380 | RW | — | [LLM] |
| this | 0x3C0 | RW | — | [LLM] |
| this | 0x400 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0x100: [LLM: once/conditional? does external poke survive?]
- this 0x140: [LLM: once/conditional? does external poke survive?]
- this 0x180: [LLM: once/conditional? does external poke survive?]
- this 0x1C0: [LLM: once/conditional? does external poke survive?]
- this 0x200: [LLM: once/conditional? does external poke survive?]
- this 0x240: [LLM: once/conditional? does external poke survive?]
- this 0x280: [LLM: once/conditional? does external poke survive?]
- this 0x2C0: [LLM: once/conditional? does external poke survive?]
- this 0x300: [LLM: once/conditional? does external poke survive?]
- this 0x340: [LLM: once/conditional? does external poke survive?]
- this 0x380: [LLM: once/conditional? does external poke survive?]
- this 0x3C0: [LLM: once/conditional? does external poke survive?]
- this 0x400: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b772c | flt_5B772C | R | DCT_CosineTable_00 [DERIVED] |
| 005b7730 | flt_5B7730 | R | DCTTransformCoeff [DERIVED] |
| 005b7734 | flt_5B7734 | R | Render_MatrixCoeff_5B7734 [DERIVED] |
| 005b7738 | flt_5B7738 | R | Unknown_Float_DCT [DERIVED] |
| 005b773c | flt_5B773C | R | DCTScalingCoeff1 [DERIVED] |
| 005b7740 | flt_5B7740 | R | DCT_TransformCoeff [DERIVED] |
| 005b7744 | flt_5B7744 | R | DCT_Coefficient07 [DERIVED] |
| 005b7748 | flt_5B7748 | R | DCT_Coefficient_5B7748 [DERIVED] |
| 005b774c | flt_5B774C | R | DCTTransformCoeff_774c [DERIVED] |
| 005b7750 | flt_5B7750 | R | DCTCoeff9 [DERIVED] |
| 005b7754 | flt_5B7754 | R | AudioMixCoeff_7754 [DERIVED] |
| 005b7758 | flt_5B7758 | R | DCTCoefficient_05B7758 [DERIVED] |
| 005b775c | flt_5B775C | R | WaveletCoeff14 [DERIVED] |
| 005b7760 | flt_5B7760 | R | FilterWeight_d14 [DERIVED] |
| 005b7764 | flt_5B7764 | R | DCT_Weight14 [DERIVED] |
| 005b7768 | flt_5B7768 | R | YUVConvMatrixCoeff [DERIVED] |
| 005b776c | flt_5B776C | R | DCTCrossCoeff0 [DERIVED] |
| 005b7770 | flt_5B7770 | R | AudioMixCoeff_7770 [DERIVED] |
| 005b7774 | flt_5B7774 | R | DCTCoefficient_05B7774 [DERIVED] |
| 005b7778 | flt_5B7778 | R | WaveletTransformAdd [DERIVED] |
| 005b777c | flt_5B777C | R | FilterWeight_d15 [DERIVED] |
| 005b7780 | flt_5B7780 | R | DCT_Weight16 [DERIVED] |
| 005b7784 | flt_5B7784 | R | YUVConvMatrixCoeff2 [DERIVED] |
| 005b7788 | flt_5B7788 | R | DCTScaleFactor3 [DERIVED] |
| 005b778c | flt_5B778C | R | DCT_Weight17 [DERIVED] |
| 005b7790 | flt_5B7790 | R | DCTTransformCoeff2 [DERIVED] |
| 005b7794 | flt_5B7794 | R | DCTConst_7794 [DERIVED] |
| 005b7798 | flt_5B7798 | R | YUVConvMatrixCoeff3 [DERIVED] |
| 005b779c | flt_5B779C | R | DCTCoeff15 [DERIVED] |
| 005b77a0 | flt_5B77A0 | R | DCTScaleFactor4 [DERIVED] |
| 005b77a4 | flt_5B77A4 | R | DCTCoefficient_05B77A4 [DERIVED] |
| 008b5924 | flt_8B5924 | RW | FilterCoeff_8B5924 [DERIVED] |
| 008b5928 | flt_8B5928 | RW | DCT_Coeff [DERIVED] |
| 008b592c | flt_8B592C | RW | ColorTransformChromaB [DERIVED] |
| 008b5930 | flt_8B5930 | RW | DCTScaleFactor0 [DERIVED] |
| 008b5934 | flt_8B5934 | RW | DCTDifferenceCoeff [DERIVED] |
| 008b5938 | flt_8B5938 | RW | Flt_DCT_Coeff [DERIVED] |
| 008b593c | flt_8B593C | RW | DCTTransformCoeff0 [DERIVED] |
| 008b5940 | flt_8B5940 | RW | DCT_Output_00 [DERIVED] |
| 008b5944 | flt_8B5944 | RW | DCTOutputCoeff1 [DERIVED] |
| 008b5948 | flt_8B5948 | RW | Render_Bicubic_8B5948 [DERIVED] |
| 008b594c | flt_8B594C | RW | Unknown_Float_DCT_Write [DERIVED] |
| 008b5950 | flt_8B5950 | RW | DCTOutputBuffer1 [DERIVED] |
| 008b5954 | flt_8B5954 | RW | DCT_OutputBuffer [DERIVED] |
| 008b5958 | flt_8B5958 | RW | DCT_OutputBuffer0 [DERIVED] |
| 008b595c | flt_8B595C | RW | DCT_Output_8B595C [DERIVED] |
| 008b5960 | flt_8B5960 | RW | DCTOutputCoeff [DERIVED] |
| 008b5964 | flt_8B5964 | RW | Render_Bicubic_8B5964 [DERIVED] |
| 008b5968 | flt_8B5968 | RW | DCTOutputCoeff2 [DERIVED] |
| 008b596c | flt_8B596C | RW | DCT_Output_01 [DERIVED] |
| 008b5970 | flt_8B5970 | RW | DCTTransformCoeff1 [DERIVED] |
| 008b5974 | flt_8B5974 | RW | Flt_DCT_Coeff2 [DERIVED] |
| 008b5978 | flt_8B5978 | RW | DCTDiffCoeff2 [DERIVED] |
| 008b597c | flt_8B597C | RW | DCTScaleFactor1 [DERIVED] |
| 008b5980 | flt_8B5980 | RW | ColorTransformChromaR [DERIVED] |
| 008b5984 | flt_8B5984 | RW | DCT_Coeff2 [DERIVED] |
| 008b5988 | flt_8B5988 | RW | FilterCoeff_8B5988 [DERIVED] |
| 008b598c | flt_8B598C | RW | WaveletDSPFloat [DERIVED] |
| 008b5990 | flt_8B5990 | RW | DCTOutputBlock [DERIVED] |
| 008b5994 | flt_8B5994 | RW | AudioMixBuffer [DERIVED] |
| 008b5998 | flt_8B5998 | RW | IDCTOutputBuffer [DERIVED] |
| 008b599c | flt_8B599C | RW | DCTWorkspaceFloat [DERIVED] |
| 008b59a0 | flt_8B59A0 | RW | DCT_Coefficient_8B59A0 [DERIVED] |
| 008b59a4 | flt_8B59A4 | RW | Render_Bicubic_8B59A4 [DERIVED] |
| 008b59a8 | flt_8B59A8 | RW | Unknown_Float_DCT_Write2 [DERIVED] |
| 008b59ac | flt_8B59AC | RW | DCTOutputBuffer2 [DERIVED] |
| 008b59b0 | flt_8B59B0 | RW | DCT_OutputBuffer2 [DERIVED] |
| 008b59b4 | flt_8B59B4 | RW | DCT_OutputBuffer1 [DERIVED] |
| 008b59b8 | flt_8B59B8 | RW | DCT_Output_8B59B8 [DERIVED] |
| 008b59bc | flt_8B59BC | RW | DCTOutputScaler [DERIVED] |
| 008b59c0 | flt_8B59C0 | RW | IDCTWorkspace [DERIVED] |
| 008b59c4 | flt_8B59C4 | RW | Unknown_Float_DCT_Write3 [DERIVED] |
| 008b59c8 | flt_8B59C8 | RW | Render_Bicubic_8B59C8 [DERIVED] |
| 008b59cc | flt_8B59CC | RW | DCTOutputCoeff3 [DERIVED] |
| 008b59d0 | flt_8B59D0 | RW | DCT_Output_02 [DERIVED] |
| 008b59d4 | flt_8B59D4 | RW | DCTTransformCoeff2 [DERIVED] |
| 008b59d8 | flt_8B59D8 | RW | Flt_DCT_Coeff3 [DERIVED] |
| 008b59dc | flt_8B59DC | RW | DCTDiffCoeff3 [DERIVED] |
| 008b59e0 | flt_8B59E0 | RW | DCTScaleFactor2 [DERIVED] |
| 008b59e4 | flt_8B59E4 | RW | AudioMixOutput_59E4 [DERIVED] |
| 008b59e8 | flt_8B59E8 | RW | Unknown_Float_DCT_Write4 [DERIVED] |
| 008b59ec | flt_8B59EC | RW | DCTOutputBuffer3 [DERIVED] |
| 008b59f0 | flt_8B59F0 | RW | Flt_DCT_Coeff4 [DERIVED] |
| 008b59f4 | flt_8B59F4 | RW | WaveletOutFloat [DERIVED] |
| 008b59f8 | flt_8B59F8 | RW | DCT_OutputBuffer2 [DERIVED] |
| 008b59fc | flt_8B59FC | RW | DCTDiffCoeff5 [DERIVED] |
| 008b5a00 | flt_8B5A00 | RW | AudioMixOutput_5A00 [DERIVED] |
| 008b5a04 | flt_8B5A04 | RW | DCT_Output_8B5A04 [DERIVED] |
| 008b5a08 | flt_8B5A08 | RW | DCT_Output_03 [DERIVED] |
| 008b5a0c | flt_8B5A0C | RW | FilterResult_8B5A0C [DERIVED] |
| 008b5a10 | flt_8B5A10 | RW | DCTTransformCoeff3 [DERIVED] |
| 008b5a14 | flt_8B5A14 | RW | DCT_OutputBuffer3 [DERIVED] |
| 008b5a18 | flt_8B5A18 | RW | DCTWorkspace [DERIVED] |
| 008b5a1c | flt_8B5A1C | RW | DCTDiffCoeff4 [DERIVED] |
| 008b5a20 | flt_8B5A20 | RW | DCTOutputBuffer4 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
