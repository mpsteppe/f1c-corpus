# Engine Wear, Lifetime, and Damage Model

## LifetimeVar / LifetimeAvg â€” Loading

Source: `FUN_004f3c80` @ `0x004f3c80` (`vehload.cpp` engine section parser)

Stored in vehicle struct (`param_1`) at fixed offsets:
```
param_1 + 0x1310  = LifetimeEngineRPM min   (Ã— RPM_TO_RAD conversion)
param_1 + 0x1318  = LifetimeEngineRPM max
param_1 + 0x1320  = LifetimeOilTemp min     (+ 273.15 K offset applied at load)
param_1 + 0x1328  = LifetimeOilTemp max
param_1 + 0x1330  = LifetimeAvg
param_1 + 0x1338  = LifetimeVar
```

`LifetimeVar` is loaded raw â€” no transformation at load time.

### LifetimeVar â€” Runtime Formula (Confirmed)

Source: `FUN_004e6d93` @ `0x004e6d93` (engine physics updater, 4516 bytes)

```c
// At function entry â€” computes effective engine lifetime for this vehicle:
fVar1 = (float)*(int *)(iVar9 + 0x1344) * (float)*(double *)(iVar9 + 0x1338)
      + (float)*(double *)(iVar9 + 0x1330);
// = random_coeff * LifetimeVar + LifetimeAvg
```

`iVar9 + 0x1344` is a per-vehicle random integer coefficient (set at vehicle spawn, not
from `.hdv`). LifetimeVar scales it; LifetimeAvg offsets it. The result `fVar1` is passed
to `FUN_004f69e0` â€” the actual engine wear rate calculator.

**Implication:** Increasing LifetimeVar increases session-to-session variance in engine life
around the LifetimeAvg mean. Setting LifetimeVar=0 gives every car exactly LifetimeAvg
engine life. The per-vehicle random coefficient (0x1344) is fixed for the session once set â€”
engine life is determined at spawn, not continuously rerolled.

`FUN_0043bc20` @ `0x0043bc20` also uses the same formula to copy effective lifetime into
state-display struct fields (HUD/damage display reads from these).

`LifetimeOilTemp` gets +273.15 offset applied (`+_DAT_0059eac8`) â€” values in `.hdv`
are in Celsius, game uses Kelvin internally.

## FUN_0049db80 — Brake/Water Temperature HUD Display

Source: HUD/telemetry module. Displays brake temperatures (per corner) and water temperature on the in-car HUD. Updates each frame during active session.

**Key logic:**
- If param_1+8 != 0 (session active):
  - **WATER:** copies "WATER:" label, reads water temp from `DAT_007c91b4` - `DAT_005acafc` (offset), displays via FUN_0049f6a0
  - **BRAKES:** copies "BRAKES:" label, reads 4 corner brake temps: `DAT_007c7ab8`, `DAT_007c7f1c`, `DAT_007c8380`, `DAT_007c87e4` (FL, FR, RL, RR), each minus `_DAT_0059eac8` (celsius offset)
  - Uses `DAT_005ccbb8` (base Y), `DAT_005ccbc0` (base X), `DAT_005ccbbc` (line height increment)

**New globals:**
- `DAT_007c7ab8` — Brake temp FL (float)
- `DAT_007c7f1c` — Brake temp FR (float)
- `DAT_007c8380` — Brake temp RL (float)
- `DAT_007c87e4` — Brake temp RR (float)
- `DAT_007c91b4` — Water temp (float)
- `DAT_007c9174` — Alternate water temp (float)

**Calls:** FUN_00423a00 (string copy), FUN_0049f6a0 (HUD draw), FUN_0049db00 (temp display format)

**Moddability:** No — runtime telemetry display only. But confirms brake temp is tracked per-corner and stored in vehicle struct.

---

## FUN_004bb730 — Failure Category Name Lookup

Source: vehicle damage system. Maps internal failure type IDs to human-readable category names. Used in damage reporting and results display.

**Mapping:**
| ID | Name |
|----|------|
| 1 | Engine |
| 2 | Gearbox |
| 3, 7 | Clutch |
| 4 | Suspension |
| 5 | Brakes |
| 6 | Accident |
| 8 | Electronics |
| 9 | (empty/unknown) |
| default | (other/unknown) |

**Calls:** None (pure switch-table lookup)

