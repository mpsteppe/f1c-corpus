## SessionMenuModeSwitch_004a0c60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceFinishHandler (004a0ba0), sub_4A0CB0 (004a0cb0), LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007c569c | dword_7C569C | W | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f00 | ByteFieldExtractorWithShift | [LLM] |
| 00404f30 | MainMenuTransition | [LLM] |
| 00408420 | ReciprocalWithSignCheck | [LLM] |
| 004a0d10 | GlobalStateOneTimeInitializer | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
