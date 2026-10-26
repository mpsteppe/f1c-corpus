=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| DAT_008B009C | ConversionState | renderer | int | write,read | 31 | State variable for texture/color format conversion pipeline. Written by setter (FUN_00507473), read by vertex color transform functions using ROUND/DAT_0059fec8 scaling. |
| DAT_007CE2A4 | Unknown_Session_7CE2A4 | session | ptr | offset | 17 | Module-level pointer in session/game state module. Referenced by 17 functions in 0x0042xxxx range (game state lifecycle). No source excerpts available — open offset access pattern. |
| DAT_008D44B8 | DynamicsSolver_BasePtr | dynamics | ptr | offset | 10 | Part of dynamics constraint solver workspace (0x8D0000 range). Referenced by 10 functions including thunks to FUN_00599958. Likely a struct base pointer within the solver matrix workspace. |
| DAT_005AF988 | PackedMathOne | math_util | qword | read | 8 | MMX/3DNow packed floating-point constant (value 1.0). Used in PackedFloatingSUB for range reduction in sin/cos approximation (FUN_005215db, FUN_00521895, FUN_005219e1). |
| DAT_005C30AC | StrDelimiter_Period | file_formats | string | offset | 7 | String delimiter (likely "." or ",") used in string parsing. Referenced by FUN_004236f0 (quote-delimited token parsing) and FUN_00559d10/FUN_00559d80 (string comparison). |
| DAT_005C57F4 | StrColor | renderer | string | offset | 6 | String literal "Color" used in renderer/UI functions (FUN_004562f0, FUN_004572b0, FUN_004585e0, FUN_004ca480, FUN_0055a060, FUN_0055a500). |
| DAT_008D47E1 | CharClassTable_byte | file_formats | byte | read | 6 | Character classification table entry (part of ctype table at 0x8D47E0). Used in FUN_00592c46 (text/token parsing, checks flag bit 4), FUN_00596e0f (char type test), FUN_00596e40 (code page init, XOR table setup). |
| DAT_005C2638 | StrTrackSuzuka | track | string | offset | 5 | Track name string "Suzuka". Referenced by track/scene functions. |
| DAT_005C57D0 | StrSize | renderer | string | offset | 5 | String literal "Size" used in renderer functions (FUN_004562f0, FUN_004572b0, FUN_004585e0, FUN_00493060, FUN_0055a060). |
| DAT_008B6C20 | RendererStateFlag | renderer | qword | read,write | 5 | Renderer module state flag. Zeroed by FUN_0053c2c0 (init), read by FUN_0055d900/FUN_0055da50 (vertex processing/rendering pipeline). |
| DAT_007CE7CC | ControlMapping_UI7 | UI | dword | read | 4 | Control mapping byte for UI menu navigation. Part of a table with DAT_007CE6F4, 007CE73C, etc. Used in FUN_00438cc0 (control assignment) and FUN_0049E170 (UI text rendering with offset calculation). |
| DAT_005C59D4 | StrPosition | renderer | string | offset | 4 | String literal "Position" used in renderer/UI functions. |
| DAT_008AC050 | Unknown_SceneSetup_8AC050 | setup | ptr | offset | 4 | Scene/setup module variable. Referenced by FUN_004C03F0, FUN_004C0B70, FUN_004C18B0, FUN_004C1E80 (scene/season setup functions). |
| DAT_008B8CF0 | RendererBrightness | renderer | float | read,write | 4 | Renderer brightness/gamma setting. Set to ~0.333 (0x3EAAB368) for mode 8 or 0.5 (0x3F000000) for mode 4 in FUN_0053C360 (init). Read by FUN_00553370/FUN_00553700 (render state setup). |
| DAT_007CE608 | DataDirectoryPath | file_formats | ptr | read | 3 | Path string pointer for data directory. Used in FUN_004B7300 (file loading), falls back to DAT_005EA438 if NULL. |
| DAT_005C3160 | TrackConfigByte_5C3160 | track | byte | read,write | 3 | Track configuration byte loaded from setup data. Used in AI functions: FUN_00424E70 (steering calculation), FUN_00425920 (AI follow/target), FUN_00426CF0 (AI speed/braking). |
| DAT_007CE6D0 | MultiplayerOptionFlag | network | dword | read | 3 | Session option flag packed into multiplayer packet bitfield. Used in FUN_004D59B0 alongside EngineWearMode/TireModelMode for multiplayer session handshake. |
| DAT_005C58B8 | StrShaderFlags | renderer | string | offset | 3 | String literal for shader/effect flags. Used in renderer effects (FUN_00456670, FUN_00457670, FUN_00458A60). |
| DAT_005C6A28 | StrCrashOutline | game_logic | string | offset | 3 | String literal for crash/replay text overlay. Used in FUN_0046B5F0, FUN_00475150, FUN_0047C360. |
| DAT_007CEC90 | VehicleLoadState | game_logic | dword | read,write | 3 | Vehicle loading completion flag. Set to 0 after vehicle loading finishes in FUN_004B70B0. Part of session startup sequence. |
| DAT_008AD38C | ResourceHandle_1 | renderer | dword | read | 3 | Resource handle/index in array (indexed by switch: 0=DAT_008AD388, 1=this, 2=DAT_008AD390, 3=DAT_008AD394). Freed by FUN_0053D130. |
| DAT_005AF638 | AudioResampleCoeff2 | audio | float | read | 3 | Audio interpolation filter coefficient. Used in sample rate conversion functions (FUN_00515303, FUN_00515417) along with DAT_005AF63C and DAT_005AF634 for resampling. |
| DAT_005DA7A0 | StrVersionString_1_13 | math_util | string | offset | 3 | String literal "1.13" used in renderer/D3D init and math functions. |
| DAT_008D21D8 | DynamicsSolver_DiagBlock1 | dynamics | double | read,write | 3 | Diagonal block element in dynamics constraint solver matrix (LDL^T factorization). Part of the 0x8D0000 solver workspace. Set to 1.0 by identity initialization, zeroed by zero-init. |
| DAT_008D3338 | DynamicsSolver_Block64kB | dynamics | double | read,write | 3 | Constraint solver matrix block (64-byte stride). Used in LDL^T factorization, identity initialization (FUN_00578F76 case 4), and zero initialization (FUN_00579CCF memset to 0). |
| DAT_008D3210 | DynamicsSolver_Block64kC | dynamics | double | read,write | 3 | Constraint solver matrix block (64-byte stride). Zeroed by FUN_00579CCF, identity-initialized per solver node by FUN_00578F76. |
| DAT_005E6C50 | MathConst_PI_2 | math_util | tbyte | read | 3 | Extended-precision (10-byte) math constant — likely PI/2 or similar. Used in MSVC CRT math functions: FUN_00588212 (log2), FUN_0058858D (fpatan/asin), FUN_005894BD (fpatan/acos). |
| DAT_005BE41C | StrDevicePath | setup | string | offset | 2 | Device path string (e.g. "\Device\F1_1999_2002"). Used in initialization functions (FUN_004024F0, FUN_004040A0). |
| DAT_005EA550 | Unknown_GameState_5EA550 | game_logic | dword | read,write | 2 | Game state handler variable. Read by FUN_00409440 (game state switch/case handler with SessionType check). |
| DAT_0059E7B0 | LODDistanceThreshold_8 | renderer | double | read | 2 | LOD/viewport distance comparison threshold. FUN_00413820/FUN_004139C0 compare param_3 against chain of thresholds (0x59E7B0, 0x59E7B8, ..., 0x59E7E0) to select camera/display mode index. |
| DAT_005C317C | StrSuspension | file_formats | string | offset | 2 | String literal "Suspension" for .svm/.hdv file field name parsing. |
| DAT_007C9081 | EngineModeFlag | game_logic | byte | read | 2 | Engine mode flag (0=standard, 1=alternate). Used in FUN_0049D070 to select rendering path. Checked alongside DAT_007C54E0+13000. |
| DAT_007C741C | LinkedListTail_7C741C | game_logic | dword | write | 2 | Tail pointer in linked list management block (0x7C73E8-0x7C7424 range). Part of allocator/object tracker zeroed by FUN_00431C00, freed by FUN_00431C70. |
| DAT_005C445C | StrFileVersion | file_formats | string | offset | 2 | File version string (e.g. "Ver: 0.06 This file..."). Used in file format parsers. |
| DAT_007CCCB8 | UIBrightness_CCCB8 | UI | float | read,write | 2 | UI brightness/contrast slider value. Set to 0 by FUN_0044C9F4. Read by FUN_004537B0 which copies from vehicle struct +0x1154 with min-clamp to 0 (DAT_0059E440). |
| DAT_007CCF6C | UIColorBias_CCF6C | UI | float | read,write | 2 | UI color bias value. Set to 0 by FUN_0044D100 alongside -1.0 constant. Read by FUN_004537B0 as color component from vehicle struct. |
| DAT_007CCC68 | UIColorConfigHandle | UI | dword | read | 2 | Color configuration struct handle. Used in FUN_00452B10 color matching table (compared against parameter to select which color config struct pointer to use). |
| DAT_007CCFD8 | UIColorValue_CCFD8 | UI | dword | read | 2 | UI color/compositing parameter value. Read by FUN_004537B0 as display configuration. |
| DAT_005C5A24 | StrOrientationFF | renderer | string | offset | 2 | String literal for fullscreen orientation/effect parameter. |
| DAT_005C5E68 | Unknown_Renderer_5C5E68 | renderer | dword | read | 2 | Renderer module variable. No source excerpts available for analysis. |
| DAT_007D0EC4 | SessionConfigValue_7D0EC4 | session | dword | read,write | 2 | Session configuration value. Set during config parsing in FUN_00461900 (reads from config struct field). Used/cleared in FUN_00463F70. |
| DAT_0059F878 | VTable_59F878 | renderer | ptr | offset | 2 | Object vtable pointer. Used in constructor FUN_0046A220 and destructor FUN_0046A270 with standard vtable assignment pattern. |
| DAT_005AB8C0 | VTable_5AB8C0 | renderer | ptr | offset | 2 | Object vtable pointer. Used in constructor FUN_00485E30 and destructor FUN_00485EB0 with standard vtable assignment pattern. |
| DAT_005CC210 | StrExtension_c | file_formats | string | offset | 2 | String literal ".c" used in file type detection. Compared in FUN_0048F9F0/FUN_004901A0 against other string constants to determine file type (0=c, 1=cc210, 2=other). |
| DAT_005ACAAC | VTable_5ACAAC | renderer | ptr | offset | 2 | Object vtable pointer. Used in constructor FUN_00499C50 and destructor FUN_00499CE0 with linked-list cleanup pattern. |
| DAT_005CD46C | StrActor | renderer | string | offset | 2 | String literal "Actor" used in object/scene functions. |
| DAT_005D1898 | StrReconPitOpen | UI | string | offset | 2 | String literal "ReconPitOpen" for UI/options menu field identification. |
| DAT_005D2B04 | StrAbortedSeasons | UI | string | offset | 2 | String literal "AbortedSeasons" for game option file field. Used in scene/setup functions. |
| DAT_005D298C | StrGameOptQualify | UI | string | offset | 2 | String literal "GameOptQualify" used in game option/setup file parsing. |
| DAT_005EA3F0 | RaycastMaxIterMult | collision | int | read | 2 | Raycast iteration limit multiplier. Used in FUN_004E9CA0 as iteration bound (DAT_005EA3F0 * 2) for physics collision raycasting loop. |
| DAT_005D46F8 | VTable_5D46F8 | renderer | ptr | offset | 2 | Object vtable/function pointer table. Referenced by FUN_004D5F70 and FUN_00565AA0. |
| DAT_005AD208 | LifetimeClampThreshold | game_logic | double | read | 2 | Lifetime calculation clamp threshold. FUN_004EE150 clamps computed lifetime to this value (or F32_MAX). FUN_00541500 uses SQRT of this for physics param setup. |
| DAT_007CF35C | ForceFeedbackGain | game_logic | float | read | 2 | Force feedback gain multiplier. Used in FUN_004F8440 (force feedback force calculation) and FUN_004F87C0 (effect setup, multiplied by param_4 for effect magnitude). |
| DAT_005ADB60 | Unknown_DInput_5ADB60 | network | double | read | 2 | COM/DirectInput interface constant. Used in FUN_0050210E (DirectInput/joystick enumeration) and FUN_00513482 (audio encoding). Unclear specific role. |
| DAT_005B0488 | JpegHuffmanTable_5B0488 | file_formats | dword | read | 2 | JPEG decoder Huffman table constant. Used in FUN_0051AF57/FUN_0051B154 which implement Huffman decoding for JPEG image data (bit shifts, table lookups at +0xD4 offsets). |
| DAT_005D9330 | PackedMathSinCosC0 | math_util | qword | read | 2 | MMX/3DNow packed floating-point constant for sin/cos polynomial approximation. Used in FUN_005295E0/FUN_00529700 as one of the polynomial coefficients (with DAT_005D92D8, 005D9320, 005D9328, 005D9338). |
| DAT_005DBC14 | StrErrorOpeningMa | file_formats | string | offset | 2 | Error message string "Error opening ma..." for math/scene file operations. |
| DAT_005DC454 | StrIllegalSceneFile | file_formats | string | offset | 2 | Error message string "Illegal scene fi..." for scene file loading failures. |
| DAT_008D25F8 | DynamicsSolver_DiagBlock5 | dynamics | double | read,write | 2 | Diagonal block in dynamics constraint solver matrix (case 0 identity init). Accessed by LDL^T factorization (FUN_00575BBD) and identity initialization (FUN_00578F76). |
| DAT_008D3880 | DynamicsSolver_DiagBlock6 | dynamics | double | read,write | 2 | Diagonal block in dynamics solver matrix. Zeroed in cases 0-2, set to 1.0 in case 3-4 of identity init (FUN_00578F76). |
| DAT_008D2C28 | DynamicsSolver_BlockCol4 | dynamics | double | read,write | 2 | Column block in dynamics constraint solver matrix. Written by LDL^T factorization, zeroed/identity-initialized by FUN_00578F76. |
| DAT_008D2D48 | DynamicsSolver_BlockCol5 | dynamics | double | read,write | 2 | Column block in dynamics solver matrix. Same access pattern as surrounding 0x8D2xxx solver blocks. |
| DAT_008D2C50 | DynamicsSolver_BlockCol6 | dynamics | double | read,write | 2 | Column block in dynamics solver matrix. Zeroed in cases 0-2 of identity init. |
| DAT_008D3408 | DynamicsSolver_BodyBlock1 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D3xxx range, larger stride). Accessed by LDL^T factorization and identity init per solver node. |
| DAT_008D2D98 | DynamicsSolver_BlockCol7 | dynamics | double | read,write | 2 | Column block in dynamics solver matrix. Zeroed/identity-initialized alongside surrounding blocks. |
| DAT_008D31F0 | DynamicsSolver_BlockBody2 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D31F0). Part of constraint solver workspace. |
| DAT_008D36C8 | DynamicsSolver_BlockBody3 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D36C8). Accessed by LDL^T factorization. |
| DAT_008D3918 | DynamicsSolver_BodyBlock7 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D3918). Part of solver workspace cleared by FUN_00579CCF. |
| DAT_008D3470 | DynamicsSolver_BodyBlock2 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D3470). Accessed by LDL^T factorization. |
| DAT_008D3670 | DynamicsSolver_BodyBlock4 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D3670). Accessed by LDL^T factorization. |
| DAT_008D37B8 | DynamicsSolver_BodyBlock5 | dynamics | double | read,write | 2 | Body block in dynamics solver matrix (0x8D37B8). Accessed by LDL^T factorization (FUN_00575BBD) and identity init (FUN_00578F76). |
| DAT_005E6734 | FloatConvertVTable | math_util | ptr | offset | 2 | Float conversion vtable/function pointer table. Initialized in FUN_00587B97 with pointers to __cfltcvt, __fassign, and custom float conversion functions. |
| DAT_005E7218 | LocaleStringTable | file_formats | ptr | offset | 2 | Locale string table pointer (points to "America" strings). Used in FUN_0058FD90 (locale/code page setup) and FUN_00590440 (locale table lookup). |
| DAT_008D48EC | HeapAllocatorMeta | file_formats | dword | read | 2 | Heap/memory allocator metadata. Used in FUN_00593E46 (free/release, bitmap management) and FUN_0059416F (allocation search with bitmask). Part of internal memory manager. |
| DAT_008D4648 | ModuleInstancePtr | game_logic | dword | offset | 2 | Module singleton instance pointer. Initialized in FUN_0059AAB9 (lazy init singleton pattern with FUN_0059ABCD). Read by FUN_0059AAAF (thin wrapper). |