**Moddability:** Yes — confirms DNF reason code categories in results file. Related to failure mode flags that could be mod-controlled for varied mechanical failures.

---



---

## Session 2 - LifetimeVar Related


Previously documented as "scripted events mode". Full enum confirmed from `FUN_0043c250`:

| Value | Meaning |
|-------|---------|
| 0 | Engine wear disabled â€” lifetime forced to `+Inf` (0x7fefffff), pitstop laps zeroed for all 4 cars |
| 1 | Unknown intermediate (excluded from lap-scaling branch `1 < x < 4`) |
| 2 | Random failures â€” LifetimeVar formula active, lap-scaled in race sessions |
| 3 | Scripted events â€” same formula + lap-scaling as mode 2, scripted event system active |

When `DAT_007cea5c = 0`, the LifetimeVar computation still runs but is immediately overwritten with +Inf. The mod-written `LifetimeVar`/`LifetimeAvg` fields have no effect when this mode is 0.

---

### FUN_0043c250 â€” Vehicle Session Initializer / LifetimeVar Spawn Formula

Large vehicle init function (5734 bytes). LifetimeVar formula runs at vehicle spawn (not at file load):

```c
fVar15 = FUN_004b3ce0();                          // random float [0,1]
fVar15 = fVar15 * LifetimeVar(param_3+0x1338)
       + LifetimeAvg(param_3+0x1330);
*(double *)(param_1 + 0x1db4) = (double)fVar15;  // stored in physics vehicle struct

if (DAT_007cea5c == 0) {
    // Override with infinity â€” no engine wear
    param_1[0x1db4] = 0xffffffff;
    param_1[0x1db8] = 0x7fefffff;
    // Zero all 4 pitstop lap fields
}
else if (1 < DAT_007cea5c && DAT_007cea5c < 4) {
    if (DAT_007c56a4 == 7) {  // race session
        // Convert absolute lifetime â†’ per-lap fraction:
        *(double *)(param_1+0x1db4) /= _DAT_008acf9c;  // divide by total race laps
    }
    // Convert fractional pitstop laps â†’ absolute lap numbers:
    for each of 4 cars: pitstop_lap *= _DAT_008acf9c;
}
```

Pitstop lap numbers in `.svm` are fractions of race distance (0.0â€“1.0). At session init they are multiplied by `_DAT_008acf9c` (total race laps) to yield absolute lap numbers.

**Runtime storage offsets (physics vehicle instance):**

| Offset | Type | Content |
|--------|------|---------|
| +0x1db4 | double | Effective engine lifetime (post-formula, post-scaling) |
| +0x1dbc | double | LifetimeEngineRPM min (raw from .svm) |
| +0x1dc4 | double | `1 / LifetimeEngineRPM_max` â€” reciprocal for fast physics multiply |
| +0x1dcc | double | LifetimeOilTemp min (raw from .svm) |
| +0x1dd4 | double | `1 / LifetimeOilTemp_max` â€” reciprocal |

The 1/max reciprocal pattern avoids division per physics tick.

---

### FUN_004537b0 / FUN_00454350 â€” Tire Compound Struct Layout

`FUN_004537b0` reads tire state from vehicle struct and broadcasts to global HUD/timing state. `FUN_00454350` maps input action codes to pit-crew activities using the same tire arrays.

**Vehicle struct tire offsets:**

| Offset | Size | Content |
|--------|------|---------|
| +0x1140â€“+0x115c | doubleÃ—8 | Front axle tire telemetry floats |
| +0x1160 | byte[16] | Front axle compound/state flag array |
| +0x1170 | int | Current front compound index (compared to 4 global constants â†’ HUD display) |
| +0x1174 | int | Compound selection: pitstop 2 |
| +0x1178 | int | Compound selection: pitstop 3 |
| +0x117c | int | Compound selection: pitstop 4 |
| +0x1180 | uint | **PitStopFlag bitmask**: bit 0 = stop 1 valid, bit 0x100 = stop 2, bit 0x200 = stop 3, bit 0x400 = stop 4 |
| +0x153câ€“+0x1558 | doubleÃ—8 | Rear axle tire telemetry floats |
| +0x155c | byte[16] | Rear axle compound/state flag array |

**Max 4 pitstops confirmed:** PitStopFlag bitmask uses bits 0x100/0x200/0x400 for stops 2â€“4, consistent with `NumPitstopsRange` maximum of 4.

---

