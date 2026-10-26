// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DCB0
// Canonical corpus name: RotationMatrixFromAxisAndAngle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixFromAxisAndAngle_0050dcb0.c

void UnknownObject::RotationMatrixFromAxisAndAngle()
{
    // Builds a quaternion (x,y,z,w) from an axis derived from a2 and an angle a3. Calls ThunkTo() to resolve the axis components into locals v5/v6/v7, computes the half angle v9=a3*0.5, writes w (this+0xC) = cos(half), and scales each axis component by sin(half) for x (this+0x0), y (this+0x4), z (this+0x8), returning a1.
    // CALL: Call ThunkTo() to resolve the rotation-axis components from a2 into locals v5/v6/v7 (axis x/y/z). [callee:0x0050C2B3, source:raw]
    // CALCULATION: Compute the half angle v9 = a3 * 0.5. [source:raw]
    // ASSIGNMENT: Write the quaternion w component at this+0xC (a1[3]) = cos(v9). [field:this:0x0000000C, source:raw]
    // CALCULATION: Compute v10 = sin(v9). [source:raw]
    // ASSIGNMENT: Write the quaternion x component at this+0x0 (a1[0]) = v5 * v10 (axis_x * sin(half)). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the quaternion y component at this+0x4 (a1[1]) = v6 * v10 (axis_y * sin(half)). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the quaternion z component at this+0x8 (a1[2]) = v7 * v10 (axis_z * sin(half)). [field:this:0x00000008, source:raw]
    // RETURN: Return the output buffer pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float* RotationMatrixFromAxisAndAngle(float* a1, int a2, float a3) {
    //     float axis_x, axis_y, axis_z;
    //     ThunkTo(); /* resolves axis components from a2 into axis_x/axis_y/axis_z * /
    //     float half = a3 * 0.5f;
    //     a1[3] = cos(half);
    //     float s = sin(half);
    //     a1[0] = axis_x * s;
    //     a1[1] = axis_y * s;
    //     a1[2] = axis_z * s;
    //     return a1;
    //   }
    // UNRESOLVED: flt_59E450 is listed as a read global but does not appear in the raw body; it is a candidate DegreesToRadians scale applied to a3 before this function or inside the thunk.
    // UNRESOLVED: How ThunkTo() maps a2 to the axis components v5/v6/v7 is not visible in this function.
    // UNRESOLVED: The a2 axis-selection semantics and whether a3 is in degrees or radians are not grounded by the packet.
}
