## CareerSeasonStateFileReader_004c0b70 — Career season state file reader

**Summary:** Parses career season state from an ini-style buffer, loading opponent standings, player standings, season status, race session, race-over flag, and current race index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerCareerStatsGameOptionsLoader (004c18b0), GameOptionsWriter (004c1e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB144 | RW | — | season status value (written from parsed "SeasonStatus" field) |
| this | 0xB150 | RW | — | race over flag byte (written from parsed "RaceOver" field) |

**Written-by note (persistence):**
- this 0xB144: overwritten each time "SeasonStatus" field is found; external poke overwrites season status
- this 0xB150: overwritten each time "RaceOver" field is found; external poke overwrites race-over flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2818 | aCurrentrace | R | "CurrentRace" field key for ini parsing |
| 005d2824 | aRaceover | R | "RaceOver" field key |
| 005d2830 | aRacesession | R | "RaceSession" field key |
| 005d283c | aSeasonstatus | R | "SeasonStatus" field key |
| 005d284c | aPlayer | R | "Player" field key |
| 005d2858 | aOpponent | R | "Opponent" field key |
| 008ac050 | unk_8AC050 | R | scene setup data structure |
| 008ac1e8 | unk_8AC1E8 | R | scene render/state struct for conditional dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c03f0 | CareerStandingsStateLoader | load per-driver standings from ini section |
| 005651b0 | sub_5651B0 | check scene setup dispatch return code |
| 00565760 | sub_565760 | write integer value from parsed ini field |
| 00566cc0 | ConditionalDispatchBasedOnFlag | iterate over ini file entries with flag check |
| 00587c20 | sub_587C20 | locate field within ini section by name |
| 00587ece | sub_587ECE | parse integer value from field string |

**Guard conditions:** Returns 0 if input buffer a2 is NULL/empty. Returns early (with value 1) if sub_5651B0 returns 1 or 4 (dispatch skip codes). Routes "Opponent" entries to CareerStandingsStateLoader at this + 436*index (per-opponent slot), "Player" to this + 44908 (player slot after all opponents), "SeasonStatus" to this+0xB144. Falls through to read RaceSession, RaceOver, and CurrentRace when no other key matches.
