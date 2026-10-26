## sub_4BBFC0_004bbfc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D0D50 (004d0d50), sub_4FBC40 (004fbc40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006290f4 | dword_6290F4 | R | [LLM] |
| 0075cbb4 | dword_75CBB4 | R | [LLM] |
| 007d7540 | dword_7D7540 | R | [LLM] |
| 007d7928 | dword_7D7928 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bbf10 | sub_4BBF10 | [LLM] |
| 004bbf80 | sub_4BBF80 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
