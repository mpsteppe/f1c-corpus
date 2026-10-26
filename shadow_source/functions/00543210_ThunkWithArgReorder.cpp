// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543210
// Canonical corpus name: ThunkWithArgReorder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkWithArgReorder_00543210.c

void UnknownObject::ThunkWithArgReorder()
{
    // __thiscall thunk that forwards to VTableDispatchByFlags with the global dispatch context dword_8B78A0 as the first argument, the this pointer second, and the two incoming arguments reordered (a3 before a2). Returns the callee's result unchanged. Used by Bink-video and rendering callers as a fixed argument-reordering dispatch shim.
    // CALL: Reads the global dispatch context dword_8B78A0 (0x008B78A0) to pass as the first argument to the dispatch call. [global:0x008B78A0, source:raw]
    // CALL: Calls VTableDispatchByFlags (0x005400C0) with dword_8B78A0, this, a3 and a2, forwarding the arguments in that order. [callee:0x005400C0, source:raw]
    // RETURN: Returns the result of VTableDispatchByFlags directly without modification. [function:0x00543210, source:raw]
    // CALL: Used by BinkVideoFrameRender, BinkVideoFrameDecoder, sub_551FD0, sub_552BA0, sub_552D70 and sub_553AA0 as an argument-reordering dispatch shim. [caller:0x00551CF0, caller:0x00551DD0, caller:0x00551FD0, caller:0x00552BA0, caller:0x00552D70, caller:0x00553AA0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_543210(void *this, int a2, int a3) {
    //     return VTableDispatchByFlags(dword_8B78A0, this, a3, a2);
    //   }
    // UNRESOLVED: Why the two incoming arguments are swapped before the call is unknown; the semantic meaning of a2 and a3 is not established from this packet
    // UNRESOLVED: dword_8B78A0 is read but never otherwise interpreted here; its role as a dispatch context is not verifiable from this packet
}
