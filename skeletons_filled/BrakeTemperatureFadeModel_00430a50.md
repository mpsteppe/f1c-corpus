## BrakeTemperatureFadeModel_00430a50 — brake temperature fade force model (per-wheel thermal degradation computation)

**Summary:** Computes the brake fade force reduction due to thermal degradation across all active wheels, using tire compound lookup, axle-specific temperature interpolation, and a per-wheel temperature-vs-fade lookup curve. Returns the normalized fade force ratio.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleStatsEstimationDisplay (00430f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC4 | R | — | tire compound index (passed to CompoundIndexLookup for compound data ptr) |
| this | 0xC30 | R | — | front axle brake temperature base/offset (double, used in interpolated temp calc) |
| this | 0xC38 | R | — | front axle brake temperature scale factor (double, multiplied by wear level) |
| this | 0xC44 | R | — | front axle brake wear level (int, converted to double for temperature formula) |
| this | 0xCB0 | R | — | rear axle brake temperature base/offset (double) |
| this | 0xCB8 | R | — | rear axle brake temperature scale factor (double) |
| this | 0xCC4 | R | — | rear axle brake wear level (int) |
| this | 0x1570 | R | — | per-wheel temperature threshold base/offset (double, in per-wheel loop) |
| this | 0x1578 | R | — | per-wheel temperature threshold scale factor (double) |
| this | 0x1584 | R | — | per-wheel wear factor (int, converted to double) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea58 | dbl_59EA58 | R | TireFormulaConstant [DERIVED] (also: /60/50/48 � Tire formula constants) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059ea68 | dbl_59EA68 | R | WheelSpeedFactor [DERIVED] |
| 0059ea70 | dbl_59EA70 | R | SuspForceConst [DERIVED] |
| 0059ea78 | dbl_59EA78 | R | DamperMultiplier [DERIVED] |
| 0059ea80 | dbl_59EA80 | R | AeroBalanceMult [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008adb00 | dword_8ADB00 | R | TireModelConstants [DERIVED] (also: /40/60 � Tire model constants (camber, friction, etc.) |
| 008adb40 | dbl_8ADB40 | R | Dbl_TireRoadMu_ADB40 [DERIVED] |
| 008adb88 | unk_8ADB88 | R | TireDatasetHandle [DERIVED] |
| 008ae194 | dbl_8AE194 | R | Double_Unknown_Physics [DERIVED] |
| 008aeec0 | dword_8AEEC0 | R | AeroSuspensionModeSelector [DERIVED] (also: ` — aero/suspension mode selector (0=fixed, 1=blended, 2=fixed-alt) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ed00 | SessionStateIndexedLookup | retrieves per-wheel brake temperature for a given wheel index |
| 00430600 | WheelForceAggregate | computes aggregate normal force and other wheel-load parameters |
| 004d5c70 | QuaternionTransformComputation | builds orientation quaternion from 3-axis suspension geometry data |
| 004d7570 | CompoundIndexLookup | looks up tire-compound data pointer from compound index |
| 004d7880 | TireBrandLookup | validates/looks up tire brand dataset from handle |
| 004f6720 | ParameterizedCurveInterpolation | interpolates on a per-wheel brake fade vs temperature lookup curve |

**Guard conditions:** 

| Condition | What PASSES | What is BLOCKED |
|-----------|-------------|-----------------|
| TireBrandLookup(&unk_8ADB88) returns 0 | — | function returns 0.0 (no tire dataset loaded) |
| CompoundIndexLookup result is null | — | function returns 0.0 (no compound data for this vehicle) |
| dword_8AEEC0 == 0 | fixed suspension mode: uses rear-axle temperature blend | — |
| dword_8AEEC0 == 1 | blended mode: averages front+rear compound geometry with 50/50 blend and 0.82/1.18 weighting | — |
| dword_8AEEC0 == 2 | fixed-alt mode: uses front-axle compound data directly | — |
| dword_8AEEC0 ∉ {0,1,2} | — | function returns 0.0 (invalid mode) |
| v28 (contact-patch/suspension load) <= 0.0 | — | function returns 0.0 (no load on contact surface) |
| per-wheel active flag byte at this+0xBCC + wheel*64 is zero | — | skips that wheel (inactive/broken) |
| per-wheel temperature <= 0.0 | — | function returns 0.0 (sensor fault / no data) |
| per-wheel temperature ratio v22 <= threshold i | wheel below thermal ceiling: interpolates fade curve | wheel above ceiling: skips fade contribution |
