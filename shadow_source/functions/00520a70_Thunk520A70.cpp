// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00520A70
// Canonical corpus name: sub_520A70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_520A70_00520a70.c

void UnknownObject::Thunk520A70()
{
    // Three-argument stdcall trampoline whose only body is an unconditional tail jump (JUMPOUT) to 0x520A81. No local computation is visible in the raw source; the three arguments are passed through to the target unchanged.
    // CALL: Unconditional tail jump (JUMPOUT) from the function header to 0x520A81, transferring control with no additional stack frame; arguments a1, a2, a3 are forwarded as-is. [function:0x00520A70, source:raw]

    // Conservative worker pseudocode:
    //   void __stdcall sub_520A70(int a1, int a2, int a3) {
    //     /* unconditional tail jump to 0x520A81; args forwarded * /
    //   }
    // UNRESOLVED: Target 0x520A81 falls outside this function; its body and the meaning of a1/a2/a3 are not visible in the packet.
    // UNRESOLVED: Whether this is a shared code thunk, an inlined-gap stub, or a linker-merged alias is unproven.
    // UNRESOLVED: No callers, callees, fields or globals are recorded in the packet to anchor ownership.
}
