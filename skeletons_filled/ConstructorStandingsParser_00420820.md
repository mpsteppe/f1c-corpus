## ConstructorStandingsParser_00420820 — ParseConstructorStandings

**Summary:** Parses constructor team standings: accumulates championship points for 14 F1 teams, determines top 3 with tie detection, inserts driver display table entries for podium teams.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringClassificationDisplay (0041e320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00420c44 | jpt_420875 | R | Switch jump table for first team-name selection loop |
| 00420c7c | jpt_420984 | R | Switch jump table for second-place team name output |
| 00420cb4 | jpt_420ABA | R | Switch jump table for third-place team name output |
| 005c25b4 | aToyota | R | Str_Team_Toyota [DERIVED] |
| 005c25bc | aStewart | R | String_Stewart [DERIVED] |
| 005c25c4 | aRenault | R | sTeamName_Renault [DERIVED] |
| 005c25cc | aBenetton | R | TeamName_Benetton [DERIVED] |
| 005c25d8 | aJaguar | R | StrJaguar [DERIVED] |
| 005c25e0 | off_5C25E0 | R | Unknown_Setup_25E0 [DERIVED] |
| 005c25e4 | aMinardi | R | TeamNameMinardi [DERIVED] |
| 005c25ec | aProst | R | aProst [DERIVED] |
| 005c25f4 | aArrows | R | TrackArrows [DERIVED] |
| 005c25fc | aSauber | R | TeamName_Sauber [DERIVED] |
| 005c2604 | aJordan | R | TrackNameJordan [DERIVED] |
| 005c260c | aWilliams | R | Str_Team_Williams [DERIVED] |
| 005c2618 | aFerrari | R | sTeamFerrari [DERIVED] |
| 005c2620 | aMclaren | R | TeamName_McLaren [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initialize struct with sentinel default values before filling |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Look up driver data and convert time values for display entry |
| 00415550 | LinkedListIndexScannerWithValidation | Scan linked list to find index matching team data path |
| 00418560 | InsertDriverTableEntry | Insert formatted entry into driver display table |
| 0041f220 | ChampionshipPointsAccumulator | Accumulate and return total championship points for a constructor team |
| 00566650 | StringCopyWithBufferRealloc | Copy team name string with buffer reallocation if needed |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory wrapper (cleanup) |

**Guard conditions:** v20 (tie flag for 2nd place) or v5 == -1 (no valid 2nd place): blocks 2nd-place insertion. a1 == 0: blocks individual 2nd-place (ID 423) and 3rd-place (ID 424) insertions during main path. v20, v14 (tie flag for 3rd place), or v10 == -1 (no valid 3rd place): blocks 3rd-place individual insertion, jumps to LABEL_84 early-return path. v5 != -1 && v10 != -1: allows combined 2nd+3rd place insertion with ID 488 at end. LABEL_84 returns 0 if a1 is set or ties exist; otherwise falls through to combined insertion.
