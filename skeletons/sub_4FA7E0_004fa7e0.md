## sub_4FA7E0_004fa7e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c35c8 | aPaused | R | String_Paused [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) |
| 005d6d70 | dbl_5D6D70 | R | EngineBrakeTorqueFactor [DERIVED] (also: ` — integration enabled flag (shared timestep variable) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] |
| 007cc4f4 | dword_7CC4F4 | R | AudioMixerInt [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce264 | dword_7CE264 | R | SessionStateFlag [DERIVED] (also: ` — sub-mode selector) |
| 007cf860 | dword_7CF860 | R | Unknown_AiTeamCount_F860 [DERIVED] |
| 007cfb90 | dword_7CFB90 | R | Unknown_Render_7CFB90 [DERIVED] |
| 007cfc68 | dword_7CFC68 | R | WeatherStateFlag [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008afca8 | dword_8AFCA8 | R | RenderDisplayListPtr [DERIVED] |
| 008afcac | dword_8AFCAC | R | Unknown_RaceDynamics_Value [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe70 | byte_8AFE70 | RW | RaceByteFlag [DERIVED] |
| 008afe72 | byte_8AFE72 | RW | AudioInitSuccessFlag [DERIVED] |
| 008afe84 | dword_8AFE84 | RW | Unknown_Race_DynamicsValue [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |
| 008afe90 | dbl_8AFE90 | RW | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afe94 | byte_8AFE94 | R | RaceTimeAbsolute2 [DERIVED] |
| 008afe98 | dbl_8AFE98 | RW | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afe9c | byte_8AFE9C | W | TimeAccumulator_A [DERIVED] |
| 008afea0 | dbl_8AFEA0 | RW | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008afea8 | dbl_8AFEA8 | RW | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042d210 | sub_42D210 | [LLM] |
| 0044f460 | PackedFlagRead | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 00461db0 | SessionStateCheckWrapper | [LLM] |
| 004c8d60 | ArithmeticComparison_8d60 | [LLM] |
| 004c8d70 | ShortComputation_8d70 | [LLM] |
| 004cf040 | RepeatedCallLoop_f040 | [LLM] |
| 004f8d70 | sub_4F8D70 | [LLM] |
| 004f8f10 | ConditionalInitBranch | [LLM] |
| 004f8f50 | sub_4F8F50 | [LLM] |
| 004f9b30 | StateFlagComputation | [LLM] |
| 004f9f70 | GlobalFloatSetter | [LLM] |
| 0053ac70 | EmptyStubWithFlagCheck | [LLM] |
| 00545d00 | sub_545D00 | [LLM] |
| 0054c1b0 | UIWidgetRecursiveStateUpdate | [LLM] |
| 00556730 | sub_556730 | [LLM] |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
