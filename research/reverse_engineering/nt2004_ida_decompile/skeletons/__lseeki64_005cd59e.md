## __lseeki64_005cd59e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __ftelli64_lk (005c4244), __fseeki64_lk (005d32f6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008003e0 | dword_8003E0 | R | [LLM] |
| 008004e0 | uNumber | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1a3c | __errno | [LLM] |
| 005c1a45 | ___doserrno | [LLM] |
| 005ccf81 | __lock_fhandle | [LLM] |
| 005ccfe0 | __unlock_fhandle | [LLM] |
| 005cd60f | FilePointerSeekWithErrorHandling [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
