// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411740
// Canonical corpus name: GlobalVTableDispatchWithQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalVTableDispatchWithQuery_00411740.c

void UnknownObject::GlobalVTableDispatchWithQuery()
{
    // Audio-commentary channel dispatch: when the global object pointer dword_8AC4C4 is non-null, initializes four query outputs (-1, -1, 0, 0) and calls AudioCommentaryChannelConfiguration to resolve two channel identifiers. If the query returns zero, dispatches the same vtable slot at offset 76 twice on that object, once per resolved channel.
    // GUARD: Guard on the global object pointer dword_8AC4C4; the whole dispatch body runs only while it is non-zero. [source:raw, global:0x008AC4C4]
    // ASSIGNMENT: Initialize four by-reference query outputs before the call: v2=-1, v3=-1, v5=0, v4=0. [source:raw]
    // CALL: Call AudioCommentaryChannelConfiguration(a1, &v2, &v3, &v5, &v4), passing the caller argument a1 and the four initialized outputs. [source:raw, callee:0x004117B0]
    // GUARD: Guard: only when AudioCommentaryChannelConfiguration returns zero (not handled) are the two vtable dispatches performed. [source:raw]
    // CALL: First __thiscall vtable dispatch on v1: call the slot at offset 76 with argument v2. [source:raw]
    // CALL: Second __thiscall vtable dispatch on v1: call the slot at offset 76 with argument v3. [source:raw]

    // Conservative worker pseudocode:
    //   void GlobalVTableDispatchWithQuery(int a1) {
    //     int v1 = dword_8AC4C4;
    //     if (v1) {
    //       int v2 = -1, v3 = -1, v5 = 0, v4 = 0;
    //       if (!AudioCommentaryChannelConfiguration(a1, &v2, &v3, &v5, &v4)) {
    //         (*(void (__thiscall **)(int, int))(*(_DWORD*)v1 + 76))(v1, v2);
    //         (*(void (__thiscall **)(int, int))(*(_DWORD*)v1 + 76))(v1, v3);
    //       }
    //     }
    //   }
    // UNRESOLVED: Semantics of the two query outputs v5 and v4 (used only to satisfy the call signature) are unknown.
    // UNRESOLVED: Purpose of the repeated vtable slot at offset 76 and why it is invoked once per channel (v2, v3) is unresolved.
    // UNRESOLVED: Meaning of dword_8AC4C4 (global object owner) and the caller argument a1 is unknown; both callers are sound/exit paths.
}
