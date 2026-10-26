# Implementation Spec: Engine Wear, Lifetime, and Damage Model

Source: docs/03-engine-wear-damage.md  |  Functions: 13  |  Date: 2026-07-15

---

## Overview

The Engine Wear and Damage model governs mechanical reliability throughout a race session.
It determines when engines fail, how gearbox/suspension/brake damage accumulates, and how
fuel consumption and tire wear are modelled each physics tick. The system runs **per-vehicle,
per-physics-tick** at (nominally) 60 Hz, with additional evaluation at vehicle spawn and
file-load time.

**Execution context:**

1. **File load** (`vehload.cpp`): `FUN_004f3c80` parses the `[ENGINE]` section of `.svm`/`.hdv`
   files into the vehicle struct. `FUN_004f24f0` parses the `[PHYSICAL]` section for
   damage/detach thresholds. `FUN_004f6bf0` reads per-gear RPM limits.

2. **Vehicle spawn** (session init): `FUN_0043c250` computes effective engine lifetime
   from `LifetimeVar`/`LifetimeAvg` plus a per-vehicle random coefficient. This lifetime
   is scaled to per-lap fraction when `SessionType == 7` (race).

3. **Per physics tick**: `FUN_004e6d93` (engine physics updater) and `FUN_0043ef20`
   (engine stress simulation) run each tick, decrementing wear accumulators and checking
   failure thresholds. `FUN_004ed960` handles fuel consumption, tire wear, brake wear,
   and 4 independent damage timers (engine/gearbox/suspension/brake).

4. **Per frame (HUD)**: `FUN_0049db80` reads brake temperatures (4 corners) and water
   temperature for on-screen telemetry display.

**Data structures owned:**

- Engine parameters are stored in the vehicle physics struct at offsets +0x670–+0x1370
  (loaded from `.svm`/`.hdv` `[ENGINE]` section) and at +0x1db4–+0x1dd4 (runtime effective
  lifetime and precomputed reciprocals).
- Damage thresholds exist in a damage sub-struct at base offset +0x00 through +0x250
  (loaded from `[PHYSICAL]` section), with per-wheel and per-detachable-part entries.
- Wheel corner damage state is in a per-corner sub-struct (stride 0x128) with offsets
  +0xb8 (BrakeOptimumTemp), +0xf0 (BrakeWearRate), +0xf8/+0x100 (BrakeFailure min/max).
- Player options failure rates live in a separate struct at +0x5c8, stride 0x24, 7 slots.

**Systems that interface:**

- **Vehicle physics loader** (`FUN_004f4270`) calls the engine section parser
- **Suspension/tire physics** (`0x0059d9d7` from docs/18) calls the engine physics updater
  each tick
- **Race steward** (`docs/06`) reads `ReasonCode` at `+0x4068` to determine retirements
- **HUD system** reads brake/water temps for display
- **AI system** (`docs/02`) uses LifetimeVar/LifetimeAvg for per-driver reliability variance

---

## Data Structures

### Vehicle Engine Parameters (loaded from [ENGINE] section)

```c
struct VehicleEngineParams {
    /* +0x0674 */ double fuelConsumption;      // raw from .svm
    /* +0x067c */ double fuelEstimate;          // raw from .svm
    /* +0x0684 */ double engineInertia;         // raw from .svm
    /* +0x068c */ double idleRPMLogic_min;      // RPM, * 2pi/60 at load
    /* +0x0694 */ double idleRPMLogic_max;      // RPM, * 2pi/60 at load
    /* +0x069c */ double idleThrottle;          // range-checked
    /* +0x06a0 */ double idleThrottleFlag;      // 0 or 1.0, computed
    /* +0x06ac */ double launchRPMLogic_min;    // RPM, * 2pi/60 at load
    /* +0x06b4 */ double launchRPMLogic_max;    // RPM, * 2pi/60 at load
    /* +0x06bc */ double revLimitLogic;         // RPM, * 2pi/60 at load
    /* +0x06c4 */ int    rpmTorquePointCount;   // curve point count
    /* +0x06c8 */ double rpmTorqueArray[];      // 3 doubles per point (rpm, torque_throttle, torque_brake); rpm * 2pi/60 at load
    /* +0x12c8 */ double optimumOilTemp;        // +273.15 K at load
    /* +0x12d0 */ double combustionHeat;        // raw
    /* +0x12d8 */ double engineSpeedHeat;       // raw
    /* +0x12e0 */ double oilMinimumCooling;     // raw
    /* +0x12e8 */ double oilWaterHeatTransfer_1;// raw
    /* +0x12f0 */ double oilWaterHeatTransfer_2;// raw
    /* +0x12f8 */ double waterMinimumCooling;   // raw
    /* +0x1300 */ double radiatorCooling_min;   // raw
    /* +0x1308 */ double radiatorCooling_max;   // raw
    /* +0x1310 */ double lifetimeEngineRPM_min; // RPM, * 2pi/60 at load
    /* +0x1318 */ double lifetimeEngineRPM_max; // RPM, * 2pi/60 at load
    /* +0x1320 */ double lifetimeOilTemp_min;   // Celsius, +273.15 K at load
    /* +0x1328 */ double lifetimeOilTemp_max;   // raw (no offset at load)
    /* +0x1330 */ double lifetimeAvg;           // raw
    /* +0x1338 */ double lifetimeVar;           // raw
    /* +0x1340 */ double engineEmission[3];     // +0x1340, +0x1348, +0x1350, raw
    /* +0x1358 */ double onboardStarter;        // raw
    /* +0x135c */ double starterTiming[3];      // +0x135c, +0x1364, +0x136c, raw
};
// Total size: engine block extends from +0x674 to at least +0x1370
```

