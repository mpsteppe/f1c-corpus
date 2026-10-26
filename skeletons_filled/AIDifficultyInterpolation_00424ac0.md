## AIDifficultyInterpolation_00424ac0 — AIDifficultyInterpolation

**Summary:** Maps AI difficulty slider to an interpolated ability value using three anchor constants (low/mid/high). Below 100 uses low-to-mid linear interpolation; above 100 uses mid-to-high extrapolation. Called once during AI driver struct init.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIDriverStructInit (00424790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e474 | flt_59E474 | R | PhysicsConstant_59E474 [DERIVED] |
| 005ea3dc | flt_5EA3DC | R | DifficultySlopeLow [DERIVED] |
| 005ea3e0 | flt_5EA3E0 | R | AIDifficultyMidValue [DERIVED] |
| 005ea3e4 | flt_5EA3E4 | R | RaceAbility_HighRange [DERIVED] |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If dword_7D01A0 > 100, uses high-range interpolation (mid + (high - mid) * (slider - 100) * 0.05). Else (slider <= 100), uses low-range interpolation ((slider - 70) * 0.0333 * (mid - low) + low).
