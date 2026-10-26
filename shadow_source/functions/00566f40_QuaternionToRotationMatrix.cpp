// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566F40
// Canonical corpus name: F_33RotationMatrixFromQuaternion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_33RotationMatrixFromQuaternion_00566f40.c

void UnknownObject::QuaternionToRotationMatrix()
{
    // Converts a unit quaternion (a1[0]=w, a1[1]=x, a1[2]=y, a1[3]=z) into a 3x3 row-major rotation matrix written to a2[0..8]. Pure computation with no branches: doubles each quaternion component, forms the pairwise products, and assembles the nine matrix elements with 1 - (xx/yy/zz) on the diagonal.
    // CALCULATION: double each quaternion component: xx2 = 2*a1[1], yy2 = 2*a1[2], zz2 = 2*a1[3] [source:raw]
    // CALCULATION: form pairwise intermediate products (yy, zz, zx, xy, xw, yw, xx, zw, yz) from the doubled components [source:raw]
    // ASSIGNMENT: a2[0] = 1.0 - (zz + yy) (matrix element m00) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: a2[1] = xy - zw (m01) [field:this:0x00000004, source:raw]
    // ASSIGNMENT: a2[2] = yw + zx (m02) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: a2[3] = zw + xy (m10) [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: a2[4] = 1.0 - (zz + xx) (m11) [field:this:0x00000010, source:raw]
    // ASSIGNMENT: a2[5] = zy - xw (m12) [field:this:0x00000014, source:raw]
    // ASSIGNMENT: a2[6] = zx - yw (m20) [field:this:0x00000018, source:raw]
    // ASSIGNMENT: a2[7] = zy + xw (m21) [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: a2[8] = 1.0 - (yy + xx) (m22) [field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   // a1: unit quaternion (w, x, y, z); a2: 3x3 row-major rotation matrix
    //   a2[0x0] = 1.0f - (zz + yy); a2[0x4] = xy - zw;  a2[0x8] = yw + zx;
    //   a2[0xC] = zw + xy;  a2[0x10] = 1.0f - (zz + xx); a2[0x14] = zy - xw;
    //   a2[0x18] = zx - yw; a2[0x1C] = zy + xw;  a2[0x20] = 1.0f - (yy + xx);
    // UNRESOLVED: Global flt_59E43C (0x0059E43C, physics constant per skeleton fill) is listed as a read global but no reference to it is visible in the raw decompiled source; its role in this function is unexplained.
}
