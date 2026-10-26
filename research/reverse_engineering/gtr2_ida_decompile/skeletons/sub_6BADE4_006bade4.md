## sub_6BADE4_006bade4 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AB08 (0067ab08)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | [LLM] |
| this | 0x10C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0074572c | aUnknownCritica | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f41 | sub_679F41 | [LLM] |
| 006b9e38 | sub_6B9E38 | [LLM] |
| 006ba69b | sub_6BA69B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `unknown critical chunk`
