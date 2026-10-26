## sub_4AEAB0_004aeab0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x254 | RW | — | [LLM] |
| this | 0x258 | R | — | [LLM] |
| this | 0x260 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x254: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075b17c | dword_75B17C | R | [LLM] |
| 00b722e4 | byte_B722E4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049a2a0 | sub_49A2A0 | [LLM] |
| 0049a6b0 | sub_49A6B0 | [LLM] |
| 004ae810 | sub_4AE810 | [LLM] |
| 004d41c0 | sub_4D41C0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x258 | >= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
