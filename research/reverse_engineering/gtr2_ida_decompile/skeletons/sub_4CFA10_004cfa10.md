## sub_4CFA10_004cfa10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D5F60 (004d5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | [LLM] |
| this | 0x80 | RW | 0 | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x80: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x88: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x108: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b708d0 | byte_B708D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cf880 | sub_4CF880 | [LLM] |
| 004de300 | sub_4DE300 | [LLM] |
| 004de460 | sub_4DE460 | [LLM] |
| 004e05f0 | RendererAlphaBlendSetter [structural] | [LLM] |
| 004e29f0 | sub_4E29F0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
