// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F710
// Canonical corpus name: SubtractionWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubtractionWithGuard_0049f710.c

void UnknownObject::SubtractionWithGuard()
{
    // Conditionally computes the difference a2 minus a safety-adjusted value and stores it through output pointer a3. When the guard argument a4 is non-zero, the raw value is first normalized through sub_5531F0 (a1, &a4, &a1, 0), which rewrites a4 in place; the stored result is a2 minus the adjusted a4, and the adjusted a4 is also returned. Called by StringFormatAndRender (0x0049F6A0).
    // GUARD: Whole body is gated on the a4 argument being non-zero; the else path returns without storing anything [source:raw]
    // CALL: Normalizes the safety quantity in place by calling sub_5531F0(a1, &a4, &a1, 0), which rewrites a4 and a1 through pointer arguments [callee:0x005531F0, source:raw]
    // ASSIGNMENT: Stores the difference of the a2 minuend and the adjusted a4 into the a3 output pointer, and records the adjusted a4 as the result [source:raw]
    // RETURN: Returns the adjusted a4 value as the function result [source:raw]
    // CALL: Invoked by StringFormatAndRender (0x0049F6A0) [caller:0x0049F6A0, source:raw]

    // Conservative worker pseudocode:
    //   int result;
    //   if (a4 != 0) {
    //     sub_5531F0(a1, &a4, &a1, 0);
    //     result = a4;
    //     *a3 = a2 - a4;
    //   }
    //   return result;
    // UNRESOLVED: result is returned uninitialized when the a4 guard fails; the decompiled local has no default
    // UNRESOLVED: The exact semantics of sub_5531F0's in-place normalization of a4 are not established from this packet
    // UNRESOLVED: The meaning of a1 relative to the returned/stored values is unclear
}
