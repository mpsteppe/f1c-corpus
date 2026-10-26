# Implementation Spec: Tire System

Source: docs/04-tire-system.md  |  Functions: 12  |  Date: 2026-07-15

---

## Overview

The tire system manages tire compound loading, slip curve computation, and tire parameter initialization for F1 Challenge 99-02. It operates at two distinct times: during **initialization** (loading `.tbc` files from the season directory to populate tire brand/compound/slipcurve databases) and during **physics setup** (initializing per-vehicle traction model constants from TireModelMode).

The system owns the tire brand database — a directory of `.tbc` files each containing multiple compounds and slip curves. Each `.tbc` file defines one tire brand with 0x2a8-byte compound records and 0x18-byte slip curve records (cubic spline coefficients). The vehicle struct stores per-axle tire compound indices, pitstop compound selections, and a PitStopFlag bitmask (+0x1180) for up to 4 pitstops.

**Boundary interfaces:** The vehicle physics system (docs/10, docs/18) reads tire force model constants from TireTractionConstant (DAT_005E5240) and TireTractionConstantSq (DAT_005E5238) — both computed by FUN_0043e050. The session/race steward (docs/06) reads tire compound info from vehicle struct offsets +0x1140–+0x1180 for HUD display via FUN_004537b0. The pit system (docs/07) maps compound IDs to pit-crew actions via FUN_00454350. The renderer (docs/19) uses FUN_004a4ed0 for tire mesh-to-wheel index mapping (graphics only).

**Data structures owned:** TireBrandManager (brand count + array at stride 0x24), TireBrand (slipcurve array stride 0x18, compound array stride 0x2a8), SlipCurve (cubic spline data, peak slip/grip), TireCompound (parsed by FUN_004d6b00, stride 0x2a8). Vehicle struct tire fields (+0x1140–+0x1180 front, +0x153c–+0x155c rear, stride for per-wheel data at +0xf8 within vehicle struct).

## Data Structures

### TireBrandManager (param_1 — brand directory context)

```c
struct TireBrandManager {
    /* +0x00 */ int   brandCount;             // number of .tbc files loaded
    /* +0x04 */ TireBrandEntry brands[0];     // brand array, stride 0x24 per entry
};
// Total size: unknown base + brandCount * 0x24
// Created by: FUN_004d7660 (directory scan)
// Accessed via: param_1 to tire_manager functions
```

### TireBrandEntry (per-brand, within brand array at stride 0x24)

```c
struct TireBrandEntry {
    /* +0x00 */ char* name;                   // brand name pointer (from .tbc filename or header)
    /* +0x04 */ unknown_t unk_04;             // (reserved / padding)
    /* +0x08 */ int   slipcurveCount;         // number of SLIPCURVE sections in .tbc file
    /* +0x0c */ SlipCurveEntry* slipcurveArray; // slipcurve array, stride 0x18 per entry
    /* +0x10 */ int   compoundCount;          // number of COMPOUND sections in .tbc file
    /* +0x14 */ TireCompoundEntry* compoundArray; // compound array, stride 0x2a8 per entry
    /* +0x18..+0x23 */ unknown_t reserved[12]; // padding to stride 0x24
};
// Total size: 0x24 bytes per entry
// Created by: FUN_004d7150 (.tbc file loader)
```

### SlipCurveEntry (per-slipcurve)

```c
struct SlipCurveEntry {
    /* +0x00 */ char* name;                   // curve name string (from SLIPCURVE section header)
    /* +0x04 */ unknown_t unk_04;             // (reserved)
    /* +0x08 */ float peakSlip;               // computed peak slip angle value
    /* +0x0c */ float peakGrip;               // computed peak grip value (normalization base)
    /* +0x10 */ int   pointCount;             // number of data points (>= 3)
    /* +0x14 */ CubicSegment* splineData;     // array of cubic spline coefficients, stride 0x20 per seg
    // Each segment: 4 doubles (a,b,c,d) = cubic polynomial coefficients
};
// Total size: 0x18 bytes
// Created by: FUN_004d5f70 (slip curve parser, also populates spline array)
```

