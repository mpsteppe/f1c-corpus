// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C2F0
// Canonical corpus name: Thunk_c2f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_c2f0_0054c2f0.c

void UnknownObject::Thunk_c2f0()
{
    // Thunk that calls BooleanToIntConversion on the function pointer stored at 0x0054C300 and returns its result. The referenced global carries the name InitializationLoop256_c300 and is read only.
    // CALL: Call BooleanToIntConversion with the value at 0x0054C300 (global InitializationLoop256_c300) as its integer argument. [callee:0x00587B3E, global:0x0054C300, source:raw]
    // RETURN: Return the result of the BooleanToIntConversion call. [function:0x0054C2F0, source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_c2f0()
    //   {
    //     return BooleanToIntConversion((int)InitializationLoop256_c300);
    //   }
    // UNRESOLVED: Whether the global at 0x0054C300 holds a function pointer to an initialization loop (per its label) or a plain value, and why it is cast through BooleanToIntConversion, is not confirmed.
    // UNRESOLVED: The behavior and side effects of BooleanToIntConversion at 0x00587B3E are not examined here.
}
