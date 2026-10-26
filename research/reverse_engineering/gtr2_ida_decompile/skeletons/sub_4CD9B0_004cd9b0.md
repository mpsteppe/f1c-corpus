## sub_4CD9B0_004cd9b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0x94 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |
| this | 0x111 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x110: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cda98 | jpt_4CDA03 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd5a0 | sub_4CD5A0 | [LLM] |
| 004cd720 | sub_4CD720 | [LLM] |
| 004de540 | sub_4DE540 | [LLM] |
| 004e29f0 | sub_4E29F0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
