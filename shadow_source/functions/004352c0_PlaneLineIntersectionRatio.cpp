// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004352C0
// Canonical corpus name: PlaneLineIntersectionRatio
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlaneLineIntersectionRatio_004352c0.c

void UnknownObject::PlaneLineIntersectionRatio()
{
    // Computes an intersection ratio t for a line segment (a1 to a3) against a plane parameterized by a2 (x component, read from this+0x0) and a4 (z component, read from this+0x8). Tests the plane x/z components against the zero threshold flt_59E440 and splits into two algebraically equivalent branches depending on which component is nonzero. Returns FLT_MAX (flt_59EAE0) when both plane components are zero or when the computed denominator is zero; otherwise returns v9 / v10. Called by VehicleMainPhysicsUpdate (004441F0).
    // CALCULATION: Computes deltas v4 = a3.x - a1.x and v15 = a3.z - a1.z; plane parameters are read from a2 (x, this+0x0) and a4 (z, this+0x8) [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: Degenerate-plane guard: when a4.x is zero (against the flt_59E440 threshold) the a4.z branch runs; if both a4.x and a4.z are zero the function returns FLT_MAX (flt_59EAE0) [global:0x0059E440, global:0x0059EAE0, source:raw]
    // CALCULATION: Branch with nonzero a4.x: v14 = a4.z / a4.x, numerator v9 = v15 - v4 * v14, denominator v10 = a2.z - v14 * a2.x [source:raw]
    // CALCULATION: Branch with a4.x zero (a4.z nonzero): v13 = v6 / v7, numerator v9 = v4 - v13 * v15, denominator v10 = a2.x - v13 * a2.z [source:raw]
    // GUARD: Denominator guard: when v10 equals zero (parallel / no intersection) the function returns FLT_MAX (flt_59EAE0) [global:0x0059EAE0, source:raw]
    // RETURN: Returns the ratio v9 / v10, or FLT_MAX on the degenerate cases; called by VehicleMainPhysicsUpdate (004441F0) [function:0x004352C0, caller:0x004441F0, source:raw]

    // Conservative worker pseudocode:
    //   v4 = a3.x - a1.x; v15 = a3.z - a1.z;
    //   if (a4.x == 0.0) {
    //     if (a4.z == 0.0) return 3.4028235e38;
    //     v13 = a4.x / a4.z;
    //     v9 = v4 - v13 * v15; v10 = a2.x - v13 * a2.z;
    //   } else {
    //     v14 = a4.z / a4.x;
    //     v9 = v15 - v4 * v14; v10 = a2.z - v14 * a2.x;
    //   }
    //   if (v10 == 0.0) return 3.4028235e38;
    //   return v9 / v10;
    // UNRESOLVED: The mapping of plane parameters a2/a4 onto this+0x0 and this+0x8 is DERIVED from the existing analysis; the raw source only exposes the four pointer arguments
    // UNRESOLVED: Whether flt_59E440 is genuinely a zero-threshold comparison constant or a separate physics clamp is DERIVED; the raw source shows the literal 0.0 comparisons and 3.4028235e38 return without naming the globals
}
