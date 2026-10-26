// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044B090
// Canonical corpus name: TriangleProximityTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TriangleProximityTest_0044b090.c

void UnknownObject::TriangleProximityTest()
{
    // Returns a boolean assembled from two status-flag captures (v4, v5 from comparison flags c0 and c2) via (v4 | v5) != 0. The decompiler did not recover the comparison body that produces the flags; the packet's deterministic facts show the function reads the double global dbl_59EF40 (0x0059EF40), so the flags are presumed to come from a floating-point comparison involving that global. Parameters a1, a2, a3 are not referenced by the recovered body.
    // CALCULATION: Read the double global dbl_59EF40 at 0x0059EF40 inside the unmodeled comparison that produces the status flags consumed by the return expression. [global:0x0059EF40, source:raw]
    // RETURN: Return (v4 | v5) != 0, where v4 and v5 are the unsigned byte captures of comparison status flags c0 and c2; a nonzero value is returned when either flag is set. [source:raw]
    // CALL: Called by sub_44B110 (0x0044B110) as the triangle proximity test on the frame path. [caller:0x0044B110, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_44B090(int a1, int a2, int a3) {
    //     // comparison over a1/a2/a3 against dbl_59EF40 sets flags c0/c2
    //     unsigned __int8 v4 = /* c0 * /;
    //     unsigned __int8 v5 = /* c2 * /;
    //     return (v4 | v5) != 0;
    //   }
    // UNRESOLVED: The comparison body that sets flags c0 and c2 is missing from the raw source; only the flag OR-return survived decompilation.
    // UNRESOLVED: Semantics of arguments a1, a2, a3 (presumed triangle geometry inputs) are not recoverable from this body.
    // UNRESOLVED: Role of the global dbl_59EF40 in the comparison is inferred from deterministic facts, not from the raw source text.
}
