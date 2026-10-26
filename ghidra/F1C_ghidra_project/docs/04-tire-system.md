# Tire System - Compounds, Slip Curves, AI vs Player

## Tire Parameters â€” AI vs Player Separation

Source: `FUN_004d6b00` @ `0x004d6b00` (`.tbc` tire loader)

AI tire behavior uses **separate parameters** from player:

```
iVar3 + 0xe0  = WearRate        (player tire wear rate)
iVar3 + 0x110 = AIWear          (AI-specific wear multiplier â€” separate)
iVar3 + 0x100 = AIGripMult      (AI grip multiplier)
iVar3 + 0xf0  = AISens          (AI tire sensitivity, min/max)
iVar3 + 0xf8  = AISens max
```

AI tire wear is independently scaled from player. Modifying `WearRate` alone does not
affect AI tire strategy.

---


## FUN_004537b0 / FUN_00454350 - Tire Compound Struct Layout
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

## tire_manager.cpp - Full Module Analysis (7 functions)
### tire_manager.cpp â€” Full Module Analysis (7 functions)

#### FUN_004d7660 â€” Tire Brand Directory Loader

Scans `*.tbc` directory (path from `DAT_005ec3d8`/`DAT_005ec428`). For each `.tbc`
file found, calls `FUN_004d7150` to load it.

**Tire brand manager struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | brand count |
| +0x04 | brand array (stride 0x24, each entry = name ptr + FUN_004d7150 result) |

#### FUN_004d7150 â€” .tbc File Loader

Opens `.tbc` file, counts `SLIPCURVE` and `COMPOUND` sections, allocates arrays,
then re-reads file dispatching to `FUN_004d5f70` (slip curve parser) and
`FUN_004d6b00` (compound parser, already documented).

**Tire brand struct (param_1, within brand array entry):**
| Offset | Field |
|--------|-------|
| +0x08 | slipcurve count |
| +0x0c | slipcurve array (stride 0x18, each = name ptr + curve data) |
| +0x10 | compound count |
| +0x14 | compound array (stride 0x2a8) |

Compound struct stride confirmed: **0x2a8 bytes** per compound.
Slipcurve struct stride: **0x18 bytes** per curve.

#### FUN_004d5f70 â€” Slip Curve Parser

Reads `SLIPCURVE` section data points. Builds cubic spline coefficients for
tire grip vs slip angle curve.

**Requirements:**
- First data point must be 0.0 (zero slip = zero lateral force origin)
- Minimum 3 data points
- Step must be positive

**Output struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | name pointer |
| +0x10 | point count |
| +0x14 | spline data array (stride 0x20: 4 doubles per segment â€” cubic coefficients) |
| +0x08 | peak slip value (computed) |
| +0x0c | peak grip value (computed) |

Computes peak slip/grip by evaluating the cubic spline and finding maximum.
Normalizes all coefficients by peak grip (divides by max).

#### FUN_004d5ee0 â€” Tire Load Factor Setter

Helper. Stores load factor (param_4/param_5 as double) and computes:
- `param_1[0]` = (param_2 + param_3) Ã— 0.5
- `param_1[1]` = (param_2 - param_3) Ã— 0.5
- `param_1[3]` = 1.0 / load_factor

#### FUN_004d7570 â€” Compound Index Lookup

Returns `compound_array + index Ã— 0x2a8`. Validates `0 â‰¤ index < compound_count`.

#### FUN_004d75d0 â€” Slip Curve Name Lookup

Linear search through slipcurve array by name string. Returns
`slipcurve_array + index Ã— 0x18`.

#### FUN_004d7880 â€” Tire Brand Name Lookup

Linear search through brand array by name. Returns `brand_array + index Ã— 0x24`.

---


## FUN_004a4ed0 - Tire/Wheel Graphics Mesh Loader

Source: pitcrew.cpp or vehicle graphics. Maps tire mesh names to wheel indices and loads tire mesh files for visual rendering.

**Wheel index mapping:**
| Mesh Name | Index |
|-----------|-------|
| LFTIRE | 0 (left front) |
| RFTIRE | 1 (right front) |
| LRTIRE | 2 (left rear) |
| RRTIRE | 3 (right rear) |

Also handles: SHADOWOBJECT, LODOUT, LODIN, MESHFILE (level-of-detail mesh files).

Not moddable - graphics mesh mapping only.

---

## FUN_004a4830 — Tire Compound Name → ID Mapping

Source: tire system (tire_manager or hdvehicle). Maps tire compound name strings to internal integer IDs used throughout the game.

**Mapping:**
| Name String | ID |
|-------------|-----|
| `"Hard Compound"` | 2 |
| `"Soft Compound"` | 3 |
| `"Intermediate Compound"` | 4 |
| `"Wet Compound"` | 5 |
| `"Monsoon Compound"` | 6 |

Note: The `"Compound"` suffix is part of the stored string — the `.tbc` file `[COMPOUND]` section uses shorter names internally.

**Calls:** FUN_00588410 (string compare)

**Moddability:** Yes — **moddable field.** Tire compound names are used in `.tbc` file `[COMPOUND]` section header. If mods assigns custom tire compounds, it must write one of these 5 strings as the compound name. The mapping confirms:
- ID 2 = Hard (least grip, most durable)
- ID 3 = Soft (most grip, least durable)
- ID 4 = Intermediate
- ID 5 = Wet
- ID 6 = Monsoon