### Xref False Positives â€” QualifyingAbility (+0x1130) and RainAbility (+0x1132)

Two functions matched the xref scan at offsets +0x1130 and +0x1132 but are graphics functions with no connection to the vehicle AI struct:

| Function | Claimed offset | Actual identity |
|----------|---------------|-----------------|
| `FUN_0053e070` | QA +0x1130 | DirectX display mode initializer (DXT texture format detection, display caps setup) |
| `FUN_0054ca00` | RainAbility +0x1132 | Graphics vertex buffer manager (UV coordinate transformation, vertex copying) |

Root cause: xref scans match raw 4-byte displacements without struct-type context. Any struct with the same byte offset produces a false hit. Both functions contain DirectX API calls and no game logic.

True consumers of QualifyingAbility and RainAbility are the AI ability pipeline functions documented in the "AI Ability Processing" section.

---

### Steward System (FUN_004d36d0 / FUN_004d38f0 / FUN_004d4600)

- **FUN_004d36d0** (Setup): registers callbacks for VEHICLE, TIMING, PITSTOP. Trivial.
- **FUN_004d38f0** (Init): allocates lap timing arrays by `DAT_005ea3fc` (session total time). Locates track polygons: `XPITIN`, `XPITOUT`, `XFINISH`, `XSECTOR1`, `XSECTOR2`. Initializes helicopter model.
- **FUN_004d4600** (Cleanup): frees timing arrays. Calls `FUN_004bb950` once per `DAT_005c329c` vehicles for retirement/finish processing.

No moddable fields found.

---

### UI Message Handler â€” FUN_0047eb70

Dispatch switch on codes 0x1e4â€“0x1f9, not a weather simulation. Case `0x1f8` reads `DAT_007cf134` (weather mode 0â€“5), confirming the weather mode enum already in this document. No new findings.

---

### New Struct Offset Summary (Session 2)

**Physics vehicle instance:**

| Offset | Type | Field |
|--------|------|-------|
| +0x1db4 | double | Effective engine lifetime |
| +0x1dbc | double | LifetimeEngineRPM min |
| +0x1dc4 | double | 1 / LifetimeEngineRPM max |
| +0x1dcc | double | LifetimeOilTemp min |
| +0x1dd4 | double | 1 / LifetimeOilTemp max |
| +0x1140â€“+0x115c | doubleÃ—8 | Front tire telemetry |
| +0x1160 | byte[16] | Front compound flags |
| +0x1170 | int | Current front compound index |
| +0x1174â€“+0x117c | intÃ—3 | Compound selections: stops 2â€“4 |
| +0x1180 | uint | PitStopFlag bitmask |
| +0x153câ€“+0x1558 | doubleÃ—8 | Rear tire telemetry |
| +0x155c | byte[16] | Rear compound flags |

**Player options struct (FUN_004aa270):**

| Offset | Stride | Count | Content |
|--------|--------|-------|---------|
| +0x5c8 | 0x24 | 7 | FailureRate[0..6]: {current=2, min=0, max=3} |

**Wheel corner struct (FUN_004f2c60, per wheel):**

| Offset | Field | Notes |
|--------|-------|-------|
| +0xb8 | BrakeOptimumTemp | +273.15 K applied at load |
| +0xf0 | BrakeWearRate | |
| +0xf8 | BrakeFailure min | |
| +0x100 | BrakeFailure max | |
## DAT_007cea5c - Engine Wear/Failure Mode Enum + Vehicle Session Initializer
### DAT_007cea5c â€” Engine Wear / Failure Mode Enum (Expanded)

Previously documented as "scripted events mode". Full enum confirmed from `FUN_0043c250`:

| Value | Meaning |
|-------|---------|
| 0 | Engine wear disabled â€” lifetime forced to `+Inf` (0x7fefffff), pitstop laps zeroed for all 4 cars |
| 1 | Unknown intermediate (excluded from lap-scaling branch `1 < x < 4`) |
| 2 | Random failures â€” LifetimeVar formula active, lap-scaled in race sessions |
| 3 | Scripted events â€” same formula + lap-scaling as mode 2, scripted event system active |

When `DAT_007cea5c = 0`, the LifetimeVar computation still runs but is immediately overwritten with +Inf. The mod-written `LifetimeVar`/`LifetimeAvg` fields have no effect when this mode is 0.

---

### FUN_0043c250 â€” Vehicle Session Initializer / LifetimeVar Spawn Formula

