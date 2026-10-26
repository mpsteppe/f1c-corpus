## AIDriverCountSetup_004bfd90 — [LLM: short descriptive name]

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
| 005c329c | dword_5C329C | RW | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC [LLM: field purpose] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007d00c8 | dword_7D00C8 | R | [LLM] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008aae70 | dword_8AAE70 | R | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac38c | dword_8AC38C | R | CurrentFontHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | [LLM] |
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 004b3c60 | DeterministicHashPseudoRandomGenerator | [LLM] |
| 004bf630 | ZeroInit4Ints | [LLM] |
| 004bf640 | LinkedListDestruction_f640 | [LLM] |
| 004bf790 | AIOpponentSelection | [LLM] |
| 004bfd40 | IndexedListLookup | [LLM] |
| 004c3f80 | VehicleLookupByName | [LLM] |
| 004c6960 | TeamIDSetter | [LLM] |
| 004c78f0 | NationalityDriverInfoLoader | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
