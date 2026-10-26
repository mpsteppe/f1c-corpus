## NetworkScorePingDisplay_0045d130 — Format player score and ping display

**Summary:** Iterates over player count from StructFieldReadAt0x3e14, formats per-player key-value pairs (player_%d, score_%d, ping_%d) into output buffer via ShortComputation_ce30. Reads score and ping data via DataTableRowAccessor for each player row.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c5c4c | aPingD | R | s_FormatPingD [DERIVED] |
| 005c5c54 | aScoreD | R | ScoreD [DERIVED] |
| 005c5c60 | aPlayerD | R | PlayerDFormatString [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ce30 | ShortComputation_ce30 | Sets key-value pairs (player_#, score_#, ping_#) in output buffer |
| 00461470 | ThunkToFUN00461480 | Initialization/thunk for player data table access |
| 00462370 | StructFieldReadAt0x3e14 | Reads player count from game module manager |
| 00462410 | DataTableRowAccessor | Reads score/ping data for a specific player row |
| 004b0170 | EmptyStub_0170 | Cleanup/stub after each player row |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting for player/score/ping keys and values |

**Guard conditions:** BLOCKED if player count from StructFieldReadAt0x3e14 <= 0 → skip all iteration. Per-row guard: if DataTableRowAccessor fails for a player, that player's entries are skipped.
