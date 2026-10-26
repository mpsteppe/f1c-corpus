## TrackOpeningProgressTimer_004612e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x29 | RW | 1 | [LLM] |
| this | 0x2C | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x29: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059f0b4 | flt_59F0B4 | R | TrackOpenInitialSpeed [DERIVED] (also: ` — initial open flag value) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6134 | aApplyingFrameT | R | StringApplyingFrameT [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045e570 | UtilityFunction_e570 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
