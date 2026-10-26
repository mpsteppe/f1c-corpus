// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C7FC
// Canonical corpus name: FileIOThreeStepSequence
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileIOThreeStepSequence_0058c7fc.c

void UnknownObject::streamLockedThreeStepWrapper()
{
    // Three-step stream operation wrapper: acquire the stream lock with StreamBufferLockViaCriticalSection(a1), run the inner operation sub_58C824(a1) forwarding the same stream handle, release the lock with AddressRangeCriticalSectionLeave(a1), and return the inner result. A caller on the string-stream read path (StringStreamReadWithMaskCheck) uses it as a locked read primitive.
    // CALL: Acquire the stream lock with StreamBufferLockViaCriticalSection(a1) using the stream handle a1 as the lock scope. [callee:0x0058C1B1, source:raw]
    // CALL: Run the inner operation: v1 = sub_58C824(a1), forwarding the stream handle unchanged; v1 holds the result returned to the caller. [callee:0x0058C824, source:raw]
    // CALL: Release the stream lock with AddressRangeCriticalSectionLeave(a1) before returning. [callee:0x0058C203, source:raw]
    // CALL: Used by StringStreamReadWithMaskCheck on the string-stream read path, consistent with a locked read/forward wrapper. [caller:0x0058801D]
    // RETURN: Return v1, the inner sub_58C824 result, unchanged after the lock is released. [source:raw, function:0x0058C7FC]

    // Conservative worker pseudocode:
    //   __int64 streamLockedThreeStepWrapper(unsigned int stream) {
    //     __int64 result;
    //     StreamBufferLockViaCriticalSection(stream);
    //     result = sub_58C824(stream);
    //     AddressRangeCriticalSectionLeave(stream);
    //     return result;
    //   }
    // UNRESOLVED: sub_58C824's body is not in this packet; what operation it performs under the lock is not established beyond the forwarding of a1.
    // UNRESOLVED: Whether StreamBufferLockViaCriticalSection (0x0058C1B1) and AddressRangeCriticalSectionLeave (0x0058C203) guard the same underlying critical section is inferred from naming, not proven here.
}