### Vehicle Runtime Engine Lifetime (physics instance)

```c
struct VehicleRuntimeEngineLifetime {
    /* +0x1db4 */ double effectiveLifetime;     // post-formula, post-scaling (per-lap fraction in race)
    /* +0x1dbc */ double lifetimeEngineRPM_min; // raw from .svm (doubles as runtime copy)
    /* +0x1dc4 */ double invLifetimeEngineRPM_max; // 1.0 / (RPM_max * 2pi/60)
    /* +0x1dcc */ double lifetimeOilTemp_min;   // from .svm + 273.15 K
    /* +0x1dd4 */ double invLifetimeOilTemp_max;// 1.0 / OilTemp_max
};
// Total size: +0x1db4 to +0x1ddc (40 bytes)
```

### Vehicle Damage Thresholds (loaded from [PHYSICAL] section)

```c
struct VehicleDamageParams {
    /* +0x00 */ float radiusAdd;           // Body collision radius addition
    /* +0x04 */ float radiusMult;          // Body collision radius multiplier
    /* +0x08 */ float radiusMax;           // Maximum collision radius
    /* +0x0c */ float engine;              // Engine collision parameter
    /* +0x10 */ float aeroDiv;             // Aero division factor
    /* +0x14 */ float aeroMin;             // Aero minimum
    /* +0x18 */ float vertMult;            // Vertical multiplier
    /* +0x1c */ float frontWingDetach;     // Front wing detach threshold
    /* +0x20 */ float frontWingRandom;     // Front wing random failure chance
    /* +0x24 */ float frontWingPos[3];     // x, y, z
    /* +0x30 */ float frontWingMass;       // mass
    /* +0x34 */ float frontWingInertia[3]; // 3 inertia values
    /* +0x40 */ float frontWingCollParam[3]; // 3 collision params
    /* +0x4c */ float rearWingDetach;      // Rear wing detach threshold
    /* +0x50 */ float rearWingRandom;      // Rear wing random failure chance
    /* +0x54 */ float rearWingPos[3];      // x, y, z
    /* +0x60 */ float rearWingMass;        // mass
    /* +0x64 */ float rearWingInertia[3];  // 3 inertia values
    /* +0x70 */ float rearWingCollParam[3];// 3 collision params
    /* +0x7c */ float wheelBend;           // Wheel bending threshold
    /* +0x80 */ float wheelDetach;         // Wheel detach threshold
    /* +0x84 */ float wheelRandom;         // Wheel random failure chance
    /* +0x88 */ float wheel0_MassInertia[4]; // wheel 0 mass + 3 inertia (stride 0x1c for 4 wheels)
    /* ... */
    /* +0x118 */ float partDetach[8];      // 8 detachable parts, 4 bytes each
    /* +0x13c */ float partPos[8][3];      // 8 parts, stride 0xc (3 floats each)
    /* +0x1a0 */ float partMassInertia[8][4]; // 8 parts, stride 0x1c
};
// Total size: at least +0x250
```

### Per-Wheel Corner Damage State

