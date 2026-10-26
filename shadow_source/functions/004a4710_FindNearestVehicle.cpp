// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4710
// Canonical corpus name: FindNearestVehicle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FindNearestVehicle_004a4710.c

void UnknownObject::FindNearestVehicle()
{
    // Searches the global vehicle pointer array (dword_7C54F0, terminated by byte_7C5690) for the candidate vehicle whose speed/distance delta from a target vehicle (index a2 into a per-slot pointer table at this) is smallest but still positive. Each candidate uses one of two delta paths: a live candidate delegates through AIDelegateCall, while a null slot whose base state at +13000 is not 1 falls back to the base vehicle data at +15016. Returns the winning vehicle pointer, or 0 when the target slot is null. Called by OpponentProximityScanTeamRecognition.
    // ASSIGNMENT: Initialize the return value to 0, the best-vehicle pointer v11 to 0, and the minimum-delta sentinel v10 to 99999.0 so any valid positive delta replaces it. [source:raw, function:0x004A4710]
    // GUARD: Guard on the target vehicle slot pointer at this[4*a2]; when null the function returns 0 immediately and skips the whole scan. [source:raw, function:0x004A4710]
    // LOOP: Iterate the vehicle pointer array starting at dword_7C54F0 up to the byte_7C5690 end sentinel, advancing one pointer per step. [source:raw, global:0x007C54F0, global:0x007C5690]
    // GUARD: Per-candidate branch: when the scanned slot pointer v6 is non-null, evaluate it via the AI delegate path. [source:raw]
    // CALL: Call AIDelegateCall(candidate) to obtain the candidate value used for the delta computation. [source:raw, callee:0x0042ADD0]
    // CALL: Call SpeedDeltaComputation(target vehicle, candidate value) to compute the distance/delta metric between the two vehicles. [source:raw, callee:0x00426CC0]
    // GUARD: Accept the candidate only when its delta is below the current minimum and greater than the zero threshold (flt_59E440, the ~0.0f clamp), so negative or zero deltas are rejected. [source:raw, global:0x0059E440]
    // ASSIGNMENT: On accept, record the new minimum delta into v10 and the winning candidate pointer into v11. [source:raw]
    // GUARD: Fallback branch for a null slot: use base vehicle data only when the state dword at base+13000 is not 1 (slot not reserved/active). [source:raw]
    // CALL: Fallback delta: call SpeedDeltaComputation(target vehicle, *(base+15016)) using the base vehicle value. [source:raw, callee:0x00426CC0]
    // GUARD: Accept the fallback candidate when its delta is below the current minimum and greater than the zero threshold. [source:raw, global:0x0059E440]
    // ASSIGNMENT: On accept, record the new minimum delta and the base vehicle pointer as the winner. [source:raw]
    // RETURN: Return the closest vehicle pointer found during the scan (0 if the target slot was null), consumed by the caller's proximity scan. [source:raw, caller:0x0042A7D0]

    // Conservative worker pseudocode:
    //   int sub_4A4710(_BYTE *this, int a2) {
    //     int result = 0;
    //     float best = 99999.0f;
    //     int winner = 0;
    //     if (!*(_DWORD*)&this[4 * a2]) return 0;
    //     for (int *p = dword_7C54F0; p < (int*)&byte_7C5690; ++p) {
    //       int cand = *(int*)p;
    //       if (cand) {
    //         double d = SpeedDeltaComputation(*(_DWORD*)&this[4 * a2], AIDelegateCall(cand));
    //         if (d < best && d > 0.0) { best = d; winner = cand; }
    //       } else if (*(_DWORD*)(*p + 13000) != 1) {
    //         double d = SpeedDeltaComputation(*(_DWORD*)&this[4 * a2], *(_DWORD*)(*p + 15016));
    //         if (d < best && d > 0.0) { best = d; winner = *p; }
    //       }
    //     }
    //     return winner;
    //   }
    // UNRESOLVED: flt_59E440 is read by the positive-delta guards but its exact numeric value (zero threshold) is DERIVED, not confirmed in this function.
    // UNRESOLVED: Semantics of AIDelegateCall's return value and the base-data dwords at +13000 and +15016 are unknown here.
    // UNRESOLVED: The exact stride/type of the this[4*a2] target slot table and whether a2 indexes slots or grid positions is unresolved.
}
