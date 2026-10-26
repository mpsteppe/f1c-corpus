## AICornerSpeedComparison_00419500 — AICornerSpeedComparisonHandler

**Summary:** Compares AI's corner/sector speed against current vehicle's corner speed array at offset 0x4050. Selects driver behavior table index based on speed delta and corner index (1 or 2). Inserts overtake (13/14) or being-overtaken (19/20) behavior entry. On corner 2 while pitting, triggers vehicle damage event.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3450 | R | — | pittingStatus [CONFIRMED] — triggers damage event when == 1 and a2 == 2 |
| this | 0x4894 | R | — | Unknown field (referenced via comparator); part of vehicle struct layout |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005f0780 | flt_5F0780 | R | VEH[0].0x40A8 — AI corner/sector speed array (VEH stride 4656) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local struct with sentinel values before lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Looks up behavior entry (indices 13,14,19,20) based on speed comparison and corner index |
| 00418560 | InsertDriverTableEntry | Inserts behavior entry into driver action table |
| 0041a170 | AIVehicleDamageEvent | Handles vehicle damage event when pitting on corner 2 |
| 004d1b50 | sub_4D1B50 | Resolves vehicle/driver index by index (player = 0) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3450 | == | 1 | pittingStatus [CONFIRMED] |

**Guard interpretation:** RaceActiveFlag must be non-zero. TrackConditionState != 0.0. RacePhase != 8. SessionType must be 5. Vehicle must be on same team as player. Speed comparison must yield valid result (speed > 0). When this+0x3450 (pittingStatus) == 1 AND a2 == 2, AIVehicleDamageEvent is called unconditionally. a2 value (1 or 2) determines which lookup index table entry to use (13/14 for faster AI, 19/20 for slower AI).
