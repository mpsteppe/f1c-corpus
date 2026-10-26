## Options_Setup_004a0eb0 — OptionsSetupHandler

**Summary:** Handles options/setup screen initialization and main processing loop. Manages state transitions between initial setup, options screen entry, and session initialization. Logs entry detection, checks guard flags, and runs setup loop until exit condition.

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
| 00404b50 | ShortComputation_4b50 | Short computation on SetupDirSuffix |
| 00404b60 | sub_404B60 | Processes SetupDirSuffix data |
| 004186f0 | TextOverlayDisplayTimer | Manages text overlay display timing |
| 004537b0 | sub_4537B0 | Processes module pointer array with cooling rate |
| 00485b90 | sub_485B90 | Performs session processing returning state result |
| 004a1830 | sub_4A1830 | Processes Windows message queue |
| 004d7a50 | StringSplitLoop | Parses config string for options entry detection |
| 004d7aa0 | DebugLogWrite | Writes debug log entry |
| 004f9ad0 | ArithmeticComparison_9ad0 | Arithmetic comparison on race phase timer |
| 004f9f00 | ConditionalInit | Conditional initialization of timer state |
| 004f9f30 | ConditionalStateReset | Resets conditional timer state |

**Guard conditions:** Three main paths: (1) If byte_7CE260 (InitGuard) is non-zero → sets byte_7C5690=1 and returns 0 (early setup exit). (2) Else if dword_7CE264 (SessionStateFlag) is non-zero → checks byte_5CCFE4: if byte_5CCFE4 is set, clears it and returns 0; otherwise returns 1 (waiting for options completion). (3) Else (main loop): runs setup processing loop until byte_7CE25C (exit flag) is set or sub_485B90 returns -1 (pause/error) or 1 (continue).
