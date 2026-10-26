## AISettingsFileResolver_00433890 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AISettingsFileLoader (004333e0), LoadAIDriverNamesFromConfig (004336f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3fa8 | off_5C3FA8 | R | VTable_Base [DERIVED] |
| 005c3fac | off_5C3FAC | R | UnknownDataPtr_5C3FAC [DERIVED] |
| 005c3fb0 | off_5C3FB0 | R | Off_5C3FB0_Sound [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432e50 | IterationCountMap | [LLM] |
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
