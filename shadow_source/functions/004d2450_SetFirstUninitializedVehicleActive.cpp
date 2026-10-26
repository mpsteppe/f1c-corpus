// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D2450
// Canonical corpus name: sub_4D2450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D2450_004d2450.c

void UnknownObject::SetFirstUninitializedVehicleActive()
{
    // Scans the active-vehicle pointer table dword_7C54F0 over dword_5C329C slots for the first slot whose in-use flag at offset 0x4064 (16484) is zero, then marks that slot active by setting the flag to 1 (unless the current value is 3) and returns the slot base plus 0x4034 (16436). If every checked slot is already in use, returns the slot count. Matches the ABI lead Set_First_Uninitialized_Vehicle_Active.
    // ASSIGNMENT: Initialize the scan index result to 0. [source:raw]
    // GUARD: Proceed only when the slot count dword_5C329C is positive; otherwise skip the scan and fall through to the final return. [global:0x005C329C, source:raw]
    // LOOP: Walk the pointer table while the in-use flag at dword_7C54F0[result] + 16484 is nonzero, i.e. skip slots already active. [global:0x007C54F0, source:raw]
    // GUARD: Within the scan, if ++result reaches dword_5C329C return the count immediately (no free slot found). [global:0x005C329C, source:raw]
    // ASSIGNMENT: Capture the candidate slot pointer v1 = dword_7C54F0[result], read its flag v2 at +16484, and set result to the slot base v1 + 16436. [global:0x007C54F0, source:raw]
    // GUARD: Only overwrite the flag when its current value v2 is not 3. [source:raw]
    // ASSIGNMENT: Set the slot's active flag at (result + 48), which is the slot base + 16484, to 1. [source:raw]
    // RETURN: Return the found slot base plus 0x4034, or the slot count when the scan was exhausted or dword_5C329C was non-positive. [function:0x004D2450, source:raw]
    // CALL: Called by DispatchChainWithVTableCalls (0x0046DA20) and sub_46DC60 (0x0046DC60) to claim the first inactive vehicle slot during startup/dispatch paths. [caller:0x0046DA20, caller:0x0046DC60, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D2450(void) {
    //     int result = 0;
    //     if (dword_5C329C > 0) {
    //       while (*(_DWORD*)(dword_7C54F0[result] + 16484)) {
    //         if (++result >= dword_5C329C) return result;
    //       }
    //       v1 = dword_7C54F0[result];
    //       v2 = *(_DWORD*)(v1 + 16484);
    //       result = v1 + 16436;
    //       if (v2 != 3) *(_DWORD*)(result + 48) = 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the flag values: 3 is treated as a sentinel that must not be overwritten, and its meaning (e.g. player-owned or permanently-active slot) is unknown.
    // UNRESOLVED: The owner class of the scanned slot structure is unknown; the scan pattern matches the vehicle array but the slot stride is not established here.
}
