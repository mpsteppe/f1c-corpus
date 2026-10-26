## AITargetDriverSelection_00418ee0 — AIDriverTargetClassification

**Summary:** Classifies each driver slot relative to player: player self (1), teammate (2), scoring/overtake target (3), or retired/invalid (-1). Iterates vehicle entries (4656-byte stride), writes classification dword per slot. Called at race restart for driver targeting init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HUDDisplayDataReset (00418e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 2 | Driver classification output array (per-slot dword: -1=retired, 0=default, 1=player, 2=teammate, 3=target) |

**Written-by note (persistence):**
- this 0x0: written per driver slot with classification; overwritten each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e7f4 | flt_59E7F4 | R | ScoringComparisonConst [DERIVED] |
| 005f0cf8 | unk_5F0CF8 | R | VEH[0].0x4620 = DriverName [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c9af8 | dword_7C9AF8 | R | Unknown_Struct_7C9AF8 [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041e840 | NestedDataSectionFieldAccessor | Accesses nested data section field for scoring threshold comparison |
| 0041e890 | AIEntrantLookupByName | Looks up AI entrant by vehicle driver name |
| 004c2990 | sub_4C2990 | Queries count from standings/classification sort buffer |

**Guard conditions:** ChampionshipMode == 2 (championship screen): all drivers set to 0, skip classification. Vehicle entry sentinel -1: set to -1 (retired) and skip. Vehicle == player vehicle: set to 1 (player). Same team as player: set to 2 (teammate). ChampionshipMode != 4 (not race weekend): skip scoring target classification. Scoring thresholds and position gaps gate the target (3) assignment.
