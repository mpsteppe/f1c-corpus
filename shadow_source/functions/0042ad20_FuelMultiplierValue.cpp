// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AD20
// Canonical corpus name: FuelMultiplierValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FuelMultiplierValue_0042ad20.c

void UnknownObject::FuelMultiplierValue()
{
    // Returns the fuel multiplier as an integer. When the dword_7D0B64 (FuelMult) flag is set, computes floor(fuelRateFactor * theoricalNumberOfLapsWithOneLitre - 0.2) via the CRT ftol conversion; otherwise returns the default value 100. On the per-frame path; called by AIAbility (0x00429470) and RacePhasePitEntryTrigger (0x00429EB0).
    // GUARD: If dword_7D0B64 (FuelMult flag) is non-zero, take the compute branch; otherwise take the default branch. [global:0x007D0B64, source:raw]
    // RETURN: When dword_7D0B64 is zero, return the default fuel multiplier value 100 without computing. [global:0x007D0B64, source:raw]
    // CALCULATION: Compute this[0x3984] * this[0x3448] - 0.2 (fuelRateFactor multiplied by theoricalNumberOfLapsWithOneLitre, minus a 0.2 offset) and convert the float result to int with CRT ftol. [field:this:0x00003984, field:this:0x00003448, source:raw]
    // RETURN: Return the computed integer fuel multiplier. [field:this:0x00003984, field:this:0x00003448, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0B64 == 0) return 100;
    //   return (int)(this[0x3984] * this[0x3448] - 0.2);
    // UNRESOLVED: flt_59E7E8 is listed as a read global by the fact table but does not appear in the raw decompiled source; its role here is unclear (existing_analysis labels it TimeScalingConstant, DERIVED).
    // UNRESOLVED: CRTFtol is invoked in the raw source but has no callee evidence reference in this packet; treated as a CRT float-to-long intrinsic, not a game callee.
}