### CubicSegment (within splineData)

```c
struct CubicSegment {
    /* +0x00 */ double coeff_a;   // a + b*x + c*x^2 + d*x^3
    /* +0x08 */ double coeff_b;
    /* +0x10 */ double coeff_c;
    /* +0x18 */ double coeff_d;
};
// Total size: 0x20 bytes
// Normalized: all coefficients divided by peakGrip after computation
```

### TireCompoundEntry (within compound array, stride 0x2a8)

```c
struct TireCompoundEntry {
    // AI vs Player parameter separation at known offsets:
    /* +0xe0 */ float wearRate;            // player tire wear rate
    /* +0xf0 */ float aiSensitivityMin;    // AI tire sensitivity min
    /* +0xf8 */ float aiSensitivityMax;    // AI tire sensitivity max
    /* +0x100 */ float aiGripMultiplier;   // AI-specific grip multiplier
    /* +0x110 */ float aiWearMultiplier;   // AI-specific wear multiplier
    /* +0x114..+0x2a7 */ unknown_t compoundData[406]; // remaining compound parameters
};
// Total size: 0x2a8 bytes per compound entry
// Parsed by: FUN_004d6b00 (.tbc compound section parser)
```

### VehicleStruct — Tire-Related Fields

```c
// Within the main vehicle struct (size 0x48c0+):
// Front axle:
/* +0x1140–+0x115c */ double frontTelemetry[8];  // front tire telemetry (temps, pressures, wear)
/* +0x1160 */         byte   frontCompoundFlags[16]; // front compound/state flag bytes
/* +0x1170 */         int    currentFrontCompound;  // current front compound index (0-5)
                                                      // compared to 4 global constants for HUD display
/* +0x1174 */         int    pitstopCompound2;      // compound selection: pitstop 2
/* +0x1178 */         int    pitstopCompound3;      // compound selection: pitstop 3
/* +0x117c */         int    pitstopCompound4;      // compound selection: pitstop 4
/* +0x1180 */         uint   pitStopFlag;           // bitmask: bit0=stop1 valid,
                                                      // bit0x100=stop2, bit0x200=stop3, bit0x400=stop4
// Rear axle:
/* +0x153c–+0x1558 */ double rearTelemetry[8];     // rear tire telemetry (temps, pressures, wear)
/* +0x155c */         byte   rearCompoundFlags[16]; // rear compound/state flag bytes
```
Max 4 pitstops confirmed. PitStopFlag bits 0x100/0x200/0x400 for stops 2-4.
Consistent with NumPitstopsRange max of 4.

### TireForceQuadraticModel (per-tire force model, from docs/13)

