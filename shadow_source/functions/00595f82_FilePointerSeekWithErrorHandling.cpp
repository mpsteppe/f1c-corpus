// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595F82
// Canonical corpus name: FilePointerSeekWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilePointerSeekWithErrorHandling_00595f82.c

void UnknownObject::FilePointerSeekWithErrorHandling()
{
    // Wraps a file seek on a handle resolved from index a1 via sub_595A1F. On handle failure stores the error code 9 through TLSOffsetGetter and returns -1. Performs a 64-bit SetFilePointer seek: high 32 bits passed as a3, low 32 bits assigned from the return value. If the low 32 bits are -1 and GetLastError() is non-zero, routes the error through ErrorIDLookupTable and returns -1. On success clears bit 2 of the file-handle-table flag byte at dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4, then returns the full 64-bit position.
    // CALL: Resolves the file handle for index a1 by calling sub_595A1F [callee:0x00595A1F, source:raw]
    // GUARD: If the resolved handle equals -1 (invalid), stores error code 9 through TLSOffsetGetter and returns -1 [callee:0x0058AFCF, function:0x00595F82, source:raw]
    // CALL: Calls SetFilePointer with the handle, low 32 bits of the offset (a2), the high 32 bits at &lDistanceToMove+1 (a3), and the move method; assigns the returned low 32 bits into lDistanceToMove [global:0x0059E168, source:raw]
    // GUARD: If the low 32 bits of the result equal -1 and GetLastError() is non-zero, passes the error to ErrorIDLookupTable and returns -1 [global:0x0059E188, callee:0x0058AF5C, source:raw]
    // ASSIGNMENT: Clears bit 2 of the flag byte at dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4 (the file-handle-table entry for a1) [global:0x008D4920, source:raw]
    // RETURN: Returns the 64-bit seek result [function:0x00595F82, source:raw]
    // STATE_TRANSITION: Invoked by sub_595F11 as the error-checked file-positioning path [caller:0x00595F11, source:raw]

    // Conservative worker pseudocode:
    //   handle = sub_595A1F(a1);
    //   if (handle == -1) {
    //     *(DWORD*)TLSOffsetGetter() = 9;
    //     return -1;
    //   }
    //   HIDWORD(lDistanceToMove) = a3;
    //   LODWORD(lDistanceToMove) = SetFilePointer(handle, a2, (PLONG)&lDistanceToMove + 1, dwMoveMethod);
    //   if (LODWORD(lDistanceToMove) == -1) {
    //     lastError = GetLastError();
    //     if (lastError != 0) { ErrorIDLookupTable(lastError); return -1; }
    //   }
    //   *(BYTE*)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) &= ~2;
    //   return lDistanceToMove;
    // UNRESOLVED: The handle table dword_8D4920 entry layout (36-byte stride, flag byte at +4) is only partially evidenced; the meaning of bit 2 is defined outside this packet
    // UNRESOLVED: The meaning of the TLS error code 9 is defined by its consumer, outside this packet
    // UNRESOLVED: sub_595A1F's handle-resolution semantics are outside this packet
}