Large vehicle init function (5734 bytes). LifetimeVar formula runs at vehicle spawn (not at file load):

```c
fVar15 = FUN_004b3ce0();                          // random float [0,1]
fVar15 = fVar15 * LifetimeVar(param_3+0x1338)
       + LifetimeAvg(param_3+0x1330);
*(double *)(param_1 + 0x1db4) = (double)fVar15;  // stored in physics vehicle struct

if (DAT_007cea5c == 0) {
    // Override with infinity â€” no engine wear
    param_1[0x1db4] = 0xffffffff;
    param_1[0x1db8] = 0x7fefffff;
    // Zero all 4 pitstop lap fields
}
else if (1 < DAT_007cea5c && DAT_007cea5c < 4) {
    if (DAT_007c56a4 == 7) {  // race session
        // Convert absolute lifetime â†’ per-lap fraction:
        *(double *)(param_1+0x1db4) /= _DAT_008acf9c;  // divide by total race laps
    }
    // Convert fractional pitstop laps â†’ absolute lap numbers:
    for each of 4 cars: pitstop_lap *= _DAT_008acf9c;
}
```

Pitstop lap numbers in `.svm` are fractions of race distance (0.0â€“1.0). At session init they are multiplied by `_DAT_008acf9c` (total race laps) to yield absolute lap numbers.

**Runtime storage offsets (physics vehicle instance):**

| Offset | Type | Content |
|--------|------|---------|
| +0x1db4 | double | Effective engine lifetime (post-formula, post-scaling) |
| +0x1dbc | double | LifetimeEngineRPM min (raw from .svm) |
| +0x1dc4 | double | `1 / LifetimeEngineRPM_max` â€” reciprocal for fast physics multiply |
| +0x1dcc | double | LifetimeOilTemp min (raw from .svm) |
| +0x1dd4 | double | `1 / LifetimeOilTemp_max` â€” reciprocal |

The 1/max reciprocal pattern avoids division per physics tick.

---

## FUN_004f3c80 - Engine Section Parser (Full Trace)
### FUN_004f3c80 â€” Engine Section Parser (Full Trace)

Source: vehload.cpp [ida:fact]. Called by `FUN_004f4270` when `RestrictorPlate` section parsed.
Full field map recovered. Loads into vehicle struct (param_1):

| Offset | Type | Field | Transform |
|--------|------|-------|-----------|
| +0x674 | double | FuelConsumption | raw |
| +0x67c | double | FuelEstimate | raw |
| +0x684 | double | EngineInertia | raw |
| +0x68c | double | IdleRPMLogic min | Ã— _DAT_005ad258 (RPMâ†’rad/s) |
| +0x694 | double | IdleRPMLogic max | Ã— _DAT_005ad258 |
| +0x69c | double | IdleThrottle | range-checked â†’ flag at +0x6a0 |
| +0x6a0 | double | IdleThrottle flag (0 or 1.0) | computed |
| +0x6ac | double | LaunchRPMLogic min | Ã— _DAT_005ad258 |
| +0x6b4 | double | LaunchRPMLogic max | Ã— _DAT_005ad258 |
| +0x6bc | double | RevLimitLogic | Ã— _DAT_005ad258 |
| +0x6c8 | double[] | RPMTorque array (3 doubles: rpm, torque_throttle, torque_brake) | rpm Ã— _DAT_005ad258 |
| +0x6c4 | int | RPMTorque point count | |
| +0x12c8 | double | OptimumOilTemp | + _DAT_0059eac8 (273.15 K) |
| +0x12d0 | double | CombustionHeat | raw |
| +0x12d8 | double | EngineSpeedHeat | raw |
| +0x12e0 | double | OilMinimumCooling | raw |
| +0x12e8 | double | OilWaterHeatTransfer (param 1) | raw |
| +0x12f0 | double | OilWaterHeatTransfer (param 2) | raw |
| +0x12f8 | double | WaterMinimumCooling | raw |
| +0x1300 | double | RadiatorCooling min | raw |
| +0x1308 | double | RadiatorCooling max | raw |
| +0x1310 | double | LifetimeEngineRPM min | Ã— _DAT_005ad258 |
| +0x1318 | double | LifetimeEngineRPM max | Ã— _DAT_005ad258 |
| +0x1320 | double | LifetimeOilTemp min | + _DAT_0059eac8 (273.15 K) |
| +0x1328 | double | LifetimeOilTemp max | raw (no offset) |
| +0x1330 | double | LifetimeAvg | raw |
| +0x1338 | double | LifetimeVar | raw |
| +0x1340 | doubleÃ—3 | EngineEmission (3 values: +0x1340, +0x1348, +0x1350) | raw |
| +0x1358 | double | OnboardStarter | raw |
| +0x135c | doubleÃ—3 | StarterTiming (+0x135c, +0x1364, +0x136c) | raw |

