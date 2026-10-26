// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561ACF
// Canonical corpus name: ArrayFillWithValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayFillWithValue_00561acf.c

void UnknownObject::ArrayFillWithValue()
{
    // Fills a contiguous array of 32-bit words with a single value. Computes the destination as a1 * 4 + a4 and invokes memset32 to write a2 dwords of value a3, returning a3. The result value is loaded before the fill call and returned unchanged.
    // ASSIGNMENT: Initialize result to a3; this value is returned unchanged after the fill. [source:raw]
    // CALCULATION: Compute the destination byte address as a1 + a1 + a1 + a1 + a4, i.e. 4 * a1 + a4, giving a pointer into a dword array. [source:raw]
    // CALL: Call memset32(dest, a3, a2) to fill a2 dwords starting at the computed destination with the value a3. [source:raw]
    // RETURN: Return a3 (the fill value) as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_561ACF(int a1, unsigned int a2, int a3, int a4) {
    //     int result = a3;
    //     memset32((void *)(4 * a1 + a4), a3, a2);
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the offset pair (a1, a4) beyond forming the destination pointer depend on the caller's array layout.
    // UNRESOLVED: Unit of a2 is assumed to be 32-bit words (memset32); element count per call is caller-determined.
    // UNRESOLVED: Caller sub_553D40 relationship and why the fill value a3 is also the return value are not established.
}
