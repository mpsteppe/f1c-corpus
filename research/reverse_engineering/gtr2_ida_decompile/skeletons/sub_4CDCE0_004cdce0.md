## sub_4CDCE0_004cdce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x108 | RW | 2 | [LLM] |

**Written-by note (persistence):**
- this 0x108: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e29b0 | sub_4E29B0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
