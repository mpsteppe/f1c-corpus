## sub_4FFF30_004fff30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4FFF90 (004fff90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x310 | RW | — | [LLM] |
| this | 0x314 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x310: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x314: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f30d8 | flt_6F30D8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fd860 | sub_4FD860 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
