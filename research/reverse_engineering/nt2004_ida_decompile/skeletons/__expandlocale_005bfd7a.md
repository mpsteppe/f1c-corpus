## __expandlocale_005bfd7a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _setlocale (005bf960), __setlocale_set_cat (005bfba6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x1 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006250a4 | aC_2 | R | [LLM] |
| 00625128 | aC_1 | R | [LLM] |
| 007ff0f4 | unk_7FF0F4 | R | [LLM] |
| 007ff0f8 | word_7FF0F8 | R | [LLM] |
| 007ff0fc | dword_7FF0FC | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bfeba | ___lc_strtolc | [LLM] |
| 005bff86 | ___lc_lctostr | [LLM] |
| 005c4620 | _memcpy_0 | [LLM] |
| 005c6e40 | _strcmp | [LLM] |
| 005c6f50 | _strcpy | [LLM] |
| 005c7040 | ___get_qualified_locale | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 67 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
