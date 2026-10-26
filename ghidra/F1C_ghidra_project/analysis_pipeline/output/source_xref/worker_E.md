# Source Cross-Reference: docs/04-tire-system.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| (no tire class in RTTI) | all | HIGH | Tire system is module-based (`tire_manager.cpp`), not class-hierarchy-based. rFactor RTTI has no `TireManager`, `TireCompound`, `SlipCurve` classes. Tire data is aggregated into the HDVehicle struct. |
| `?AV?$PFData@W4MechFailureRate@@@@` (PFData enum) | FUN_004d6b00 (compound parser) | MED | Compound parser reads WearRate which feeds into mech failure system. PFData template used for config parameter storage — tire wear is a failure-rate-like parameter. |
| `?AVPitMan@@` | FUN_00454350 (pit-crew tire activities) | MED | PitMan maps action codes to tire changes. The pitcrew tire compound selection UI feeds from the same tire arrays. rFactor RTTI confirms `PitMan` class. |

## RTTI Enum Types Relevant to Tire System

| rFactor Enum | F1C Equivalent | Insight |
|-------------|---------------|---------|
| `MechFailureRate` | TireWearMode / EngineWearMode (DAT_007cea5c) | Tire wear operates on same mechanic failure rate paradigm. rFactor uses PFData<MechFailureRate> for tire wear configuration. |
| `FormationAndStart` | n/a (session-level) | Tire choices affect formation/start strategy, but no direct mapping. |
| `WeatherCond` | WeatherMode (DAT_007cf080) | Tire compound selection (wet/intermediate) depends on WeatherCond. |

## Parameter-to-Offset Mappings

### From config_params.txt COMPOUND section + rFactor .tbc files

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| WearRate | COMPOUND (.tbc) | +0xe0 | WearRate (player) | CompoundWearRate | HIGH — rFactor .tbc field name matches F1C usage |
| AIWear | COMPOUND (.tbc) | +0x110 | AIWear | CompoundAIWearRate | HIGH — rFactor .tbc: "AI wear rate constant" |
| AIGripMult | COMPOUND (.tbc) | +0x100 | AIGripMult | CompoundAIGripMult | HIGH — rFactor .tbc: "Grip multiplier for AI vehicles" |
| AISens | COMPOUND (.tbc) | +0xf0 / +0xf8 | AISens min/max | CompoundAILoadSensitivity | HIGH — config_params: "Simplified AI load sensitivity (final grip mult, final load)" |
| AIPeakSlip | COMPOUND (.tbc) | (not in doc — likely in compound str) | — | CompoundAIPeakSlip | MED — rFactor .tbc: "Simple peak slip angle for AI vehicles" |
| AITireModel | COMPOUND (.tbc) | (not in doc) | — | CompoundAITireModel | MED — rFactor .tbc: "0.0 = original AI tire model... 1.0 = more similar to player tire model" |
| DryLatLong | COMPOUND (.tbc) | (compound struct 0x2a8 stride) | — | CompoundDryLatLong | MED — rFactor .tbc: "Lateral/longitudinal coefficients in dry weather" |
| WetLatLong | COMPOUND (.tbc) | (compound struct) | — | CompoundWetLatLong | MED |
| Radius | COMPOUND (.tbc) | (compound struct) | — | TireRadius | MED — rFactor .tbc: "Radius of tire" |
| Width | COMPOUND (.tbc) | (compound struct) | — | TireWidth | MED |
| SpringBase | COMPOUND (.tbc) | (compound struct) | — | TireSpringBase | MED — rFactor: "Base spring rate with no pressure" |
| SpringkPa | COMPOUND (.tbc) | (compound struct) | — | TireSpringkPa | MED — "Spring rate per unit pressure" |
| Damper | COMPOUND (.tbc) | (compound struct) | — | TireDamper | MED — config_params: "Damping rate of tire" |
| SpeedEffects | COMPOUND (.tbc) | (compound struct) | — | SpeedGripDropoff | MED — "Speed at which grip drops to half" |
| LoadSensLat | COMPOUND (.tbc) | (compound struct) | — | LoadSensitivityLat | MED |
| LoadSensLong | COMPOUND (.tbc) | (compound struct) | — | LoadSensitivityLong | MED |
| LatPeak | COMPOUND (.tbc) | (compound struct) | — | LatSlipPeak | MED — "Slip range where lateral peak force occurs" |
| LongPeak | COMPOUND (.tbc) | (compound struct) | — | LongSlipPeak | MED |
| CamberLatLong | COMPOUND (.tbc) | (compound struct) | — | CamberLatLongGain | MED — config_params: "Peak camber angle, lateral gain at peak, longitudinal loss" |
| RollingResistance | COMPOUND (.tbc) | (compound struct) | — | RollingResistanceTorque | MED |
| PneumaticTrail | COMPOUND (.tbc) | (compound struct) | — | PneumaticTrailRate | MED |
| Heating | COMPOUND (.tbc) | (compound struct) | — | TireHeatingRate | MED — "Heat caused by (rolling, friction)" |
| Transfer | COMPOUND (.tbc) | (compound struct) | — | TireHeatTransfer | MED — "Heat transfer to (road, static air, moving air)" |
| HeatDistrib | COMPOUND (.tbc) | (compound struct) | — | TireHeatDistribution | MED |
| AirTreadRate | COMPOUND (.tbc) | (compound struct) | — | AirTreadHeatTransfer | MED — config_params: "Heat transfer between tread and inside air" |
| WearGrip1/WearGrip2 | COMPOUND (.tbc) | (compound struct) | — | WearGripTable | MED — 16-point grip vs wear lookup table |
| Softness | COMPOUND (.tbc) | (compound struct) | — | CompoundSoftness | MED — "for AI strategic use" |
| Temperatures | COMPOUND (.tbc) | (compound struct) | — | OptimumTireTemp | MED — "Optimum operating temperature for peak forces" |
| OptimumPressure | COMPOUND (.tbc) | (compound struct) | — | OptimumTirePressure | MED |
| GripTempPress | COMPOUND (.tbc) | (compound struct) | — | GripOffTempPressPenalty | MED — "Grip effects of being below temp, above temp, and off-pressure" |
| HeatBasePeak | COMPOUND (.tbc) | (compound struct) | — | HeatBasePeakFactor | MED — rFactor .tbc: "Base peak slip to compute friction heat" |