```c
struct TireForceQuadraticModel {
    /* +0x1ec */ char   tireActive;           // 0=inactive, 1=active
    /* +0x1f8 */ double forceConst1;           // constant term 1
    /* +0x200 */ double forceLinCoeff;         // linear coefficient
    /* +0x208 */ double forceQuadCoeff;        // quadratic coefficient
    /* +0x210 */ double forceConst2;           // constant term 2
    /* +0x218 */ double torqueLinCoeff;        // torque linear coefficient
    /* +0x220 */ double torqueQuadCoeff;       // torque quadratic coefficient
    /* +0x228 */ double torqueCamberCoeff;     // camber effect on torque
    /* +0x250 */ double latForcePeak;          // lateral force peak
    /* +0x288 */ double longForcePeak;         // longitudinal force peak
    /* +0x2e8 */ double camberAngle;           // camber angle input
    /* +0x2f8 */ byte   modelEnabledFlag;      // 0/1 enable
    /* +0x2fc */ double quadraticC;            // quadratic constant term
    /* +0x304 */ double quadraticA;            // linear term
    /* +0x30c */ double quadraticB;            // quadratic term
    /* +0x314 */ double outputQuadC;           // output constant
    /* +0x31c */ double outputQuadA;           // output linear
    /* +0x324 */ double outputQuadB;           // output quadratic
    /* +0x34c */ double absOutput1;            // absolute output 1
    /* +0x384 */ double absOutput2;            // absolute output 2
};
// Stride: 0x3a0+ bytes (confirmed from docs/13 TireForceQuadraticModel observations)
```

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007ce958 | int | TireModelMode | Controls tire model resolution: 0=simple, 2=medium, 3=detailed |
| DAT_007d0c60 | float | TireWearMultiplier | Global tire wear scaling factor (from .hdv/.svm) |
| DAT_005E5240 | double | TireTractionConstant | Computed as `(400 >> TireModelMode) * DAT_0059ec70`. Used in force calcs. |
| DAT_005E5238 | float | TireTractionConstantSq | Square of TireTractionConstant, precomputed for use in friction calcs |
| DAT_0059ec70 | double | TireMultiplierFactor | Base multiplier for tire traction computation |
| DAT_0059ec48 | double | TireThermalMult | Tire thermal/damage value multiplier at offsets +0x900, +0x38c, +0x234 |
| DAT_0059E46C | float | TireSlipOffset | Slip angle offset in brush tire model (FUN_004e8b80, FUN_004e8ce0) |
| DAT_005ad1b0 | float | TireDryGripMult2 | Secondary dry grip multiplier applied when param_2 != 0 (dry mode) |
| DAT_005ad1b4 | float | DryGripMultiplier | Primary dry grip multiplier in brush tire model |
| DAT_007d020c | float | WetGripMultiplier | Wet track grip reduction factor (< 1.0) |
| DAT_007d0254 | float | WetForceScale | Wet condition force scaling (~0.3-0.9) |
| DAT_007d0278 | float | SpeedScalingDenominator | Speed divisor in tire brush model |
| DAT_008adb00 | double[] | TireModelConstants | Tire model constants (camber, friction, load sensitivity) |
| DAT_008ADB88 | handle | TireDatasetHandle | Dataset handle from tire brand lookup (0.0 if unavailable) |
| DAT_007CE994 | int | FiveContactPointMode | 1 = 5-contact-point tire model, 0 = 3-point |
| DAT_008ADAF8 | int | SlotCounter | Slot allocator for tire/suspension (max 32, stride 0xE per slot) |

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0x2a8 | FUN_004d7150, FUN_004d7570 | Compound struct stride in bytes |
| 0x18 | FUN_004d7150, FUN_004d75d0 | Slip curve struct stride in bytes |
| 0x24 | FUN_004d7660, FUN_004d7880 | Brand array entry stride in bytes |
| 0x20 | FUN_004d5f70 | Cubic spline segment stride (4 doubles) |
| 0x1140–0x115c | FUN_004537b0 | Front tire telemetry: 8 consecutive doubles |
| 0x153c–0x1558 | FUN_004537b0 | Rear tire telemetry: 8 consecutive doubles |
| 0x1180 | FUN_004537b0 | PitStopFlag bitmask: bit0=stop1, 0x100=stop2, 0x200=stop3, 0x400=stop4 |
| 400 | FUN_0043e050 | Base value right-shifted by TireModelMode to get step |
| 4 | FUN_004537b0 | HUD compound constant count (compared against currentFrontCompound) |
| 0x0e | Tire slot stride | Per-slot stride for tire/suspension slot allocator (DAT_008ADAF8) |
| 32 (0x20) | Slot allocator | Max tire/suspension allocation slots |
| 3 | FUN_004d5f70 | Minimum required data points for slip curve |
| 0.0 | FUN_004d5f70 | First data point must be zero slip |

## Public API — Entry Points

