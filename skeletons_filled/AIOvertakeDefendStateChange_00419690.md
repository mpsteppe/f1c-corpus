## AIOvertakeDefendStateChange_00419690 — AIOvertakeDefendStateHandler

**Summary:** Manages AI overtake/defend/pit state changes. Writes state flag (1) at this[a3+108]. For session type 5 (race): selects lookup index based on overtake (3/10/16/33), defend (4), or pit (5) relative to player and target. For session type 7 (quali): outlap state indices (72/262). Inserts behavior entry into driver table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D1C40 (004d1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005f0714 | dword_5F0714 | R | VEH[0].0x403C = lapNumber [CONFIRMED] |
| 005f0f74 | dword_5F0F74 | R | VEH[0].0x489C = DriverID [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local struct with sentinel values before lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Looks up behavior entry with selected index and driver ID |
| 00418560 | InsertDriverTableEntry | Inserts behavior entry into driver action table |
| 00418a20 | BooleanOROfTwoChecks | Queries/sets boolean flag checks on driver behavior table |

**Guard conditions:** dword_7D0308 (RaceActiveFlag) must be non-zero. flt_7CF3C8 (TrackConditionState) != 0.0. dword_7C56A8 (RacePhase) != 8. Session type must be 5 or 7. For a2==0 (overtake): writes state=1 at this[a3+108], selects index based on player/target relationship. For a2==1 (defend) and a2==2 (pit): requires not player, laps > 0, championship mode != 5. For session type 7: requires laps between 1 and total-1.
