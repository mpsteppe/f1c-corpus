## CamMan_Init_0040c920 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x2D | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x2D: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be8e0 | aMainview | R | StrMainView [DERIVED] |
| 005be940 | aEnteredCammanI | R | EnteredCamManIString [DERIVED] |
| 005be958 | aDDevF119992002_15 | R | AssertStr_SourcePath_15 [DERIVED] |
| 005ea500 | dword_5EA500 | W | GameStateFlag_5EA500 [DERIVED] |
| 005ea504 | dword_5EA504 | W | UIMenuState [DERIVED] |
| 005ea508 | dword_5EA508 | W | UIDispatchTable [DERIVED] |
| 005ea550 | dword_5EA550 | W | Unknown_GameState_5EA550 [DERIVED] |
| 005ea554 | dword_5EA554 | W | Unknown_Flag_5EA554 [DERIVED] |
| 005ea558 | dword_5EA558 | W | Unknown_SetupFlag [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c140 | sub_40C140 | [LLM] |
| 0040c240 | SceneFileLoadByCurrentIndex | [LLM] |
| 0040c3b0 | ModuleAssetPathResolver | [LLM] |
| 0040c520 | sub_40C520 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00544f50 | TwoLevelWideStringSearch | [LLM] |
| 0054a200 | GlobalFlagSetClear | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
