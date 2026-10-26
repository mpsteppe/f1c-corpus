## start_005c144e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bf888 | __except_handler3 | R | [LLM] |
| 005d5134 | GetModuleHandleA | R | [LLM] |
| 005d5214 | GetVersion | R | [LLM] |
| 005d5218 | GetCommandLineA | R | [LLM] |
| 005d521c | GetStartupInfoA | R | [LLM] |
| 005f65f8 | stru_5F65F8 | R | [LLM] |
| 007ff11c | dword_7FF11C | W | [LLM] |
| 007ff120 | dword_7FF120 | W | [LLM] |
| 007ff124 | dword_7FF124 | W | [LLM] |
| 007ff128 | dword_7FF128 | W | [LLM] |
| 007ff15c | dword_7FF15C | W | [LLM] |
| 00801504 | dword_801504 | W | [LLM] |
| ff000000000018bd | byte_FF000000000018BD | W | [LLM] |
| ff000000000018c1 | byte_FF000000000018C1 | RW | [LLM] |
| ff000000000018c2 | byte_FF000000000018C2 | R | [LLM] |
| ff000000000018c3 | byte_FF000000000018C3 | W | [LLM] |
| ff00000000005e0d | byte_FF00000000005E0D | RW | [LLM] |
| ff00000000005e0e | byte_FF00000000005E0E | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c460 | GameMainEntry [structural] | [LLM] |
| 005c0b4b | __cinit | [LLM] |
| 005c0b78 | _exit | [LLM] |
| 005c0b89 | __exit | [LLM] |
| 005c157b | _fast_error_exit | [LLM] |
| 005c50c1 | TLSAllocationThreadIDInit [structural] | [LLM] |
| 005c532a | __ioinit | [LLM] |
| 005c9ffa | __XcptFilter | [LLM] |
| 005ca172 | __wincmdln | [LLM] |
| 005ca1ca | __setenvp | [LLM] |
| 005ca283 | __setargv | [LLM] |
| 005ca4d0 | ___crtGetEnvironmentStringsA | [LLM] |
| 005ca777 | sub_5CA777 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
