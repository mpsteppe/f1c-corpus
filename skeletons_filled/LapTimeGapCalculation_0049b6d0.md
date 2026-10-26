## LapTimeGapCalculation_0049b6d0 — VehicleLapTimeGapCalculator

**Summary:** Computes the time gap between two vehicles based on lap count and sector times. If vehicles are on the same lap, returns signed gap. Handles lap-wrap scenarios (one lap ahead with smaller time, or multi-lap gaps). Returns 1 if first vehicle is behind by lap count, 0 if gap was computed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIRetirementVehicleFailureEvent (004199e0), sub_49C370 (0049c370), sub_49C4E0 (0049c4e0), VehicleStateUpdate (004d9fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x403C | R | — | lapNumber [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea408 | flt_5EA408 | R | SessionMaxTime [DERIVED] (also: ` — threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f01b0 | sub_4F01B0 | Reads sector/total time from vehicle at given offset |

**Guard conditions:** a1 == NULL or a2 == NULL → BLOCKED: return 1. If lap counts equal → PASSES to same-lap gap. If a1 laps <= a2 laps → BLOCKED: return 1 (behind). If a1 has exactly one more lap and time < other → PASSES to wrap-around gap. Otherwise → PASSES to multi-lap difference.
