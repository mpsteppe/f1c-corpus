## sub_42FAB0_0042fab0 — LoadGameAssets

**Summary:** Loads all game asset files (vehicles, tires, tracks/scenes, audio) during initialization. Returns 0 on success, 1 if required files are missing or game is already initialized.

**Called by:** sub_42FCC0 (0042fcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d514c | GetModuleFileNameA | R | Windows API — get executable path to locate game data directory |
| 005fb7e8 | Format | R | "%s%s" format string for sprintf path concatenation |
| 005fd62c | aDDevNascar2004_2 | R | Source file path string for debug/error message context |
| 005fd66c | aNoVehicleFiles | R | "No vehicle files found" error message text |
| 005fd684 | aNoSceneFilesFo | R | "No scene files found" error message text |
| 005fd69c | aPit | R | "*.pit" search pattern for track pit data files |
| 005fd6a4 | aRcd | R | "*.rcd" search pattern for race/track definition files |
| 00629120 | byte_629120 | R | Default empty string fallback when path pointer is null |
| 0062a068 | dword_62A068 | R | Pointer to base data directory path string |
| 0062a098 | dword_62A098 | R | Pointer to alternative/sub path string |
| 0062a130 | dword_62A130 | R | Pointer to path suffix string (appended to base path) |
| 0062a170 | dword_62A170 | R | Game data/config pointer passed to initialization |
| 007661cc | unk_7661CC | R | Initialization flag — non-zero means game already loaded |
| 007d3c50 | dword_7D3C50 | R | Scene/track data structure pointer |
| 007d6a30 | byte_7D6A30 | R | Track data collection — used to get track count |
| 007d6a50 | unk_7D6A50 | R | Vehicle data container — used to get vehicle count |
| 007d6a58 | dword_7D6A58 | R | Vehicle file count — checked for > 0 to verify vehicles loaded |
| 007d6b50 | dword_7D6B50 | R | Track/scene file count — checked for > 0 to verify scenes loaded |
| 007d7918 | dword_7D7918 | R | Tire brand data structure — loaded by TireBrandLoader |
| 007d7920 | unk_7D7920 | R | Error reporting context — passed to error display functions |
| 007d7a0c | dword_7D7A0C | R | Directory entry iterator state — used to enumerate .rcd and .pit files |
| 007d7a10 | byte_7D7A10 | R | Directory data — associated with dword_7D7A0C iterator |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f0c0 | sub_41F0C0 | Initialize/configure game data with path and config |
| 004bb930 | sub_4BB930 | Check if game is already initialized (non-zero = yes) |
| 004d19f0 | sub_4D19F0 | Initialize scene/track data structures |
| 004e73e0 | sub_4E73E0 | Populate/get vehicle data count |
| 004e8880 | sub_4E8880 | Populate/get track/scene data count |
| 00500b40 | TireBrandLoader [structural] | Load tire brand definitions from data files |
| 00500f90 | sub_500F90 | Show error/assert dialog with source file path and line number |
| 00500fe0 | sub_500FE0 | Display formatted error message with custom text |
| 005789d0 | LinkedListNodePeek [exact] | Remove processed entry from directory enumeration linked list |
| 00578a30 | sub_578A30 | Begin directory search with pattern, flag, and base path |
| 00578d80 | DirectoryEntryIterator [structural] | Get next matching file from directory enumeration |
| 0057ac50 | AudioFileLoadDecode [structural] | Load and decode a data file (audio/resource format) |
| 0057b490 | UtilityFunction_8a60 [structural] | Extract directory path from full file path (strip filename) |
| 005beec8 | _sprintf | Build path string by concatenating base path and suffix |

**Guard conditions:** 
- sub_4BB930(&unk_7661CC) returns non-zero → BLOCKED, return 1 (game already initialized)
- dword_7D6B50 <= 0 → BLOCKED, show "No scene files found" error, return 1
- dword_7D6A58 <= 0 → BLOCKED, show "No vehicle files found" error, return 1
- All counts > 0 → PASSES, return 0 (success)

**String literals referenced (deterministic):**

- `%s%s`
- `D:\dev\NASCAR_2004\Source\game.cpp`
- `D:\dev\NASCAR_2004\Source\game.cpp`
- `No vehicle files found`
- `No scene files found`
- `*.pit`
- `*.rcd`
