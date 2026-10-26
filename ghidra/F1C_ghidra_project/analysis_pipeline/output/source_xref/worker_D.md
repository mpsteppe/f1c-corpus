# Source Cross-Reference: docs/03-engine-wear-damage.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| Steward (`.?AVSteward@@`) | FUN_004d36d0, FUN_004d38f0, FUN_004d4600 | HIGH | Steward system Setup/Init/Cleanup. rFactor Dedicated.exe RTTI lists `.?AVSteward@@`. Source path `..\Source\steward.cpp` in both rFactor.exe and F1C assert strings. FUN_004d36d0 registers VEHICLE/TIMING/PITSTOP callbacks. FUN_004d38f0 allocates arrays by `DAT_005ea3fc`, locates XPITIN/XPITOUT/XFINISH polygons. |
| Weather (`.?AVWeather@@`) | Indirect: FUN_0047eb70 reads `DAT_007cf134` | MED | UI message dispatch switch at codes 0x1e4–0x1f9 reads weather mode. rFactor RTTI has `.?AVWeather@@`. Source `weather.cpp` shared. |
| GameComponent (`.?AVGameComponent@@`) | All steward functions | MED | Steward is a GameComponent subclass in rFactor class hierarchy. `GameComponent` listed in rFactor Dedicated RTTI. Steward::Setup/Init/Cleanup matches component lifecycle pattern. |
| MechFailureRate (`.?AV?$PFData@W4MechFailureRate@@@@`) | FUN_004aa270 (FailureRate[0..6]) | HIGH | rFactor Dedicated has `MechFailureRate` enum type in PFData template instantiation. F1C's FailureRate[0..6] with {current=2, min=0, max=3} matches this enum for setting mechanical failure rates across 7 categories. |

**Note on HDVehicle:** No RTTI entry for `HDVehicle` found in any rFactor binary. Likely compiled without RTTI (`/GR-`) for performance-critical vehicle physics classes. Source paths confirm `hdvehicle.cpp` and `vehload.cpp` as the source modules for engine parser, damage model, and fuel/consumption functions.

