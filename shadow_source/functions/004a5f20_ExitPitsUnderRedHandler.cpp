// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5F20
// Canonical corpus name: sub_4A5F20
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/sub_4A5F20_004a5f20.c

void F1CPitMachine::ExitPitsUnderRedHandler()
{
    // Pit-state handler fired once when the one-shot flag at this+0x180 is non-zero (the "exiting pits under red flag" condition). Notifies a state change to 0 via StateChangeNotify, clears the flag, increments the pit-exit counter in the vehicle's pit state at vehicle+0x406C, and calls AIFormationLap with the vehicle pointer. When the race-config gate dword_8ACFD4 equals 2 and penalties are enabled (dword_7CEF84), it either disqualifies (session type dword_7C56A4 == 7) or applies a time penalty via sub_4BBA90 with the aExitingPitsUnd message. Finally, if the sub-object pointer at this+0x14 is non-null, returns the result of the helper called on it; otherwise returns the trailing result value.
    // GUARD: Read one-shot flag at this+0x180; if zero, skip the whole state-change body. [field:this:0x00000180]
    // CALL: Notify state change: StateChangeNotify(this, 0). [callee:0x004A5C80]
    // ASSIGNMENT: Read the vehicle pointer stored at this+0 and compute its pit-state base at +16436. [field:this:0x00000000]
    // ASSIGNMENT: Clear the one-shot guard flag: this+0x180 = 0. [field:this:0x00000180]
    // CALCULATION: Increment the pit-exit counter at vehicle pit-state base +56 (vehicle+0x406C). [field:obj:0x0000406C]
    // CALL: Call AIFormationLap with the vehicle pointer read from this+0. [callee:0x0041A3A0, field:this:0x00000000]
    // GUARD: Race-config gate: only proceed when dword_8ACFD4 equals 2. [global:0x008ACFD4]
    // GUARD: Penalties-enabled gate: only act when dword_7CEF84 is non-zero. [global:0x007CEF84]
    // GUARD: Branch on session type: dword_7C56A4 == 7 selects disqualification, otherwise the time-penalty path. [global:0x007C56A4]
    // CALL: Disqualification path: DisqualificationHandler(aExitingPitsUnd). [callee:0x004BC0E0, global:0x005CD698]
    // CALL: Time-penalty path: sub_4BBA90(aExitingPitsUnd, 1000.0). [callee:0x004BBA90, global:0x005CD698]
    // GUARD: If the sub-object pointer at this+0x14 is non-null, call the helper on it and return its result. [field:this:0x00000014]
    // RETURN: Return the helper's result when the sub-object exists, otherwise the trailing result value. [field:this:0x00000014, source:raw]

    // Conservative worker pseudocode:
    //   char PitExitUnderRedHandler(void* this) {
    //     char result = this[384];
    //     if (result) {
    //       StateChangeNotify(this, 0);
    //       int* pitState = (int*)(*(int*)this + 16436);
    //       this[384] = 0;
    //       ++*(int*)(pitState + 56);
    //       AIFormationLap(*(int**)this);
    //       result = dword_8ACFD4 - 2;
    //       if (dword_8ACFD4 == 2) {
    //         result = dword_7CEF84;
    //         if (dword_7CEF84) {
    //           if (dword_7C56A4 == 7) result = DisqualificationHandler(aExitingPitsUnd);
    //           else result = sub_4BBA90((int)aExitingPitsUnd, 1000.0);
    //         }
    //       }
    //     }
    //     if (*(void**)((char*)this + 0x14)) return ShortComputation_3fe0(*(void**)((char*)this + 0x14));
    //     return result;
    //   }
    // UNRESOLVED: The helper called on the this+0x14 sub-object (ShortComputation_3fe0) is not listed in the packet callee table; its identity is unknown.
    // UNRESOLVED: The semantic meaning of the pit-state base offset 16436 and counter +56 (vehicle+0x406C) is inferred from the fill, not independently proven.
    // UNRESOLVED: global:0x005EB978 is listed as read but does not appear in the decompiled source text; role unresolved.
    // UNRESOLVED: dword_8ACFD4==2 and dword_7C56A4==7 exact enum meanings are DERIVED from the fill, not confirmed.
}
