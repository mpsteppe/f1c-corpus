## AIDriverStateTransition_00419120 — AIDriverStateTransitionHandler

**Summary:** Handles AI driver state transitions (overtake/defend/pit/retire). Gated by race active, track condition, race phase, and valid state change. For session type 7, performs timed and randomized lookup into driver behavior tables (198/259/120 indices), inserts entry, updates driver's state field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFieldSetter (004bc2f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e804 | flt_59E804 | R | DistanceSquaredThreshold [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local struct with sentinel values before lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Looks up driver behavior data from table with time conversion |
| 00418560 | InsertDriverTableEntry | Inserts behavior entry into driver action table |
| 004189f0 | ArraySearchReturningIndex | Searches behavior array for matching index value |
| 004d1b50 | sub_4D1B50 | Resolves vehicle/driver pointer by driver ID |

**Guard conditions:** dword_7D0308 (RaceActiveFlag) must be non-zero. flt_7CF3C8 (TrackConditionState) != 0.0. dword_7C56A8 (RacePhase) != 8. Current state must differ from new state (a4). Old state (a3) must differ from new state. Session type == 7 required for main transition logic. Additional sub-guards for driver vs player, state type (1=pit/retire?), state ordering (a4 < a3), time gate (2.0s threshold), and random roll (<0.75 / >=0.25 trig lookups).
