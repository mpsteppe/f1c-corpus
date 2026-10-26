## TextFileReader_004b09a0 — TextFileReaderAndEnvironmentSetup

**Summary:** Reads text file path, creates directory tree for the path, sets environment type (wet/dry), loads AIW data if scene files exist, loads vehicle data if vehicle files exist, then runs file copy, track environment selection, cleanup, and settings file read/write.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50), PlayerNameNeverUsedProfileFileCreateRead (004b03f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B4 | R | — | pointer to a path string for ShortComputation_5730 (when loading vehicle data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007cb710 | byte_7CB710 | R | EnvironmentFlags [DERIVED] (also: ` — Env flag (bit 0 = wet) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415730 | ShortComputation_5730 | pushes path onto memory cleanup list |
| 004331a0 | DualLinkedListCleanup | cleans up dual-linked list (device identity) |
| 004add50 | sub_4ADD50 | copies save file with metadata |
| 004ade20 | TrackEnvironmentSelect | selects track environment (wet/dry) and initializes physics |
| 004ae750 | sub_4AE750 | sets environment type (1=dry, 2=wet) based on flag bit 0 |
| 004b0180 | sub_4B0180 | builds directory path from name + settings dir |
| 004b01b0 | sub_4B01B0 | builds full directory path from name + settings dir |
| 004b0770 | sub_4B0770 | settings file read/write with backup |
| 004c4080 | CurrentVehicleAccessor | accesses current vehicle data pointer |
| 004c54f0 | AIW | loads AIW (artificial intelligence waypoint) data |
| 00566650 | StringCopyWithBufferRealloc | copies string with reallocation |
| 00568620 | sub_568620 | initializes buffer/string of given size |
| 00587dd0 | sub_587DD0 | copies substring with length limit |
| 00589671 | CreateDirectoryAWrapper | creates directory (wraps CreateDirectoryA) |

**Guard conditions:** If a2 (input path string) is NULL, returns -1 immediately. Blocked: null input.
