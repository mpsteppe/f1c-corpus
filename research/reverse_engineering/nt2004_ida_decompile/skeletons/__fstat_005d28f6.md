## __fstat_005d28f6 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** MathDispatchWithErrorFallback [structural] (0044be60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d50bc | GetFileInformationByHandle | R | [LLM] |
| 005d5154 | GetLastError | R | [LLM] |
| 005d51bc | GetFileType | R | [LLM] |
| 005d5224 | FileTimeToLocalFileTime | R | [LLM] |
| 005d5228 | FileTimeToSystemTime | R | [LLM] |
| 005d5264 | PeekNamedPipe | R | [LLM] |
| 008004e0 | uNumber | R | [LLM] |
| ff00000000005de5 | byte_FF00000000005DE5 | R | [LLM] |
| ff00000000005de6 | byte_FF00000000005DE6 | R | [LLM] |
| ff00000000005ef2 | byte_FF00000000005EF2 | R | [LLM] |
| ff00000000005ef3 | byte_FF00000000005EF3 | R | [LLM] |
| ff00000000005ef5 | byte_FF00000000005EF5 | R | [LLM] |
| ff00000000005ef6 | byte_FF00000000005EF6 | R | [LLM] |
| ff00000000005ef7 | byte_FF00000000005EF7 | R | [LLM] |
| ff00000000005ef8 | byte_FF00000000005EF8 | R | [LLM] |
| ff00000000005f6b | byte_FF00000000005F6B | R | [LLM] |
| ff00000000005f6c | byte_FF00000000005F6C | R | [LLM] |
| ff00000000005f6d | byte_FF00000000005F6D | R | [LLM] |
| ff00000000005f6e | byte_FF00000000005F6E | R | [LLM] |
| ff00000000005f71 | byte_FF00000000005F71 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c19c9 | ErrorIDLookupTable [structural] | [LLM] |
| 005c1a3c | __errno | [LLM] |
| 005c918b | ___loctotime_t | [LLM] |
| 005ccf81 | __lock_fhandle | [LLM] |
| 005ccfe0 | __unlock_fhandle | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
