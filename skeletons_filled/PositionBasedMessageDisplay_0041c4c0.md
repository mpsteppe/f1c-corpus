## PositionBasedMessageDisplay_0041c4c0 — PositionBasedRaceMessage

**Summary:** Dispatches a position-based race status message using standings buffer position and a computed message ID; switches between live timing parameters and default sentinels based on a boolean flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60), sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID and position+2 |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 004203d0 | ThunkToFUN004201e0 | Compute message ID for position-based race status |
| 004c2990 | sub_4C2990 | Query standings sort buffer for current position (returns 0-based) |

**Guard conditions:**
1. `dword_7D0308` (RaceActiveFlag) must be non-zero → PASSES: race active. BLOCKED: race inactive.
2. `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: track condition initialized. BLOCKED: track condition zero.
3. `a1` (boolean flag): non-zero → PASSES: use live timing params (-1.0, 0.0). Zero → use default sentinels (-2.0, -2.0).
