## VehgenScnFileLoader_004c6c40 — Vehicle generation scene file loader

**Summary:** Loads the "vehgen.scn" scene configuration, sets up vehicle graphics and physics scene, initialises driver name and nationality path from config, sets driver number, and cleans up allocated memory. Called during vehicle setup/initialisation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0), NetCommPlayerSlotSync (0045fc50), ProcessDriverEntries (004b8da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32C8 | R | — | vehicle type/index flag; checked for 0 to decide if driver name needs loading |
| this | 0x4677 | RW | 0 | null terminator for nationality/path string buffer at this+18039 |
| this | 0x4894 | R | — | team ID used for scene file path lookup |
| this | 0x48A4 | RW | 18446744073709551615 | initialised to -1; reset vehicle field |
| this | 0x48A8 | RW | 18446744073709551615 | initialised to -1; reset vehicle field |

**Written-by note (persistence):**
- this 0x4677: set to 0 as null terminator; persists
- this 0x48A4: set to -1 unconditionally during load; persists until overwritten
- this 0x48A8: set to -1 unconditionally during load; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3224 | aVehgenScn | R | VehgenScnString [DERIVED] (also: ` — "vehgen.scn" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 005ec438 | dword_5EC438 | R | WeatherDir [DERIVED] (also: ` — SeasonDir/LoadPath, docs/12) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce684 | dword_7CE684 | R | NationalityDataPath [DERIVED] (also: ` — nationality data pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410b20 | ShortComputation_0b20 | short computation on global instance data |
| 004a4900 | sub_4A4900 | initialise vehicle data from loaded scene |
| 004b0b20 | sub_4B0B20 | load config/ini string value by key |
| 004bb800 | ZeroTwoFields | zero-initialise two struct fields |
| 004c6980 | SetDriverName | set driver full name and derive abbreviation |
| 004c7b50 | VehicleSetupDriverNumber | set driver number from vehicle config |
| 004ddf90 | SceneFileTEAMDIRVEHDIRNOTSPINWriter | write scene file paths (team dir, vehicle dir) |
| 004dfce0 | VehicleGraphicsSceneLoader | load vehicle graphics scene |
| 004f8370 | ArithmeticComparison_8370 | arithmetic comparison on struct data |
| 005665b0 | sub_5665B0 | path string concatenation |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 00568540 | FileAttributesExistenceCheck | check if file exists |
| 00587bcf | FreeWrapper_7bcf | free allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory (malloc wrapper) |
| 00587dd0 | sub_587DD0 | bounded string copy (strncpy-like) |

**Guard conditions:** Guard: if *(this+13000) (offset 0x32C8) is non-zero, skip driver name loading block (driver already configured). Otherwise load driver name from config, set nationality path, and null-terminate.
