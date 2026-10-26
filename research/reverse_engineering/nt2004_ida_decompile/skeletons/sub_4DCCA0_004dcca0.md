## sub_4DCCA0_004dcca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D0D50 (004d0d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x38 | RW | 3 | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075cbac | dword_75CBAC | R | [LLM] |
| 007d758c | byte_7D758C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f81a0 | sub_4F81A0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