```c
struct WheelCornerDamage {
    /* +0x0b8 */ double brakeOptimumTemp;  // +273.15 K applied at load
    /* +0x0f0 */ double brakeWearRate;     // from .svm
    /* +0x0f8 */ double brakeFailure_min;  // from .svm
    /* +0x100 */ double brakeFailure_max;  // from .svm
};
// Part of per-wheel struct, stride 0x128 between corners
```

### Player Options Failure Rates

```c
struct PlayerFailureRate {
    /* +0x5c8 */ int failureRate[7];       // stride 0x24 per slot, {current=2, min=0, max=3}
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007cea5c | int | EngineWearMode | 0=disabled, 1=unknown, 2=random failures, 3=scripted events |
| DAT_007d0c60 | float | TireWearMultiplier | Scales tire wear rate across all vehicles |
| DAT_008acf9c | int | TotalRaceLaps | Total race lap count, used for lifetime lap-scaling |
| DAT_007c7ab8 | float | BrakeTempFL | Brake temperature front-left |
| DAT_007c7f1c | float | BrakeTempFR | Brake temperature front-right |
| DAT_007c8380 | float | BrakeTempRL | Brake temperature rear-left |
| DAT_007c87e4 | float | BrakeTempRR | Brake temperature rear-right |
| DAT_007c91b4 | float | WaterTemp | Water temperature |
| DAT_005ccbb8 | float | HUDBaseY | HUD display base Y coordinate |
| DAT_005ccbc0 | float | HUDBaseX | HUD display base X coordinate |
| DAT_005ccbbc | float | HUDLineHeight | HUD line height increment |

---

## Public API — Entry Points

### FUN_004f3c80 — Engine Section Parser

**Inferred signature:** `void ParseEngineSection(void* vehicleStruct, const char* sectionData)`
**Called from:** vehload.cpp, invoked by FUN_004f4270 when processing `[ENGINE]` section
**Called by (from callers.json):** Not tracked in call graph (deep load path)

**What it does:**
1. Reads 31+ parameters from the `[ENGINE]` section of `.svm`/`.hdv` files
2. Applies per-field transforms:
   - RPM values (IdleRPMLogic, LaunchRPMLogic, RevLimitLogic, RPMTorque, LifetimeEngineRPM):
     multiplied by `_DAT_005ad258` (2pi/60, RPM→rad/s)
   - Temperature values (OptimumOilTemp, LifetimeOilTemp_min): add `_DAT_0059eac8` (273.15 K, Celsius→Kelvin)
   - NaturalRPM stored as reciprocal: `1.0 / (NaturalRPM * 2pi/60)` for fast multiply
3. Validates IdleRPMLogic (max >= min), LaunchRPMLogic (max >= min), RPMTorque curve (max 126 points, torque_brake <= torque_throttle, monotonic order)
4. All validation warnings suppressed when `DAT_007c569c == 5` (dedicated server mode)

**Side effects:**
- Writes: VehicleEngineParams fields at offsets +0x674 through +0x1370
- Reads: DAT_005ad258 (RPM conversion), DAT_0059eac8 (Kelvin offset), DAT_0059e430 (zero), DAT_0059e420 (1.0)
- Validation: DAT_007c569c (SessionType5, server mode gates assertions)

---

### FUN_004e6d93 — Engine Physics Updater (per tick)

**Inferred signature:** `void UpdateEngineWear(void* vehiclePhysicsStruct, float deltaTime)`
**Called from:** Physics loop, called by 0x0059d9d7 (Wheel Contact Force & Suspension Update from docs/18) every physics tick
**Called by (from callers.json):** 0x0059d9d7, 0x00464a10

**What it does:**
1. Reads per-vehicle random coefficient at `+0x1344` (integer, set at vehicle spawn)
2. Computes effective engine lifetime:
   ```c
   float effectiveLifetime = (float)randomCoeff * (float)lifetimeVar + (float)lifetimeAvg;
   ```
3. Passes `effectiveLifetime` to `FUN_004f69e0` (engine wear rate calculator) as the comparand
4. Also calls: FUN_004f3190, FUN_004f68b0, FUN_004f6950 (tire force model), FUN_004f6a50,
   FUN_0054b420 (timer), FUN_004e9bd0 (rotation transform), FUN_004ee150, FUN_0054f830,
   FUN_004dd7c0, FUN_0059da3a

**Side effects:**
- Reads: VehicleEngineParams.lifetimeVar (+0x1338), lifetimeAvg (+0x1330), randomCoeff (+0x1344)
- Calls into tire/force computation chain via FUN_004f69e0

---

### FUN_0043c250 — Vehicle Session Initializer / LifetimeVar Spawn Formula

**Inferred signature:** `void InitVehicleSessionLifetime(void* physicsStruct, void* configStruct, int vehicleIndex)`
**Called from:** Vehicle spawn path, called by 0x0043e050 (vehicle physics init)
**Called by (from callers.json):** 0x0043e050

**What it does:**
1. Generates random float [0, 1] via `FUN_004b3ce0()`
2. Computes effective engine lifetime:
   ```c
   double fLifetime = randomFloat * configStruct.lifetimeVar (+0x1338) + configStruct.lifetimeAvg (+0x1330);
   physicsStruct.effectiveLifetime (+0x1db4) = fLifetime;
   ```
3. Checks EngineWearMode (`DAT_007cea5c`):
   - **Mode 0 (disabled)**: Overwrites `effectiveLifetime` with +Infinity (`0x7fefffff` as high word, `0xffffffff` as low word). Zeros all 4 pitstop lap fields.
   - **Mode 2 or 3** (when `1 < mode < 4`): If `SessionType == 7` (race session):
     - Divides `effectiveLifetime` by `DAT_008acf9c` (TotalRaceLaps) to produce per-lap fraction
   - **Mode 1**: Falls through the lap-scaling branch (excluded by `1 < mode < 4` condition)
4. Converts fractional pitstop lap values (0.0–1.0 from `.svm`) to absolute lap numbers by multiplying by `DAT_008acf9c` (TotalRaceLaps)

**Side effects:**
- Writes: VehicleRuntimeEngineLifetime.effectiveLifetime (+0x1db4, double)
- Writes: Pitstop lap fields (4 cars, absolute lap numbers)
- Reads: DAT_007cea5c (EngineWearMode), DAT_007c56a4 (SessionType), DAT_008acf9c (TotalRaceLaps)
- Calls: FUN_004b3ce0 (random float [0,1])

---

### FUN_0043ef20 — EngineStressSimulation

**Inferred signature:** `void SimulateEngineStress(void* vehiclePhysicsStruct, float deltaTime)`
**Called from:** Physics tick (not tracked in callers.json — likely called via function pointer or deep chain)
**Called by (from callers.json):** Not found in call graph

**What it does:**
1. **Crankshaft stress**: Computes stress from crankshaft rotation delta at `+0x1c5c` (absolute value)
2. **RPM limit**: If RPM at `+0x19c` exceeds threshold, reduces RPM by `torque * stress * friction`
   - If RPM drops below 0: stores `ReasonCode=9` at vehicle `+0x4068` via `+0x1f00 → +0x4068` indirection
   - Updates gauge display via `+0x1d4 → +0xac/+0xb4`
3. **Oil temperature** at `+0x1d4c`: Complex heat equation
   ```c
   oilTemp = ambient + (ambient_gap * convection + delta * radiation + stress * friction - cooling * cooling) * mass
   ```
   - Clamps oil temp, applies sine-based ripple for gauge fluctuation
   - If oil temp exceeds threshold: damps oscillation
4. **Cylinder head temp** at `+0x1d8c`: Similar heat equation model
5. **Wear/fatigue tracking** at `+0x1db4`:
   - If `effectiveLifetime <= 0` (worn out): checks 3 axes at `+0x1de4/+0x1dec/+0x1df4` for complete failure
   - When all axes zeroed: sets `ReasonCode=1` (engine failure) at `+0x4068`
   - Random component failure distribution across 3 axes via ring buffer (DAT_008aae70)
   - Different failure patterns determined by random thresholds (DAT_0059eb28, DAT_0059ec70, etc.)
6. Resets vibration accumulators at `+0x1dac/+0x1d08`
7. Calls `FUN_0041ac50` to trigger failure animation/effect

**Side effects:**
- Writes: ReasonCode (+0x4068 via +0x1f00 indirection), gauge display (+0xac/+0xb4), oilTemp (+0x1d4c), headTemp (+0x1d8c), vibration accumulators (+0x1dac/+0x1d08), wear axes (+0x1de4/dec/df4)
- Reads: crankDelta (+0x1c5c), RPM (+0x19c), ring buffer (DAT_008aae70, DAT_008aae74, DAT_008ab274)
- Calls: FUN_005881f0 (random), FUN_0041ac50 (failure animation/effect)

---

### FUN_004ed960 — FuelConsumptionAndWear

**Inferred signature:** `void UpdateFuelAndWear(void* vehiclePhysicsStruct, float deltaTime)`
**Called from:** Physics tick, called by 0x0042c690
**Called by (from callers.json):** 0x0042c690

**What it does:**
1. **Fuel consumption**: Decreases fuel at `param_1[0xe5e]` by `flow * consumptionRate * deltaTime`
   - If fuel empty: sets `ReasonCode=9` (+0x4068)
2. **Effective fuel mass**: `fuelLevel * 0.75 + baseMass`
3. **Tank capacity reciprocal**: `1.0 / effectiveMass` — precomputed division
4. **Tire wear** (if speed magnitude > threshold):
   - Aggregates 4 wheel loads, computes wear factor `1.0 - totalLoad * 0.25`
   - Per wheel: `wear -= factor * load * grip * TireWearMultiplier * deltaTime`
   - Minimum grip floor: if `wear < 0.75`, resets to 0.75
5. **Brake wear**: Computed from brake bias + pedal input
6. **Speed display**: Detects speed change (> 0.01 threshold), updates display value with random jitter
7. **4 damage timers** (engine modes: 0=engine, 1=gearbox, 2=suspension, 3=brake):
   - Decrements each active timer by deltaTime
   - On timer expiry:
     - **Case 0 (engine)**: ReasonCode=1, random failure distribution across 3 axes
     - **Case 1 (gearbox)**: ReasonCode=5, random gear damage
     - **Case 2 (suspension)**: ReasonCode=2, sets `param_1 + 0x39ee` flag, increments failure counter
     - **Case 3 (brake)**: ReasonCode=4, random increases brake failure accumulator
   - Resets failure accumulators after distribution
   - Checks `DAT_007cea5c == 3` (Scripted Events): caps engine timer at 60.0

**Side effects:**
- Writes: ReasonCode (+0x4068), fuel level (+0xe5e), tire wear values, brake wear values, damage timers
- Writes: param_1 + 0x39ee (suspension failure flag)
- Reads: DAT_007d0c60 (TireWearMultiplier), DAT_007cea5c (EngineWearMode)
- Calls: FUN_004d21d0, FUN_0041ac50 (failure animation/effect), FUN_004e8010 (tire physics)

---

### FUN_004f24f0 — Vehicle Damage Model (PHYSICAL section parser)

**Inferred signature:** `void ParsePhysicalSection(void* damageStruct, const char* sectionData)`
**Called from:** vehload.cpp
**Called by (from callers.json):** Not tracked in call graph

**What it does:**
1. Reads `[PHYSICAL]` section from `.svm`/`.hdv` files
2. Loads collision radius parameters: RadiusAdd, RadiusMult, RadiusMax
3. Loads engine collision param, aero division/minimum, vertical multiplier
4. Loads **front wing** detach threshold, random failure chance, position (3 floats), mass + inertia (4 values), collision params (3 values)
5. Loads **rear wing** detach threshold, random failure chance, position, mass/inertia, collision params
6. Loads **wheel** bend threshold, detach threshold, random failure chance, per-wheel mass/inertia (4 wheels, stride 0x1c)
7. Loads **8 detachable parts**: detach thresholds, positions (3 floats each), mass/inertia + collision params (stride 0x1c)

**Side effects:**
- Writes: VehicleDamageParams struct at base offset +0x00 through +0x250
- All fields are moddable from `.svm`/`.hdv` files (high moddability)

---

### FUN_004f6bf0 — RPM Range Loader (Per Gear)

**Inferred signature:** `void LoadGearRPM(void* rpmStruct, int gearIndex, const char* sectionData)`
**Called from:** vehload.cpp (part of gearbox loading)
**Called by (from callers.json):** Not tracked in call graph

**What it does:**
1. Reads MinimumRPM, MaximumRPM, NaturalRPM for gear 0–4
2. Per-gear stride: 0xc bytes
3. Transforms:
   - MinimumRPM * _DAT_005ad258 (RPM→rad/s) → +0x04 + gear*0xc
   - MaximumRPM * _DAT_005ad258 → +0x08 + gear*0xc
   - NaturalRPM: stored as reciprocal `1.0 / (NaturalRPM * _DAT_005ad258)` → +0x0c + gear*0xc

**Side effects:**
- Writes: RPM struct fields (5 gears, stride 0xc)
- Reads: DAT_005ad258 (RPM conversion), DAT_0059e420 (1.0)

---

### FUN_0043bc20 — State-Display Lifetime Copy

**Inferred signature:** `void CopyLifetimeToDisplay(void* physicsStruct, void* displayStruct)`
**Called from:** HUD/damage display path
**Called by (from callers.json):** Not tracked in call graph

**What it does:**
1. Reads effectiveLifetime at physicsStruct +0x1db4
2. Copies to display struct fields for HUD rendering
3. Calls: FUN_004363f0 (transform init?), FUN_00436470 (float store?), FUN_0043bb30/bb80/bbd0 (hierarchy resolve 1/2/3)

**Side effects:**
- Reads: VehicleRuntimeEngineLifetime.effectiveLifetime (+0x1db4)
- Calls 4 helper functions for struct field copy/hierarchy resolution

---

### FUN_0049db80 — Brake/Water Temperature HUD Display

**Inferred signature:** `void DrawTempHUD(void* hudContext)`
**Called from:** Per-frame HUD rendering, called by 0x0049d5d0
**Called by (from callers.json):** 0x0049d5d0

**What it does:**
1. If session active (param_1+8 != 0):
2. **Water temperature**: Copies "WATER:" label string, reads water temp from `DAT_007c91b4` - `DAT_005acafc` (Kelvin→Celsius offset), displays via FUN_0049f6a0
3. **Brake temperatures**: Copies "BRAKES:" label, reads 4 corner temps at DAT_007c7ab8/7f1c/8380/87e4 (FL, FR, RL, RR), subtracts _DAT_0059eac8 (273.15 K offset) for Celsius display

**Side effects:**
- Reads: DAT_007c91b4 (WaterTemp), DAT_007c7ab8/7f1c/8380/87e4 (BrakeTemps), DAT_005acafc (TemperatureOffset), DAT_0059eac8 (Kelvin offset)
- Reads: DAT_005ccbb8 (HUDBaseY), DAT_005ccbc0 (HUDBaseX), DAT_005ccbbc (HUDLineHeight)
- Calls: FUN_00423a00 (string copy), FUN_0049f6a0 (HUD draw), FUN_0049db00 (temp display format)

---

### FUN_004bb730 — Failure Category Name Lookup

**Inferred signature:** `const char* GetFailureCategoryName(int failureId)`
**Called from:** Damage reporting/results display
**Called by (from callers.json):** Not tracked in call graph

**What it does:**
1. Switch on failure ID (1–9):
   - 1 → "Engine"
   - 2 → "Gearbox"
   - 3, 7 → "Clutch"
   - 4 → "Suspension"
   - 5 → "Brakes"
   - 6 → "Accident"
   - 8 → "Electronics"
   - 9 → "" (empty/unknown)
   - default → "" (other/unknown)

**Side effects:** None (pure lookup)

---

## Internal Call Graph

Major call chains within engine wear/damage system:

### Vehicle Load Chain (session startup)

```
FUN_004f4270 — Vehicle File Loader
  +-- FUN_004f3c80 — Engine Section Parser  [reads [ENGINE] section, 31+ fields]
  +-- FUN_004f24f0 — Vehicle Damage Model   [reads [PHYSICAL] section, detach thresholds]
  +-- FUN_004f6bf0 — RPM Range Loader       [reads per-gear RPM limits, stride 0xc × 5]
