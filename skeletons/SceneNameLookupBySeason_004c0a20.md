## SceneNameLookupBySeason_004c0a20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ChampionshipPointsAccumulator (0041f220), MemoryAllocation_fb10 (0041fb10), SessionStateSearch (0041fc60), ConfigSectionSearchByKeyValue (0041fe00), SceneElementScanWithConditionCheck (0041ff10), ShortComputation_12e0 (004212e0), CountActiveEntitiesByState (00421380), sub_47C360 (0047c360), sub_4A08E0 (004a08e0), sub_4C13C0 (004c13c0), PathFileComparisonCounter (004c1450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3f80 | VehicleLookupByName | [LLM] |
| 004c4080 | CurrentVehicleAccessor | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
