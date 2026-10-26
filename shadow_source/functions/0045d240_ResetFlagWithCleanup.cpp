// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D240
// Canonical corpus name: BooleanFlagResetWithSideEffects
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BooleanFlagResetWithSideEffects_0045d240.c

void UnknownObject::ResetFlagWithCleanup()
{
    // Conditional cleanup on a single-byte flag: if the byte at this+0 is nonzero, calls SingleFunctionCallWrapper_1f60(0) and SocketCloseAndCleanup(0), then clears the flag to 0. Always returns 1. Flag-controlled side-effect reset.
    // GUARD: Guard on the byte at this+0: the cleanup block runs only when it is nonzero. [field:this:0x00000000, source:raw]
    // CALL: Call SingleFunctionCallWrapper_1f60(0). [callee:0x00561F60, source:raw]
    // CALL: Call SocketCloseAndCleanup(0). [callee:0x00561F80, source:raw]
    // ASSIGNMENT: Clear the flag byte at this+0 to 0 after cleanup. [field:this:0x00000000, source:raw]
    // RETURN: Return constant 1 unconditionally. [source:raw, function:0x0045D240]

    // Conservative worker pseudocode:
    //   char __thiscall sub_45D240(_BYTE* this) {
    //     if (*this) {
    //       SingleFunctionCallWrapper_1f60(0);
    //       SocketCloseAndCleanup(0);
    //       *this = 0;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The single-byte object at this+0 is unnamed; what the flag represents is unknown.
    // UNRESOLVED: The two cleanup callees are wrappers whose underlying resource (a socket or connection) is not established from this packet.
    // UNRESOLVED: Structural-twin prelabel (cluster_copy from ObjectAllocator 0045bb90) is DERIVED and not independently verified.
}