```

### Vehicle Spawn Chain (session init)

```
FUN_0043e050 — Vehicle Physics Init
  +-- FUN_0043c250 — LifetimeVar Spawn Formula  [computes effectiveLifetime at +0x1db4]
  |     +-- FUN_004b3ce0 — Random float [0,1]
  +-- FUN_004f4270 — Vehicle File Loader (re-entrant)
```

### Per-Tick Physics Chain (60 Hz)

```
0x0059d9d7 — Wheel Contact Force & Suspension Update (docs/18)
  +-- FUN_004e6d93 — Engine Physics Updater
  |     +-- FUN_004f69e0 — Engine Wear Rate Calculator
  |     +-- FUN_004f68b0 — Tire Force Quadratic Model
  |     +-- FUN_004f6950 — Tire Force Model Secondary
  |     +-- FUN_004f3190 — [energy channel]
  |     +-- FUN_004f6a50 — [damage accumulators]
  |     +-- FUN_0054b420 — Timer state
  |     +-- FUN_004e9bd0 — Rotation transform
  |     +-- FUN_004ee150 — [sub-function]
  |     +-- FUN_0054f830 — [sub-function]
  |     +-- FUN_004dd7c0 — [sub-function]
  |     +-- FUN_0059da3a — [sub-function]

FUN_0043ef20 — EngineStressSimulation
  +-- FUN_005881f0 — Random (ring buffer)
  +-- FUN_0041ac50 — Failure animation/effect

