## VehicleDynamicsForceAccumulatorIntegration_00438130 — Tire/Brake Thermal Integration and Wear Simulation

**Summary:** Integrates brake and tire temperatures over time using force inputs, weighted blending, and ambient temperature offsets. Computes wear/fatigue accumulation with blowout threshold detection, and triggers pit-stop state transitions when wear exceeds critical levels. Part of the vehicle dynamics thermal and degradation simulation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15C) | 0x64 | R | — | angular velocity component X (from sub-struct pointed by this+0x15C) |
| *(this+0x15C) | 0x6C | R | — | angular velocity component Y (from sub-struct) |
| *(this+0x15C) | 0x74 | R | — | angular velocity component Z (from sub-struct) |
| this | 0x78 | R | — | input force/torque component (read for power computation) |
| this | 0xBC | R | — | damping/velocity input (this+188, read for power) |
| this | 0x14C | R | — | braking blend coefficient (this+332, 1.0 - coefficient used) |
| this | 0x15C | R | — | pointer to sub-struct containing angular velocity data |
| this | 0x234 | RW | — | integrated brake temperature output component (this+564, scaled after blowout) |
| this | 0x268 | R | — | brake pressure/force input (this+616) |
| this | 0x270 | R | — | brake heating constant (this+624) |
| this | 0x278 | RW | — | scale factor written after blowout event (this+632, *= 0.7) |
| this | 0x288 | RW | — | scale factor written after blowout event (this+648, *= 0.7) |
| this | 0x314 | R | — | engine RPM / speed input (this+788, normalized to [0,1]) |
| this | 0x31C | R | — | brake pressure input (this+796, gating thermal accumulation) |
| this | 0x324 | R | — | brake force/torque input (this+804, gating brake thermal accumulation) |
| this | 0x334 | R | — | reference diameter / rolling baseline (this+820, used in wear ratio) |
| this | 0x33C | R | — | temperature input A (this+828, combined with heating) |
| this | 0x344 | R | — | temperature input B / heating coefficient (this+836) |
| this | 0x34C | RW | — | integrated temperature array start (3 doubles: disc temp L/C/R, this+844) |
| this | 0x354 | R | — | integrated temperature component (this+852, read for averaging) |
| this | 0x35C | R | — | integrated temperature component (this+860, read for averaging) |
| this | 0x364 | RW | 1546188227 | temperature minimum clamp (low dword of double 273.16 K, this+868) |
| this | 0x368 | RW | 1082200719 → 4.0335f | temperature maximum clamp (high dword of double 546.32 K, this+872) |
| this | 0x36C | RW | — | wear/fatigue rate accumulator (this+876, computed from forces and speed) |
| this | 0x374 | R | — | temperature reference value (this+884, used in thermal delta) |
| this | 0x37C | R | — | wear scale factor (this+892, multiplied by 0.25 after blowout) |
| this | 0x384 | RW | — | temperature accumulator after blowout reset (this+900, *= 0.18) |
| this | 0x394 | RW | 0 | wear/fatigue accumulator (this+916, decremented by wear rate, threshold 0.75) |
| this | 0x398 | RW | 1072168960 → 1.8125f | fatigue recovery rate (this+920, set to 1.8125 after blowout) |
| this | 0x39C | RW | — | smoothed wear output (this+924, combines wear with damping factor) |
| this | 0x3A4 | R | — | brake heating coefficient A (this+932, multiplied by brake force * RPM) |
| this | 0x3AC | R | — | brake cooling coefficient (this+940, multiplied by brake pressure) |
| this | 0x3B4 | R | — | temperature heating coefficient (this+948, used with ambient offset) |
| this | 0x3BC | R | — | temperature offset constant (this+956, added to heating) |
| this | 0x3C4 | R | — | scaling factor for temperature (this+964, multiplies angular velocity) |
| this | 0x3CC | R | — | wear computation coefficient (this+972, multiplies wear rate) |
| this | 0x44C | RW | — | post-blowout scaled factor A (this+1100, *= 0.7) |
| this | 0x454 | RW | — | post-blowout scaled factor B (this+1108, *= 0.7) |

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
| 0041aa10 | AISessionPhaseCounter | increment AI session phase counter (pit-stop decision trigger) |
| 0041ab30 | PitStateSlotActivation | activate pit-stop state for a given vehicle slot |
| 00438100 | TorqueForceProductComputation | compute torque * force product for thermal/wear integration |

**Guard conditions:** The function uses several conditional branches based on field values but none are simple field-vs-literal early-return guards:
- Brake force > 0.0 (0x324): gates brake thermal accumulation term (v3 computed only if brake force positive)
- Brake pressure > 0.0 (0x31C): gates brake cooling/heating term (v28/v4 computed only if pressure positive)
- Temperature < 273.16 (0x364): clamps temperature at minimum threshold (sets to 273.16)
- Temperature > 546.32 (0x368): clamps temperature at maximum threshold (sets to 546.32)
- Wear > 0.75 (0x394): triggers blowout event (reduces temperature, scales various coefficients)
- RaceActiveFlag && TrackConditionState != 0: gates pit-stop AI decisions (wear-based pit calls)
