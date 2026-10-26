## ConfigDirectoryPathRegistration_004216f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FunctionCallWrapper_1470 (00421470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | RW | 0 | [LLM] |
| this | 0xBC | RW | 0 | [LLM] |
| this | 0xC0 | RW | 0 | [LLM] |
| this | 0xC4 | RW | 22 | [LLM] |
| this | 0xC8 | RW | 1 | [LLM] |
| this | 0xCC | RW | 0 | [LLM] |
| this | 0xD0 | RW | 0 | [LLM] |
| this | 0xD4 | RW | 0 | [LLM] |
| this | 0xD5 | RW | 1 | [LLM] |
| this | 0xD6 | RW | 0 | [LLM] |
| this | 0xD8 | RW | 1 | [LLM] |
| this | 0xDC | RW | 1 | [LLM] |
| this | 0xE0 | RW | 0 | [LLM] |
| this | 0xE4 | RW | 1 | [LLM] |
| this | 0xE8 | RW | 18446744072627421184 → -1.0f | [LLM] |

**Written-by note (persistence):**
- this 0xB8: [LLM: once/conditional? does external poke survive?]
- this 0xBC: [LLM: once/conditional? does external poke survive?]
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0xC4: [LLM: once/conditional? does external poke survive?]
- this 0xC8: [LLM: once/conditional? does external poke survive?]
- this 0xCC: [LLM: once/conditional? does external poke survive?]
- this 0xD0: [LLM: once/conditional? does external poke survive?]
- this 0xD4: [LLM: once/conditional? does external poke survive?]
- this 0xD5: [LLM: once/conditional? does external poke survive?]
- this 0xD6: [LLM: once/conditional? does external poke survive?]
- this 0xD8: [LLM: once/conditional? does external poke survive?]
- this 0xDC: [LLM: once/conditional? does external poke survive?]
- this 0xE0: [LLM: once/conditional? does external poke survive?]
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]

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
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
