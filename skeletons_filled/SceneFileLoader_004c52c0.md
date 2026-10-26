## SceneFileLoader_004c52c0 — BuildSceneFileArrayFromDirectory

**Summary:** Scans a directory for scene (.SCN) files for the current track/season combination, allocates an array of 396-byte scene entries, and loads each .SCN file via TrackFilePathBuilder. Sorts the resulting scene array by season/race using SeasonRacesSceneSorter and returns the total scene count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFileLoader (0042d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005d3044 | aDDevF119992002_8 | R | StringDevF119992002_8 [DERIVED] |
| 005d30dc | a3ThereAreNoSce | R | Str_3ThereAreNoSce [DERIVED] |
| 005d30fc | a2WeDoNotHaveRe | R | String2WeDoNotHaveRe [DERIVED] |
| 005d3138 | a1IncorrectSeas | R | IncorrectSeasonString [DERIVED] |
| 005d317c | aCouldNotFindAn | R | CouldNotFindAnString [DERIVED] |
| 005d31b0 | aScn | R | ScnString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec420 | dword_5EC420 | R | TrackDir [DERIVED] |
| 008ac398 | byte_8AC398 | W | TrackNameBuffer [DERIVED] |
| 008ac3e8 | byte_8AC3E8 | W | SCNFilePathBuffer [DERIVED] |
| 008ac438 | byte_8AC438 | W | AIWFilePathBuffer [CONFIRMED] |
| 008ac488 | dword_8AC488 | RW | SceneFileCount [DERIVED] |
| 008ac48c | dword_8AC48C | W | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | RW | SceneArray (stride 0x18c) [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad3b0 | dword_8AD3B0 | R | FileSearchData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c51a0 | TrackFilePathBuilder | Loads and parses a single .SCN file at the given path, writing scene entry into the scene array |
| 004c5940 | SeasonRacesSceneSorter | Sorts/normalizes scene array entries by season and race index |
| 004d7a50 | StringSplitLoop | Debug log filter: checks bitmask to gate debug message emission |
| 004d7aa0 | DebugLogWrite | Writes formatted debug warning when no SCN files found or season/track mismatch |
| 00565eb0 | sub_565EB0 | Closes/cleans up the directory file search iterator |
| 00565f20 | LinkedListNodePeek | Checks if the directory entry linked list has another node (non-destructive peek) |
| 00565f50 | LinkedListPopFront_5f50 | Removes and returns the first node from the file search linked list |
| 00565f70 | ShortComputation_5f70 | Counts the number of file entries found by the directory search |
| 00565f80 | sub_565F80 | Initiates a file search for files matching a pattern (.SCN) in a given directory |
| 005662d0 | DirectoryEntryIterator | Returns the next directory entry name from the file search results |
| 00587bcf | FreeWrapper_7bcf | Frees a previously allocated heap memory block |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates heap memory for the scene entry array (396 * count bytes) |
| 00587d02 | FileCloseWithLock | Closes a file handle with lock release |
| 00587db0 | sub_587DB0 | Opens a file in read mode ("r") |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with buffer overflow protection; builds full path from season+track directories |

**Guard conditions:** Directory fallback: if TrackDir (dword_5EC420) is null, falls back to byte_5EA438 (default empty directory). Same for SeasonDir (dword_5EC3D8) if null. Existing array: if SceneArray (dword_8AC490) is already allocated from a previous load, it is freed before reallocation. Empty results: if the directory search yields zero entries (v3 == 0), four debug log messages are conditionally emitted (gated by StringSplitLoop filters at IDs 1282-1285) warning about missing .SCN files or incorrect season/track. Loop exit: the directory iteration loop exits when LinkedListNodePeek returns 0 (no more entries in the search results linked list).</content>
