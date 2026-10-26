// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BA36
// Canonical corpus name: ToggleFileReadOnlyAttributeViaWin32API
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ToggleFileReadOnlyAttributeViaWin32API_0058ba36.c

void UnknownObject::ToggleFileReadOnlyAttributeViaWin32API()
{
    // Toggles the read-only attribute (bit 0) of a file through the Win32 file API. Reads the current attributes with GetFileAttributesA; if the read fails (-1) it falls through to the error path. Otherwise it sets the read-only bit when a2 is non-negative (OR 1) and clears it when a2 is negative (AND 0xFE), applies the change with SetFileAttributesA and returns 0 on success. On any failure it records the Win32 error via GetLastError plus ErrorIDLookupTable and returns -1.
    // CALL: Call GetFileAttributesA(lpFileName) to read the current file attributes; returns -1 on failure. [global:0x0059E0D8, source:raw]
    // GUARD: If the returned attributes equal -1 (INVALID_FILE_ATTRIBUTES), skip the toggle and fall through to the error path. [source:raw]
    // CALCULATION: Toggle the read-only bit (bit 0): if a2 >= 0 set it (attrs | 1), otherwise clear it (attrs & 0xFE). [source:raw]
    // CALL: Call SetFileAttributesA(lpFileName, attrs) to apply the modified attributes. [global:0x0059E17C, source:raw]
    // RETURN: If SetFileAttributesA returns nonzero, return 0 (success). [source:raw]
    // CALL: Call GetLastError() to capture the failure code from the failed Win32 call. [global:0x0059E188, source:raw]
    // CALL: Call ErrorIDLookupTable(GetLastError()) to map the Win32 error code to an internal error ID and log it. [callee:0x0058AF5C, source:raw]
    // RETURN: Return -1 on any failure path. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD attrs = GetFileAttributesA(lpFileName);
    //   if (attrs != -1) {
    //       attrs = (a2 >= 0) ? (attrs | 1) : (attrs & 0xFE);
    //       if (SetFileAttributesA(lpFileName, attrs)) return 0;
    //   }
    //   ErrorIDLookupTable(GetLastError());
    //   return -1;
    // UNRESOLVED: Semantic meaning of the a2 flag across callers is not established: the raw source only dictates the bit-0 decision (non-negative sets, negative clears read-only).
    // UNRESOLVED: The ABI lead carries LEGACY trust and is consistent with the raw source, so no conflict is recorded.
}
