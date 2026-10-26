## SteeringInputSmoothingWithSaturation_004569b0 — SteeringInputSmoothAccumulate

**Summary:** Accumulates steering input with direction sign and multiplier (0.5 or 2.0) into two float state fields at offsets 0xA0 and 0xBC, with InterruptDispatch clamping after each update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | RW | — | primary accumulator field (element [40]) |
| this | 0xBC | RW | — | secondary accumulator field (element [47]) |

**Written-by note (persistence):**
- this 0xA0: always written. Accumulates across frames; external poke survives.
- this 0xBC: always written. Accumulates across frames; external poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | sentinel/saturation constant |
| 0059ef84 | flt_59EF84 | R | camera offset float constant |
| 0059ef88 | flt_59EF88 | R | unknown float constant |
| 0059efa8 | flt_59EFA8 | R | 2*PI constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058957a | InterruptDispatch | clamps or saturates the float value |

**Guard conditions:** a3 == 1 selects multiplier 2.0 instead of 0.5. LOBYTE(a2) == 0 negates the multiplier. No early-return guards.
