## TireCompoundPerWheelPhysicsApplication_0043da10 — Per-Wheel TireCompoundParameterLoader

**Summary:** Loads tire compound parameters (camber curves, temperature coefficients, wear rates, grip curves) from compound data and applies them to a per-wheel physics structure. Includes debug logging for missing slip curve files. Part of tire physics initialization per wheel.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250), sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | RW | — | suspension ratio output: (v29/v30) * max(range delta) written to this[43] |
| this | 0x145C | R | — | tire compound index (this[1303]), used for CompoundIndexLookup |

**Written-by note (persistence):**
- this 0xAC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e898 | dbl_59E898 | R | CamberAngleLimitDeg [DERIVED] (also: ` = 90.0 (camber angle limit, degrees) |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb40 | dbl_59EB40 | R | PositionScalingConstant [DERIVED] |
| 0059ec48 | dbl_59EC48 | R | TireThermalMult [DERIVED] |
| 0059ec50 | dbl_59EC50 | R | tire compound parameter — source for offset 152/camber angle |
| 0059ec58 | dbl_59EC58 | R | Unknown_Double_59EC58 [DERIVED] |
| 0059ec60 | dbl_59EC60 | R | SuspensionTravelOffset [DERIVED] |
| 0059ec68 | dbl_59EC68 | R | Unknown_Double_59EC68 [DERIVED] |
| 005c421c | aDDevF119992002 | R | SourcePathPrefix [DERIVED] |
| 005c4328 | aTireOptimumCam | R | TireOptimumCamString [DERIVED] |
| 005c4364 | aCouldNotFindOn | R | StringCouldNotFindOn [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 007d0c60 | dword_7D0C60 | R | TireWearMultiplier [DERIVED] |
| 008acea8 | dword_8ACEA8 | R | Unknown_Scene_Value [DERIVED] |
| 008aceac | dword_8ACEAC | R | Session_RaceConfig_CEAC [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00438100 | TorqueForceProductComputation | computes torque-force product from tire parameters |
| 004d5c70 | QuaternionTransformComputation | computes quaternion-based transform for tire orientation |
| 004d5ee0 | TireLoadFactorSetter | sets tire load factor from compound parameter triple |
| 004d6830 | CubicHermiteInterpolation | performs cubic Hermite spline interpolation (3 calls with (1.0, 0.0001)) |
| 004d6ae0 | VehicleSuspensionForceHelper | computes suspension force contribution from vehicle state |
| 004d7570 | CompoundIndexLookup | looks up compound data index from tire compound type |
| 004d75d0 | TireSlipCurveNameLookup | looks up tire slip curve by filename string |
| 004d7a50 | StringSplitLoop | string split/parse loop for debug logging check |
| 004d7aa0 | DebugLogWrite | writes debug log message to buffer |

**Guard conditions:** 
- `wheelIndex <= 1`: front wheel → compound offset = v3 + 24 (front compound data). BLOCKED (rear): offset = v3 + 352 (rear compound data).
- `!slipCurve0 || !slipCurve1 || !slipCurve2) AND SessionType != 5`: any slip curve lookup failed AND not server mode → conditionally log "Could not find..." debug message via StringSplitLoop gate. BLOCKED: skip logging (server mode or all curves found).
- `camberAngle >= 1.570796326794897 (π/2) AND SessionType != 5`: optimum camber angle ≥ 90° AND not server → conditionally log "Tire optimum cam..." debug message. BLOCKED: skip logging.
- `x87 status flags (v16 | v17)`: camber angle is zero or NaN → force camber scaling factors to 0 (division by zero guard). BLOCKED: compute 1/camber scaling factor.
- `TireModelMode != 0`: alternate tire model active → scale thermal/grip parameters by 0.92. BLOCKED: use default parameters.
- `dword_8ACEA8 > 0`: session has range data → iterate over race config entries computing max suspension range delta. BLOCKED: use delta = 0.0.
