## PlayerCareerStatsGameOptionsLoader_004c18b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameOptionsWriter (004c1e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | RW | — | [LLM] |
| *(this+0x4) | 0x4 | RW | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x14) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x4) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]

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
| 004c03a0 | AlternatingInit | [LLM] |
| 004c0ab0 | AudioSubsystemInitializer | [LLM] |
| 004c0b10 | PitStopMemoryCleanup | [LLM] |
| 004c0b70 | CareerSeasonStateFileReader | [LLM] |
| 004c18b0 | PlayerCareerStatsGameOptionsLoader | [LLM] |
| 004c2860 | LinkedListSearchByName | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00565760 | sub_565760 | [LLM] |
| 00565870 | sub_565870 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 0058850f | sub_58850F | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
