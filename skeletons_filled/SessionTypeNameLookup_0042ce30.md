## SessionTypeNameLookup_0042ce30 — SessionTypeNameToString

**Summary:** Maps session type ID (0-7) to display string. Short names when a2=true, full names when a2=false. "Unknown" for out-of-range IDs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0), sub_4FE350 (004fe350), WeatherConditionsFileWriter (004fe820)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0042cea0 | jpt_42CE39 | R | Jump table for the long-name switch (a2=false) |
| 0042cec0 | jpt_42CE63 | R | Jump table for the short-name switch (a2=true) |
| 005c307c | aUnknown | R | sUnknown [DERIVED] |
| 005c34c8 | aRace_0 | R | RaceField [DERIVED] |
| 005c34d0 | aWarmup | R | UISession_Warmup [DERIVED] |
| 005c34d8 | aQualify | R | String_Qualify [DERIVED] |
| 005c34e0 | aPractice4_0 | R | Practice4String [DERIVED] |
| 005c34ec | aPractice3_0 | R | Practice3String [DERIVED] |
| 005c34f8 | aPractice2_0 | R | Practice2String [DERIVED] |
| 005c3504 | aPractice1_0 | R | String_Practice1 [DERIVED] |
| 005c3510 | aTestday | R | s_TestDay [DERIVED] |
| 005c3518 | aPractice4 | R | Practice4 [DERIVED] |
| 005c3524 | aPractice3 | R | SessionTypePractice3String [DERIVED] |
| 005c3530 | aPractice2 | R | PracticeString [DERIVED] |
| 005c353c | aPractice1 | R | Practice1String [DERIVED] |
| 005c3548 | aTestDay | R | TestDayString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — pure lookup. Branch on a2 selects long name (false) vs short name (true). All values pass through; default returns "Unknown".
