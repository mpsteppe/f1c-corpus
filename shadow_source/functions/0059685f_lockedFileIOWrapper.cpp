// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059685F
// Canonical corpus name: FileIOWrapperWithLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileIOWrapperWithLock_0059685f.c

void UnknownObject::lockedFileIOWrapper()
{
    // Locked file-I/O wrapper: acquire the stream lock with StreamBufferLockViaCriticalSection(a2), run the inner operation sub_596888(a1, a2) forwarding both arguments, release the lock with AddressRangeCriticalSectionLeave(a2), and return the inner result. Callers include character-encoding validation and backward-scan string routines (CharValidationAgainstEncodingTableWithLocaleFall, CharByCharBackwardScanWithValidation) and sub_59BE0C.
    // CALL: Acquire the stream lock with StreamBufferLockViaCriticalSection(a2) using the stream handle a2 as the lock scope. [callee:0x0058C1B1, source:raw]
    // CALL: Run the inner operation: v2 = sub_596888(a1, a2), forwarding both arguments unchanged; v2 holds the result returned to the caller. [callee:0x00596888, source:raw]
    // CALL: Release the stream lock with AddressRangeCriticalSectionLeave(a2) before returning. [callee:0x0058C203, source:raw]
    // CALL: Used by CharValidationAgainstEncodingTableWithLocaleFall, CharByCharBackwardScanWithValidation and sub_59BE0C as a shared locked I/O primitive on string/encoding scan paths. [caller:0x00598FD4, caller:0x00599707, caller:0x0059BE0C]
    // RETURN: Return v2, the inner sub_596888 result, unchanged after the lock is released. [source:raw, function:0x0059685F]

    // Conservative worker pseudocode:
    //   int lockedFileIOWrapper(int a1, unsigned int a2) {
    //     int result;
    //     StreamBufferLockViaCriticalSection(a2);
    //     result = sub_596888(a1, a2);
    //     AddressRangeCriticalSectionLeave(a2);
    //     return result;
    //   }
    // UNRESOLVED: sub_596888's body is not in this packet; what I/O operation it performs under the lock and the role of a1 are not established.
    // UNRESOLVED: Whether StreamBufferLockViaCriticalSection (0x0058C1B1) and AddressRangeCriticalSectionLeave (0x0058C203) guard the same underlying critical section is inferred from naming, not proven here.
}
