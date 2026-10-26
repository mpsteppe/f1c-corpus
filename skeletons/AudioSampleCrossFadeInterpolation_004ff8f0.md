## AudioSampleCrossFadeInterpolation_004ff8f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioSamplePlaybackWithPitchModulationAndStereoP (00500210), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 005ad35c | flt_5AD35C | R | BlendThresholdFloat [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2580 | ShortVectorToFloatWithScale | [LLM] |
| 004b2930 | FloatToBitfieldPack | [LLM] |
| 004b2980 | BitfieldExtractScale | [LLM] |
| 004b29b0 | BitfieldInsert | [LLM] |
| 004b29f0 | ShortComputation_29f0 | [LLM] |
| 004b2a30 | BitfieldExtract | [LLM] |
| 004b2a40 | FloatToBitfieldEncoder | [LLM] |
| 004b2a80 | BitfieldToFloatConversion | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004ff3a0 | F_3DHermiteSplineInterpolation | [LLM] |
| 005001d0 | FieldCompareConstant | [LLM] |
| 00567010 | sub_567010 | [LLM] |
| 00567030 | QuaternionFromEulerAngles | [LLM] |
| 00567580 | sub_567580 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
