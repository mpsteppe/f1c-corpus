// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587D02
// Canonical corpus name: FileCloseWithLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileCloseWithLock_00587d02.c

void UnknownObject::closeFileWithLock()
{
    // Conditional file close guarded by a flag bit and a critical-section lock. If the flag bit 0x40 at this+0xC is set, the dword there is cleared to 0 and the close is skipped, returning -1. Otherwise the stream lock is acquired (StreamBufferLockViaCriticalSection), the file is closed through the CRT (MSVCCRTFileClose), the lock is released (AddressRangeCriticalSectionLeave), and the close result is returned. Callers are file loading, parsing and resource-release routines.
    // ASSIGNMENT: Initialize the return value v1 to -1 as the default. [source:raw]
    // GUARD: Guard on the flag bit 0x40 of the dword at this+0xC: when set, skip the close; otherwise take the locked-close path. [field:this:0x0000000C]
    // ASSIGNMENT: When the 0x40 flag is set, clear the dword at this+0xC to 0 and leave v1 at -1 (close skipped). [field:this:0x0000000C]
    // CALL: StreamBufferLockViaCriticalSection(a1) acquires the stream's critical section before closing. [callee:0x0058C1B1]
    // CALL: MSVCCRTFileClose(a1) performs the actual CRT file close and stores the result in v1. [callee:0x00587D33]
    // CALL: AddressRangeCriticalSectionLeave(a1) releases the stream critical section after the close. [callee:0x0058C203]
    // RETURN: Return v1: the CRT close result, or -1 when the close was skipped by the flag guard. [source:raw, function:0x00587D02]

    // Conservative worker pseudocode:
    //   int closeFileWithLock(int stream) {
    //     int result = -1;
    //     if ((*(byte*)(stream + 12) & 0x40) != 0) {
    //       *(dword*)(stream + 12) = 0;
    //     } else {
    //       StreamBufferLockViaCriticalSection(stream);
    //       result = MSVCCRTFileClose(stream);
    //       AddressRangeCriticalSectionLeave(stream);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the 0x40 flag bit at this+0xC (close-skip guard) is not established beyond this function's own behavior.
    // UNRESOLVED: Object owning the file stream at a1 is unknown; field this+0xC is only ever written on the skip path.
    // UNRESOLVED: The CRT close result v1 is produced only when the flag is clear.
}
