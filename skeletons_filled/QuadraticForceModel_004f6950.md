## QuadraticForceModel_004f6950 — simplified quadratic force model (no bias term)

**Summary:** Computes one torque (a4) and three force components (a3[0-2]) using quadratic polynomials and absolute values. Variation of tire force model without the bias/scale term on torque output.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceAggregate (00430600), CollisionEnergy (004390a0), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | R | — | enable flag: non-zero enables computation |
| this | 0x2FC | R | — | quadratic C0 for force component a3[2] |
| this | 0x304 | R | — | quadratic C1 for force component a3[2] |
| this | 0x30C | R | — | quadratic C2 for force component a3[2] |
| this | 0x314 | R | — | quadratic C0 for torque *a4 |
| this | 0x31C | R | — | quadratic C1 for torque *a4 |
| this | 0x324 | R | — | quadratic C2 for torque *a4 |
| this | 0x34C | R | — | double taken as absolute value for a3[0] (force component) |
| this | 0x384 | R | — | double taken as absolute value for a3[1] (force component) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Byte at 0x2F8: non-zero → computes all outputs. Zero → zeroes all four outputs (a4, a3[0-2]).
