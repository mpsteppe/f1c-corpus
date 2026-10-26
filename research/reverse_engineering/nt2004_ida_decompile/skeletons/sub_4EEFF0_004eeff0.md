## sub_4EEFF0_004eeff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4F0020 (004f0020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x8)+0x8) | 0x0 | R | — | [LLM] |
| *(*(this+0x8)+0x8) | 0x4 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0x8 | RW | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5c40 | flt_5D5C40 | R | [LLM] |
| 007d6bb0 | dword_7D6BB0 | R | [LLM] |
| 007da9c8 | dbl_7DA9C8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ef140 | sub_4EF140 | [LLM] |
| 004f0500 | sub_4F0500 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x8) | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
