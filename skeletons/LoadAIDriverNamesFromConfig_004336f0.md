## LoadAIDriverNamesFromConfig_004336f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432df0 | sub_432DF0 | [LLM] |
| 00433890 | AISettingsFileResolver | [LLM] |
| 004339e0 | LookUpVehicleConfigEntry | [LLM] |
| 00433d60 | LinkedListRemovalByName | [LLM] |
| 00433ed0 | ValidateVehicleConfigurationFile | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568540 | FileAttributesExistenceCheck | [LLM] |
| 00568b00 | sub_568B00 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
