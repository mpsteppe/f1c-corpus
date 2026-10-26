## VehgenScnFileLoader_004c6c40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0), NetCommPlayerSlotSync (0045fc50), ProcessDriverEntries (004b8da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32C8 | R | — | [LLM] |
| this | 0x4677 | RW | 0 | [LLM] |
| this | 0x4894 | R | — | [LLM] |
| this | 0x48A4 | RW | 18446744073709551615 | [LLM] |
| this | 0x48A8 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x4677: [LLM: once/conditional? does external poke survive?]
- this 0x48A4: [LLM: once/conditional? does external poke survive?]
- this 0x48A8: [LLM: once/conditional? does external poke survive?]

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
| 00410b20 | ShortComputation_0b20 | [LLM] |
| 004a4900 | sub_4A4900 | [LLM] |
| 004b0b20 | sub_4B0B20 | [LLM] |
| 004bb800 | ZeroTwoFields | [LLM] |
| 004c6980 | SetDriverName | [LLM] |
| 004c7b50 | VehicleSetupDriverNumber | [LLM] |
| 004ddf90 | SceneFileTEAMDIRVEHDIRNOTSPINWriter | [LLM] |
| 004dfce0 | VehicleGraphicsSceneLoader | [LLM] |
| 004f8370 | ArithmeticComparison_8370 | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568540 | FileAttributesExistenceCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
