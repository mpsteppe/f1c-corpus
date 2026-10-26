## sub_4EC3A0_004ec3a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4ED620 (004ed620)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xC)+0x8)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0xC)+0x8) | 0x4 | R | — | [LLM] |
| *(*(this+0xC)+0x8) | 0x8 | R | — | [LLM] |
| *(obj+0x0) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x8 | R | — | [LLM] |
| *(this+0xC) | 0x14 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
