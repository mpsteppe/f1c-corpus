## CollisionCoefficientApplication_00456f70 — CollisionForceAccumulate

**Summary:** Computes collision force/response by applying a direction-signed coefficient (0.4 or 6.0) multiplied by input acceleration, added to an accumulator at this[43], then clamped via ClampedFloatSetter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4085F0 (004085f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | R | — | source accumulator field (element [43]) fed into ClampedFloatSetter |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | sentinel/saturation constant |
| 0059ef9c | flt_59EF9C | R | force feedback gain multiplier |
| 0059efa0 | flt_59EFA0 | R | audio pan/LFE mix constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456fb0 | ClampedFloatSetter | clamps computed force value between bounds |

**Guard conditions:** a3 == 1 selects coefficient 6.0 instead of 0.4. a2 == 0 negates the coefficient. No early-return guards.
