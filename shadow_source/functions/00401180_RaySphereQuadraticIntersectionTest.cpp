// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401180
// Canonical corpus name: RaySphereQuadraticIntersectionTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaySphereQuadraticIntersectionTest_00401180.c

void UnknownObject::RaySphereQuadraticIntersectionTest()
{
    // Ray-sphere quadratic intersection test on six double inputs (a1..a6). Builds squared-offset and difference terms, resolves a degenerate axis by swapping terms, then solves the quadratic and returns 1/sqrt(p) as a penetration-length proxy, or 0.0 on any miss. Called by VehicleSuspensionForceCalculation (00401340).
    // CALCULATION: Squared-offset terms: v19 = a1*a1 + a2*a2 and v18 = v19 - a3*a3 - a4*a4 [source:raw]
    // CALCULATION: Difference terms from doubled coordinates: v21 = a1+a1, v17 = a3+a3-v21, v20 = a2+a2, v6 = a4+a4-v20, then v23 = v19 - a5*a5 - a6*a6, v22 = a5+a5-v21, v7 = a6+a6-v20 [source:raw]
    // GUARD: Degenerate axis handling: if v6==0.0 and v7==0.0, return 0.0 (no intersection); otherwise when v6==0.0 swap the two axis term groups so the quadratic can be solved [source:raw]
    // CALCULATION: Quadratic coefficient: v12 = -(v7 / v6), then v13 = v17 * v12 + v22; return 0.0 when v13 == 0.0 [source:raw]
    // CALCULATION: Root computation: v14 = (v12 * v18 + v23) * (-1.0 / v13); return 0.0 when v24 == 0.0 [source:raw]
    // CALCULATION: Final offset term: v15 = (v22 * v14 + v23) * (-1.0 / v24) - a4 [source:raw]
    // CALCULATION: Magnitude: v16 = sqrt(v15*v15 + (v14 - a3)*(v14 - a3)) [source:raw]
    // RETURN: Return 0.0 when v16 == 0.0 (miss), otherwise return 1.0 / v16 as the penetration-length proxy [function:0x00401180, source:raw]
    // CALL: Invoked by VehicleSuspensionForceCalculation (00401340) to evaluate the ray-sphere penetration along the suspension travel axis [caller:0x00401340, source:raw]

    // Conservative worker pseudocode:
    //   v19 = a1*a1 + a2*a2;
    //   v18 = v19 - a3*a3 - a4*a4;
    //   v21 = a1 + a1; v17 = a3 + a3 - v21;
    //   v20 = a2 + a2; v6 = a4 + a4 - v20;
    //   v23 = v19 - a5*a5 - a6*a6;
    //   v22 = a5 + a5 - v21; v7 = a6 + a6 - v20;
    //   if (v6 == 0.0) {
    //     if (v7 == 0.0) return 0.0;
    //     swap the (v17,v22) and (v18,v23) and (v6,v7) term groups;
    //   }
    //   v12 = -(v7 / v6);
    //   v13 = v17 * v12 + v22;
    //   if (v13 == 0.0) return 0.0;
    //   v14 = (v12 * v18 + v23) * (-1.0 / v13);
    //   if (v24 == 0.0) return 0.0;
    //   v15 = (v22 * v14 + v23) * (-1.0 / v24) - a4;
    //   v16 = sqrt(v15*v15 + (v14 - a3)*(v14 - a3));
    //   if (v16 == 0.0) return 0.0;
    //   return 1.0 / v16;
    // UNRESOLVED: The roles of the six double inputs (a1..a6) are inferred from call context only and are not documented in this function
    // UNRESOLVED: Three read-only double globals (dbl_59E420, dbl_59E428, dbl_59E430) are flagged by packet facts but appear nowhere in the raw decompiled source; their role (possibly compiler-intrinsic support constants) is not verifiable here
}
