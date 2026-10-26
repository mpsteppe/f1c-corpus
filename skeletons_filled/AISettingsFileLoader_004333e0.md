## AISettingsFileLoader_004333e0 — AISettingsFileLoader

**Summary:** Loads AI settings (SVM) files per vehicle. Iterates all vehicles, builds paths from vehicle directory + settings folder + qual/race + .svm, tries multiple file variants, and stores found path into vehicle struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Restart (0042c3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | backslash character for path building |
| 005c329c | dword_5C329C | R | VehicleCount — number of vehicles to iterate |
| 005c36f0 | aR | R | file-open mode string "r" |
| 005c403c | aSvm | R | ".svm" file extension |
| 005c4070 | aAiSvm | R | "\\ai.svm" fallback path segment |
| 005c4078 | aRace_1 | R | "\\race" path segment for race sessions |
| 005c4080 | aQual | R | "\\qual" path segment for qualifying sessions |
| 005ea438 | byte_5EA438 | R | default application directory path |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — array of vehicle struct pointers |
| 007c56a4 | dword_7C56A4 | R | SessionType — used to pick qual vs race path |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath — settings folder path |
| 007d03e0 | byte_7D03E0 | R | AISettingsMode — 0=use default, non-0=load per-vehicle files |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | safely dereference pointer (return 0 if null) |
| 004326a0 | SettingsFolderResolver | resolve settings folder from settings file path |
| 00432e50 | IterationCountMap | check session type enumeration value |
| 004336d0 | SafeStringCopy | safe bounded string copy |
| 00433890 | AISettingsFileResolver | resolve default AI settings file path into buffer |
| 005665b0 | sub_5665B0 | concatenate/append string to path buffer |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | free heap memory |
| 00587d02 | FileCloseWithLock | close file handle with lock |
| 00587db0 | sub_587DB0 | try to open file for reading (fopen "r"); returns handle or 0 |
| 00587dd0 | sub_587DD0 | copy string with length limit |

**Guard conditions:** Outer loop: iterates `dword_5C329C` (VehicleCount) times. Per vehicle: checks `*(v2+13000)` (vehicle AI active flag) — if zero, skips vehicle entirely. If `byte_7D03E0` (AISettingsMode) is zero, skips per-vehicle file search and uses default path. Within search: tries three file variants in order; if any `sub_587DB0` (fopen "r") returns non-null, accepts that file, copies path to vehicle struct, clears loaded flag at `v2+18579`, and continues to next vehicle.
