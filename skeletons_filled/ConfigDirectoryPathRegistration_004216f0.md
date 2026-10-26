## ConfigDirectoryPathRegistration_004216f0 — ConfigDirectoryPathRegistration

**Summary:** Registers all configuration directory paths by copying path string constants for audio, circuits, drivers, movies, options, replays, and other data directories, then initializes default config structure fields with preset values (including a count of 22 registered paths and a -1.0f sentinel).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FunctionCallWrapper_1470 (00421470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | RW | 0 | config field — reserved / zero-initialized |
| this | 0xBC | RW | 0 | config field — reserved / zero-initialized |
| this | 0xC0 | RW | 0 | config field — reserved / zero-initialized |
| this | 0xC4 | RW | 22 | count of registered directory paths (22 entries) |
| this | 0xC8 | RW | 1 | config flag — enabled / active (bool as dword) |
| this | 0xCC | RW | 0 | config flag — disabled / inactive |
| this | 0xD0 | RW | 0 | config field — reserved / zero-initialized |
| this | 0xD4 | RW | 0 | byte flag at offset 212 — disabled (zeroed after D5) |
| this | 0xD5 | RW | 1 | byte flag at offset 213 — enabled |
| this | 0xD6 | RW | 0 | byte flag at offset 214 — disabled |
| this | 0xD8 | RW | 1 | config option — enabled (dword) |
| this | 0xDC | RW | 1 | config option — enabled (dword) |
| this | 0xE0 | RW | 0 | config field — reserved / zero-initialized |
| this | 0xE4 | RW | 1 | config option — enabled (dword) |
| this | 0xE8 | RW | 18446744072627421184 → -1.0f | sentinel float value (-1.0f, marks uninitialized/invalid) |

**Written-by note (persistence):**
- this 0xB8: write-once registration — external poke persists until next registration
- this 0xBC: write-once registration — external poke persists until next registration
- this 0xC0: write-once registration — external poke persists until next registration
- this 0xC4: write-once registration — external poke persists until next registration
- this 0xC8: write-once registration — external poke persists until next registration
- this 0xCC: write-once registration — external poke persists until next registration
- this 0xD0: write-once registration — external poke persists until next registration
- this 0xD4: write-once registration — external poke persists until next registration
- this 0xD5: write-once registration — external poke persists until next registration
- this 0xD6: write-once registration — external poke persists until next registration
- this 0xD8: write-once registration — external poke persists until next registration
- this 0xDC: write-once registration — external poke persists until next registration
- this 0xE0: write-once registration — external poke persists until next registration
- this 0xE4: write-once registration — external poke persists until next registration
- this 0xE8: write-once registration — external poke persists until next registration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c29bc | aAudioCommentar_1 | R | AudioCommentaryString [DERIVED] |
| 005c29d0 | aSchool | R | SchoolString [DERIVED] |
| 005c29d8 | aDevfilesCamed | R | Str_DevFilesCamEd [DERIVED] |
| 005c29e8 | aAudioMusic | R | StringAudioMusic [DERIVED] |
| 005c29f8 | aSave | R | SaveString [DERIVED] |
| 005c2a00 | aLog | R | LogString [DERIVED] |
| 005c2a08 | aDrivers | R | DriversString [DERIVED] |
| 005c2a14 | aVehicles | R | VehiclesDirString [DERIVED] |
| 005c2a20 | aCircuits | R | CircuitsString [DERIVED] |
| 005c2a2c | aMovies | R | MoviesField [DERIVED] |
| 005c2a34 | aReplays | R | Path_Replays [DERIVED] |
| 005c2a40 | aOptions | R | String_Options [DERIVED] |
| 005c2a4c | aAudioOptions | R | AudioOptionsString [DERIVED] |
| 005c2a5c | aOptionsFlags | R | OptionsFlagsString [DERIVED] |
| 005c2a6c | aOptionsAnim | R | OptionsAnimString [DERIVED] |
| 005c2a7c | aAudioVehicle | R | String_AudioVehicle [DERIVED] |
| 005c2a8c | aAudio | R | s_Audio [DERIVED] |
| 005c2a94 | aSeasondata | R | SeasonData [DERIVED] |
| 005c2aa0 | ExistingFileName | R | FileSearchPattern [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies a directory path string constant into a reallocated buffer (called 25 times for each path) |

**Guard conditions:** No guard conditions — unconditional initialization of all directory path strings and config structure fields.
