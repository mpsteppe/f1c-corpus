// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490390
// Canonical corpus name: sub_490390
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_490390_00490390.c

void UnknownObject::StateDispatchGroupsB()
{
    // State-dependent vtable dispatch. Computes a state value via ShortComputation_6720(this) and switches on it through jump table jpt_49039D: states 0-2 dispatch the virtual method at vtable offset 0x40 with argument 4; states 3-5 dispatch the same slot with argument 1; the default path dispatches nothing. The virtual method at vtable offset 0x9C is then called unconditionally, followed by VTableDispatchListIteration(this). Returns 0.
    // CALL: ShortComputation_6720(this) computes the state value that selects the dispatch group [callee:0x00486720, source:raw]
    // GUARD: Switch on the computed state through jump table jpt_49039D: cases 0, 1 and 2 select the group-A dispatch path [global:0x004903D0, source:raw]
    // CALL: Dispatch group A: call the virtual method at vtable offset 0x40 (reads vtable pointer at this+0x0) with argument 4 [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // GUARD: Switch cases 3, 4 and 5 select the group-B dispatch path [source:raw]
    // CALL: Dispatch group B: call the same virtual method at vtable offset 0x40 with argument 1 [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: Unconditional post-dispatch call: invoke the virtual method at vtable offset 0x9C [field:obj:0x0000009C, field:this:0x00000000, source:raw]
    // CALL: Iterate the child dispatch list via VTableDispatchListIteration(this) [callee:0x00490660, source:raw]
    // RETURN: Return constant 0 regardless of the selected dispatch group [function:0x00490390, source:raw]

    // Conservative worker pseudocode:
    //   state = ShortComputation_6720(this);
    //   switch (state) {
    //     case 0: case 1: case 2:
    //       (*(void (**)(void*, int))(*this + 0x40))(this, 4);
    //       break;
    //     case 3: case 4: case 5:
    //       (*(void (**)(void*, int))(*this + 0x40))(this, 1);
    //       break;
    //     default:
    //       break;
    //   }
    //   (*(void (**)(void*))(*this + 0x9C))(this);
    //   VTableDispatchListIteration(this);
    //   return 0;
    // UNRESOLVED: The semantics of the state groups (0-2 vs 3-5) and of the dispatched arguments (4 vs 1) are not established from this packet
    // UNRESOLVED: The indirect vtable targets at obj+0x40 and obj+0x9C have no static callee evidence, so their identities are unknown
    // UNRESOLVED: The owning object type is unknown (packet owner is UNKNOWN); no ABI entry is exposed for this function
}
