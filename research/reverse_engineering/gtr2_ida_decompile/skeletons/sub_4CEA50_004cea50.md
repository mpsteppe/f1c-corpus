## sub_4CEA50_004cea50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| obj | 0x90 | R | — | [LLM] |
| obj | 0xA8 | R | — | [LLM] |
| obj | 0xAC | R | — | [LLM] |
| obj | 0xB4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x344 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x344: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd570 | sub_4CD570 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
