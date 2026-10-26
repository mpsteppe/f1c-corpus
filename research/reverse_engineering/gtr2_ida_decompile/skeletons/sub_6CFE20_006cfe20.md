## sub_6CFE20_006cfe20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B4A10 (006b4a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x1C0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006cf8f0 | sub_6CF8F0 | R | [LLM] |
| 006cfcc0 | sub_6CFCC0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
