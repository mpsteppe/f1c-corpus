## RaceLapsStringLoadOnTrigger_0047e3f4 — RaceLapsDisplayUpdate

**Summary:** Loads and displays race laps data by traversing season data with "racelaps" key and showing the result string in the UI.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7444 | aRacelaps | R | String_RaceLaps [DERIVED] — "racelaps" string key for season data lookup |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] — season data root for racelaps query |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488b40 | UIStringComparison | display the loaded race laps string in the UI |
| 004c5840 | SeasonRacesSectionFinder | find the season races data section root |
| 00567970 | DataEntryAccessor | extract string data from linked list node |
| 005679c0 | StringKeyedLinkedListSearch | traverse linked list by "racelaps" string key |

**Guard conditions:** If SeasonRacesSectionFinder returns null, or StringKeyedLinkedListSearch for "racelaps" fails, returns without displaying.
