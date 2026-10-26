## sub_6C8AE5_006c8ae5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c), sub_6C8C6D (006c8c6d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x108) | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |
| this | 0x15C | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x15C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16a0 | dbl_6F16A0 | R | [LLM] |
| 007479b8 | aComplementOppo | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686816 | sub_686816 | [LLM] |
| 006c73e9 | sub_6C73E9 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15C | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `complement opportunity missed because input result WAS clamped from 0 to 1`