**Constants:**
- `_DAT_005ad258` = RPM conversion factor (RPMâ†’rad/s, likely 2Ï€/60)
- `_DAT_0059eac8` = 273.15 (Celsiusâ†’Kelvin offset)
- `_DAT_0059e430` = 0.0 (zero comparison)
- `_DAT_0059e420` = 1.0 (one comparison)

**Validation logic:**
- IdleRPMLogic: warns if max < min (assert at vehload.cpp:599)
- LaunchRPMLogic: warns if max < min (assert at vehload.cpp:0x263)
- RPMTorque: warns if >126 points, if torque_brake > throttle, if curve out of order
- `DAT_007c569c != 5` gates all warnings (5 = dedicated server mode, suppresses asserts)

**Moddability:** New potential .svm levers discovered:
- `FuelConsumption`, `FuelEstimate`, `EngineInertia`
- `IdleRPMLogic`, `IdleThrottle`, `LaunchRPMLogic`, `RevLimitLogic`
- `RPMTorque` curve (engine power band)
- `OptimumOilTemp`, `CombustionHeat`, `EngineSpeedHeat`
- `OilMinimumCooling`, `OilWaterHeatTransfer`, `WaterMinimumCooling`, `RadiatorCooling`
- `EngineEmission`, `OnboardStarter`, `StarterTiming`

These are all engine thermal/power model parameters read from `.svm`/`.hdv` files.
Mods currently write LifetimeAvg/Var/EngineRPM/OilTemp â€” the above fields
are additional levers for engine behavior randomization.

---

## FUN_004f24f0 - Vehicle Damage Model (PHYSICAL section)
### FUN_004f24f0 â€” Vehicle Damage Model (.svm/.hdv PHYSICAL section)

Source: `vehload.cpp`. Reads `PHYSICAL` section from vehicle file. This is the
damage/deformation model â€” detach thresholds, random failure chances, collision
parameters, mass/inertia for detachable parts.

**Damage struct (param_1):**

| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | RadiusAdd | Body collision radius addition |
| +0x04 | RadiusMult | Body collision radius multiplier |
| +0x08 | RadiusMax | Maximum collision radius |
| +0x0c | Engine | Engine collision param |
| +0x10 | AeroDiv | Aero division factor |
| +0x14 | AeroMin | Aero minimum |
| +0x18 | VertMult | Vertical multiplier |
| +0x1c | FrontWingDetach | Front wing detach threshold |
| +0x20 | FrontWingRandom | Front wing random failure chance |
| +0x24â€“0x2c | FrontWingPos | 3 floats (x, y, z) |
| +0x30â€“0x3c | FrontWingMassInertia | 4 values (mass + 3 inertia) |
| +0x40â€“0x48 | FrontWingCollParams | 3 collision params |
| +0x4c | RearWingDetach | Rear wing detach threshold |
| +0x50 | RearWingRandom | Rear wing random failure chance |
| +0x54â€“0x5c | RearWingPos | 3 floats |
| +0x60â€“0x6c | RearWingMassInertia | 4 values |
| +0x70â€“0x78 | RearWingCollParams | 3 collision params |
| +0x7c | WheelBend | Wheel bending threshold |
| +0x80 | WheelDetach | Wheel detach threshold |
| +0x84 | WheelRandom | Wheel random failure chance |
| +0x88â€“0xfc | Wheel0â€“3 MassInertia | 4 wheels Ã— stride 0x1c (4 values each) |
| +0x118â€“0x158 | Part0â€“7 Detach | 8 parts Ã— 4 bytes (detach thresholds) |
| +0x13câ€“0x178 | Part0â€“7 Pos | 8 parts Ã— stride 0xc (3 floats each) |
| +0x1a0â€“0x250 | Part0â€“7 MassInertia+CollParams | 8 parts Ã— stride 0x1c |

