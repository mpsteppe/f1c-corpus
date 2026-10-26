## SuspensionForceComputationWithPerCornerVirtualDi_004f8440 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTickUpdate (004c8b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48BC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0x63C | RW | 0 | [LLM] |
| this | 0x6D8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x63C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005d6798 | dword_5D6798 | R | BrakeForceConst_5D6798 [DERIVED] |
| 005d679c | dword_5D679C | R | PedalForceCoeff [DERIVED] |
| 005d67a0 | dword_5D67A0 | R | SteeringForceCoeff [DERIVED] |
| 005d67a4 | dword_5D67A4 | R | AeroDownforceConstant [DERIVED] |
| 005d67a8 | dword_5D67A8 | R | Flt_AiBrakeBiasGain_67A8 [DERIVED] |
| 005d67ac | dword_5D67AC | R | FFBParam_5D67AC [DERIVED] |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |
| 007cf2f0 | flt_7CF2F0 | R | BrakeForceMult [DERIVED] |
| 007cf314 | flt_7CF314 | R | SuspensionDampingMultiplier [DERIVED] |
| 007cf338 | flt_7CF338 | R | Flt_ForceFeedbackMult [DERIVED] |
| 007cf35c | flt_7CF35C | R | ForceFeedbackGain [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c7bd0 | sub_4C7BD0 | [LLM] |
| 004f6d90 | ParametricInterpolationBlending | [LLM] |
| 004f8850 | PerIndexStructFieldSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
