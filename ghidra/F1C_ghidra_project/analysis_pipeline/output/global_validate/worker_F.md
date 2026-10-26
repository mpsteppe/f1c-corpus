
=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_008ACEE0 | ForceFeedbackBase | race/ai | int/ptr | both | 48 | Struct base pointer for force feedback/haptic system. Referenced by race UI functions that manage vibration effects per-vehicle. Located near ring buffer DAT_008aae70. Offset access pattern suggests object with multiple fields. |
| DAT_005BE828 | FileModeRb | fileio | string | read | 22 | String literal "rb" used as file open mode for binary reads. Passed to file I/O functions (FUN_0058ae69, FUN_00587db0) alongside DAT_005ea438 path. |
| DAT_008AB710 | UIWidgetList | ui | ptr | offset | 12 | Widget/control list for UI element management. Functions 0x0040e770-0x0040f130 handle widget creation, command dispatch, and color/position setup. Stride 0x6c between entries. |
| DAT_008AC4B0 | SceneCameraParam | setup | float | read | 9 | Float parameter passed by address to scene/camera evaluation function. Located near SceneFileCount (0x008ac488) and CurrentSceneIndex (0x008ac48c). Likely a scene rendering parameter (fog/view distance). |
| DAT_005C25FC | TeamName_Sauber | setup | string | offset | 7 | String "Sauber" — F1 constructor team name. Used in team identification/lookup. |
| DAT_005D6DC4 | PathPrefix | setup | string | offset | 7 | Source directory path string. IDA name suggests "D:\\dev\\F1_1999_2002\\..." format. |
| DAT_005F070C | SeasonScoringLaps | steward | int | offset | 6 | Lap/scoring data within season scoring DB (stride 0x48c0). Used by command processor (0x004b3400) and session timer functions to track completed laps per driver. |
| DAT_005C26AC | TrackName_Montreal | setup | string | offset | 5 | String "Montreal" — Circuit Gilles Villeneuve track name for Canadian GP. |
| DAT_007C54D8 | VehicleArrayEnd | global | ptr | offset | 5 | Upper boundary marker for VehiclePtrArray. Used as loop terminator in vehicle enumeration: while `(int)puVar1 < 0x7c54d8` iterate through vehicle structs at stride 0x48c0. |
| DAT_008AB700 | FreeListHead | network/heap | ptr | both | 5 | Head pointer for linked-list free/allocator pool. Functions 0x004b44e0 (init), 0x004b4a30 (remove), 0x004b4e10 (cleanup) manage free nodes via singly-linked list with DAT_008ab708, 0x008ab70c tracking. |
| DAT_005F0780 | VehicleSectorTimes | race | float | read | 4 | Per-vehicle sector time array. Accessed with stride `vehicleIdx * 0x1230 + sectorIdx`, within vehicle data block at 0x5ef9a0. Used in 0x00419500 to compare sector times against thresholds and trigger haptic feedback. |
| DAT_0059EE8C | QualityThresholdHigh | renderer | float | read | 4 | Float constant used as LOD/quality threshold. In FUN_004b2b90: compared hierarchically — param_2 < 0x59e7fc → lowest, < 0x59e908 → medium, < 0x59ee8c → high, else highest. Also used in UI text positioning as multiplier. |
| DAT_007CFFF0 | TextRenderFlag | renderer | byte | read | 4 | Flag byte used by text/bitmap rendering functions (0x0049bd40-0x0049c0b0). Controls text rendering behavior. |
| DAT_005AF9D0 | SIMD_Mask3DNow | math_util | qword | read | 4 | 64-bit SIMD mask constant used with AMD 3DNow! packed floating-point instructions. ANDed with comparison results in vector math operations (FUN_005215db, 0x0052278b). Part of 3DNow! math library. |
| DAT_005B8CC8 | DoubleZero | math_util | double | read | 4 | Double constant 0.0 used as comparison reference in CRT math functions: floating-point classification (FUN_0058a8a3), atan2-like conversion (FUN_0058de2c), and exponential math (FUN_005919da). |
| DAT_0059E7D0 | AgeThreshold_D | renderer | double | read | 3 | Double threshold in age/LOD chain (descending: 0x59e420 > 0x59e7e0 > 0x59e7d8 > 0x59e7d0 > ...). Used in FUN_00413820 and FUN_004139c0 to select rendering LOD (0-18 or 0x2d-0x3f range) based on integer age cast to double. |
| DAT_005C403C | FileExtSvm | fileio | string | offset | 3 | File extension string ".svm". Appended to filenames during save/load operations in FUN_0046e600 (vehicle setup file path builder). |
| DAT_005C57B0 | StringFlags1 | setup | string | offset | 3 | String "Flags1" or "Flags.1" used in configuration/build processing functions. |
| DAT_005C676C | TireName_RR | vehicle | string | offset | 3 | Tire position string — "RrTire" or "rr_tire" for rear-right wheel. Used in 0x004681b0 with similar strings for other corners (aRftire, aLrtire) to identify tire positions. |
| DAT_005CC68C | StringPosWH | ui | string | offset | 3 | String "PosWH" used in UI/screen layout functions (0x00492710, 0x00492a40, 0x00493990) for position/width/height parameter mapping. |
| DAT_008AB70C | FreeNodeCount | network/heap | int | both | 3 | Counter for free list allocator nodes. Incremented on alloc (FUN_004b44e0, 0x004b4e10) and freed-node return (FUN_004b4a30). Tracks number of available entries in the 0x8AB700 free pool. |
| DAT_005AD1F4 | AudioLerpCoeff | audio | float | read | 3 | Float interpolation coefficient used in audio sample rate conversion/blending (FUN_00514fee). Alternative to DAT_0059e98c and DAT_0059e450 for position interpolation between ushort audio samples. |
| DAT_005D8A90 | BSplineCoeff3 | renderer | xmmword | read | 3 | SSE 128-bit coefficient vector for cubic B-spline/Bezier evaluation. Used in FUN_0051f400, FUN_0051f4c0, FUN_0051f560 with _mm_mul_ps/_mm_add_ps intrinsics. Part of a 4-coefficient set (0x5d8a90, 0x5d8ab0, 0x5d8ac0) for polynomial interpolation. |
| DAT_005DBD40 | Skip_ErrorCreatingV | renderer | string | offset | 3 | DirectX error string "Error creating vertex buffer". Skip — DirectX internals. |
| DAT_008D2C08 | DynamicsMatrix_DiagBlock | dynamics | double | both | 3 | Double element in dynamics constraint solver LDL^T factorization workspace (0x8D0000-0x8D9000). Diagonal block entry in sparse matrix. Zeroed by FUN_00579ccf, set to identity by FUN_00578f76, factorized by FUN_00575bbd. |
| DAT_008D36A8 | DynamicsMatrix_Block136 | dynamics | double | both | 3 | Dynamics matrix block at offset 136 in the solver workspace. Pattern: zeroed by FUN_00579ccf, identity-initialized by FUN_00578f76 case matching, factorized by FUN_00575bbd LDL^T. |
| DAT_008D33A8 | DynamicsMatrix_Block24 | dynamics | double | both | 3 | Dynamics matrix block at offset 24 in solver workspace. Same pattern: zero-init, identity-init, LDL^T factorize cycle. |
| DAT_008D46CC | CodePageInitFlag | locale | int | both | 3 | Codepage initialization flag. Set to 1 by FUN_00596e40 after building DBCS translation tables at 0x8d47e0. Reset to 0 by FUN_0059706a. Checked by FUN_00598569 to skip direct translation when tables are ready. |
| DAT_0059E4EC | ThreadObjectVTable | threading | ptr | offset | 2 | Vtable pointer for threading/synchronization object (mutex + worker thread pool). Assigned to `*param_1` in FUN_00406130 (constructor with CreateMutexA) and FUN_00406250 (destructor with CloseHandle). Class has 3 worker slot entries. |
| DAT_0059E718 | AudioVolumeMul | audio | float | read | 2 | Float multiplier used in UI sound effect gain (FUN_0040f600) and color/alpha blending (FUN_00500210). Scales volume or color intensity. |
| DAT_005C2700 | StringJumpedStart | steward | string | offset | 2 | Penalty message string "Jumped Start". Used in jump-start detection and penalty reporting. |
| DAT_0059E930 | PhysicsDoubleThreshold | vehicle | double | read | 2 | Double constant used in vehicle suspension physics (FUN_004270a0) and tire physics (FUN_004441f0). Compared against vehicle dynamics values as a computation threshold. |
| DAT_005C3758 | StringFormatS | fileio | string | offset | 2 | Format string "%s" variant used in path/string formatting operations. |
| DAT_0059EB78 | PhysicsSuspensionConst | vehicle | double | read | 2 | Double constant in suspension/aero physics. Used in FUN_00438130 as a multiplication factor in suspension force computations. Also referenced by tire physics (FUN_004441f0). |
| DAT_007CA3CC | HUDTelemetry_Param4 | hud | float | both | 2 | Display copy of vehicle setup parameter at offset +0x1148. Copied with clamping in FUN_004537b0, initialized to 0 in FUN_0044c800. One of 12+ telemetry values shown on virtual steering wheel/cockpit HUD (brake/throttle/steering/g-force). |
| DAT_007CA444 | HUDTelemetry_Param5 | hud | float | both | 2 | Another tracked float in the cockpit HUD telemetry display. Initialized to 0.0 in FUN_0044ce14. Copied from vehicle struct in FUN_004537b0 with clamping. |
| DAT_007D2140 | HUDRefValue | hud | float | read | 2 | Reference float value in the HUD/cockpit display system. Compared against HUDStateArray elements in FUN_0044ff50 for widget rendering decisions. |
| DAT_007D1448 | HUDStateArray | hud | struct | both | 2 | Base of HUD/cockpit display state array. Contains 16 entries (2 groups of 8) at stride 0x6c (27 floats). Each entry: +0x0 (int/ptr), +0x8 (double), +0xC (float). Processed by FUN_004532d0 and FUN_0047a080 for display widget updates. |
| DAT_005C4E30 | StringEmpty | ui | string | offset | 2 | String "Empty" used for UI default/null display values. |
| DAT_005C5C34 | StringHostname | network | string | offset | 2 | String "Hostname" used in network/server browser UI. |
| DAT_007CEF3C | PenaltyConfigFlag | steward | int | both | 2 | Penalty/race configuration flag near PenaltiesEnabled (0x7cef84). Read by FUN_00461610 for config serialization and written by FUN_00461900 for config deserialization. |
| DAT_005C670C | StringCustom | ui | string | offset | 2 | String "Custom" used in UI for custom setup/configuration labels. |
| DAT_007D011C | UIModeValue | game | int | read | 2 | Game UI mode/state value. Compared against dword_7D0110 in FUN_004735b0 to select HUD display content. Determines race info, timing, or default display mode. |
| DAT_005AC044 | UIElementVTable | ui | ptr | offset | 2 | Function pointer table (vtable) for a UI element class. Assigned to `*param_1` in FUN_0048c9a0 (constructor) and FUN_0048c9d0. |
| DAT_005CC694 | StringLocation | ui | string | offset | 2 | String "Location" used in UI layout/screen rendering. |
| DAT_005CCE74 | UIRenderVTable | renderer | ptr | offset | 2 | Function pointer table (vtable) for a UI rendering class. Used in FUN_0049c370 and FUN_0049c4e0. |
| DAT_005CD604 | StringLODOut | renderer | string | offset | 2 | String "LODOut" used in rendering/LOD system. |
| DAT_005D2434 | SerializeMagic | network | ptr | read | 2 | Pointer to static data block used as magic/header in binary serialization. Written as 4 bytes by FUN_004b6a10, compared as byte array by FUN_004b8090. Likely a protocol magic number. |
| DAT_005D2A60 | StringAvgFinishPosit | steward | string | offset | 2 | String "AvgFinishPosit" — average finish position statistic label. Used in career/driver stats display. |
| DAT_005D30CC | MessageBoxConfig | ui | struct | read | 2 | Message box display configuration struct. Fields loaded by FUN_004c4d50: 0x5d30cc/0x5d30d0/0x5d30d4 (format params), 0x5d30c0-0x5d30d8 (display colors/text). Used for in-game message/prompt rendering. |
| DAT_005ACEE0 | VehicleDynamicsFloat | vehicle | float | read | 2 | Float constant in vehicle dynamics (FUN_004e5f60). Used in wheel slip/force computations. |
| DAT_007CF7F4 | PhysicsFlag | physics | int | read | 2 | Flag read in physics stepping (FUN_004e19d0) and renderer pipeline. Controls physics processing path. |
| DAT_005D67C8 | MaterialColorR | renderer | float | read | 2 | Default material color component R. One of a triplet (0x5d67c8=R, 0x5d67cc=G, 0x5d67d0=B). Returned by FUN_004f8280 with different values selected by material type switch (0-0x2c range covering various surface types). |
| DAT_008AFE71 | SubsystemEnableFlag | physics | byte | both | 2 | Subsystem enable flag. Toggled 0↔1 by FUN_004f9f00/FUN_004f9f30 based on FUN_0055c9b0 return. Controls FUN_005550a0/FUN_005550c0 activation. |
| DAT_005D781C | FuncPtrTable_Dispatch | audio | ptr | read | 2 | Function pointer table for indirect dispatch. Called as `(*(code *)PTR_FUN_005d781c)()` in FUN_0050e3cd after FUN_0050fea7(1) prepares a parameter. Likely a MIDI/audio event dispatch table. |
| DAT_005AF9A0 | SIMD_Coeff_3DNow_2 | math_util | qword | read | 2 | 64-bit 3DNow! packed float constant used in polynomial evaluation (FUN_00526392, FUN_005271ed). Part of cubic interpolation coefficient set for MMX/3DNow! vector math. |
| DAT_008B1924 | AudioWavetableBuffer | audio | struct | both | 2 | Wavetable synthesis data buffer. Populated from source tables (0x5b6f0a, 0x5b730a) in FUN_005317c0 with stride 0x40 per entry, 2 interleaved channels. Processed by FUN_00532aa0 using SIMD (pmaddwd, packssdw) for audio sample generation. |
| DAT_005DBE54 | StringFormatS2dS | fileio | string | offset | 2 | Format string "%s %d %s" used in text/log formatting. |
| DAT_005E5248 | StringPmodelErrorTxt | fileio | string | offset | 2 | Error log filename path: "pmodel_error.txt". |
| DAT_008D23F0 | Dynamics_Block23E0_Elem | dynamics | double | both | 2 | Double element within 40-byte constraint block at 0x8d23e0. Part of constraint solver LDL^T workspace. Zeroed by FUN_00579ccf (sub_58BB10 size=40), identity-initialized by FUN_00578f76. |
| DAT_008D2D30 | Dynamics_Block2D18_Elem | dynamics | double | both | 2 | Double element within 80-byte constraint block at 0x8d2d18. Part of constraint solver LDL^T workspace. Stride of 80 bytes common for wheel/contact constraints. |
| DAT_008D2C30 | Dynamics_Block2C08_Elem2 | dynamics | double | both | 2 | Double element within 80-byte constraint block at 0x8d2c08. Adjacent to 0x8d2c08 base. Part of constraint solver LDL^T workspace. |
| DAT_008D38A8 | Dynamics_Block3870_Elem | dynamics | double | both | 2 | Double element within 272-byte constraint block at 0x8d3870 (largest block — vehicle body constraint with all DOF). Part of constraint solver LDL^T workspace. |
| DAT_008D3340 | Dynamics_Block33A8_ElemPre | dynamics | double | both | 2 | Double element preceding 24-byte constraint block at 0x8d33a8. Within 64-byte block at 0x8d33f8 region. Part of constraint solver LDL^T workspace. |
| DAT_008D38D8 | Dynamics_Block3870_Elem2 | dynamics | double | both | 2 | Double element within 272-byte constraint block at 0x8d3870. Part of constraint solver LDL^T workspace. |
| DAT_008D34E0 | Dynamics_Block34B8_Elem | dynamics | double | both | 2 | Double element within 64-byte constraint block at 0x8d34b8. Part of constraint solver LDL^T workspace. |
| DAT_008D38F8 | Dynamics_Block3870_Elem3 | dynamics | double | both | 2 | Double element within 272-byte constraint block at 0x8d3870. Part of constraint solver LDL^T workspace. |
| DAT_008D3638 | Dynamics_Block3610_Elem | dynamics | double | both | 2 | Double element within 128-byte constraint block at 0x8d3610. Part of constraint solver LDL^T workspace. |
| DAT_008D3780 | Dynamics_Block3740_Elem | dynamics | double | both | 2 | Double element within 144-byte constraint block at 0x8d3740. Part of constraint solver LDL^T workspace. |
| DAT_008D3538 | Dynamics_Block3528_Elem | dynamics | double | both | 2 | Double element within 40-byte constraint block at 0x8d3528. Part of constraint solver LDL^T workspace. |
| DAT_008D3840 | Dynamics_Block3870_Elem4 | dynamics | double | both | 2 | Double element within 272-byte constraint block at 0x8d3870. Part of constraint solver LDL^T workspace. |
| DAT_008D3868 | Dynamics_Block3870_Elem5 | dynamics | double | both | 2 | Double element within 272-byte constraint block at 0x8d3870. Part of constraint solver LDL^T workspace. |
| DAT_008D5A40 | ThreadPoolCount | threading | int | read | 2 | Worker thread/slot count in thread pool. Used as loop bound in FUN_0058a0bf, FUN_0058c5ac for enumerating thread entries at DAT_008d4a24. |
| DAT_005E77F4 | DateSerialDay | locale | int | both | 2 | Day-of-year value in system date/time tracking (FUN_0059249b, FUN_00592647). Used alongside DAT_005e77f0 (year), DAT_005e77f8 (ms), DAT_005e7800-0x5e7808 (end date) for date range comparison. |
| DAT_008D4650 | EncodingSingletonPtr | locale | ptr | read | 2 | Singleton object pointer for string/encoding manager. Lazily allocated in FUN_0059aab9 with operator_new(0x28) and initialized via FUN_0059abcd. Used for codepage/text encoding operations. |
