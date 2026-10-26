// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E585
// Canonical corpus name: PlaneFromTriangle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlaneFromTriangle_0050e585.c

void UnknownObject::PlaneFromTriangle()
{
    // Math helper that builds a plane (normal + offset) from three triangle corner points. Treats a2 as the reference corner and a3/a4 as the other two: computes the cross product of the edge vectors (a2-a3) and (a2-a4) to form the plane normal, stores the three normal components into the output float[4] a1 (offsets 0, 4, 8), invokes ThunkTo, then writes the plane offset as -(dot(normal, a2)) into a1[3] (offset 0xC). Returns the output pointer a1. ABI name PlaneFromTriangle is LEGACY-trust; behavior matches that name structurally.
    // CALCULATION: v4 = a2[0] - a3[0]: first edge (a2-a3) x component [source:raw]
    // CALCULATION: v5 = a2[1] - a3[1]: first edge (a2-a3) y component [source:raw]
    // CALCULATION: v6 = a2[2] - a3[2]: first edge (a2-a3) z component [source:raw]
    // CALCULATION: v12 = a2[0] - a4[0]: second edge (a2-a4) x component [source:raw]
    // CALCULATION: v13 = a2[1] - a4[1]: second edge (a2-a4) y component [source:raw]
    // CALCULATION: v7 = a2[2] - a4[2]: second edge (a2-a4) z component [source:raw]
    // CALCULATION: v9 = v7*v5 - v13*v6: cross product x of (a2-a3) x (a2-a4), i.e. plane normal.x [source:raw]
    // CALCULATION: v10 = v6*v12 - v7*v4: cross product y of (a2-a3) x (a2-a4), i.e. plane normal.y [source:raw]
    // CALCULATION: v11 = v13*v4 - v12*v5: cross product z of (a2-a3) x (a2-a4), i.e. plane normal.z [source:raw]
    // ASSIGNMENT: a1[0] = v9: write plane normal.x into output offset 0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: a1[1] = v10: write plane normal.y into output offset 0x4 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: a1[2] = v11: write plane normal.z into output offset 0x8 [field:this:0x00000008, source:raw]
    // CALL: ThunkTo() invoked with no arguments between the normal writes and the offset computation [callee:0x0050C2B3, source:raw]
    // CALCULATION: a1[3] = -(a1[2]*a2[2] + a1[1]*a2[1] + a1[0]*a2[0]): plane offset = -dot(normal, a2), anchored at the reference corner; written into output offset 0xC [field:this:0x0000000C, source:raw]
    // RETURN: Returns the output pointer a1 (the completed plane float[4]) [source:raw]

    // Conservative worker pseudocode:
    //   float *PlaneFromTriangle(float *out, float *p2, float *p3, float *p4) {
    //     float e1x = p2[0] - p3[0];
    //     float e1y = p2[1] - p3[1];
    //     float e1z = p2[2] - p3[2];
    //     float e2x = p2[0] - p4[0];
    //     float e2y = p2[1] - p4[1];
    //     float e2z = p2[2] - p4[2];
    //     out[0] = e1y * e2z - e1z * e2y;
    //     out[1] = e1z * e2x - e1x * e2z;
    //     out[2] = e1x * e2y - e1y * e2x;
    //     ThunkTo();
    //     out[3] = -(out[2] * p2[2] + out[1] * p2[1] + out[0] * p2[0]);
    //     return out;
    //   }
    // UNRESOLVED: ThunkTo (0x0050C2B3) is called with no apparent arguments and its effect on the plane computation is unknown; it sits between the normal writes and the offset write, so it may be a null/nop thunk or may mutate registers the compiler keeps in live values
    // UNRESOLVED: The plane offset term is anchored at a2 (the reference corner) rather than one of the other corners; whether the triangle winding convention expects a specific corner ordering is not established
    // UNRESOLVED: Whether the returned normal is normalized or unit-scaled is not shown by this function; normalization, if any, must occur elsewhere
    // UNRESOLVED: Callers are unknown (packet lists none), so the calling context for this helper is unverified
}
