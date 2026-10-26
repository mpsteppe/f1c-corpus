// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058986E
// Canonical corpus name: FileDeleteWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileDeleteWithErrorHandling_0058986e.c

void UnknownObject::FileDeleteWithErrorHandling()
{
    // Deletes a file and normalizes the result into a simple success/failure code. Calls DeleteFileA(lpFileName); on success the local error code is set to 0, otherwise it is set to GetLastError(). If the resulting code is zero the function returns 0 (success). Otherwise the failure code is passed to ErrorIDLookupTable(LastError) (an error-code to message/lookup handler) and the function returns -1. A thin Win32 wrapper used by six callers including vehicle scene/tire loading, setting-existence checks and physics joint loading paths.
    // CALL: DeleteFileA(lpFileName) attempts to delete the named file via the Win32 DeleteFileA import. [global:0x0059E1DC, source:raw]
    // GUARD: If DeleteFileA returned non-zero the deletion succeeded and LastError is set to 0; otherwise LastError is set to GetLastError() to capture the failure code. [global:0x0059E188, global:0x0059E1DC, source:raw]
    // GUARD: If LastError is zero the function returns 0 immediately, signalling success. [source:raw]
    // CALL: ErrorIDLookupTable(LastError) consumes the non-zero failure code (error-code to message lookup/handler). [callee:0x0058AF5C]
    // RETURN: Return -1 to signal that the deletion failed. [source:raw]

    // Conservative worker pseudocode:
    //   int FileDeleteWithErrorHandling(const char *lpFileName) {
    //     DWORD LastError = DeleteFileA(lpFileName) ? 0 : GetLastError();
    //     if (!LastError)
    //       return 0;
    //     ErrorIDLookupTable(LastError);
    //     return -1;
    //   }
    // UNRESOLVED: The behavior of ErrorIDLookupTable is not evidenced by this packet; whether it logs, shows an error dialog, or maps the code into a user-visible message is unknown.
    // UNRESOLVED: The success/failure convention (0 on success, -1 on failure) is stated by the raw source but the meaning callers attach to it is not evidenced here.
    // UNRESOLVED: The GetLastError import's read is the only use of the 0x0059E188 global in this function; its runtime state is not captured by the packet.
}
