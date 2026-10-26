## SceneFileLoader_004c52c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 004c51a0 | TrackFilePathBuilder | [LLM] |
| 004c5940 | SeasonRacesSceneSorter | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00565eb0 | sub_565EB0 | [LLM] |
| 00565f20 | LinkedListNodePeek | [LLM] |
| 00565f50 | LinkedListPopFront_5f50 | [LLM] |
| 00565f70 | ShortComputation_5f70 | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 005662d0 | DirectoryEntryIterator | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
