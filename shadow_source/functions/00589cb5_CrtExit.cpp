// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589CB5
// Canonical corpus name: sub_589CB5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589CB5_00589cb5.c

void UnknownObject::CrtExit()
{
    // CRT exit-path entry point (ABI label CRT___exit). Takes a UINT exit code and delegates to sub_589CC6(uExitCode, 1, 0), passing two fixed arguments alongside the exit code, then returns that call's result. Callers are SEH dispatch/guarded-call wrappers and other CRT helpers, consistent with a process/exit termination helper.
    // CALL: Forward uExitCode into the deeper termination routine sub_589CC6(uExitCode, 1, 0); the fixed trailing arguments 1 and 0 are not explained by the packet. [source:raw, callee:0x00589CC6]
    // RETURN: Return the delegated call's result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_589CB5(UINT uExitCode) {
    //     return sub_589CC6(uExitCode, 1, 0);
    //   }
    // UNRESOLVED: Meaning of the two fixed arguments (1 and 0) passed to sub_589CC6 is not established by the packet; they likely select termination mode and a flag.
    // UNRESOLVED: sub_589CC6 is outside this packet, so the final OS termination call (e.g. ExitProcess) is not evidenced here.
    // UNRESOLVED: Whether this is the C exit() path or the _exit()/_Exit() path is not resolvable from the packet alone.
}
