## sub_64F9CC_0064f9cc — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_658A1D (00658a1d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF8) | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |
| this | 0xD4 | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00737514 | off_737514 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d3 | j__free | [LLM] |
| 0064eaff | sub_64EAFF | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xF4 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
