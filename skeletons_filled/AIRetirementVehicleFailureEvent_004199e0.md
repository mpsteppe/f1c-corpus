## AIRetirementVehicleFailureEvent_004199e0 — AIRetirementVehicleFailureHandler

**Summary:** Handles AI retirement/vehicle failure events for player's team during race (session type 7). Inserts driver behavior entries: initial failure notification (41), opponent retirement gap (1), leading vehicle gap (2, gated by status != 2), and final-lap countdown alerts (272/273). Calculates lap time gaps between vehicles.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4060 | R | — | position [CONFIRMED] — driver param used in lookup 41 |
| this | 0x40D0 | R | — | Pointer to opponent vehicle/standings entry (v1[4148]) |
| this | 0x40D4 | R | — | Pointer to leading vehicle struct (v1[4149]) |
| this | 0x4894 | R | — | Driver ID/team check (compared with player's team) |
| this | 0x8130 | R | — | Opponent's lap time param (v1[4148]+16480) |
| this | 0x8134 | R | — | Opponent's driver ID (v1[4148]+18588) |
| this | 0x8138 | R | — | Leading vehicle status (v4[4121]); guard: != 2 to process lookup 2 |
| this | 0x896C | R | — | Leading vehicle driver ID (v4[4647]) |
| this | 0x8970 | R | — | Leading vehicle lap param (v4[4120]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00419c0c | jpt_419B98 | R | Jump table for remaining-laps switch/case |
| 00419c18 | byte_419C18 | R | Jump table data bytes |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local struct with sentinel values before each lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Looks up behavior entries (indices 1,2,41,272,273) |
| 00418560 | InsertDriverTableEntry | Inserts behavior entry into driver action table |
| 0049b6d0 | LapTimeGapCalculation | Calculates lap time gap between two vehicles for gap-based entries |
| 00587bdc | CRTFtol | Converts float gap to int for lookup parameter |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8138 | != | 2 | Leading vehicle status flag |

**Guard interpretation:** RaceActiveFlag must be non-zero. TrackConditionState != 0.0. RacePhase != 8. SessionType must be 7. Vehicle must be on same team as player. When this+0x8138 (leading vehicle status) == 2, index 2 lookup is BLOCKED (vehicle already retired/processed). When != 2, index 2 entry is inserted with gap data. Remaining laps switch: 1 → index 273, 2-50 (specific values) → index 272, others → return (no entry).
