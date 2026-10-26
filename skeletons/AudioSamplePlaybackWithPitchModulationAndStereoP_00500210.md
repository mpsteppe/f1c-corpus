## AudioSamplePlaybackWithPitchModulationAndStereoP_00500210 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LinkedListIteratorWithStateUpdate (004b5760), sub_4B6360 (004b6360), sub_4B9AC0 (004b9ac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x12 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x16 | R | — | [LLM] |
| this | 0x1A | R | — | [LLM] |
| this | 0x1B | R | — | [LLM] |
| this | 0x1D | R | — | [LLM] |
| this | 0x1F | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C2 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1C6 | R | — | [LLM] |
| this | 0x1CA | R | — | [LLM] |
| this | 0x1CB | R | — | [LLM] |
| this | 0x1CD | R | — | [LLM] |
| this | 0x1CF | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 0059e718 | flt_59E718 | R | AudioVolumeMul [DERIVED] |
| 0059e71c | flt_59E71C | R | Unknown_RendererFloat [DERIVED] |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b21f0 | FloatToRGBColorConversion | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004ff8f0 | AudioSampleCrossFadeInterpolation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
