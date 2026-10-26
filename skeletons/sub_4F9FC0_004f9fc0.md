## sub_4F9FC0_004f9fc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), SessionSynchronizer (0045f950), VidMan_Restart (004fa640)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afea0 | dbl_8AFEA0 | W | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008afea8 | dbl_8AFEA8 | W | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556700 | BoundsCheckAgainstDAT008b8e48 | [LLM] |
| 00556760 | sub_556760 | [LLM] |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
