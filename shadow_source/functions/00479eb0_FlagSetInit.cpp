// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479EB0
// Canonical corpus name: FlagSetInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetInit_00479eb0.c

void UnknownObject::FlagSetInit()
{
    // Straight-line initializer: calls the no-op stub Return0Stub, sets the byte flag at this+0x100 to 1, and returns 0. No guards or branching.
    // CALL: Return0Stub invoked first; a stub with no observable side effect beyond the call itself. [callee:0x0047ABB0, source:raw]
    // ASSIGNMENT: Set the byte flag at this+0x100 (index 256) to 1, marking the flag active. [field:this:0x00000100, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int FlagSetInit(_BYTE *this) {
    //     Return0Stub();
    //     this[256] = 1;
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of the flag at this+0x100 and the identity of the object owning it are unknown; this is an unconditional one-time init with no context in the packet.
    // UNRESOLVED: Why Return0Stub is called before setting the flag is unknown; it is likely a retained compatibility stub.
}
