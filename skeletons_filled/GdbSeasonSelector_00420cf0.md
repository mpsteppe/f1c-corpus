## GdbSeasonSelector_00420cf0 — SeasonDatabaseTeamSelector

**Summary:** Selects the F1 team with the most active drivers for the current season database, using tie-breaking logic; then loads the correct season's GDB file and inserts driver performance data into the global table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringClassificationDisplay (0041e320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Driver/entity name pointer; used as key for LinkedListIndexScannerWithValidation lookups |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00421200 | jpt_420DA8 | R | Jump table entry for switch dispatch on team index (case 0..13) |
| 00421238 | jpt_420EB7 | R | Jump table entry for switch dispatch on team index |
| 00421270 | jpt_420FAE | R | Jump table entry for switch dispatch on team index |
| 004212a8 | jpt_421015 | R | Jump table entry for switch dispatch on team index |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] |
| 005bf97c | aF12001Gdb | R | aF12001Gdb [DERIVED] |
| 005bf988 | aF12000Gdb | R | TrackDatabaseFilename [DERIVED] |
| 005bf994 | aF11999Gdb | R | aF11999Gdb [DERIVED] |
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
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initialize driver stats structure (8 floats) to sentinel values before population |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Look up driver data for a given team index and convert lap times |
| 00415550 | LinkedListIndexScannerWithValidation | Scan linked list to find driver entry index by name string |
| 00418560 | InsertDriverTableEntry | Insert processed driver data record into global table |
| 0041f220 | ChampionshipPointsAccumulator | Compute total championship points for a team to identify current season |
| 0041f340 | sub_41F340 | Load or fetch the season GDB database file path string |
| 004212e0 | ShortComputation_12e0 | Compute a numeric score for tie-breaking when two teams share the same max active count |
| 00421380 | CountActiveEntitiesByState | Count how many drivers/entities are active for the currently selected team |
| 00566650 | StringCopyWithBufferRealloc | Set the current team name string into an internal buffer |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory (team list pointer, temporary structures) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 8-byte tracking structure when this pointer is NULL |
| 00588410 | sub_588410 | String comparison — check if a season GDB filename matches the current path |

**Guard conditions:** 
- `this == NULL` → allocates internal 8-byte tracking structure (v32), proceeds with full logic. If `sub_41F340` returns NULL after — early exit returns 0.
- First pass (tie-breaking pass 1): after iterating all 14 teams — if `v5 == -1` (no team found with any active entities matching the baseline season), returns 0 immediately. If one team has a strictly greater max, it wins. If multiple teams tie, `v31 = 1` triggers second pass.
- Second pass (tie-breaking pass 2): iterates only the tied teams, calls `ShortComputation_12e0` for each. If `v14 == -1` after this pass (no winner), returns 0. If `v13` is still set (unresolvable tie), copies the season file path string, frees, and sets `v3 = 1` (skip driver data insertion? no — still calls InsertDriverTableEntry after). PASSES when a single team emerges as winner.
- Season file selection: cascading `sub_588410` checks for `aF11999Gdb`, `aF12000Gdb`, `aF12001Gdb`, `aF12002Gdb` against `dword_7D0434` path. Selects a season ID (492, 496, 500, or 504) for `DriverDataTableLookupAndTimeConversion`. Blocks each path if the file does not exist, falls through to next candidate.
- Cleanup: if `v3` (local alloc flag) and `v1` (this or allocated struct) are non-null, frees `*v1` and `v1` before returning.