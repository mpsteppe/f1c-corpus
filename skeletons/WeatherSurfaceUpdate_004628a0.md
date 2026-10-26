## WeatherSurfaceUpdate_004628a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461550 | FAILWRONGDESCRIPTION | [LLM] |
| 00461610 | SessionConfigBuilder | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 00462760 | BufferSendWithLocks | [LLM] |
| 004630d0 | UniqueID | [LLM] |
| 00463760 | ConditionalStateDispatch | [LLM] |
| 004a0dc0 | SystemOSAPICall_0dc0 | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
