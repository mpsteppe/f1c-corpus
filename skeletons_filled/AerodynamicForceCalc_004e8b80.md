## AerodynamicForceCalc_004e8b80 — aerodynamic downforce/drag computation

**Summary:** Computes aerodynamic force from speed-squared with weight compensation, table lookup with linear interpolation, and quadratic drag formula. Part of aerodynamic dynamics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIRacingLine (00425920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | sprung mass factor (multiplied by gravity 9.81) |
| this | 0x3518 | R | — | aerodynamic downforce scaling multiplier |
| this | 0x3A70 | R | — | aerodynamic downforce speed² coefficient |
| this | 0x3BFC | R | — | aerodynamic force scaling factor |
| this | 0x3C00 | R | — | start of 14-entry aerodynamic lookup table (linear interpolation) |
| this | 0x3D3C | R | — | aerodynamic force maximum cap |
| this | 0x3D44 | R | — | additional aerodynamic drag/cross-term coefficient |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e99c | flt_59E99C | R | PhysicsConversionFactor [DERIVED] (also: ` — conversion factor) |
| 005aceb8 | flt_5ACEB8 | R | SuspensionOffsetConstant [DERIVED] (also: ` — constant offset in brush model) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | unknown — called with computed aerodynamic force value, no return used |

**Guard conditions:** v7 >= 0 → PASS (lookup table access). v7 >= 14 → clamped to index 13. v15 > 0 → PASS (quadratic solution path). BLOCKED: v15 <= 0 with a2 < 1.0 returns 0.0; v15 <= 0 with a2 >= 1.0 returns a2.
