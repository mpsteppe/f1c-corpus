// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564B10
// Canonical corpus name: BinarySearchWithCallbackComparator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinarySearchWithCallbackComparator_00564b10.c

void UnknownObject::BinarySearchWithCallbackComparator()
{
    // Binary search over a3 elements starting at pointer a2 with stride a4, comparing each midpoint element a2 + a4 * v9 against a1 through the callback comparator a5(element_pointer, a1). The found-flag at *a6 starts at 0 and is set to 1 when the comparator returns zero (exact match). Negative comparator results move the lower bound above the midpoint; zero and positive results move the upper bound below it. Returns a2 + a4 * v7, the element pointer at the terminal lower-bound index.
    // ASSIGNMENT: Initialize the upper bound index v6 to a3 - 1. [source:raw]
    // ASSIGNMENT: Initialize the lower bound index v7 to 0. [source:raw]
    // ASSIGNMENT: Clear the caller-provided found-flag at *a6 to 0. [source:raw]
    // LOOP: Repeat while the lower bound v7 is less than or equal to the upper bound v6. [function:0x00564B10, source:raw]
    // CALCULATION: Compute the midpoint index v9 = (v6 + v7) >> 1. [source:raw]
    // CALL: Invoke the comparator callback a5(a2 + a4 * v9, a1) on the element pointer at the midpoint. [function:0x00564B10, source:raw]
    // GUARD: When the comparator result is negative, move the lower bound above the midpoint (v7 = v9 + 1) and continue the loop. [source:raw]
    // GUARD: When the comparator result is zero, record an exact match by setting the found-flag *a6 to 1. [source:raw]
    // ASSIGNMENT: For both the zero result and the nonzero-positive result, narrow the upper bound to v6 = v9 - 1. [source:raw]
    // RETURN: Return a2 + a4 * v7, the element pointer at the final lower-bound index. [source:raw]

    // Conservative worker pseudocode:
    //   int BinarySearchWithCallbackComparator(int a1, int a2, int a3, int a4, int (*a5)(int, int), int* a6) {
    //     int upper = a3 - 1;
    //     int lower = 0;
    //     *a6 = 0;
    //     while (lower <= upper) {
    //       int mid = (upper + lower) >> 1;
    //       int cmp = a5(a2 + a4 * mid, a1);
    //       if (cmp) {
    //         if (cmp < 0) { lower = mid + 1; continue; }
    //       } else {
    //         *a6 = 1;
    //       }
    //       upper = mid - 1;
    //     }
    //     return a2 + a4 * lower;
    //   }
    // UNRESOLVED: The ordering convention of the comparator callback (negative/zero/positive) is assumed to be the standard comparator contract but is not proven by the packet.
    // UNRESOLVED: The roles of a1 and a3 are ambiguous: the caller 0x00564A20 passes four explicit arguments (range, stride, key, &found), while the raw source consumes a1 as the comparator's second operand and a3 as the element count; the exact argument mapping is not established by the packet.
    // UNRESOLVED: The stride a4 is treated as a byte displacement per element but its unit is not stated in the packet.
}
