## NamedEntryLookupInFormatList_00415230 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5730 (00415730), SeasonDisplayIDResolver (0041daf0), PositionChangeDetector (00420490), VehicleSetupDriverNumber (004c7b50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x0 | R | — | [LLM] |
| *(obj+0x4) | 0x8 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00414370 | ShortComputation_4370 | R | [LLM] |
| 00415520 | SmallEntryStructInit | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | [LLM] |
| 00401030 | ArrayDestructorIterator | [LLM] |
| 00414370 | ShortComputation_4370 | [LLM] |
| 00414600 | sub_414600 | [LLM] |
| 004149a0 | TextFormatStructInitializer | [LLM] |
| 00415520 | SmallEntryStructInit | [LLM] |
| 004b0b20 | sub_4B0B20 | [LLM] |
| 004c3f80 | VehicleLookupByName | [LLM] |
| 004c4080 | CurrentVehicleAccessor | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
