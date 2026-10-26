## SettingsCopySetupFileCopy_00432220 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerNameSetup (004326e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005c3fa8 | off_5C3FA8 | R | VTable_Base [DERIVED] |
| 005c403c | aSvm | R | FileExtSvm [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007d03f8 | byte_7D03F8 | R | SessionConfigGate [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00432650 | StringCapitalizer | [LLM] |
| 004326a0 | SettingsFolderResolver | [LLM] |
| 00433b60 | AddVehicleConfigEntryToLinkedList | [LLM] |
| 0049adb0 | ShortComputation_adb0 | [LLM] |
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566810 | sub_566810 | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568620 | sub_568620 | [LLM] |
| 00568b00 | sub_568B00 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 00589671 | CreateDirectoryAWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
