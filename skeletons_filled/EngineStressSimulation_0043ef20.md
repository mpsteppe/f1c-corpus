## EngineStressSimulation_0043ef20 — Engine Stress, Thermal & Component Failure Simulation

**Summary:** Simulates per-frame engine durability degradation from RPM, coolant/oil temperature dynamics with thermal stress accumulation, and random component failures (3 components) using weather-noise-driven probability. Engine physics / damage system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x2C | R | — | engine model: torque component A (from sub-struct at 0x15F0 + 44) |
| *(this+0x15F0) | 0x44 | R | — | engine model: torque component B (from sub-struct at 0x15F0 + 68) |
| *(this+0x15F0) | 0x5C | R | — | engine model: torque component C (from sub-struct at 0x15F0 + 92) |
| *(this+0x15F0) | 0x64 | R | — | engine model: torque component D (from sub-struct at 0x15F0 + 100) |
| *(this+0x15F0) | 0x6C | R | — | engine model: torque component E (from sub-struct at 0x15F0 + 108) |
| *(this+0x15F0) | 0x74 | R | — | engine model: torque component F (from sub-struct at 0x15F0 + 116) |
| *(this+0x1D4) | 0xAC | RW | — | vehicle physics: engine power/torque output at sub-struct offset 0xAC |
| *(this+0x1D4) | 0xB4 | RW | — | vehicle physics: inverse torque multiplier (1/power) at sub-struct offset 0xB4 |
| *(this+0x1F00) | 0x4068 | RW | 1 | game state: engine failure state code (set to 9 = durability exhausted, 1 = component failure) |
| this | 0x8 | R | — | engine RPM input value (double) |
| this | 0x68 | R | — | per-frame time delta (dt, double) |
| this | 0x19C | RW | 0 | engine durability / lifetime value (decremented by RPM-induced damage) |
| this | 0x1A0 | RW | 0 | durability exhausted flag (set to 0 when durability hits zero) |
| this | 0x1AC | R | — | damage scaling factor (RPM-to-durability conversion multiplier) |
| this | 0x1B4 | R | — | damage dissipation factor (multiplies damage * dt) |
| this | 0x1D4 | R | — | vehicle physics sub-struct pointer (provides torque/power data) |
| this | 0x15F0 | R | — | engine model parameter block pointer (torque coefficients) |
| this | 0x1C5C | R | — | engine RPM absolute value (fabs of this+0x1C5C, input for damage calc) |
| this | 0x1CFC | R | — | component failure array pointer (3 engine components) |
| this | 0x1D08 | R | — | component count (number of failure-tracked components) |
| this | 0x1D4C | RW | — | coolant temperature (updated each frame via thermal dynamics) |
| this | 0x1D50 | RW | — | coolant temperature upper 32 bits of double |
| this | 0x1D54 | R | — | max coolant temperature threshold (overheat limit) |
| this | 0x1D5C | R | — | thermal dissipation coefficient (heat loss rate) |
| this | 0x1D64 | R | — | RPM-to-heat conversion factor (mechanical→thermal energy) |
| this | 0x1D6C | R | — | ambient-to-coolant heat transfer coefficient |
| this | 0x1D74 | RW | — | coolant thermal stress accumulator (integrated over time) |
| this | 0x1D7C | R | — | base cooling efficiency |
| this | 0x1D84 | R | — | RPM-dependent cooling boost factor |
| this | 0x1D8C | RW | — | oil temperature (updated each frame) |
| this | 0x1D94 | R | — | base oil heating constant |
| this | 0x1D9C | R | — | load-dependent oil heating factor |
| this | 0x1DA4 | RW | — | oil thermal stress accumulator |
| this | 0x1DAC | RW | 858993459 | failure timer (packed double, low DWORD = 0x33333333, effective value ~0.6) |
| this | 0x1DB0 | RW | 1071854387 → 1.775f | failure threshold (packed double high DWORD, effective ~0.6 complete) |
| this | 0x1DB4 | RW | 0 | component stress accumulator (negative = accumulating, positive = recovering) |
| this | 0x1DB8 | RW | 0 | component stress cleared flag |
| this | 0x1DE4 | RW | 0 | component 0 failure probability/state (zeroed on reset, set to random 0-1) |
| this | 0x1DE8 | RW | 0 | component 1 failure probability/state |
| this | 0x1DEC | RW | 0 | component 2 failure probability/state |
| this | 0x1DF0 | RW | 0 | component 3 cleared (part of component 0 upper DWORD) |
| this | 0x1DF4 | RW | 0 | component 4 cleared (part of component 1 upper DWORD) |
| this | 0x1DF8 | RW | 0 | component 5 cleared (part of component 2 upper DWORD) |
| this | 0x1F00 | R | — | game state pointer (for writing failure codes) |

