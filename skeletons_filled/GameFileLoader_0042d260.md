## GameFileLoader_0042d260 — GameFileLoader

**Summary:** Loads game assets (scene files, vehicle files, tire brands) and initializes random noise table. Returns 0 on success, 1 if scene or vehicle files are missing. Called during game enter sequence.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0ec | GetModuleFileNameA | R | Get application executable path |
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
| 00423890 | sub_423890 | Build path string from module directory and override |
| 004b3bd0 | RandomNoiseTableInitialization | Initialize random/weather noise lookup table |
| 004c3d80 | VehicleFileLoader | Load vehicle definition files from disk |
| 004c52c0 | SceneFileLoader | Load scene/graphics files from disk |
| 004d7660 | TireBrandLoader | Load tire brand definitions |
| 004d7a50 | StringSplitLoop | Parse/log build path string for debug output |
| 004d7aa0 | DebugLogWrite | Write missing-files error message to debug buffer |
| 00568a60 | UtilityFunction_8a60 | Set up application path from module filename |

**Guard conditions:** Scene files count (dword_8AC488) ≤ 0 → BLOCKED (logs error, returns 1, skips vehicle loading). Vehicle files count (dword_8AC390) ≤ 0 → BLOCKED (logs error, returns 1). Both checks must pass for success return 0.