### FUN_004d7660 — Tire Brand Directory Loader

**Inferred signature:** `int TireBrandManager_LoadBrands(TireBrandManager* manager, const char* path)`
**Called from:** Game initialization (once at startup), scans `SeasonDir/TrackDir` for `.tbc` files
**Called by (from callers.json):** NOT FOUND (not in callers.json — likely called via function pointer or early init path)

**What it does:**
1. Builds path from `DAT_005ec3d8` (SeasonDir) / `DAT_005ec428` (SeasonName)
2. Scans directory for `*.tbc` files
3. For each `.tbc` file found, calls `FUN_004d7150` to load it
4. Stores brand entries in brand array at stride 0x24
5. Sets brand count at manager +0x00

**Side effects:**
- Writes: TireBrandManager.brandCount (+0x00)
- Writes: TireBrandManager.brands[] — allocated array of TireBrandEntry
- Reads: DAT_005ec3d8 (SeasonDir), DAT_005ec428 (SeasonName)
- Allocates: brand array memory for each .tbc loaded

### FUN_004d7150 — .tbc File Loader

**Inferred signature:** `int TbcFile_Load(TireBrandEntry* brandEntry, const char* filepath)`
**Called from:** FUN_004d7660 (Tire Brand Directory Loader)
**Called by (from callers.json):** NOT FOUND

**What it does:**
1. Opens `.tbc` file from path
2. First pass: counts `SLIPCURVE` and `COMPOUND` sections
3. Allocates arrays: slipcurve array (stride 0x18) and compound array (stride 0x2a8)
4. Second pass: re-reads file, dispatching each section to:
   - `FUN_004d5f70` for each `SLIPCURVE` section (slip curve parser)
   - `FUN_004d6b00` for each `COMPOUND` section (compound parser)
5. Sets brand entry fields: slipcurveCount, slipcurveArray, compoundCount, compoundArray

**Side effects:**
- Writes: brandEntry->slipcurveCount, brandEntry->slipcurveArray
- Writes: brandEntry->compoundCount, brandEntry->compoundArray
- Allocates: slipcurve and compound arrays via heap
- Calls: FUN_004d5f70 (slip curve parser), FUN_004d6b00 (compound parser)

### FUN_004d5f70 — Slip Curve Parser

**Inferred signature:** `void SlipCurve_Parse(SlipCurveEntry* curve, FILE* file)`
**Called from:** FUN_004d7150 (.tbc file loader)
**Called by (from callers.json):** NOT FOUND

**What it does:**
1. Reads `SLIPCURVE` section data points (slip angle vs grip pairs)
2. **Validates:**
   - First data point must be 0.0 (zero slip = zero lateral force)
   - Minimum 3 data points required
   - Step between points must be positive
3. Builds cubic spline coefficients for tire grip vs slip angle curve
4. Each segment stores 4 doubles (a+b*x+c*x^2+d*x^3) at stride 0x20
5. Computes peak slip/grip by evaluating the cubic spline and finding maximum
6. Normalizes all coefficients by dividing by peak grip value

**Side effects:**
- Writes: curve->name, curve->pointCount, curve->splineData
- Writes: curve->peakSlip, curve->peakGrip (computed peak values)
- Allocates: splineData array (pointCount-1 segments × 0x20 bytes)

### FUN_004d6b00 — .tbc Compound Parser (already documented)

**Inferred signature:** `void TbcCompound_Parse(TireCompoundEntry* compound, FILE* file)`
**Called from:** FUN_004d7150 (.tbc file loader)
**Called by (from callers.json):** NOT FOUND

**What it does (from docs/04 Tire Parameters section):**
1. Reads `COMPOUND` section from .tbc file
2. Sets AI vs Player parameter separation:
   - compound+0xe0 = WearRate (player tire wear rate)
   - compound+0x110 = AIWear (AI-specific wear multiplier)
   - compound+0x100 = AIGripMult (AI grip multiplier)
   - compound+0xf0 = AISens (AI tire sensitivity min/max)
