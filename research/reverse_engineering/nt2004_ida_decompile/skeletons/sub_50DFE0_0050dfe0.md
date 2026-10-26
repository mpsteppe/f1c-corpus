## sub_50DFE0_0050dfe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D0D50 (004d0d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB58 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xB58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d5da4 | dword_7D5DA4 | R | [LLM] |
| 007d5dac | dword_7D5DAC | R | [LLM] |
| 007da9d0 | dbl_7DA9D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d9e20 | sub_4D9E20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
