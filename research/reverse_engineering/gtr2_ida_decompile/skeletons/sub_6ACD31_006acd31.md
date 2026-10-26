## sub_6ACD31_006acd31 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x220 | RW | 0 | [LLM] |
| this | 0x22C | RW | 0 | [LLM] |
| this | 0x230 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x220: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x22C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00744468 | aShaderCannotCo | R | [LLM] |
| 007444e8 | aCannotMapThisD | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d3 | j__free | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006a9cd5 | sub_6A9CD5 | [LLM] |
| 006aa1a9 | sub_6AA1A9 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 4 | [LLM] |
| this | 0x4C | == | 0 | [LLM] |
| this | 0xC8 | > | 257 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `shader cannot compile to a ps_1_%i shader because this model can't match all the dependent texture read(s) this shader requires`
- `cannot map this dependent texture read to ps_1_%i`
