## DriverCareerStatsHTMLWriter_0047dd10 — PopulateDriverCareerStatsScreen

**Summary:** Populates the driver career statistics UI screen by fetching career data from the game command interface, clearing old list entries, building linked-list menu items for Driver, Nationality, Date of Birth, Starts, Pole Positions, Wins, and Drivers Championship, and rendering each with values from the career database.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | Data payload pointer within linked list node (string data) |
| *(this+0x48) | 0x4 | R | — | Next pointer within linked list node (node chain traversal) |
| this | 0x44 | RW | 0 | Linked list head pointer — cleared before rebuilding UI item list |
| this | 0x48 | RW | 0 | Linked list secondary pointer — cleared at start |
| this | 0x4C | RW | 0 | Counter / tertiary pointer — cleared at start |
| this | 0x50 | RW | 0 | Counter / quaternary pointer — cleared at start |

**Written-by note (persistence):**
- this 0x44: set to 0 at start then rebuilt with new list — external poke overwritten each population cycle
- this 0x48: set to 0 at start — external poke overwritten each cycle
- this 0x4C: set to 0 at start — external poke overwritten each cycle
- this 0x50: set to 0 at start — external poke overwritten each cycle

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
| 005c73dc | aDateOfBirth | R | Localized "Date of Birth" string key — searched in career data via StringKeyedLinkedListSearch |
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
| 00423a00 | BinarySearchInStringTable | Searches for string in binary-sorted table (localization lookup) |
| 00486f30 | LinkedListInsertWithNodeAllocation | Inserts a node into linked list, allocating memory if needed |
| 00487010 | UIListIndexedAccessor | Accesses UI list element by sequential index for menu item creation |
| 004894d0 | StrlenOverwrite | Copies string with length-based overwrite into destination |
| 00489600 | UIMenuItemCreator | Creates a UI menu item with string, position, and style parameters |
| 00489cb0 | StateCleanupNotification | Sends cleanup notification for UI state transition |
| 0048f590 | LinkedListIndexedAccessor_f590 | Accesses linked list element by index to retrieve career stats data |
| 00567970 | DataEntryAccessor | Accesses data value entry within career/stats data struct |
| 005679c0 | StringKeyedLinkedListSearch | Searches linked list by string key to find matching data entry |
| 00568210 | AudioChannelStop | Stops audio channel (background music/sfx before displaying UI) |
| 00587bcf | FreeWrapper_7bcf | Frees allocated memory (wrapper around free) |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe sprintf with buffer overflow protection |

**Guard conditions:** Game command dispatch (dword_7CD8C0 vtable+28 with arg 17) returns null → return (BLOCKED: no career data available). LinkedListIndexedAccessor_f590 returns null → return (BLOCKED: no stats data structure). Career data at result+60 (v31) is null → return (BLOCKED: empty career record). AudioChannelStop on career data audio channel returns null → early return before populating items (BLOCKED: audio system error or no active session).
