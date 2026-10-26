## VehicleDynamicsForceAccumulatorIntegration_00438130 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15C) | 0x64 | R | — | [LLM] |
| *(this+0x15C) | 0x6C | R | — | [LLM] |
| *(this+0x15C) | 0x74 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x234 | RW | — | [LLM] |
| this | 0x268 | R | — | [LLM] |
| this | 0x270 | R | — | [LLM] |
| this | 0x278 | RW | — | [LLM] |
| this | 0x288 | RW | — | [LLM] |
| this | 0x314 | R | — | [LLM] |
| this | 0x31C | R | — | [LLM] |
| this | 0x324 | R | — | [LLM] |
| this | 0x334 | R | — | [LLM] |
| this | 0x33C | R | — | [LLM] |
| this | 0x344 | R | — | [LLM] |
| this | 0x34C | RW | — | [LLM] |
| this | 0x354 | R | — | [LLM] |
| this | 0x35C | R | — | [LLM] |
| this | 0x364 | RW | 1546188227 | [LLM] |
| this | 0x368 | RW | 1082200719 → 4.0335f | [LLM] |
| this | 0x36C | RW | — | [LLM] |
| this | 0x374 | R | — | [LLM] |
| this | 0x37C | R | — | [LLM] |
| this | 0x384 | RW | — | [LLM] |
| this | 0x394 | RW | 0 | [LLM] |
| this | 0x398 | RW | 1072168960 → 1.8125f | [LLM] |
| this | 0x39C | RW | — | [LLM] |
| this | 0x3A4 | R | — | [LLM] |
| this | 0x3AC | R | — | [LLM] |
| this | 0x3B4 | R | — | [LLM] |
| this | 0x3BC | R | — | [LLM] |
| this | 0x3C4 | R | — | [LLM] |
| this | 0x3CC | R | — | [LLM] |
| this | 0x44C | RW | — | [LLM] |
| this | 0x454 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x234: recalc every frame — external poke does NOT persist
- this 0x278: recalc every frame — external poke does NOT persist
- this 0x288: recalc every frame — external poke does NOT persist
- this 0x34C: recalc every frame — external poke does NOT persist
- this 0x364: recalc every frame — external poke does NOT persist
- this 0x368: recalc every frame — external poke does NOT persist
- this 0x36C: recalc every frame — external poke does NOT persist
- this 0x384: recalc every frame — external poke does NOT persist
- this 0x394: recalc every frame — external poke does NOT persist
- this 0x398: recalc every frame — external poke does NOT persist
- this 0x39C: recalc every frame — external poke does NOT persist
- this 0x44C: recalc every frame — external poke does NOT persist
- this 0x454: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059e830 | dbl_59E830 | R | TempWarningThreshold [DERIVED] (also: ` — dot product comparison threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb30 | dbl_59EB30 | R | EngineOilPressureScale [DERIVED] |
| 0059eb38 | dbl_59EB38 | R | Physics_Double_59EB38 [DERIVED] |
| 0059eb40 | dbl_59EB40 | R | PositionScalingConstant [DERIVED] |
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059eb58 | dbl_59EB58 | R | Damper2RateCoefficient [DERIVED] |
| 0059eb60 | dbl_59EB60 | R | AntiRollScale [DERIVED] |
| 0059eb68 | dbl_59EB68 | R | SlipAngleGain [DERIVED] |
| 0059eb70 | dbl_59EB70 | R | TireSlipForceMult [DERIVED] |
| 0059eb78 | dbl_59EB78 | R | PhysicsSuspensionConst [DERIVED] |
| 0059eb80 | dbl_59EB80 | R | SteeringReturnDamping [DERIVED] |
| 0059eb88 | dbl_59EB88 | R | Unknown_Double_BrakeCalc [DERIVED] |
| 0059eb90 | dbl_59EB90 | R | EngineSweptVolumeConst [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec3bc | dword_5EC3BC | W | Dword_Unknown_Setup [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008afee4 | flt_8AFEE4 | R | RainFadeCoeff [DERIVED] |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |
| 008afef4 | flt_8AFEF4 | R | Flt_PhysicsBrakeBalance [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041aa10 | AISessionPhaseCounter | [LLM] |
| 0041ab30 | PitStateSlotActivation | [LLM] |
| 00438100 | TorqueForceProductComputation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
