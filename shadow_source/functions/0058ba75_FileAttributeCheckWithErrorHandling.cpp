// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BA75
// Canonical corpus name: FileAttributeCheckWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileAttributeCheckWithErrorHandling_0058ba75.c

void UnknownObject::FileAttributeCheckWithErrorHandling()
{
    // File-attribute check with error handling (__cdecl; lpFileName, flag byte a2). Calls GetFileAttributesA; if it returns INVALID_FILE_ATTRIBUTES (-1), retrieves the last error via GetLastError, maps it through ErrorIDLookupTable, and returns -1. If the file is read-only (attribute bit 0 set) and the caller's reject flag bit is set (a2 & 2), stores error codes 13 and 5 through the two TLS getters and returns -1. Otherwise returns 0 (the file is acceptable).
    // CALL: Call GetFileAttributesA(lpFileName) to retrieve the file's attribute flags. [global:0x0059E0D8, source:raw]
    // GUARD: If the attributes equal -1 (INVALID_FILE_ATTRIBUTES), the file was not found. [source:raw, function:0x0058BA75]
    // CALL: On the not-found path, capture the error with GetLastError and map it through ErrorIDLookupTable. [global:0x0059E188, callee:0x0058AF5C, source:raw]
    // RETURN: Return -1 on the not-found path after the error lookup. [source:raw, function:0x0058BA75]
    // GUARD: If the read-only attribute bit (attr & 1) is set and the caller's reject flag bit is set (a2 & 2), reject the file. [source:raw, function:0x0058BA75]
    // ASSIGNMENT: On the read-only rejection path, store error code 13 through TLSOffsetGetter and error code 5 through TLSOffsetGetter_afd8. [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 for the read-only rejection path, and 0 (success) otherwise. [source:raw, function:0x0058BA75]
    // CALL: Called by ConfigIniParser (0x00421CD0) and FileAttributeCheckSequence (0x005668F0) to validate a file before further processing. [caller:0x00421CD0, caller:0x005668F0, source:raw]

    // Conservative worker pseudocode:
    //   int FileAttributeCheckWithErrorHandling(LPCSTR lpFileName, char flags) {
    //     DWORD attrs = GetFileAttributesA(lpFileName);
    //     if (attrs == (DWORD)-1) {
    //       ErrorIDLookupTable(GetLastError());
    //       return -1;
    //     }
    //     if ((attrs & 1) && (flags & 2)) {
    //       *TLSOffsetGetter() = 13;
    //       *TLSOffsetGetter_afd8() = 5;
    //       return -1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of error codes 13 and 5 (read-only rejection) is taken from the caller context in existing analysis; not confirmed by this packet.
    // UNRESOLVED: The semantics of ErrorIDLookupTable's mapping and any side effects beyond the lookup are unknown.
    // UNRESOLVED: The full meaning of the a2 flag bits beyond bit 1 (reject read-only) is not established.
}
