## InputBindingConfigSetup_0051cb6d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 25 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x4A | R | — | [LLM] |
| this | 0x64 | RW | 1 | [LLM] |
| this | 0x68 | RW | 1 | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0x1A0 | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x1A0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051c653 | F_2DBlitTextureCopy | R | [LLM] |
| 0051c6be | F_2DCopyDelegation | R | [LLM] |
| 0051c6e1 | sub_51C6E1 | R | [LLM] |
| 0051c94f | sub_51C94F | R | [LLM] |
| 0051dfca | nullsub_4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051c5a3 | TableInitWithArithmeticProgression | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | == | 1 | [LLM] |
| this | 0x20 | == | 3 | [LLM] |
| this | 0x20 | == | 4 | [LLM] |
| this | 0x20 | > | 1 | [LLM] |
| this | 0x20 | >= | 1 | [LLM] |
| this | 0x28 | != | 4 | [LLM] |
| this | 0x28 | != | 1 | [LLM] |
| this | 0x28 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
