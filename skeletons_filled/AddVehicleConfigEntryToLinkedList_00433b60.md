## AddVehicleConfigEntryToLinkedList_00433b60 — AddVehicleConfigEntryToLinkedList

**Summary:** Searches linked list for existing matching vehicle config entry by settings folder and filter. If found and flag allows, copies strings. If not found, allocates new 28-byte entry and appends to linked list. Always writes config file via ConfigFileParser.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsCopySetupFileCopy (00432220), ClearBufferAndInit (0046f490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | pHead: linked list head pointer (written only on first insert) |
| this | 0x20 | RW | — | pTail: linked list tail pointer (written every append) |
| this | 0x24 | RW | — | pFirst: first/iterator pointer (written on first insert and during traversal) |
| this | 0x28 | R | — | nCount: entry count (incremented every append) |

**Written-by note (persistence):**
- this 0x1C: written once on first node insertion only. Survives.
- this 0x20: written every insertion (set to new node). Last write is final node. Survives.
- this 0x24: written on first insert as iterator; also overwritten during linked list search traversal. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path |
| 007c56a4 | dword_7C56A4 | R | SessionType — for IterationCountMap |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile — config file to write |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath — for SettingsFolderResolver |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath — for ConditionalDispatch_40b0 |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004326a0 | SettingsFolderResolver | resolve settings folder path |
| 00432cc0 | SessionConfigDefaultInit | zero-initialize 28-byte entry struct |
| 00432e50 | IterationCountMap | convert session type to iteration count |
| 004330d0 | ConfigFileParser | write linked list to config file |
| 004c40b0 | ConditionalDispatch_40b0 | resolve game filter data from path |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for entry and node |
| 00588410 | sub_588410 | compare two path strings |

**Guard conditions:** If `a3` (settings folder) is 0, resolves from SettingsFilePath. Parameter `a4` flags: when search finds matching entry and `a4` is 0, returns 1 early without further processing. List search: iterates from head (`this[7]`); if head is null or first data pointer is null, skips to allocation path. Per node: path match vs settings folder and (if non-empty) secondary string match vs game filter data. Match on either condition breaks loop.
