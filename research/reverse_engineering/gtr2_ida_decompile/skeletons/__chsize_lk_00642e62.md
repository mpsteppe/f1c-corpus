## __chsize_lk_00642e62 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __tsopen_lk (0064185d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f110c | SetEndOfFile | R | [LLM] |
| 006f1168 | GetLastError | R | [LLM] |
| 00912b08 | dword_912B08 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631bd0 | sub_631BD0 | [LLM] |
| 006349bb | sub_6349BB | [LLM] |
| 00635180 | _memset | [LLM] |
| 006351e0 | __errno | [LLM] |
| 006351e9 | ___doserrno | [LLM] |
| 00637d2a | __lseek_lk | [LLM] |
| 00638633 | __write_lk | [LLM] |
| 0064144e | FAILWRONGDESCRIPTION_42e0 [structural] | [LLM] |
| 0064360f | __setmode_lk | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
