// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC2D0
// Canonical corpus name: SingleCallWrapper_c2d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleCallWrapper_c2d0_004dc2d0.c

void UnknownObject::SingleCallWrapperC2d0()
{
    // One-call forwarding wrapper: passes the global dword_8AD3B4 as the single argument to StructZeroInit_7a00 and returns its result unchanged. No branches, no other reads or writes.
    // CALL: Read global dword_8AD3B4 at 0x008AD3B4 and pass its value as the argument to StructZeroInit_7a00. [source:raw, global:0x008AD3B4]
    // RETURN: Return the pointer result of StructZeroInit_7a00 unchanged to the caller. [source:raw, function:0x004DC2D0, abi:lead]

    // Conservative worker pseudocode:
    //   _DWORD *SingleCallWrapperC2d0() {
    //     return StructZeroInit_7a00(dword_8AD3B4);
    //   }
    // UNRESOLVED: The identity and semantics of callee StructZeroInit_7a00 are out of scope for this packet; its effect on dword_8AD3B4 is unknown.
    // UNRESOLVED: Meaning of the dword_8AD3B4 global and which subsystem owns it is not recoverable here.
}
