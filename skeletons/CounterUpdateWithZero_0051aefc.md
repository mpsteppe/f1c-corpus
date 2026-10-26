## CounterUpdateWithZero_0051aefc — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BitstreamDecoder (0051af57), sub_51B154 (0051b154), PlaneVisibilityTestWithBitfieldOutput (0051b37d), sub_51B45F (0051b45f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xFC | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x1A8 | RW | 0 | [LLM] |
| this | 0x1AC | RW | 0 | [LLM] |
| this | 0x1B4 | RW | 0 | [LLM] |
| this | 0x1B8 | RW | 0 | [LLM] |
| this | 0x1C8 | RW | — | [LLM] |
| this | 0x1E8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1AC: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1B8: [LLM: once/conditional? does external poke survive?]
- this 0x1C8: [LLM: once/conditional? does external poke survive?]
- this 0x1E8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
