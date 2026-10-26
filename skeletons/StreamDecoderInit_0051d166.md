## StreamDecoderInit_0051d166 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x4 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x19C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x19C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051cd3e | PhysicsObjectStateSetter | R | [LLM] |
| 0051cd53 | AudioSampleStream | R | [LLM] |
| 0051cdf9 | VirtualDispatchWrapper_cdf9 | R | [LLM] |
| 0051ce2a | TexturePaletteColorLookup | R | [LLM] |
| 0051cf80 | sub_51CF80 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x110 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
