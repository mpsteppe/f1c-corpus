## TireForceSolver_004e8ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SweptSuspensionCollisionDetection (00401910), PhysicsNodePropagationWithDistanceFalloff (00401c90), sub_426430 (00426430), AIComputePassScore (0042a780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | [LLM] |
| this | 0x3A70 | R | — | [LLM] |
| this | 0x3C3C | R | — | [LLM] |
| this | 0x3C40 | R | — | [LLM] |
| this | 0x3C7C | R | — | [LLM] |
| this | 0x3C80 | R | — | [LLM] |
| this | 0x3CFC | R | — | [LLM] |
| this | 0x3D00 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e6fc | flt_59E6FC | R | RGBChannelMultiplier [DERIVED] (also: ` — RGB channel multiplier (~255.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
