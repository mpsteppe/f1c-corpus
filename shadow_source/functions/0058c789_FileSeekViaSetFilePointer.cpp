// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C789
// Canonical corpus name: FileSeekViaSetFilePointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSeekViaSetFilePointer_0058c789.c

void UnknownObject::FileSeekViaSetFilePointer()
{
    // CRT file seek (lseek) via SetFilePointer: validates the CRT handle index, positions the OS handle with SetFilePointer, maps OS errors to CRT errno via ErrorIDLookupTable (writing errno=9 EBADF for an invalid handle), clears the EOF tracking bit (bit 1) on success, and returns the new file pointer.
    // CALL: Resolve the OS handle value for CRT handle index a1 via sub_595A1F(a1). [callee:0x00595A1F, source:raw]
    // GUARD: Guard: when the resolved handle is -1 (invalid), write errno 9 (EBADF) to the TLS slot via TLSOffsetGetter() and return -1. [callee:0x0058AFCF, source:raw]
    // CALL: Invoke SetFilePointer(handle, lDistanceToMove, 0, dwMoveMethod) and store the result as v4. [global:0x0059E168, source:raw]
    // ASSIGNMENT: Set LastError = GetLastError() when v4 is -1 (0xFFFFFFFF), otherwise LastError = 0. [global:0x0059E188, source:raw]
    // CALL: On LastError nonzero, map the OS error to CRT errno via ErrorIDLookupTable(LastError) and return -1. [callee:0x0058AF5C, source:raw]
    // ASSIGNMENT: On success, clear the EOF tracking bit: *(BYTE*)(dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4) &= ~2u. [global:0x008D4920, source:raw]
    // RETURN: Return the new file pointer v4 on success. [source:raw]
    // CALL: Called by sub_58C724, sub_58CA19, sub_58E290, sub_595AF9 and sub_59797B to position file handles during read/write/seek paths. [caller:0x0058C724, caller:0x0058CA19, caller:0x0058E290, caller:0x00595AF9, caller:0x0059797B, source:raw]

    // Conservative worker pseudocode:
    //   DWORD FileSeekViaSetFilePointer(int a1, LONG dist, DWORD method) {
    //     void* h = sub_595A1F(a1);
    //     if (h == (void*)-1) { *(DWORD*)TLSOffsetGetter() = 9; return -1; }
    //     DWORD p = SetFilePointer(h, dist, 0, method);
    //     DWORD err = (p == -1) ? GetLastError() : 0;
    //     if (err) { ErrorIDLookupTable(err); return -1; }
    //     *(BYTE*)(dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4) &= ~2u;
    //     return p;
    //   }
    // UNRESOLVED: Meaning of the block tracking array indexed by dword_8D4920[a1>>5] with 36-byte stride per handle slot is not proven here.
    // UNRESOLVED: Subsystem classification of the CRT handle-layer (file vs console) is not established from this function alone.
}