---
## FUN_0043e050 — TireModelInit (tire physics constants)

Source: likely hdvehicle/tire.cpp. Initializes tire traction model globals and sets up tire subsystem parameters based on TireModelMode.

**Key logic:**
- Calls FUN_005881c0 (probably memory/alloc init)
- Sets *(param_1 + 0x1f00) from stack parameter (context data)
- Writes *(int *)(param_1 + 0x60) = 0, *(int *)(param_1 + 100) = 0 (zero init wheel states)
- Computes tire model step: `400 >> (TireModelMode & 0x1f)`, writes to `*(double *)(param_1 + 0x68)` and global `_DAT_005e5240`
- `_DAT_005e5240` = double(400 >> TireModelMode) × `_DAT_0059ec70` (tire multiplier)
- `_DAT_005e5238` = `_DAT_005e5240`² (squared for use in force calcs)
- `_DAT_005e5240` = `_DAT_005e5240` × 2 (doubled)
- Calls initialization chain: FUN_0042e320, FUN_004f34e0, FUN_004f4270(x2), FUN_00438da0, FUN_00439210, FUN_0043c250, FUN_00438cc0, FUN_00438f00
- If FUN_00567740() return != 0x200: calls FUN_00567780 (alternative init path)
- Frees any non-null params via FUN_00587bcf (6 params checked)
- Calls FUN_0042ddd0 (cleanup/shutdown hook)

**Globals:**
- `DAT_007ce958` — TireModelMode (controls tire model resolution: 0=simple, 2=medium, 3=detailed)
- `_DAT_005e5240` — Tire traction constant (computed)
- `_DAT_005e5238` — Tire traction constant squared
- `_DAT_0059e420` — Base constant (1.0, near)
- `_DAT_0059ec70` — Tire multiplier factor

**Calls:** FUN_005881c0 (alloc), FUN_00567740 (query mode), FUN_00567780 (alt init), FUN_0042e320, FUN_004f34e0, FUN_004f4270, FUN_00438da0, FUN_00439210, FUN_0043c250, FUN_00438cc0, FUN_00438f00, FUN_0042ddd0, FUN_00587bcf (free)

**Moddability:** `configurable` — TireModelMode from .hdv or .svm affects computed constants

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e88b0 — TireGripCoefficient

Source: tire_grip.cpp | Confidence: High
Computes tire grip/force coefficient from multiple vehicle state channels with 3-mode selection and clamping. Central to AI tire force estimation (called by AI following/pathing in FUN_004e8780, docs/02).

**Key logic:**
- Selects computation mode from param_1+0x39b4 (int): 0, 1, or 2
- Mode 0 (front grip): Computes 3 candidate force terms from vehicle struct fields:
  - Term A: +0x39c8 × +0x39a8 × _DAT_0059e450 (0.5f)
  - Term B: (+0x38f8 × +0x38b4 + Term A) × +0x3900
  - Term C: (+0x3800 × +0x37bc + Term A) × +0x3808
  - Selects max of Term B, Term C, and (+0x3710 × +0x3708 × +0x36c4)
  - Clamps against min of (+0x3618 × +0x3610 × +0x35cc, Term C, Term B)
- Mode 1 (rear grip): Similar structure with 4 candidates, uses _DAT_0059e7f8 instead of _DAT_0059e450
- Mode 2 (combined): Mixes front/rear patterns with _DAT_0059e450 scale factor
- Final result clamped to [DAT_0059e440 (ZeroThreshold), _DAT_0059e43c (1.0f)]

**Struct offsets (param_1 vehicle struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x39b4 | TireGripMode | Selector (0=front, 1=rear, 2=combined) |
| +0x39c8 | LateralCoeff | Lateral force coefficient |
| +0x39a8 | LoadSensitivity | Load sensitivity factor |
| +0x38f8 | ForceChannelA | Force/velocity channel A |
| +0x38b4 | ForceChannelB | Force/velocity channel B |
| +0x3900 | ForceChannelScaleA | Scale for channel A |
| +0x3800 | ForceChannelC | Force/velocity channel C |
| +0x37bc | ForceChannelD | Force/velocity channel D |
| +0x3808 | ForceChannelScaleC | Scale for channel C |
| +0x3710 | ForceChannelE | Force/velocity channel E |
| +0x3708 | ForceChannelF | Force/velocity channel F |
| +0x36c4 | ForceChannelScaleE | Scale for channel E |
| +0x3618 | ForceChannelG | Force/velocity channel G |
| +0x3610 | ForceChannelH | Force/velocity channel H |
| +0x35cc | ForceChannelScaleG | Scale for channel G |

**Globals:**
- DAT_0059e440 (ZeroThreshold) — lower clamp (0.0f, docs/12)
- _DAT_0059e43c (PhysicsBaseSpeed/1.0f) — upper clamp (1.0f? 0x3f800000, docs/12)
- _DAT_0059e450 (HalfConstant/0.5f) — scale factor (docs/12)
- _DAT_0059e7f8 (AntiRollMixingFactor) — scale factor for mode 1 (docs/12)

**Calls:** none (leaf computation, pure arithmetic + branches)

**Used by system:** docs/02-ai-system.md, docs/18-physics-dynamics.md, docs/20-math-utilities.md

**Moddability:** hardcoded (mode selection and thresholds are constants, but struct fields may be configurable)

<!-- target: docs/19-renderer.md -->

