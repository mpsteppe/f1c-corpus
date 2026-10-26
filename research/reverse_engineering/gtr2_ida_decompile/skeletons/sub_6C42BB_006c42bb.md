## sub_6C42BB_006c42bb — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6C47A3 (006c47a3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0x14) | 0xC | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0x188 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x188: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006339c0 | _strchr | [LLM] |
| 0066238f | sub_66238F | [LLM] |
| 00680cec | ZeroInit16ElementArray [structural] | [LLM] |
| 00680d22 | sub_680D22 | [LLM] |
| 00681186 | sub_681186 | [LLM] |
| 006811d1 | sub_6811D1 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x188 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
