## _setlocale_005bf960 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_41F0C0 (0041f0c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d513c | Sleep | R | [LLM] |
| 005f65b8 | Control | R | [LLM] |
| 005f65bc | asc_5F65BC | R | [LLM] |
| 006251b4 | dword_6251B4 | RW | [LLM] |
| 006251bc | off_6251BC | R | [LLM] |
| 006251ec | off_6251EC | R | [LLM] |
| 006251f0 | off_6251F0 | R | [LLM] |
| 00801518 | dword_801518 | W | [LLM] |
| 0080151c | dword_80151C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005beab0 | _strncpy | [LLM] |
| 005bee90 | _strncmp | [LLM] |
| 005bfba6 | __setlocale_set_cat | [LLM] |
| 005bfcc1 | __setlocale_get_all | [LLM] |
| 005bfd7a | __expandlocale | [LLM] |
| 005c1b88 | sub_5C1B88 | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | [LLM] |
| 005c5315 | __unlock | [LLM] |
| 005c6e40 | _strcmp | [LLM] |
| 005c6ed0 | _strcspn | [LLM] |
| 005c6f10 | InPlaceStringShift [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `xe_`
