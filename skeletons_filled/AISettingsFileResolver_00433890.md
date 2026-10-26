## AISettingsFileResolver_00433890 — AISettingsFilePathResolver

**Summary:** Resolves the full AI settings file path by combining base directory with settings entry from linked-list lookup tables, based on session type. AI settings/session configuration system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AISettingsFileLoader (004333e0), LoadAIDriverNamesFromConfig (004336f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | output string buffer, cleared before resolve |

**Written-by note (persistence):**
- this 0x0: written as null terminator at start and final result via sub_587DD0 — buffer written by callee, not persistent

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3fa8 | off_5C3FA8 | R | VTable_Base [DERIVED] |
| 005c3fac | off_5C3FAC | R | UnknownDataPtr_5C3FAC [DERIVED] |
| 005c3fb0 | off_5C3FB0 | R | Off_5C3FB0_Sound [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432e50 | IterationCountMap | get iteration count from session type value |
| 004c5840 | SeasonRacesSectionFinder | validate season/races section in settings file |
| 00567970 | DataEntryAccessor | access data entry string from linked list node |
| 005679c0 | StringKeyedLinkedListSearch | search linked list by string key in lookup table |
| 00587dd0 | sub_587DD0 | copy resolved file path string into output buffer with size limit |

**Guard conditions:** returns 1 (error) if SeasonRacesSectionFinder fails or no matching entry found (v3 remains null). Only checks off_5C3FAC entry when IterationCountMap(session_type) == 5. Falls back to byte_5EA438 when SettingsFilePath or SettingsDirectory pointers are null.
