## ___crtsetenv_005cf818 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** WideCharMultiByteStringConversionWithAllocLoop [structural] (005cf4cc)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d50e4 | SetEnvironmentVariableA | R | [LLM] |
| 007ff138 | dword_7FF138 | RW | [LLM] |
| 007ff13c | dword_7FF13C | R | [LLM] |
| 007ff140 | dword_7FF140 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1a4e | _malloc | [LLM] |
| 005c1b88 | sub_5C1B88 | [LLM] |
| 005c293d | sub_5C293D | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005c6f50 | _strcpy | [LLM] |
| 005cf4cc | WideCharMultiByteStringConversionWithAllocLoop [structural] | [LLM] |
| 005cf99f | _findenv | [LLM] |
| 005cf9f7 | NullTerminatedIntArrayCopyWithAlloc [structural] | [LLM] |
| 005cfa5e | __mbschr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
