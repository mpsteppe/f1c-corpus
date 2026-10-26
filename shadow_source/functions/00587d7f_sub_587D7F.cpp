// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587D7F
// Canonical corpus name: sub_587D7F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587D7F_00587d7f.c

void UnknownObject::sub_587D7F()
{
    // Lock-guarded delegation wrapper. Calls sub_58C5AC to obtain a critical-section state; when it is non-zero, runs the actual operation sub_58C43C(a1, a2, a3, state) while the lock is held, releases it with AddressRangeCriticalSectionLeave, and returns the operation's result. When the initial acquire result is zero, no operation runs and that zero is returned. The ABI lead labels this path as a CRT stream getc with lock/unlock, but the raw body shows only the locked delegation, not a getc primitive.
    // CALL: Call sub_58C5AC() to acquire/probe the critical-section state; the result is kept in v4. [callee:0x0058C5AC, source:raw]
    // GUARD: Only when the acquired state is non-zero does the guarded operation run; otherwise the function returns the zero result immediately. [function:0x00587D7F, source:raw]
    // CALL: Call sub_58C43C(a1, a2, a3, lockState) to perform the actual stream/address-range operation while the lock is held; the result is kept in v5. [callee:0x0058C43C, source:raw]
    // CALL: Release the lock by calling AddressRangeCriticalSectionLeave(lockState). [callee:0x0058C203, source:raw]
    // RETURN: Return the guarded operation's result v5 on success, or the zero acquire result on failure; the function is invoked by sub_587DB0. [function:0x00587D7F, caller:0x00587DB0, abi:lead]

    // Conservative worker pseudocode:
    //   state = sub_58C5AC();
    //   if (state != 0) {
    //     result = sub_58C43C(a1, a2, a3, state);
    //     AddressRangeCriticalSectionLeave(state);
    //     return result;
    //   }
    //   return 0;
    // UNRESOLVED: The actual operation inside sub_58C43C is not visible; the ABI label 'CRT stream getc' is only a lead, not grounded by the raw body.
    // UNRESOLVED: Whether sub_58C5AC is a strict lock acquire or a conditional/optional enter is not grounded.
    // UNRESOLVED: The semantics of the parameters a1 (const CHAR *), a2, and a3 are unknown.
}
