// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BA1D
// Canonical corpus name: sub_59BA1D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59BA1D_0059ba1d.c

void UnknownObject::SetPerDriveCurrentDir()
{
    // Changes to the given path, then stores the resolved absolute directory as the per-drive current directory environment variable ("=X:") via SetEnvironmentVariableA. UNC paths are skipped (returns 0 without setting the variable). Any failure path reports the GetLastError code through ErrorIDLookupTable and returns -1.
    // CALL: Call SetCurrentDirectoryA(lpPathName) to change the working directory to the requested path. [global:0x0059E20C, source:raw]
    // GUARD: Short-circuit guard on SetCurrentDirectoryA; if it fails, fall through to the error path. [source:raw]
    // CALL: Call GetCurrentDirectoryA(0x105, Buffer) to read the resolved directory into Buffer (264 bytes). [global:0x0059E1B0, source:raw]
    // GUARD: Guard on GetCurrentDirectoryA; if either this call or SetCurrentDirectoryA failed, proceed to the error path. [source:raw]
    // GUARD: Guard on the resolved path being a UNC path: Buffer[0] is 92 ('\\') or 47 ('/') and Buffer[0] == Buffer[1]. [source:raw]
    // RETURN: Return 0 without touching environment variables when the resolved path is a UNC path. [source:raw]
    // CALL: Call sub_59C0AC(Buffer[0]) to uppercase the drive letter for the variable name. [callee:0x0059C0AC, source:raw]
    // ASSIGNMENT: Build the per-drive variable name '=X:' in the reused lpPathName buffer: LOBYTE = 61 ('='), BYTE1 = uppercased drive letter, HIWORD = 58 (':'). [source:raw]
    // CALL: Call SetEnvironmentVariableA((LPCSTR)&lpPathName, Buffer) to set the per-drive current directory variable to the resolved path. [global:0x0059E0B0, source:raw]
    // GUARD: Guard on the SetEnvironmentVariableA result; success returns 0, failure falls into the error path. [source:raw]
    // CALL: Call GetLastError() to capture the failure code. [global:0x0059E188, source:raw]
    // CALL: Call ErrorIDLookupTable(LastError) to raise an error for the failed operation. [callee:0x0058AF5C, source:raw]
    // RETURN: Return -1 on any failure path. [source:raw]
    // CALL: Called by sub_565F80 (0x00565F80). [caller:0x00565F80]

    // Conservative worker pseudocode:
    //   int sub_59BA1D(LPCSTR lpPathName) {
    //     CHAR Buffer[264];
    //     if (SetCurrentDirectoryA(lpPathName) && GetCurrentDirectoryA(0x105, Buffer)) {
    //       if ((Buffer[0] == 92 || Buffer[0] == 47) && Buffer[0] == Buffer[1])
    //         return 0;
    //       LOBYTE(lpPathName) = 61;
    //       BYTE1(lpPathName) = sub_59C0AC(Buffer[0]);
    //       HIWORD(lpPathName) = 58;
    //       if (SetEnvironmentVariableA((LPCSTR)&lpPathName, Buffer))
    //         return 0;
    //     }
    //     ErrorIDLookupTable(GetLastError());
    //     return -1;
    //   }
    // UNRESOLVED: Semantics of sub_59C0AC are only inferred from usage as drive-letter uppercasing; its true contract is unknown.
    // UNRESOLVED: Caller context of sub_565F80 (0x00565F80) is not available in this packet.
}
