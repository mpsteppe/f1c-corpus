## sub_6D0DF0_006d0df0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B4A10 (006b4a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xDC) | 0x50 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0x1C4 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xDC) 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006d0a90 | sub_6D0A90 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
