## sub_4CFC00_004cfc00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D08E0 (004d08e0), sub_4EE360 (004ee360), sub_52DF70 (0052df70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5af0 | flt_5D5AF0 | R | [LLM] |
| 005d6028 | flt_5D6028 | R | [LLM] |
| 005ea5bc | flt_5EA5BC | R | [LLM] |
| 005ea5c0 | flt_5EA5C0 | R | [LLM] |
| 005ea5c4 | flt_5EA5C4 | R | [LLM] |
| 005ea5c8 | flt_5EA5C8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
