## __read_lk_00637aa4 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __read (00637c7f), __tsopen_lk (0064185d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1168 | GetLastError | R | [LLM] |
| 006f1268 | ReadFile | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006351e0 | __errno | [LLM] |
| 006351e9 | ___doserrno | [LLM] |
| 006351f2 | CollisionParameterClampAndStore [structural] | [LLM] |
| 00637d2a | __lseek_lk | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
