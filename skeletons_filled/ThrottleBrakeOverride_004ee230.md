## ThrottleBrakeOverride_004ee230 — throttle/brake override with sentinel detection

**Summary:** Computes override value from brake ratio and cooling factor (v1³ * factor * 0.5), replaces throttle/brake channel values when reference equals sentinel -789.0. Part of throttle/brake control system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x77C | RW | — | throttle/brake output channel 0 |
| this | 0x790 | RW | — | throttle/brake output channel 1 |
| this | 0x7A4 | RW | — | throttle/brake output channel 2 |
| this | 0x3570 | R | — | brake cooling effectiveness factor |
| this | 0x3994 | R | — | brake bias numerator (for override ratio) |
| this | 0x3998 | R | — | brake bias denominator (for override ratio) |
| this | 0x3D48 | R | — | reference value channel 0 (sentinel -789.0 → use override) |
| this | 0x3D4C | R | — | reference value channel 1 (sentinel -789.0 → use override) |
| this | 0x3D50 | R | — | reference value channel 2 (sentinel -789.0 → use override) |

**Written-by note (persistence):**
- this 0x77C: recalc every frame — external poke does NOT persist
- this 0x790: recalc every frame — external poke does NOT persist
- this 0x7A4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ad1f8 | dbl_5AD1F8 | R | UninitFloatMarker [DERIVED] (also: ` — Sentinel value -789.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Per channel: reference value == -789.0f → PASS (override with computed v2). BLOCKED: reference != -789.0 → keep original reference value.
