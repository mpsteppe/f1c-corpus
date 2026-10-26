## WheelForceAggregate_00430600 — WheelForceAggregate

**Summary:** Computes aggregate wheel forces from six indexed parameter triples using polynomial, quadratic, and linear physics models. Outputs summed lateral (a3) and longitudinal (a4) force components.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_430750 (00430750), BrakeTemperatureFadeModel (00430a50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xDF0 | R | — | First force term base value (double) |
| this | 0xDF8 | R | — | First force term multiplier (double) |
| this | 0xE04 | R | — | First force term index (int) |
| this | 0xE30 | R | — | Second force term base value (double) |
| this | 0xE38 | R | — | Second force term multiplier (double) |
| this | 0xE44 | R | — | Second force term index (int) |
| this | 0x1270 | R | — | Third force term base value (tire force) (double) |
| this | 0x1278 | R | — | Third force term multiplier (tire force) (double) |
| this | 0x1284 | R | — | Third force term index (tire force) (int) |
| this | 0x12B0 | R | — | Fourth force term base value (quadratic) (double) |
| this | 0x12B8 | R | — | Fourth force term multiplier (quadratic) (double) |
| this | 0x12C4 | R | — | Fourth force term index (quadratic) (int) |
| this | 0x12F0 | R | — | Fifth force term base value (linear) (double) |
| this | 0x12F8 | R | — | Fifth force term multiplier (linear) (double) |
| this | 0x1304 | R | — | Fifth force term index (linear) (int) |
| this | 0x1330 | R | — | Sixth force term base value (torque curve) (double) |
| this | 0x1338 | R | — | Sixth force term multiplier (torque curve) (double) |
| this | 0x1344 | R | — | Sixth force term index (torque curve) (int) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f3190 | QuadraticCubicPolynomialEvaluator | Evaluate quadratic/cubic polynomial for first/second force terms |
| 004f68b0 | TireForceTorqueComputation | Compute tire force/torque for third term with 0.025 time step |
| 004f6950 | QuadraticForceModel | Evaluate quadratic force model for fourth term |
| 004f69e0 | LinearVehicleParameterEvaluation | Evaluate linear vehicle parameter model for fifth term |
| 004f6a50 | QuadraticForceTorqueCurveEvaluation | Evaluate quadratic torque curve for sixth term with 0.025 time step |

**Guard conditions:** No guard — all six force terms computed unconditionally. All intermediate computations use `base + multiplier * index` pattern.
