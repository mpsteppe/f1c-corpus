// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C724
// Canonical corpus name: sub_58C724
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C724_0058c724.c

void UnknownObject::FileSeekGuarded()
{
    // Protected file-position seek. Validates the file index a1 against the open-file count uNumber and checks the handle's open flag (bit 0 of the per-handle record at dword_8D4920). On success, enters the file critical section, performs the seek via FileSeekViaSetFilePointer, leaves the critical section, and returns the seek result. On failure, writes a TLS error code 9 and a TLS sub-field 0, then returns -1.
    // GUARD: Guard: file index a1 must be less than the open-file count uNumber (global 0x008D4A20). [global:0x008D4A20, source:raw]
    // GUARD: Guard: the handle's open flag (bit 0) at per-handle record dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4 must be set for the seek to proceed. [global:0x008D4920, source:raw]
    // CALL: Enter the file critical section for handle a1 via CriticalSectionEnterWithLazyInit. [callee:0x00595A61, source:raw]
    // CALL: Perform the seek: call FileSeekViaSetFilePointer(a1, lDistanceToMove, dwMoveMethod) and keep its return value. [callee:0x0058C789, source:raw]
    // CALL: Leave the file critical section for handle a1 via FileCriticalSectionLeave. [callee:0x00595AC0, source:raw]
    // RETURN: Return the seek result produced by FileSeekViaSetFilePointer. [source:raw]
    // ASSIGNMENT: Error path: store error code 9 into the TLS slot returned by TLSOffsetGetter. [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: Error path: store 0 into the second TLS slot returned by TLSOffsetGetter_afd8. [callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 to signal the failed seek on the error path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58C724(int handle, LONG distance, DWORD method) {
    //     if (handle < uNumber && (byteAt(recordTable[handle >> 5], 36 * (handle & 0x1F) + 4) & 1) != 0) {
    //       CriticalSectionEnterWithLazyInit(handle);
    //       int result = FileSeekViaSetFilePointer(handle, distance, method);
    //       FileCriticalSectionLeave(handle);
    //       return result;
    //     }
    //     *(DWORD*)TLSOffsetGetter() = 9;
    //     *(DWORD*)TLSOffsetGetter_afd8() = 0;
    //     return -1;
    //   }
    // UNRESOLVED: Meaning of TLS error code 9 (the error-code vocabulary is defined outside this function).
    // UNRESOLVED: Layout of the per-handle record beyond the open-flag byte at +4.
}