**Moddability: HIGH.** All these fields are readable from `.svm`/`.hdv`
files. Randomizing `FrontWingDetach`, `RearWingDetach`, `WheelDetach`,
`Part%dDetach`, and `*Random` fields would create per-car damage variance â€”
some cars more fragile, some more durable. This is a major new moddable field
category: **damage model randomization**.

---

## FUN_004f6bf0 - RPM Range Loader (Per Gear)
### FUN_004f6bf0 â€” RPM Range Loader (Per Gear)

Reads MinimumRPM, MaximumRPM, NaturalRPM per gear (param_3 = gear 0â€“4).

**RPM struct (param_1, per gear, stride 0xc):**
| Offset | Field | Transform |
|--------|-------|-----------|
| +0x04 + gearÃ—0xc | MinimumRPM | Ã— _DAT_005ad258 (RPMâ†’rad/s) |
| +0x08 + gearÃ—0xc | MaximumRPM | Ã— _DAT_005ad258 |
| +0x0c + gearÃ—0xc | 1/NaturalRPM | _DAT_0059e420 / (NaturalRPM Ã— _DAT_005ad258) |

5 gears supported (0–4). NaturalRPM stored as reciprocal for fast physics multiply.

---

## FUN_0043ef20 — EngineStressSimulation

Source: vehicle_physics. Simulates engine block stress, RPM limits, oil temperature, and fatigue.

**Key logic:**
- Computes stress from crankshaft rotation delta (ABS of +0x1c5c)
- If RPM > threshold at +0x19c: reduces RPM by `torque * stress * friction`
  - If RPM drops below 0: stores ReasonCode=9 (`*(+0x1f00 → +0x4068)`)
  - Updates gauge display at `+0x1d4 → +0xac/+0xb4`
- Computes oil temperature at +0x1d4c with complex heat equation:
  - `ambient + (ambient_gap * convection + delta * radiation + stress * friction - cool * cool) * mass`
  - Clamps oil temp, applies sine-based ripple for gauge fluctuation
  - If above threshold: damps temperature oscillation
- Computes cylinder head temp at +0x1d8c with similar model
- **Wear/fatigue tracking** at +0x1db4:
  - If <= 0 (worn out): checks for complete failure at +0x1de4/0x1dec/0x1df4
  - When all axes zeroed: sets ReasonCode=1 (engine failure)
  - Random component failure distribution across 3 axes via ring buffer
  - Different failure patterns based on random thresholds (DAT_0059eb28, DAT_0059ec70, etc.)
- Resets vibration accumulators at +0x1dac/+0x1d08
- Calls FUN_0041ac50 to trigger failure animation/effect

**Struct offsets:** +0x1c5c (crank delta), +0x19c (RPM), +0x1d4 (gauge ptr → +0xac display, +0xb4 reciprocal), +0x1d4c (oil temp), +0x1d8c (head temp), +0x1db4 (wear remaining), +0x1de4/0x1dec/0x1df4 (wear axes), +0x1dac (vibration), +0x1f00 (vehicle ptr → +0x4068 ReasonCode)

**Globals:** DAT_008aae70, DAT_008aae74, DAT_008ab274 (random ring buffer)

**Calls:** FUN_005881f0 (random), FUN_0041ac50

**Moddability:** configurable — all temperature thresholds, wear rates, friction coefficients are constants

---

## FUN_004ed960 — FuelConsumptionAndWear

Source: vehicle_physics. Handles fuel consumption, tire wear, engine damage timers.

**Key logic:**
- Decreases fuel level at `param_1[0xe5e]` by `flow * consumption_rate * delta`
  - If fuel empty: sets ReasonCode=9
- Computes effective fuel mass: `fuel_level * 0.75 + base_mass`
- Computes tank capacity: `1.0 / effective_mass`
- If speed magnitude > threshold: applies tire wear
  - Aggregates 4 wheel loads, computes wear factor `1.0 - total_load * 0.25`
  - Each wheel: `wear -= factor * load * grip * TireWearMultiplier * delta`
  - If wear < 0.75: resets to 0.75 (minimum grip)
