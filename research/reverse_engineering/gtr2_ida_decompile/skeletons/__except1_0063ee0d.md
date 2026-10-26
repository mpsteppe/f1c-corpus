## __except1_0063ee0d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __floor_default (0063c53c), __ceil_default (00640580), _frexp (006e0127)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912b08 | dword_912B08 | R | [LLM] |
| 009137d8 | dword_9137D8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006349bb | sub_6349BB | [LLM] |
| 0063e79f | __raise_exc | [LLM] |
| 0063ea44 | __handle_exc | [LLM] |
| 0063ec68 | sub_63EC68 | [LLM] |
| 0063ec90 | __errcode | [LLM] |
| 0063ecbd | __umatherr | [LLM] |
| 0063efa5 | __ctrlfp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
