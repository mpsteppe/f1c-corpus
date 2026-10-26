// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589CC6
// Canonical corpus name: sub_589CC6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589CC6_00589cc6.c

void UnknownObject::CRTProcessExitHandler()
{
    // CRT process-exit/termination handler. Runs a pre-exit cleanup (sub_589D6B), then when the terminate-on-exit flag dword_8D3EB0 equals 1 force-terminates via TerminateProcess. Records the exit state (dword_8D3EAC = 1, byte_8D3EA8 = a3), and when a2 is zero runs the registered atexit function stack (top dword_8D5A50 down to bottom dword_8D5A54) plus a terminate-data-range cleanup via UtilityFunction_9d7d. An unconditional second UtilityFunction_9d7d pass covers the terminate-handler data range. When a3 is zero, marks dword_8D3EB0 = 1 and exits via ExitProcess. Returns CriticalSectionLeave().
    // CALL: Run the pre-exit cleanup routine sub_589D6B before any exit decision. [callee:0x00589D6B, source:raw]
    // GUARD: When the terminate-on-exit flag dword_8D3EB0 equals 1, hard-terminate the process. [global:0x008D3EB0, source:raw]
    // CALL: Obtain the current process handle via GetCurrentProcess. [global:0x0059E18C, source:raw]
    // CALL: Force-terminate the process with TerminateProcess(handle, uExitCode). [global:0x0059E1D0, source:raw]
    // ASSIGNMENT: Record that the application is exiting: dword_8D3EAC = 1. [global:0x008D3EAC, source:raw]
    // ASSIGNMENT: Store the gate flag a3 into byte_8D3EA8. [global:0x008D3EA8, source:raw]
    // GUARD: When a2 is zero, run the registered exit handlers (atexit stack and terminate-data cleanup); otherwise skip that block. [source:raw]
    // GUARD: Guard the atexit stack walk: proceed only when dword_8D5A54 (stack bottom) is non-null and the stack top (dword_8D5A50 - 4) is at or above it. [global:0x008D5A54, global:0x008D5A50, source:raw]
    // LOOP: Walk the registered exit-function stack from the top dword_8D5A50 down to the bottom dword_8D5A54, calling each non-null function pointer. [global:0x008D5A50, global:0x008D5A54, source:raw]
    // CALL: Clean up the terminate data range [unk_5BE3DC, unk_5BE3E4) via UtilityFunction_9d7d. [callee:0x00589D7D, global:0x005BE3DC, global:0x005BE3E4, source:raw]
    // CALL: Clean up the terminate-handler data range [unk_5BE3E8, unk_5BE3F0) via UtilityFunction_9d7d (unconditional). [callee:0x00589D7D, global:0x005BE3E8, global:0x005BE3F0, source:raw]
    // GUARD: When the gate flag a3 is zero, mark terminate-on-exit (dword_8D3EB0 = 1) and exit normally. [global:0x008D3EB0, source:raw]
    // CALL: Exit the process with ExitProcess(uExitCode). [global:0x0059E1D4, source:raw]
    // RETURN: Release the exit critical section via CriticalSectionLeave() and return its result. [callee:0x00589D74, source:raw]
    // CALL: Invoked by UtilityFunction_9ca4 and sub_589CB5 as the CRT process-exit handler. [caller:0x00589CA4, caller:0x00589CB5, source:raw]

    // Conservative worker pseudocode:
    //   int sub_589CC6(UINT exitCode, int skipCleanup, int gateFlag) {
    //     sub_589D6B();
    //     if (dword_8D3EB0 == 1) TerminateProcess(GetCurrentProcess(), exitCode);
    //     dword_8D3EAC = 1;
    //     byte_8D3EA8 = gateFlag;
    //     if (!skipCleanup) {
    //       if (dword_8D5A54) {
    //         void (**fn)(void) = (void (**)(void))(dword_8D5A50 - 4);
    //         if ((unsigned)dword_8D5A50 - 4 >= (unsigned)dword_8D5A54) {
    //           do {
    //             if (*fn) (*fn)();
    //             --fn;
    //           } while ((unsigned)fn >= (unsigned)dword_8D5A54);
    //         }
    //       }
    //       UtilityFunction_9d7d(&unk_5BE3DC, &unk_5BE3E4);
    //     }
    //     UtilityFunction_9d7d(&unk_5BE3E8, &unk_5BE3F0);
    //     if (!gateFlag) {
    //       dword_8D3EB0 = 1;
    //       ExitProcess(exitCode);
    //     }
    //     return CriticalSectionLeave();
    //   }
    // UNRESOLVED: The exact semantics of a2 and a3: a2 gates the atexit/terminate-data cleanup block; a3 gates byte_8D3EA8 and the ExitProcess path. Their caller-level meaning is not established.
    // UNRESOLVED: UtilityFunction_9d7d's cleanup behavior over the two data ranges is not established by this packet.
    // UNRESOLVED: dword_8D3EB0 is read as the hard-terminate gate and later written to 1 on the normal-exit path; the two states are only partially characterized.
    // UNRESOLVED: The registered-exit-function stack layout (top dword_8D5A50, bottom dword_8D5A54) is inferred from the pointer-walk arithmetic.
}
