## Game_Enter_0042d370 — Game Subsystems Enter / Initialization

**Summary:** Game session initialization entry point — sequentially initializes all subsystems (OS manager, game files, video, special FX, dynamics, player data, audio configs, sound, input, on-screen display, game modules) and loads audio asset directories. Returns 1 on any init failure, 0 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | game-entered flag (1 = active/alive, set at function entry) |

**Written-by note (persistence):**
- this 0x0: init once at session start — external poke persists until next game enter

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] |
| 005c3590 | aDDevF119992002_11 | R | device path / config string (parsed by StringSplitLoop) | DevicePath_99_02 [DERIVED] |
| 005c3600 | aPit | R | ".pit" file extension string for directory search | PitString [DERIVED] |
| 005c3608 | aRcd | R | ".rcd" file extension string for directory search | Str_Rcd [DERIVED] |
| 005c3610 | aEnteredGameEnt | R | debug log message: "Entered game enter" | EnteredGameEnterString [DERIVED] |
| 005ea438 | byte_5EA438 | R | default application directory (fallback when season dir null) | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | season directory path (may be null) | SeasonDir [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | unused in this function |
| 007ca590 | ppvOut | R | module pointer array (passed to HWInput_Enter) | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | game module manager (passed to sub_463E20) | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | race session state (passed to OnScreen_Enter) | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | session transition flag (passed to EmptyStub_0170) | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | OS manager state (passed to OSMan_Enter) | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce498 | byte_7CE498 | R | auto-load config file flag (passed to PlayerFile_Enter) | AutoLoadConfigFile [DERIVED] |
| 007d0434 | dword_7D0434 | R | season path suffix string (appended to season dir) | SeasonPath [DERIVED] |
| 007d0438 | dword_7D0438 | R | game config flag (unused in this function) | GameConfigFlag [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | scoring gate (passed to EmptyStub_0170 for reset) | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | first scene name in scene array (passed to Sound_Enter) | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | scoring grid base (passed to SpecialFX_Enter) | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | force feedback base (passed to EmptyStub_0170 for reset) | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | debug message buffer (passed to DebugLogWrite) | DebugMessageBuffer [DERIVED] |
| 008ad3b0 | dword_8AD3B0 | R | file search data / directory iterator state | FileSearchData [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | game data directory (unused in this function) | GameDataDir [DERIVED] |
| 008afe18 | unk_8AFE18 | R | game race phase timer (passed to VidMan_Enter) | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042c130 | DynMan_Enter | initializes dynamics/physics manager |
| 0042d260 | GameFileLoader | loads game configuration/data files from disk |
| 00455bf0 | HWInput_Enter | initializes hardware input system (keyboard, wheel, gamepad) |
| 00463e20 | sub_463E20 | initializes game module manager |
| 0049ef40 | OnScreen_Enter | initializes on-screen display / HUD system |
| 004a18d0 | OSMan_Enter | initializes OS-level manager (window, message loop) |
| 004b0170 | EmptyStub_0170 | no-op stub (reset/clear call for session transition, scoring gate, force feedback) |
| 004b1820 | PlayerFile_Enter | loads player profile/config file |
| 004c8a20 | Sound_Enter | initializes sound system with first scene name |
| 004cee90 | SpecialFX_Enter | initializes special effects system |
| 004d7a50 | StringSplitLoop | parses a device/config string into tokenized parts |
| 004d7aa0 | DebugLogWrite | writes debug log message to buffer |
| 004fa000 | VidMan_Enter | initializes video/render manager |
| 00565f20 | LinkedListNodePeek | advances linked-list iterator to next node |
| 00565f80 | sub_565F80 | opens directory search for files matching extension |
| 005662d0 | DirectoryEntryIterator | iterates directory entries from file search |
| 00566650 | StringCopyWithBufferRealloc | copies fallback audio config filename into buffer |
| 00567f40 | AudioFileLoadDecode | loads and decodes an audio configuration file |
| 0058815f | StringFormatWithBufferOverflowCheck | formats a path string with season dir + season path suffix |

**Guard conditions:** None — unconditional sequential initialization. Each subsystem Enter call returns non-zero on failure, causing early return 1. If no failures, returns 0 after all subsystems initialized. The audio file loading has a fallback: if the primary audio config file fails to load, it falls back to "F12002.gdb" (copied via StringCopyWithBufferRealloc) and retries.
