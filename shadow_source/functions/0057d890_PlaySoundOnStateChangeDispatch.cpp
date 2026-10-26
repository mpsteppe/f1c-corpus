// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057D890
// Canonical corpus name: SoundPlayDispatchWithStateChangeCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundPlayDispatchWithStateChangeCheck_0057d890.c

void UnknownObject::PlaySoundOnStateChangeDispatch()
{
    // Reads a thread-safe integer from this via ThreadSafeIntReadWithMutex; when the value at offset 0x14 of the a3 object differs from it, and the pointer at a3+28 is non-null, resolves that object through sub_4B3DB0 and dispatches the resulting handle with sub_57D6C0(this, a2, handle). Always returns 0.
    // ASSIGNMENT: Read the current thread-safe integer from this via ThreadSafeIntReadWithMutex and store into v4. [callee:0x00585770]
    // GUARD: Guard: proceed only when the value read via ReadFieldAtOffset0x14(a3) differs from v4. [callee:0x005871F0]
    // GUARD: Guard: proceed only when the pointer at a3+28 is non-null. [source:raw]
    // CALL: Resolve the object at a3+28 through sub_4B3DB0 and store the result into v6. [callee:0x004B3DB0]
    // CALL: Dispatch the resolved handle with sub_57D6C0(this, a2, v6). [callee:0x0057D6C0]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_57D890(void* this, unsigned int a2, int a3) {
    //     int v4 = ThreadSafeIntReadWithMutex(this);
    //     if ((unsigned int)ReadFieldAtOffset0x14(a3) != v4) {
    //       void* v5 = *(void**)(a3 + 28);
    //       if (v5) sub_57D6C0(this, a2, sub_4B3DB0(v5));
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the comparison field at a3+0x14 (state token) and of the object resolved by sub_4B3DB0 are unknown from this packet.
    // UNRESOLVED: Meaning of a2 for the sub_57D6C0 dispatch depends on the audio subsystem contract, not recoverable here.
}
