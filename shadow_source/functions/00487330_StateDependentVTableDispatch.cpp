// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487330
// Canonical corpus name: StateDependentVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateDependentVTableDispatch_00487330.c

void UnknownObject::StateDependentVTableDispatch()
{
    // State-dependent vtable dispatch for a UI widget. Reads a mode (0-4) from ShortComputation_6720(this) and, per mode, maps boolean input a2 to a specific argument for a virtual method at offset 64. Cases 0 and 1 invoke the method only when a2 is set; cases 2 and 3 only when a2 is clear; case 4 gates the dispatch on the current state byte from ByteFieldGetterAt100 and selects the argument (2 or 0, else 3 or 1) using ShortComputation_7720. Default case returns the mode unchanged. Called by UIWidgetPropagateState (0048741B).
    // CALL: Compute the widget mode by calling ShortComputation_6720(this); the result selects the switch case. [callee:0x00486720, source:raw]
    // STATE_TRANSITION: Switch on the mode 0-4 using the jump table jpt_48733E; a mode outside 0-4 falls through to the default return. [global:0x004873E0, source:raw]
    // CALL: Case 0: if a2 is non-zero, invoke the virtual method at offset 64 on this with argument 2. [source:raw]
    // CALL: Case 1: if a2 is non-zero, invoke the virtual method at offset 64 on this with argument 3. [source:raw]
    // CALL: Case 2: if a2 is zero, invoke the virtual method at offset 64 on this with argument 0. [source:raw]
    // CALL: Case 3: if a2 is zero, invoke the virtual method at offset 64 on this with argument 1. [source:raw]
    // CALL: Case 4: read the current state byte via ByteFieldGetterAt100; only when it is zero, select the vtable argument (a2 != 0 ? 2 : 0 when ShortComputation_7720 is zero, otherwise 2 * (a2 != 0) + 1) and invoke the virtual method at offset 64. [callee:0x00486710, callee:0x00487720, source:raw]
    // RETURN: Return the accumulated result v2 (mode or last vtable call result); the default case returns the mode unchanged. [function:0x00487330, source:raw]

    // Conservative worker pseudocode:
    //   char StateDependentVTableDispatch(void* this, char a2) {
    //     int mode = ShortComputation_6720(this);
    //     int result = a2;
    //     switch (mode) {
    //       case 0: if (a2) result = vtable_call_64(this, 2); break;
    //       case 1: if (a2) result = vtable_call_64(this, 3); break;
    //       case 2: if (!a2) result = vtable_call_64(this, 0); break;
    //       case 3: if (!a2) result = vtable_call_64(this, 1); break;
    //       case 4:
    //         if (ByteFieldGetterAt100(this) == 0) {
    //           int arg = ShortComputation_7720() == 0 ? (a2 ? 2 : 0) : (2 * (a2 != 0) + 1);
    //           result = vtable_call_64(this, arg);
    //         }
    //         break;
    //       default: return mode;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The owning UI widget class and the identity of the virtual method at offset 64 are not established.
    // UNRESOLVED: The vtable call receiver in the decompilation is an ecx alias of this; no separate object is proven.
    // UNRESOLVED: ShortComputation_7720's exact role (a range or mode check) is inferred from the branch shape only.
}
