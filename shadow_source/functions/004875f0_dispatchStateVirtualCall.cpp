// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004875F0
// Canonical corpus name: sub_4875F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4875F0_004875f0.c

void UnknownObject::dispatchStateVirtualCall()
{
    // State-dependent vtable dispatch with unconditional flag clear. Computes a state value by calling ShortComputation_6720(this), subtracts 2, and dispatches through the vtable pointer at this+0 to the slot at byte offset 64 with branch-specific arguments: state value 2 calls it thiscall with (this, 0); state value 3 calls it with (1); any other value skips the dispatch. Every path clears the flag at this+0xDC to 0 and returns 0.
    // CALL: Call ShortComputation_6720 with this as argument to obtain the state value. [callee:0x00486720, function:0x004875F0, source:raw]
    // CALCULATION: Compute state_delta = ShortComputation_6720(this) - 2, the selector for the dispatch branches. [callee:0x00486720, function:0x004875F0, source:raw]
    // GUARD: If state_delta == 0 (ShortComputation_6720 returned 2), dispatch through vtable pointer at this+0, slot at byte offset 64, thiscall convention. [field:this:0x00000000, source:raw]
    // CALL: Virtual call via vtable slot at byte offset 64 with arguments (this, 0), thiscall convention. [field:this:0x00000000, source:raw]
    // GUARD: Else if state_delta == 1 (ShortComputation_6720 returned 3), dispatch through vtable pointer at this+0, slot at byte offset 64, stdcall convention. [field:this:0x00000000, source:raw]
    // CALL: Virtual call via vtable slot at byte offset 64 with argument (1), stdcall convention. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the flag at this+0xDC (this[55]) to 0 on every path. [field:this:0x000000DC, source:raw]
    // RETURN: Return 0 on every path. [function:0x004875F0, source:raw]

    // Conservative worker pseudocode:
    //   int dispatchStateVirtualCall(_DWORD* this) {
    //       int state_delta = ShortComputation_6720(this) - 2;
    //       if (state_delta == 0) {
    //           (vtable_call_at(this + 0, 64))(this, 0);  /* thiscall * /
    //       } else if (state_delta == 1) {
    //           (vtable_call_at(this + 0, 64))(1);        /* stdcall * /
    //       }
    //       this[0xDC / 4] = 0;
    //       return 0;
    //   }
    // UNRESOLVED: Field obj+0x40 is listed as read, but the raw source only passes this to ShortComputation_6720; the read is not directly visible in this function and likely belongs to the callee's frame.
    // UNRESOLVED: The same vtable slot (byte offset 64) is invoked with two different calling conventions and argument shapes (thiscall (this, 0) vs stdcall (1)); either a decompiler artifact or a genuine dual-prototype usage that cannot be resolved statically here.
    // UNRESOLVED: Semantic role of the this+0xDC flag and the meaning of the state values 2 and 3 are not established.
}