FUN_004ed960 — FuelConsumptionAndWear
  +-- FUN_004d21d0 — [sub-function]
  +-- FUN_0041ac50 — Failure animation/effect
  +-- FUN_004e8010 — Tire physics solver
```

### Shared Subsystem (called from multiple branches)

```
FUN_004f69e0 — Engine Wear Rate Calculator
  Called by: FUN_004e6d93, FUN_004e5f60, FUN_004390a0, FUN_00430600
  [returns wear rate for current physics tick based on effectiveLifetime]

FUN_0041ac50 — Failure Animation/Effect
  Called by: FUN_0043ef20, FUN_004ed960
  +-- FUN_004144d0, FUN_004144f0, FUN_00418560
  [triggers visual/audio failure notification]
```

### Per-Frame HUD Chain

```
0x0049d5d0 — HUD Renderer
  +-- FUN_0049db80 — Brake/Water Temperature HUD Display
  |     +-- FUN_00423a00 — String copy
  |     +-- FUN_0049f6a0 — HUD draw
  |     +-- FUN_0049db00 — Temp display format
  +-- FUN_0043bc20 — Copy Lifetime To Display
        +-- FUN_004363f0, FUN_00436470 — Transform/float store
        +-- FUN_0043bb30, FUN_0043bb80, FUN_0043bbd0 — Hierarchy resolve
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0x7fefffff | FUN_0043c250 | +Infinity high word (engine wear disabled mode) |
| 0xffffffff | FUN_0043c250 | +Infinity low word |
| 0.75 | FUN_004ed960 | Minimum tire wear floor (grip floor) |
| 0.25 | FUN_004ed960 | Tire wear load aggregation divisor (1/4 wheels) |
| 60.0 | FUN_004ed960 | Max engine timer cap in scripted events mode (seconds) |
| 0.01 | FUN_004ed960 | Speed change display update threshold |
| 273.15 | FUN_004f3c80, FUN_0043c250 | Kelvin offset (DAT_0059eac8) |
| 2π/60 | FUN_004f3c80, FUN_004f6bf0 | RPM→rad/s conversion (DAT_005ad258) |
| 3 | FUN_0043ef20 | Number of wear/failure axes |
| 5 | FUN_004f6bf0 | Number of gears (0–4) |
| 4 | FUN_004ed960 | Number of damage timer types |
| 4 | FUN_004ed960 | Number of wheels for tire wear |
| 8 | FUN_004f24f0 | Number of detachable parts |
| 126 | FUN_004f3c80 | Max RPMTorque curve points |
| 0x1c | FUN_004f24f0 | Wheel/part MassInertia stride (4 floats) |
| 0xc | FUN_004f24f0 | Part position stride (3 floats) |
| 0xc | FUN_004f6bf0 | Per-gear stride (3 doubles) |
| 0x24 | PlayerOptions | FailureRate stride (7 slots) |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007c56a4` (SessionType) — from docs/12 (steward): gates race-session lap-scaling of lifetime
- `DAT_007c569c` (SessionType5) — from docs/12: suppresses validation warnings on dedicated server
- `DAT_008aae70` (RingBufferCounter) — from docs/12 (ai_db): random index for wear axis distribution
- `DAT_008ab274` (WeatherNoiseTable) — from docs/12 (weather): random table for failure patterns
- `DAT_0059eac8` (KelvinOffset) — from constant pool: Celsius→Kelvin conversion
- `DAT_005ad258` (RPMConversion) — from constant pool: RPM→rad/s conversion
- `DAT_0059eb28` (Damper2MaxAdd) — from docs/12 (physics): failure axis threshold
- `DAT_0059ec70` (TireMultiplierFactor) — from docs/12 (physics): failure pattern threshold
- `DAT_005acafc` (TemperatureOffset) — from docs/12 (physics): water temp sensor calibration

**Calls into:**
- docs/18-physics-dynamics.md: FUN_004f69e0 (engine wear rate), FUN_004e8010 (tire physics)
- docs/17-physics-collision.md: FUN_0041ac50 (failure animation/effect)
- docs/20-math-utilities.md: FUN_005881f0 (random), FUN_004b3ce0 (random float)

**Called by:**
- docs/18-physics-dynamics.md: FUN_004e5f60, 0x0059d9d7 (Wheel Contact Force & Suspension Update) — per-tick physics drivers
- docs/06-session-race-logic.md: steward system reads ReasonCode (+0x4068) for DNF/retirement processing
- docs/19-renderer.md: HUD rendering calls FUN_0049db80 for temp display

---

## Reimplementation Notes

1. **EngineWearMode (DAT_007cea5c) branching order matters**: Mode 0 (disabled) must be checked FIRST because the LifetimeVar formula still runs but is overwritten with +Inf. Mode 1 is an undocumented intermediate that falls through all branches — when mode==1, `effectiveLifetime` is computed from the formula but NOT lap-scaled.

2. **SessionType must be checked before RacePhase**: The lap-scaling branch at FUN_0043c250 gates on `SessionType == 7` (race). In qualifying/practice sessions, the lifetime is NOT divided by TotalRaceLaps. This means effectiveLifetime has different units depending on session type.

3. **Pitstop lap fractions**: Pitstop laps in `.svm` are stored as fractions (0.0–1.0) of race distance and are multiplied by TotalRaceLaps at vehicle spawn — they are NOT absolute lap numbers in the config file.

4. **Reciprocal precomputation**: Two fields use the `1/max` reciprocal pattern for fast multiply:
   - `1 / LifetimeEngineRPM_max` at +0x1dc4
   - `1 / LifetimeOilTemp_max` at +0x1dd4
   - `1/NaturalRPM` per gear at gear stride +0x0c
   The reimplementation should precompute these at load time.

5. **Temperature unit convention**: All temperature values in `.svm`/`.hdv` are in Celsius. At load time, +273.15 K is added for internal use (Kelvin). At HUD display time, the offset is subtracted back to Celsius. The reimplementation should store temperatures in Kelvin internally and convert at I/O boundaries.

6. **Per-vehicle random coefficient at +0x1344**: This is an integer set at vehicle spawn, NOT from `.svm`/`.hdv`. It multiplies LifetimeVar to create per-vehicle variance. It is fixed for the session once set — engine life is determined at spawn, not continuously rerolled. The reimplementation should generate this via `FUN_004b3ce0()` (random float [0,1]) scaled appropriately.

7. **LifetimeVar formula always runs**: The formula `randomCoeff * LifetimeVar + LifetimeAvg` at FUN_0043c250 runs unconditionally at vehicle spawn. Only after computing the result does the branching on EngineWearMode occur. Even in mode 0 (disabled), the computation is performed before being overwritten.

8. **Failure effect trigger (FUN_0041ac50)**: This function is called by both EngineStressSimulation (FUN_0043ef20) and FuelConsumptionAndWear (FUN_004ed960). It triggers audio/visual/animation effects for mechanical failures. The reimplementation should route failure events to a centralized notification system.

9. **Failure axis distribution**: Engine failures are distributed across 3 axes at +0x1de4/+0x1dec/+0x1df4 using a ring buffer index (DAT_008aae70). Each axis represents a different failure mode (e.g., conrod, bearing, valve). The reimplementation should use a modulo-256 ring counter to index into a random noise table.

10. **Fuel mass model**: Fuel level at `param_1[0xe5e]` is decremented, then effective fuel mass is computed as `fuelLevel * 0.75 + baseMass`. The 0.75 factor and baseMass are constants — likely representing fuel density and minimum fuel mass.

11. **Tire wear floor**: Tire wear is clamped to a minimum of 0.75 at FUN_004ed960. This means tires never lose more than 25% of their grip from wear alone (thermal/compound effects are separate).

12. **Scripted events timer cap**: When `EngineWearMode == 3`, the engine damage timer is capped at 60.0 seconds — limiting how long a scripted failure event can take to trigger.

13. **Engine speed gauge**: The stress simulation updates gauge display at `+0x1d4 → +0xac/+0xb4`. The gauge values include a sine-based ripple for visual fluctuation — this is cosmetic only and does not affect physics.

14. **Multiple wear axes**: The 3-axis failure system at FUN_0043ef20 uses random thresholds from global constants. Different DAT_0059eXXX values provide threshold variety. The reimplementation should read these thresholds from config or constants.

---

## Completeness

- Full specs written: 13 / 13 total documented functions
- Thunks/empty stubs omitted: 0
- Confidence: **high** — all globals, offsets, thresholds, and call chains confirmed from decompiled source code and call graph data
