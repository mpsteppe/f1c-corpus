// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005898D3
// Canonical corpus name: MoveFileAWrapperWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MoveFileAWrapperWithErrorHandling_005898d3.c

void UnknownObject::MoveFileAWrapperWithErrorHandling()
{
    // Win32 MoveFileA wrapper that reports failures. Calls MoveFileA through the import; on success clears the error code, on failure captures GetLastError. When an error is present it is routed through ErrorIDLookupTable and the function returns -1; otherwise it returns 0.
    // GUARD: Call MoveFileA(lpExistingFileName, lpNewFileName) via the import at 0x0059E1D8; branch on its success result. [global:0x0059E1D8, source:raw]
    // ASSIGNMENT: On success set LastError = 0. [source:raw]
    // ASSIGNMENT: On failure capture LastError = GetLastError() via the import at 0x0059E188. [global:0x0059E188, source:raw]
    // GUARD: If LastError is zero, return 0 immediately. [function:0x005898D3, source:raw]
    // CALL: Report the captured error through ErrorIDLookupTable(LastError). [callee:0x0058AF5C, source:raw]
    // RETURN: Return -1 when an error was reported. [source:raw]

    // Conservative worker pseudocode:
    //   int MoveFileAWrapperWithErrorHandling(LPCSTR from, LPCSTR to) {
    //     DWORD LastError = MoveFileA(from, to) ? 0 : GetLastError();
    //     if (LastError == 0)
    //       return 0;
    //     ErrorIDLookupTable(LastError);
    //     return -1;
    //   }
    // UNRESOLVED: ErrorIDLookupTable side effects (message lookup vs. logging) are not evidenced in the packet.
}
