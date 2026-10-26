## InsertDriverTableEntry_00418560 — SortedTableInsert

**Summary:** Inserts an 8-DWORD entry into a 20-entry sorted table (at this+0x86C). Validates input, looks up driver data, computes score, finds insertion point by time/score ordering, shifts entries, and copies. Returns 1 on success, 0 on failure. Used by AI/commentary subsystems.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIDriverStateTransition (00419120), AISessionModeTransition (004193a0), AICornerSpeedComparison (00419500), AIOvertakeDefendStateChange (00419690), AIPositionChangeEvent (004198b0), AIRetirementVehicleFailureEvent (004199e0), PerDriverRaceCommentary (00419c50), AIOutOfTrackEvent (0041a0c0), AIVehicleDamageEvent (0041a170), AIPitStrategyState (0041a200), AISessionPhaseChange (0041a2b0), AIFormationLap (0041a3a0), DisplayMessage0x11c (0041a4a0), TimeBasedMessageChain (0041a500), DisplayMessage0x113 (0041a6b0), sub_41A720 (0041a720), AISessionEventAudio (0041a8c0), sub_41A940 (0041a940), AISessionPhaseCounter (0041aa10), PitStateSlotActivation (0041ab30), sub_41AC50 (0041ac50), sub_41AD80 (0041ad80), sub_41AFD0 (0041afd0), sub_41B190 (0041b190), DisplayMessage0x4a (0041b200), sub_41B250 (0041b250), PitSelectionStateMachine (0041b3c0), TeamNameDisplayIDLookup (0041b980), PitRaceStatusMessageDispatcher (0041be60), DisplayMessage0x202 (0041c090), PitExit (0041c0f0), DisplayMessage0x151 (0041c3e0), sub_41C440 (0041c440), PositionBasedMessageDisplay (0041c4c0), RaceCommentary (0041d630), SeasonDisplayIDResolver (0041daf0), ScoringClassificationDisplay (0041e320), PositionChangeDetector (00420490), ConstructorStandingsParser (00420820), GdbSeasonSelector (00420cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x86C | R | — | Start of 20-entry sorted table (each entry = 8 DWORDs × 4 = 32 bytes) |
| this | 0x880 | R | — | Threshold value for entry[5] comparison (sorting boundary) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bf9b0 | dword_5BF9B0 | R | DriverDataTable pointer — lookup by driver ID for entry[1] default value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004145c0 | StructCopy | Copies 8-DWORD entry struct (32 bytes) between table slots |
| 00418b70 | ShortComputation_8b70 | Computes score value stored in entry[7] |
| 00418b90 | ScoreThresholdGateCheck | Validates driver ID against scoring threshold; returns 0 to block insert |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x86C | == | 18446744072627421184 → -1.0f | Empty slot sentinel (entry[0] == -1.0f marks free slot) |

**Guard interpretation:** If `a2->field0` (input entry @ +0x0) == -1 (invalid ID), return 0 immediately. If `ScoreThresholdGateCheck(a2->field0)` returns 0, block insertion. Loop finds insertion point: v4 is first slot where entry[0] is -1.0f (empty) OR input entry[2] < entry[0] (earlier time) OR (entry[2] == entry[0] AND v17 > entry[5]) (same time, higher score). If no suitable slot (v4 < 0), return 0. Otherwise shift entries and insert, return 1.
