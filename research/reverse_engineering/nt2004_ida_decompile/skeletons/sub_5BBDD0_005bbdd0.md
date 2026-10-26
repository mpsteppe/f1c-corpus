## sub_5BBDD0_005bbdd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5BBD90 (005bbd90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x28) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x4 | R | — | [LLM] |
| *(this+0x28) | 0x8 | R | — | [LLM] |
| *(this+0x28) | 0xC | R | — | [LLM] |
| *(this+0x28) | 0x15 | R | — | [LLM] |
| *(this+0x28) | 0x20 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| ff00000000005e86 | byte_FF00000000005E86 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bbe90 | sub_5BBE90 | [LLM] |
| 005bbfb0 | sub_5BBFB0 | [LLM] |
| 005bdc00 | sub_5BDC00 | [LLM] |
| 005d2704 | recvfrom [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
