## DistanceComparison_004effd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), LoopOverTwoParallelArrays (004d1030), VelocityThresholdCheck (004f1aa0), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1140 | RenderCallWithGuard | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
