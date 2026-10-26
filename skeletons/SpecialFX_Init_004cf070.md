## SpecialFX_Init_004cf070 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cfc68 | jpt_4CF998 | R | [LLM] |
| 004cfc78 | byte_4CFC78 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005be690 | aRt | R | Str_RT [DERIVED] |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c6810 | aCouldNotOpenS | R | Str_CouldNotOpenS [DERIVED] |
| 005cceb0 | aCmapsMas | R | TrackCmapsMas [DERIVED] |
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d36d8 | aReaction | R | String_Reaction [DERIVED] |
| 005d3940 | aLptree | R | LptreeString [DERIVED] |
| 005d3948 | aAiwetgrip | R | AIWetGripString [DERIVED] |
| 005d3954 | aAidrygrip | R | AiDryGripString [DERIVED] |
| 005d3960 | aMasfile | R | StringMasFile [DERIVED] |
| 005d3968 | aSearchpath | R | Str_SearchPath [DERIVED] |
| 005d3974 | aLoose | R | LooseStr [DERIVED] |
| 005d397c | aExcludetracks | R | ExcludeTracksString [DERIVED] |
| 005d398c | aIncludetracks | R | IncludeTracksField [DERIVED] |
| 005d399c | aFeedback | R | FeedbackKeyword [DERIVED] |
| 005d39a8 | aTrackvars | R | String_TrackVars [DERIVED] |
| 005d39b4 | aEnteredSpecial_1 | R | EnteredSpecialString [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004024f0 | AIWaypointPathCheckerRenderer | [LLM] |
| 00403cd0 | sub_403CD0 | [LLM] |
| 0044c0e0 | SceneTrackFileLoader | [LLM] |
| 0044c4c0 | SpatialGridQuery | [LLM] |
| 004c58a0 | StringCopyWithValidation | [LLM] |
| 004c9d10 | TwoFieldSetter_9d10 | [LLM] |
| 004c9d30 | RecursiveTreeFree | [LLM] |
| 004c9fb0 | ParticleCollisionSpawn | [LLM] |
| 004ca280 | sub_4CA280 | [LLM] |
| 004ca3e0 | ArithmeticComparison_a3e0 | [LLM] |
| 004ca480 | MaterialShaderReactionEffectParser | [LLM] |
| 004caed0 | sub_4CAED0 | [LLM] |
| 004cb120 | sub_4CB120 | [LLM] |
| 004cdb90 | ConstructorInitFields | [LLM] |
| 004cdd80 | TrackSurfaceMaterialLoader | [LLM] |
| 004ceef0 | sub_4CEEF0 | [LLM] |
| 004cef30 | sub_4CEF30 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 0053c800 | StringRegistry | [LLM] |
| 0053c900 | StringMatchWithFlagSet | [LLM] |
| 0053cbc0 | sub_53CBC0 | [LLM] |
| 0053ce40 | PhysicsObjectLinkedListRemoval | [LLM] |
| 005452f0 | AudioNetworkNodeCount | [LLM] |
| 00545340 | LinkedListNodeFinder | [LLM] |
| 0054bda0 | SelfRelativeStringCopy | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00566810 | sub_566810 | [LLM] |
| 00568a60 | UtilityFunction_8a60 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ca0 | FileReadUntilNewline | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587f64 | sub_587F64 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 0058850f | sub_58850F | [LLM] |
| 00588640 | sub_588640 | [LLM] |
| 00589db0 | sub_589DB0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
