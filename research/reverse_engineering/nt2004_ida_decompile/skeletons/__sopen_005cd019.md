## __sopen_005cd019 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __openfile (005c3540), __open (005cd002)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d50a8 | CreateFileA | R | [LLM] |
| 005d5154 | GetLastError | R | [LLM] |
| 005d5174 | CloseHandle | R | [LLM] |
| 005d51bc | GetFileType | R | [LLM] |
| 007ff118 | dword_7FF118 | R | [LLM] |
| 007ff4ac | dword_7FF4AC | R | [LLM] |
| ff00000000005e94 | byte_FF00000000005E94 | W | [LLM] |
| ff00000000005e95 | byte_FF00000000005E95 | W | [LLM] |
| ff00000000005e96 | byte_FF00000000005E96 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c19c9 | ErrorIDLookupTable [structural] | [LLM] |
| 005c1a3c | __errno | [LLM] |
| 005c1a45 | ___doserrno | [LLM] |
| 005c3435 | __close | [LLM] |
| 005c41a9 | FileSeekViaSetFilePointer [structural] | [LLM] |
| 005c4439 | __read_lk | [LLM] |
| 005ccd21 | __alloc_osfhnd | [LLM] |
| 005cce44 | __set_osfhnd | [LLM] |
| 005ccfe0 | __unlock_fhandle | [LLM] |
| 005cee9b | __chsize_lk | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
