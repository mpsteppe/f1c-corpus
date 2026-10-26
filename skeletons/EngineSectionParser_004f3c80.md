## EngineSectionParser_004f3c80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x68C | RW | — | [LLM] |
| this | 0x694 | RW | — | [LLM] |
| this | 0x69C | RW | 0 | [LLM] |
| this | 0x6A0 | RW | 1072693248 → 1.875f | [LLM] |
| this | 0x6AC | RW | — | [LLM] |
| this | 0x6B4 | RW | — | [LLM] |
| this | 0x6BC | RW | — | [LLM] |
| this | 0x6C4 | RW | — | [LLM] |
| this | 0x6C8 | RW | — | [LLM] |
| this | 0x6D0 | R | — | [LLM] |
| this | 0x6D8 | R | — | [LLM] |
| this | 0x12C8 | RW | — | [LLM] |
| this | 0x1310 | RW | — | [LLM] |
| this | 0x1318 | RW | — | [LLM] |
| this | 0x1320 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x68C: recalc every frame — external poke does NOT persist
- this 0x694: recalc every frame — external poke does NOT persist
- this 0x69C: recalc every frame — external poke does NOT persist
- this 0x6A0: recalc every frame — external poke does NOT persist
- this 0x6AC: recalc every frame — external poke does NOT persist
- this 0x6B4: recalc every frame — external poke does NOT persist
- this 0x6BC: recalc every frame — external poke does NOT persist
- this 0x6C4: recalc every frame — external poke does NOT persist
- this 0x6C8: recalc every frame — external poke does NOT persist
- this 0x12C8: recalc every frame — external poke does NOT persist
- this 0x1310: recalc every frame — external poke does NOT persist
- this 0x1318: recalc every frame — external poke does NOT persist
- this 0x1320: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ea38 | dbl_59EA38 | R | BodyDragCoeff [DERIVED] |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 005ad258 | dbl_5AD258 | R | PhysicsConstant_5AD258 [DERIVED] |
| 005d548c | aDDevF119992002_7 | R | DefaultScenePath7 [DERIVED] |
| 005d5528 | aRadiatorcoolin | R | RadiatorCoolingString [DERIVED] |
| 005d5538 | aWaterminimumco | R | WaterMinimumString [DERIVED] |
| 005d554c | aOilwaterheattr | R | OilwaterheattrString [DERIVED] |
| 005d5564 | aOilminimumcool | R | OilMinCoolStr [DERIVED] |
| 005d5578 | aEnginespeedhea | R | EngineSpeedHeadString [DERIVED] |
| 005d5588 | aCombustionheat | R | CombustionHeatField [DERIVED] |
| 005d5598 | aOptimumoiltemp | R | aOptimumOilTemp [DERIVED] |
| 005d55a8 | aStartertiming | R | String_StarterTiming [DERIVED] |
| 005d55b8 | aOnboardstarter | R | OnboardStarterString [DERIVED] |
| 005d55c8 | aEngineemission | R | EngineemissionString [DERIVED] |
| 005d55d8 | aLifetimevar | R | LifetimeVarString [DERIVED] |
| 005d55e4 | aLifetimeavg | R | String_LifetimeAvg [DERIVED] |
| 005d55f0 | aLifetimeoiltem | R | LifetimeOilTempRangeString [DERIVED] |
| 005d5600 | aLifetimeengine | R | LifetimeEngine [DERIVED] |
| 005d5614 | aRpmTorqueCurve | R | RpmTorqueCurveField [DERIVED] |
| 005d5638 | aRpmTorqueBrake | R | RpmTorqueBrakeString [DERIVED] |
| 005d565c | aTooManyRpmTorq | R | TooManyRpmTorqString [DERIVED] |
| 005d567c | aRpmtorque | R | RpmtorqueString [DERIVED] |
| 005d5688 | aRevlimitlogic | R | Str_Revlimitlogic [DERIVED] |
| 005d5698 | aBadEngineLaunc | R | StringBadEngineLaunc [DERIVED] |
| 005d56b0 | aLaunchrpmlogic | R | LaunchRPMLogicString [DERIVED] |
| 005d56c0 | aLaunchefficien | R | LaunchEfficiencyString [DERIVED] |
| 005d56d4 | aBadEngineIdleR | R | BadEngineIdleString [DERIVED] |
| 005d56ec | aIdlerpmlogic | R | IdleRPMLogicStr [DERIVED] |
| 005d56fc | aIdlethrottle | R | IdleThrottleString [DERIVED] |
| 005d570c | aEngineinertia | R | EngineInertiaField [DERIVED] |
| 005d571c | aFuelestimate | R | aFuelEstimate [DERIVED] |
| 005d572c | aFuelconsumptio | R | String_FuelConsumption [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f3c10 | EngineMapSetupFieldDefinitions | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 005655f0 | sub_5655F0 | [LLM] |
| 00565aa0 | sub_565AA0 | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
