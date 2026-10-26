## sub_4B5AA0_004b5aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x348 | RW | — | [LLM] |
| this | 0x350 | R | — | [LLM] |
| this | 0x354 | R | — | [LLM] |
| this | 0x358 | R | — | [LLM] |
| this | 0x35C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x348: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b71da4 | dword_B71DA4 | W | [LLM] |
| 00b71dac | dword_B71DAC | R | [LLM] |
| 00b71db0 | dword_B71DB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
