// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567030
// Canonical corpus name: QuaternionFromEulerAngles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionFromEulerAngles_00567030.c

void UnknownObject::QuaternionFromEulerAngles()
{
    // Converts three Euler angles in a1[0..2] into a quaternion written to a2[0..3] using the half-angle trigonometric construction. Computes cos/sin of each half angle, forms the four cos/sin cross products, and combines them into the w/x/y/z quaternion components. Marked by cluster_copy as a structural twin of EulerAnglesToQuaternion (0050dd40, DERIVED). Called by CollisionResponseFilter (004584c0) and AudioSampleCrossFadeInterpolation (004ff8f0).
    // CALCULATION: Half-angle trig of the first Euler angle: v2 = cos(a1[0]*0.5), v3 = sin(a1[0]*0.5) [field:this:0x00000000, source:raw]
    // CALCULATION: Half-angle trig of the second Euler angle: v4 = a1[1]*0.5, v5 = cos(v4), v6 = sin(v4) [field:this:0x00000004, source:raw]
    // CALCULATION: Half-angle trig of the third Euler angle: v7 = a1[2]*0.5, v12 = cos(v7), v14 = sin(v7) [field:this:0x00000008, source:raw]
    // CALCULATION: Form the cos/sin cross products: v10 = v12*v5, v8 = v14*v6, v11 = v8, v13 = v12*v6, v9 = v5*v14 [source:raw]
    // ASSIGNMENT: Compose quaternion components: a2[0] = v8*v3 + v10*v2, a2[1] = v10*v3 + v11*v2 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Compose quaternion components: a2[2] = v13*v2 - v9*v3, a2[3] = v9*v2 - v13*v3 [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Invoked by CollisionResponseFilter (004584c0) and AudioSampleCrossFadeInterpolation (004ff8f0) to produce an orientation quaternion from angles; clustered with EulerAnglesToQuaternion (0050dd40, DERIVED) [caller:0x004584C0, caller:0x004FF8F0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   v2 = cos(a1[0] * 0.5); v3 = sin(a1[0] * 0.5);
    //   v4 = a1[1] * 0.5; v5 = cos(v4); v6 = sin(v4);
    //   v7 = a1[2] * 0.5; v12 = cos(v7); v14 = sin(v7);
    //   v10 = v12 * v5; v8 = v14 * v6; v11 = v8;
    //   v13 = v12 * v6; v9 = v5 * v14;
    //   a2[0] = v8 * v3 + v10 * v2;
    //   a2[1] = v10 * v3 + v11 * v2;
    //   a2[2] = v13 * v2 - v9 * v3;
    //   a2[3] = v9 * v2 - v13 * v3;
    // UNRESOLVED: Read-only float global flt_59E450 (0x0059E450) is flagged by packet facts but appears nowhere in the raw decompiled source; its role is not verifiable here
    // UNRESOLVED: Euler angle ordering/convention is inferred from the half-angle construction pattern only
    // UNRESOLVED: The cluster_copy prelabel identifies 0050dd40 as a structural twin; the shared owner/class is not evidenced
}
