## ObjectSetupWithBoundsCheck_0051eb6e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 56 | [LLM] |
| obj | 0x18 | RW | 256 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x1A4 | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1A4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051dfca | nullsub_4 | R | [LLM] |
| 0051ea90 | CodecModeSelect | R | [LLM] |
| 0051eb5a | VirtualCallWithIntegerSet | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051e2ba | ImageBufferStrideFill | [LLM] |
| 0051e3e7 | sub_51E3E7 | [LLM] |
| 0051ea5a | VirtualArrayFill | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 2 | [LLM] |
| this | 0x54 | > | 256 | [LLM] |
| this | 0x64 | > | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
