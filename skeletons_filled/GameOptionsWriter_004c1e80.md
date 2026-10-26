## GameOptionsWriter_004c1e80 — Game options / career stats file parser and loader

**Summary:** Parses game options and career statistics from config files: reads career season state, player track stats, and race condition settings (qualifying, race length, opponent strength, fuel/tire multipliers, speed compensation, mechanical failure rate, weather, flags, format). Populates an options struct for use in race setup. Part of the game options / career system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FAILWRONGTRIAGECATEGORY (004c22a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | RW | — | next pointer in linked list of career state entries |
| this | 0x0 | RW | — | head pointer of career state linked list |
| this | 0x4 | RW | — | tail pointer of career state linked list |
| this | 0x8 | RW | — | tail pointer copy (set to same as 0x4 on first insert) |
| this | 0xC | R | — | count of career state entries |
| this | 0x44 | RW | — | total races with (string-loaded int) |
| this | 0x48 | RW | — | total points scored (string-loaded int) |
| this | 0x4C | RW | — | total championships (string-loaded int) |
| this | 0x50 | RW | — | total wins (string-loaded int) |
| this | 0x54 | RW | — | total poles (string-loaded int) |
| this | 0x68 | RW | — | average finish position (float) |
| this | 0x6C | RW | — | average race distance (float) |

**Written-by note (persistence):**
- *(this+0x4) 0x4: set once during file parse — external poke survives until next parse
- this 0x0: set once during file parse — external poke survives until next parse
- this 0x4: set once during file parse — external poke survives until next parse
- this 0x8: set once during file parse — external poke survives until next parse
- this 0x44: set once during file parse — external poke survives until next parse
- this 0x48: set once during file parse — external poke survives until next parse
- this 0x4C: set once during file parse — external poke survives until next parse
- this 0x50: set once during file parse — external poke survives until next parse
- this 0x54: set once during file parse — external poke survives until next parse
- this 0x68: set once during file parse — external poke survives until next parse
- this 0x6C: set once during file parse — external poke survives until next parse

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2900 | aGameoptSpeedCo | R | sGameOptSpeedCompare [DERIVED] |
| 005d2914 | aGameoptTireMul | R | String_GameoptTireMult [DERIVED] |
| 005d2928 | aGameoptFuelMul | R | StrGameOptFuelMult [DERIVED] |
| 005d293c | aGameoptOpponen | R | StrGameOptOpponent [DERIVED] |
| 005d2950 | aGameoptRaceLen | R | Key_GameOptRaceLen [DERIVED] |
| 005d2964 | aGameoptRaceTim | R | Str_GameOptRaceTime [DERIVED] |
| 005d2978 | aGameoptRaceLap | R | StringGameoptRaceLap [DERIVED] |
| 005d298c | aGameoptQualify | R | StrGameOptQualify [DERIVED] |
| 005d29a4 | aRacecondTimesc | R | Str_RaceCondTimeScale [DERIVED] |
| 005d29c0 | aRacecondWeathe | R | String_RaceCondWeather [DERIVED] |
| 005d29d4 | aRacecondFlagRu | R | sRaceCondFlagRule [DERIVED] |
| 005d29e8 | aRacecondFormat | R | RaceConditionFormat [DERIVED] |
| 005d29fc | aRacecondWalkth | R | StrRaceCondWalkth [DERIVED] |
| 005d2a14 | aRacecondReconn | R | aRacecondReconn [DERIVED] |
| 005d2a2c | aMechfailRate | R | ConfigKeyMechFailRate [DERIVED] |
| 005d2a3c | aAvgopponentstr | R | aAvgopponentstrength [DERIVED] |
| 005d2a50 | aAvgracedistanc | R | AvgRaceDistKey [DERIVED] |
| 005d2a60 | aAvgfinishposit | R | StringAvgFinishPosit [DERIVED] |
| 005d2a74 | aAvgstartpositi | R | StringAvgStartPosition [DERIVED] |
| 005d2a88 | aTotallaprecord | R | Str_TotalLapRecord [DERIVED] |
| 005d2a98 | aTotalpoles | R | sTotalPoles [DERIVED] |
| 005d2aa4 | aTotalwins | R | String_TotalWins [DERIVED] |
| 005d2ab0 | aTotalchampions | R | StrTotalChampions [DERIVED] |
| 005d2ac4 | aTotalpointssco | R | StrTotalPointsScore [DERIVED] |
| 005d2ad8 | aTotalraceswith | R | Key_TotalRacesWith [DERIVED] |
| 005d2aec | aTotalraces | R | Str_TotalRaces [DERIVED] |
| 005d2af8 | aTotallaps | R | StringTotalLaps [DERIVED] |
| 005d2b04 | aAbortedseasons | R | StrAbortedSeasons [DERIVED] |
| 005d2b14 | aPlayertracksta | R | StrPlayerTrackStat [DERIVED] |
| 005d2b28 | aCareerseason | R | aCareerseason [DERIVED] |
| 008ac050 | unk_8AC050 | R | Unknown_SceneSetup_8AC050 [DERIVED] |
| 008ac1e8 | unk_8AC1E8 | R | SceneRenderStruct [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0ab0 | AudioSubsystemInitializer | initialize career season state object (constructor) |
| 004c0b10 | PitStopMemoryCleanup | cleanup career state memory on parse failure |
| 004c0b70 | CareerSeasonStateFileReader | read career season state from file |
| 004c18b0 | PlayerCareerStatsGameOptionsLoader | load player career stats into options struct |
| 005651b0 | sub_5651B0 | classify config line type |
| 00565520 | sub_565520 | parse key=value from config line |
| 00565760 | sub_565760 | parse integer value from config line |
| 00565870 | sub_565870 | parse extended value from config line |
| 00566cc0 | ConditionalDispatchBasedOnFlag | conditional dispatch based on flag state |
| 00587bcf | FreeWrapper_7bcf | free memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory |
| 00587c20 | sub_587C20 | string prefix match check |
| 0058850f | sub_58850F | parse float from string |

**Guard conditions:** The outer loop is gated by `*a2 != 0` (input pointer non-null) and `ConditionalDispatchBasedOnFlag` returning true (file still has data). Each section is dispatched by string prefix match: `aCareerseason` triggers career state loading with linked-list insertion, `aPlayertracksta` triggers player stats loading, and all other sections fall through to the generic key=value parser loading totals, averages, and race condition settings. Line type 1 or 4 triggers early return 0 (end-of-section or end-of-file).
