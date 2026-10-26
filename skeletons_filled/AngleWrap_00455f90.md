## AngleWrap_00455f90 — AngleNormalizeToPi

**Summary:** Normalizes a floating-point angle to the range [-PI, PI] by adding or subtracting 2*PI.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionResponseFilter (004584c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | angle value to normalize |

**Written-by note (persistence):**
- this 0x0: always written. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059efa4 | flt_59EFA4 | R | +PI constant (3.1415927) |
| 0059efa8 | flt_59EFA8 | R | 2*PI constant (6.2831855) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** *this > PI → subtract 2*PI. *this < -PI → add 2*PI. Values within [-PI, PI] pass through unchanged.
