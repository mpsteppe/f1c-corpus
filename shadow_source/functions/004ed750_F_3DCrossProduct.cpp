// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED750
// Canonical corpus name: F_3DCrossProduct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DCrossProduct_004ed750.c

void UnknownObject::F_3DCrossProduct()
{
    // 3D vector cross product (fastcall): computes a1 x a2 and stores the three components into the output vector a3, returning a3. Component x = a2[2]*a1[1] - a2[1]*a1[2], y = a2[0]*a1[2] - a2[2]*a1[0], z = a2[1]*a1[0] - a2[0]*a1[1]. Pure math helper with no guards, globals or nested calls.
    // CALCULATION: Compute the x component of a1 x a2: v6 = a2[2]*a1[1] - a2[1]*a1[2]. [source:raw]
    // CALCULATION: Compute the y component of a1 x a2: v7 = a2[0]*a1[2] - a2[2]*a1[0]. [source:raw]
    // CALCULATION: Compute the z component of a1 x a2: v8 = (a2[1]*a1[0]) - (a2[0]*a1[1]). [source:raw]
    // ASSIGNMENT: Store the x component into the output vector: a3[0] = v6. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the y component into the output vector: a3[1] = v7. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the z component into the output vector: a3[2] = v8. [field:this:0x00000008, source:raw]
    // RETURN: Return the output vector pointer a3 (result). [source:raw]
    // CALL: Used by VehicleGeometryProximityTest (0x004ED420), sub_4EE2D0 (0x004EE2D0) and RayTriangleIntersectionWithBarycentricCoordinate (0x004EFBD0) for geometric cross products. [caller:0x004ED420, caller:0x004EE2D0, caller:0x004EFBD0, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_4ED750(float *a1, float *a2, float *a3) {
    //     a3[0] = a2[2]*a1[1] - a2[1]*a1[2];
    //     a3[1] = a2[0]*a1[2] - a2[2]*a1[0];
    //     a3[2] = a2[1]*a1[0] - a2[0]*a1[1];
    //     return a3;
    //   }
    // UNRESOLVED: The packet lists fields at this+0x0/0x4/0x8; in the raw source these are the three output-vector components a3[0..2], not members of an input class.
    // UNRESOLVED: Whether a1 x a2 is the intended operand order vs a2 x a1 is determined by callers; the source shows a1 x a2.
    // UNRESOLVED: caller 0x004EE2D0 has no semantic name in the packet.
}