- Computes brake wear from brake bias + pedal input
- Detects speed change (> 0.01 threshold): updates speed display value with random jitter
- Runs 4 damage timers (engine modes: 0=engine, 1=gearbox, 2=suspension, 3=brake):
  - Decrements each active timer by delta
  - On timer expiry:
    - **Case 0 (engine):** Sets ReasonCode=1, random failure type distribution across 3 axes with random thresholds
    - **Case 1 (gearbox):** Sets ReasonCode=5, random gear damage
    - **Case 2 (suspension):** Sets ReasonCode=2, sets `param_1 + 0x39ee` flag, increments failure counter
    - **Case 3 (brake):** Sets ReasonCode=4, random increases brake failure accumulator
  - Resets failure accumulators after distribution
  - Checks EngineWearMode (`DAT_007cea5c == 3`): caps engine timer at 60.0

**Struct offsets:** param_1 → *param_1 + 0x4068 (ReasonCode). Various param_1 offsets for fuel, wear, damage timers.

**Globals:** DAT_007d0c60 (TireWearMultiplier), DAT_007cea5c (EngineWearMode), DAT_008aae70, DAT_008aae74, DAT_008ab274

**Calls:** FUN_004d21d0, FUN_0041ac50, FUN_004e8010

**Moddability:** `configurable` — fuel consumption rate, tire wear rate, damage timer durations, failure thresholds

---

## FUN_004BEC55 — EngineFailureCheck

Source: Unknown (physics/failure system). Checks whether engine/component wear has exceeded failure threshold; triggers failure with randomized severity.

**Key logic:**
- Takes a5 = vehicle object ptr, a4 = float array of wear values per component, a3 = session parameter block
- Outer loop iterates a4 array of components; each iteration: a4[104] holds failure threshold for current component
- If component state (+16484) == 1 (already failed), skip. If state == 2 or 3 (inactive/unused), skip.
- If current value (*a4) is negative, resets via sub_4BEA10 and clamps to zero
- If *a4 < a4[104] (wear exceeds threshold):
  - Calls sub_4BEF60(a5, 1.0) — checks if failure conditions met; returns 0 if not, 1+ if yes
  - If sub_4BEF60 returns 0: increment failure counter (+16444), compute remaining life at +16536, update +16540 and +16568 timing values, call sub_4BF390 (update failure state)
  - If return >= counter limit (+860) or flag v18: set state +16484 to 1 (failed)
  - If sub_4BEF60 returns nonzero: failure triggered — calls sub_4B33B0(4, 26, 1, ...) to play failure sound (sound ID 26)
  - If failure code == 1: severity = 6 (immediate failure)
  - Else: pick severity from ring buffer flt_8AAE74[dword_8AAE70++] via threshold chain: 0.30→sev1, 0.45→sev2, 0.60→sev3, 0.75→sev4, 0.89→sev5, 0.91→sev7, 0.93→sev8, 0.96→sev9, ≥0.96→sev0
  - Calls sub_4BBFC0 to create failure effect with severity code
- After loop, accumulate global failure timer dbl_8AFEA0 += time step (+848)
- If no active failures (v15 false or v16 false), call sub_4BF4F0 to clear/reset; reset dbl_8AFEA0
- Returns true if both v15 (active failure flag) and v16 (any failure occurred flag) are set

**Struct offsets (a5 = vehicle object):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4044 (16484) | FailureState | 0=normal, 1=failed, 2/3=inactive |
| +0x403C (16444) | FailureCounter | number of failure events accumulated |
| +0x40A8 (16536) | RemainingLifeCap | computed remaining component life |
| +0x40AC (16540) | WearLowWater | min wear value for this component |
| +0x40C8 (16568) | TimeGapToSession | session time remaining minus threshold |
| +0x32C8 (13000) | ComponentType | -1 = invalid/end marker |

**Globals:**
- `dbl_8AFEA0` — global failure timer accumulator (adds time step each frame)
- `flt_8AAE74` — ring buffer of random values for severity selection
- `dword_8AAE70` — ring buffer counter (incremented each access)
- `flt_8ACF90` — race time offset (RaceTimeOffset, docs/12)
- `dword_7C56A4` — SessionType (7=race, carries penalty; other modes skip)

**Calls:** FUN_0042AE90 (unknown), FUN_004BEA10 (failure/wear reset), FUN_004BEF60 (failure condition check), FUN_004B33B0 (sound play, ID 26 = failure sound), FUN_004BBFC0 (failure effect creation), FUN_004BF390 (failure state update), FUN_004BF4F0 (failure clear/reset)

**Moddability:** `hardcoded` — failure thresholds randomized via ring buffer; severity thresholds fixed

<!-- target: docs/20-math-utilities.md -->

