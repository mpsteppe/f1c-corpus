## PitCrewStateMachine_004bbfc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400), EngineFailureCheck (004bec55)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1054 | R | — | [LLM] |
| obj | 0x105D | RW | 1 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x34 | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x105D: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00680000 | unk_680000 | R | VEH[32].0x2128 [LLM: field purpose] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042af40 | AIStateReset | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x105D | != | 1 | [LLM] |
| this | 0x30 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
