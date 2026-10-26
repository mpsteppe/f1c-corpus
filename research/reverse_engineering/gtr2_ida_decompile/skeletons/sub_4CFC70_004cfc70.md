## sub_4CFC70_004cfc70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B7CA0 (004b7ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x4 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004df110 | sub_4DF110 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
