## PlayerNameSetup_004326e0 — PlayerNameConfigSetup

**Summary:** Sets up player name configuration by reading settings files, resolving folder paths, searching string tables for player name, and enumerating matching files in the settings directory. Orchestrates multiple settings-file and path-resolution steps.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0x20)+0x4)+0x0) | 0x0 | R | — | Player name string from linked list entry |
| *(*(obj+0x20)+0x4) | 0x0 | R | — | Linked list node pointer |
| *(*(obj+0x20)+0x4) | 0x4 | R | — | Linked list next pointer |
| obj | 0x20 | R | — | Pointer to settings/linked-list structure |
| obj | 0x2C | R | — | Entry index or count field |
| this | 0x0 | R | — | Top-level string pointer passed to file readers |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Searches a sorted string table for matching player name |
| 00432180 | SettingsSetupFileRead | Reads settings setup file and enumerates directory |
| 00432220 | SettingsCopySetupFileCopy | Copies settings files to target locations |
| 004326a0 | SettingsFolderResolver | Resolves settings section to vehicle data entry |
| 004326d0 | Wrapper | Intermediate wrapper for settings processing |
| 00432980 | PathNormalizerFileEnumeration | Enumerates files matching a normalized path pattern |
| 00566650 | StringCopyWithBufferRealloc | Copies string with automatic buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | Low-level memory deallocation wrapper |
| 00588410 | sub_588410 | String comparison utility |

**Guard conditions:** If dword_7CE5EC (SettingsFilePath) is null, uses default application directory instead. BinarySearchInStringTable return determines whether player name is copied to display buffer. Linked list walk: index is checked against entry count bound; null next pointer terminates walk; null entry pointer terminates walk; null string pointer defaults to application directory. sub_588410 (string comparison) determines whether current entry triggers PathNormalizerFileEnumeration — only entries that do NOT match the target string trigger enumeration.
