## TireGripLateralForceCalculation_004e9300 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | [LLM] |
| this | 0x3518 | R | — | [LLM] |
| this | 0x3800 | R | — | [LLM] |
| this | 0x3998 | R | — | [LLM] |
| this | 0x39A4 | R | — | EngineMaxRPM [CONFIRMED] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x39D0 | R | — | [LLM] |
| this | 0x39F8 | R | — | [LLM] |
| this | 0x3A70 | R | — | [LLM] |
| this | 0x3C3C | R | — | [LLM] |
| this | 0x3C40 | R | — | [LLM] |
| this | 0x3C7C | R | — | [LLM] |
| this | 0x3C80 | R | — | [LLM] |
| this | 0x3CBC | R | — | [LLM] |
| this | 0x3CC0 | R | — | [LLM] |
| this | 0x3D44 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39B4 | != | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
