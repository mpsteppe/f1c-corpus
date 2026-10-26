## F_3DSoundPositioningUpdate_00405b90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MilesAudioSamplePlaybackSetup (00405900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x58 | R | — | [LLM] |
| *(this+0x54) | 0x5C | R | — | [LLM] |
| *(this+0x54) | 0x60 | R | — | [LLM] |
| *(this+0x54) | 0x8C | R | — | [LLM] |
| *(this+0x58) | 0x10 | R | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3b8 | _AIL_set_sample_volume_levels@12 | R | [LLM] |
| 0059e3bc | _AIL_set_sample_playback_rate@8 | R | [LLM] |
| 0059e3c0 | _AIL_set_sample_position@8 | R | [LLM] |
| 0059e3c4 | _AIL_start_sample@4 | R | [LLM] |
| 0059e3d4 | _AIL_resume_sample@4 | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405f80 | ScaledDotProductWithClamp | [LLM] |
| 00406020 | SmoothstepInterpolation | [LLM] |
| 00406060 | DotProductWithScaleOffset | [LLM] |
| 00406100 | ShortComputation_6100 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
