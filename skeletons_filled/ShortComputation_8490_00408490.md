## ShortComputation_8490_00408490 — FloatMultiplyByGlobalConstant

**Summary:** Multiplies the first float field of the struct by global constant flt_5BE8F8 and returns the result. Simple scaling utility used by steering/physics computations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870), SteeringAckermannComputation (004db170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first float field of struct; multiplied by global constant |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be8f8 | flt_5BE8F8 | R | SerializationScaleFactor [DERIVED] (also: ` — global float constant (serialization constant area, docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function always executes unconditionally.
