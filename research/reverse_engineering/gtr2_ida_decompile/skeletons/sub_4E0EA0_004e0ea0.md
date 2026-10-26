## sub_4E0EA0_004e0ea0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4E0FF0 (004e0ff0), sub_4E1520 (004e1520)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x0) | 0x5C | R | — | [LLM] |
| *(this+0x40) | 0x0 | R | — | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd340 | sub_4CD340 | [LLM] |
| 004e0d20 | sub_4E0D20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
