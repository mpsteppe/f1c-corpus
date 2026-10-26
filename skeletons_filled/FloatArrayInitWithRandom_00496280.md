## FloatArrayInitWithRandom_00496280 — FloatArrayInitUniform

**Summary:** Initializes 16 consecutive floats at offset 0x162C with values from 0.0 to 0.9375 in steps of 0.0625 (i/16). Calls sub_5881F0 for each value as a seed/transform step. Part of a lookup table or noise initialization system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x162C | RW | — | Start of 16-element float array; filled with uniform step values 0 to 15/16 |

**Written-by note (persistence):**
- this 0x162C: initialized once with 16 floats 0.0 .. 0.9375; persists unchanged after init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9e0 | flt_59E9E0 | R | Color channel scale factor constant (used by sub_5881F0 during seed/transform) |
| 005ac9c8 | dbl_5AC9C8 | R | Double constant (0.0625 = 1/16 step increment) used for array value generation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005881f0 | sub_5881F0 | Per-element processing/transform applied to each float value before storage (seeding or randomization) |

**Guard conditions:** None — loop always runs 16 iterations. No early exit.
