// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487160
// Canonical corpus name: UtilityFunction_7160
// Owner: UIOffsetLookupTable [DERIVED]
// Raw source: functions/UtilityFunction_7160_00487160.c

void UIOffsetLookupTable::CombinedXYOffsetLookup()
{
    // Reads an indexed pair of offset values from a linked list via LinkedListIndexedFieldReader and combines each with a base offset stored on the owner: writes this[3] + v7 into *a3 and this[1] + v8 into *a4. The lookup is guarded by an index-boundary check against ShortComputation_adb0(this+28) with a flag at this[50] (offset 0xC8); if the index is out of range while the flag is clear, or the reader fails, the function returns 0. Used by UI rendering helpers (rectangle drawing and text box scrollbar rendering).
    // GUARD: If a2 >= ShortComputation_adb0(this + 28) and the guard flag this[50] (offset 0xC8) is zero, block and return 0. [callee:0x0049ADB0, field:this:0x000000C8]
    // GUARD: Call LinkedListIndexedFieldReader(a2, &v7, &v8) to fetch the indexed offset pair; if it returns zero, block and return 0. [callee:0x0049AEC0]
    // ASSIGNMENT: Combine the base offset at this[3] (offset 0xC) with the first read value: *a3 = this[3] + v7. [field:this:0x0000000C]
    // ASSIGNMENT: Combine the base offset at this[1] (offset 0x4) with the second read value: *a4 = this[1] + v8. [field:this:0x00000004]
    // RETURN: Return 1 to signal that both combined offsets were written. [function:0x00487160, source:raw]

    // Conservative worker pseudocode:
    //   int CombinedXYOffsetLookup(int a2, int *outA, int *outB) {
    //     __int16 v7, v8;
    //     if (a2 >= ShortComputation_adb0(this + 28) && !this[50])
    //       return 0;
    //     if (!LinkedListIndexedFieldReader(a2, &v7, &v8))
    //       return 0;
    //     *outA = this[3] + v7;
    //     *outB = this[1] + v8;
    //     return 1;
    //   }
    // UNRESOLVED: Whether the read pair (v7, v8) and the bases this[1]/this[3] represent X/Y or another coordinate pair is not established by this function alone.
    // UNRESOLVED: Exact meaning of the boundary returned by ShortComputation_adb0 and the flag at this[50] is caller/owner dependent.
}
