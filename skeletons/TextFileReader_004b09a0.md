## TextFileReader_004b09a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50), PlayerNameNeverUsedProfileFileCreateRead (004b03f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B4 | R | — | [LLM] |

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
| 00415730 | ShortComputation_5730 | [LLM] |
| 004331a0 | DualLinkedListCleanup | [LLM] |
| 004add50 | sub_4ADD50 | [LLM] |
| 004ade20 | TrackEnvironmentSelect | [LLM] |
| 004ae750 | sub_4AE750 | [LLM] |
| 004b0180 | sub_4B0180 | [LLM] |
| 004b01b0 | sub_4B01B0 | [LLM] |
| 004b0770 | sub_4B0770 | [LLM] |
| 004c4080 | CurrentVehicleAccessor | [LLM] |
| 004c54f0 | AIW | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568620 | sub_568620 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00589671 | CreateDirectoryAWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
