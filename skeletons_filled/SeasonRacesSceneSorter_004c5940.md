## SeasonRacesSceneSorter_004c5940 — Sort scene array by season races order

**Summary:** Reads the current "season races" linked list, maps each scene entry to its position in that list, then selection-sorts the scene array entries by that mapping order. Frees the temporary index array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileLoader (004c52c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d31c8 | aSeasonraces | R | ParamKey_SeasonRaces [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | Extract string pointer from linked list node |
| 00567980 | LinkedListCount | Count elements in linked list returned by AudioChannelStop |
| 005679a0 | NullCheckWrapper | Safe-access linked list node by index (returns node or null) |
| 00568210 | AudioChannelStop | Retrieve season races list by name key from audio channel system |
| 00587bcf | FreeWrapper_7bcf | Free temporary index allocation array |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate index array of size dword_8AC488 |
| 00588410 | sub_588410 | Compare scene name against season races list entry name; 0 on match |

**Guard conditions:** If `AudioChannelStop(dword_8AD3B4, "seasonraces")` returns null, entire function is skipped (returns null). Otherwise, if `dword_8AC488` (scene count) <= 0, skip mapping phase. Selection sort runs only if `dword_8AC488` > 0.
