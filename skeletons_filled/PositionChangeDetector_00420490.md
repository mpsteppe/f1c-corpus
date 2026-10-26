## PositionChangeDetector_00420490 — LeadingPositionChangeDispatcher

**Summary:** Detects position changes for top-2 standings entries by scanning for entries with position values 1 and 2 at offset 412, checking for tied values at offset 408; dispatches message 397 with driver display info when `a1` is set and the position is uniquely held.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDisplayIDResolver (0041daf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID and driver display info |
| 00415230 | NamedEntryLookupInFormatList | Resolve display name/ID from format list using entrant name |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Get first/base standings entry pointer |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- **Position 1 scan:** searches for entry with offset 412 == 1 (first position). If not found → skip position-1 dispatch.
- **Position 2 scan:** searches for entry with offset 412 == 2 (second position). If not found → skip position-2 dispatch.
- For each position: if another entry has the same value at offset 408 → sets tie flag (v36/v37 = 1), suppressing dispatch.
- Position 1 dispatch fires only when: `!v36 && a1` (no tie AND dispatch flag set) → message 397 with position param 2.
- Position 2 dispatch fires only when: `!v37 && a1` and position-2 entry exists → message 397 with position param 3.
- When `a1 == 0`: no dispatch occurs; returns tie status flags.
