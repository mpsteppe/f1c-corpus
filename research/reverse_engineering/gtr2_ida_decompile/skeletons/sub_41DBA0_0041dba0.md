## sub_41DBA0_0041dba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_41DC90 (0041dc90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x24)+0x0) | 0x48 | R | — | [LLM] |
| *(this+0x24) | 0x0 | R | — | [LLM] |
| *(this+0x2C) | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
