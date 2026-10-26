## F_1DTableLookupWithLerp_004fd7e0 — 1D table lookup with linear interpolation

**Summary:** Looks up a value from a 1D float table (starting at `this+0x64`) indexed by `a2`, clamping at 3.75 and performing linear interpolation between adjacent entries. Physics/vehicle subsystem.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4423B0 (004423b0), sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | R | — | Last entry in lookup table (sentinel/high bound value) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — input value a2 for tire slip lookup) |
| 005ad2d0 | flt_5AD2D0 | R | SpeedComparisonThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Float-to-integer truncation (floor) for table index |
| 005895a2 | sub_5895A2 | Process float value (likely floor/fraction extraction for interpolation factor) |

**Guard conditions:** If `a2 >= 3.75`, return `this[40]` directly (clamp at high end of table). Otherwise interpolate between `this[v5+25]` and `this[v5+26]` using fractional part `(v7 - v4)`.
