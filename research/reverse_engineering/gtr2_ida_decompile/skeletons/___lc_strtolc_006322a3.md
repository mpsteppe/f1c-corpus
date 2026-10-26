## ___lc_strtolc_006322a3 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __expandlocale (006324c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8F | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x8F: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00730468 | Control | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | [LLM] |
| 00635180 | _memset | [LLM] |
| 0063a5a0 | _strcspn | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `_.,`
