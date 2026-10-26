// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00520C00
// Canonical corpus name: sub_520C00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_520C00_00520c00.c

void UnknownObject::Thunk520C00()
{
    // Two-argument stdcall trampoline whose only body is an unconditional tail jump (JUMPOUT) to 0x520C11. No local computation is visible in the raw source; the two arguments are passed through to the target unchanged.
    // CALL: Unconditional tail jump (JUMPOUT) from the function header to 0x520C11, transferring control with no additional stack frame; arguments a1, a2 are forwarded as-is. [function:0x00520C00, source:raw]

    // Conservative worker pseudocode:
    //   void __stdcall sub_520C00(int a1, int a2) {
    //     /* unconditional tail jump to 0x520C11; args forwarded * /
    //   }
    // UNRESOLVED: Target 0x520C11 falls outside this function; its body and the meaning of a1/a2 are not visible in the packet.
    // UNRESOLVED: Whether this is a shared code thunk, an inlined-gap stub, or a linker-merged alias is unproven.
    // UNRESOLVED: No callers, callees, fields or globals are recorded in the packet to anchor ownership.
}
