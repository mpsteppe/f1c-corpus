## __NMSG_WRITE_005ca80d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __amsg_exit (005c1556), _fast_error_exit (005c157b), __FF_MSGBANNER (005ca7d4), _abort (005ce891)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d514c | GetModuleFileNameA | R | [LLM] |
| 005d51c0 | GetStdHandle | R | [LLM] |
| 005d5290 | WriteFile | R | [LLM] |
| 005f7270 | aMicrosoftVisua | R | [LLM] |
| 005f7298 | asc_5F7298 | R | [LLM] |
| 005f729c | aRuntimeErrorPr | R | [LLM] |
| 005f72b8 | aProgramNameUnk | R | [LLM] |
| 006021b0 | asc_6021B0 | R | [LLM] |
| 00625274 | dword_625274 | R | [LLM] |
| 00626568 | dword_626568 | R | [LLM] |
| 0062656c | off_62656C | R | [LLM] |
| 006265f8 | off_6265F8 | R | [LLM] |
| 007ff164 | dword_7FF164 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005beab0 | _strncpy | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005c6f50 | _strcpy | [LLM] |
| 005c6f60 | _strcat | [LLM] |
| 005ce754 | ___crtMessageBoxA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Microsoft Visual C++ Runtime Library`
- `Runtime Error!

Program: `
- `<program name unknown>`
- `...`
- `Hr_`
- `Hr_`
