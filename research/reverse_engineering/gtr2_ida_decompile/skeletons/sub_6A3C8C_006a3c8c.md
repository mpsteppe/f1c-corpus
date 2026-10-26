## sub_6A3C8C_006a3c8c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x100 | RW | 0 | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00681c03 | sub_681C03 | [LLM] |
| 006a326c | sub_6A326C | [LLM] |
| 006a32c7 | sub_6A32C7 | [LLM] |
| 006c5456 | sub_6C5456 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