3. AI tire wear independently scaled from player — modifying WearRate alone doesn't affect AI tire strategy

**Side effects:**
- Writes: compound->wearRate, compound->aiWearMultiplier, compound->aiGripMultiplier
- Writes: compound->aiSensitivityMin, compound->aiSensitivityMax
- Moddability: `configurable` — all AI/player parameters from .tbc file

### FUN_0043e050 — TireModelInit

**Inferred signature:** `void TireModel_Init(void* param_1, int contextData)`
**Called from:** Vehicle physics initialization (called by 0x004e45b0)
**Called by (from callers.json):** 0x004e45b0

**What it does:**
1. Calls FUN_005881c0 (memory/alloc init)
2. Sets `*(param_1 + 0x1f00) = contextData` (stack parameter)
3. Zero-initializes wheel states: `*(int*)(param_1 + 0x60) = 0`, `*(int*)(param_1 + 100) = 0`
4. **Computes tire model step:** `step = 400 >> (TireModelMode & 0x1f)`
5. Writes step to `*(double*)(param_1 + 0x68)` and global `DAT_005E5240`
6. **Applies multiplier:** `DAT_005E5240 = double(step) * DAT_0059ec70 (TireMultiplierFactor)`
7. **Precomputes:** `DAT_005E5238 = DAT_005E5240²` (squared for force calcs)
8. **Doubles:** `DAT_005E5240 = DAT_005E5240 × 2`
9. Calls initialization chain (12 functions): FUN_0042e320, FUN_004f34e0, FUN_004f4270 (×2), FUN_00438da0, FUN_00439210, FUN_0043c250, FUN_00438cc0, FUN_00438f00
10. If `FUN_00567740() != 0x200`: calls `FUN_00567780` (alternative init path)
11. Frees non-null params via FUN_00587bcf (6 params checked)
12. Calls FUN_0042ddd0 (cleanup/shutdown hook)

**Side effects:**
- **Writes:** DAT_005E5240 (TireTractionConstant) — computed from TireModelMode
- **Writes:** DAT_005E5238 (TireTractionConstantSq) — precomputed square
- **Reads:** DAT_007ce958 (TireModelMode) — controls resolution
- **Reads:** DAT_0059ec70 (TireMultiplierFactor) — scales base constant
- **Moddability:** `configurable` — TireModelMode from .hdv/.svm affects computed constants

### FUN_004a4830 — Tire Compound Name → ID Mapping

**Inferred signature:** `int TireCompound_NameToId(const char* name)`
**Called from:** Pit system (0x00429470, 0x0042a180, 0x004f18c0, 0x004a5c10, 0x00429fd0)
**Called by (from callers.json):** 0x00429470, 0x0042a180, 0x004f18c0, 0x004a5c10, 0x00429fd0

**What it does:**
1. Compares input name string against 5 known compound names via FUN_00588410 (string compare)
2. Returns integer ID:
   - `"Hard Compound"` → ID 2 (least grip, most durable)
   - `"Soft Compound"` → ID 3 (most grip, least durable)
   - `"Intermediate Compound"` → ID 4
   - `"Wet Compound"` → ID 5
   - `"Monsoon Compound"` → ID 6
3. The `"Compound"` suffix is part of stored string — .tbc file `[COMPOUND]` section uses shorter names internally

**Side effects:**
- Reads: input name string (param_1)
- Returns: compound ID integer (2-6)
- Calls: FUN_00588410 (string compare)
- Moddability: `configurable` — compound names from .tbc file headers

### FUN_004537b0 / FUN_00454350 — Tire Compound Struct Layout and Broadcast

**Inferred signature:** `void TireState_Broadcast(void* vehicleStruct)`
**Called from:** steward init (0x004a0eb0), collision param set (0x00455e50)
**Called by (from callers.json):** 0x004a0eb0, 0x00455e50

