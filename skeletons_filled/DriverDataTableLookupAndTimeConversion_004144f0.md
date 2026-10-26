## DriverDataTableLookupAndTimeConversion_004144f0 — DriverDataLookupAndTimeCalc

**Summary:** Populates a struct with driver context IDs and computed time values. Uses sentinel-replacement logic (defaults from DriverDataTable globals) and performs time conversion via CRTFtol. Core lookup utility called by ~35 AI/commentary/display functions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIDriverStateTransition (00419120), AISessionModeTransition (004193a0), AICornerSpeedComparison (00419500), AIOvertakeDefendStateChange (00419690), AIPositionChangeEvent (004198b0), AIRetirementVehicleFailureEvent (004199e0), PerDriverRaceCommentary (00419c50), AIOutOfTrackEvent (0041a0c0), AIVehicleDamageEvent (0041a170), AIPitStrategyState (0041a200), AISessionPhaseChange (0041a2b0), AIFormationLap (0041a3a0), DisplayMessage0x11c (0041a4a0), TimeBasedMessageChain (0041a500), DisplayMessage0x113 (0041a6b0), sub_41A720 (0041a720), AISessionEventAudio (0041a8c0), sub_41A940 (0041a940), AISessionPhaseCounter (0041aa10), PitStateSlotActivation (0041ab30), sub_41AC50 (0041ac50), sub_41AD80 (0041ad80), sub_41AFD0 (0041afd0), sub_41B190 (0041b190), DisplayMessage0x4a (0041b200), sub_41B250 (0041b250), PitSelectionStateMachine (0041b3c0), TeamNameDisplayIDLookup (0041b980), PitRaceStatusMessageDispatcher (0041be60), DisplayMessage0x202 (0041c090), PitExit (0041c0f0), DisplayMessage0x151 (0041c3e0), sub_41C440 (0041c440), PositionBasedMessageDisplay (0041c4c0), RaceCommentary (0041d630), SeasonDisplayIDResolver (0041daf0), ScoringClassificationDisplay (0041e320), PositionChangeDetector (00420490), ConstructorStandingsParser (00420820), GdbSeasonSelector (00420cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Driver ID / primary index into tables |
| this | 0x8 | RW | — | Computed time value (result of CRTFtol conversion) |
| this | 0xC | RW | — | Adjusted time value (computed time + a8 offset + 0.2, or -1.0 sentinel) |
| this | 0x10 | RW | — | Parameter a3 (context/index copy) |
| this | 0x14 | RW | — | Parameter a4 (context/index copy) |
| this | 0x18 | RW | — | Parameter a5 (context/index copy) |
| this | 0x1C | RW | — | Parameter a6 (possibly replaced from DriverDataTable if -1) |

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
| 0059e670 | flt_59E670 | R | Sentinel flag constant (-2.0 comparison) |
| 0059e7e8 | flt_59E7E8 | R | Time scaling constant (5.0 used in CRTFtol expression) |
| 0059e7ec | flt_59E7EC | R | Constant 0.0 |
| 0059e7f0 | flt_59E7F0 | R | Default-from-table sentinel (-1.0 comparison for a8) |
| 005bf9a0 | dword_5BF9A0 | R | DriverDataTable — lookup replacement for a6 when -1 (5 DWORD stride) |
| 005bf9a4 | flt_5BF9A4 | R | DriverDataTable + 4 — default a8 float (5*4 byte stride) |
| 005bf9a8 | flt_5BF9A8 | R | DriverDataTable spacing value — default a7 float (5*4 byte stride) |
| 008afea8 | dbl_8AFEA8 | R | Input axis dead zone / base offset for CRTFtol computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Converts float expression to integer (floor/truncation), used for time computation |

**Guard conditions:** Checks a6 == -1 → replace from dword_5BF9A0[5*a2]. Checks a7 == -2.0 → replace default from flt_5BF9A8[5*a2]. Checks a8 == -2.0 → replace default from flt_5BF9A4[5*a2]. Checks a8 == -1.0 → set this[0x0C] = -1.0 (sentinel), else compute this[0x0C] = computed_time + a8 + 0.2.
