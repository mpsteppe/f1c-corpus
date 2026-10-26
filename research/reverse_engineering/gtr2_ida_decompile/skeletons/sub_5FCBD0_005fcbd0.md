## sub_5FCBD0_005fcbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FDB10 (005fdb10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005fcb20 | sub_5FCB20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
