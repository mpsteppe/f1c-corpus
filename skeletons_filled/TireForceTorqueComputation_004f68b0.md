## TireForceTorqueComputation_004f68b0 — tire force/torque computation with quadratic model

**Summary:** Computes tire force (3 components) and torque outputs using quadratic polynomials and absolute values. Force component a4[2] and torque a5 use quadratic functions of a2 with additional bias/scale terms on a3.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceAggregate (00430600), CollisionEnergy (004390a0), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1EC | R | — | enable flag: non-zero enables computation |
| this | 0x1F8 | R | — | quadratic C0 for force component a4[2] |
| this | 0x200 | R | — | quadratic C1 for force component a4[2] |
| this | 0x208 | R | — | quadratic C2 for force component a4[2] |
| this | 0x210 | R | — | quadratic C0 for torque *a5 |
| this | 0x218 | R | — | quadratic C1 for torque *a5 |
| this | 0x220 | R | — | quadratic C2 for torque *a5 |
| this | 0x228 | R | — | scale factor multiplied with (a3 + bias) for torque |
| this | 0x250 | R | — | double taken as absolute value for a4[0] (force component) |
| this | 0x288 | R | — | double taken as absolute value for a4[1] (force component) |
| this | 0x2E8 | R | — | bias added to a3 before scaling for torque |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Byte at 0x1EC: non-zero → computes all outputs. Zero → zeroes all four outputs (a5, a4[0-2]).
