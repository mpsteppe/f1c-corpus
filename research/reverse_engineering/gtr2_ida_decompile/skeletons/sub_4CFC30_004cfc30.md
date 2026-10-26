## sub_4CFC30_004cfc30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B7CA0 (004b7ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x54)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x54) | 0x0 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x64 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e2630 | sub_4E2630 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