### From GENERAL section (.hdv)

| Config Param | Section | F1C Offset | Current Name | Confidence |
|-------------|---------|-----------|--------------|------------|
| FrontTireCompoundSetting | GENERAL | +0x1170 (front compound index) | CurrentFrontCompound | HIGH — rFactor .hdv: "Compound index within brand" |
| RearTireCompoundSetting | GENERAL | (compound index, likely near +0x1170 area) | CurrentRearCompound | HIGH |
| TireBrand | GENERAL | (brand manager struct) | TireBrandName | HIGH |

### Pitstop-related tire parameters

| Config Param | Section | F1C Offset | Current Name | Confidence |
|-------------|---------|-----------|--------------|------------|
| NumPitstopsRange | PITMENU | +0x1180 (PitStopFlag bitmask max) | PitStopCountLimit | HIGH — rFactor .hdv: (0, 1, 4) matches doc "Max 4 pitstops confirmed" |
| CompoundRestrictions | PITMENU | (session rules) | CompoundChangeRule | MED — doc confirms compound selection for pitstops 2-4 |

### From FUN_004e88b0 (TireGripCoefficient) offsets

| F1C Offset | Matching Config Param | Match? | Notes |
|-----------|----------------------|--------|-------|
| +0x39b4 (TireGripMode) | none | — | Internal mode selector, not config-file-exposed |
| +0x39c8 (LateralCoeff) | (part of DryLatLong?) | POSSIBLE | DryLatLong has lateral coefficient — may be stored separately at runtime |
| +0x39a8 (LoadSensitivity) | LoadSensLat / LoadSensLong | HIGH | matches config_params: "Load sensitivity for lateral/longitudinal grip" |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `*.hdv file references unknown tire compound "%s"` | NASCAR_2003, NASCAR_2004, rFactor (shared) | FUN_004d6b00 (compound parser) | Compound validation error message shared across all ISI games. Confirms FUN_004d6b00 is the .tbc compound parser. |
| `Hard Compound` / `Soft Compound` / `Intermediate Compound` / `Wet Compound` / `Monsoon Compound` | F1C strings (FUN_004a4830) | FUN_004a4830 | These compound names map to IDs 2-6. rFactor .tbc uses shorter names ("Super Soft", "Soft", "Medium Soft", "Medium", "Hard"). F1C uses compound suffix convention. |
| `APP_SpinBox_GameOpt_TireWear` | NASCAR_2003/2004, rFactor (shared) | (UI code) | Tire wear game option shared across all ISI games. |
| `APP_SpinBox_GameOpt_CH_TireWear` | NASCAR_2004 (unique) | (UI code) | Championship mode tire wear separate control. |
| `APP_SpinBox_GameOpt_MP_TireWear` | NASCAR_2004 (unique) | (UI code) | Multiplayer tire wear separate control. |
| `APP_TextValue_GarageTireLoad_FrontLeft` etc. | NASCAR_2003/2004 (shared) | (garage UI) | Tire load display shared across ISI games. F1C likely has similar UI structure. |
| `APP_Picture_TireDisplay` | NASCAR_2003/2004 (shared) | (UI code) | Tire display UI component shared. |
| `Tire Compound:` | NASCAR_2003 Patch (unique) | (UI text) | Tire compound selection label in NASCAR UI. |
| `TireWearMulti` | NASCAR_2003 Patch (unique) | DAT_007d0c60 (TireWearMultiplier) | Global variable name partially confirmed by NASCAR string. |
| `APP_TextValue_GarageFLTirePressure` etc. | NASCAR_2004 (unique) | (garage UI) | Tire pressure display in garage. |

