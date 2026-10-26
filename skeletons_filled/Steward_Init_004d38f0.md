## Steward_Init_004d38f0 — StewardTrackInit

**Summary:** Initializes the steward system for a track: locates light/glow scene nodes, computes steering waypoints from track reference speed, discovers pit-in/pit-out/finish/sector polygon nodes, places multiplayer vehicles, and optionally spawns a helicopter object. Called during game initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | RW | — | helicopter object pointer (set by ObjectConstructor if helicopter node found, else 0.0) |
| this | 0xF8 | R | — | scene node handle for light/glow lookup (checked for non-null before spatial query) |
| this | 0x100 | RW | — | ground height at nearest neighbor point (float from spatial query result) |
| this | 0x108 | RW | — | waypoint density (1/step_size, computed as waypoint_count / track_ref_speed) |
| this | 0x10C | RW | — | waypoint count (computed from CRTFtol(track_ref_speed * 0.005 + 1.0)) |
| this | 0x110 | RW | — | waypoint array pointer (malloc'd: 8 bytes × waypoint_count) |
| this | 0x114 | RW | — | waypoint index/state array pointer (malloc'd: 4 bytes × waypoint_count) |
| this | 0x194 | RW | — | pit-in polygon scene node handle (from EvaluateSceneNodeProperty) |
| this | 0x198 | RW | — | pit-out polygon scene node handle |
| this | 0x19C | RW | — | finish polygon scene node handle |
| this | 0x1A0 | RW | — | sector 1 polygon scene node handle |
| this | 0x1A4 | RW | — | sector 2 polygon scene node handle |

**Written-by note (persistence):**
- this 0xA8: written once on init (helicopter pointer, or 0.0 if no helicopter node)
- this 0x100: written conditionally only if this[62] (0xF8) is non-null
- this 0x108: written once from computed density value
- this 0x10C: written once from waypoint count computation
- this 0x110: written once (malloc'd array pointer)
- this 0x114: written once (malloc'd array pointer)
- this 0x194: written once from EvaluateSceneNodeProperty result
- this 0x198: written once from EvaluateSceneNodeProperty result
- this 0x19C: written once from EvaluateSceneNodeProperty result
- this 0x1A0: written once from EvaluateSceneNodeProperty result
- this 0x1A4: written once from EvaluateSceneNodeProperty result

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d3cd4 | jpt_4D3C62 | R | jump table for switch on dword_7D0410 (ChampionshipMode dispatch) |
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
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` — waypoint accumulation weight) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004038e0 | SpatialNearestNeighborQueryWithPlaneTest | finds nearest point on track surface below light node for ground height |
| 0042cf10 | MultiplayerVehiclePlacement | places multiplayer vehicles based on championship mode |
| 00448120 | ObjectConstructor | constructs helicopter game object from scene node |
| 00448140 | sub_448140 | initializes constructed helicopter object with scene node data |
| 004d0e20 | StewardLightGlowNodeFinder | locates stlite/stglow or ptlit/ptglow scene node pairs by name |
| 004d0f00 | ShortComputation_0f00 | zeros out a waypoint entry (8-byte struct initialization) |
| 004d7a50 | StringSplitLoop | debug/dev logging gate: splits feature flag string and checks token |
| 004d7aa0 | DebugLogWrite | writes debug message to buffer when scene node not found |
| 005453a0 | EvaluateSceneNodeProperty | resolves a named scene node property handle |
| 0054b950 | SceneNodePositionGetter | gets world position (x,y,z) of a scene node |
| 0054c110 | RenderFlagSetter | sets render flags on a scene node (e.g. visibility, highlight) |
| 00587bdc | CRTFtol | converts float to int with rounding toward zero (used for waypoint count) |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation wrapper for waypoint arrays and helicopter object |

**Guard conditions:** StewardLightGlowNodeFinder lookups for stlite/stglow, ptlit01/ptglow01, ptlit02/ptglow02 always execute. Spatial nearest neighbor query only runs if this[62] (light node at 0xF8) is non-null. Waypoint count is computed from CRTFtol(flt_5EA3FC * 0.005 + 1.0). Waypoint density (this[66]) is 0.0 if flt_5EA3FC <= 0.0, else waypoint_count / flt_5EA3FC. Each polygon node (pit-in, pit-out, finish, sector1, sector2) is looked up via EvaluateSceneNodeProperty; if found, RenderFlagSetter is called, otherwise a debug log message is written (gated by StringSplitLoop dev flag check). Multiplayer vehicle placement dispatches via switch on dword_7D0410 (ChampionshipMode): case 1 → mode 0, case 2 → mode 7, cases 3/5 → mode 1, default → skip. Helicopter object created only if EvaluateSceneNodeProperty for "helicopter" returns non-null.
