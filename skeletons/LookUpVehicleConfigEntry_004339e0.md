## LookUpVehicleConfigEntry_004339e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadAIDriverNamesFromConfig (004336f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1C)+0x0)+0x8) | 0x0 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x10 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x14 | R | — | [LLM] |
| *(*(this+0x24)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| *(this+0x24) | 0x4 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004326a0 | SettingsFolderResolver | [LLM] |
| 00432e50 | IterationCountMap | [LLM] |
| 00432e70 | AutoLoadEntryListLoader | [LLM] |
| 004c40b0 | ConditionalDispatch_40b0 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
