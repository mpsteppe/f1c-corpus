// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A2CB
// Canonical corpus name: ErrorHandlerWithOptionalCleanupThenExit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ErrorHandlerWithOptionalCleanupThenExit_0058a2cb.c

void UnknownObject::ErrorHandlerWithOptionalCleanupThenExit()
{
    // Fatal error handler. When the error-display flag dword_8D3EBC equals 1, first displays an error message via sub_5932BA; then always runs cleanup via sub_5932F3(NumberOfBytesWritten) and terminates the process with exit code 0xFF via ExitProcess. __noreturn: control never reaches the caller. Called from sub_58A19E.
    // GUARD: Test error-display flag dword_8D3EBC; if it equals 1 the error message is shown, otherwise the message step is skipped. [global:0x008D3EBC, source:raw]
    // CALL: Call sub_5932BA to display the error message to the user when the flag is set. [callee:0x005932BA, source:raw]
    // CALL: Call sub_5932F3(NumberOfBytesWritten) to perform cleanup operations before termination. [callee:0x005932F3, source:raw]
    // CALL: Call ExitProcess with exit code 0xFF to terminate the process; the function does not return. [global:0x0059E1D4, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3EBC == 1) sub_5932BA();
    //   sub_5932F3(NumberOfBytesWritten);
    //   ExitProcess(0xFF);  // noreturn
    // UNRESOLVED: Meaning and writers of the error-display flag dword_8D3EBC (which error paths set it to 1) are not visible in this packet.
    // UNRESOLVED: What sub_5932BA displays and what cleanup sub_5932F3 performs is beyond this function's raw source; both are only referenced by call.
}
