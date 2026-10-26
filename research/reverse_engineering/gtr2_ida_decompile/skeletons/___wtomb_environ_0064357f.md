## ___wtomb_environ_0064357f — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _getenv (006426b7), ___crtsetenv (00643ac9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f12a8 | WideCharToMultiByte | R | [LLM] |
| 00fb81bc | dword_FB81BC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | [LLM] |
| 00634c1d | _malloc | [LLM] |
| 00643ac9 | ___crtsetenv | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
