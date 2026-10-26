## __unlock_fhandle_005ccfe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __close (005c3435), __lseek (005c4144), __read (005c43d4), __write (005c54e6), __commit (005c9f67), __sopen (005cd019), __lseeki64 (005cd59e), __dup (005d27e6), __fstat (005d28f6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d51e4 | LeaveCriticalSection | R | [LLM] |
| 008003e0 | dword_8003E0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
