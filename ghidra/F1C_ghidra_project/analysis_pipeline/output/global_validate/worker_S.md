=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005c3280 | ConfigParseTokenList | setup | char[] | read | 28 | String token table used by config file parser (FUN_00587c20 substring search). Part of a group at 0x005c30ac-0x005c30b8. Used by UI/config functions. |
| DAT_005c30b4 | ConfigSubstringToken | setup | char[] | read | 16 | String delimiter token used with FUN_00587c20 for config file substring search/parsing. Part of delimiter group with DAT_005c30b0, DAT_005c30b8. |
| DAT_0059e7e0 | LookupThreshold_14 | game_logic | double | read | 9 | Upper threshold in 14-element comparison chain (0x0059e788-0x0059e7e0). FUN_00413820/FUN_004139c0 compare param against chain to map value to output index (0x0-0x10). Related to engine/temperature mapping. |
| DAT_005e7898 | DefaultBufferDescriptor | audio | struct | offset | 8 | Default buffer/stream descriptor struct. Used by audio/streaming functions (0x0058afe1, 0x0058c255, 0x0058cf35) when buffer handle is 0xFFFFFFFF. Bit flags at offset+4 tested for state transitions. |
| DAT_0059e86c | FloatToInt64Scale | physics_math | float | read | 7 | Scale factor for float-to-int64 conversion. Used in FUN_004b9b80: multiplies floats then converts via __ftol. Also used as threshold in AI racing line selection (FUN_00424e70). |
| DAT_007ce058 | Unknown_UI_Singleton | UI | struct | offset | 6 | Opaque struct pointer passed to FUN_0049d150. Used by UI/window manager functions (0x0049afe0, 0x0049b030, 0x0049f070). Initialization/teardown context. |
| DAT_0059e6ec | ShortIntToWorldScale | physics_math | float | read | 5 | Converts short int vertex data to world-space floats. FUN_004b2580 multiplies short[3] by this factor. Also used as grid sampling step in spatial query (FUN_0040e480 nested loops over 5x5x5 grid). |
| DAT_0059e808 | EngineTempThreshold | engine | float | read | 5 | Threshold in engine temperature comparison chain (FUN_0041a500). Also used as pit timer delta in FUN_0042a3d0 to compute pit window timing. |
| DAT_005c6888 | Key_PolePositions | driver_db | char[] | offset | 5 | String constant "PolePositions". Used as lookup key with sub_486F30 in career/driver stats database. Part of driver stats field registration. |
| DAT_005e9ad0 | CrtFPEExceptionFlag | CRT | int | read | 5 | MSVC CRT floating-point exception mode flag. Checked by __cintrindisp2, FUN_0059163b, FUN_0059168f. When 0: normal math path. When non-zero: sets error code 0x21 via FUN_0058afcf and calls FUN_00591e66. |
| DAT_007ce8a4 | ConfigByte_PitSettings | setup | byte | read | 4 | Configuration byte controlling pit stop settings. Read in FUN_00438cc0 and written to struct field +0x75. Used with FUN_0049e170 for text composition with offset 0x3e. |
| DAT_007cec54 | ReconPitClosed | race | int | read/write | 4 | *** ALREADY IN docs/12 *** Recon pit stop window closed timer. Controls pit window visibility timing. Used by race/pit logic functions. |
| DAT_007cf8a8 | RenderThrottleFrames | renderer | int | read | 4 | Frame throttle counter for render/LOD updates. Functions FUN_004ce3e0 and FUN_004ce930 check `2 < DAT_007cf8a8` to limit update frequency. Reset every 0x14 frames via DAT_007c5698 modulo check. |
| DAT_005dc1d8 | Err_CouldNotFindResource | fileio | char[] | offset | 4 | Error string "Could Not Find Resource..." used by resource loader. |
| DAT_0059e634 | VTable_SceneNodeChain | renderer | ptr | offset | 3 | Vtable table entry in scene node chain. Used by FUN_00408520/FUN_0040ac40/FUN_0040b5a0 to walk through vtable entries (PTR_FUN_0059e60c, PTR_LAB_0059e634, PTR_LAB_0059e678, PTR_LAB_0059e6ac). |
| DAT_0059e97c | LapTimeDeltaScale | race | float | read | 3 | Scale factor for lap time delta calculation. Used in FUN_0042a180 to compute AI push lap timing: `local_4 * DAT_0059e97c + lapRatio`. Also in FUN_004c7f30 for race phase 8 time scaling. |
| DAT_007ccfb0 | RenderStateID_S | renderer | int | read/write | 3 | Render state block identifier (initialized to 8 in FUN_0044c8c0). Compared in FUN_00452810 state block lookup. Part of ~30 render state blocks (DAT_007ca490..DAT_007cd188 family). |
| DAT_007d0a44 | GameModePlayerCount | game | byte | read/write | 3 | Player count or player index for game mode. Written from param_1+100 by UI config reader (FUN_00461900). Clamped between DAT_007d0a4c and DAT_007d0a50 in FUN_00463ef0. |
| DAT_005a4450 | VTable_HUDTextNode | UI | ptr | offset | 3 | Vtable entry for HUD text display node. Used by UI constructor/destructor chain (FUN_00476100, FUN_004761e0, FUN_0048fc50). Part of vtable inheritance (off_5A4464 -> off_5A4450 -> off_5A443C). |
| DAT_005cd614 | Key_MeshFile | renderer | char[] | offset | 3 | String constant "MeshFile". Config file key used by mesh loader (FUN_004a4ed0, FUN_0055a910, FUN_0055b8c0). |
| DAT_008ad39c | RenderBufferID_2 | renderer | int | read/write | 3 | Render buffer/context handle for index 2. Part of switch table (0=8AD3A8, 1=8AD398, 2=8AD39C, 3=8AD3A0, 4=8AD3A4, 5=8AD3A8). Used with FUN_005539f0 for deallocation and FUN_00553700 for setup. |
| DAT_005d8a80 | PolyCoeff_3_Hermite | math_util | __m128 | read | 3 | SSE vector polynomial coefficient (4th-order). Used in Hermite/cubic interpolation functions (sub_51F200, sub_51F2C0, sub_51F350). Combined with xmmword_5D8A70, xmmword_5D8A60, xmmword_5D8A50 to evaluate polynomial of float parameter. |
| DAT_005b83f8 | zlib_LengthExtraBits | compression | byte[] | read | 3 | zlib deflate extra bits lookup table for length codes. Used by deflate decoder (sub_5365D0, sub_536A70, sub_539200). Indexed by distance/length value during Huffman decoding. |
| DAT_008d23e0 | DynamicsMatrix_Block4 | dynamics | double | read/write | 3 | Dynamics constraint solver matrix block (case 4). Part of LDL^T factorization workspace at 0x008d0000. Used by FUN_00575bbd (factorization), initialized to identity in FUN_00578f76, zeroed in FUN_00579ccf. |
| DAT_008d2b70 | DynamicsMatrix_Block13 | dynamics | double | read/write | 3 | Dynamics solver matrix block (case 13). Initialized to 0.0 in identity init (FUN_00578f76 case 0). Zeroed in FUN_00579ccf. Used in LDL^T factorization (FUN_00575bbd). |
| DAT_008d3450 | DynamicsMatrix_Block29 | dynamics | double | read/write | 3 | Dynamics solver matrix block (case 29). Zeroed in FUN_00579ccf. Used in LDL^T factorization (FUN_00575bbd). |
| DAT_008d5a44 | CmdLinePtr | CRT | char* | read/write | 3 | Stores result of GetCommandLineA() during startup. Used by FUN_00592a9c to parse command-line tokens and FUN_00592bad for module path resolution. |
| DAT_005be694 | Key_AIDatabaseFile | ai_db | char[] | offset | 2 | String constant "ai_database_file" or similar. Config key used by AI database loader. |
| DAT_0059e664 | RenderTransformScale | renderer | float | read | 2 | Scale factor in render transformation pipeline. Used by FUN_00409a00 (scene graph transform) and FUN_004e5470 (render coordinate transform). |
| DAT_0059e798 | LookupThreshold_11 | game_logic | double | read | 2 | Threshold 11 in 14-element comparison chain (FUN_00413820/FUN_004139c0). Maps intake value to output index. |
| DAT_0059e860 | AIDifficultyScaleFactor | AI | float | read | 2 | Scale factor for AI difficulty calculation. FUN_00424750: `(AIDifficultySlider - 70) * DAT_0059e860 * DAT_0059e7f8 + DAT_0059e7fc`. Also used in FUN_00462ff0 for braking speed calculation. |
| DAT_007d00f4 | GameStateMin | game | int | read | 2 | Minimum clamp value for GameState (DAT_007d00ec). Used in FUN_004c1050 state initialization: `if (GameState < GameStateMin) GameState = GameStateMin`. |
| DAT_005c3f8c | Unknown_Ptr_5C3F8C | unknown | ptr | read | 2 | Pointer to unknown struct. Used only by FUN_00432a70 and FUN_00432bf0. |
| DAT_007ca498 | RenderStateMinThreshold_498 | renderer | float | read/write | 2 | Render state block minimum float threshold. Initialized to 0.0 in FUN_0044c620 (paired with DAT_007ca49c = 1.0f). Used in FUN_004537b0: if value <= threshold, clamp to 0.0f. |
| DAT_007cd150 | RenderStateThreshold_150 | renderer | float | read/write | 2 | Render state block float threshold. Initialized to 0.0 in FUN_0044cab4 (paired with DAT_007cd154 = 1.0f). Used in FUN_004537b0 to clamp incoming vehicle setup values. |
| DAT_007ccfa0 | RenderStateID_CFA0 | renderer | int | read/write | 2 | Render state block ID (initialized to 0x6d in FUN_0044d1c0). Compared in FUN_00452810 state block lookup. |
| DAT_007ccc38 | RenderStateID_C38 | renderer | int | read | 2 | Render state block identifier. Compared in FUN_00452b10 state block lookup (among ~25 siblings). |
| DAT_007ca548 | RenderStateID_548 | renderer | int | read | 2 | Render state block identifier. Used in FUN_004537b0 and FUN_00454350 render state comparisons. |
| DAT_0059f00c | VTable_CameraNode | UI | ptr | offset | 2 | Vtable entry for camera/scene node UI element. Used by FUN_004583b0 (constructor, initializes fields like zoom 0x42700000, speed 0x43fa0000) and FUN_004584a0 (destructor). |
| DAT_0059f11c | ContactNormalDotThreshold | collision | float | read | 2 | Threshold for contact normal dot product. Used in FUN_004a5fa0 collision response: compared against surface normal dot velocity to determine contact type. |
| DAT_007d1004 | Unknown_Word_7D1004 | UI | word | read | 2 | 16-bit value used by UI functions (FUN_00463160, FUN_00463e20). |
| DAT_005c6a94 | ConfigFilterString | setup | char[] | offset | 2 | ASCII string config filter/token. Used by UI/config functions. |
| DAT_005aba18 | VTable_ListBoxNode | UI | ptr | offset | 2 | Vtable entry for list box UI element. Used by FUN_00487660 (constructor) and FUN_004876b0 (destructor). |
| DAT_005cc4f8 | StringDelimiter_Brace | setup | char[] | offset | 2 | String delimiter/token used with FUN_00587c20 for parsing. Paired with DAT_005cc4f4. Used in brace-matching parser (FUN_00492030). |
| DAT_007ce240 | UIDrawDetailFlag | UI | int | read | 2 | Flag enabling additional UI detail rendering. Checked in FUN_0049b370: when non-zero, enables extra rendering elements. |
| DAT_005cd49c | Ext_Anm | renderer | char[] | offset | 2 | String extension ".anm" for animation files. Used by animation loader (FUN_004a3910, FUN_004d0110). |
| DAT_005acc94 | VertexShortClampMax | renderer | float | read | 2 | Maximum clamp value for vertex coordinate to short conversion. FUN_004b2310/FUN_004b31a0: if value > DAT_005acc94, output 0x7fff. Paired with DAT_005acc90 (min clamp, output 0x8001). Scale factor DAT_0059e714 applied for normal range. |
| DAT_005d2ad8 | Key_TotalRacesWith | game | char[] | offset | 2 | String key "TotalRacesWith...". Used by game options UI (FUN_004c18b0, FUN_004c1e80). |
| DAT_005d2950 | Key_GameOptRaceLen | game | char[] | offset | 2 | String key "GameOptRaceLen...". Used by game options UI (FUN_004c18b0, FUN_004c1e80) for race length option. |
| DAT_005d348c | CollisionPenetrationThreshold | collision | float | read | 2 | Collision penetration distance threshold. FUN_004cbdd0: if corrected squared distance < threshold, skip penetration resolution. Used for object separation in collision response. |
| DAT_005acf60 | TextColorDefault | UI | float | read | 2 | Default text color/alpha parameter. Used by UI text rendering (FUN_004d98a0, FUN_004d9690) as color component for HUD text. |
| DAT_008af570 | InputMappingTable | input | int[225] | read/write | 2 | Input/control mapping table (45 entries x 5 ints = 225 ints). Initialized in FUN_004f6b40: each entry has [-2]=0, [-1]=-1, [0]=-1, [1]=-1, [2]=0. Controls/input device bindings. |
| DAT_005ec48c | NetworkPortHandle | network | int | read | 2 | Network/game port handle. Passed to FUN_004f9200 (packet send). |
| DAT_005adbb8 | VTable_VideoDecoder | video | ptr | offset | 2 | Vtable entry for video decoder node. Used by YUV video playback (FUN_0050a7e1 constructor, FUN_0050b830 destructor). Checks for 'YVYU' fourcc. |
| DAT_005b06c8 | CombinatoricsLookupTable | math_util | int[] | read | 2 | Lookup table for combinatorics/permutation generation. Used by FUN_0051e1ef (lexicographic permutation) and FUN_0051e512 (iterative combinatorial generation). |
| DAT_005b0858 | Err_InvalidLiteralLength | compression | char[] | offset | 2 | Error string "Invalid literal/length" for deflate/zlib decoder (FUN_00529b2c, FUN_0052c334). |
| DAT_005dbbd4 | Err_IncorrectMassFile | setup | char[] | offset | 2 | Error string "Incorrect mass file" used by vehicle/physics file parser (FUN_0053cbc0, FUN_0055fc40). |
| DAT_005dd848 | ShadowProjectionScale | renderer | float | read | 2 | Scale factor for shadow volume projection. Used by renderer shadow view setup (FUN_00560c10, FUN_00560fe0) to compute shadow frustum bounds. |
| DAT_008d2b00 | DynamicsMatrix_Block12 | dynamics | double | read/write | 2 | Dynamics constraint solver matrix block (case 12). Part of LDL^T factorization workspace. Initialized to 0.0 in identity init, zeroed in clear-all. |
| DAT_008d24a8 | DynamicsMatrix_Block8 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 3). Initialized to 0.0 in identity init (FUN_00578f76 case 3). Used in LDL^T factorization (FUN_00575bbd). |
| DAT_008d3890 | DynamicsMatrix_Block34 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 34). Zeroed in FUN_00579ccf with sub_58BB10(&dbl_8D3870, 0, 272) covering this block. Used in LDL^T factorization. |
| DAT_008d2628 | DynamicsMatrix_Block10 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 10). Part of 0x008d0000-0x008d9000 LDL^T workspace. Used by factorization and zero-init. |
| DAT_008d38b8 | DynamicsMatrix_Block35 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 35). Part of LDL^T factorization workspace. Used by FUN_00575bbd and FUN_00578f76. |
| DAT_008d29e0 | DynamicsMatrix_Block11 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 11). Part of LDL^T workspace. Used by factorization and zero-init. |
| DAT_008d31e8 | DynamicsMatrix_Block25 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 25). Part of 0x008d0000 LDL^T workspace. |
| DAT_008d3430 | DynamicsMatrix_Block28 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 28). Part of LDL^T factorization workspace. |
| DAT_008d37f0 | DynamicsMatrix_Block33 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 33). Part of LDL^T workspace. Includes sub-block at 0x008d3870 (size 272 bytes) for case 34. |
| DAT_008d36e0 | DynamicsMatrix_Block31 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 31). Part of LDL^T factorization workspace. |
| DAT_008d3660 | DynamicsMatrix_Block30 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 30). Part of LDL^T workspace. |
| DAT_008d3838 | DynamicsMatrix_Block32 | dynamics | double | read/write | 2 | Dynamics solver matrix block (case 32). Part of LDL^T factorization workspace. |
| DAT_008d3728 | DynamicsMatrix_Block32b | dynamics | double | read/write | 2 | Dynamics solver matrix block (adjacent to Block32). Part of LDL^T factorization workspace. |
| DAT_005e673c | CRT_FloatConvertFuncPtr | CRT | ptr | read/write | 2 | MSVC CRT floating-point conversion function pointer table entry. Set to FUN_0058bccf. Part of group with __cfltcvt, __fassign at 0x005e6730-0x005e6744. |
| DAT_005e7534 | CRT_FPDivisionConst | CRT | tbyte | read | 2 | MSVC CRT 80-bit long double constant used in floating-point division (fdiv) emulation. Used by FUN_005910b6 and sub_59136E for software FP division. |
| DAT_005e9988 | HeapManagerLoopHead | CRT | ptr | read | 2 | Heap memory manager linked list head pointer. Used by CRT heap functions (FUN_00594a5e free with VirtualFree/HeapFree, FUN_00594c12 malloc with heap block iteration). |
| DAT_005b9d5c | VTable_StdLengthError | CRT | ptr | offset | 2 | MSVC C++ std::length_error vtable. Used by exception constructor FUN_0059af50 (sets vtable, calls FUN_0059ae7d base init). |
