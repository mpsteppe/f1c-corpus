// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A163
// Canonical corpus name: FileWriteWrapperWithLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileWriteWrapperWithLock_0058a163.c

void UnknownObject::FileWriteWrapperWithLock()
{
    // Critical-section-guarded stream write wrapper. Acquires the stream-buffer lock via StreamBufferLockViaCriticalSection, reads a flag via sub_58E41B, performs the actual write via sub_58D04D(a1, a2, a3), conditionally clears struct fields via ClearStructFieldsIfFlagSet when the flag is set, releases the lock via AddressRangeCriticalSectionLeave, and returns the write result. Called by DebugLogWrite and BufferWriteWithStringLengthCheck.
    // CALL: Acquire the stream-buffer critical section via StreamBufferLockViaCriticalSection(a1) before writing. [callee:0x0058C1B1, source:raw]
    // CALL: v3 = sub_58E41B(a1); read a flag/state value that gates the later struct-field clearing. [callee:0x0058E41B, source:raw]
    // CALL: v4 = sub_58D04D(a1, a2, a3); perform the actual write of a2/a3 against the buffer owned by a1 and keep its result. [callee:0x0058D04D, source:raw]
    // CALL: ClearStructFieldsIfFlagSet(v3, a1); if the flag from sub_58E41B is set, clear struct fields on the object a1. [callee:0x0058E4A8, source:raw]
    // CALL: Release the stream-buffer critical section via AddressRangeCriticalSectionLeave(a1). [callee:0x0058C203, source:raw]
    // RETURN: Return v4, the result produced by sub_58D04D. [function:0x0058A163, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58A163(int a1, int a2, int a3) {
    //     StreamBufferLockViaCriticalSection(a1);
    //     int flag = sub_58E41B(a1);
    //     int written = sub_58D04D(a1, a2, a3);
    //     ClearStructFieldsIfFlagSet(flag, a1);
    //     AddressRangeCriticalSectionLeave(a1);
    //     return written;
    //   }
    // UNRESOLVED: Semantics of sub_58E41B's return value and of the field clearing in ClearStructFieldsIfFlagSet are unknown.
    // UNRESOLVED: Argument roles of a2/a3 for the write in sub_58D04D are not established from this function alone.
}
