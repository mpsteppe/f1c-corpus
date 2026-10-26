## sub_592DFA_00592dfa — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e10c | GetEnvironmentStringsW | R | [LLM] |
| 0059e110 | GetEnvironmentStrings | R | [LLM] |
| 0059e114 | FreeEnvironmentStringsW | R | [LLM] |
| 0059e118 | FreeEnvironmentStringsA | R | [LLM] |
| 0059e228 | WideCharToMultiByte | R | [LLM] |
| 008d41a8 | dword_8D41A8 | RW | CRT_EnvCache_Flag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |
| 0058aa6f | sub_58AA6F | [LLM] |
| 0058cc00 | MemoryCopy_cc00 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
