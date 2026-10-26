## DynMan_Init_0042c1a0 — Dynamic Manager Initialization

**Summary:** Initializes the Dynamic Manager subsystem during game startup: selects the player vehicle index from the vehicle array, loads AI driver names and counts, handles formation lap state, loads vehicle graphics scenes for all vehicles, and sets up player name/identity.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e9d0 | flt_59E9D0 | R | Flt_59E9D0_Race [DERIVED] |
| 0059e9d4 | flt_59E9D4 | R | Flt_Physics_Const_E9D4 [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 005c3374 | aEnteredDynmanI | R | EnteredDynManIString [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 005ef9a0 | dword_5EF9A0 | R | Vehicle array base (first slot dword checked for null to find empty player vehicle slot) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5690 | byte_7C5690 | R | InitStateFlag (0 = first init, runs AI driver setup; non-zero = already initialized) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable [DERIVED] |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007c87a0 | dword_7C87A0 | R | End-of-vehicle-array sentinel pointer (past last vehicle slot) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007cebc4 | byte_7CEBC4 | R | FormationLap flag (0 = no formation lap, non-zero = formation lap active) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040fe50 | sub_40FE50 | Global instance initialization (passes dword_5EA560) |
| 0042bbd0 | SetPlayerVehicleIndex | Sets the current player vehicle index to the first found empty slot |
| 0042bc40 | SetPlayerVehicleIndex_bc40 | Sets player vehicle index (secondary registration) |
| 0042bc80 | BuildActiveVehiclePointerArray | Builds array of pointers to active vehicles from vehicle slots |
| 004326e0 | PlayerNameSetup | Sets up player name from module callback table |
| 004336f0 | LoadAIDriverNamesFromConfig | Loads AI driver names from configuration file for current vehicle |
| 004b1520 | sub_4B1520 | Reads vehicle data to populate AI driver name buffer |
| 004bfd90 | AIDriverCountSetup | Configures number of AI drivers from loaded names |
| 004bff70 | sub_4BFF70 | Default/null AI driver setup (non-formation-lap path) |
| 004c01a0 | sub_4C01A0 | Formation lap AI driver setup (championship mode + session type 1-4) |
| 004c6c40 | VehgenScnFileLoader | Loads vehicle graphics scene file for one vehicle |
| 004d7a50 | StringSplitLoop | Debug conditional print guard |
| 004d7aa0 | DebugLogWrite | Writes formatted debug log message to buffer |
| 004f9480 | sub_4F9480 | Loading progress bar update (sets current position) |
| 005895a2 | sub_5895A2 | Loading progress bar range setup (sets upper bound) |

**Guard conditions:**
- `dword_7D0410 (ChampionshipMode) != 4`: If not championship mode, skips setting vehicle array field offset (v2[868] = index+1). PASSES: ChampionshipMode == 4. BLOCKED: ChampionshipMode != 4 (the assignment is skipped).
- `!*v2` (vehicle slot dword == 0): NULL vehicle entry → breaks out of search loop, selects this index as player vehicle. PASSES: slot empty (NULL). BLOCKED: slot occupied (keeps searching).
- `v1 == 104`: All 104 vehicle slots occupied → fallback to player index 0. PASSES: fallback triggered. BLOCKED: v1 < 104 (normal flow).
- `!byte_7C5690` (InitStateFlag == 0): First-time initialization → runs AI driver setup via sub_4B1520/AIDriverCountSetup, then checks `dword_7D0410 != 3 || !byte_7CEBC4` to decide formation lap vs default AI setup. PASSES: InitStateFlag == 0 (first init). BLOCKED: InitStateFlag non-zero (already initialized, skips to direct check of `v0 == 4 && v4`).
- `dword_7D0410 == 4 && (SessionType 1-4)`: Championship mode + qualifying/race session types → runs formation lap AI setup (sub_4C01A0). PASSES: both conditions true. BLOCKED: either condition false (uses default sub_4BFF70 instead).
- `(unsigned int)dword_7C54E4 < 0x68 && !*(_DWORD *)(dword_7C54F0[dword_7C54E4] + 13000)`: Valid vehicle index AND vehicle driver name field is null → loads AI driver names from config. PASSES: index < 104 and no driver name set. BLOCKED: index >= 104 or driver name already set.
