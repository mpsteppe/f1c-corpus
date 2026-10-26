## GameFileLoader_0042d260 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0ec | GetModuleFileNameA | R | [LLM] |
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c35d0 | aNoVehicleFiles | R | NoVehicleFilesString [DERIVED] |
| 005c35e8 | aNoSceneFilesFo | R | NoSceneFilesFoundString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 008aae70 | dword_8AAE70 | R | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423890 | sub_423890 | [LLM] |
| 004b3bd0 | RandomNoiseTableInitialization | [LLM] |
| 004c3d80 | VehicleFileLoader | [LLM] |
| 004c52c0 | SceneFileLoader | [LLM] |
| 004d7660 | TireBrandLoader | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00568a60 | UtilityFunction_8a60 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
