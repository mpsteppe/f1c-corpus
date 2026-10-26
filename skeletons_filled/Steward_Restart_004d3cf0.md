## Steward_Restart_004d3cf0 — Steward_Restart

**Summary:** Initializes/resets the race steward/session state machine at game restart, setting session-specific parameters (laps, time limits, speed scaling, display labels) based on the session type (practice/qualifying/race/pre-race presentation). Reads configuration overrides from vehicle/track data files and resets internal arrays and state flags. Part of the race session management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | R | — | pointer to scaling/randomization data (float pointer), passed to RandomScaledValue at end |
| this | 0xAC | RW | 2147483647 | session lap count: INT_MAX (unlimited) for practice, or actual lap count from config/track data (dword_7D04A4 for session 5) |
| this | 0xB0 | RW | 2139095039 | session time lower bound (float): 0 for practice/presentation, ~40.0s for qualifying/race, or 2139095039 (sentinel) |
| this | 0xB4 | RW | 2139095039 | session time upper bound (float): computed total session duration in seconds, or 2139095039 (sentinel), or fixed values for presentation paths |
| this | 0xB8 | RW | — | race time from config override (float, v71 * 60.0), or scaled by flt_7D0798; written via data file parsing |
| this | 0xBC | RW | 1065353216 → 1.0f | laps-per-session ratio (float): set to 1.0 default, or computed as laps_from_config / total_laps for presentation |
| this | 0xC0 | RW | 0 | byte flag: session state byte at this+192, always reset to 0 |
| this | 0xC1 | RW | 0 | byte flag at this+193, always reset to 0 |
| this | 0xC2 | RW | 0 | byte flag at this+194, reset to 0; conditionally written in presentation fallback path |
| this | 0xCE | RW | 0 | byte at this+206: null-terminator written after name string copy (sub_587DD0 copies to this+195, zeroes this+206) |
| this | 0xD0 | RW | 1190993920 → 32400.0f | default race duration in seconds (9 hours), overwritten by config-parsed value (hours:minutes:seconds.fraction) |
| this | 0xD4 | RW | 1102169884 → 22.2222f | default speed in m/s (~80 km/h converted by *0.277778), overwritten by config value from data files |
| this | 0xD8 | RW | 2139095039 | some float sentinel at this+216, reset to 2139095039 in practice and presentation fallback paths |
| this | 0x104 | RW | 0 | byte flag at this+260, always reset to 0 |
| this | 0x10C | R | — | array element count (this+268), guards loop that resets internal arrays |
| this | 0x110 | R | — | pointer to first internal array (this+272), elements passed to ShortComputation_0f00 for reset |
| this | 0x114 | R | — | pointer to second internal array (this+276), elements zeroed in reset loop |
| this | 0x118 | RW | 18446744072877927208 → -1000000000.0f | large negative sentinel float at this+280 (-1.0e9f), marks uninitialized state |
| this | 0x11C | RW | 0 | session-dependent value at this+284: 0 normally, dword_7D0894 for presentation mode |
| this | 0x120 | RW | 0 | field at this+288, always reset to 0 |
| this | 0x190 | RW | 18446744073709551615 | 0x68-byte memset to 0xFF at this+296: bulk-resets standings/pit data (192 bytes), WORD at 0x190 set to 0xFFFF |
| this | 0x192 | RW | 18446744073709551615 | byte at this+402 set to 0xFF (part of the 0xFF memset block, sentinel for standings data) |

