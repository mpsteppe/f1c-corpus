## sub_6AA1A9_006aa1a9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6ACD31 (006acd31)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |
| this | 0x224 | R | — | [LLM] |
| this | 0x22C | R | — | [LLM] |
| this | 0x230 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00744008 | aCannotBindSamp_2 | R | [LLM] |
| 0074404c | aInternalErrorU_6 | R | [LLM] |
| 00744078 | aCannotMatchToT_2 | R | [LLM] |
| 007440c8 | aCannotMatchToT_1 | R | [LLM] |
| 00744120 | aUnableToMatchT_0 | R | [LLM] |
| 007441b0 | aUnableToMatchT | R | [LLM] |
| 007441f8 | aCannotBindSamp_1 | R | [LLM] |

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

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `cannot bind sampler to sampler array, sampler must be bound to %i`
- `internal error: unexpected argument type`
- `cannot match to texm* because texm* can only have bx2 modifier on input texload`
- `cannot match to texm* because texm* cannot have source modifiers on input texcoord`
- `unable to match texm* because source inputs are not in appropriate texture coordinates. See ps_1_% assembly reference for more information`
- `unable to match texm because computed texcoord is used in shader`
- `cannot bind sampler to user specified stage, sampler must be bound to %i`
