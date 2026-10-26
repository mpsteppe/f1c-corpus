## ___crtExitProcess_00633cf8 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _doexit (00633dbc), _fast_error_exit (00634720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f10e0 | GetProcAddress | R | [LLM] |
| 006f11c4 | GetModuleHandleA | R | [LLM] |
| 006f1210 | ExitProcess | R | [LLM] |
| 007304fc | aCorexitprocess | R | [LLM] |
| 0073050c | aMscoreeDll | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `CorExitProcess`
- `mscoree.dll`
