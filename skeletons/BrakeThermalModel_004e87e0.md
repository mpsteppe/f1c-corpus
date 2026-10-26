## BrakeThermalModel_004e87e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIRacingLine (00425920), AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x3500 | R | — | [LLM] |
| this | 0x39A8 | R | — | [LLM] |
| this | 0x39AC | R | — | [LLM] |
| this | 0x39C8 | R | — | [LLM] |
| this | 0x3A58 | R | — | [LLM] |
| this | 0x3A5C | R | — | [LLM] |
| this | 0x3A60 | R | — | [LLM] |
| this | 0x3D40 | R | — | [LLM] |
| this | 0x3D44 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
