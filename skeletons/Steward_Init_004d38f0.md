## Steward_Init_004d38f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | RW | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x10C | RW | — | [LLM] |
| this | 0x110 | RW | — | [LLM] |
| this | 0x114 | RW | — | [LLM] |
| this | 0x194 | RW | — | [LLM] |
| this | 0x198 | RW | — | [LLM] |
| this | 0x19C | RW | — | [LLM] |
| this | 0x1A0 | RW | — | [LLM] |
| this | 0x1A4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xA8: [LLM: once/conditional? does external poke survive?]
- this 0x100: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]
- this 0x10C: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x114: [LLM: once/conditional? does external poke survive?]
- this 0x194: [LLM: once/conditional? does external poke survive?]
- this 0x198: [LLM: once/conditional? does external poke survive?]
- this 0x19C: [LLM: once/conditional? does external poke survive?]
- this 0x1A0: [LLM: once/conditional? does external poke survive?]
- this 0x1A4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d3cd4 | jpt_4D3C62 | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acd3c | flt_5ACD3C | R | AeroDragCoefficient [DERIVED] (also: ` — aero constant) |
| 005d3b6c | aDDevF119992002_3 | R | aDDevF119992002_3 [DERIVED] |
| 005d4208 | aHelicopter | R | HelicopterString [DERIVED] |
| 005d4214 | aNoSector2PolyF | R | NoSector2PolyFString [DERIVED] |
| 005d422c | aXsector2 | R | XSector2String [DERIVED] |
| 005d4238 | aNoSector1PolyF | R | String_NoSector1Poly [DERIVED] |
| 005d4250 | aXsector1 | R | XSector1String [DERIVED] |
| 005d425c | aNoFinishPolyFo | R | NoFinishPolyFo [DERIVED] |
| 005d4274 | aXfinish | R | XFinishField [DERIVED] |
| 005d427c | aNoPitOutPolyFo | R | NoPitOutPolyString [DERIVED] |
| 005d4294 | aXpitout | R | XpitoutString [DERIVED] |
| 005d429c | aNoPitInPolyFou | R | NoPitInPolyFouString [DERIVED] |
| 005d42b4 | aXpitin | R | Str_Xpitin [DERIVED] |
| 005d42bc | aPtlit01 | R | StringPtLit01 [DERIVED] |
| 005d42c4 | aPtglow01 | R | Ptglow01String [DERIVED] |
| 005d42d0 | aPtlit02 | R | PtLit02String [DERIVED] |
| 005d42d8 | aPtglow02 | R | Ptglow02String [DERIVED] |
| 005d42e4 | aStlite | R | StliteStr [DERIVED] |
| 005d42ec | aStglow | R | StGlowString [DERIVED] |
| 005d42f4 | aEnteredSteward_0 | R | EnteredStewardField [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` â€” waypoint accumulation weight) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004038e0 | SpatialNearestNeighborQueryWithPlaneTest | [LLM] |
| 0042cf10 | MultiplayerVehiclePlacement | [LLM] |
| 00448120 | ObjectConstructor | [LLM] |
| 00448140 | sub_448140 | [LLM] |
| 004d0e20 | StewardLightGlowNodeFinder | [LLM] |
| 004d0f00 | ShortComputation_0f00 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005453a0 | EvaluateSceneNodeProperty | [LLM] |
| 0054b950 | SceneNodePositionGetter | [LLM] |
| 0054c110 | RenderFlagSetter | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
