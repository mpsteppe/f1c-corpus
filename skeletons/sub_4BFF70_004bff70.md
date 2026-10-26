## sub_4BFF70_004bff70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 005f070c | unk_5F070C | R | VEH[0].0x4034 [LLM: field purpose] |
| 005f0734 | unk_5F0734 | R | VEH[0].0x405C = timeOfQualySession [CONFIRMED] |
| 005f0cf8 | unk_5F0CF8 | R | VEH[0].0x4620 = DriverName [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007ce668 | dword_7CE668 | R | TrackNameStringPtr [DERIVED] (also: ` � track name display string) |
| 007d0110 | dword_7D0110 | R | CurrentCarDisplayIndex [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | [LLM] |
| 004bc2f0 | ConditionalFieldSetter | [LLM] |
| 004c0260 | sub_4C0260 | [LLM] |
| 004c02d0 | sub_4C02D0 | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
