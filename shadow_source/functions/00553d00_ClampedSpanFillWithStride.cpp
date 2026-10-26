// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553D00
// Canonical corpus name: sub_553D00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553D00_00553d00.c

void UnknownObject::ClampedSpanFillWithStride()
{
    // Orders a span along an axis: v6 starts as a3; if a2 > a3, v6 becomes a2 and a2 becomes a3, so after the swap a2 holds the lower endpoint and v6 the upper. Then calls ShortArrayFillWithStride(a1 + a5*a2, v6 - a2 + 1, a4, a5, a6), filling a strided array starting at a1 + a5*a2 for (upper - lower + 1) elements. Returns the fill helper's result.
    // ASSIGNMENT: Initialize v6 = a3, the initial candidate for the upper endpoint. [source:raw]
    // GUARD: If a2 > a3, set v6 = a2 and a2 = a3, so a2 becomes the lower endpoint and v6 the upper. [source:raw]
    // CALCULATION: Compute destination pointer a1 + a5*a2 and element count v6 - a2 + 1. [source:raw]
    // CALL: Call ShortArrayFillWithStride(a1 + a5*a2, v6 - a2 + 1, a4, a5, a6) to fill the strided span. [callee:0x00561A15]
    // RETURN: Return the result of ShortArrayFillWithStride. [source:raw]

    // Conservative worker pseudocode:
    //   int ClampedSpanFillWithStride(int base_pointer, int index_a, int index_b, int fill_value, int stride, int fill_argument) {
    //       int upper_index = index_b;
    //       if (index_a > index_b) {
    //           upper_index = index_a;
    //           index_a = index_b;
    //       }
    //       return ShortArrayFillWithStride(base_pointer + stride * index_a, upper_index - index_a + 1, fill_value, stride, fill_argument);
    //   }
    // UNRESOLVED: Element width and type of the array filled by ShortArrayFillWithStride are unknown (name implies a strided short fill but the helper contract is not in this packet).
    // UNRESOLVED: Semantic meaning of the fill argument a6 is unconfirmed.
}
