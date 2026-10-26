## CollisionTestWithThreshold_00500560 — Collision test with threshold and parameter interpolation

**Summary:** Tests collision state with threshold: if field is initialized and time delta is valid, interpolates audio parameters and cross-fades collision sample; otherwise performs basic parameter interpolation. Physics/collision system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UtilityFunction_3d50 (00463d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | Field compared against sentinel via FieldCompareConstant |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | Compare/copy arithmetic state between source and output |
| 004ff680 | AudioParameterInterpolation | Interpolate audio parameter state |
| 004ff8f0 | AudioSampleCrossFadeInterpolation | Cross-fade audio sample with position/rotation blend |
| 005000e0 | PhysicsFloatUpdateWithCompare | Update float value after spatial grid check |
| 005001d0 | FieldCompareConstant | Check field sentinel (initialization status) |
| 005001f0 | FloatComparisonCheck | Check float sentinel (initialization status) |

**Guard conditions:** If `FloatComparisonCheck(this)` returns FALSE → return early (uninitialized, value v7 undefined). If `FieldCompareConstant` returns TRUE AND `*(this+444) < a2` → enter threshold interpolation branch (clamp delta to [0.001, 0.5], then interpolate + cross-fade). Otherwise → direct parameter interpolation only. If `v13` (return value from interpolation) is set AND `a6` flag is set → also call `PhysicsFloatUpdateWithCompare`.
