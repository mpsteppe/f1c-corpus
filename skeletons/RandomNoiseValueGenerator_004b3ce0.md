## RandomNoiseValueGenerator_004b3ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250), EngineWearFailureSimulation (004ee150), sub_4FD8B0 (004fd8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005accf8 | flt_5ACCF8 | R | FinalScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3c60 | DeterministicHashPseudoRandomGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
