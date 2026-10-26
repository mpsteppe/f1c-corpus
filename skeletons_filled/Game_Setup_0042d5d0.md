## Game_Setup_0042d5d0 — GameSubsystemInitialization

**Summary:** Master game initialization: sets game state to "loading" (2), parses device path string, then sequentially initializes all game subsystems — input, scoring, options, special effects, physics steward, dynamics manager, sound, on-screen display, video manager, player file, and module manager.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 2 | game state flag (2 = setup/loading phase) |

**Written-by note (persistence):**
- this 0x0: one-time init at startup — external poke survives until next game restart

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3628 | aEnteredGameSet | R | EnteredGameSetString [DERIVED] |
| 005ec488 | dword_5EC488 | R | PlayerFile [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | unknown init parameter struct |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042c170 | DynMan_Setup | initialize dynamics/vehicle physics manager subsystem |
| 00455c60 | HWInput_Setup | initialize hardware input (keyboard/controller) subsystem |
| 00463ef0 | sub_463EF0 | initialize game module manager with module list |
| 0049ef70 | OnScreen_Setup | initialize on-screen display / HUD subsystem |
| 004a0eb0 | Options_Setup | initialize game options / settings subsystem |
| 004a1830 | sub_4A1830 | initialize session-related data structure |
| 004b1870 | PlayerFile_Setup | initialize player profile / save file subsystem |
| 004ba1e0 | SimpleZeroInit | zero-initialize scoring gate struct |
| 004c8ab0 | Sound_Setup | initialize audio / sound subsystem |
| 004ceec0 | SpecialFX_Setup | initialize special effects subsystem |
| 004d36d0 | Steward_Setup | initialize physics steward / force feedback subsystem |
| 004d7a50 | StringSplitLoop | parse device configuration path string |
| 004d7aa0 | DebugLogWrite | write debug log message ("Entered Game Setup") |
| 004f9160 | UtilityFunction_9160 | initialize player file utility / helper |
| 004fa2f0 | VidMan_Setup | initialize video manager / renderer subsystem |

**Guard conditions:** none — straight-line initialization sequence with two early-return points if Options_Setup or PlayerFile_Setup return non-zero (failure).
