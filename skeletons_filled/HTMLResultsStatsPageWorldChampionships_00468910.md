## HTMLResultsStatsPageWorldChampionships_00468910 — HTMLResultsStatsPageWorldChampionships

**Summary:** Destroys the existing linked list of stat entries, then repopulates it with 10 career driver stat strings (experience laps, starts, avg positions, wins, points, etc.). Belongs to career mode results/stats HTML page generation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CareerModeDriverStatsReset (00468a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | linked list node data pointer (string) |
| *(this+0x48) | 0x4 | R | — | linked list node next pointer |
| this | 0x44 | RW | 0 | linked list head pointer (this[17]); cleared after destruction |
| this | 0x48 | RW | 0 | linked list tail pointer (this[18]); cleared after destruction |
| this | 0x4C | RW | 0 | linked list node count (this[19]); cleared after destruction |
| this | 0x50 | RW | 0 | linked list capacity (this[20]); cleared after destruction |

**Written-by note (persistence):**
- this 0x44: set to 0 after freeing list; then updated by LinkedListInsertWithNodeAllocation.
- this 0x48: set to 0 after freeing list; then updated by LinkedListInsertWithNodeAllocation.
- this 0x4C: set to 0 after freeing list; then updated by LinkedListInsertWithNodeAllocation.
- this 0x50: set to 0 after freeing list; then updated by LinkedListInsertWithNodeAllocation.

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

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | inserts a stat key string into the linked list |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated node data and node structures |

**Guard conditions:** For each linked list node during destruction, checks byte at node+8 (free flag). If non-zero (PASSES), frees inner data pointer and node struct. If zero (BLOCKED), frees only the node struct. No early return — always frees entire list, then inserts all 10 stat strings.
