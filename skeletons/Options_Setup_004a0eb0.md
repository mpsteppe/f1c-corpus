## Options_Setup_004a0eb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccfe4 | byte_5CCFE4 | RW | Byte_Unknown_Setup [DERIVED] |
| 005cd048 | aEnteredOptions | R | EnteredOptionsString [DERIVED] |
| 005cd064 | aDDevF119992002_17 | R | DevPathString [DERIVED] |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007ce250 | dword_7CE250 | RW | CollisionConfigVersion [DERIVED] (also: ` — frame counter) |
| 007ce25c | byte_7CE25C | RW | GlobalSessionFlag [DERIVED] (also: ` — exit flag) |
| 007ce25f | byte_7CE25F | R | SessionPauseFlag [DERIVED] |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] (also: ` -- init guard flag) |
| 007ce264 | dword_7CE264 | R | SessionStateFlag [DERIVED] (also: ` — sub-mode selector) |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404b50 | ShortComputation_4b50 | [LLM] |
| 00404b60 | sub_404B60 | [LLM] |
| 004186f0 | TextOverlayDisplayTimer | [LLM] |
| 004537b0 | sub_4537B0 | [LLM] |
| 00485b90 | sub_485B90 | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9ad0 | ArithmeticComparison_9ad0 | [LLM] |
| 004f9f00 | ConditionalInit | [LLM] |
| 004f9f30 | ConditionalStateReset | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
