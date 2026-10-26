## __lseek_lk_00637d2a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __read_lk (00637aa4), __lseek (00637d9e), __tsopen_lk (0064185d), __chsize_lk (00642e62)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1168 | GetLastError | R | [LLM] |
| 006f126c | SetFilePointer | R | [LLM] |
| 00fbb4e0 | dword_FBB4E0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006351e0 | __errno | [LLM] |
| 006351f2 | CollisionParameterClampAndStore [structural] | [LLM] |
| 0064144e | FAILWRONGDESCRIPTION_42e0 [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
