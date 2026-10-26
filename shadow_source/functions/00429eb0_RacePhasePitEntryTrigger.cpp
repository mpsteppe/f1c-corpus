// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00429EB0
// Canonical corpus name: RacePhasePitEntryTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RacePhasePitEntryTrigger_00429eb0.c

void UnknownObject::RacePhasePitEntryTrigger()
{
    // Per-frame AI pit-entry check: queries the fuel multiplier via FuelMultiplierValue; when the multiplier is below 1 (low fuel), the pit-requested flag at this[0x4550] is still clear, and the race phase (dword_7C56A8) equals 5 (pit window), forces a pit exit. Returns the last computed value otherwise. Called once per frame from AIAbility.
    // CALL: FuelMultiplierValue(this) queries the current fuel level multiplier; its return value gates the pit logic below. [callee:0x0042AD20]
    // GUARD: When the fuel multiplier result >= 1 (fuel still OK) the pit-forcing path is skipped and the multiplier is returned unchanged. [callee:0x0042AD20, source:raw]
    // ASSIGNMENT: result = this[0x4550], the pit-requested flag. [field:this:0x00004550]
    // GUARD: Pit forcing proceeds only when this[0x4550] == 0, i.e. a pit stop has not already been requested. [field:this:0x00004550]
    // GUARD: Pit forcing proceeds only when dword_7C56A8 == 5, the race phase corresponding to the pit window. [global:0x007C56A8]
    // CALL: ForcePitExit(this) is invoked to force the pit exit when all three guards pass. The callee is named only in the raw source; no address is evidenced for it in this packet. [source:raw]
    // RETURN: Return the current result value (the fuel multiplier, the pit-requested flag, or the outcome of the forced pit-exit path). [function:0x00429EB0, source:raw]

    // Conservative worker pseudocode:
    //   int RacePhasePitEntryTrigger(_DWORD *this) {
    //     int result = FuelMultiplierValue(this);
    //     if (result < 1) {
    //       result = this[0x4550];
    //       if (result == 0 && dword_7C56A8 == 5)
    //         return ForcePitExit(this);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: ForcePitExit is named only in the raw source text; its call target address is absent from the packet and cannot be stated.
    // UNRESOLVED: The return-value contract (fuel multiplier vs pit-requested flag vs force result) depends on caller interpretation.
}
