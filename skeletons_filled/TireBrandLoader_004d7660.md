## TireBrandLoader_004d7660 — TireBrandLoader

**Summary:** Loads tire brand configuration (.tbc) files from season directory. Searches for .tbc files using sub_565F80, allocates entry array (36 bytes each), parses each file via TireBrandFileParser, logs warning if no brands found. Called by GameFileLoader.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFileLoader (0042d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | count of tire brand entries found |
| this | 0x4 | RW | — | pointer to allocated array of parsed .tbc entries (36 bytes each) |

**Written-by note (persistence):**
- this 0x0: written once (file count from directory scan); survives external poke
- this 0x4: written once (heap pointer to entry array); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] — format string "%s%s" for path construction |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] — format string "%s%s%s" for path with filename |
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] — hardcoded path string |
| 005d49a4 | aNoTireBrandsTb | R | warning message "No tire brands .tbc" |
| 005d49dc | aTbc | R | file extension ".tbc" |
| 005ea438 | byte_5EA438 | R | default application directory (fallback path) |
| 005ec3d8 | dword_5EC3D8 | R | season directory path |
| 005ec428 | dword_5EC428 | R | season name string |
| 008ad25c | dword_8AD25C | R | debug message buffer for log output |
| 008ad3b0 | dword_8AD3B0 | R | file search context data structure |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7020 | StructInitWithSentinels | initializes each 36-byte entry struct to sentinel state |
| 004d7150 | TireBrandFileParser | parses a single .tbc file into entry struct |
| 004d7800 | TextureSurfaceDestroyer | cleanup/reinit of this struct before loading |
| 004d7a50 | StringSplitLoop | string splitting/util check (used in guard condition) |
| 004d7aa0 | DebugLogWrite | writes debug/log message |
| 00565eb0 | sub_565EB0 | cleanup/teardown of file search context |
| 00565f20 | LinkedListNodePeek | checks if more nodes exist in linked list |
| 00565f50 | LinkedListPopFront_5f50 | pops head node from linked list |
| 00565f70 | ShortComputation_5f70 | retrieves count from file search data structure |
| 00565f80 | sub_565F80 | registers file search pattern (.tbc) in directory |
| 005662d0 | DirectoryEntryIterator | iterates directory entries for .tbc files |
| 00567740 | FPUControlWordMaskExtract | saves FPU control word (preserved across call) |
| 00567780 | EmptyStub_7780 | empty stub (likely FPU restore if mask changed) |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation for entry array |
| 0058815f | StringFormatWithBufferOverflowCheck | safe snprintf-style path formatting |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | count of loaded tire brands |

**Guard interpretation:** PASSES (warning logged) when this+0x0 (entry count) is 0 OR allocation pointer at this+0x4 is null, AND StringSplitLoop returns true. BLOCKED (normal flow) when entries were loaded successfully.