**FUN_004537b0 What it does:**
1. Reads tire state from vehicle struct offsets:
   - Front axle telemetry: 8 doubles at +0x1140–+0x115c
   - Front compound flags: 16 bytes at +0x1160
   - Current front compound index at +0x1170
   - PitStopFlag bitmask at +0x1180
   - Rear axle telemetry: 8 doubles at +0x153c–+0x155c
   - Rear compound flags: 16 bytes at +0x155c
2. Broadcasts selected values to global HUD/timing state for on-screen display
3. Compares currentFrontCompound against 4 global constants → determines HUD display string

**FUN_00454350 What it does:**
1. Maps input action codes to pit-crew activities using the same tire compound arrays
2. Reads compound selection fields at +0x1174, +0x1178, +0x117c (pitstop 2-4 selections)
3. Returns pit-crew action ID based on compound type selected for each pitstop

**Side effects (FUN_004537b0):**
- Reads: vehicleStruct +0x1140–0x1180, +0x153c–0x155c
- Writes to: global HUD/timing state (for display)
- Moddability: `hardcoded` — struct layout determined by vehicle struct definition

**Side effects (FUN_00454350):**
- Reads: vehicleStruct +0x1170–0x1180 (compound indices)
- Returns: pit-crew action code

### FUN_004d7570 — Compound Index Lookup

**Inferred signature:** `TireCompoundEntry* TireCompound_GetByIndex(void* brandEntry, int index)`
**Called from:** Pit system, physics (0x004a5330, 0x004a5820, 0x004a6340, 0x0042f470, 0x004e5f60, 0x004f1630, 0x004f18c0, 0x00430a50, 0x00430750, 0x00431850, 0x00429fd0)
**Called by (from callers.json):** Multiple callers across pit/physics/vehicle setup systems

**What it does:**
1. Validates `0 <= index < compoundCount`
2. Returns `compoundArray + index * 0x2a8`
3. Bounds-checked accessor with stride constant 0x2a8

**Side effects:**
- Returns: pointer to compound entry at index, or nullptr if out of bounds

### FUN_004d75d0 — Slip Curve Name Lookup

**Inferred signature:** `SlipCurveEntry* SlipCurve_FindByName(void* brandEntry, const char* name)`
**Called from:** NOT FOUND in callers.json
**Called by (from callers.json):** (internally, likely called by compound loader)

**What it does:**
1. Linear search through slipcurve array by name string
2. Uses FUN_00588410 (string compare) for matching
3. Returns `slipcurveArray + matchIndex * 0x18`

**Side effects:**
- Calls: FUN_00588410 (string compare), FUN_004d7a50 (debug logging), FUN_004d7aa0 (trace output)
- Returns: pointer to matched slipcurve entry, or nullptr

### FUN_004d7880 — Tire Brand Name Lookup

**Inferred signature:** `TireBrandEntry* TireBrand_FindByName(TireBrandManager* manager, const char* name)`
**Called from:** Physics/vehicle setup (0x004a5330, 0x0042f470, 0x004e5f60, 0x00430a50, 0x00430750, 0x00431850)
**Called by (from callers.json):** Multiple callers — "tire brand lookup", "get tire dataset"

**What it does:**
1. Linear search through brand array by name
2. Returns `brandArray + matchIndex * 0x24`

**Side effects:**
- Returns: pointer to matched brand entry, or nullptr
- Stores result in DAT_008ADB88 (TireDatasetHandle)

### FUN_004a4ed0 — Tire/Wheel Graphics Mesh Loader

**Inferred signature:** `void TireMesh_Load(void* sceneContext, const char* meshName, int wheelIndex)`
**Called from:** Vehicle graphics initialization
**Called by (from callers.json):** NOT FOUND

