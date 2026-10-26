## ShortComputation_c8a0_0049c8a0 — championship score threshold formatter

**Summary:** Looks up a championship score threshold via ChampionshipScoreThresholdSearch; displays as integer if positive, otherwise displays a placeholder string (e.g. "---").

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49DE40 (0049de40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c694c | word_5C694C | R | FormatWord [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5700 | ChampionshipScoreThresholdSearch | search/calculate a championship score threshold value from player data |
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf-style formatting with buffer bounds check |

**Guard conditions:** `v2 > 0` — if score threshold is positive, format as integer; otherwise format placeholder string (word_5C694C, likely "---").
