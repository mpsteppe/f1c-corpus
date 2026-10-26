// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C38E
// Canonical corpus name: HandleCloseWithErrorReporting
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HandleCloseWithErrorReporting_0058c38e.c

void UnknownObject::HandleCloseWithErrorReporting()
{
    // CRT handle-close helper: resolves the OS handle for CRT index a1, skips CloseHandle for the shared stdout/stderr pair (indices 1 and 2 when they map to the same OS handle) and for invalid handles, clears the handle open-state byte in the block tracking array, and maps a CloseHandle failure to CRT errno via ErrorIDLookupTable, returning 0 on success or -1 on failure.
    // CALL: Resolve the OS handle value for CRT handle index a1 via sub_595A1F(a1). [callee:0x00595A1F, source:raw]
    // GUARD: Guard: when sub_595A1F(a1) returns -1 (invalid handle), skip CloseHandle and treat the close as success. [callee:0x00595A1F, source:raw]
    // GUARD: Guard: when a1 is 1 or 2 (stdout/stderr) and sub_595A1F(2) equals sub_595A1F(1) (shared console handle), skip CloseHandle to avoid closing shared console output. [callee:0x00595A1F, source:raw]
    // CALL: Invoke CloseHandle on the resolved OS handle; a success returns nonzero, so the error path is taken only when CloseHandle fails. [global:0x0059E1A8, source:raw]
    // ASSIGNMENT: Set LastError = 0 when the handle was skipped or CloseHandle succeeded, otherwise LastError = GetLastError(). [global:0x0059E188, source:raw]
    // CALL: Invoke sub_5959A0(a1) to clean up the handle entry metadata after the close. [callee:0x005959A0, source:raw]
    // ASSIGNMENT: Clear the open-state byte for the handle: *(BYTE*)(dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4) = 0. [global:0x008D4920, source:raw]
    // RETURN: Return 0 when LastError is 0. [source:raw]
    // CALL: On LastError nonzero, map the OS error to CRT errno via ErrorIDLookupTable(LastError) and return -1. [callee:0x0058AF5C, source:raw]
    // CALL: Called by sub_58C331 (0x0058C331) on the frame path to close a handle with errno mapping. [caller:0x0058C331, source:raw]

    // Conservative worker pseudocode:
    //   int HandleCloseWithErrorReporting(int a1) {
    //     int err = 0;
    //     if (sub_595A1F(a1) == -1) { /* skip * / }
    //     else if ((a1 == 1 || a1 == 2) && sub_595A1F(2) == sub_595A1F(1)) { /* shared console, skip * / }
    //     else if (!CloseHandle(sub_595A1F(a1))) err = GetLastError();
    //     sub_5959A0(a1);
    //     *(BYTE*)(dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4) = 0;
    //     if (err) { ErrorIDLookupTable(err); return -1; }
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the block tracking array indexed by dword_8D4920[a1>>5] with 36-byte stride per handle slot is not proven here.
}
