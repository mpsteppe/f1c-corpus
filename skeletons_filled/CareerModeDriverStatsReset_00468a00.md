## CareerModeDriverStatsReset_00468a00 — CareerModeDriverStatsReset

**Summary:** Resets career mode driver stats display by destroying the existing stat list, calling a vtable method, rebuilding the stat list with 13 stat keys (adding Circuit, BestLap, and an extra ExperienceLaps to the base 10), then calling state cleanup and sub_468BF0. Belongs to career mode results/stats system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | linked list node data pointer (string) |
| *(this+0x48) | 0x4 | R | — | linked list node next pointer |
| obj | 0x3C | R | — | vtable offset 60: method called with arg 0 for reset |
| this | 0x0 | R | — | vtable pointer |
| this | 0x44 | RW | 0 | linked list head pointer (this[17]); cleared after destruction |
| this | 0x48 | RW | 0 | linked list tail pointer (this[18]); cleared after destruction |
| this | 0x4C | RW | 0 | linked list node count (this[19]); cleared after destruction |
| this | 0x50 | RW | 0 | linked list capacity (this[20]); cleared after destruction |

**Written-by note (persistence):**
- this 0x44: set to 0 after list destruction; then rebuilt with stat insertions.
- this 0x48: set to 0 after list destruction; then rebuilt.
- this 0x4C: set to 0 after list destruction; then rebuilt.
- this 0x50: set to 0 after list destruction; then rebuilt.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6860 | aWorldChampions | R | StrWorldChampions [DERIVED] |
| 005c6878 | aWins | R | StrWins [DERIVED] |
| 005c6880 | aPoints | R | StatKey_Points [DERIVED] |
| 005c6888 | aPolePositions | R | Key_PolePositions [DERIVED] |
| 005c6898 | aAvgOpponentStr | R | aAvgOpponentStr [DERIVED] |
| 005c68b4 | aAvgRaceLength | R | DriverStatKeyAvgRaceLength [DERIVED] |
| 005c68c8 | aAvgFinishPosit | R | StrAvgFinishPosit [DERIVED] |
| 005c68e0 | aAvgStartingPos | R | aAvgStartingPos [DERIVED] |
| 005c68f8 | aStarts | R | Str_Starts [DERIVED] |
| 005c6900 | aExperienceLaps | R | String_ExperienceLaps [DERIVED] |
| 005c6914 | aBestLap | R | sBestLap [DERIVED] |
| 005c6920 | aCircuit | R | StatKey_Circuit [DERIVED] |
| 007cff30 | byte_7CFF30 | W | ExperienceLapsResetFlag [DERIVED] |
| 007cff32 | byte_7CFF32 | R | UI_TriggerFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00468910 | HTMLResultsStatsPageWorldChampionships | builds base 10-stat list (experience laps through world championships) |
| 00468bf0 | sub_468BF0 | additional processing after stat list rebuild |
| 00486f30 | LinkedListInsertWithNodeAllocation | inserts a stat key string into the linked list |
| 00489cb0 | StateCleanupNotification | performs state cleanup notification |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated node data and node structures |

**Guard conditions:** For each linked list node during destruction, checks byte at node+8 (free flag). If non-zero (PASSES), frees inner data and node struct. If zero (BLOCKED), frees only node struct. Also checks byte_7CFF32 (UI_TriggerFlag) to propagate value to byte_7CFF30. No early return — always rebuilds full stat list.
