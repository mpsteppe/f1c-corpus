## DriverDataTableLookupAndTimeConversion_004144f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIDriverStateTransition (00419120), AISessionModeTransition (004193a0), AICornerSpeedComparison (00419500), AIOvertakeDefendStateChange (00419690), AIPositionChangeEvent (004198b0), AIRetirementVehicleFailureEvent (004199e0), PerDriverRaceCommentary (00419c50), AIOutOfTrackEvent (0041a0c0), AIVehicleDamageEvent (0041a170), AIPitStrategyState (0041a200), AISessionPhaseChange (0041a2b0), AIFormationLap (0041a3a0), DisplayMessage0x11c (0041a4a0), TimeBasedMessageChain (0041a500), DisplayMessage0x113 (0041a6b0), sub_41A720 (0041a720), AISessionEventAudio (0041a8c0), sub_41A940 (0041a940), AISessionPhaseCounter (0041aa10), PitStateSlotActivation (0041ab30), sub_41AC50 (0041ac50), sub_41AD80 (0041ad80), sub_41AFD0 (0041afd0), sub_41B190 (0041b190), DisplayMessage0x4a (0041b200), sub_41B250 (0041b250), PitSelectionStateMachine (0041b3c0), TeamNameDisplayIDLookup (0041b980), PitRaceStatusMessageDispatcher (0041be60), DisplayMessage0x202 (0041c090), PitExit (0041c0f0), DisplayMessage0x151 (0041c3e0), sub_41C440 (0041c440), PositionBasedMessageDisplay (0041c4c0), RaceCommentary (0041d630), SeasonDisplayIDResolver (0041daf0), ScoringClassificationDisplay (0041e320), PositionChangeDetector (00420490), ConstructorStandingsParser (00420820), GdbSeasonSelector (00420cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e7f0 | flt_59E7F0 | R | DefaultFromTableSentinel [DERIVED] (also: ` — sentinel value (use default from table) |
| 005bf9a0 | dword_5BF9A0 | R | DriverDataTable [DERIVED] |
| 005bf9a4 | flt_5BF9A4 | R | DriverDataField4 [DERIVED] (also: ` (DriverDataTable + 4) |
| 005bf9a8 | flt_5BF9A8 | R | DriverDataTableSpacing [DERIVED] |
| 008afea8 | dbl_8AFEA8 | R | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
