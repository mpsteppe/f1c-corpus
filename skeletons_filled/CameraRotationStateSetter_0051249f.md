## CameraRotationStateSetter_0051249f — Store camera rotation values with validation flag

**Summary:** Stores two double-precision rotation parameters as floats at offsets 0x130/0x134; sets flag bit 5 on byte at offset 0x61 when the product of the two values deviates from 1.0 by more than 0.05.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x61 | RW | — | flags byte; bit 5 set on invalid rotation product |
| this | 0x130 | RW | — | float storage for rotation value a3 |
| this | 0x134 | RW | — | float storage for rotation value a2 |

**Written-by note (persistence):**
- this 0x61: bit 5 OR-set conditionally; persists until cleared
- this 0x130: overwritten each call with a3 as float
- this 0x134: overwritten each call with a2 as float

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] — constant 1.0 used in product validity check |
| 005af428 | dbl_5AF428 | R | EpsilonThreshold [DERIVED] — tolerance 0.05 for product deviation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `fabs(a2 * a3 - 1.0) > 0.05`. If product of the two rotation values deviates from 1.0 beyond 0.05 threshold (PASS), sets bit 5 on flag byte; if within tolerance (BLOCKED), skips flag modification. Floats written unconditionally.
