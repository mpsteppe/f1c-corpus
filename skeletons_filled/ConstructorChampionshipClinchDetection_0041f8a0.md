## ConstructorChampionshipClinchDetection_0041f8a0 — ConstructorClinchVerifier

**Summary:** Verifies if a constructor team has mathematically clinched the championship by checking that the team leads all other 13 teams in cumulative points across every category prefix (0..v6 for v6 = 0 to FlagsGetter-2); returns 1 if clinched, 0 otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringClassificationDisplay (0041e320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041faa0 | jpt_41F8E5 | R | Jump table for team index lookup switch (14 team names) |
| 0041fad8 | jpt_41F9AC | R | Jump table for score compute switch (14 team names) |
| 005c25b4 | aToyota | R | Str_Team_Toyota [DERIVED] |
| 005c25bc | aStewart | R | String_Stewart [DERIVED] |
| 005c25c4 | aRenault | R | sTeamName_Renault [DERIVED] |
| 005c25cc | aBenetton | R | TeamName_Benetton [DERIVED] |
| 005c25d8 | aJaguar | R | StrJaguar [DERIVED] |
| 005c25e0 | off_5C25E0 | R | Unknown_Setup_25E0 [DERIVED] |
| 005c25e4 | aMinardi | R | TeamNameMinardi [DERIVED] |
| 005c25ec | aProst | R | aProst [DERIVED] |
| 005c25f4 | aArrows | R | TrackArrows [DERIVED] |
| 005c25fc | aSauber | R | TeamName_Sauber [DERIVED] |
| 005c2604 | aJordan | R | TrackNameJordan [DERIVED] |
| 005c260c | aWilliams | R | Str_Team_Williams [DERIVED] |
| 005c2618 | aFerrari | R | sTeamFerrari [DERIVED] |
| 005c2620 | aMclaren | R | TeamName_McLaren [DERIVED] |
| 005ea438 | byte_5EA438 | R/W | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f220 | ChampionshipPointsAccumulator | Get cumulative points for a team up to a category cutoff |
| 004c11d0 | FlagsGetter | Get number of scoring categories from standings node |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00566650 | StringCopyWithBufferRealloc | Copy team name string into intermediate buffer |
| 00566810 | sub_566810 | Compare team name against input name to find team index |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- Team name (`this`) must match one of the 14 known constructor names → PASSES: found. BLOCKED: return 0 (not found).
- `FlagsGetter` must return >= 3 (v12 = v4 - 2 > 0) → PASSES: at least 2 category ranges to check. BLOCKED: return 0.
- For each category prefix 0..v6, the input team's cumulative points must be >= all other 13 teams → PASSES: clinched (return 1). BLOCKED: any other team leads at any prefix → return 0.
