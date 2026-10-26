// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7DE0
// Canonical corpus name: sub_4D7DE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D7DE0_004d7de0.c

void UnknownObject::AtexitRegistration_4d7de0()
{
    // Trivial exit-registration thunk: calls BooleanToIntConversion (0x00587B3E, a critical-section-guarded push of its argument onto a global exit-callback list that returns 0 on success or -1 on failure) with the address of sub_4D7DF0 as its argument, and returns the int result. sub_4D7DF0 is a cleanup routine that invokes a method on the object referenced by a module global; the shape matches the MSVC atexit(...) registration idiom.
    // CALL: Call BooleanToIntConversion with the function address of sub_4D7DF0 as argument; this registers sub_4D7DF0 on the global exit-callback list guarded by a critical section. [callee:0x00587B3E, global:0x004D7DF0, source:raw]
    // RETURN: Return the int result of BooleanToIntConversion (0 on successful registration, -1 on failure). [function:0x004D7DE0, source:raw]

    // Conservative worker pseudocode:
    //   int AtexitRegistration_4d7de0() {
    //     return BooleanToIntConversion((int)sub_4D7DF0);
    //   }
    // UNRESOLVED: The object that owns this registration thunk is unknown; the packet assigns UnknownObject/UNKNOWN.
    // UNRESOLVED: The exact cleanup semantics of the registered function sub_4D7DF0 (which calls sub_4D89D0 on a module-global object) are outside this function's body and remain unverified here.
}
