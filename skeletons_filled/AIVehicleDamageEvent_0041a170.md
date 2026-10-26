## AIVehicleDamageEvent_0041a170 — AIVehicleDamageEventHandler

**Summary:** Handles AI vehicle damage events. Selects behavior entry index: 52 for non-race context (practice/quali), 196 for race (session type 7). Looks up driver's team ID from vehicle struct and inserts damage event entry into driver action table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AICornerSpeedComparison (00419500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48A0 | R | — | Driver team ID (18592 = 0x4894); passed as param to behavior lookup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local struct with sentinel values before lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Looks up damage behavior entry (index 52 or 196) |
| 00418560 | InsertDriverTableEntry | Inserts damage event entry into driver action table |
| 004c7bd0 | sub_4C7BD0 | Session status query; non-zero return selects non-race damage index (52) |

**Guard conditions:** dword_7D0308 (RaceActiveFlag) must be non-zero. flt_7CF3C8 (TrackConditionState) != 0.0. For race damage path (index 196): dword_7C56A4 (SessionType) must be 7. If sub_4C7BD0 returns non-zero, uses non-race index (52). If session type != 7 AND sub_4C7BD0 returns 0, function returns without inserting.
