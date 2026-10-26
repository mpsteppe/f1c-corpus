## sub_592BAD_00592bad — [LLM: short descriptive name]

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
| 0059e0ec | GetModuleFileNameA | R | [LLM] |
| 008d3e84 | dword_8D3E84 | W | CRTArgc [DERIVED] |
| 008d3e88 | dword_8D3E88 | W | CmdLineArgv [DERIVED] |
| 008d3ea0 | dword_8D3EA0 | W | CmdLineArgvPtr [DERIVED] |
| 008d40a4 | Filename | R | CRT_ModuleFileName [DERIVED] |
| 008d5a44 | dword_8D5A44 | R | CmdLinePtr [DERIVED] |
| 008d5a4c | dword_8D5A4C | R | InitGuardFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a2a6 | CRTAmsgExit | [LLM] |
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |
| 00592c46 | sub_592C46 | [LLM] |
| 00597218 | LazyInitSingletonWithFlagGuard_7218 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
