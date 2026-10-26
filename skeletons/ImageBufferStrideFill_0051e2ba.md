## ImageBufferStrideFill_0051e2ba — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectSetupWithBoundsCheck (0051eb6e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 94 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| obj | 0x1C | RW | — | [LLM] |
| obj | 0x20 | RW | — | [LLM] |
| obj | 0x24 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1B4 | RW | — | [LLM] |
| this | 0x1B8 | RW | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |
| this | 0x1CC | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- obj 0x1C: [LLM: once/conditional? does external poke survive?]
- obj 0x20: [LLM: once/conditional? does external poke survive?]
- obj 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1B8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051e1ef | CombinatorialPermutationGenerator | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x64 | == | 3 | [LLM] |
| this | 0x64 | > | 0 | [LLM] |
| this | 0x1C4 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
