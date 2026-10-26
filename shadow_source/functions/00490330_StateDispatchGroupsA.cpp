// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490330
// Canonical corpus name: sub_490330
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_490330_00490330.c

void UnknownObject::StateDispatchGroupsA()
{
    // State-dependent vtable dispatch. Computes a state value via ShortComputation_6720(this) and switches on it through jump table jpt_49033D: states 0-2 dispatch the virtual method at vtable offset 0x40 with argument 2; states 3-5 dispatch the same slot with argument 5; the default path dispatches nothing. The virtual method at vtable offset 0x98 is then called unconditionally, followed by VTableDispatchListIteration(this). Returns 0.
    // CALL: ShortComputation_6720(this) computes the state value that selects the dispatch group [callee:0x00486720, source:raw]
    // GUARD: Switch on the computed state through jump table jpt_49033D: cases 0, 1 and 2 select the group-A dispatch path [global:0x00490370, source:raw]
    // CALL: Dispatch group A: call the virtual method at vtable offset 0x40 (reads vtable pointer at this+0x0) with argument 2 [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // GUARD: Switch cases 3, 4 and 5 select the group-B dispatch path [source:raw]
    // CALL: Dispatch group B: call the same virtual method at vtable offset 0x40 with argument 5 [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: Unconditional post-dispatch call: invoke the virtual method at vtable offset 0x98 [field:obj:0x00000098, field:this:0x00000000, source:raw]
    // CALL: Iterate the child dispatch list via VTableDispatchListIteration(this) [callee:0x00490660, source:raw]
    // RETURN: Return constant 0 regardless of the selected dispatch group [function:0x00490330, source:raw]

    // Conservative worker pseudocode:
    //   state = ShortComputation_6720(this);
    //   switch (state) {
    //     case 0: case 1: case 2:
    //       (*(void (**)(void*, int))(*this + 0x40))(this, 2);
    //       break;
    //     case 3: case 4: case 5:
    //       (*(void (**)(void*, int))(*this + 0x40))(this, 5);
    //       break;
    //     default:
    //       break;
    //   }
    //   (*(void (**)(void*))(*this + 0x98))(this);
    //   VTableDispatchListIteration(this);
    //   return 0;
    // UNRESOLVED: The semantics of the state groups (0-2 vs 3-5) and of the dispatched arguments (2 vs 5) are not established from this packet
    // UNRESOLVED: The indirect vtable targets at obj+0x40 and obj+0x98 have no static callee evidence, so their identities are unknown
    // UNRESOLVED: The owning object type is unknown (packet owner is UNKNOWN); the ABI label is LEGACY trust and not independently confirmed
}
