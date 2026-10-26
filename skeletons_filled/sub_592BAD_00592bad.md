## sub_592BAD_00592bad — CommandLineToArgvParse

**Summary:** Parses command line into argc/argv array using two-pass parser, allocating required memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0ec | GetModuleFileNameA | R | Win32 API to get executable path |
| 008d3e84 | dword_8D3E84 | W | CRTArgc [DERIVED] |
| 008d3e88 | dword_8D3E88 | W | CmdLineArgv [DERIVED] |
| 008d3ea0 | dword_8D3EA0 | W | CmdLineArgvPtr [DERIVED] |
| 008d40a4 | Filename | R | CRT_ModuleFileName [DERIVED] |
| 008d5a44 | dword_8D5A44 | R | CmdLinePtr [DERIVED] |
| 008d5a4c | dword_8D5A4C | R | InitGuardFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a2a6 | CRTAmsgExit | Exit with out-of-memory error code |
| 0058a935 | MallocWrapperForNhMalloc | Allocate argv array + string buffer |
| 00592c46 | sub_592C46 | Command line parser (two-pass) |
| 00597218 | LazyInitSingletonWithFlagGuard_7218 | Lazy init CRT singleton |

**Guard conditions:** If `dword_8D5A4C` (InitGuardFlag) is 0, lazy-initializes CRT singleton first. If malloc fails, calls `CRTAmsgExit(8u)` (BLOCKED: out of memory).
