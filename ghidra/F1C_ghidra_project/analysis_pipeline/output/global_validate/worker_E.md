=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_008AC368 | VehicleSetupBase | setup/vehicle | ptr | read/write | 49 | Struct base pointer near VehicleArray (0x8AC394). 49 refs — game setup/init functions. Stride likely 0x424. |
| DAT_008ACEA0 | ScoringGridBase | race/scoring | ptr | offset | 22 | Scoring/race position data base. Accessed by session lifecycle functions (0x0042d370 etc). |
| DAT_005EA43C | SetupDirSuffix | setup/file | int | offset | 13 | Directory path segment near 0x5EA438 (base path). Used in file I/O setup. |
| DAT_005CC79C | HashTableHead | file/hash | int | offset | 9 | Hash table entry for string lookup. Used with FUN_00587c20 (hash table find). Companion DAT_005cc7a0 at +4. |
| DAT_005C2604 | TrackNameJordan | track | string | offset | 7 | String "Jordan". Track name constant. |
| DAT_005D45E4 | SourcePath_F1_1999_2002_4 | debug | string | offset | 7 | Assert/debug source path "D:\dev\F1_1999_2002\Source\..." |
| DAT_005CD620 | StringInstance | renderer/scene | string | offset | 6 | String "Instance". Used in scene graph/object hierarchy. |
| DAT_005C26B8 | TrackNameBarcelona | track | string | offset | 5 | String "Barcelona". Track name constant. |
| DAT_0059E8FC | AccelAccumLimit | physics/dynamics | float | read | 5 | Acceleration accumulation clamping threshold. Used in FUN_004ed0f0 (accumulator capping) and physics integration. |
| DAT_005D22E0 | SourcePath_F1_1999_2002_20 | debug | string | offset | 5 | Assert/debug source path string. |
| DAT_007D0798 | RaceSetupScaling | race/init | float | read/write | 4 | Race setup scaling factor. Set to 0.05 in FUN_00404890, passed to FUN_004c2d30 for AI difficulty scaling. |
| DAT_0059EC10 | DoublePhysicsZero | physics/dynamics | double | read | 4 | Double-precision zero/comparison constant. Compared against _DAT_0059e430 in dynamics integration. |
| DAT_005CC650 | StringName | file/config | string | offset | 4 | String "Name". File/config field name. |
| DAT_005AF990 | MMX_3DNow_QuadConstant_0 | math/3dnow | qword | read | 4 | Packed floating-point constant for MMX/3DNow! math. Used in PackedFloatingMUL operations for matrix/vector transforms. |
| DAT_005E7760 | DSTOffsetSeconds | time | int | read/write | 4 | Daylight saving time adjustment in seconds. Set from (DST_end - DST_start) * 60 in timezone init. |
| DAT_0059E720 | VTable_FileStream | file | ptr | offset | 3 | VTable pointer for file stream class. Set as constructor base. |
| DAT_005C36FC | StringN | UI/text | string | offset | 3 | String "N". Gateway/UI text. |
| DAT_005C57B8 | StringMipmapLODBias | renderer/texture | string | offset | 3 | String "MipmapLODBias". D3D texture config parameter name. |
| DAT_007CFE0C | VehicleSkinOverridePath | setup/file | ptr | read | 3 | Vehicle skin override path pointer. If null, defaults to base directory. Used in vehicle skin loading. |
| DAT_005CC5AC | StringGizmo | UI/framework | string | offset | 3 | String "Gizmo". UI toolkit object type name. |
| DAT_008AB704 | FreeListTailPtr | memory | ptr | write | 3 | Free list tail pointer for memory allocator. Linked list management for collision/physics allocator. |
| DAT_005ACDC0 | InterpFactor_5ACDC0 | physics/dynamics | float | read | 3 | Interpolation/scaling factor used in physics interpolation and brake force calculation. |
| DAT_005D8AA0 | SSE_PolynomialBias | math/SSE | float | read | 3 | Polynomial evaluation bias offset. Used in SSE bezier/catmull-rom spline basis evaluation (sub_51F400, sub_51F4C0, sub_51F560). |
| DAT_005DBC08 | CubeMapFileName | renderer/texture | string | offset | 3 | String "Cubemas410". Cube map texture file name. |
| DAT_008D2AF8 | SolverBlock_8D2AF8 | dynamics/solver | double | read/write | 3 | Dynamics constraint solver matrix block. Part of LDL^T factorization workspace at 0x8D0000-0x8D9000. Zeroed (80 bytes) in sub_579CCF. |
| DAT_008D3610 | SolverBlock_8D3610 | dynamics/solver | double | read/write | 3 | Dynamics constraint solver matrix block. 128 bytes memset via sub_58BB10 in sub_579CCF. |
| DAT_008D32E8 | SolverBlock_8D32E8 | dynamics/solver | double | read/write | 3 | Dynamics constraint solver matrix block element. |
| DAT_008D48F0 | HeapAllocCursor | memory/heap | ptr | read/write | 3 | Heap allocation cursor pointer. Set from HeapAlloc result in FUN_00593dd3. Used as linear allocation cursor in memory manager. |
| DAT_0059E50C | VTable_FileMutex | file/sync | ptr | offset | 2 | VTable pointer for file synchronization/mutex class. Constructor sets *param_1 = &PTR_LAB_0059e50c. |
| DAT_0059E71C | Unknown_RendererFloat | renderer | float | read | 2 | Renderer scaling constant. Used with FUN_0040f600 and FUN_00500210 (renderer/timing code). |
| DAT_005C2710 | StringCutTrack | track | string | offset | 2 | String "CutTrack". Track config field name for shortcut/cut detection. |
| DAT_0059E93C | EngineSpeedThreshold | physics/engine | float | read | 2 | Low RPM/speed threshold for engine physics. Clamped against ZeroThreshold in engine stall detection. |
| DAT_005C3730 | Ptr_FormatStringArray | UI/text | ptr | offset | 2 | Pointer to printf format string array. Used with FUN_0058815f for message formatting in UI. |
| DAT_005C40E8 | StringNormal | UI/text | string | offset | 2 | String "Normal". File/config field value. |
| DAT_007CD1A0 | AudioMixThreshold | audio | float | read/write | 2 | Audio mixer channel threshold. Initialized to 0.0, compared against controller values for audio channel clamping. |
| DAT_007CD100 | AudioPanInitialValue | audio | float | read/write | 2 | Audio pan/balance initial value. Set to 0.0 with companion at +4 set to 1.0 (1065353216). |
| DAT_007CA3B8 | AudioControllerIdx_7CA3B8 | audio/midi | int | read | 2 | Audio controller body index. One of ~30 global addresses used as DLS/MIDI controller value identifiers. FUN_00452810 maps parameters to these addresses. |
| DAT_007CCBC4 | AudioControllerIdx_7CCBC4 | audio/midi | int | read | 2 | Audio controller body index in FUN_00452b10 chain. |
| DAT_007CA46C | AudioControllerIdx_7CA46C | audio/midi | int | read | 2 | Audio controller body index. Compared in FUN_004537b0 controller value copy chain. |
| DAT_005C5BCC | FormatString_1_3f | UI/text | string | offset | 2 | Format string "%1.3f" for float display. |
| DAT_007CEE40 | ConfigFieldHandler | setup/config | int | read/write | 2 | Configuration field save/load handler. Copied from config UI struct in FUN_00461900. |
| DAT_0059F1F4 | HeadingAngleOffset | renderer/vehicle | float | read | 2 | Heading angle offset in radians. Added to atan2 result for vehicle/camera orientation in FUN_00541f60. |
| DAT_007D0110 | CurrentCarDisplayIndex | game/UI | int | read | 2 | Current car display index. Compared with DAT_007d011C in UI display code (sub_4735B0). |
| DAT_005ABF88 | VTable_HUDTimer | UI/hud | ptr | offset | 2 | VTable pointer for HUD/timer display class. FUN_0048c070 sets *param_1 = &PTR_FUN_005abf88. |
| DAT_005CC634 | StringSoundLostFocus | audio/config | string | offset | 2 | String "SoundLostFocus". Audio config file key name. |
| DAT_005CCE60 | FormatString_S | UI/text | string | offset | 2 | Format string "%s". String output format. |
| DAT_005CD60C | StringLODIn | renderer | string | offset | 2 | String "LODIn". Level-of-detail transition marker. |
| DAT_005ACD40 | TireGripScaleFactor | physics/tire | float | read | 2 | Tire grip scaling factor indexed by tire compound. Used with _acd3c, _acd44, _acd48 for per-compound grip. |
| DAT_005D2A74 | StringAvgStartPosition | file/gdb | string | offset | 2 | String "AvgStartPosition". GDB track config field name. |
| DAT_005D2EA4 | StringDotIni | file/config | string | offset | 2 | String ".ini". File extension constant. |
| DAT_005D3960 | StringMasFile | file | string | offset | 2 | String ".mas" or "MasFile". Archive file extension constant. |
| DAT_005D4CE0 | SourcePath_F1_1999_2002_6 | debug | string | offset | 2 | Assert/debug source path string. |
| DAT_005D67C4 | FlavorColorBlue | renderer/flavor | int | offset | 2 | Blue channel value in flavor color table. Indexed by param_1 case in FUN_004f8280. |
| DAT_008AFE72 | AudioInitSuccessFlag | audio | byte | read/write | 2 | Audio init success flag. Set to 1 when FUN_0055c060 returns -2 (initialized). |
| DAT_005D7854 | PtrFunc_GfxCallback | renderer | ptr | read | 2 | Function pointer for graphics callback. Called indirectly via (*(code *)PTR_FUN_005d7854)(). |
| DAT_005AF938 | MMX_3DNow_QuadConstant_1 | math/3dnow | qword | read | 2 | Packed floating-point constant for MMX/3DNow! math. Used in vector normalization (sub_52193C). |
| DAT_005DA738 | AnimationWeightScale | renderer/animation | int | read | 2 | Animation weight/scale table. Indexed by vertex animation lookup code in FUN_00530050 and FUN_00530840. |
| DAT_008B8DF8 | SoundBufferFlags | audio/miles | int | read | 2 | Sound buffer creation flags (0x40008). Passed to FUN_00542950 for Miles Sound System buffer creation. |
| DAT_005E5074 | FormatStringD | UI/text | string | offset | 2 | Format string "%d" for integer display. |
| DAT_008D2340 | SolverBlock_8D2340 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block. Part of LDL^T factorization workspace. |
| DAT_008D2C20 | SolverBlock_8D2C20 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D2B20 | SolverBlock_8D2B20 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D2FE0 | SolverBlock_8D2FE0 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D3280 | SolverBlock_8D3280 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D34D0 | SolverBlock_8D34D0 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D3428 | SolverBlock_8D3428 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D37E8 | SolverBlock_8D37E8 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D35A0 | SolverBlock_8D35A0 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D35B8 | SolverBlock_8D35B8 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D3478 | SolverBlock_8D3478 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D37A8 | SolverBlock_8D37A8 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_008D3970 | SolverBlock_8D3970 | dynamics/solver | double | read/write | 2 | Dynamics constraint solver matrix block element. |
| DAT_005E6530 | VTable_FileSystem | file | ptr | offset | 2 | VTable pointer for file system class. |
| DAT_008D4062 | TimeZoneDSTFlag | time | byte | read | 2 | Time zone daylight saving time flag. 0=no DST, 1=DST active. Part of Windows TIME_ZONE_INFORMATION struct. |
| DAT_005B9BB8 | VTable_StreamBuffer | file | ptr | offset | 2 | VTable pointer for stream/buffer class. Constructor sets *this = &DAT_005b9bb8, with companion vtables PTR_FUN_005b9bb4 and PTR_LAB_005b9bac. |
