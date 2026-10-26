# Moddable Fields — All Discovered Writable Game Parameters

All data file fields confirmed readable by the game engine at runtime.
These are the parameters a mod can change via `.svm`, `.hdv`, `.rcd`, `.tbc`,
`.gdb`, `.veh`, `.scn`, or setup files to alter game behavior.

Organized by subsystem. Each field includes: file format, parser function, and effect.

---

## Engine Power

Source: `FUN_004f3c80` (engine section parser), `.svm`/`.hdv` files.

- `FuelConsumption`, `FuelEstimate`, `EngineInertia`
- `IdleRPMLogic` (min/max), `IdleThrottle`
- `LaunchRPMLogic` (min/max), `RevLimitLogic`
- `RPMTorque` curve (power band — rpm/torque_throttle/torque_brake points)

## Engine Thermal

Source: `FUN_004f3c80`, `.svm`/`.hdv` files.

- `OptimumOilTemp`, `CombustionHeat`, `EngineSpeedHeat`
- `OilMinimumCooling`, `OilWaterHeatTransfer`, `WaterMinimumCooling`
- `RadiatorCooling` (min/max)

## Engine Misc

- `EngineEmission` (3 values), `OnboardStarter`, `StarterTiming` (3 values)

---

## Damage Model

Source: `FUN_004f24f0`, `.svm`/`.hdv` files.

- FrontWingDetach, FrontWingRandom
- RearWingDetach, RearWingRandom
- WheelDetach, WheelBend, WheelRandom
- Part0–7 Detach, Random (8 detachable parts)
- RadiusAdd, RadiusMult, RadiusMax (body collision)
- AeroDiv, AeroMin, VertMult

## Engine RPM Per Gear

Source: `FUN_004f6bf0`, `.svm`/`.hdv` files.

- MinimumRPM, MaximumRPM, NaturalRPM per gear (5 gears)

---

## Track Surface

Source: `FUN_004cdd80`, track terrain config.

- GripLevel, Resistance, BumpAmp, BumpWaveLen, Spring, Damper, CollFrict per material type

## AI Grip

Source: `FUN_004cf070` (SpecialFX::Init), track-specific.

- AIDryGrip, AIWetGrip (track-specific AI grip multipliers)

---

## Season and Scoring

Source: `FUN_004c2a80` / `FUN_004c0910`.

- `SeasonScoringInfo` — championship points table. Parsed via `thunk_FUN_0059d6a9`
  (1-indexed finish position to points). Only active when `DAT_007d0410` (RaceMode) == 3 or 4.

## Career/Season Config

- `SceneOrder`, `SeasonRaces`, `EventName`, `TrackName`, `SettingsFolder`,
  `AutoLoadEntry`, `Nationality` — UI/session-config fields. Not physics-affecting.

---

## Gearbox

Source: `FUN_0059d822` / `FUN_0059d8ab` (docs/10).

Setup adjustment fields for gear ratios. Format: `.svm` or setup file, range [0, 0x3ff00000).

- Gear7Setting, Gear8Setting, Gear9Setting, Gear10Setting
- Same pattern as Gear1–6Setting (FinalDriveSetting/ReverseSetting already documented)

## Brakes

Source: `FUN_00447d00` (docs/10).

- Brake bias: driver-adjustable, `index * slope + intercept` formula
- Display format: `"%4.1f:%4.1f"` (rear:front split)
- Fields: bias slope (`_DAT_0059ea20`), bias intercept, max bias index
- Stored in vehicle struct +0x1564–0x1580

---

## Tires

### Compound IDs

Source: `FUN_004a4830` (docs/04). `.tbc` `[COMPOUND]` section.

| ID | Name |
|----|------|
| 2 | Hard Compound |
| 3 | Soft Compound |
| 4 | Intermediate Compound |
| 5 | Wet Compound |
| 6 | Monsoon Compound |

---

## Weather

### Wetness Multipliers

Source: `FUN_004fe0d0` (docs/05). `.gdb` Weather section.

| Name | Wetness |
|------|---------|
| Clear | 0.0 (dry) |
| Overcast | ~0.007 |
| Drizzle | ~0.34 |
| Monsoon | ~0.61 |

### Grip Multipliers

Source: `FUN_004fe1e0` (docs/05). `.gdb` Weather section.

| Name | Grip reduction |
|------|----------------|
| Normal | 0.0 (full grip) |
| Soaked | ~0.05 |
| Monsoon | 1.0 (no grip) |

---

## Pit Strategy

### Pit Window Timing

Source: `FUN_0059d74e` (docs/06). `.gdb` track config.

- `ReconPitOpen` → `DAT_007cec30` (pit window open time, float seconds)
- `ReconPitClosed` → `DAT_007cec54` (pit close time, float seconds)
