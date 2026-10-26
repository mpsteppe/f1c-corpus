## CollisionEnergy_004390a0 — Collision energy computation with tire force evaluation

**Summary:** Computes total collision energy from weighted sums of damage parameters, then evaluates tire force and torque models across multiple polynomial/quadratic curve functions. Returns summed damage contributions. Part of vehicle collision damage system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x144 | R | — | Damage parameter index/ID for loop iteration |
| this | 0xDF0 | R | — | Energy weighting coefficient (double) |
| this | 0xDF8 | R | — | Energy scale factor (double) |
| this | 0xE04 | R | — | Damage parameter ID selector |
| this | 0xE30 | R | — | Energy weighting coefficient (double) |
| this | 0xE38 | R | — | Energy scale factor (double) |
| this | 0xE44 | R | — | Damage parameter ID selector |
| this | 0x1270 | R | — | Energy weighting coefficient (double) |
| this | 0x1278 | R | — | Energy scale factor (double) |
| this | 0x1284 | R | — | Damage parameter ID selector |
| this | 0x12B0 | R | — | Energy weighting coefficient (double) |
| this | 0x12B8 | R | — | Energy scale factor (double) |
| this | 0x12C4 | R | — | Damage parameter ID selector |
| this | 0x12F0 | R | — | Energy weighting coefficient (double) |
| this | 0x12F8 | R | — | Energy scale factor (double) |
| this | 0x1304 | R | — | Damage parameter ID selector |
| this | 0x1330 | R | — | Energy weighting coefficient (double) |
| this | 0x1338 | R | — | Energy scale factor (double) |
| this | 0x1344 | R | — | Damage parameter ID selector |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059eba0 | dbl_59EBA0 | R | EnergyToDamageScaleFactor [DERIVED] (also: ` — energy-to-damage conversion factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f3190 | QuadraticCubicPolynomialEvaluator | Evaluates quadratic/cubic polynomial for damage curve |
| 004f68b0 | TireForceTorqueComputation | Computes tire force and torque from damage/energy |
| 004f6950 | QuadraticForceModel | Evaluates quadratic force model from damage |
| 004f69e0 | LinearVehicleParameterEvaluation | Evaluates linear vehicle parameter from damage |
| 004f6a50 | QuadraticForceTorqueCurveEvaluation | Evaluates quadratic force-torque curve |

**Guard conditions:** None — always executes the 4-iteration loop and all evaluations.
