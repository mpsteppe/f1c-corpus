## __ioinit_005c532a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** start (005c144e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d51bc | GetFileType | R | [LLM] |
| 005d51c0 | GetStdHandle | R | [LLM] |
| 005d51c4 | SetHandleCount | R | [LLM] |
| 005d521c | GetStartupInfoA | R | [LLM] |
| 008003e0 | dword_8003E0 | RW | [LLM] |
| 008003e4 | unk_8003E4 | R | [LLM] |
| 008004e0 | uNumber | RW | [LLM] |
| ff00000000005e0f | byte_FF00000000005E0F | R | [LLM] |
| ff00000000005e10 | byte_FF00000000005E10 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1556 | __amsg_exit | [LLM] |
| 005c1a4e | _malloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
