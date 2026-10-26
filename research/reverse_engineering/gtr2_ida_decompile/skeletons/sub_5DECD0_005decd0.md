## sub_5DECD0_005decd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5DF750 (005df750)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | [LLM] |
| this | 0x80C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x80C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f30b4 | asc_6F30B4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630a80 | _strstr | [LLM] |
| 00631d10 | _strncmp | [LLM] |
| 00633cd6 | sub_633CD6 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | != | 61 | [LLM] |
| this | 0xC | != | 32 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
