=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005ec4c0 | EmptyStringBuffer | setup/file | ptr | offset | 74 | Default/empty string buffer for path/file initialization |
| DAT_007ce234 | DriverAppearanceFlag | renderer | byte | read | 24 | Driver appearance/helmet rendering flag; checked per-vehicle with TeamID/FinishPosition |
| DAT_0059e824 | AIDynamicsThreshold | physics/ai | float | read | 15 | AI suspension/dynamics threshold for steering calculations; compared against suspension travel/wheel speed |
| DAT_0059e9c0 | TimeConversionFactor | ui/time | float | read | 9 | Lap time formatting conversion constant (frames-to-seconds or similar) |
| DAT_007cb21c | InputActionMap | input | ptr | read | 7 | Keyboard/controller action-to-function input mapping table; switch cases mapped to input device handlers |
| DAT_008ab678 | RaceSessionState | session/race | ptr | offset | 7 | Race session state/phase tracker; passed through race manager functions |
| DAT_005c692c | PathDelimiterChar | file/path | byte | read | 6 | Delimiter/separator character for string/path tokenization |
| DAT_005c26e0 | TrackNameAlbertPark | setup/track | ptr | offset | 5 | Track name string "Albert Park" for Albert Park Grand Prix Circuit (Melbourne) |
| DAT_005c2ab0 | ConfigDirectoryPath | setup/file | ptr | offset | 5 | Directory path or filename string for configuration file loading |
| DAT_005ec418 | UIScreenHighlightIndex | ui | int | read | 5 | Current UI screen/highlight selection index for setup screens |
| DAT_008d48f8 | HeapBlockCounter | memory | int | both | 5 | Heap block allocation counter for memory allocator (stride 0x14, blocks of 0x140-size) |
| DAT_007d0450 | CostDisplayMode | ui | int | read | 4 | Cost display mode for UI; assigned to session state then triggers cost display update |
| DAT_005c37cc | FormatSpecifierD | ui/text | ptr | offset | 4 | Integer-to-string format specifier "%d" used with sprintf-like function |
| DAT_008afca8 | RenderDisplayListPtr | renderer | ptr | offset | 4 | Render state flag or display list pointer; used in render/display list functions |
| DAT_008d2120 | ConstraintMatrix00 | physics/dynamics | double | both | 4 | Dynamics constraint solver matrix element [0,0]; part of LDL^T/Cholesky factorization workspace |
| DAT_0059e6a8 | ProximityThresholdSq | physics/collision | float | read | 3 | Squared distance threshold for vehicle-to-vehicle proximity/collision detection |
| DAT_005c32fc | LapsLabel | ui | ptr | read | 3 | "Laps" UI label string for race session display |
| DAT_007cca7c | UIElementTypeID | ui/menu | int | both | 3 | UI element type/ID selector for menu/options system; initialized to 0xC |
| DAT_007d084c | UIPercentageSlider | ui | float | both | 3 | UI percentage slider value (0.0-1.0 range, displayed as "0%-100%") |
| DAT_005c73b8 | aNationality | ui | ptr | read | 3 | UI label "Nationality" for driver nationality selector |
| DAT_005d2310 | aRacetime | ui | ptr | read | 3 | UI label/config key "RaceTime" for race time settings |
| DAT_008ad3a4 | AudioChannel4 | audio | int | read | 3 | Audio channel handle index 4 of 5, plays/stops via FUN_00553700 |
| DAT_005d8a60 | SSE_CONST_0_CubicInterp | math | float | read | 3 | SSE vector constant for Hermite/cubic interpolation polynomial evaluation |
| DAT_008b6ab8 | AudioBufferLoopBoundary | audio | int | write | 3 | Loop boundary in audio/network buffer processing, set to 0 in init |
| DAT_008d2540 | ConstraintMatrix_Body0_DOF5 | dynamics | double | both | 3 | LDL^T constraint matrix element for body 0, degree of freedom 5 |
| DAT_008d2d90 | ConstraintMatrix_Body3_Row6 | dynamics | double | both | 3 | LDL^T constraint matrix element for body 3, row 6, stride 24 |
| DAT_008d30d8 | ConstraintMatrix_Body5_6 | dynamics | double | both | 3 | LDL^T constraint matrix element in body 5-6 range |
| DAT_005e7718 | MathTableBoundary_5E7640 | math | double | read | 3 | MSVC CRT math constant/table boundary for atan/asin/log/exp at 0x5e7640 |
| DAT_007cb2fc | SCREEN_WIDTH | renderer | int | read | 2 | Window width in pixels, assigned to screen width offset 0x64 |
| DAT_0059e6a4 | MIN_VELOCITY_THRESHOLD | physics | float | read | 2 | Minimum velocity threshold for collision response, below this no forces applied |
| DAT_0059e788 | SessionLengthThreshold_11 | game_logic | double | read | 2 | Elapsed time threshold for session length category (~12 thresholds) |
| DAT_0059e8a8 | AIOvertakeThreshold | ai | float | read | 2 | AI overtaking/positioning threshold for steering angle and passing logic |
| DAT_007cec78 | PitTimerVisible | race | byte | read | 2 | Pit timer visibility flag in timer/pit display logic (already in docs/12) |
| DAT_005c3f94 | vtable_UIWidget_00432a70 | ui | ptr | read | 2 | Vtable pointer for C++ UI widget class, used in constructor/destructor |
| DAT_007cca50 | UISliderMinThreshold | ui | float | both | 2 | UI slider minimum value threshold, compared against vehicle struct offset 0x1140 |
| DAT_007cd110 | UIElementFloat_7CD110 | ui | float | both | 2 | UI element float state, init to 0.0 in sub_44CB74 |
| DAT_007ccfac | UIElementFloat_7CCFAC | ui | float | both | 2 | UI element float state, init to 0 in FUN_0044d1c0 |
| DAT_007ccf18 | UIElementSelector_7CCF18 | ui | ptr | read | 2 | UI element pointer/selector in factory dispatch (~30 targets) |
| DAT_007cca28 | UIElementState | ui | int | read | 2 | UI element state flag used in element update chain and UI menu rendering |
| DAT_0059f080 | Vtable_RenderUIObject | renderer | ptr | offset | 2 | Vtable pointer assigned in constructor/destructor of render/UI object |
| DAT_007d0c18 | OptionAutoReverse | setup | byte | both | 2 | Game options flag stored in save file; byte at param_1+0x67 triggers UI update via FUN_0047f1f0 |
| DAT_0059f138 | RadToDegFactor | math_util | float | read | 2 | Radian-to-degree conversion factor used in 104-iteration utility function |
| DAT_005c6958 | StrProfileIconBMP | ui | ptr | read | 2 | String literal "profileicon.bmp" for profile icon bitmap file path operations |
| DAT_005abc28 | Vtable_UIWidget | ui | ptr | offset | 2 | Vtable pointer for UI widget class assigned in constructor FUN_00488b00 |
| DAT_005cc544 | StrSetSymbol | ui | ptr | offset | 2 | String "SetSymbol" used as function/debug symbol name in UI rendering |
| DAT_005acaec | AITireGripThreshold | ai | float | read | 2 | Grip threshold compared against speedRatio returning 3/7/0xF wheel grip bitmask |
| DAT_005acb28 | AISteerAngleThreshold | ai | float | read | 2 | Steering angle comparison threshold for AI path calculation |
| DAT_008affc8 | NetworkReplayPacketData | network | ptr | offset | 2 | Network/replay packet data area used in packet type dispatch parsing |
| DAT_005d2ab0 | StrTotalChampions | ui | ptr | offset | 2 | String "TotalChampions..." config key for championship points option screen |
| DAT_005d2928 | StrGameOptFuelMult | ui | ptr | offset | 2 | String "GameOptFuelMult..." config key for fuel multiplier option screen |
| DAT_005acea8 | AudioNetworkTimingOffset | audio | float | read | 2 | Timing offset added to randomFloat for audio/network effect jitter calculation |
| DAT_005ad034 | Vtable_UIWidgetFactory | ui | ptr | offset | 2 | Vtable pointer for UI widget factory dispatching type indices to constructors |
| DAT_005d67b4 | RGBColorLookup | renderer | int | read | 2 | RGB color component lookup table returning color sets for input indices |
| DAT_008afe78 | NetworkPacketParam | network | int | both | 2 | Network packet state parameter stored from function parameter |
| DAT_005d77f0 | CallbackFuncPtr | system | ptr | read | 2 | Function pointer for indirect call dispatch via (*(code *)PTR_FUN_005d77f0)() |
| DAT_008d4690 | SSE_NRConstant | math_util | double | read | 2 | SSE vector constant for Newton-Raphson reciprocal sqrt approximation |
| DAT_005b47e8 | Vtable_GameObject | game | ptr | offset | 2 | Vtable pointer for game object class assigned in constructor FUN_0052d9b0 |
| DAT_005dbcac | DirectXErrorGetCurrent | setup | char* | read | 2 | Error string "Could not get current..." for DirectX/setup failure |
| DAT_005e4cf8 | DefaultSocketStruct | network | ptr | both | 2 | Default/fallback static network socket structure |
| DAT_008d2d20 | DynSolverMatrixElem_8D2D20 | physics/dynamics | double | both | 2 | Dynamics solver LDL^T constraint matrix element, identity init body 1 row 5 |
| DAT_008d2608 | DynSolverMatrixElem_8D2608 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, case 3 row 7, stride 56 zero |
| DAT_008d2568 | DynSolverMatrixElem_8D2568 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d2788 | DynSolverMatrixElem_8D2788 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d2938 | DynSolverMatrixElem_8D2938 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d31d0 | DynSolverMatrixElem_8D31D0 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d32a8 | DynSolverMatrixElem_8D32A8 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d3588 | DynSolverMatrixElem_8D3588 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d3908 | DynSolverMatrixElem_8D3908 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, case 0 row 14, stride 272 zero |
| DAT_008d3810 | DynSolverMatrixElem_8D3810 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d3790 | DynSolverMatrixElem_8D3790 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d3548 | DynSolverMatrixElem_8D3548 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d3858 | DynSolverMatrixElem_8D3858 | physics/dynamics | double | both | 2 | Dynamics solver constraint matrix element, factorization + identity init |
| DAT_008d3f30 | LocaleThreadSafeFlag | CRT/locale | byte | both | 2 | Multithreaded locale flag for string comparison; 0=simple, 1=thread-safe |
| DAT_005e7514 | FmodDenormalScale | CRT/math | double | read | 2 | Floating point scaling constant to scale up denormal values before fmod |
| DAT_008d47e0 | CodePageCharBitmap | CRT/locale | ptr | both | 2 | 256-byte code page character classification bitmask table (upper/lower/digit) |
| DAT_005b9d8c | StdOutOfRangeVtable | CRT/exception | ptr | read | 2 | C++ std::out_of_range exception vtable, set in constructor |