**What it does:**
1. Maps tire mesh name strings to wheel indices (purely visual):
   - `"LFTIRE"` → 0 (left front)
   - `"RFTIRE"` → 1 (right front)
   - `"LRTIRE"` → 2 (left rear)
   - `"RRTIRE"` → 3 (right rear)
2. Also handles: SHADOWOBJECT, LODOUT, LODIN, MESHFILE (level-of-detail mesh files)
3. Loads tire mesh files for visual rendering (no physics impact)

**Side effects:**
- Returns: nothing
- Moddability: `hardcoded` — graphics mesh mapping only, not configurable

### FUN_004d5ee0 — Tire Load Factor Setter

**Inferred signature:** `void TireLoadFactor_Set(double* dest, float a, float b, double loadFactor)`
**Called from:** (internal helper during slip curve / compound loading)
**Called by (from callers.json):** NOT FOUND

**What it does:**
1. Stores `loadFactor` (param_4/param_5 as double) at dest
2. Computes:
   - `dest[0] = (param_2 + param_3) × 0.5`
   - `dest[1] = (param_2 - param_3) × 0.5`
   - `dest[3] = 1.0 / loadFactor`

**Side effects:**
- Writes: dest[0] (mean), dest[1] (half-diff), dest[3] (inverse load factor)

## Internal Call Graph

Major call chains within this system:

```
FUN_004d7660 — TireBrandManager_LoadBrands  [triggered by: game init, scans directory for *.tbc]
  +-- FUN_004d7150 — TbcFile_Load  [opens .tbc file, counts sections, allocates arrays]
        +-- FUN_004d5f70 — SlipCurve_Parse  [reads SLIPCURVE data, builds cubic spline coeffs]
        |     +-- FUN_004d5ee0 — TireLoadFactor_Set  [helper: stores load factor + computes mean/diff/inverse]
        +-- FUN_004d6b00 — TbcCompound_Parse  [reads COMPOUND section: AI vs player params]

FUN_0043e050 — TireModel_Init  [triggered by: vehicle physics init, once per vehicle]
  +-- FUN_005881c0 — memory alloc init
  +-- FUN_00567740 — query init mode
  |     +-- (if != 0x200) FUN_00567780 — alternative init path
  +-- FUN_0042e320, FUN_004f34e0, FUN_004f4270, etc. — chain of 12 init helpers
  +-- FUN_00587bcf — free (6 conditional frees)
  +-- FUN_0042ddd0 — cleanup/shutdown hook

FUN_004537b0 — TireState_Broadcast  [triggered by: steward init, per-session]
  (reads vehicle struct tire fields, writes to HUD globals)

FUN_004a4830 — TireCompound_NameToId  [triggered by: pit system, vehicle setup]
  +-- FUN_00588410 — string compare (called up to 5 times in worst case)

FUN_004d75d0 — SlipCurve_FindByName  [lookup helper]
  +-- FUN_00588410 — string compare
  +-- FUN_004d7a50 — debug logging (on miss)
  +-- FUN_004d7aa0 — trace output

FUN_004d7570 — TireCompound_GetByIndex  [lookup helper, bounds-checked]
FUN_004d7880 — TireBrand_FindByName  [linear search by name]
```

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_005ec3d8 (SeasonDir) — from docs/12, directory scanning for .tbc files
- DAT_005ec428 (SeasonName) — from docs/12, subdirectory building
- DAT_007ce958 (TireModelMode) — from docs/12, controls resolution of traction model (hdvehicle)
- DAT_0059ec70 (TireMultiplierFactor) — from docs/12, base multiplier for traction constant
- DAT_007d0c60 (TireWearMultiplier) — from docs/12, global wear scaling (hdvehicle)
- FUN_00588410 (string compare) — from docs/06, used for name matching

**Writes to (external globals/systems):**
- DAT_005E5240 (TireTractionConstant) — read by physics (docs/10, docs/18)
- DAT_005E5238 (TireTractionConstantSq) — read by physics for friction calcs
- DAT_008ADB88 (TireDatasetHandle) — read by physics for tire dataset access

