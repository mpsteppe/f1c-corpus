## FuelWeightLimitCheck_0042ad50 — FuelSufficiencyCheck

**Summary:** Checks if fuel is sufficient for remaining race distance. Returns FALSE (low fuel) when computed fuel consumption exceeds remaining laps adjusted by stint factor. If FuelMult flag is zero, always returns TRUE (fuel check disabled).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3448 | R | — | theoricNumberOfLapsWithOneLitre [CONFIRMED] |
| this | 0x3984 | R | — | fuelRateFactor |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4040 | R | — | stintLapsRemainingFactor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e458 | flt_59E458 | R | ConstraintForceEpsilon [DERIVED] (also: ` — constraint force threshold (near-zero) |
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` â€” acceleration tuning) |
| 007d0b64 | dword_7D0B64 | R | FuelMult [DERIVED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `dword_7D0B64` (FuelMult) is zero, return TRUE immediately (fuel check bypassed). Else check: `(TotalRaceLaps - lapNumber) - (stintLapsRemainingFactor * 0.333...) < (fuelRateFactor * theoricNumberOfLapsWithOneLitre - 0.35)`. Returns TRUE when fuel consumption is within remaining laps (sufficient fuel).
