// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AD50
// Canonical corpus name: FuelWeightLimitCheck
// Owner: PitStrategy [DERIVED]
// Raw source: functions/FuelWeightLimitCheck_0042ad50.c

void PitStrategy::isFuelSufficient()
{
    // Fuel sufficiency check for AI pit strategy. Returns TRUE immediately when the FuelMult global (dword_7D0B64) is zero (check disabled). Otherwise compares the remaining-laps quantity (TotalRaceLaps minus lap number, reduced by a stint factor) against a fuel-consumption estimate (fuel rate factor times theoretical laps per litre minus a margin) and returns TRUE when the remaining-laps quantity is the smaller one.
    // GUARD: Guard: if dword_7D0B64 (FuelMult) is zero, return TRUE immediately, bypassing the fuel check entirely. [global:0x007D0B64]
    // CALCULATION: Compute remaining laps quantity = (double)(dword_8ACF8C - lapNumber(this+0x403C)) - (double)stintLapsRemainingFactor(this+0x4040) * 0.33333334. [global:0x008ACF8C, field:this:0x0000403C, field:this:0x00004040]
    // CALCULATION: Compute fuel-consumption estimate = fuelRateFactor(this+0x3984) * theoricNumberOfLapsWithOneLitre(this+0x3448) - 0.34999999. [field:this:0x00003984, field:this:0x00003448]
    // RETURN: Return TRUE when the remaining-laps quantity is less than the fuel-consumption estimate (sufficient fuel for remaining distance), FALSE otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   if (!FuelMult) return TRUE
    //   remaining = (TotalRaceLaps - lapNumber) - stintFactor * 0.33333334
    //   consumed  = fuelRateFactor * theoreticalLapsPerLitre - 0.35
    //   return remaining < consumed
    // UNRESOLVED: The two literals 0.33333334 (stint scaling) and 0.34999999 (fuel margin) are not named in the packet; their roles are inferred from the surrounding formula.
    // UNRESOLVED: globals flt_59E458 and flt_59E98C are listed as read in the packet but do not appear in the raw decompiled body, so their role is unknown.
    // UNRESOLVED: The exact meaning of stintLapsRemainingFactor (this+0x4040) is not confirmed by the packet.
}
