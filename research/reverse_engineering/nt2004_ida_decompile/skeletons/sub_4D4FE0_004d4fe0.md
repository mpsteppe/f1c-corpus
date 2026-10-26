## sub_4D4FE0_004d4fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D8DD0 (004d8dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x1B0 | RW | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x20) 0x1B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006291d0 | dword_6291D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418020 | sub_418020 | [LLM] |
| 0052e830 | sub_52E830 | [LLM] |
| 0052e850 | FloatComparisonCheck [exact] | [LLM] |
| 0052e870 | sub_52E870 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
