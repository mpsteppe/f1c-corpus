## SpecialFX_Init_004cf070 — Special effects system initialization and config parser

**Summary:** Initializes the special effects (particle collision, material reaction, track surface) subsystem: parses track `.mas` config files, loads feedback/reaction effect definitions, sets up per-track material effect arrays, allocates particle collision structures, and configures spatial grid queries for effect placement. Part of the special effects / physics reaction system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | sub-field of the reaction array ptr: effect type/category |
| this | 0x0 | RW | 0 | counter of lptree collision nodes found |
| this | 0x4 | RW | — | allocated array of particle collision effect structs |
| this | 0x8 | RW | 0 | count of feedback effect entries |
| this | 0xC | RW | — | allocated array of track feedback effect structs (108 bytes each) |
| this | 0x10 | RW | 0 | count of material reaction effects processed |
| this | 0x14 | RW | — | allocated array of material reaction effect structs (108 bytes each) |
| this | 0x18 | RW | 0 | zeroed counter |
| this | 0x1C | RW | 0 | zeroed counter |
| this | 0x20 | RW | 0 | zeroed counter |
| this | 0x24 | RW | 0 | ptr to special effect type 12 (always set if found) |
| this | 0x28 | RW | 0 | ptr to special effect type 13 |
| this | 0x2C | RW | — | grid query result: collision geometry node ptr |
| this | 0x30 | RW | — | dry grip override value (float) |
| this | 0x34 | RW | — | wet grip override value (float) |

**Written-by note (persistence):**
- this 0x0: set once at game init — external poke survives until next init
- this 0x4: set once at game init — external poke survives until next init
- this 0x8: set once at game init — external poke survives until next init
- this 0xC: set once at game init — external poke survives until next init
- this 0x10: set once at game init — external poke survives until next init
- this 0x14: set once at game init — external poke survives until next init
- this 0x18: set once at game init — external poke survives until next init
- this 0x1C: set once at game init — external poke survives until next init
- this 0x20: set once at game init — external poke survives until next init
- this 0x24: set once at game init — external poke survives until next init
- this 0x28: set once at game init — external poke survives until next init
- this 0x2C: set once at game init — external poke survives until next init
- this 0x30: set once at game init — external poke survives until next init
- this 0x34: set once at game init — external poke survives until next init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cfc68 | jpt_4CF998 | R | switch jump table for effect type dispatch |
| 004cfc78 | byte_4CFC78 | R | switch case byte data for effect type routing |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005be690 | aRt | R | Str_RT [DERIVED] |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` — format string for path construction) |
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
| 004024f0 | AIWaypointPathCheckerRenderer | render waypoint path check visualization |
| 00403cd0 | sub_403CD0 | query scene config bounds for spatial grid setup |
| 0044c0e0 | SceneTrackFileLoader | load track scene file into spatial database |
| 0044c4c0 | SpatialGridQuery | query spatial grid for collision geometry at point |
| 004c58a0 | StringCopyWithValidation | copy string with bounds validation |
| 004c9d10 | TwoFieldSetter_9d10 | initialize two-field struct (key-value pair constructor) |
| 004c9d30 | RecursiveTreeFree | free linked tree of key-value parse nodes |
| 004c9fb0 | ParticleCollisionSpawn | spawn particle effect for collision node |
| 004ca280 | sub_4CA280 | initialize particle collision struct fields |
| 004ca3e0 | ArithmeticComparison_a3e0 | initialize reaction effect struct fields |
| 004ca480 | MaterialShaderReactionEffectParser | parse material/shader reaction effect definition |
| 004caed0 | sub_4CAED0 | compare two reaction effect structs for dedup |
| 004cb120 | sub_4CB120 | dispatch effect initialization by type (3-phase) |
| 004cdb90 | ConstructorInitFields | zero-initialize struct fields |
| 004cdd80 | TrackSurfaceMaterialLoader | load track surface material definition |
| 004ceef0 | sub_4CEEF0 | initialize string buffer with format |
| 004cef30 | sub_4CEF30 | finalize special effects init after parsing |
| 004d7a50 | StringSplitLoop | debug log string split/format |
| 004d7aa0 | DebugLogWrite | write debug log message |
| 0053c800 | StringRegistry | register string in hash table for lookup |
| 0053c900 | StringMatchWithFlagSet | match string and set flags |
| 0053cbc0 | sub_53CBC0 | open file by path (returns handle) |
| 0053ce40 | PhysicsObjectLinkedListRemoval | remove from physics linked list |
| 005452f0 | AudioNetworkNodeCount | count audio network nodes for collision geometry |
| 00545340 | LinkedListNodeFinder | find node in linked list by index |
| 0054bda0 | SelfRelativeStringCopy | copy string from self-referencing buffer |
| 005651b0 | sub_5651B0 | parse line type classifier |
| 00565520 | sub_565520 | parse key=value line |
| 00566810 | sub_566810 | string/integer comparison utility |
| 00568a60 | UtilityFunction_8a60 | utility function (format/init with value 181) |
| 00587bcf | FreeWrapper_7bcf | free memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory |
| 00587c20 | sub_587C20 | string prefix match check |
| 00587ca0 | FileReadUntilNewline | read file line into buffer |
| 00587d02 | FileCloseWithLock | close file handle |
| 00587db0 | sub_587DB0 | open file for reading with path |
| 00587f64 | sub_587F64 | seek file to beginning |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with overflow protection |
| 0058850f | sub_58850F | parse float from string |
| 00588640 | sub_588640 | string prefix compare (strncmp wrapper) |
| 00589db0 | sub_589DB0 | find character in string (strchr wrapper) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | > | 0 | material reaction count positive — triggers effect type assignment loop |

**Guard interpretation:** After all parsing, if `this+0x10` (material reaction count) > 0, the function iterates over reaction effects assigning sequential IDs and dispatching per-type initialization in 3 phases. When count is 0, the type-assignment and dispatch loops are skipped entirely (no effects to process).
