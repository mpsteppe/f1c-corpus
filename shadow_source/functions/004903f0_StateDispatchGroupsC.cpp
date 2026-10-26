// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004903F0
// Canonical corpus name: UtilityFunction_03f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_03f0_004903f0.c

void UnknownObject::StateDispatchGroupsC()
{
    // State-based dispatch (thiscall): selects an argument by group from ShortComputation_6720's result. Groups 0-2 dispatch the vtable method at +0x40 with argument 1; groups 3-5 dispatch it with argument 4; any other value skips the vtable dispatch. Every path then iterates the child dispatch list via VTableDispatchListIteration and returns 0.
    // CALL: Read the state/computation value via ShortComputation_6720(this) to select the dispatch group. [callee:0x00486720, source:raw]
    // STATE_TRANSITION: Switch on the ShortComputation_6720 result using jump table jpt_4903FD; groups 0,1,2,3,4,5 and default are handled. [global:0x0049042C, source:raw]
    // CALL: For groups 0-2, call the vtable method stored at +0x40 with argument 1: ((int (__thiscall **)(_DWORD *, int))(*this + 64))(this, 1). [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: For groups 3-5, call the vtable method stored at +0x40 with argument 4: ((int (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4). [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: On every path, iterate the child dispatch list via VTableDispatchListIteration(this). [callee:0x00490660, source:raw]
    // ASSIGNMENT: Set the result to 0 for all handled groups. [source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int StateDispatchGroupsC(_DWORD *this) {
    //     switch (ShortComputation_6720(this)) {
    //       case 0: case 1: case 2:
    //         (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 1);
    //         break;
    //       case 3: case 4: case 5:
    //         (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4);
    //         break;
    //       default:
    //         break;
    //     }
    //     VTableDispatchListIteration(this);
    //     return 0;
    //   }
    // UNRESOLVED: Owner class and the meaning of the +0x40 vtable slot are unknown.
    // UNRESOLVED: Semantics of the argument distinction (1 vs 4) and of ShortComputation_6720 are not established here.
}
