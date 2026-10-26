## SessionConfigReader_004c11e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C1050 (004c1050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB130 | RW | 18446744073709551615 | [LLM] |
| this | 0xB134 | RW | 18446744073709551615 | [LLM] |
| this | 0xB138 | RW | 18446744073709551615 | [LLM] |
| this | 0xB13C | RW | 18446744073709551615 | [LLM] |
| this | 0xB140 | RW | 18446744073709551615 | [LLM] |
| this | 0xB148 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB130: [LLM: once/conditional? does external poke survive?]
- this 0xB134: [LLM: once/conditional? does external poke survive?]
- this 0xB138: [LLM: once/conditional? does external poke survive?]
- this 0xB13C: [LLM: once/conditional? does external poke survive?]
- this 0xB140: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7444 | aRacelaps | R | String_RaceLaps [DERIVED] |
| 005d2310 | aRacetime | R | aRacetime [DERIVED] |
| 005d231c | aQualifylaps | R | Str_QualifyLaps [DERIVED] |
| 005d28b4 | aSceneorder | R | SceneOrderStringConst [DERIVED] (also: ` — "SceneOrder" string constant) |
| 005d28c0 | aQualifytime | R | QualifytimeString [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | [LLM] |
| 004c55b0 | TrackSceneLoader | [LLM] |
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679a0 | NullCheckWrapper | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587ece | sub_587ECE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
