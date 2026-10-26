## sub_4B5DE0_004b5de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x98 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x34C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x34C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b64150 | byte_B64150 | R | [LLM] |
| 00b64154 | dword_B64154 | W | [LLM] |
| 00b71d80 | dword_B71D80 | W | [LLM] |
| 00b71d88 | dword_B71D88 | R | [LLM] |
| 00b71d8c | dword_B71D8C | R | [LLM] |
| 00b72454 | dword_B72454 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432c90 | sub_432C90 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
