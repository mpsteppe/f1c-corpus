## UIListIndexedAccessor_00487010 — StringListIndexedAccess

**Summary:** Returns string pointer at index a2 from a linked list of string nodes. Traverses from head (this+0x44) following next pointers (offset 4). Returns fallback default string (byte_5EA438) if index out of bounds or node has no data. Part of UI string list system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_468BF0 (00468bf0), sub_469900 (00469900), ResultsPageBuilder (00469fb0), StandingsDisplay (0046a560), ProcessingDispatch (0046e590), ScreenMenuNavigationController (00470040), RaceModeScreenSetup (004707c0), SessionSetupScreenSetup (00470960), RaceSessionModeDataLoader (00470f20), ModeSpecificScreenSetup (00471440), TransmissionAIDifficultyScreenSetup (00471dc0), sub_472510 (00472510), sub_472630 (00472630), sub_472930 (00472930), UIStringFormatDisplay (00472cc0), sub_4732D0 (004732d0), UIFrontendCounterDisplayUpdate (004735b0), sub_474510 (00474510), TelemetryDisplaySwitch (0047dbe0), DriverCareerStatsHTMLWriter (0047dd10), sub_47E0A0 (0047e0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | head node's data pointer (first field) |
| *(this+0x48) | 0x4 | R | — | node's next pointer during linked-list traversal |
| this | 0x44 | R | — | head pointer of linked list |
| this | 0x50 | R | — | count of elements in list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: fallback default string returned on out-of-bounds) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 1) If a2 >= this[20] (count) or a2 < 0 → return fallback string (byte_5EA438). 2) If target node's data pointer (*v3) is null → return fallback string. 3) If data exists → return the string.
