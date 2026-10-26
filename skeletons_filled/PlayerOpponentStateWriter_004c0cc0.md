## PlayerOpponentStateWriter_004c0cc0 — Player/opponent state ini writer

**Summary:** Writes career season state for player and active opponents to an ini-format text buffer. Outputs season status, race session, race-over flag, current race, and per-driver standings via SettingsIniFileWriter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CareerStatsWriter (004c2420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B0 | R | — | active flag byte — if set, opponent section is written to ini |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | config/config separator token (written at end) |
| 005d284c | aPlayer | R | "Player" section key |
| 005d2858 | aOpponent | R | "Opponent" section key |
| 005d2864 | aS22d_0 | R | "%s%2.2d]" format for indexed opponent section names |
| 005d2870 | aCurrentraceD | R | "CurrentRace" field key |
| 005d2880 | aRaceoverD | R | "RaceOver" field key |
| 005d2890 | aRacesessionD | R | "RaceSession" field key |
| 005d28a0 | aSeasonstatusD | R | "SeasonStatus" field key |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0690 | SettingsIniFileWriter | write per-driver standings fields to ini buffer |
| 00566c30 | BufferWriteWithStringLengthCheck | write key-value pair to output buffer |
| 00566cf0 | ResourceLookupWithDualPath | resolve resource path for output file |
| 0058815f | StringFormatWithBufferOverflowCheck | format indexed opponent section name |

**Guard conditions:** Returns early if output buffer a2 is NULL/empty. For each active opponent (active flag at this+0x1B0 non-zero), writes opponent section via SettingsIniFileWriter. Opponents with active flag == 0 are skipped.
