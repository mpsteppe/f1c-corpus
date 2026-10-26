## DivisionWithThreshold_004d5ea0 — SafeDivisorWithThreshold

**Summary:** Performs a guarded division: if divisor a3 <= 0, uses FLT_MAX (3.4028235e38) instead. Stores the (possibly clamped) divisor in this[1], and the result of (a2 - 1.0) / divisor in this[0].

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | result of (a2 - 1.0) / clamped divisor |
| this | 0x4 | RW | — | clamped divisor value (FLT_MAX if a3 <= 0) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059eae0 | flt_59EAE0 | R | FLT_MAX_Infinity [DERIVED] (also: ` — infinity/FLT_MAX return value) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a3 <= 0, uses 3.4028235e38 (FLT_MAX) as the divisor to prevent division by zero.
