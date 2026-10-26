=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_008AFE18 | GameRacePhaseTimer | race | struct/ptr | offset | 31 | Struct/timer used by Game::Post step functions (0x0042dxxx) and UI/render functions. Tracks race phase timing or session state. High ref count (31) indicates core game loop consumption. |
| DAT_005E6748 | DynamicsVTable | dynamics | ptr | offset | 18 | Vtable/function pointer table for dynamics constraint solver methods. Referenced by stub functions calling FUN_00598815 and FUN_00599958 from the 0x0057xxxx dynamics code range. |
| DAT_008D4510 | DynamicsSolverWorkspace_4510 | dynamics | double | offset | 10 | Double-precision matrix workspace element in the 0x008Dxxxx constraint solver block. Part of the LDL^T factorization workspace. |
| DAT_005CC4F4 | Str_UI_CompareToken_CC4F4 | UI | string | offset | 8 | String constant used with FUN_00587C20 (string compare) in UI/menu code. Paired with DAT_005CC4F8 as comparison tokens for menu navigation logic. |
| DAT_005C25B4 | Str_Team_Toyota | setup | string | offset | 7 | String literal "Toyota". Used in team/car name matching across setup and AI functions. |
| DAT_007CE2A0 | HInstance | system | ptr/handle | read/write | 6 | Windows HINSTANCE (module instance handle). Set during app init, used for window creation and resource loading. |
| DAT_008D3FB4 | LocaleLanguageID | system | int | read/write | 6 | Windows locale language identifier (LCID/language ID). Set during locale detection, used in GetLocaleInfoA/IsValidLocale calls in internationalization code. |
| DAT_005C2640 | Str_Track_Sepang | setup | string | offset | 5 | String literal "Sepang". Track name string used in track selection/matching code. |
| DAT_007CE2DC | HWnd | system | handle | read/write | 5 | Window handle (HWND) for the game's main window. Used by DirectX device creation and window management functions. |
| DAT_008B6C28 | AudioSoundBuffer | audio | ptr/struct | offset | 5 | Audio buffer/sound resource pointer. Used by audio engine functions (0x0053xxxx range) for buffer allocation and playback. |
| DAT_007CE6AC | CtrlFlag_NetcodeTolerance | UI | byte | read | 4 | UI/control flag byte used as tolerance or state indicator. Used in FUN_00438CC0 (telemetry/control setup) and FUN_0049E170 (UI rendering) as a control state field. Part of a group of 11 flag bytes at 0x007CE6AC-0x007CE7CC. |
| DAT_005C5800 | Str_Shader_S_1 | renderer | string | offset | 4 | Shader/effect parameter string constant. Used by renderer setup functions for Direct3D shader configuration. |
| DAT_008AC1E8 | SceneRenderStruct | renderer | struct/ptr | offset | 4 | Scene/renderer struct pointer. Used by rendering pipeline functions for scene graph traversal and draw call dispatch. |
| DAT_008B8E28 | AudioInitialized | audio | int | read/write | 4 | Audio engine initialization flag. Set to 1 during audio init (FUN_0053C360). Checked by audio processing functions to determine if audio is active. |
| DAT_005B9D54 | VTable_StdfacetLocale | crt | ptr | offset | 4 | C++ vtable pointer for `std::locale::facet`. Used by MSVC STL locale implementation. Part of the C++ runtime support. |
| DAT_0059E854 | Flt_Physics_AI_Threshold | physics | float | read | 3 | Float physics constant used in AI vehicle control calculations. Referenced by AI ability/behavior functions as a comparison threshold. |
| DAT_0059ED98 | Dbl_Physics_TimingThreshold | physics | double | read | 3 | Double precision threshold used in vehicle setup timing and physics integration stepping. Compared against frame delta values. |
| DAT_005C58CC | Str_RenderState_sMipmapLodBias | renderer | string | offset | 3 | Direct3D render state string "sMipmapLodBias". Used by D3D shader/effect parameter setup functions. |
| DAT_005C6970 | Str_UI_PlayerNameNever | UI | string | offset | 3 | UI string constant related to player name display. Used by menu/UI text rendering functions. |
| DAT_005ACB0C | Flt_ViewportConstant | renderer | float | read | 3 | Float constant used in viewport/screen calculations. Referenced by UI position math and collision detection. |
| DAT_007CF9EC | Byte_RendererFlag_F9EC | renderer | byte | read | 3 | Renderer byte flag controlling rendering mode. Checked for conditionally enabling/disabling render paths. |
| DAT_005AF63C | Flt_AudioResampleCoeff | audio | float | read | 3 | Audio DSP/resampling filter coefficient. Used in 16-tap interpolation filter for audio sample rate conversion. |
| DAT_008B0118 | AudioBufferPtr | audio | ptr | offset | 3 | Audio buffer pointer that gets zeroed on init. Returned by audio setup function (sub_52E577) and assigned to audio class instances. |
| DAT_008D21D0 | DynSolver_Matrix_8D21D0 | dynamics | double | read/write | 3 | Double-precision matrix element in the dynamics constraint solver LDL^T factorization workspace (0x008D2120-0x008D3890 block). Set to 0.0 or 1.0 during identity initialization in FUN_00578F76. |
| DAT_008D3278 | DynSolver_Workspace_3278 | dynamics | double | read/write | 3 | Double-precision workspace block (64 bytes: 8 doubles starting at 0x008D3278). Part of the dynamics constraint solver LDL^T workspace. Zeroed in FUN_00579CCF and read/modified in FUN_00575BBD. |
| DAT_008D3050 | DynSolver_Workspace_3050 | dynamics | double | read/write | 3 | Double-precision workspace element at 0x008D3050. Part of the constraint solver matrix workspace. Set to 0.0 during solver init (FUN_00579CCF). |
| DAT_005B8C30 | VTable_TaskBase | system | ptr | offset | 3 | Vtable pointer for a task/job base class. Used by FUN_00587030 (task constructor), FUN_00587090 (copy constructor), and FUN_005870D0 (destructor). |
| DAT_0059E44C | Flt_CollisionTolerance | physics | float | read | 2 | Float tolerance threshold used in collision detection functions. Compared against distances in collision/suspension calculations. |
| DAT_005BE900 | Int_GameStateSubmode | game | int | read/write | 2 | Game state sub-mode integer. Written in FUN_00409440 (state machine) and read in FUN_00409A00 (game mode switch). Controls branching of game mode behavior. |
| DAT_0059E7C0 | Dbl_DamageThreshold_14 | physics | double | read | 2 | Double threshold in a cascade of 14 damage/comparison thresholds (0x0059E788-0x0059E7E0). Used by FUN_00413820 and FUN_004139C0 to map damage values to visual/mechanical states. |
| DAT_0059E850 | Flt_Physics_Vehicle_AIScale | physics | float | read | 2 | Float physics constant used in AI vehicle speed/position calculations. Multiplied with other physics values in AI control functions. |
| DAT_0059E9D4 | Flt_Physics_Const_E9D4 | physics | float | read | 2 | Float physics constant used in vehicle dynamics functions. |
| DAT_007C7410 | Int_RenderListHead | renderer | int | write | 2 | Renderer list head/tail field. Part of a group of globals at 0x007C73E8-0x007C7424 that get reset to 0/-1 during list initialization. Used in linked list management for render objects. |
| DAT_008ACFD4 | Int_RaceConfig_CFD4 | race | int | read | 2 | Race configuration integer. Read by physics setup (FUN_004441F0) and game logic functions. |
| DAT_007CCF8C | Flt_CopilotThreshold | setup | float | read/write | 2 | Float threshold for copilot/assist systems. Initialized to 0 (FUN_0044C980), compared against vehicle setup values in FUN_004537B0 to clamp assist levels. |
| DAT_007CCF64 | Flt_Threshold_CF64 | setup | float | write | 2 | Float setup threshold. Initialized to 0 in FUN_0044D100, used as comparison threshold in vehicle setup functions. |
| DAT_007C8A18 | Ptr_VehicleTransformBase | vehicle | ptr | read | 2 | Struct base pointer for vehicle chassis/transform data. Used as base for offset-based field access in physics transform calculations (FUN_004E49B0). |
| DAT_007CD078 | Flt_Threshold_CD078 | setup | float | read | 2 | Float threshold used in vehicle setup comparison code. Initialized from vehicle data fields. |
| DAT_005C5A44 | Str_Shader_sPositionFFF | renderer | string | offset | 2 | Direct3D shader parameter string "sPositionFFF". Used by renderer setup functions for vertex shader parameter binding. |
| DAT_005C5E64 | Int_RenderState_5E64 | renderer | int | read | 2 | Integer render state or constant used in rendering pipeline code. |
| DAT_007D0EBC | Int_RaceSetupFuelStrat | race | int | write | 2 | Race setup integer set from player configuration file byte offset +0x6b. Written in FUN_00461900 (setup reading) and FUN_00463F70. Likely fuel strategy or pit window setting. |
| DAT_007D2E41 | Byte_SeasonScoringFlag | game | byte | read | 2 | Byte flag within the SeasonScoringDB struct (stride 0x48C0). Used by season/championship scoring functions. |
| DAT_005CC9E0 | Flt_UIColorIntensity | UI | float | write | 2 | Float color/alpha intensity for UI element rendering. Set from DAT_007CF2CC and clamped between 0.0-1.0, passed to UI draw functions. |
| DAT_005CC21C | Str_UI_Load | UI | string | offset | 2 | String constant used in UI file/path string comparisons. Compared against file paths to determine UI mode. |
| DAT_007CE040 | Unk_UIVtable_7CE040 | UI | ptr | offset | 2 | UI element vtable/struct pointer. Used only via nullsub_3 call, suggesting a base class with default no-op implementation. |
| DAT_007CE2E0 | Int_WindowState_E2E0 | system | int | read/write | 2 | Window management state variable. Used alongside hWnd and hinst for game window lifecycle management. |
| DAT_005ACBCC | VTable_UIElement_ACBCC | UI | ptr | offset | 2 | Vtable pointer for a UI widget/element class. Set in constructors (FUN_004A70E0, FUN_004B1990) for a scrollbar/slider-like UI element with position tracking. |
| DAT_005D284C | Str_UI_Player | UI | string | offset | 2 | String literal "Player". Used in menu/UI text rendering for player name labels. |
| DAT_005D29A4 | Str_RaceCondTimeScale | race | string | offset | 2 | String constant "RaceCond_TimeScale" or similar. Used by race condition/scenario configuration parsing. |
| DAT_005C67A8 | VTable_Renderer_67A8 | renderer | ptr | offset | 2 | Vtable pointer for a renderer utility element class. Used by rendering functions for draw state management. |
| DAT_005D4710 | Str_Name | UI | string | offset | 2 | String literal "Name". Used in UI data binding and field name matching. |
| DAT_007C749F | Byte_PlayerControlFlag | vehicle | byte | read | 2 | Player vehicle control flag byte. Checked in camera/control functions to conditionally skip processing or enable special handling for the player car. |
| DAT_007CF338 | Flt_ForceFeedbackMult | game | float | read | 2 | Float multiplier for force feedback/steering effects. Used as alternate scaling factor in control force calculations. |
| DAT_005AD34C | Flt_Sentinel_StructInit | system | float | read | 2 | Float sentinel/magic value used to detect struct initialization state. Written to struct field +0xC as init marker, compared to check if struct has been initialized. |
| DAT_005AFD30 | Str_Debug_IgnoringIncorrect | system | string | offset | 2 | Debug/error message string "Ignoring incorrect...". Used in error logging for data validation. |
| DAT_005D92D8 | MMX_PolyCoeff_SinCos | math_util | double (MMX) | read | 2 | Polynomial coefficient (double as packed MMX) for sin/cos approximation using MMX/3DNow! instructions. Part of a set of constants (0x005D92D8-0x005D9368) used in FUN_005295E0 and FUN_00529700. |
| DAT_008B8CEC | Int_AudioQuality | audio | int | read/write | 2 | Audio quality/mode selector. Set to 2 (stereo?) or 3 (mono?) based on init flags in FUN_0053C360. Read by audio processing for format decisions. |
| DAT_005DC298 | Str_Light | renderer | string | offset | 2 | String literal "Light". Used by renderer scene graph for light node name matching. |
| DAT_008D2548 | DynSolver_Matrix_8D2548 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Set to 0.0 in identity initialization and read during LDL^T factorization. |
| DAT_008D2FB8 | DynSolver_Matrix_8D2FB8 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace (0x8D2FA8 + 0x10 offset). Part of the LDL^T block. |
| DAT_008D2B18 | DynSolver_Matrix_8D2B18 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Used in block case 4 of identity init. |
| DAT_008D2C38 | DynSolver_Matrix_8D2C38 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of a 80-byte block starting at 0x8D2C08. |
| DAT_008D2B40 | DynSolver_Matrix_8D2B40 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Used in LDL^T factorization. |
| DAT_008D3348 | DynSolver_Matrix_8D3348 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of 64-byte block at 0x8D3338. |
| DAT_008D38E8 | DynSolver_Matrix_8D38E8 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of 272-byte block at 0x8D3870. |
| DAT_008D3030 | DynSolver_Matrix_8D3030 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of block at 0x8D3020. |
| DAT_008D36C0 | DynSolver_Matrix_8D36C0 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of 128-byte block at 0x8D3610. |
| DAT_008D3808 | DynSolver_Matrix_8D3808 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of 152-byte block at 0x8D37D8. |
| DAT_008D33B0 | DynSolver_Matrix_8D33B0 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of block at 0x8D33A8. |
| DAT_008D35D8 | DynSolver_Matrix_8D35D8 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of 120-byte block at 0x8D3578. |
| DAT_008D3720 | DynSolver_Matrix_8D3720 | dynamics | double | read/write | 2 | Double-precision matrix element in dynamics constraint solver workspace. Part of 144-byte block at 0x8D3740. |
| DAT_008D5A50 | Ptr_AtexitStackPtr | system | ptr | read | 2 | Pointer tracking current position in at-exit function stack. Used by FUN_00587AC0 (atexit handler push) and FUN_00589CC6 (atexit shutdown). Paired with DAT_008D5A54 (stack base). |
| DAT_005E69D2 | CodepageMappingTable | system | word array | read | 2 | Unicode/codepage mapping table (word array). Used by character conversion code (FUN_0058F939 locale/CP init, FUN_00596E0F character classification). |
| DAT_008D48E8 | Int_HeapReAllocCapacity | system | int | read/write | 2 | Heap capacity counter for dynamic resource allocation. Incremented by +0x10 when reallocation needed. Used in heap-managed buffer (likely for file/resource loading). |
| DAT_005B9D34 | Buf_NullStringSentinel | crt | byte/ptr | offset | 2 | Null/empty string sentinel buffer. Used as default return value for null string buffers and as empty string replacement in MSVC STL basic_string implementation. |
