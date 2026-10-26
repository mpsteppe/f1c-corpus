## PlayerCareerStatsGameOptionsLoader_004c18b0 — PlayerCareerStatsGameOptionsLoader

**Summary:** Loads player career statistics and game options from save data — reads season state files, track stats, and game configuration parameters, building internal linked lists of career data records; validates track/directory existence before committing results.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameOptionsWriter (004c1e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | RW | — | next pointer in secondary linked list (track/dir entries) |
| *(this+0x4) | 0x4 | RW | — | next pointer in primary linked list (career season entries) |
| this | 0x0 | RW | — | head pointer of primary linked list (career season data) |
| this | 0x4 | RW | — | tail pointer of primary linked list (last node inserted) |
| this | 0x8 | RW | — | end sentinel of primary linked list (initial head on first insert) |
| this | 0xC | R | — | primary list node count (read and incremented) |
| this | 0x10 | RW | — | head pointer of secondary linked list (track/directory entries) |
| this | 0x14 | RW | — | tail pointer of secondary linked list |
| this | 0x18 | RW | — | end sentinel of secondary linked list |
| this | 0x1C | R | — | secondary list node count (read and incremented) |
| this | 0x44 | RW | — | career stat: average start position (float, parsed from string) |
| this | 0x48 | RW | — | career stat: average finish position (float) |
| this | 0x4C | RW | — | career stat: average race distance (float) |
| this | 0x50 | RW | — | career stat: average opponent strength (float) |
| this | 0x54 | RW | — | career stat: mechanical failure rate (dword, 0/1) |
| this | 0x68 | RW | — | game option: race condition reconnection (dword) |
| this | 0x6C | RW | — | game option: race condition walkthrough (dword) |

**Written-by note (persistence):**
- *(this+0x14) 0x4: write-once load — external poke survives until next load
- *(this+0x4) 0x4: write-once load — external poke survives until next load
- this 0x0: write-once load — external poke survives until next load
- this 0x4: write-once load — external poke survives until next load
- this 0x8: write-once load — external poke survives until next load
- this 0x10: write-once load — external poke survives until next load
- this 0x14: write-once load — external poke survives until next load
- this 0x18: write-once load — external poke survives until next load
- this 0x44: write-once load — external poke survives until next load
- this 0x48: write-once load — external poke survives until next load
- this 0x4C: write-once load — external poke survives until next load
- this 0x50: write-once load — external poke survives until next load
- this 0x54: write-once load — external poke survives until next load
- this 0x68: write-once load — external poke survives until next load
- this 0x6C: write-once load — external poke survives until next load

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d28cc | aTrackfile | R | TrackFile [DERIVED] |
| 005d28d8 | aTrackname_0 | R | TrackNameField [DERIVED] |
| 005d28e4 | aBestlaptime | R | BestLapTimeString [DERIVED] |
| 005d28f0 | aTotalnumlaps | R | TotalnumlapsString [DERIVED] |
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
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac050 | unk_8AC050 | R | Unknown_SceneSetup_8AC050 [DERIVED] |
| 008ac1e8 | unk_8AC1E8 | R | SceneRenderStruct [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c03a0 | AlternatingInit | initializes an alternating/dual-buffer data struct (24 bytes) |
| 004c0ab0 | AudioSubsystemInitializer | initializes audio subsystem with a 45396-byte allocation |
| 004c0b10 | PitStopMemoryCleanup | cleans up pit stop memory / releases resources |
| 004c0b70 | CareerSeasonStateFileReader | reads and parses a career season state file into the allocated buffer |
| 004c18b0 | PlayerCareerStatsGameOptionsLoader | recursive call to load player track stats from the same config source |
| 004c2860 | LinkedListSearchByName | searches a linked list for a node matching a given name string |
| 005651b0 | sub_5651B0 | returns a state/index key from the config reader |
| 005654a0 | sub_5654A0 | reads a string value from the config by key into a buffer |
| 00565520 | sub_565520 | reads a string value from config, returns success flag |
| 00565760 | sub_565760 | reads an integer/dword config value by key, stores result |
| 00565870 | sub_565870 | reads an extended config value (possibly float or multi-field) |
| 00566650 | StringCopyWithBufferRealloc | copies a string into a reallocated buffer |
| 00566cc0 | ConditionalDispatchBasedOnFlag | loop control — returns true while config data remains to be parsed |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory via a wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation wrapper |
| 00587c20 | sub_587C20 | string comparison / key match against config reader state |
| 0058850f | sub_58850F | parses a float value from a string buffer |

**Guard conditions:** The function returns 0 immediately if `*a2 == 0` (no config data provided). Within the parsing loop, `LinkedListSearchByName` checks whether the loaded track/directory already exists — if found, all allocated memory is freed and the function returns 0 (duplicate prevention).