## SDK Struct Alignment

### TelemWheel (rFactor SDK) vs F1C Vehicle Tire Telemetry

| SDK Field | SDK Type | SDK Offset | F1C Offset Range | Status | Notes |
|-----------|----------|-----------|-------------------|--------|-------|
| mRotation | float | +0x00 | +0x1140 (front) | SHIFTED | F1C stores as double (8 bytes). Front axle block at 0x1140, rear at 0x153c. F1C likely has 8 doubles = 64 bytes per axle vs rFactor's 11 floats = 44 bytes. |
| mSuspensionDeflection | float | +0x04 | +0x1148 | SHIFTED | Same double vs float difference. |
| mRideHeight | float | +0x08 | +0x1150 | SHIFTED | Double storage. |
| mTireLoad | float | +0x0C | (part of double×8 block) | SHIFTED | Could be any of the 8 doubles at 0x1140-0x115c. |
| mLateralForce | float | +0x10 | (part of double×8 block) | SHIFTED | — |
| mGripFract | float | +0x14 | (part of double×8 block) | SHIFTED | — |
| mBrakeTemp | float | +0x18 | (part of double×8 block) | SHIFTED | — |
| mPressure | float | +0x1C | (part of double×8 block) | SHIFTED | — |
| mTemperature[3] | float[3] | +0x20 | (part of double×8 block) | SHIFTED | Three temps (left/center/right) per SDK. F1C may store as 3 doubles. |
| mWear (V2) | float | +0x2C | (not in doc — likely elsewhere) | MISSING | Wear fraction. F1C wear stored as discrete WearRate-based accumulation. |
| mTerrainName[16] (V2) | char[16] | +0x30 | (not in doc) | MISSING | Surface material name. F1C may have this elsewhere. |
| mSurfaceType (V2) | uchar | +0x40 | (not in doc) | MISSING | 0=dry, 1=wet, etc. |
| mFlat (V2) | bool | +0x41 | (not in doc) | MISSING | — |
| mDetached (V2) | bool | +0x42 | (not in doc) | MISSING | — |

**Overall Alignment Assessment:** F1C tire telemetry struct is **SHIFTED** relative to rFactor. Key differences:
1. F1C uses **double** (8 bytes) where rFactor uses **float** (4 bytes)
2. F1C organizes by axle (front block +0x1140, rear block +0x153c) rather than per-wheel array
3. F1C has separate compound/state flag arrays (byte[16] at +0x1160 and +0x155c) not present in SDK
4. F1C has compound index ints (+0x1170) and pitstop compound selections (+0x1174-0x117c)

The compound struct (stride 0x2a8 = 680 bytes) likely contains all .tbc COMPOUND fields for front+rear pairs. rFactor .tbc shows 35+ parameters per compound axis (FRONT/REAR), each typically a float, double, or tuple.

### Tire compound struct stride validation

