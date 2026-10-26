// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00435290
// Canonical corpus name: FloatEpsilonCompare
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatEpsilonCompare_00435290.c

void UnknownObject::FloatEpsilonCompare()
{
    // __stdcall double tolerance comparison: returns TRUE when the absolute difference of the two double arguments is below the epsilon constant 0.000000001, i.e. the two values are equal within tolerance. The packet deterministically lists dbl_59EAD8 as a read global, presumed to be the storage for the folded epsilon literal (identity DERIVED). Used by the suspension wheel dynamics solver.
    // CALCULATION: Compute fabs(a1 - a2) < 0.000000001: absolute difference of the two doubles compared against the epsilon threshold (packet lists dbl_59EAD8 as the read global backing this constant). [global:0x0059EAD8, source:raw]
    // RETURN: Return the comparison result as BOOL (true when the two doubles are equal within the epsilon tolerance). [function:0x00435290, source:raw]
    // CALL: Invoked by SuspensionWheelDynamicsSolver (0x0043F7F0). [caller:0x0043F7F0]

    // Conservative worker pseudocode:
    //   return fabs(a1 - a2) < 0.000000001;
    // UNRESOLVED: The raw source inlines the literal 0.000000001 while the deterministic packet lists dbl_59EAD8 as a read global; the literal is presumed to be the constant stored at dbl_59EAD8, but that identity is DERIVED, not packet-stated.
    // UNRESOLVED: The exact tolerance use (e.g. position/distance equality check inside the suspension solver) is not evident from this function alone.
}
