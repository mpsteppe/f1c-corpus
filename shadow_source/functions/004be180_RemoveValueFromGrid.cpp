// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE180
// Canonical corpus name: NestedLoopCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NestedLoopCall_004be180.c

void UnknownObject::RemoveValueFromGrid()
{
    // Nested 8x8 loop removing a value from a grid of array-like cells. Walks 64 cells in two nested do-while loops advancing the cell pointer by 9 dwords (36 bytes) per step, calling ArrayRemoveByValue(cell, a2) on each. After the grid sweep it makes one final ArrayRemoveByValue(this + 576, a2) call, where 576 dwords equals 64 cells x 9, i.e. the first element just past the grid, and returns that call's result.
    // LOOP: Outer loop counter v3 runs 8 iterations over the grid rows [function:0x004BE180, source:raw]
    // LOOP: Inner loop counter v4 runs 8 iterations per outer pass, yielding 64 cells total [source:raw]
    // CALCULATION: Cell pointer v2 advances by 9 dwords per inner iteration (36-byte stride between cells) [source:raw]
    // CALL: ArrayRemoveByValue(v2, a2) invoked once per cell to remove value a2 [callee:0x004BD970, source:raw]
    // CALL: Final ArrayRemoveByValue(this + 576, a2) removes the value from the element 576 dwords past this, the first element after the 8x8 grid [callee:0x004BD970, source:raw]
    // RETURN: Returns the result of the final ArrayRemoveByValue call [function:0x004BE180, source:raw]
    // CALL: Invoked on the frame path by ShortComputation_f0d0 and StateDependentUpdateDispatch [abi:lead, caller:0x0040F0D0, caller:0x0040F130]

    // Conservative worker pseudocode:
    //   v2 = this;
    //   v3 = 8;
    //   do {
    //     v4 = 8;
    //     do {
    //       ArrayRemoveByValue(v2, a2);
    //       v2 += 9;
    //     } while (--v4);
    //   } while (--v3);
    //   return ArrayRemoveByValue(this + 576, a2);
    // UNRESOLVED: The concrete container shape at each 9-dword cell (base pointer, size and capacity layout) is not defined in this packet; the stride and count are the only structural facts available
    // UNRESOLVED: The trailing call at this + 576 targets an element just past the grid, whose separate role is unknown
}
