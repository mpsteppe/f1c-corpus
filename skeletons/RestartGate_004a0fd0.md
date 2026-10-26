## RestartGate_004a0fd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | RW | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce250 | dword_7CE250 | RW | CollisionConfigVersion [DERIVED] (also: ` — frame counter) |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce258 | dword_7CE258 | RW | InitZeroFieldSet [DERIVED] |
| 007ce25d | byte_7CE25D | RW | GlobalFlagA0DA0 [DERIVED] (also: ` -- global flag) |
| 007ce25e | byte_7CE25E | RW | SessionRequestFlag [DERIVED] |
| 007ce25f | byte_7CE25F | R | SessionPauseFlag [DERIVED] |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] (also: ` -- init guard flag) |
| 007ce264 | dword_7CE264 | R | SessionStateFlag [DERIVED] (also: ` — sub-mode selector) |
| 007ce269 | byte_7CE269 | RW | SessionInitGate [DERIVED] (also: Init flag (char) |
| 007ce26c | dword_7CE26C | RW | RaceTimerValue [DERIVED] (also: Initialized to 5.0f) |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404b60 | sub_404B60 | [LLM] |
| 00404f00 | ByteFieldExtractorWithShift | [LLM] |
| 00404f30 | MainMenuTransition | [LLM] |
| 0042bc10 | ScoringGateCheck | [LLM] |
| 00485b90 | sub_485B90 | [LLM] |
| 004a0cb0 | sub_4A0CB0 | [LLM] |
| 004a0cf0 | ConditionalInitGuard | [LLM] |
| 004bc330 | FieldCopy_c330 | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
