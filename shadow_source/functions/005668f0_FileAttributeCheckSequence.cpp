// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005668F0
// Canonical corpus name: FileAttributeCheckSequence
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileAttributeCheckSequence_005668f0.c

void UnknownObject::FileAttributeCheckSequence()
{
    // File attribute check-and-fix sequence for a given file name. Starts with result = 1 (success). If the attribute check with flag 0 does not return -1, and the check with flag 6 reports the attribute present, the file's read-only attribute is toggled via the Win32 API with value 128, and a recheck with flag 6 decides the outcome: if the attribute is still present the function returns 0 (failure), otherwise the initial success value is returned.
    // ASSIGNMENT: Initialize result to 1 before any check runs. [source:raw]
    // GUARD: Guard on FileAttributeCheckWithErrorHandling(lpFileName, 0) != -1; when it equals -1 the rest of the sequence is skipped and result remains 1. [source:raw, callee:0x0058BA75]
    // CALL: Call FileAttributeCheckWithErrorHandling(lpFileName, 6); a non-zero (true) result proceeds to the toggle step. [source:raw, callee:0x0058BA75]
    // CALL: Call ToggleFileReadOnlyAttributeViaWin32API(lpFileName, 128) to flip the read-only attribute state. [source:raw, callee:0x0058BA36]
    // GUARD: Recheck FileAttributeCheckWithErrorHandling(lpFileName, 6); if it is still true the function returns 0 immediately. [source:raw, callee:0x0058BA75]
    // RETURN: Return the preserved result (1 on the normal path, 0 on the failed-toggle path). [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_5668F0(LPCSTR lpFileName) {
    //     bool result = 1;
    //     if (FileAttributeCheckWithErrorHandling(lpFileName, 0) != -1) {
    //       if (FileAttributeCheckWithErrorHandling(lpFileName, 6)) {
    //         ToggleFileReadOnlyAttributeViaWin32API(lpFileName, 128);
    //         if (FileAttributeCheckWithErrorHandling(lpFileName, 6))
    //           return 0;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact meaning of the attribute-check flag values 0 and 6 and of the value 128 passed to the toggle helper is not established from this packet.
    // UNRESOLVED: The callers sub_566940 and sub_566A70 determine when this attribute repair sequence is invoked.
}
