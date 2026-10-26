## TrackSceneConfigLoader_00477680 — TrackSceneConfigurationLoader

**Summary:** Loads track scene configuration: resolves season scene by name, sets font handle, and copies current vehicle name strings from a global list entry's pointer table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CopyProfileIconBMP (0046cd20), GameMode (0046d6d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007ce668 | dword_7CE668 | R | TrackNameStringPtr [DERIVED] (also: ` � track name display string) |
| 008ac36c | dword_8AC36C | R | Unknown_VehicleSetup_8AC36C [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac38c | dword_8AC38C | W | CurrentFontHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f590 | LinkedListIndexedAccessor_f590 | retrieves an indexed element from a linked list |
| 004b1520 | sub_4B1520 | reads configuration value (arg=1) into buffer |
| 004c4080 | CurrentVehicleAccessor | retrieves current vehicle data structure |
| 004c4d50 | sub_4C4D50 | processes configuration buffer value |
| 004c4ff0 | SeasonSceneMatchByIndex | matches season scene entry by name/index |
| 004c5130 | ListIndexedAccessor | accesses indexed element from a list (font handle) |
| 00566650 | StringCopyWithBufferRealloc | copies a string with automatic buffer reallocation |

**Guard conditions:** `LinkedListIndexedAccessor_f590()` must return non-null; pointer table at offset 0x3C of result must be non-null