| Property | rFactor .tbc Evidence | F1C Docs | Match? |
|----------|----------------------|----------|--------|
| Compound stride | — | 0x2a8 (680 bytes) | Can't directly validate, but 35+ fields per axis × 2 axes (FRONT/REAR) × 8 bytes (F1C doubles) ≈ 560+ bytes, plus metadata → 680 plausible |
| Slipcurve stride | — | 0x18 (24 bytes) | rFactor .tbc SLIPCURVE section: name + step + dropoff function + data points. 24 bytes plausible for header metadata. |
| Brand array stride | — | 0x24 (36 bytes) | Name ptr + slipcurve count + slipcurve ptr + compound count + compound ptr + padding = ~36 bytes plausible. |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| +0xe0 "WearRate (player)" | CompoundWearRate | rFactor .tbc field name `WearRate` confirmed in config_params.txt and hdv_pm_full.txt (rFactor .tbc line 3668). |
| +0x110 "AIWear" | CompoundAIWearRate | rFactor .tbc field `AIWear` (line 3675): "AI wear rate constant". |
| +0x100 "AIGripMult" | CompoundAIGripMult | rFactor .tbc field `AIGripMult` (line 3672): "Grip multiplier for AI vehicles (due to tire model simplification)". |
| +0xf0/+0xf8 "AISens min/max" | CompoundAILoadSensitivity | config_params.txt `AISens`: "Simplified AI load sensitivity (final grip mult, final load)". Matches pair semantics. |
| +0x39a8 "LoadSensitivity" | CompoundLoadSensitivity | rFactor .tbc field `LoadSensLat` / `LoadSensLong` (lines 3653-3654). F1C separate field likely stores combined runtime value. |
| +0x39c8 "LateralCoeff" | CompoundDryLatLateral | rFactor .tbc field `DryLatLong` first component (line 3643): "Lateral/longitudinal coefficients in dry weather". |
| +0x1180 "PitStopFlag bitmask" | PitStopFlag (keep) | Confirmed — rFactor .hdv: `NumPitstopsRange=(0, 1, 4)` matches "Max 4 pitstops confirmed". Bit 0x100/0x200/0x400 maps to stops 2/3/4. |

## Cross-Binary Source Path Confirmation

| Source Path | Binary | F1C Function(s) | Insight |
|------------|--------|----------------|---------|
| `..\Source\tire_manager.cpp` | rFactor, NASCAR_2003/2004 | FUN_004d6b00, FUN_004d7150, FUN_004d5f70, FUN_004d7660, etc. | Confirms this source file exists across all ISI games. rFactor and NASCAR source strings both reference `tire_manager.cpp`. |
| `D:\Dev\NASCAR_2003\Source\tire_manager.cpp` | NASCAR_2003_Demo (unique) | — | Developer path for the tire manager module. F1C equivalent likely at `D:\dev\F1_1999_2002\Source\tire_manager.cpp`. |
| `D:\dev\F1_1999_2002\Source\` | F1C (assert strings) | all | Root dev directory confirmed by assert strings in executable. dev_tree.txt places F1C retail here. |

## Key Discoveries

1. **AI tire params separated from player**: rFactor .tbc confirms `AIGripMult`, `AIWear`, `AIPeakSlip`, `AITireModel`, `AISens` (LoadSensitivity for AI) are per-compound fields. F1C doc's Layout section with AI-gated offsets (+0xe0, +0xf0, +0xf8, +0x100, +0x110) aligns perfectly with rFactor convention.

2. **WearGrip table**: rFactor .tbc has `WearGrip1` (8 values at 6-50% wear) and `WearGrip2` (8 values at 56-100% wear) — not documented in F1C. This 16-point grip-vs-wear curve determines how grip degrades. F1C likely has equivalent within compound struct but not yet documented.

3. **Thermal model confirmed**: rFactor .tbc has `Heating`, `Transfer`, `AirTreadRate`, `HeatBasePeak`, `HeatDistrib`, `GripTempPress` — all thermal model parameters. F1C doc does not document tire thermal model in compound struct yet.

4. **Slip curve normalization**: rFactor .tbc comment (lines 3500-3503) confirms "automatically normalized to have a peak of 1.0" — exactly what FUN_004d5f70 does (normalizes all coefficients by peak grip). Confirms FUN_004d5f70 is the slip curve parser.

5. **F1C tire telemetry is double-based**: While rFactor SDK uses floats, F1C uses doubles for tire telemetry. Any reimplementation must account for 8-byte alignment vs rFactor's 4-byte layout.
