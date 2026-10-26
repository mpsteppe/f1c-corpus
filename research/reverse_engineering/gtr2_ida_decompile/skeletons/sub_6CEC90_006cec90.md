## sub_6CEC90_006cec90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |
| this | 0x12A | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x13A | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x1B0 | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1CC | R | — | [LLM] |
| this | 0x1F8 | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006b6040 | sub_6B6040 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x194 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