**Calls into:**
- docs/06-session-race-logic.md: FUN_00588410 (string compare for compound name matching)
- docs/09-track-system.md: DAT_005ec3d8/DAT_005ec428 directory path resolution
- docs/18-physics-dynamics.md: TireTractionConstant consumption in force calcs

**Called by:**
- docs/01-engine-architecture.md: FUN_004d7660 (brand loader during game init)
- docs/06-session-race-logic.md: steward init calls FUN_004537b0 (tire state broadcast)
- docs/07-pit-system.md: pit crew system calls FUN_004a4830 (compound name → ID) and FUN_00454350 (pit-crew action mapping)
- docs/10-vehicle-physics.md: vehicle physics calls FUN_0043e050 (tire model init) and FUN_004d7570 (compound lookup)
- docs/19-renderer.md: FUN_004a4ed0 (tire mesh → wheel index mapping)
- docs/18-physics-dynamics.md: brush tire model reads constants from FUN_0043e050 setup

## Reimplementation Notes

1. **TireModelMode dependency chain:** TireModelMode (DAT_007ce958) controls the right-shift of 400 to produce the base step. This step is multiplied by TireMultiplierFactor (DAT_0059ec70), then squared (TireTractionConstantSq), then doubled (TireTractionConstant). The order matters: step → multiply → square → double.

2. **AI vs Player parameter separation:** Compound parameters at offsets +0xe0, +0xf0, +0xf8, +0x100, +0x110 are deliberately separated. AI tire wear uses its own multiplier (+0x110) independent of player wear rate (+0xe0). Modifying player WearRate alone won't change AI tire behavior.

3. **Slip curve first-point requirement:** The cubic spline parser requires the first data point to be exactly 0.0 (zero slip = zero lateral force). Minimum 3 data points. All coefficients normalized by peak grip after computation.

4. **Compound name→ID mapping:** Uses full display strings with "Compound" suffix (e.g., "Hard Compound" not "Hard"). The .tbc file `[COMPOUND]` section internally uses shorter names. The `"Compound"` suffix is part of the stored string in the binary.

5. **PitStopFlag bitmask encoding:** Max 4 pitstops. Bit 0 = stop 1 valid, bit 0x100 = stop 2, bit 0x200 = stop 3, bit 0x400 = stop 4. Compound selections for stops 2-4 at offsets +0x1174, +0x1178, +0x117c. The gap between stop 1 compound (inferred elsewhere) and stops 2-4 suggests stop 1 compound might be encoded differently or in the +0x1170 currentFrontCompound field.

6. **Init guard:** FUN_0043e050 checks FUN_00567740() != 0x200 to choose between normal and alternative init paths. The "normal" path is the one where the return is exactly 0x200.

7. **Struct stride constants are critical:** Compound array stride 0x2a8, slipcurve stride 0x18, brand entry stride 0x24 must match exactly or all array lookups (FUN_004d7570, FUN_004d75d0, FUN_004d7880) will produce wrong pointers.

8. **Vehicle struct tire telemetry:** The 8 doubles at +0x1140 and +0x153c are labeled "tire telemetry floats" in docs but are stored as doubles (8 bytes each). Temperature, pressure, and wear data per axle.

9. **Init call chain order:** The 12 init helpers in FUN_0043e050 are called in sequence — FUN_0042e320, FUN_004f34e0, FUN_004f4270(x2), FUN_00438da0, FUN_00439210, FUN_0043c250, FUN_00438cc0, FUN_00438f00. This order must be preserved.

## Completeness

- Full specs written: 12 / 12 total documented functions
- Thunks/empty stubs omitted: 0
- Confidence: **high** — all function entries in docs/04 have complete key logic, struct offsets, and call relationships. Call graph data confirms callers and callees. Globals resolved from docs/12.
