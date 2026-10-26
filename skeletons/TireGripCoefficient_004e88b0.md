## TireGripCoefficient_004e88b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIRacingLine (00425920), AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x35CC | R | — | [LLM] |
| this | 0x3610 | R | — | [LLM] |
| this | 0x3618 | R | — | [LLM] |
| this | 0x36C4 | R | — | [LLM] |
| this | 0x3708 | R | — | [LLM] |
| this | 0x3710 | R | — | [LLM] |
| this | 0x37BC | R | — | [LLM] |
| this | 0x3800 | R | — | [LLM] |
| this | 0x3808 | R | — | [LLM] |
| this | 0x38B4 | R | — | [LLM] |
| this | 0x38F8 | R | — | [LLM] |
| this | 0x3900 | R | — | [LLM] |
| this | 0x39A8 | R | — | [LLM] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x39C8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
