## CubicHermiteInterpolation_004d6830 — TableCubicHermiteInterpolator

**Summary:** Performs 1D cubic Hermite interpolation from a coefficient table. Computes normalized parameter t = a3/a2 * this[8], clamps index to table bounds, then evaluates cubic polynomial: ((c3*t + c2)*t + c1)*t + c0, where coefficients are read from 32-byte stride entries in this[20].

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionContactGenerationAndFrictionResponse (00436870), TireCompoundPerWheelPhysicsApplication (0043da10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | scaling factor for computing normalized input t |
| this | 0x10 | R | — | table entry count (max index = count - 1) |
| this | 0x14 | R | — | pointer to cubic Hermite coefficient table (32-byte stride) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | converts double to float (narrowing cast) |

**Guard conditions:** If computed integer index v4 >= this[4] (table count), clamps to count-1. No early return; always evaluates interpolation.
