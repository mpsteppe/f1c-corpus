## __tsopen_lk_0064185d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __open (00641b44), __sopen (00641b99)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1110 | CreateFileA | R | [LLM] |
| 006f1168 | GetLastError | R | [LLM] |
| 006f118c | CloseHandle | R | [LLM] |
| 006f12bc | GetFileType | R | [LLM] |
| 00fb8190 | dword_FB8190 | R | [LLM] |
| 00fb8194 | dword_FB8194 | R | [LLM] |
| 00fb8658 | dword_FB8658 | R | [LLM] |
| ff0000000000a660 | byte_FF0000000000A660 | W | [LLM] |
| ff0000000000a661 | byte_FF0000000000A661 | W | [LLM] |
| ff0000000000a662 | byte_FF0000000000A662 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006351e0 | __errno | [LLM] |
| 006351e9 | ___doserrno | [LLM] |
| 006351f2 | CollisionParameterClampAndStore [structural] | [LLM] |
| 00636d78 | HandleCloseWithErrorReporting [structural] | [LLM] |
| 00637aa4 | __read_lk | [LLM] |
| 00637d2a | __lseek_lk | [LLM] |
| 00641353 | __set_osfhnd | [LLM] |
| 00641551 | __alloc_osfhnd | [LLM] |
| 00642e62 | __chsize_lk | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
