## AISettingsFileLoader_004333e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Restart (0042c3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005c403c | aSvm | R | FileExtSvm [DERIVED] |
| 005c4070 | aAiSvm | R | AiSvmExtension [DERIVED] |
| 005c4078 | aRace_1 | R | RaceString [DERIVED] |
| 005c4080 | aQual | R | QualString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007d03e0 | byte_7D03E0 | R | AISettingsMode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | [LLM] |
| 004326a0 | SettingsFolderResolver | [LLM] |
| 00432e50 | IterationCountMap | [LLM] |
| 004336d0 | SafeStringCopy | [LLM] |
| 00433890 | AISettingsFileResolver | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
