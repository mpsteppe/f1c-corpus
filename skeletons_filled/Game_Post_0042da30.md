## Game_Post_0042da30 — Game Post-Frame Subsystem Dispatch

**Summary:** Main per-frame Post() dispatch: calls all engine subsystems in order — guarded dispatch, nested call loop, sound, special FX, steward, hardware input, dynamics, camera, render, on-screen display, video manager, player file, and session state — then sets multiplayer flags to 3. Called from GameMainEntry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 6 | game state / phase identifier (set to 6 = post-frame phase) |

**Written-by note (persistence):**
- this 0x0: recalc every call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3690 | aEnteredGamePos | R | s_DebugEnteredGamePos [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | unknown — role unclear from decompilation |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004045f0 | ShortComputation_45f0 | processes setup scene pointer (short computation on dword_5EA2C0) |
| 0040cce0 | CamMan_Post | camera manager post-frame update |
| 0042c9f0 | DynMan_Post | dynamics manager post-frame update |
| 00455e70 | HWInput_Post | hardware input post-frame update |
| 00464600 | SessionStateByte7CE25FSetter | sets session state byte from game module manager |
| 0049f0d0 | OnScreen_Post | on-screen display / HUD post-frame update |
| 004a11b0 | GlobalFlagClear | clears session transition flag |
| 004a1830 | sub_4A1830 | processes unknown session data (unk_7CE2A4) |
| 004b1900 | PlayerFile_Post | player file / profile post-frame update |
| 004b4170 | Render_Post | renderer post-frame update |
| 004ba740 | GuardedDispatchWithStateCheck | guarded dispatch with scoring gate state check |
| 004bdde0 | F_65xNestedCallLoop | 65-element nested call loop over UI widget list |
| 004c8ca0 | Sound_Post | sound system post-frame update |
| 004cfed0 | SpecialFX_Post | special effects post-frame update |
| 004d4600 | Steward_Post | steward/force-feedback post-frame update |
| 004d7a50 | StringSplitLoop | splits device path string, checks for match — gates debug log |
| 004d7aa0 | DebugLogWrite | writes "Entered Game Post" debug message |
| 004fac00 | VidMan_Post | video manager / race phase timer post-frame update |
| 004fd6d0 | TwoCallDelegation_d6d0 | two-call delegation on setup struct |

**Guard conditions:** StringSplitLoop return value gates DebugLogWrite only (conditional debug log). All 19 subsystem Post() calls execute unconditionally in sequence. No branching or early-return from the main dispatch chain. Final write to dword_7C56A0 is unconditional (set to 3).