## sub_6B9A1A_006b9a1a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AC9B (0067ac9b), sub_6BAE2D (006bae2d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | 12 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006b9d45 | jpt_6B9A57 | R | [LLM] |
| 0072ee24 | aNeedDictionary | R | [LLM] |
| 0072ee34 | aIncorrectDataC | R | [LLM] |
| 0072ee4c | aIncorrectHeade | R | [LLM] |
| 0072ee64 | aInvalidWindowS | R | [LLM] |
| 0072ee78 | aUnknownCompres | R | [LLM] |
| 016c9784 | off_16C9784 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006daca9 | sub_6DACA9 | [LLM] |
| 006dad8d | sub_6DAD8D | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `need dictionary`
- `incorrect data check`
- `incorrect header check`
- `invalid window size`
- `unknown compression method`
