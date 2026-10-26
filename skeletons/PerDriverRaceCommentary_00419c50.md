## PerDriverRaceCommentary_00419c50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceFinishHandler (004a0ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x4070 | R | — | noOfPenaltiesToProcess [CONFIRMED] |
| this | 0x4894 | R | — | [LLM] |
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
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 004c1190 | SceneOrderReader | [LLM] |
| 004c11d0 | FlagsGetter | [LLM] |
| 004c1390 | FixedOffsetReturn | [LLM] |
| 004c13a0 | ShortComputation_13a0 | [LLM] |
| 004c2850 | LinkedListDereference | [LLM] |
| 00566810 | sub_566810 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4064 | == | 1 | FinishState [FACT] == finished |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
