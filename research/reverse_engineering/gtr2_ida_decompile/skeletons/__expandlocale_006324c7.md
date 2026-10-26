## __expandlocale_006324c7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __setlocale_lk (006328b2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x1 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 00912938 | aC_7 | R | [LLM] |
| 009129ba | byte_9129BA | W | [LLM] |
| 009129c0 | Str1 | R | [LLM] |
| 00912b08 | dword_912B08 | R | [LLM] |
| 00fb8184 | unk_FB8184 | R | [LLM] |
| 00fb8188 | word_FB8188 | R | [LLM] |
| 00fb818c | dword_FB818C | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | [LLM] |
| 006322a3 | ___lc_strtolc | [LLM] |
| 0063237f | ___lc_lctostr | [LLM] |
| 006349bb | sub_6349BB | [LLM] |
| 006354d0 | sub_6354D0 | [LLM] |
| 00635560 | _memcpy_0 | [LLM] |
| 00636a70 | _strcpy | [LLM] |
| 00636cf0 | _strcmp | [LLM] |
| 0063ad25 | ___get_qualified_locale | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 67 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
