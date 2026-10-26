// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589671
// Canonical corpus name: CreateDirectoryAWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CreateDirectoryAWrapper_00589671.c

void UnknownObject::CreateDirectoryAWrapper()
{
    // Thin wrapper around CreateDirectoryA: returns 0 on success, calls ErrorIDLookupTable and returns -1 when the directory creation fails.
    // CALL: Call CreateDirectoryA(lpPathName, 0) to create the directory. [global:0x0059E1EC, source:raw]
    // ASSIGNMENT: LastError = 0 when CreateDirectoryA returns nonzero (success). [source:raw]
    // CALL: On failure, LastError = GetLastError() to capture the OS error code. [global:0x0059E188, source:raw]
    // GUARD: if ( LastError == 0 ) then success path. [source:raw]
    // RETURN: return 0 on success. [source:raw]
    // CALL: On error, call ErrorIDLookupTable(LastError) with the captured error code. [callee:0x0058AF5C, source:raw]
    // RETURN: return -1 to signal failure to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   int CreateDirectoryAWrapper(LPCSTR lpPathName) {
    //     DWORD LastError;
    //     if ( CreateDirectoryA(lpPathName, 0) )
    //       LastError = 0;
    //     else
    //       LastError = GetLastError();
    //     if ( !LastError )
    //       return 0;
    //     ErrorIDLookupTable(LastError);
    //     return -1;
    //   }
    // UNRESOLVED: Purpose of the ErrorIDLookupTable call on the failure path is unknown (log, message, or abort).
    // UNRESOLVED: A wrapper that also returns -1 vs 0 on success suggests an internal boolean contract; exact caller expectation unknown.
}
