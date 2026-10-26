## LoadAIDriverNamesFromConfig_004336f0 — LoadAIDriverNamesFromConfig

**Summary:** Loads AI driver names and settings for vehicles from config file. Iterates vehicle range, skips vehicles with existing AI settings, looks up remaining vehicles in auto-load config, and validates configuration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | config file path string pointer |
| this | 0x10 | R | — | second string pointer (vehicle name for lookup/removal) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount — iteration bound |
| 005ea438 | byte_5EA438 | R | default application directory path |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — array of vehicle struct pointers |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile — auto-load config file path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432df0 | sub_432DF0 | set up config file path for reading |
| 00433890 | AISettingsFileResolver | resolve default AI settings file path |
| 004339e0 | LookUpVehicleConfigEntry | look up vehicle entry in config by name |
| 00433d60 | LinkedListRemovalByName | remove vehicle name from linked list |
| 00433ed0 | ValidateVehicleConfigurationFile | validate vehicle configuration file |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 00568540 | FileAttributesExistenceCheck | check if file exists |
| 00568b00 | sub_568B00 | check config parse state |
| 00587dd0 | sub_587DD0 | copy string with length limit |

**Guard conditions:** Parameter `a2` bounds-checked against VehicleCount: if out of range, processes all vehicles; otherwise processes single vehicle at index `a2`. Per vehicle: checks `*(v7+13000)` (AI settings present flag). If non-zero (settings already loaded), copies default AI path and continues to next vehicle. If zero, attempts config file load: file existence check must pass, `LookUpVehicleConfigEntry` must find entry, and `sub_568B00` parse check gates the fallback path.
