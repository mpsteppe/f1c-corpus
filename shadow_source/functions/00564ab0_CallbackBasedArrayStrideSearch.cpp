// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564AB0
// Canonical corpus name: CallbackBasedArrayStrideSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackBasedArrayStrideSearch_00564ab0.c

void UnknownObject::CallbackBasedArrayStrideSearch()
{
    // Linear scan over an array of up to a3 elements starting at pointer a2, advancing by a4 bytes per element, invoking the callback predicate a5(a1, element_pointer) on each element while it returns nonzero. Returns the pointer to the first element for which the callback returns zero, or 0 when a3 <= 0 or the count is exhausted before the callback returns zero.
    // ASSIGNMENT: Initialize the element counter v5 to 0. [source:raw]
    // GUARD: Return 0 immediately when the element count a3 is less than or equal to 0. [source:raw]
    // ASSIGNMENT: Set the element cursor v6 to the starting element pointer a2. [source:raw]
    // LOOP: While the callback a5(a1, v6) returns nonzero, continue scanning elements. [function:0x00564AB0, source:raw]
    // ASSIGNMENT: Increment the element counter v5 for each element visited. [source:raw]
    // CALCULATION: Advance the cursor by the stride: v6 += a4. [source:raw]
    // GUARD: Return 0 when the counter v5 reaches the element count a3, indicating the callback never returned zero within the range. [source:raw]
    // RETURN: Return a2 + a4 * v5, the pointer to the first element whose callback returned zero. [source:raw]

    // Conservative worker pseudocode:
    //   int CallbackBasedArrayStrideSearch(int a1, int a2, int a3, int a4, int (*a5)(int, int)) {
    //     int count = 0;
    //     if (a3 <= 0) return 0;
    //     int cursor = a2;
    //     while (a5(a1, cursor)) {
    //       ++count;
    //       cursor += a4;
    //       if (count >= a3) return 0;
    //     }
    //     return a2 + a4 * count;
    //   }
    // UNRESOLVED: The meaning of the callback return value (which elements count as matches) is not described by the packet; the loop only establishes that scanning stops at the first element where a5 returns zero.
    // UNRESOLVED: The role of a1, passed unchanged as the first callback argument, is not established by the packet.
    // UNRESOLVED: In the caller 0x00564A20 the function is invoked with three explicit arguments (range, stride, key); the mapping of those arguments onto a1..a5 and the callback bound by the caller are not described in the raw source.
}
