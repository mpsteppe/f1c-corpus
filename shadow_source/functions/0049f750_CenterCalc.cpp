// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F750
// Canonical corpus name: CenterCalc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CenterCalc_0049f750.c

void UnknownObject::CenterCalc()
{
    // Conditionally computes a centered span value. When the guard argument a4 is non-zero, the raw value is first normalized through sub_5531F0 (a1, &a4, &a1, 0), which rewrites a4 in place; the function then halves the adjusted a4 and stores a2 minus that half through output pointer a3, returning the half as the result. Called by StringFormatAndRender (0x0049F6A0), which suggests it positions content around a center relative to an edge.
    // GUARD: Whole body is gated on the a4 argument being non-zero; the else path returns without storing anything [source:raw]
    // CALL: Normalizes the span quantity in place by calling sub_5531F0(a1, &a4, &a1, 0), which rewrites a4 and a1 through pointer arguments [callee:0x005531F0, source:raw]
    // CALCULATION: Halves the adjusted a4 to obtain the centered offset [source:raw]
    // ASSIGNMENT: Stores a2 minus the halved a4 into the a3 output pointer and records the halved a4 as the result [source:raw]
    // RETURN: Returns the halved a4 value as the function result [source:raw]
    // CALL: Invoked by StringFormatAndRender (0x0049F6A0) [caller:0x0049F6A0, source:raw]

    // Conservative worker pseudocode:
    //   int result;
    //   if (a4 != 0) {
    //     sub_5531F0(a1, &a4, &a1, 0);
    //     result = a4 / 2;
    //     *a3 = a2 - a4 / 2;
    //   }
    //   return result;
    // UNRESOLVED: result is returned uninitialized when the a4 guard fails; the decompiled local has no default
    // UNRESOLVED: The exact semantics of sub_5531F0's in-place normalization of a4 are not established from this packet
    // UNRESOLVED: Whether a2 is a left or right edge for the centered span is not determinable from this packet
    // UNRESOLVED: The identity of a1 relative to the returned/stored values is unclear
}
