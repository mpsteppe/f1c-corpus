// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048DFF0
// Canonical corpus name: StateMachineWithVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateMachineWithVirtualDispatch_0048dff0.c

void UnknownObject::StateMachineWithVirtualDispatch()
{
    // Computes a state via ShortComputation_6720(this) and dispatches through the vtable (read at this+0x00). State 1 calls the vtable slot at obj+0x40 with argument 6 then the slot at obj+0x9C; state 2 calls slot obj+0x40 with 7 then falls through to the obj+0x9C call; state 4 calls slot obj+0x40 with 8 then obj+0x9C; state 5 calls slot obj+0x40 with 9 then falls through to obj+0x9C; the default path calls only the obj+0x9C slot. Always returns 0. Existing analysis (DERIVED) interprets states 1/2/4/5 as scroll up/down/left/right and the two vtable slots as a scroll-command setter and a refresh/repaint method.
    // CALL: Compute the current state by calling ShortComputation_6720(this); the result selects the dispatch case. [callee:0x00486720, source:raw]
    // GUARD: Switch over the computed state using the jump table jpt_48DFFE at 0x0048E050 with cases 1, 2, 4, 5 and a default. [global:0x0048E050, source:raw]
    // CALL: State 1: invoke the vtable method at obj+0x40 with argument 6 (interpreted by existing analysis as a scroll-up command). [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: State 1: invoke the vtable method at obj+0x9C with only this (interpreted as a refresh/repaint call), then return 0. [field:obj:0x0000009C, field:this:0x00000000, source:raw]
    // CALL: State 2: invoke the vtable method at obj+0x40 with argument 7 (interpreted as a scroll-down command), then fall through to the shared default refresh call. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: State 4: invoke the vtable method at obj+0x40 with argument 8 (interpreted as a scroll-left command), then invoke the refresh slot at obj+0x9C and return 0. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: State 5: invoke the vtable method at obj+0x40 with argument 9 (interpreted as a scroll-right command), then fall through to the shared default refresh call. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: Default path: invoke the vtable method at obj+0x9C with only this (the refresh/repaint call) shared by states 2 and 5 via fall-through. [field:obj:0x0000009C, field:this:0x00000000, source:raw]
    // RETURN: Always return 0 on every dispatch path. [source:raw]

    // Conservative worker pseudocode:
    //   int StateMachineWithVirtualDispatch(void** this) {
    //       switch (ShortComputation_6720(this)) {
    //           case 1: (*(void (__thiscall **)(void**, int))((*this) + 0x40))(this, 6); break;
    //           case 2: (*(void (__thiscall **)(void**, int))((*this) + 0x40))(this, 7); break;
    //           case 4: (*(void (__thiscall **)(void**, int))((*this) + 0x40))(this, 8); break;
    //           case 5: (*(void (__thiscall **)(void**, int))((*this) + 0x40))(this, 9); break;
    //           default: break;
    //       }
    //       (*(void (__thiscall **)(void**))((*this) + 0x9C))(this);
    //       return 0;
    //   }
    // UNRESOLVED: The mapping of states 1/2/4/5 to scroll directions and arguments 6-9 to specific commands comes from existing analysis (DERIVED) and is not independently proven by this packet.
    // UNRESOLVED: The roles of the vtable slots at obj+0x40 and obj+0x9C (set-command and refresh) are inferred from call shape, not confirmed.
    // UNRESOLVED: The jump table global jpt_48DFFE at 0x0048E050 implements the switch but its exact layout is not reconstructed here.
}
