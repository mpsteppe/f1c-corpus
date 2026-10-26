## CareerStatsWriter_004c2420 — CareerStatsFileWriter

**Summary:** Writes career statistics (player/opponent states, track records, race conditions, game options) to an output buffer using format strings. Iterates two linked lists: player-opponent state nodes and per-track stat records. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CareerSectionReader (004c2700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | output buffer validity token (checked at entry to guard writes) |
| this | 0x4 | R | — | player/opponent state linked list head pointer |
| this | 0x8 | RW | — | current iterator node into player/opponent state list |
| this | 0xC | R | — | track stats data container pointer (unused directly) |
| this | 0x10 | R | — | track stats linked list head pointer |
| this | 0x18 | RW | — | current iterator node into track stats list |
| this | 0x1C | R | — | pointer to output buffer context struct (passed as a2) |

**Written-by note (persistence):**
- this 0x8: conditional (only written when player list head is non-null; advanced through nodes via next pointer at +4); external poke via list modification survives
- this 0x18: conditional (only written when track list head is non-null and first node valid; advanced via next pointer at +4); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c4064 | aS_7 | R | BackupExt [DERIVED] |
| 005d2b14 | aPlayertracksta | R | StrPlayerTrackStat [DERIVED] |
| 005d2b28 | aCareerseason | R | aCareerseason [DERIVED] |
| 005d2b38 | aBestlaptimeF | R | BestLapTimeFormat [DERIVED] |
| 005d2b48 | aTotalnumlapsD | R | TotalNumLapsString [DERIVED] |
| 005d2b5c | aTrackfileS | R | TrackfileString [DERIVED] |
| 005d2b6c | aTracknameS | R | TrackNameFormatStr [DERIVED] |
| 005d2b7c | aGameoptSpeedCo_0 | R | GameoptSpeedCoString [DERIVED] |
| 005d2b94 | aGameoptTireMul_0 | R | GameoptTireMulField [DERIVED] |
| 005d2bac | aGameoptFuelMul_0 | R | GameoptFuelMult [DERIVED] |
| 005d2bc4 | aGameoptOpponen_0 | R | String_GameOptOpponent_0 [DERIVED] |
| 005d2bdc | aGameoptRaceLen_0 | R | GameOptRaceLenString [DERIVED] |
| 005d2bf4 | aGameoptRaceTim_0 | R | GameoptRaceTimString [DERIVED] |
| 005d2c0c | aGameoptRaceLap_0 | R | GameoptRaceLapString [DERIVED] |
| 005d2c24 | aGameoptQualify_0 | R | String_GameoptQualify [DERIVED] |
| 005d2c40 | aRacecondTimesc_0 | R | RaceCondTimeScaleString [DERIVED] |
| 005d2c60 | aRacecondWeathe_0 | R | RaceCondWeather [DERIVED] |
| 005d2c78 | aRacecondFlagRu_0 | R | RacecondFlagRunField [DERIVED] |
| 005d2c90 | aRacecondFormat_0 | R | RaceCondFormatString [DERIVED] |
| 005d2ca8 | aRacecondWalkth_0 | R | RacecondWalkthString [DERIVED] |
| 005d2cc4 | aRacecondReconn_0 | R | RacecondReconnString [DERIVED] |
| 005d2ce0 | aMechfailRateD | R | Str_MechFailRate [DERIVED] |
| 005d2cf8 | aChampionshipSe | R | Str_ChampionshipSe [DERIVED] |
| 005d2d7c | aAvgopponentstr_0 | R | StringAvgOpponentsStr [DERIVED] |
| 005d2d94 | aAvgracedistanc_0 | R | AvgRaceDistanceString [DERIVED] |
| 005d2da8 | aAvgfinishposit_0 | R | AvgFinishPositionString [DERIVED] |
| 005d2dc0 | aAvgstartpositi_0 | R | AvgStartPositionString [DERIVED] |
| 005d2dd8 | aTotallaprecord_0 | R | TotalLapRecordStr [DERIVED] |
| 005d2dec | aTotalpolesD | R | TotalPolesDString [DERIVED] |
| 005d2dfc | aTotalwinsD | R | TotalWinsField [DERIVED] |
| 005d2e0c | aTotalchampions_0 | R | TotalChampionships [DERIVED] |
| 005d2e24 | aTotalpointssco_0 | R | String_TotalPointsScored [DERIVED] |
| 005d2e3c | aTotalraceswith_0 | R | TotalRacesWithString [DERIVED] |
| 005d2e54 | aTotalracesD | R | TotalracesDString [DERIVED] |
| 005d2e64 | aTotallapsD | R | TotalLapsFormatString [DERIVED] |
| 005d2e74 | aAbortedseasons_0 | R | String_AbortedSeasons [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0cc0 | PlayerOpponentStateWriter | write individual player/opponent state entry to buffer with season label |
| 00566c30 | BufferWriteWithStringLengthCheck | write a string to the output buffer with length validation |

**Guard conditions:** Guard at a2->offset 0x0 (output buffer validity pointer): non-zero → write all career stats to buffer; zero → skip entire function and return 0.
