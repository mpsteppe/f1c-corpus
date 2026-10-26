## QuadraticForceTorqueCurveEvaluation_004f6a50 — quadratic curve evaluation with split linear term

**Summary:** Evaluates a quadratic curve: a2²*C2 + a2*C1 + a2*C3 + C0. The linear contribution is split across two coefficients (C1 and C3). Disabled by flag at 0x4D4.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceAggregate (00430600), CollisionEnergy (004390a0), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4D4 | R | — | enable flag: non-zero computes output |
| this | 0x4D8 | R | — | constant term C0 (double) |
| this | 0x4E0 | R | — | linear coefficient C1 (double) |
| this | 0x4E8 | R | — | quadratic coefficient C2 (double) |
| this | 0x4F0 | R | — | additional linear coefficient C3 (double) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Byte at 0x4D4: non-zero → computes quadratic output into *a3. Zero → sets *a3 = 0.0.
