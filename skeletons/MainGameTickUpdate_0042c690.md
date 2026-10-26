## MainGameTickUpdate_0042c690 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9b0 | dbl_59E9B0 | R | Rad2DegOrTimerMult [DERIVED] (also: ` — conversion multiplier) |
| 0059e9d8 | dbl_59E9D8 | R | GameTickMultiplier [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5694 | dword_7C5694 | RW | TimerOutputInt [DERIVED] (also: ` — timer/angle output global) |
| 007c5698 | dword_7C5698 | RW | SessionTickCounter [DERIVED] |
| 007c932c | dword_7C932C | W | RaceScoring_ClearFlags_0 [DERIVED] |
| 007c9330 | dword_7C9330 | W | UpdateLoopZeroState [DERIVED] |
| 007c9334 | dword_7C9334 | W | SessionClearStateArray [DERIVED] |
| 007c9338 | dword_7C9338 | W | StewardCounterBlock8 [DERIVED] |
| 007c933c | dword_7C933C | W | CollisionAccumulator [DERIVED] |
| 007c9340 | dword_7C9340 | W | ScoringAudioAccum0 [DERIVED] |
| 007c9344 | dword_7C9344 | W | PhysicsWorkspace_Zeroed_Block [DERIVED] |
| 007c9348 | dword_7C9348 | W | PhysicsAccum_07 [DERIVED] |
| 007c934c | dword_7C934C | W | ZeroedBlock7C934C [DERIVED] |
| 007c9350 | dword_7C9350 | W | Unknown_FlagBlock_Clear [DERIVED] |
| 007c9354 | dword_7C9354 | W | LapScoringFlagsBatch [DERIVED] |
| 007c9358 | dword_7C9358 | W | SimulationAccumBlock [DERIVED] |
| 007cbb10 | unk_7CBB10 | R | Collision_ContactBuffer [DERIVED] |
| 007cbf24 | dword_7CBF24 | R | Unknown_Int_7CBF24 [DERIVED] |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad238 | dword_8AD238 | R | ScoringGateOpen [DERIVED] |
| 008ad23c | dword_8AD23C | R | TimerTickAccumulator [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410980 | LoopWithConditionalSkipFunction | [LLM] |
| 004109d0 | PerVehicleCameraUpdateIterator | [LLM] |
| 00424e70 | AIMainUpdate | [LLM] |
| 0042c440 | sub_42C440 | [LLM] |
| 0042caa0 | AILateralForceComputation | [LLM] |
| 00451720 | DriverInputController | [LLM] |
| 004bccc0 | sub_4BCCC0 | [LLM] |
| 004d5960 | DebugLogInit | [LLM] |
| 004d59b0 | sub_4D59B0 | [LLM] |
| 004e4930 | VehiclePhysicsModeDispatcher | [LLM] |
| 004eb430 | ParticleEffectUpdateDispatch | [LLM] |
| 004ed810 | WheelTireForceUpdate | [LLM] |
| 004ed960 | FuelConsumptionAndWear | [LLM] |
| 004ee2d0 | sub_4EE2D0 | [LLM] |
| 004f1c40 | VehicleYawRotationRecoveryController | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 005895a2 | sub_5895A2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
