## VehicleGraphicsSceneLoader_004dfce0 — Vehicle graphics scene node tree loader and initializer

**Summary:** Loads and initializes the full vehicle graphics scene graph — wheel nodes, wings, cockpit, debris, lights, and all visual sub-nodes — from a scene file and populates bounding boxes, audio parameters, and tread/sound effect handles. Part of the vehicle rendering/graphics scene management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehgenScnFileLoader (004c6c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | vehicle slot/instance index (from parent object) |
| obj | 0x4898 | R | — | vehicle array index (from parent object) |
| this | 0x0 | R | — | pointer to parent/owner object |
| this | 0x4 | RW | — | root scene node instance handle (vehicle slot result) |
| this | 0x60 | RW | — | bounding box minimum X (float) |
| this | 0x64 | RW | — | bounding box minimum Y (float) |
| this | 0x68 | RW | — | bounding box minimum Z (float) |
| this | 0x6C | RW | — | bounding box maximum X (float) |
| this | 0x70 | RW | — | bounding box maximum Y (float) |
| this | 0x74 | RW | — | bounding box maximum Z (float) |
| this | 0x78 | R | — | source bounding box min X (copy from) |
| this | 0x7C | R | — | source bounding box min Y |
| this | 0x80 | R | — | source bounding box min Z |
| this | 0x84 | R | — | source bounding box max X |
| this | 0x88 | R | — | source bounding box max Y |
| this | 0x8C | R | — | source bounding box max Z |
| this | 0x144 | RW | — | LF (left-front) tire scene node handle |
| this | 0x188 | RW | — | LF spindle scene node handle |
| this | 0x18C | RW | — | per-wheel data block[0]: spindle/tire node copy, disc glow refs (stride 74 dwords) |
| this | 0x190 | RW | — | per-wheel[0] field 1 |
| this | 0x194 | RW | — | per-wheel[0] field 2 |
| this | 0x198 | RW | — | per-wheel[0] field 3 |
| this | 0x19C | RW | — | per-wheel[0] field 4 |
| this | 0x1A0 | RW | — | per-wheel[0] field 5 |
| this | 0x1E0 | RW | 0 | per-wheel[0] disc glow reference index 1 (v79[21]) |
| this | 0x1E4 | RW | 0 | per-wheel[0] disc glow reference index 2 (v79[22]) |
| this | 0x1E8 | RW | 0 | per-wheel[0] zero-init field (v79[23]) |
| this | 0x1EC | W | 0 | per-wheel[0] zero-init (disc glow lookup result) |
| this | 0x26C | RW | — | RF (right-front) tire scene node handle |
| this | 0x2B0 | RW | — | RF spindle scene node handle |
| this | 0x394 | RW | — | LR (left-rear) tire scene node handle |
| this | 0x3D8 | RW | — | LR spindle scene node handle |
| this | 0x4BC | RW | — | RR (right-rear) tire scene node handle |
| this | 0x500 | RW | — | RR spindle scene node handle |
| this | 0x5E4 | RW | — | front wing scene node handle |
| this | 0x628 | RW | — | rear wing scene node handle |
| this | 0x66C | RW | — | debris[0] scene node handle |
| this | 0x88C | RW | — | cockpit scene node handle |
| this | 0x890 | RW | — | suspension scene node handle |
| this | 0x894 | RW | — | helmet scene node handle |
| this | 0x898 | RW | — | arms scene node handle |
| this | 0x89C | RW | — | body scene node handle |
| this | 0x8A0 | RW | — | wheel (generic) scene node handle |
| this | 0x8A4 | RW | — | rain light scene node handle |
| this | 0x8A8 | RW | — | brake light scene node handle |
| this | 0x8AC | RW | — | headlight scene node handle |
| this | 0x8B0 | RW | — | backfire scene node handle |
| this | 0x8B4 | RW | 0 | catsteer child node count |
| this | 0x8C0 | RW | 0 | catsteer matched steering node count |
| this | 0x8C4 | RW | — | catsteer matched steering node[0] |
| this | 0x8E8 | RW | — | vehicle data field[0] (from VehicleArray ptr+17) |
| this | 0x8EC | RW | — | vehicle data field[1] (ptr+18) |
| this | 0x8F0 | RW | — | vehicle data field[2] (ptr+19) |
| this | 0x8F4 | RW | — | vehicle data field[3] (ptr+14) |
| this | 0x8F8 | RW | — | vehicle data field[4] (ptr+15) |
| this | 0x8FC | RW | — | vehicle data field[5] (ptr+16) |
| this | 0x900 | RW | 0 | zero-init vehicle data slot[0] |
| this | 0x904 | RW | 0 | zero-init vehicle data slot[1] |
| this | 0x908 | RW | 0 | zero-init vehicle data slot[2] |
| this | 0x90C | RW | 0 | zero-init vehicle data slot[3] |
| this | 0x910 | RW | 0 | zero-init vehicle data slot[4] |
| this | 0x914 | RW | 0 | zero-init vehicle data slot[5] |
| this | 0x918 | RW | — | vehicle data field[6] (ptr+20) |
| this | 0x91C | RW | — | vehicle data field[7] (ptr+21) |
| this | 0x920 | RW | — | vehicle data field[8] (ptr+22) |
| this | 0x924 | RW | — | vehicle data field[9] (ptr+23) |
| this | 0x928 | RW | — | vehicle data field[10] (ptr+24) |
| this | 0x92C | W | — | vehicle data field[11] (ptr+25) |
| this | 0x930 | RW | 0 | helmet triple-field query result[0] |
| this | 0x934 | W | 0 | zero-init[0] |
| this | 0x938 | W | 0 | zero-init[1] |
| this | 0x93C | W | 0 | zero-init[2] |
| this | 0x940 | W | 0 | zero-init[3] |
| this | 0x944 | W | 0 | zero-init[4] |
| this | 0x948 | W | 0 | zero-init[5] |
| this | 0x950 | RW | 0 | zero-init counter/value (596) |
| this | 0x958 | W | — | vehicle data field[12] (ptr+26) |
| this | 0x95C | W | — | vehicle data field[13] (ptr+27) |
| this | 0x960 | W | — | vehicle data field[14] (ptr+28) |
| this | 0x96C | W | 1 | byte flag: initialization complete flag A |
| this | 0x96D | W | 1 | byte flag: initialization complete flag B |
| this | 0x970 | W | — | tire tread brightness multiplier (float, 1.0f init) |
| this | 0x975 | W | 0 | byte flag: clear state |
| this | 0x976 | W | 1 | byte flag: enabled state A |
| this | 0x977 | W | 0 | byte flag: disabled state |
| this | 0x978 | W | 1 | byte flag: enabled state B |
| this | 0x979 | W | 0 | byte flag: clear state |
| this | 0x97C | W | — | per-tire brightness factor (computed from weather noise) |
| this | 0xB6C | W | 0 | zero-init audio/effect field (this[731]) |
| this | 0x2BD0 | W | — | tire scene node array count (number of tire child nodes found) |
| this | 0x2BD4 | W | — | tire position data array pointer (malloc'd, 20 bytes per tire) |

**Written-by note (persistence):**
- this 0x4: once (scene init); external poke survives (holds scene node handle)
- this 0x60: once (scene init); external poke survives (bounding box updated later by BoundingBoxUpdate)
- this 0x64: once (scene init); external poke survives
- this 0x68: once (scene init); external poke survives
- this 0x6C: once (scene init); external poke survives
- this 0x70: once (scene init); external poke survives
- this 0x74: once (scene init); external poke survives
- this 0x144: once (scene init); external poke survives (holds scene node handle)
- this 0x188: once (scene init); external poke survives
- this 0x18C: once (scene init); external poke survives
- this 0x190: once (scene init); external poke survives
- this 0x194: once (scene init); external poke survives
- this 0x198: once (scene init); external poke survives
- this 0x19C: once (scene init); external poke survives
- this 0x1A0: once (scene init); external poke survives
- this 0x1E0: once (scene init); external poke survives (may be updated by disc glow system)
- this 0x1E4: once (scene init); external poke survives
- this 0x1E8: once (scene init); external poke survives
- this 0x1EC: once (scene init); external poke survives
- this 0x26C: once (scene init); external poke survives
- this 0x2B0: once (scene init); external poke survives
- this 0x394: once (scene init); external poke survives
- this 0x3D8: once (scene init); external poke survives
- this 0x4BC: once (scene init); external poke survives
- this 0x500: once (scene init); external poke survives
- this 0x5E4: once (scene init); external poke survives
- this 0x628: once (scene init); external poke survives
- this 0x66C: once (scene init); external poke survives
- this 0x88C: once (scene init); external poke survives
- this 0x890: once (scene init); external poke survives
- this 0x894: once (scene init); external poke survives
- this 0x898: once (scene init); external poke survives
- this 0x89C: once (scene init); external poke survives
- this 0x8A0: once (scene init); external poke survives
- this 0x8A4: once (scene init); external poke survives
- this 0x8A8: once (scene init); external poke survives
- this 0x8AC: once (scene init); external poke survives
- this 0x8B0: once (scene init); external poke survives
- this 0x8B4: once (scene init); external poke survives (updated if catsteer children found)
- this 0x8C0: once (scene init); external poke survives
- this 0x8C4: once (scene init); external poke survives
- this 0x8E8: once (scene init); external poke survives (vehicle data from global array)
- this 0x8EC: once (scene init); external poke survives
- this 0x8F0: once (scene init); external poke survives
- this 0x8F4: once (scene init); external poke survives
- this 0x8F8: once (scene init); external poke survives
- this 0x8FC: once (scene init); external poke survives
- this 0x900: once (scene init); external poke survives
- this 0x904: once (scene init); external poke survives
- this 0x908: once (scene init); external poke survives
- this 0x90C: once (scene init); external poke survives
- this 0x910: once (scene init); external poke survives
- this 0x914: once (scene init); external poke survives
- this 0x918: once (scene init); external poke survives
- this 0x91C: once (scene init); external poke survives
- this 0x920: once (scene init); external poke survives
- this 0x924: once (scene init); external poke survives
- this 0x928: once (scene init); external poke survives
- this 0x92C: once (scene init); external poke survives
- this 0x930: once (scene init); external poke survives
- this 0x934: once (scene init); external poke survives
- this 0x938: once (scene init); external poke survives
- this 0x93C: once (scene init); external poke survives
- this 0x940: once (scene init); external poke survives
- this 0x944: once (scene init); external poke survives
- this 0x948: once (scene init); external poke survives
- this 0x950: once (scene init); external poke survives
- this 0x958: once (scene init); external poke survives
- this 0x95C: once (scene init); external poke survives
- this 0x960: once (scene init); external poke survives
- this 0x96C: once (scene init); external poke survives (init-complete flag, may be checked elsewhere)
- this 0x96D: once (scene init); external poke survives
- this 0x970: once (scene init); external poke survives
- this 0x975: once (scene init); external poke survives
- this 0x976: once (scene init); external poke survives
- this 0x977: once (scene init); external poke survives
- this 0x978: once (scene init); external poke survives
- this 0x979: once (scene init); external poke survives
- this 0x97C: once (scene init); external poke survives (may be updated per-frame by weather/noise)
- this 0xB6C: once (scene init); external poke survives
- this 0x2BD0: once (scene init); external poke survives (tire array count set during load)
- this 0x2BD4: once (scene init); external poke survives (malloc pointer, may be freed elsewhere)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e854 | flt_59E854 | R | Flt_Physics_AI_Threshold [DERIVED] |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 005ad14c | flt_5AD14C | R | RenderTargetWidth [DERIVED] |
| 005beb70 | aWheel | R | WheelNode [DERIVED] |
| 005c6740 | aCatsteer | R | CatsteerString [DERIVED] |
| 005c674c | aArms | R | ArmsString [DERIVED] |
| 005c6754 | aLftire | R | NodeNameLFTire [DERIVED] |
| 005c675c | aRftire | R | aRftire [DERIVED] |
| 005c6764 | aLrtire | R | LRTire [DERIVED] |
| 005c676c | aRrtire | R | TireName_RR [DERIVED] |
| 005c677c | aCockpit | R | Cockpit [DERIVED] |
| 005d4ce0 | aDDevF119992002_6 | R | SourcePath_F1_1999_2002_6 [DERIVED] |
| 005d4d08 | aTire | R | TireString [DERIVED] |
| 005d4d10 | off_5D4D10 | R | VehicleSceneVTable [DERIVED] |
| 005d4d14 | aTreadlow | R | TreadlowStr [DERIVED] |
| 005d4d20 | aTreadmed | R | TreadMedString [DERIVED] |
| 005d4d2c | aTread | R | TreadField [DERIVED] |
| 005d4d34 | aBackfire | R | BackfireString [DERIVED] |
| 005d4d40 | aHeadlight | R | String_Headlight [DERIVED] |
| 005d4d4c | aBrakelight | R | BrakeLightString [DERIVED] |
| 005d4d58 | aRainlight | R | RainLight [DERIVED] |
| 005d4d64 | aBody | R | BodyField [DERIVED] |
| 005d4d6c | aHelmet | R | HelmetString2 [DERIVED] |
| 005d4d74 | aSuspension_0 | R | SuspensionString [DERIVED] |
| 005d4d80 | aDebrisD | R | Str_DebrisD [DERIVED] |
| 005d4d8c | aRwing | R | StringRWing [DERIVED] |
| 005d4d94 | aFwing | R | FwingString [DERIVED] |
| 005d4d9c | aDiscglow | R | DiscGlowString [DERIVED] |
| 005d4da8 | aRrspindle | R | RrspindleString [DERIVED] |
| 005d4db4 | aLrspindle | R | LrSpindleStr [DERIVED] |
| 005d4dc0 | aRfspindle | R | RFSpindleString [DERIVED] |
| 005d4dcc | aLfspindle | R | LfSpindleField [DERIVED] |
| 005d4dd8 | aCouldNotFindIn | R | aCouldNotFindIn [DERIVED] |
| 005d4df8 | aSlot03d_0 | R | String_Slot03d [DERIVED] |
| 005d4e04 | aUnableToSetupA_0 | R | UnableToSetupString [DERIVED] |
| 005d4e2c | aUnableToReadSS | R | UnableToReadSSString [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad3ec | dword_8AD3EC | W | SoundEffectArray [DERIVED] |
| 008ad3f0 | dword_8AD3F0 | W | Network_JoinFlag_8AD3F0 [DERIVED] |
| 008ad3f4 | dword_8AD3F4 | W | Dword_8AD3F4 [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411570 | StatusFieldCopy | copies status/state field value from global instance to vehicle slot |
| 004cef30 | sub_4CEF30 | unknown secondary initialization (called with ScoringGridBase) |
| 004d7a50 | StringSplitLoop | parses debug/trace string for logging and error reporting |
| 004d7aa0 | DebugLogWrite | writes formatted debug/trace message to log buffer |
| 004dd550 | BoundingBoxComputation | computes axis-aligned bounding box for a scene node |
| 004dd6a0 | BoundingBoxUpdate | expands existing bounding box to include a node's bounding box |
| 004dfa60 | ConditionalAudioParamSetup | sets up audio parameters conditionally for a scene node |
| 004e0c90 | UITimerTweenUpdate | UI timer/tween animation update (called with 0.0 to reset) |
| 004e2a60 | sub_4E2A60 | unknown post-load setup routine |
| 004e2ad0 | PhysicsAudioVectorUpdate | updates physics-audio vector for a wheel node pair |
| 004e2d00 | VertexClusteringLODGrouping | performs vertex clustering LOD grouping on the vehicle mesh |
| 004e3360 | sub_4E3360 | unknown secondary processing after LOD grouping |
| 0053c5b0 | StringRelocationCopy | copies string with buffer relocation, reporting errors |
| 00543fa0 | VertexBufferResourceAllocation | allocates vertex buffer resources for collision geometry |
| 005453a0 | EvaluateSceneNodeProperty | looks up child scene node by name within a parent node |
| 00545f40 | ValueGetter | retrieves a typed value from a property/state handle |
| 00547370 | ArithmeticComparison_7370 | performs arithmetic comparison operation on a value |
| 00548890 | sub_548890 | creates/retrieves a resource handle by name (returns resource ID) |
| 0054b420 | TripleFieldQuery | queries three float fields from a scene node (position/dimensions) |
| 0054bda0 | SelfRelativeStringCopy | copies a self-referencing string from scene node |
| 0054c030 | FlagFieldBitManipulation | sets/clears/tests bit flags on a field |
| 0054c110 | RenderFlagSetter | sets a render flag by index and value |
| 0054c210 | SceneGraphChildCount | returns number of child nodes in a scene graph node |
| 0054c230 | LinkedListIndexedAccessor_c230 | accesses child node by index from scene graph linked list |
| 0054e190 | CameraDistanceGetter | gets camera LOD distance property from a node |
| 0054e240 | ArrayIndexRead | reads array element by index |
| 0054fb40 | SceneNodeVisibilityToggle | toggles visibility state of a scene node |
| 005506a0 | sub_5506A0 | unknown helper (called with three zeros during wheel setup) |
| 00551830 | WideStringComparisonWalkingLinkedList | walks linked list comparing wide strings (used to match catsteer) |
| 0055b6b0 | sub_55B6B0 | file validity check (returns true if file is valid/readable) |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation wrapper (operator new) |
| 00587c20 | sub_587C20 | string comparison against vtable/type info (used to classify tire nodes) |
| 0058815f | StringFormatWithBufferOverflowCheck | formatted sprintf with buffer overflow protection |
| 00588410 | sub_588410 | string comparison helper (used to match disc glow string) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8B4 | > | 0 | catsteer child node count; controls iteration over children to find steering nodes |

**Guard interpretation:** When `this->catsteer_child_count > 0`, iterates over the first `min(count, 2)` children, searching for nodes matching the catsteer string to populate the catsteer matched array. When count == 0, the loop body is skipped entirely — no catsteer children exist in the scene graph. Additional guard: parameter `a3` (post-load-setup flag) at line 99 — if true, triggers vertex buffer allocation check and additional initialization (sub_4E2A60, sub_4CEF30). If false, skips post-load setup.
