## AIDifficultyScalar_00424750 — AIDifficultyScalar

**Summary:** Maps AI difficulty slider value (0-100 range) to a performance scalar between 0.75 and 1.0. Above 95 returns flat 1.0 (maximum AI ability); below 95 uses linear interpolation: ((slider - 70) * 0.01) + 0.75.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_424080 (00424080), AISteeringCorrection (00426cf0), AIAbility (00429470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e860 | flt_59E860 | R | AIDifficultyScaleFactor [DERIVED] |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If dword_7D01A0 >= 95, returns 1.0 directly (skips linear interpolation). Below 95 falls through to compute scaled value.
