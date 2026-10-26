## sub_6DA8F7_006da8f7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B8942 (006b8942)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x16B0 | RW | 0 | [LLM] |
| this | 0x16B1 | R | — | [LLM] |
| this | 0x16B4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x16B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x16B4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006da419 | sub_6DA419 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
