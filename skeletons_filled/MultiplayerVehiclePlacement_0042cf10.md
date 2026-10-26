## MultiplayerVehiclePlacement_0042cf10 — MultiplayerVehiclePlacementStateMachine

**Summary:** Manages multiplayer session placement state transitions (0-7). Handles vehicle field copies, championship standings reordering, and debug logging at each state step. Clamps game state on exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), SessionSynchronizer (0045f950), sub_4A0590 (004a0590), SessionSceneInitChain (004a0630), SessionInit (004a06e0), LoadVehicleEntries (004b70b0), Steward_Init (004d38f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Current placement state (0-7); read to compare, written on transition |

**Written-by note (persistence):**
- this 0x8: Set to the new state (a2) after every call. Overwritten each invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c355c | aMultiplayerMod | R | MultiplayerModeString [DERIVED] |
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cebc4 | byte_7CEBC4 | R | FormationLap [DERIVED] |
| 007d00ec | dword_7D00EC | W | GameState (1-7) [DERIVED] |
| 007d00f4 | dword_7D00F4 | R | GameStateMin [DERIVED] |
| 007d00f8 | dword_7D00F8 | R | GameStateUpperBound [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461db0 | SessionStateCheckWrapper | Test if session is active/initialized |
| 00461dc0 | StateCheckWrapper | Check if session state allows transitions |
| 00462a10 | ChampionshipStandingsReOrdering | Reorder championship standings for race order |
| 00462e20 | sub_462E20 | Handle non-championship standings ordering |
| 004bc320 | FieldCopy | Copy vehicle telemetry/lap data fields |
| 004bc330 | FieldCopy_c330 | Copy a different set of vehicle fields |
| 004c01a0 | sub_4C01A0 | Handle pre-race state transition logic |
| 004c2830 | ConditionalSeasonDataFree | Free season data if championship mode |
| 004c6f10 | sub_4C6F10 | Post-placement per-vehicle initialization |
| 004d7a50 | StringSplitLoop | Parse/log build path for debug output |
| 004d7aa0 | DebugLogWrite | Write debug message to buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 5 | Current placement state == 5 |

**Guard interpretation:** this[2] == 5: PASSES (enters field-copy loop for all vehicles when session active + state check passes). != 5: BLOCKED (skips that copy loop). Outer guards: SessionStateCheckWrapper returning zero BLOCKS entire active path → falls to offline transition path. StateCheckWrapper returning zero within active path BLOCKS championship handling.
