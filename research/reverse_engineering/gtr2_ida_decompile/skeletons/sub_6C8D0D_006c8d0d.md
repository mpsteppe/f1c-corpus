## sub_6C8D0D_006c8d0d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x100 | RW | 0 | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x15C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x15C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f2dac | flt_6F2DAC | R | [LLM] |
| 006f32d8 | flt_6F32D8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006c5028 | sub_6C5028 | [LLM] |
| 006c73e9 | sub_6C73E9 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
