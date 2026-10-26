## AIMainUpdate_00424e70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x48A4 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32C8 | R | — | [LLM] |
| this | 0x34E0 | R | — | [LLM] |
| this | 0x34E8 | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x357C | RW | 0 | ThrottleFactor [CONFIRMED] |
| this | 0x3580 | RW | 0 | [LLM] |
| this | 0x3584 | RW | 1065353216 → 1.0f | BrakeFactor [CONFIRMED] |
| this | 0x3984 | R | — | [LLM] |
| this | 0x399C | R | — | [LLM] |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] |
| this | 0x4028 | RW | 0 | [LLM] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x4068 | RW | — | ReasonCode [FACT] |
| this | 0x409C | R | — | bestLap [CONFIRMED] |
| this | 0x413C | RW | 2139095039 | [LLM] |
| this | 0x4144 | R | — | [LLM] |
| this | 0x4148 | R | — | [LLM] |
| this | 0x416C | RW | 1109393408 → 40.0f | [LLM] |
| this | 0x4170 | RW | 2139095039 | [LLM] |
| this | 0x43F8 | RW | 0 | [LLM] |
| this | 0x4404 | RW | — | [LLM] |
| this | 0x4420 | RW | 0 | [LLM] |
| this | 0x4424 | RW | 0 | [LLM] |
| this | 0x4428 | R | — | [LLM] |
| this | 0x442C | RW | 0 | [LLM] |
| this | 0x4434 | RW | 0 | [LLM] |
| this | 0x4438 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x443C | RW | 0 | [LLM] |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4448 | RW | — | [LLM] |
| this | 0x444C | RW | — | [LLM] |
| this | 0x447C | RW | — | [LLM] |
| this | 0x4480 | RW | — | [LLM] |
| this | 0x4484 | RW | 1232348144 → 999999.0f | [LLM] |
| this | 0x448C | RW | — | [LLM] |
| this | 0x4494 | RW | — | [LLM] |
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | [LLM] |
| this | 0x4534 | RW | — | timeOfNextExit [CONFIRMED] |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 1 | [LLM] |
| this | 0x4560 | RW | — | [LLM] |
| this | 0x4564 | RW | — | [LLM] |
| this | 0x4568 | RW | — | [LLM] |
| this | 0x4588 | R | — | [LLM] |
| this | 0x45E0 | R | — | [LLM] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x45FC | RW | 0 | [LLM] |
| this | 0x461C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x357C: recalc every frame — external poke does NOT persist
- this 0x3580: recalc every frame — external poke does NOT persist
- this 0x3584: recalc every frame — external poke does NOT persist
- this 0x4028: recalc every frame — external poke does NOT persist
- this 0x4068: recalc every frame — external poke does NOT persist
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x416C: recalc every frame — external poke does NOT persist
- this 0x4170: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4404: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x4424: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4438: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x4448: recalc every frame — external poke does NOT persist
- this 0x444C: recalc every frame — external poke does NOT persist
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4480: recalc every frame — external poke does NOT persist
- this 0x4484: recalc every frame — external poke does NOT persist
- this 0x448C: recalc every frame — external poke does NOT persist
- this 0x4494: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4560: recalc every frame — external poke does NOT persist
- this 0x4564: recalc every frame — external poke does NOT persist
- this 0x4568: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist
- this 0x461C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 0059e6a8 | flt_59E6A8 | R | ProximityThresholdSq [DERIVED] |
| 0059e6ec | flt_59E6EC | R | ShortIntToWorldScale [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e820 | flt_59E820 | R | OvertakingDistanceThreshold [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 0059e870 | flt_59E870 | R | AIStateDeltaThreshold [DERIVED] |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059e878 | flt_59E878 | R | AISpeedThreshold [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 005c30e0 | unk_5C30E0 | R | Unknown_String_5C30E0 [DERIVED] |
| 005c3144 | dword_5C3144 | R | VehicleField_3144 [DERIVED] |
| 005c3160 | byte_5C3160 | RW | TrackConfigByte_5C3160 [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
| 008acfb8 | flt_8ACFB8 | R | TimingsConst2 [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403f70 | ArrayOfStructIndexedFieldCopy | [LLM] |
| 00424c80 | AIRingBufferFieldInit | [LLM] |
| 00425660 | FieldZeroSetter | [LLM] |
| 00425670 | SteeringAngleController | [LLM] |
| 004258c0 | sub_4258C0 | [LLM] |
| 00425920 | AIRacingLine | [LLM] |
| 00426100 | sub_426100 | [LLM] |
| 00426330 | PhysicsGearShiftLogicWithThresholds | [LLM] |
| 00426430 | sub_426430 | [LLM] |
| 00426cf0 | AISteeringCorrection | [LLM] |
| 004270a0 | AISteering | [LLM] |
| 00429470 | AIAbility | [LLM] |
| 00429fd0 | RandomWeightedTierSelection | [LLM] |
| 0042a180 | AIPushLap | [LLM] |
| 0042a7d0 | OpponentProximityScanTeamRecognition | [LLM] |
| 0042ac70 | AIStateFlagSetter | [LLM] |
| 0042adb0 | SessionCleanupFlagClear | [LLM] |
| 0042ae00 | AIClearStateFlags | [LLM] |
| 004a4110 | sub_4A4110 | [LLM] |
| 004ef930 | RaceStartCountdownStateUpdate | [LLM] |
| 004efa40 | VehicleClimbAdjust | [LLM] |
| 004efac0 | ConditionalGate | [LLM] |
| 004f1a60 | LoopWithConditionalSubCall | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | != | 1 | [LLM] |
| obj | 0x32C8 | == | 1 | [LLM] |
| this | 0x32C8 | > | 1 | [LLM] |
| this | 0x3D6C | != | 2 | carConditions [CONFIRMED] |
| this | 0x3D6C | == | 2 | carConditions [CONFIRMED] |
| this | 0x4064 | == | 2 | FinishState [FACT] == DNF |
| this | 0x4148 | < | 4 | [LLM] |
| this | 0x444C | == | 4 | [LLM] |
| this | 0x4510 | == | 5 | driverStatus [CONFIRMED] |
| this | 0x45F4 | == | 1 | ActiveFlag [FACT] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
