## sub_48BCF0_0048bcf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | RW | 0 | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x130: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b64150 | byte_B64150 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434bb0 | sub_434BB0 | [LLM] |
| 00435990 | sub_435990 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
