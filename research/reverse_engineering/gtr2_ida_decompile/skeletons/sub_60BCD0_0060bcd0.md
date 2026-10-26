## sub_60BCD0_0060bcd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C8 | R | — | [LLM] |
| this | 0x2D0 | RW | — | [LLM] |
| this | 0x2D4 | R | — | [LLM] |
| this | 0x2DC | R | — | [LLM] |
| this | 0x2E4 | RW | — | [LLM] |
| this | 0x2E8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x2D0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2E4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059f730 | LinkedListNodeRemovalByValue [structural] | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
