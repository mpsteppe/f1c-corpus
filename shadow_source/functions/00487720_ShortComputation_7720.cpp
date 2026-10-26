// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487720
// Canonical corpus name: ShortComputation_7720
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_7720_00487720.c

void UnknownObject::ShortComputation_7720()
{
    // Pure predicate over the result of ShortComputation_6720: calls it with this, subtracts 1, and returns true when the decremented value is 0 or 2 (equivalently, when the callee result is 1 or 3). No fields, globals or guards are touched directly.
    // CALL: Call ShortComputation_6720(0x00486720) with this and capture its integer result as v1. [callee:0x00486720, source:raw]
    // CALCULATION: Compute v1 = ShortComputation_6720(this) - 1. [callee:0x00486720, source:raw]
    // CALCULATION: Evaluate the boolean condition: true when v1 == 0 (!v1) or v1 == 2; equivalent to the callee result being 1 or 3. [source:raw]
    // RETURN: Return the computed boolean result. [source:raw, function:0x00487720]

    // Conservative worker pseudocode:
    //   bool ShortComputation_7720(_DWORD* this) {
    //     int v1 = ShortComputation_6720(this) - 1;
    //     return !v1 || v1 == 2;
    //   }
    // UNRESOLVED: The meaning of the two accepted states (original callee result 1 or 3) is not established; caller names suggest UI/state dispatch (StateDependentVTableDispatch, UIRadioCheckStateChangeHandler, ConditionalStateMachineDispatch, UIControlStateChangeHandler, sub_487D70) but the packet provides no field evidence.
    // UNRESOLVED: No fields or globals are read or written here; the function is a pure predicate over ShortComputation_6720's result.
    // UNRESOLVED: ShortComputation_6720 (0x00486720) semantics are outside this packet; this function only constrains its result.
}