---

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| BrakeWearRate | FRONTLEFT/REARLEFT/REARRIGHT | +0xf0 (per wheel) | BrakeWearRate | BrakeWearRate | HIGH — Parameter name exact match. Confirmed across NASCAR_2003_Demo, NASCAR_2004_Demo, rFactor HDV files. Meters of wear per second at optimum temp. |
| BrakeFailure | FRONTLEFT/REARLEFT/REARRIGHT | min:+0xf8, max:+0x100 | BrakeFailure min/max | BrakeFailureDiscThickness | HIGH — rFactor HDV: `BrakeFailure=(avg_thickness, variation)`. F1C loads two values at +0xf8/+0x100 confirming same tuple. |
| BrakeRotting | — | — | — | BrakeDiskThickness | MED — Not found in F1C offsets but present in F1_2000 FAILURES section as `brake_lifetime`/`brake_variance` (F1_2000 naming convention, not camelCase). |
| BrakeOptimumTemp | FRONTLEFT/REARLEFT/REARRIGHT | +0xb8 | BrakeOptimumTemp | BrakeOptimumTemp | HIGH — rFactor: `BrakeOptimumTemp=250.0` (optimum brake temp in Celsius). F1C applies +273.15K offset at load. |
| BrakeGlow | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeGlowTempRange | MED — rFactor HDV: `BrakeGlow=(750.0,1000.0)` temperature range. Not yet documented in F1C offsets but likely in wheel corner struct near +0xc0. |
| BrakeTorque | FRONTLEFT/REARLEFT/REARRIGHT | — | — | MaxBrakeTorque | MED — rFactor: 3985.0 per corner. Present in every ISI HDV since NASCAR 2003. Likely in wheel struct, offset undoc'd. |
| BrakeHeating | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeHeatingRate | MED — rFactor: 0.00191. Heat added linearly with brake torque × wheel speed. |
| BrakeCooling | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeCoolingRate | MED — rFactor: `(min_cooling, per_velocity_cooling)`. Per-wheel cooling params. |
| BrakeResponseCurve | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeResponseCurve | MED — rFactor: `(cold_temp, opt_min, opt_max, overheated_temp)`. 4-value curve mapping temp→grip. |
| BrakeDiscInertia | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeDiscInertia | MED — rFactor: 0.820 inertia per meter thickness. |
| BrakeDiscRange | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeDiscThicknessRange | MED — rFactor: `(0.026, 0.001, 3)` thickness, step, steps. |
| BrakeDuctCooling | FRONTLEFT/REARLEFT/REARRIGHT | — | — | BrakeDuctCoolingRate | MED — rFactor: 0.8000e-04 cooling rate per duct setting. |
| CombustionHeat | Engine (external .ini) | +0x12d0 | CombustionHeat | CombustionHeat | HIGH — rFactor: 64.1 °C per liter fuel burned. NASCAR 2003: 34.8. Confirmed as 8-byte double at F1C offset. |
| OilMinimumCooling | Engine | +0x12e0 | OilMinimumCooling | OilMinimumCooling | HIGH — rFactor: engine .ini parameter. First of the thermal cooling pair. |
| OilWaterHeatTransfer | Engine | +0x12e8/+0x12f0 | OilWaterHeatTransfer (param 1/2) | OilWaterHeatTransferPair | HIGH — Two double parameters at consecutive offsets. Matches rFactor engine ini pattern. |
| WaterMinimumCooling | Engine | +0x12f8 | WaterMinimumCooling | WaterCoolingRate | HIGH — Water cooling minimum. |
| RadiatorCooling | Engine | +0x1300/+0x1308 | RadiatorCooling min/max | RadiatorCoolingRange | HIGH — Two doubles: min and max radiator cooling. |
| FuelConsumption | HDV GENERAL (via engine file) | +0x674 | FuelConsumption | FuelConsumption | HIGH — Raw double, no transform at load. |
| FuelEstimate | HDV GENERAL | +0x67c | FuelEstimate | FuelEstimate | HIGH — Fuel usage estimate for pit strategy. |
| EngineInertia | Engine | +0x684 | EngineInertia | EngineInertia | HIGH — Rotational inertia of engine assembly. |
| IdleRPMLogic | Controls/AI | +0x68c min, +0x694 max | IdleRPMLogic | IdleRPMLogicRange | HIGH — RPM×π/30 at load. |
| LaunchRPMLogic | Controls/AI | +0x6ac min, +0x6b4 max | LaunchRPMLogic | LaunchRPMLogicRange | HIGH — RPM×π/30 at load. |
| RevLimitLogic | Engine | +0x6bc | RevLimitLogic | RevLimitLogic | HIGH — RPM×π/30 at load. |
| LifetimeAvg | Engine | +0x1330 | LifetimeAvg | LifetimeAvg | HIGH — Mean engine life in seconds. |
| LifetimeVar | Engine | +0x1338 | LifetimeVar | LifetimeVar | HIGH — Variance of engine life. Scaled by per-vehicle random at spawn. |
| LifetimeEngineRPM | Engine | +0x1310 min, +0x1318 max | LifetimeEngineRPM min/max | LifetimeEngineRPMLimits | HIGH — RPM×π/30 at load. Defines RPM range that wears engine. |
| LifetimeOilTemp | Engine | +0x1320 min, +0x1328 max | LifetimeOilTemp min/max | LifetimeOilTempLimits | HIGH — +273.15K at load. Temp range accelerates wear. |
| Mass | GENERAL | — | — | VehicleMass | MED — Not in doc offsets but rFactor: `Mass=603.0`. Base vehicle struct. |
| Inertia | GENERAL | — | — | VehicleInertia | MED — rFactor: `Inertia=(664.0, 758.0, 127.0)`. Pitch, Yaw, Roll. |
| CGHeight | GENERAL | — | — | CGHeight | MED — rFactor: 0.1720m above ref plane. |
| FrontWingDetach | PHYSICAL (damage.ini) | +0x1c | FrontWingDetach | FrontWingDetachThreshold | HIGH — rFactor damage.ini AeroMin/AeroDiv params. DOCUMENTED in FUN_004f24f0. |
| RearWingDetach | PHYSICAL (damage.ini) | +0x4c | RearWingDetach | RearWingDetachThreshold | HIGH — Same pattern as front wing. |
| WheelDetach | PHYSICAL (damage.ini) | +0x80 | WheelDetach | WheelDetachThreshold | HIGH — rFactor: `AeroDiv` (1.25e-5) and `AeroMin` (1750.0) govern thresholds. |
| WheelRandom | PHYSICAL (damage.ini) | +0x84 | WheelRandom | WheelRandomFailureChance | HIGH — Random wheel failure chance param. |
| ActivateInstance | PHYSICAL (damage.ini) | — | — | DamageActivateInstance | MED — rFactor: `ActivateInstance=HighDetailEngine` — which instance to activate when parts detach. Not in F1C doc but likely parsed by FUN_004f24f0. |
| AeroDiv | PHYSICAL (damage.ini) | +0x10 | AeroDiv | AeroDivImpulseMult | HIGH — rFactor: 1.25e-5. Multiplied by impulse for aero/vertex damage. |
| AeroMin | PHYSICAL (damage.ini) | +0x14 | AeroMin | AeroMinImpulse | HIGH — rFactor: 1750.0. Minimum impulse for aero damage (before damage multiplier). |

