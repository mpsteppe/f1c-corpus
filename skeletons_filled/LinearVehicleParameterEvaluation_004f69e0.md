## LinearVehicleParameterEvaluation_004f69e0 — linear force/torque parameter evaluation

**Summary:** Evaluates linear combinations of input parameters (a2, a3, a4) with stored coefficients plus bias terms. Outputs force components (absolute values) and a combined torque-like quantity. No enable flag — always active.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceAggregate (00430600), CollisionEnergy (004390a0), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3F4 | R | — | bias term C0 for force component a5[2] (double) |
| this | 0x3FC | R | — | coefficient for a4 in force component a5[2] (double) |
| this | 0x444 | R | — | double taken as absolute value for a5[0] (force component) |
| this | 0x47C | R | — | double taken as absolute value for a5[1] (force component) |
| this | 0x4AC | R | — | bias term C0 for output *a6 (double) |
| this | 0x518 | R | — | coefficient for a3 in force component a5[2] (double) |
| this | 0x520 | R | — | coefficient for a3 in output *a6 (double) |
| this | 0x528 | R | — | coefficient for a2 in force component a5[2] (double) |
| this | 0x530 | R | — | coefficient for a2 in output *a6 (double) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always computes all outputs unconditionally.
