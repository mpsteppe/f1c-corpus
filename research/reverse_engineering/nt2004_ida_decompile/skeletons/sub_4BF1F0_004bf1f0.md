## sub_4BF1F0_004bf1f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42FFB0 (0042ffb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC0 | RW | 0 | [LLM] |
| this | 0xC4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00628f84 | dword_628F84 | R | [LLM] |
| 0075cbb0 | dword_75CBB0 | R | [LLM] |
| 00766304 | dword_766304 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bfd80 | sub_4BFD80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