---

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `CombustionHeat` | NASCAR_2003_Demo, rFactor config_params | FUN_004f3c80 (+0x12d0) | Confirms CombustionHeat is loaded at engine section parse time. Cross-game: NASCAR 2003 uses 34.8, rFactor uses 64.1 °C/L. |
| `Engine Damaged` | NASCAR_2003_Demo unique (string_crossref) | FUN_0043ef20 | Confirms engine damage state exists as a HUD/message concept. F1C triggers this via ReasonCode=1. |
| `EngineBrakeMapRange` | NASCAR_2003_Demo unique | Not yet mapped | Engine braking map UI — not a physics parameter. NASCAR-unique UI string. |
| `EngineBrakeMapSetting` | NASCAR_2003_Demo unique | Not yet mapped | Same — engine brake map garage setting. |
| `EngineFadeRadius` | NASCAR_2003_Demo unique | FUN_0049db80? | Engine sound fade radius — likely audio, not physics. |
| `*.hdv file references unknown tire compound "%s"` | NASCAR_2003_Demo, rFactor | FUN_004f3c80 parent parser | Confirms HDV parsing code shared between ISI titles. |
| `brake_lifetime` / `brake_variance` | F1_2000 FAILURES section (config_params) | FUN_004f24f0 (damage model) | F1_2000 had simpler brake lifetime model with single avg+variance pair. F1C expanded to per-corner BrakeWearRate+B details. Shows evolution: F1_2000→F1C→rFactor. |
| `BrakeFadeRange` | NASCAR_2003_Demo, rFactor (config_params) | Wheel corner struct | Brake fade: temp outside optimum where grip drops to half. Not explicitly in F1C doc but likely in wheel struct near BrakeOptimumTemp. |

---

## SDK Struct Alignment

Comparing F1C vehicle struct offsets (from 03-engine-wear-damage.md) against rFactor SDK structs.

### FinishStatus Field

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| VehicleScoringInfo::mFinishStatus (0=none, 1=finished, 2=dnf, 3=dq) | VSI +0x63 | F1C +0x4068 | **MATCH** — Same enum values. F1C doc: "0=running, 1=finished, 2=DNF, 3=DSQ". SDK: "0=none, 1=finished, 2=dnf, 3=dq". Minor naming diff (running vs none), functionally identical. |

### BestLapTime Field

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| VehicleScoringInfo::mBestLapTime (float) | VSI +0x78 | F1C +0x409c | **MATCH** — Both float, both store best lap time. F1C offset in vehicle struct (param_1). SDK offset in VSI substruct. |

### ReasonCode / Failure Data

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| TelemInfoV2::mLastImpactMagnitude (float) | TelemInfoV2 +0x12B | F1C +0x4068 (ReasonCode stores failure type) | **MISMATCH** — F1C at +0x4068 stores ReasonCode (int: 1=engine, 2=suspension, 4=brake, 5=gearbox, 9=fuel). SDK stores float mLastImpactMagnitude at similar offset in different struct. These are completely different struct layouts. |
| TelemInfoV2::mDetached (bool) | TelemInfoV2 +0x11E | Not mapped | **MISSING** — F1C likely has equivalent flag in vehicle struct but not yet documented. |
| TelemInfoV2::mDentSeverity[8] (uchar[8]) | TelemInfoV2 +0x11F | Not mapped | **MISSING** — F1C has damage body mapping but dent severity undocumented. |

### ScoringInfoV2 GamePhase

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| ScoringInfoV2::mGamePhase (0–8) | ScoringInfoV2 +0x5C | DAT_007c56a8 (RacePhase 0–7) | **MATCH** — F1C's RacePhase (0–7) overlaps with SDK mGamePhase (0–8). SDK has extra phase 5 (Full course yellow). F1C may not have had full-course yellow system in 2002. |
| ScoringInfoV2::mMaxLaps (long) | ScoringInfoV2 +0x4C | DAT_008acf9c (TotalRaceLaps) | **MATCH** — Both store total race laps. |
| ScoringInfoV2::mRaining (float) | ScoringInfoV2 +0xC8 | DAT_007cf080 (WeatherMode 0–5) | **PARTIAL** — F1C stores weather as integer mode enum (0–5). SDK stores as float 0.0–1.0 severity. F1C's model is simpler/categorical. |

