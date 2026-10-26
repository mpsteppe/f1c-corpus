## DriverCareerStatsHTMLWriter_0047dd10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005c6878 | aWins | R | StrWins [DERIVED] |
| 005c6888 | aPolePositions | R | Key_PolePositions [DERIVED] |
| 005c68f8 | aStarts | R | Str_Starts [DERIVED] |
| 005c737c | aDriverschampio | R | String_DriversChampionship [DERIVED] |
| 005c7394 | aWins_0 | R | WinsString [DERIVED] |
| 005c739c | aPoles | R | PolesString [DERIVED] |
| 005c73a4 | aStarts_0 | R | StartsString [DERIVED] |
| 005c73ac | aDateofbirth | R | String_DateOfBirth [DERIVED] |
| 005c73b8 | aNationality | R | aNationality [DERIVED] |
| 005c73c4 | aDriversChampio | R | s_DriversChampion [DERIVED] |
| 005c73dc | aDateOfBirth | R | [LLM] |
| 005c73ec | aNationality_0 | R | NationalityField [DERIVED] |
| 005c73fc | aDriver_2 | R | DriverString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00487010 | UIListIndexedAccessor | [LLM] |
| 004894d0 | StrlenOverwrite | [LLM] |
| 00489600 | UIMenuItemCreator | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 0048f590 | LinkedListIndexedAccessor_f590 | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
