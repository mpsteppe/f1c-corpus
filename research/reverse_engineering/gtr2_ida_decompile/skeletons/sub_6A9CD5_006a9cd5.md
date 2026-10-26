## sub_6A9CD5_006a9cd5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6ACD31 (006acd31)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |
| this | 0x22C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00743f00 | aCannotMatchToT_0 | R | [LLM] |
| 00743f58 | aExpressionCanO | R | [LLM] |
| 00743fb0 | aCannotMatchToT | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | [LLM] |
| 00680cec | ZeroInit16ElementArray [structural] | [LLM] |
| 00681186 | sub_681186 | [LLM] |
| 006811d1 | sub_6811D1 | [LLM] |
| 006815d6 | sub_6815D6 | [LLM] |
| 00681997 | sub_681997 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006a9a7c | sub_6A9A7C | [LLM] |
| 006a9b74 | sub_6A9B74 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC8 | < | 258 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `cannot match to texreg2ar or texreg2gb instruction because cannot have input modifiers`
- `expression can only be map to texreg2rgb, but this instruction is not supported on 1_%i`
- `cannot match to texreg2rgb instruction because can only have input modifier _bx2`
