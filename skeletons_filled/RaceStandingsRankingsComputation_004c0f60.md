## RaceStandingsRankingsComputation_004c0f60 — Post-race ranking computation

**Summary:** Computes driver rankings after race by scoring season points for player and opponents, then ranking active drivers by position. Sets race-over flag when complete.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalSeasonDataFree (004c2830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B0 | R | — | per-entry active flag (byte) — if set, scores this driver |
| this | 0xB104 | R | — | flags getter result used for scoring |
| this | 0xB108 | RW | — | player final ranking position (computed from position comparison) |
| this | 0xB11C | R | — | init/active flag byte |
| this | 0xB14C | R | — | race session value (compared to 7) |
| this | 0xB150 | RW | 1 | race over flag byte (set to 1 after computation) |

**Written-by note (persistence):**
- this 0xB108: computed each time from position comparisons; external poke changes player ranking
- this 0xB150: set to 1 after first computation, prevents re-computation; external poke resets guard

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0910 | SeasonScoring | compute season points for a driver entry |
| 004c11d0 | FlagsGetter | get scoring flags for the session |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xB14C | == | 7 | race session field — must == 7 (race session) to trigger ranking computation |

**Guard interpretation:** Entire function is blocked if race-over flag (this+0xB150) is already 1 (non-zero). SeasonScoring is called for player and each active opponent regardless of session type. The ranking loop (counting how many drivers have higher position than each driver) only executes when race session == 7. Active flag (this+0x1B0 byte) must be non-zero for each entry to participate in scoring and ranking.
