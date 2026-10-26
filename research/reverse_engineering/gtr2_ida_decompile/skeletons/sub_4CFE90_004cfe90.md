## sub_4CFE90_004cfe90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x10C | RW | 2 | [LLM] |
| this | 0x134 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006f2de4 | Mode | R | [LLM] |
| 006fd194 | aC_8 | R | [LLM] |
| 00711784 | asc_711784 | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | [LLM] |
| 004cd670 | sub_4CD670 | [LLM] |
| 004df1b0 | sub_4DF1B0 | [LLM] |
| 004e08c0 | sub_4E08C0 | [LLM] |
| 004e2b30 | PositionUpdate [exact] | [LLM] |
| 00631c0d | __stricmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
