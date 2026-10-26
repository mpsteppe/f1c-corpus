// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D24A0
// Canonical corpus name: sub_4D24A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D24A0_004d24a0.c

void UnknownObject::AllActiveVehiclesSatisfyFlag()
{
    // Session state predicate with no arguments: returns true (1) when dword_5C329C (the count of active slots) is not positive, or when every one of the first dword_5C329C pointers in the dword_7C54F0 array points to a vehicle whose dword at byte offset 16484 (0x4064) is nonzero. Returns false (0) as soon as one active vehicle's +0x4064 dword is zero. Invoked from session end-condition evaluation paths.
    // ASSIGNMENT: Initialize the loop index v0 = 0 and the default result = 1 before the count check. [source:raw]
    // GUARD: Guard on dword_5C329C > 0; when the active-slot count is not positive the loop is skipped and the default true is returned. [global:0x005C329C, source:raw]
    // LOOP: Scan v0 across the first dword_5C329C entries of the dword_7C54F0 pointer array while each entry's dword at byte offset 16484 (0x4064) is nonzero. [global:0x007C54F0, source:raw]
    // GUARD: Inside the loop, increment v0 and return the default true once v0 reaches dword_5C329C, i.e. every active entry had a nonzero +0x4064 dword. [global:0x005C329C, source:raw]
    // RETURN: Return false when an active entry's +0x4064 dword is zero (the loop exits without index exhaustion). [source:raw]
    // RETURN: Return the default true when the count is not positive or the index reaches the count. [source:raw]
    // CALL: Called by SessionCheckEndCondition (0x0046D0D0) and ConditionalVirtualDispatchWithStateCheck (0x0046D360) while evaluating session end conditions. [caller:0x0046D0D0, caller:0x0046D360, source:raw]

    // Conservative worker pseudocode:
    //   char AllActiveVehiclesSatisfyFlag() {
    //     int i = 0;
    //     if (dword_5C329C <= 0) return 1;
    //     while (*(DWORD*)(dword_7C54F0[i] + 0x4064) != 0) {
    //       if (++i >= dword_5C329C) return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the per-vehicle dword at byte offset 16484 (0x4064) is unknown here; a nonzero value is required for a true result and likely flags a completed/retired state, but that is not evidenced in the packet.
    // UNRESOLVED: dword_5C329C is treated as the count of active slots because it bounds the scan of the dword_7C54F0 pointer array; its exact semantics are inferred, not named in the packet.
}
