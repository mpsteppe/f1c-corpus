## AISessionModeTransition_004193a0 — SessionModeTransitionHandler

**Summary:** Processes a session mode transition (0/1/2) for AI commentary/event system. Validates race active, track condition, and player vehicle match. Converts mode index via FloatRangeIndexLookup/ThreeWayEnumConverter, checks ScoringGateSelector, then fires BooleanOROfTwoChecks + DriverDataTableLookupAndTimeConversion per mode, inserts table entry, and marks mode as transitioned. Part of AI session event pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to the session event storage table (passed to InsertDriverTableEntry) |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used to verify vehicle match |
| 007c56a8 | dword_7C56A8 | R | Race phase — checked != 8 for mode 1 transition path |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero to proceed |
| 008acee0 | dword_8ACEE0 | R | Force feedback base (unreferenced in this function directly) |
| 008ad264 | dword_8AD264 | R | Penalty message queue (unreferenced in this function directly) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct to sentinel values for new entry |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with driver data IDs and computed time values |
| 00418560 | InsertDriverTableEntry | Inserts the prepared entry into session event table |
| 00418a20 | BooleanOROfTwoChecks | Fires a Boolean OR check on two event flags for the mode |
| 004d1ad0 | ScoringGateSelector | Returns gate value (must be 2 to proceed) for mode-based scoring |
| 004d7c10 | FloatRangeIndexLookup | Converts a float value to an index when a3 == -1 |
| 004d7cc0 | ThreeWayEnumConverter | Maps mode index to 0/1/2 enum |

**Guard conditions:** All of: dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0, player vehicle field +18580 equals input object field +18580, ScoringGateSelector(v5) returns 2, this[v5+316] (state flag at this+0x4F0 + v5*4) must NOT be 2 (not already transitioned). If any fails, function returns early with no action.
