## ChampionshipScoreThresholdSearch_004a5700 — ScoreThresholdSearch

**Summary:** Searches an array of up to 3 championship score thresholds (stride-2, starting at offset 0x164). Returns the first threshold whose value falls between the player's current championship score (at *this + 0x403C) and total race laps (dword_8ACF8C). Returns -1 if no threshold matches.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_c8a0 (0049c8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x403C | R | — | player's current championship score for threshold comparison |
| this | 0x0 | R | — | pointer to player/championship data struct (base for obj offset) |
| this | 0x160 | R | — | count of entries in the threshold array (max 3) |
| this | 0x164 | R | — | first threshold value in stride-2 array (even indices: thresholds, odd indices: unused return values) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop guard on this[0x160] (count): iterates while loop counter < count. Early exit cap at 3 iterations maximum. Guard on each threshold: passes if `threshold > playerScore` AND `threshold < totalRaceLaps`. If both true, return threshold. If not, continue search or return -1.
