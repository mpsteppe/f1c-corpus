## GameExit_0042db20 — GameExit

**Summary:** Orchestrates full game teardown: logs entry, shuts down subsystems (sound, special effects, input, display, DynMan, OnScreen, session), and closes main handle. Sets game state to 7 (exiting).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 7 | Game state field; set to 7 (exit/teardown) on entry |

**Written-by note (persistence):**
- this 0x0: Set to 7 each call. Overwritten on each exit call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c36a8 | aEnteredGameExi | R | String_EnteredGame [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | Unknown session resource handle |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ca70 | DynMan_Exit | Log DynMan exit and cleanup |
| 0042d350 | SessionReset | Reset session/season resources |
| 00455f00 | HWInput_Exit | Shut down hardware input subsystem |
| 00464670 | ConditionalObjectCleanup | Conditionally free game module objects |
| 0049f120 | OnScreen_Exit | Shut down on-screen display system |
| 004b0170 | EmptyStub_0170 | Empty/no-op call (possibly debug placeholder) |
| 004ba770 | sub_4BA770 | Cleanup scoring-related data |
| 004c8d00 | Sound_Exit | Shut down sound system |
| 004cfff0 | SpecialFX_Exit | Shut down special effects system |
| 004d7a50 | StringSplitLoop | Parse/log build path for debug output |
| 004d7aa0 | DebugLogWrite | Write debug messages to debug buffer |
| 004fad00 | VidMan_Exit | Shut down video manager / display system |

**Guard conditions:** Guard: StringSplitLoop return value — zero BLOCKS individual debug log writes. All subsystem shutdown calls are unconditional (no guards).
