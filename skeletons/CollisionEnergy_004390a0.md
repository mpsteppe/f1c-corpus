## CollisionEnergy_004390a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x144 | R | — | [LLM] |
| this | 0xDF0 | R | — | [LLM] |
| this | 0xDF8 | R | — | [LLM] |
| this | 0xE04 | R | — | [LLM] |
| this | 0xE30 | R | — | [LLM] |
| this | 0xE38 | R | — | [LLM] |
| this | 0xE44 | R | — | [LLM] |
| this | 0x1270 | R | — | [LLM] |
| this | 0x1278 | R | — | [LLM] |
| this | 0x1284 | R | — | [LLM] |
| this | 0x12B0 | R | — | [LLM] |
| this | 0x12B8 | R | — | [LLM] |
| this | 0x12C4 | R | — | [LLM] |
| this | 0x12F0 | R | — | [LLM] |
| this | 0x12F8 | R | — | [LLM] |
| this | 0x1304 | R | — | [LLM] |
| this | 0x1330 | R | — | [LLM] |
| this | 0x1338 | R | — | [LLM] |
| this | 0x1344 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059eba0 | dbl_59EBA0 | R | EnergyToDamageScaleFactor [DERIVED] (also: ` — energy-to-damage conversion factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f3190 | QuadraticCubicPolynomialEvaluator | [LLM] |
| 004f68b0 | TireForceTorqueComputation | [LLM] |
| 004f6950 | QuadraticForceModel | [LLM] |
| 004f69e0 | LinearVehicleParameterEvaluation | [LLM] |
| 004f6a50 | QuadraticForceTorqueCurveEvaluation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
