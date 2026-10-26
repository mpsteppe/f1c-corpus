// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CAD9
// Canonical corpus name: Mat4x4Determinant
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Mat4x4Determinant_0050cad9.c

void UnknownObject::Mat4x4Determinant()
{
    // Computes the determinant of a 4x4 matrix of floats using cofactor (Laplace) expansion along column 0. Reads all 16 elements as a flat array a1[0..15] (column-major per the leading name), computes six 2x2 sub-determinants over the trailing 3x3 block, combines them into four 3x3 cofactor minors, and returns the signed dot product with the first column. Pure read-only function, no calls, no branches, no globals.
    // CALCULATION: v2 = a1[10]*a1[15] - a1[14]*a1[11]; 2x2 minor over elements at offsets 0x28, 0x3C, 0x38, 0x2C [field:this:0x00000028, field:this:0x0000003C, field:this:0x00000038, field:this:0x0000002C]
    // CALCULATION: v3 = a1[15]*a1[9] - a1[13]*a1[11]; 2x2 minor over elements at offsets 0x3C, 0x24, 0x34, 0x2C [field:this:0x0000003C, field:this:0x00000024, field:this:0x00000034, field:this:0x0000002C]
    // CALCULATION: v4 = a1[14]*a1[9] - a1[10]*a1[13]; 2x2 minor over elements at offsets 0x38, 0x24, 0x28, 0x34 [field:this:0x00000038, field:this:0x00000024, field:this:0x00000028, field:this:0x00000034]
    // CALCULATION: v5 = a1[8]*a1[15] - a1[12]*a1[11]; 2x2 minor over elements at offsets 0x20, 0x3C, 0x30, 0x2C [field:this:0x00000020, field:this:0x0000003C, field:this:0x00000030, field:this:0x0000002C]
    // CALCULATION: v6 = a1[14]*a1[8] - a1[12]*a1[10]; 2x2 minor over elements at offsets 0x38, 0x20, 0x30, 0x28 [field:this:0x00000038, field:this:0x00000020, field:this:0x00000030, field:this:0x00000028]
    // CALCULATION: v8 = a1[8]*a1[13] - a1[12]*a1[9]; 2x2 minor over elements at offsets 0x20, 0x34, 0x30, 0x24 [field:this:0x00000020, field:this:0x00000034, field:this:0x00000030, field:this:0x00000024]
    // CALCULATION: cofactor term d0 = v2*a1[5] - v3*a1[6] + v4*a1[7]; 3x3 minor for a1[0] using elements at offsets 0x14, 0x18, 0x1C [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // CALCULATION: cofactor term d1 = v2*a1[4] - v5*a1[6] + v6*a1[7]; 3x3 minor for a1[1] using elements at offsets 0x10, 0x18, 0x1C [field:this:0x00000010, field:this:0x00000018, field:this:0x0000001C]
    // CALCULATION: cofactor term d2 = v3*a1[4] - v5*a1[5] + v8*a1[7]; 3x3 minor for a1[2] using elements at offsets 0x10, 0x14, 0x1C [field:this:0x00000010, field:this:0x00000014, field:this:0x0000001C]
    // CALCULATION: cofactor term d3 = v4*a1[4] - v6*a1[5] + v8*a1[6]; 3x3 minor for a1[3] using elements at offsets 0x10, 0x14, 0x18 [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018]
    // RETURN: return (d0*a1[0] - d1*a1[1] + d2*a1[2] - d3*a1[3]); signed cofactor expansion along column 0, reading first-column elements at offsets 0x0, 0x4, 0x8, 0xC; result widened to double [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]

    // Conservative worker pseudocode:
    //   double Mat4x4Determinant(float a1[16]) {
    //     double v2 = a1[10]*a1[15] - a1[14]*a1[11];
    //     double v3 = a1[15]*a1[9]  - a1[13]*a1[11];
    //     double v4 = a1[14]*a1[9]  - a1[10]*a1[13];
    //     double v5 = a1[8]*a1[15]  - a1[12]*a1[11];
    //     double v6 = a1[14]*a1[8]  - a1[12]*a1[10];
    //     double v8 = a1[8]*a1[13]  - a1[12]*a1[9];
    //     return ( v2*a1[5] - v3*a1[6] + v4*a1[7]) * a1[0]
    //          - ( v2*a1[4] - v5*a1[6] + v6*a1[7]) * a1[1]
    //          + ( v3*a1[4] - v5*a1[5] + v8*a1[7]) * a1[2]
    //          - ( v4*a1[4] - v6*a1[5] + v8*a1[6]) * a1[3];
    //   }
}
