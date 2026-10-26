## ActorMotionPostProcessingUpdate_004ed030 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD0C | R | — | [LLM] |
| this | 0xD4C | R | — | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x3A6C | RW | — | [LLM] |
| this | 0x3A70 | RW | — | [LLM] |
| this | 0x3A78 | R | — | [LLM] |
| this | 0x3A7C | R | — | [LLM] |
| this | 0x3A80 | R | — | [LLM] |
| this | 0x3D60 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x3A6C: [LLM: once/conditional? does external poke survive?]
- this 0x3A70: [LLM: once/conditional? does external poke survive?]
- this 0x3D60: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a56b0 | StateTransition | [LLM] |
| 004e0d00 | LazyInitCallback | [LLM] |
| 004e8010 | TireBrushModelForceSolver | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D60 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
