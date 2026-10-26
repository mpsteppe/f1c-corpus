## ShortComputation_1330_00411330 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ecf0c | dword_5ECF0C | R | VEH[0].0x834 [LLM: field purpose] |
| 005ed3ac | dword_5ED3AC | R | VEH[0].0xCD4 [LLM: field purpose] |
| 005ed3f0 | dword_5ED3F0 | R | VEH[0].0xD18 [LLM: field purpose] |
| 005ed434 | dword_5ED434 | R | VEH[0].0xD5C [LLM: field purpose] |
| 007d0ad4 | flt_7D0AD4 | R | GlobalFloatOffset [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e770 | ShortComputation_e770 | [LLM] |
| 0040eec0 | SwitchBasedFloatProcessing | [LLM] |
| 0040ef70 | PhysicsStateVectorConversion | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
