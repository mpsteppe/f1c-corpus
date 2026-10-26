## OnScreen_Restart_0049f000 — OnScreen_Restart

**Summary:** OnScreen restart handler called during Game_Restart. Runs assertion log, dispatches resource calls, resets two state fields (0x4=1, 0x8=0), then walks table at 8AD2A8 clearing 25 entries via VTableDispatchWithFieldClear.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 1 | Active/visible flag set to 1 on restart |
| this | 0x8 | RW | 0 | Some boolean state cleared to 0 on restart |

**Written-by note (persistence):**
- this 0x4: Set to 1 unconditionally each restart; survives in parent struct
- this 0x8: Set to 0 unconditionally each restart; survives in parent struct

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccf10 | aDDevF119992002_16 | R | AssertStr_SourcePath_16 [DERIVED] |
| 005ccf70 | aEnteredOnscree_2 | R | String_EnteredOnScreen_2 [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bdf0 | ShortComputation_bdf0 | Resource dispatch computation |
| 0049f150 | FunctionCallWrapper_f150 | Writes session init complete flag and stores arg |
| 004d7a50 | StringSplitLoop | Assertion check parsing source path string (arg 2635) |
| 004d7aa0 | DebugLogWrite | Writes debug log message when assertion passes |

**Guard conditions:** Checks StringSplitLoop return != 0 (assertion log gate); loops 25 entries at 8AD2A8 — non-null entries dispatch VTableDispatchWithFieldClear
