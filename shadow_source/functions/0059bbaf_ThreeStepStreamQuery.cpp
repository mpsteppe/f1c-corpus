// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BBAF
// Canonical corpus name: ThreeStepStreamQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreeStepStreamQuery_0059bbaf.c

void UnknownObject::ThreeStepStreamQuery()
{
    // Critical-section-wrapped stream query wrapper: acquires the stream lock identified by a2 via StreamBufferLockViaCriticalSection, runs the three-step query sub_59BBD9(a1, a2), releases the lock via AddressRangeCriticalSectionLeave(a2), and returns the 16-bit result. Called from sub_599ED6.
    // CALL: Call StreamBufferLockViaCriticalSection(a2) to enter the critical section for stream handle a2. [callee:0x0058C1B1, source:raw]
    // CALL: Call sub_59BBD9(a1, a2), the actual query over the locked stream, and store its result in v2. [callee:0x0059BBD9, source:raw]
    // ASSIGNMENT: Assign v2 = result of sub_59BBD9(a1, a2) so it survives the unlock call. [source:raw]
    // CALL: Call AddressRangeCriticalSectionLeave(a2) to release the critical section for stream handle a2. [callee:0x0058C203, source:raw]
    // RETURN: Return the __int16 result captured from sub_59BBD9. [source:raw]
    // CALL: Invoked by sub_599ED6, which wraps the query in the same lock/unlock discipline. [caller:0x00599ED6, source:raw]

    // Conservative worker pseudocode:
    //   __int16 sub_59BBAF(int a1, unsigned int a2) {
    //     StreamBufferLockViaCriticalSection(a2);
    //     __int16 result = sub_59BBD9(a1, a2);
    //     AddressRangeCriticalSectionLeave(a2);
    //     return result;
    //   }
    // UNRESOLVED: What sub_59BBD9 reads and the meaning of arguments a1 and a2 beyond 'stream handle key' is unknown.
    // UNRESOLVED: The critical section is keyed by a2; its owning object and scope are unresolved.
    // UNRESOLVED: Why the query is described as 'three step' is not visible in this wrapper.
}