### TelemWheel Comparison

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| TelemWheel::mBrakeTemp (float, Celsius) | +0x18 | DAT_007c7ab8 (FL), DAT_007c7f1c (FR), DAT_007c8380 (RL), DAT_007c87e4 (RR) | **MATCH** — F1C stores brake temp as globals per corner. SDK stores per wheel in TelemWheel struct. F1C offsets suggest a per-wheel array starting near +0x668 or similar (not fully documented). Brake temp globals are copies/mirrors of per-wheel data. |
| TelemWheelV2::mWear (float, 0.0–1.0) | TelemWheelV2 +0x2C | Not mapped | **MISSING** — Tire wear fraction. F1C likely stores per-tire wear in vehicle struct but not yet documented in this doc. See docs/04-tire-system.md. |
| TelemWheelV2::mSurfaceType (uchar: 0=dry,1=wet,2=grass,3=dirt,4=gravel,5=rumble) | TelemWheelV2 +0x40 | Not mapped | **MISSING** — F1C track surface system likely stores this. |

---

## Proposed Renames / Corrections

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_004f3c80 name: "Engine Section Parser" | "EngineAndThermalParser (vehload)" | rFactor HDV [ENGINE] section references external ini file for torque curves but thermal params (CombustionHeat, OilWaterHeatTransfer, RadiatorCooling) are embedded in HDV/binary files. F1C loads both thermal model and RPMTorque data from same section. |
| BrakeFailure min/max name ambiguity | BrakeFailureThicknessAvg / BrakeFailureThicknessVar | rFactor HDV has `BrakeFailure=(avg, variation)` as a tuple representing disc thickness at failure, not separate failure modes. F1C stores as two doubles. |
| +0x12e8 name "OilWaterHeatTransfer (param 1)" | OilWaterHeatTransferRate | rFactor engine ini has single heat transfer value — F1C dividing into two parameters may represent transfer rate + saturation point. |
| +0x12f0 name "OilWaterHeatTransfer (param 2)" | OilWaterHeatTransferSaturation | See above. |
| LifetimeEngineRPM min/max naming | LifetimeEngineRPMLimits (min/max) | Consistent with SDK naming pattern. The "min/max" in current name is already clear. |
| "EffectiveEngineLifetime" field name | LifetimeRemainingSeconds | At +0x1db4, after spawn formula produces (avg + var×random), then scaled per-lap. "Remaining" is more accurate than "Effective" since it counts down. |

---

## Additional Notes

1. **F1_2000→F1C→rFactor evolution of failure model:**
   - F1_2000: Simple `brake_lifetime` + `brake_variance` per vehicle in FAILURES section. Single fixed failure model.
   - F1C: Per-corner brake wear (`BrakeWearRate`), disc thickness at failure (`BrakeFailure`), optimum temperature window (`BrakeOptimumTemp`), thermal model. `EngineWearMode` enum (0=off, 2=random, 3=scripted). Damage model with detach thresholds per part. Much more complex.
   - rFactor: Adds `BrakeGlow`, `BrakeResponseCurve`, more granular cooling (`BrakeDuctCooling`). `AITireModel`, `AIWear` for AI-specific parameters. `MechFailureRate` enum type in settings.

2. **EngineWearMode enum (DAT_007cea5c):** The enum values (0/2/3) match the `Rules` parameter pattern in rFactor HDV where `Rules=0` means no rules, `Rules=1` means stock car rules. F1C's 0=disabled, 2=random, 3=scripted is a simpler variant.

3. **Damage model struct alignment:** The PHYSICAL section struct (FUN_004f24f0) with offsets +0x00 to +0x250 matches rFactor damage.ini structure:
   - AeroDiv, AeroMin, VertMult at same relative positions
   - Part detach thresholds follow wheel params
   - rFactor adds `ActivateInstance` referencing lod instances — F1C may not have this

4. **RPMTorque curve format:** `(rpm, torque_throttle, torque_brake)` tuple matches rFactor engine .ini format. Brake torque entry confirms engine braking simulation.

5. **Reciprocal storage pattern:** F1C stores `1/NaturalRPM` and `1/LifetimeOilTemp_max` as precomputed reciprocals. This matches the performance optimization pattern seen across all isiMotor 1.x code — division at load, multiply per tick.
