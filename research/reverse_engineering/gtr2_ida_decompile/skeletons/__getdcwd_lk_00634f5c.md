## __getdcwd_lk_00634f5c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __getcwd (00635047)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1234 | GetCurrentDirectoryA | R | [LLM] |
| 006f1238 | GetFullPathNameA | R | [LLM] |
| 00912b08 | dword_912B08 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006349bb | sub_6349BB | [LLM] |
| 00634c1d | _malloc | [LLM] |
| 00634f25 | __validdrive | [LLM] |
| 006351e0 | __errno | [LLM] |
| 006351e9 | ___doserrno | [LLM] |
| 00636a70 | _strcpy | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
