## VehicleFileLoader_004c3d80 — [LLM: short descriptive name]

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
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005d3044 | aDDevF119992002_8 | R | StringDevF119992002_8 [DERIVED] |
| 005d307c | aFailedReadingD | R | FailedReadingField [DERIVED] |
| 005d3098 | aVeh | R | VehExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 008ac390 | dword_8AC390 | RW | VehicleFileCount [DERIVED] |
| 008ac394 | dword_8AC394 | RW | VehicleArray (stride 0x424) [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad3b0 | dword_8AD3B0 | R | FileSearchData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3050 | sub_4C3050 | [LLM] |
| 004c3130 | MultiFieldCleanup | [LLM] |
| 004c3200 | VehFileParser | [LLM] |
| 004c4240 | VehicleDataLoader | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00565eb0 | sub_565EB0 | [LLM] |
| 00565f20 | LinkedListNodePeek | [LLM] |
| 00565f50 | LinkedListPopFront_5f50 | [LLM] |
| 00565f70 | ShortComputation_5f70 | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 005662d0 | DirectoryEntryIterator | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
