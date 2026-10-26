## sub_6D7FE0_006d7fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B7160 (006b7160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 99 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x16C | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x16C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00606bd0 | pfnAPC | R | [LLM] |
| 006d7640 | sub_6D7640 | R | [LLM] |
| 006d76e0 | sub_6D76E0 | R | [LLM] |
| 006d7800 | sub_6D7800 | R | [LLM] |
| 006d7b30 | sub_6D7B30 | R | [LLM] |
| 006d7da0 | sub_6D7DA0 | R | [LLM] |
| 006d7f20 | sub_6D7F20 | R | [LLM] |
| 006d7f80 | sub_6D7F80 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
