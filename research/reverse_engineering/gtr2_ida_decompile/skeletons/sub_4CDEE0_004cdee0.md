## sub_4CDEE0_004cdee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xFC)+0x18) | 0x18 | R | — | [LLM] |
| obj | 0x94 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x11A | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x11A: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e3b60 | sub_4E3B60 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
