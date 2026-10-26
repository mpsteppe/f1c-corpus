## sub_4AD7B0_004ad7b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x98 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x254 | RW | — | [LLM] |
| this | 0x258 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x254: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x258: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f3154 | flt_6F3154 | R | [LLM] |
| 00b7628c | dword_B7628C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004de460 | sub_4DE460 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
