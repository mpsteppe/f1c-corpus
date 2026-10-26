## FuelMultiplierValue_0042ad20 — FuelMultiplierCalculator

**Summary:** Computes fuel multiplier as integer. If FuelMult flag enabled, multiplies fuel rate factor by theoretical laps-per-litre minus 0.2 offset; otherwise returns default value 100.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), RacePhasePitEntryTrigger (00429eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3448 | R | — | theoricNumberOfLapsWithOneLitre [CONFIRMED] |
| this | 0x3984 | R | — | fuelRateFactor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 007d0b64 | dword_7D0B64 | R | FuelMult [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `dword_7D0B64` (FuelMult) is non-zero, compute `CRTFtol(this[0x3984] * this[0x3448] - 0.2)`. If zero, return 100 without computing.
