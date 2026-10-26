## EngineStressSimulation_0043ef20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x2C | R | — | [LLM] |
| *(this+0x15F0) | 0x44 | R | — | [LLM] |
| *(this+0x15F0) | 0x5C | R | — | [LLM] |
| *(this+0x15F0) | 0x64 | R | — | [LLM] |
| *(this+0x15F0) | 0x6C | R | — | [LLM] |
| *(this+0x15F0) | 0x74 | R | — | [LLM] |
| *(this+0x1D4) | 0xAC | RW | — | [LLM] |
| *(this+0x1D4) | 0xB4 | RW | — | [LLM] |
| *(this+0x1F00) | 0x4068 | RW | 1 | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x19C | RW | 0 | [LLM] |
| this | 0x1A0 | RW | 0 | [LLM] |
| this | 0x1AC | R | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1D4 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1C5C | R | — | [LLM] |
| this | 0x1CFC | R | — | [LLM] |
| this | 0x1D08 | R | — | [LLM] |
| this | 0x1D4C | RW | — | [LLM] |
| this | 0x1D50 | RW | — | [LLM] |
| this | 0x1D54 | R | — | [LLM] |
| this | 0x1D5C | R | — | [LLM] |
| this | 0x1D64 | R | — | [LLM] |
| this | 0x1D6C | R | — | [LLM] |
| this | 0x1D74 | RW | — | [LLM] |
| this | 0x1D7C | R | — | [LLM] |
| this | 0x1D84 | R | — | [LLM] |
| this | 0x1D8C | RW | — | [LLM] |
| this | 0x1D94 | R | — | [LLM] |
| this | 0x1D9C | R | — | [LLM] |
| this | 0x1DA4 | RW | — | [LLM] |
| this | 0x1DAC | RW | 858993459 | [LLM] |
| this | 0x1DB0 | RW | 1071854387 → 1.775f | [LLM] |
| this | 0x1DB4 | RW | 0 | [LLM] |
| this | 0x1DB8 | RW | 0 | [LLM] |
| this | 0x1DE4 | RW | 0 | [LLM] |
| this | 0x1DE8 | RW | 0 | [LLM] |
| this | 0x1DEC | RW | 0 | [LLM] |
| this | 0x1DF0 | RW | 0 | [LLM] |
| this | 0x1DF4 | RW | 0 | [LLM] |
| this | 0x1DF8 | RW | 0 | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

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
| 0041ac50 | sub_41AC50 | [LLM] |
| 005881f0 | sub_5881F0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
