// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC2E0
// Canonical corpus name: AtexitRegistration_c2e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AtexitRegistration_c2e0_004dc2e0.c

void UnknownObject::AtexitRegistration_c2e0()
{
    // Trivial exit-registration thunk: calls BooleanToIntConversion (0x00587B3E, a critical-section-guarded push of its argument onto a global exit-callback list that returns 0 on success or -1 on failure) with the address of sub_4DC2F0 as its argument, and returns the int result. sub_4DC2F0 is a cleanup routine that destroys a linked list rooted at a module global; the shape matches the MSVC atexit(...) registration idiom.
    // CALL: Call BooleanToIntConversion with the function address of sub_4DC2F0 as argument; this registers sub_4DC2F0 on the global exit-callback list guarded by a critical section. [callee:0x00587B3E, global:0x004DC2F0, source:raw]
    // RETURN: Return the int result of BooleanToIntConversion (0 on successful registration, -1 on failure). [function:0x004DC2E0, source:raw]

    // Conservative worker pseudocode:
    //   int AtexitRegistration_c2e0() {
    //     return BooleanToIntConversion((int)sub_4DC2F0);
    //   }
    // UNRESOLVED: The object that owns this registration thunk is unknown; the packet assigns UnknownObject/UNKNOWN.
    // UNRESOLVED: The exact cleanup semantics of the registered function sub_4DC2F0 (which destroys a linked list rooted at a module global) are outside this function's body and remain unverified here.
}
