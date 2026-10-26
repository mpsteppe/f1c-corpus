// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F000
// Canonical corpus name: OnScreen_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OnScreen_Restart_0049f000.c

void UnknownObject::OnScreen_Restart()
{
    // On-screen restart handler invoked from Game_Restart. Conditionally writes an assertion/debug message, performs two resource-dispatch computations, writes session-complete state through a wrapper, resets two owner fields (active flag to 1, boolean state to 0), then walks a 25-entry dispatch table clearing non-null entries via VTableDispatchWithFieldClear. Returns the last dispatch result.
    // GUARD: If StringSplitLoop(2, aDDevF119992002_16, 2635) returns non-zero, the assertion log branch is taken. [callee:0x004D7A50, global:0x005CCF10, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredOnscree_2) writes the entered-OnScreen debug message when the assertion gate passes. [callee:0x004D7AA0, global:0x008AD25C, global:0x005CCF70, source:raw]
    // CALL: ShortComputation_bdf0(&dword_7CD204) performs the first resource-dispatch computation. [callee:0x0045BDF0, global:0x007CD204, source:raw]
    // CALL: FunctionCallWrapper_f150(0) writes the session-init-complete flag and stores its argument. [callee:0x0049F150, source:raw]
    // ASSIGNMENT: Set this+4 (active/visible flag) to 1. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clear this+8 (boolean state) to 0. [field:this:0x00000008, source:raw]
    // CALL: ShortComputation_bdf0(&dword_7CD204) runs the second resource-dispatch computation and its return value seeds result. [callee:0x0045BDF0, global:0x007CD204, source:raw]
    // LOOP: do-while over 25 entries starting at the table base; for each non-null entry call VTableDispatchWithFieldClear and keep the last returned value. [source:raw]
    // RETURN: Return result, the last VTableDispatchWithFieldClear return value. [source:raw]

    // Conservative worker pseudocode:
    //   int OnScreen_Restart(int this) {
    //     int result;
    //     if (StringSplitLoop(2, aDDevF119992002_16, 2635) != 0)
    //       DebugLogWrite(&dword_8AD25C, aEnteredOnscree_2);
    //     ShortComputation_bdf0(&dword_7CD204);
    //     FunctionCallWrapper_f150(0);
    //     *(int*)(this + 4) = 1;
    //     *(char*)(this + 8) = 0;
    //     result = ShortComputation_bdf0(&dword_7CD204);
    //     int* v3 = &unk_8AD2A8;
    //     int v4 = 25;
    //     do { if (*v3) result = VTableDispatchWithFieldClear(); ++v3; --v4; } while (v4);
    //     return result;
    //   }
    // UNRESOLVED: Packet global dword_8AD298 is not referenced by the raw source text; its role in this function is unproven.
    // UNRESOLVED: Table base unk_8AD2A8 and the dispatch target VTableDispatchWithFieldClear are named in the source but carry no packet evidence refs (addresses absent).
    // UNRESOLVED: Exact semantics of the this+8 boolean state are unknown.
    // UNRESOLVED: StringSplitLoop argument 2635 is an opaque assertion token.
}
