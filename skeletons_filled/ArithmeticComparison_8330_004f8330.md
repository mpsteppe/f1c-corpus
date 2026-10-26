## ArithmeticComparison_8330_004f8330 — inverse difference with zero floor

**Summary:** Computes 1.0 / (value_at_0x80 - value_at_0x84) if the difference is positive, otherwise writes 0. Used for computing a reciprocal distance or stiffness factor.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | R | — | minuend value (float) |
| this | 0x84 | R | — | subtrahend value (float) |
| this | 0x88 | RW | 0 | result: 1.0/diff if diff > 0, else 0 |

**Written-by note (persistence):**
- this 0x88: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Difference (0x80 - 0x84) <= 0.0 → result 0x88 = 0. Difference > 0.0 → result 0x88 = 1.0 / difference.
