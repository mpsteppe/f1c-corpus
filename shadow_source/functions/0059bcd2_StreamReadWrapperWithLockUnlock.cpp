// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BCD2
// Canonical corpus name: StreamReadWrapperWithLockUnlock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamReadWrapperWithLockUnlock_0059bcd2.c

void UnknownObject::StreamReadWrapperWithLockUnlock()
{
    // Critical-section-wrapped stream read wrapper: acquires the stream lock identified by a2 via StreamBufferLockViaCriticalSection, performs the read via sub_59BCFC(a1, a2), releases the lock via AddressRangeCriticalSectionLeave(a2), and returns the 16-bit read result. Called from FileOffsetPositionValidation.
    // CALL: Call StreamBufferLockViaCriticalSection(a2) to enter the critical section for stream handle a2. [callee:0x0058C1B1, source:raw]
    // CALL: Call sub_59BCFC(a1, a2), the actual read over the locked stream, and store its result in v2. [callee:0x0059BCFC, source:raw]
    // ASSIGNMENT: Assign v2 = result of sub_59BCFC(a1, a2) so it survives the unlock call. [source:raw]
    // CALL: Call AddressRangeCriticalSectionLeave(a2) to release the critical section for stream handle a2. [callee:0x0058C203, source:raw]
    // RETURN: Return the __int16 result captured from sub_59BCFC. [source:raw]
    // CALL: Invoked by FileOffsetPositionValidation, which validates an offset before reading through this wrapper. [caller:0x0059A01E, source:raw]

    // Conservative worker pseudocode:
    //   __int16 sub_59BCD2(int a1, unsigned int a2) {
    //     StreamBufferLockViaCriticalSection(a2);
    //     __int16 result = sub_59BCFC(a1, a2);
    //     AddressRangeCriticalSectionLeave(a2);
    //     return result;
    //   }
    // UNRESOLVED: What sub_59BCFC reads and the meaning of arguments a1 and a2 beyond 'stream handle key' is unknown.
    // UNRESOLVED: The critical section is keyed by a2; its owning object and scope are unresolved.
    // UNRESOLVED: The caller context (FileOffsetPositionValidation) suggests the read is gated on offset validation done by the caller.
}
