## sub_5B1CB0_005b1cb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5B1DC0 (005b1dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x40C | RW | — | [LLM] |
| this | 0x80C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x40C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x80C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fd028 | Delimiter | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bf16b | _strtok | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