**Written-by note (persistence):**
- *(this+0x1D4) 0xAC: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0xB4: recalc every frame — external poke does NOT persist
- *(this+0x1F00) 0x4068: recalc every frame — external poke does NOT persist
- this 0x19C: recalc every frame — external poke does NOT persist
- this 0x1A0: recalc every frame — external poke does NOT persist
- this 0x1D4C: recalc every frame — external poke does NOT persist
- this 0x1D50: recalc every frame — external poke does NOT persist
- this 0x1D74: recalc every frame — external poke does NOT persist
- this 0x1D8C: recalc every frame — external poke does NOT persist
- this 0x1DA4: recalc every frame — external poke does NOT persist
- this 0x1DAC: recalc every frame — external poke does NOT persist
- this 0x1DB0: recalc every frame — external poke does NOT persist
- this 0x1DB4: recalc every frame — external poke does NOT persist
- this 0x1DB8: recalc every frame — external poke does NOT persist
- this 0x1DE4: recalc every frame — external poke does NOT persist
- this 0x1DE8: recalc every frame — external poke does NOT persist
- this 0x1DEC: recalc every frame — external poke does NOT persist
- this 0x1DF0: recalc every frame — external poke does NOT persist
- this 0x1DF4: recalc every frame — external poke does NOT persist
- this 0x1DF8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e900 | dbl_59E900 | R | Physics_Double_59E900 [DERIVED] |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059ea68 | dbl_59EA68 | R | WheelSpeedFactor [DERIVED] |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb28 | dbl_59EB28 | R | Damper2MaxAdd [DERIVED] (also: ` — damper 2 max add (range limit) |
| 0059eb30 | dbl_59EB30 | R | EngineOilPressureScale [DERIVED] |
| 0059eb38 | dbl_59EB38 | R | Physics_Double_59EB38 [DERIVED] |
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 0059eba0 | dbl_59EBA0 | R | EnergyToDamageScaleFactor [DERIVED] (also: ` — energy-to-damage conversion factor) |
| 0059ec60 | dbl_59EC60 | R | SuspensionTravelOffset [DERIVED] |
| 0059ec70 | dbl_59EC70 | R | TireMultiplierFactor [DERIVED] |
| 0059ec80 | dbl_59EC80 | R | InputOffsetBias [DERIVED] |
| 0059ec98 | dbl_59EC98 | R | Unknown_Double_Dissipation [DERIVED] |
| 0059eca0 | dbl_59ECA0 | R | TorqueDissipationMult [DERIVED] |
| 0059eca8 | dbl_59ECA8 | R | PhysicsTireDamping [DERIVED] |
| 0059ecb0 | dbl_59ECB0 | R | Engine_ThermalDouble [DERIVED] |
| 0059ecb8 | dbl_59ECB8 | R | Physics_EngineBrakeFactor [DERIVED] |
| 0059ecc0 | dbl_59ECC0 | R | ClutchSlipThreshold [DERIVED] |
| 0059ecc8 | dbl_59ECC8 | R | EngineModelConstant_59ECC8 [DERIVED] |
| 0059ecd0 | dbl_59ECD0 | R | EngineTorqueDecayFactor [DERIVED] |
| 0059ecd8 | dbl_59ECD8 | R | TireGripConst [DERIVED] |
| 0059ece0 | dbl_59ECE0 | R | LifetimeClampThreshold [DERIVED] (also: ` — double threshold constant for lifetime clamp) |
| 0059ece8 | dbl_59ECE8 | R | DissipationThreshold [DERIVED] |
| 0059ecf0 | dbl_59ECF0 | R | EngineDamageCoeff [DERIVED] |
| 0059ecf8 | dbl_59ECF8 | R | EngineThermalEnergyConst [DERIVED] |
| 0059ed00 | dbl_59ED00 | R | DampingFactor [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041ac50 | sub_41AC50 | reset/clear component states on game state struct after failure event |
| 005881f0 | sub_5881F0 | compute pseudo-random value (likely noise/timing input) |

**Guard conditions:** No single dominating guard — function flows through multiple internal branches based on temperature thresholds (coolant < max, oil > 373.16), stress accumulator sign, and component failure probabilities. The main early-exit guard is `*(double *)(this + 7604) > 0.0` (component stress still accumulating) — if true, function processes failure probability and returns early without thermal update. If false (stress exhausted/recovering), proceeds to thermal equilibrium computation.
