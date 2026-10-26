## UIListComboBoxConstructor_0051a4f2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x14 | R | — | [LLM] |
| *(this+0xC4) | 0xC | R | — | [LLM] |
| *(this+0xC4) | 0x1C | R | — | [LLM] |
| *(this+0xC4) | 0x20 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x184 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x184: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005199c5 | InitAndChain | R | [LLM] |
| 005199d5 | CompositingPass | R | [LLM] |
| 00519baf | sub_519BAF | R | [LLM] |
| 00519bb2 | CompositingCopy | R | [LLM] |
| 00519d51 | DrawableObjectBatchProcessor | R | [LLM] |
| 0051a4b7 | ProtocolStateHandler | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515927 | AlignUp | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