**Written-by note (persistence):**
- this 0xAC: written once at restart with session lap count; may be overwritten by config data parsing in same call, survives until next restart
- this 0xB0: written once at restart; session type default, may be overridden by config data
- this 0xB4: written once at restart; session time limit, computed or sentinel
- this 0xB8: conditionally written when config data found (v23/v25/v34/v36); absent config preserves prior value
- this 0xBC: written once at restart; always 1.0 or computed presentation ratio
- this 0xC0: written once at restart (always 0), external poke survives until next restart
- this 0xC1: written once at restart (always 0), external poke survives until next restart
- this 0xC2: written once at restart (0 normally; may be set to 0 again in presentation else-branch)
- this 0xCE: written conditionally when name string copied from config data; absent config preserves prior value
- this 0xD0: written once at restart with default 32400.0 or config value; external poke survives
- this 0xD4: written once at restart with default 22.2222 or config value; external poke survives
- this 0xD8: written once at restart; sentinel or reset value
- this 0x104: written once at restart (always 0), external poke survives
- this 0x118: written once at restart with large negative sentinel; marks uninitialized
- this 0x11C: written once at restart (0 or dword_7D0894); external poke survives
- this 0x120: written once at restart (always 0), external poke survives
- this 0x190: bulk memset to 0xFF at restart; external poke survives until next restart
- this 0x192: part of bulk memset at restart; external poke survives until next restart

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d453c | jpt_4D4162 | R | jump table for switch on session type (dword_7C56A4) sub-cases within case 6 |
| 004d455c | jpt_4D41E4 | R | jump table for switch on session type time defaults (cases 1,2,5 / 3,4 / 6) |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e9c8 | dbl_59E9C8 | R | Unknown_Double_59E9C8 [DERIVED] |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 0059fb48 | dbl_59FB48 | R | PhysicsConstant_59FB48 [DERIVED] |
| 005acf00 | dbl_5ACF00 | R | Double_Unknown_Render [DERIVED] |
| 005c32fc | aLaps_1 | R | LapsLabel [DERIVED] |
| 005c3300 | byte_5C3300 | R | VehicleFile_Count [DERIVED] |
| 005d2310 | aRacetime | R | aRacetime [DERIVED] |
| 005d3b6c | aDDevF119992002_3 | R | aDDevF119992002_3 [DERIVED] |
| 005d430c | aPreracepresent | R | PreRacePresentationString [DERIVED] |
| 005d4320 | dword_5D4320 | R | TrackCVarConstant [DERIVED] |
| 005d4324 | dword_5D4324 | R | UnknownDataInt [DERIVED] |
| 005d4328 | byte_5D4328 | R | Unknown_Byte_5D4328 [DERIVED] |
| 005d432c | aRacetimescaled | R | RacetimescaledString [DERIVED] |
| 005d433c | asc_5D433C | R | ASCIIString_5D433C [DERIVED] |
| 005d4340 | aDDF | R | Str_DDF [DERIVED] |
| 005d434c | aDefaultscoring | R | DefaultScoringString [DERIVED] |
| 005d435c | aWednesday | R | WednesdayString [DERIVED] |
| 005d4368 | byte_5D4368 | R | HUDVisibilityFlag [DERIVED] |
| 005d4374 | byte_5D4374 | R | CarNumberFontIndex [DERIVED] |
| 005d4384 | dword_5D4384 | R | Dword5D4384 [DERIVED] |
| 005d4388 | word_5D4388 | R | Unknown_Word_5D4388 [DERIVED] |
| 005d438c | off_5D438C | R | off_5D438C [DERIVED] |
| 005d4390 | aEnteredSteward_1 | R | String_EnteredSteward_1 [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 007cec54 | dword_7CEC54 | R | ReconPitClosed [DERIVED] |
| 007cec90 | dword_7CEC90 | R | VehicleLoadState [DERIVED] |
| 007ced8c | dword_7CED8C | R | UIRacePhaseFlag [DERIVED] |
| 007cee88 | dword_7CEE88 | R | SessionInitFlags [DERIVED] |
| 007d04a4 | dword_7D04A4 | R | RaceUint32_7D04A4 [DERIVED] |
| 007d05a0 | dword_7D05A0 | R | Race_UriCheck_05A0 [DERIVED] |
| 007d0798 | flt_7D0798 | R | RaceSetupScaling [CONFIRMED] |
| 007d0894 | dword_7D0894 | R | UnknownGameStateInt [DERIVED] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040da30 | CameraDirectorResetInit | resets the camera director system (case 7, presentation mode) |
| 0040dc00 | StringPathExtensionManipulation | manipulates file/string path extensions (case 7 initialization) |
| 0040dcd0 | StateMachineInitializer | initializes the state machine for pre-race presentation mode |
| 0042ce30 | SessionTypeNameLookup | looks up the display name for the current session type (returns "Practice"/"Qualifying"/"Race") |
| 0042d140 | sub_42D140 | sets session type state in dword_7C569C (param: 5=practice, 0=qual/race, 2=UI phase, 3=init, 4=fallback) |
| 00448300 | RandomScaledValue | generates a random scaled value from the float array at this+0xA8 |
| 004c29f0 | sub_4C29F0 | processes/sorts race standings data from dword_7D2DB0 buffer |
| 004c5840 | SeasonRacesSectionFinder | finds/loads season races configuration section (param 0); returns handle for config overrides |
| 004d0ec0 | ArithmeticComparison_0ec0 | sets arithmetic comparison state on sub-object (this+232 or this+244) with mode parameter |
| 004d0f00 | ShortComputation_0f00 | resets computation state for an array element (param 0) |
| 004d1cd0 | SingleCallWrapper_1cd0 | single-call wrapper that resets the steward state machine |
| 004d2dd0 | sub_4D2DD0 | called during case 7 sub-paths (recon pit and race phase) — additional state init |
| 004d7a50 | StringSplitLoop | debug string parsing utility; returns bool for conditional logging |
| 004d7aa0 | DebugLogWrite | writes a debug log message to dword_8AD25C buffer |
| 00567970 | DataEntryAccessor | accesses a data entry value from linked list node returned by StringKeyedLinkedListSearch |
| 005679c0 | StringKeyedLinkedListSearch | searches a linked list for a node matching a string key; returns data node handle |
| 00568210 | AudioChannelStop | stops the default scoring audio channel; returns non-zero if audio config data is available |
| 00587dd0 | sub_587DD0 | copies a name string (11 chars) from config data entry to destination buffer |
| 00587ece | sub_587ECE | parses an integer value from config data entry |
| 0058850f | sub_58850F | parses a float value from config data entry |
| 005887ed | StrlenFormatCallWrapper | sscanf-style format string parser; returns number of successfully parsed fields |

**Guard conditions:** The StringSplitLoop debug check gates a debug log write ("Entered Steward"). The main dispatch is the switch on dword_7C56A4 (session type): case 0 = practice (laps=INT_MAX, time=unlimited), cases 1-6 = qualifying/race (time-based with config overrides), case 7 = pre-race presentation (camera + state machine init, then sub-cases for recon pit / race phase / init flags / fallback). Within cases 1-7, v72 (AudioChannelStop result) being non-zero enables config data parsing from vehicle/track files — StringKeyedLinkedListSearch results override default speed, duration, name, laps, and race time. SeasonRacesSectionFinder result (v27/v75) provides a second override source (season-specific configs). In case 7, dword_7CEC90 (vehicle load state) triggers recon pit path; dword_7CED8C (UI race phase) triggers race phase path; dword_7CEE88 (session init flags) triggers init state; else falls through to presentation fallback with sentinel values. The loop at this+0x10C (> 0) resets internal arrays element by element only if count is positive. The final guard: if this+0xA8 is non-null, calls RandomScaledValue on it.
