// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004189B0
// Canonical corpus name: StateCheckedVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateCheckedVirtualDispatch_004189b0.c

void UnknownObject::StateCheckedVirtualDispatch()
{
    // State-gated virtual action dispatch. First checks that the current state ID at this+0xAEC equals the requested state parameter a2, returning 0 on mismatch. Then reads the vtable-equipped object pointer at this+0xAF4; if it is null, or its vtable gate-check slot (vtable+0x8, slot 2) returns 0, returns 0. Otherwise invokes the vtable action slot at vtable+0xC (slot 3) on the object and returns 1. Called by BooleanOROfTwoChecks (00418a20) and PitSelectionStateMachine (0041b3c0) as state-machine infrastructure.
    // GUARD: State match guard: returns 0 immediately when the current state ID at this+0xAEC differs from the requested state a2 [field:this:0x00000AEC, source:raw]
    // GUARD: Dispatch target guard: returns 0 when the pointer at this+0xAF4 is null, or when its vtable gate-check slot (vtable+0x8) returns 0 [field:this:0x00000AF4, field:*(this+0xAF4):0x00000008, source:raw]
    // CALL: On both guards passing, invokes the vtable action slot at vtable+0xC (slot 3) via the object pointer at this+0xAF4 [field:this:0x00000AF4, field:*(this+0xAF4):0x0000000C, source:raw]
    // RETURN: Returns 1 when the virtual action was executed, or 0 when the state mismatch or gate check blocked the dispatch [source:raw]
    // CALL: Shared state-machine helper reached from BooleanOROfTwoChecks (00418a20) and PitSelectionStateMachine (0041b3c0) [caller:0x00418A20, caller:0x0041B3C0, source:raw]

    // Conservative worker pseudocode:
    //   char StateCheckedVirtualDispatch(int *this, int a2) {
    //     if (this[699] != a2) return 0;               // this+0xAEC current state ID
    //     v3 = this[701];                              // this+0xAF4 dispatch object
    //     if (!v3) return 0;
    //     if (!(*(int (__thiscall **)(int))(*(DWORD*)v3 + 8))(v3)) return 0;   // vtable slot 2 gate
    //     (*(void (__thiscall **)(DWORD))(*(DWORD*)v3 + 12))(v3);              // vtable slot 3 action
    //     return 1;
    //   }
    // UNRESOLVED: The owner classes of the state object (this) and the vtable-equipped dispatch target are unknown; the gate and action slot roles are proposals grounded in call patterns, not confirmed
    // UNRESOLVED: The semantics of the state ID at this+0xAEC (which state machine, what state encoding) are not established from this packet alone
}
