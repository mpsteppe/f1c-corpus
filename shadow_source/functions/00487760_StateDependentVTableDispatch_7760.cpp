// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487760
// Canonical corpus name: StateDependentVTableDispatch_7760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateDependentVTableDispatch_7760_00487760.c

void UnknownObject::StateDependentVTableDispatch_7760()
{
    // State-dependent vtable dispatch for a UI control. Reads a mode (0-4) from ShortComputation_6720(this) and, per mode, maps boolean input a2 to a specific argument for a virtual method at offset 64. Cases 0 and 2 invoke the method only when a2 is set; cases 1 and 3 only when a2 is clear; case 4 gates the dispatch on the current state byte from ByteFieldGetterAt100 and selects the argument 0/1 or 2/3 based on RangeCheck. Default case returns the mode unchanged. Called by UIControlStateChangeHandler (00487960) and InitDispatchWithVTableCheck (004879E0).
    // CALL: Compute the control mode by calling ShortComputation_6720(this); the result selects the switch case. [callee:0x00486720, source:raw]
    // STATE_TRANSITION: Switch on the mode 0-4 using the jump table jpt_48776F; a mode outside 0-4 falls through to the default return. [global:0x00487810, source:raw]
    // CALL: Case 0: if a2 is non-zero, invoke the virtual method at offset 64 on this with argument 1. [source:raw]
    // CALL: Case 1: if a2 is zero, invoke the virtual method at offset 64 on this with argument 0. [source:raw]
    // CALL: Case 2: if a2 is non-zero, invoke the virtual method at offset 64 on this with argument 3. [source:raw]
    // CALL: Case 3: if a2 is zero, invoke the virtual method at offset 64 on this with argument 2. [source:raw]
    // CALL: Case 4: read the current state byte via ByteFieldGetterAt100; only when it is zero, base the argument on a2 != 0 and add 2 when RangeCheck is true, then invoke the virtual method at offset 64. [callee:0x00486710, callee:0x00487740, source:raw]
    // RETURN: Return the accumulated result v2 (mode or last vtable call result); the default case returns the mode unchanged. [function:0x00487760, source:raw]

    // Conservative worker pseudocode:
    //   char StateDependentVTableDispatch_7760(void* this, char a2) {
    //     int mode = ShortComputation_6720(this);
    //     int result = a2;
    //     switch (mode) {
    //       case 0: if (a2) result = vtable_call_64(this, 1); break;
    //       case 1: if (!a2) result = vtable_call_64(this, 0); break;
    //       case 2: if (a2) result = vtable_call_64(this, 3); break;
    //       case 3: if (!a2) result = vtable_call_64(this, 2); break;
    //       case 4:
    //         if (ByteFieldGetterAt100(this) == 0) {
    //           int base = (a2 != 0) ? 1 : 0;
    //           int arg = RangeCheck(this) ? base + 2 : base;
    //           result = vtable_call_64(this, arg);
    //         }
    //         break;
    //       default: return mode;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The owning UI control class and the identity of the virtual method at offset 64 are not established.
    // UNRESOLVED: The vtable call receiver in the decompilation is an ecx alias of this; no separate object is proven.
    // UNRESOLVED: RangeCheck's precise semantics (range bound vs state check) are inferred from the branch shape only.
}
