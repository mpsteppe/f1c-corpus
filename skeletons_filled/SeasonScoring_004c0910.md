## SeasonScoring_004c0910 — Season scoring computation

**Summary:** Computes season championship points for a vehicle based on race position and game state. Handles both idle scoring (GameState==5) and post-race scoring (GameState==7) with points lookup from scoring data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceStandingsRankingsComputation (004c0f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x198 | RW | — | accumulated season points total |
| this | 0x1A0 | R | — | leader lap counter (incremented when position == 1 in idle mode) |
| this | 0x1A4 | R | — | vehicle index into SeasonScoringDB |
| this | 0x1A8 | RW | — | computed race position result |

**Written-by note (persistence):**
- this 0x198: accumulated each scoring call (additive); external poke alters total points
- this 0x1A8: overwritten each scoring call with current position; external poke survives until next scoring update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e824 | flt_59E824 | R | AI dynamics threshold [DERIVED] |
| 005d2804 | aSeasonscoringi | R | "SeasonScoringInfo" section name for data lookup |
| 007d00ec | dword_7D00EC | R | GameState (5 = idle/scoring, 7 = post-race) |
| 007d2e48 | dword_7D2E48 | R | SeasonScoringDB base (stride 0x48c0) |
| 008acf8c | dword_8ACF8C | R | total race laps for 90% distance threshold |
| 008ad3b4 | dword_8AD3B4 | R | game data directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567970 | DataEntryAccessor | access data entry for point value lookup |
| 005679a0 | NullCheckWrapper | safe access to scoring list entry with null check |
| 00568210 | AudioChannelStop | check if season scoring audio channel exists |
| 00587bdc | CRTFtol | convert float to int (90% lap threshold) |
| 00587ece | sub_587ECE | parse integer value from scoring data entry |

**Guard conditions:** If GameState == 5: reads vehicle position from DB, sets result, increments leader counter only if position == 1. If GameState == 7: skips point scoring if AI state == 3 (retired), if lap count < 90% of total race laps, or if AudioChannelStop check fails. Points only awarded when all three conditions pass.
