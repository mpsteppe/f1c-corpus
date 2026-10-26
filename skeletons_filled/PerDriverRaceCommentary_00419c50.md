## PerDriverRaceCommentary_00419c50 — Per-Driver Race Finish Commentary Trigger

**Summary:** Generates race commentary/event entries when a driver finishes. Maps the driver's finishing position and current track name to a commentary ID, then inserts playback entries into a driver-table. Handles player-specific finish commentary, close-race gap commentary, and championship-mode logic.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceFinishHandler (004a0ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x4070 | R | — | noOfPenaltiesToProcess [CONFIRMED] |
| this | 0x4894 | R | — | number of penalties (raceFinishPenalties, checked as zero for clean finish) |
| this | 0x489C | R | — | DriverID [FACT] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c2628 | aIndianapolis | R | StringIndianapolis [DERIVED] |
| 005c2638 | aSuzuka | R | StrTrackSuzuka [DERIVED] |
| 005c2640 | aSepang | R | Str_Track_Sepang [DERIVED] |
| 005c2648 | aNurburgring | R | String_Nurburgring [DERIVED] |
| 005c2654 | aMonza | R | sTrackName_Monza [DERIVED] |
| 005c265c | aSpaFrancorcham | R | TrackName_Spa [DERIVED] |
| 005c2670 | aHungaroring | R | StrHungaroring [DERIVED] |
| 005c267c | aHockenheim | R | aHockenheim [DERIVED] |
| 005c2688 | aA1Ring | R | TrackNameA1Ring [DERIVED] |
| 005c2694 | aSilverstone | R | aSilverstone [DERIVED] |
| 005c26a0 | aMagnyCours | R | TrackMagnyCours [DERIVED] |
| 005c26ac | aMontreal | R | TrackName_Montreal [DERIVED] |
| 005c26b8 | aBarcelona | R | TrackNameBarcelona [DERIVED] |
| 005c26c4 | aMonaco_0 | R | Str_TrackName_Monaco [DERIVED] |
| 005c26cc | aImola | R | sTrackImola [DERIVED] |
| 005c26d4 | aInterlagos | R | TrackName_Interlagos [DERIVED] |
| 005c26e0 | aAlbertPark | R | TrackNameAlbertPark [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | initialize commentary entry struct with sentinel values (-2.0 sentinels) |
| 004144f0 | DriverDataTableLookupAndTimeConversion | insert commentary event into driver data table with timing |
| 00418560 | InsertDriverTableEntry | insert driver table record at flt_5EA618 pointer |
| 004c1190 | SceneOrderReader | read scene/track order from current scene module |
| 004c11d0 | FlagsGetter | get flags from linked list node |
| 004c1390 | FixedOffsetReturn | return value at fixed offset from linked-list dereference |
| 004c13a0 | ShortComputation_13a0 | short computation on index (likely vehicle pointer lookup) |
| 004c2850 | LinkedListDereference | dereference linked list pointer (race standings list) |
| 00566810 | sub_566810 | string comparison function (compare track name vs known track strings) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4064 | == | 1 | FinishState [FACT] == finished |

**Guard interpretation:** Only drivers with FinishState==1 (finished) AND no penalties (0x4070==0) trigger commentary. All other states BLOCKED. Player driver (DriverID matches dword_7C54E8+18580) gets track-specific commentary IDs (mapped via string comparison against 17 track strings). Non-player drivers get generic position-based IDs. Championship mode (dword_7D0410==4) adds close-race gap commentary (ID 159) when gap between cars exceeds threshold. Race must be active (dword_7D0308!=0) and track condition state non-zero.
