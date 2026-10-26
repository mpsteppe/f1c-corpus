// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B9F3
// Canonical corpus name: sub_59B9F3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B9F3_0059b9f3.c

void UnknownObject::RemoveDirectoryWithErrorHandling()
{
    // RemoveDirectoryA wrapper with error reporting. Calls RemoveDirectoryA(lpPathName); on success treats LastError as 0, otherwise captures GetLastError(). If the resulting error code is zero, returns 0 (success). Otherwise hands the error code to ErrorIDLookupTable (0058af5c) and returns -1 (failure).
    // CALL: Invoke RemoveDirectoryA(lpPathName) through its IAT thunk at 0x0059E210; a non-zero result marks success. [global:0x0059E210, source:raw]
    // GUARD: When RemoveDirectoryA returns non-zero, LastError is set to 0; otherwise LastError is captured from GetLastError(). [global:0x0059E210, global:0x0059E188, source:raw]
    // CALL: Invoke GetLastError() through its IAT thunk at 0x0059E188 to obtain the failure code after a failed removal. [global:0x0059E188, source:raw]
    // GUARD: When LastError is zero (success or no error captured), the function returns 0 early. [source:raw]
    // RETURN: Return 0 to signal successful removal. [source:raw]
    // CALL: Hand the error code to ErrorIDLookupTable (0058af5c) to report or translate the OS error. [callee:0x0058AF5C, source:raw]
    // RETURN: Return -1 to signal failed removal. [source:raw]
    // CALL: Invoked by sub_499690 (00499690). [caller:0x00499690, source:raw]

    // Conservative worker pseudocode:
    //   int sub_59B9F3(LPCSTR lpPathName) {
    //     DWORD LastError;
    //     if (RemoveDirectoryA(lpPathName))
    //       LastError = 0;
    //     else
    //       LastError = GetLastError();
    //     if (!LastError) return 0;
    //     ErrorIDLookupTable(LastError);
    //     return -1;
    //   }
    // UNRESOLVED: The behavior of ErrorIDLookupTable (0058af5c) beyond accepting the error code is not visible in this packet.
    // UNRESOLVED: The call-site intent of sub_499690 (00499690) for removing a directory is not resolved here.
}
