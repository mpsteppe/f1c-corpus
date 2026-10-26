## CareerSeasonStateFileReader_004c0b70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerCareerStatsGameOptionsLoader (004c18b0), GameOptionsWriter (004c1e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB144 | RW | — | [LLM] |
| this | 0xB150 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xB144: [LLM: once/conditional? does external poke survive?]
- this 0xB150: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2818 | aCurrentrace | R | CurrentRaceStr [DERIVED] |
| 005d2824 | aRaceover | R | RaceOverString [DERIVED] |
| 005d2830 | aRacesession | R | RaceSessionField [DERIVED] |
| 005d283c | aSeasonstatus | R | SeasonStatus [DERIVED] |
| 005d284c | aPlayer | R | Str_UI_Player [DERIVED] |
| 005d2858 | aOpponent | R | String_Opponent [DERIVED] |
| 008ac050 | unk_8AC050 | R | Unknown_SceneSetup_8AC050 [DERIVED] |
| 008ac1e8 | unk_8AC1E8 | R | SceneRenderStruct [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c03f0 | CareerStandingsStateLoader | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565760 | sub_565760 | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ece | sub_587ECE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
