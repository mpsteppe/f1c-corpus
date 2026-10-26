## sub_4CEE20_004cee20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x9C | R | — | [LLM] |
| obj | 0xBC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10C | RW | — | [LLM] |
| this | 0x120 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cde30 | sub_4CDE30 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
