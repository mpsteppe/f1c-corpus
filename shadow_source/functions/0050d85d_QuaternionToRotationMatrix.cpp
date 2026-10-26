// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D85D
// Canonical corpus name: QuaternionToRotationMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionToRotationMatrix_0050d85d.c

void UnknownObject::QuaternionToRotationMatrix()
{
    // Converts a unit quaternion (a2: x, y, z, w) into a 4x4 column-major rotation matrix (a1) using the standard formula R[i][j] built from 2x, 2y, 2z and the double products qx*qy, qx*qz, qy*qz, qx*qw, qy*qw, qz*qw. Translation row/column are zeroed and the bottom-right element is 1.0. Returns a1.
    // CALCULATION: Scale the quaternion components by 2: v13 = 2*x, v16 = 2*y, v3 = 2*z. [source:raw]
    // CALCULATION: Compute the double products with w: v4 = 2*x*w, v5 = 2*y*w, v6 = 2*z*w. [source:raw]
    // CALCULATION: Compute the pairwise double products of the vector part: v10 = 2*x*x, v14 = 2*y*x, v12 = 2*z*x, v11 = 2*y*y, v17 = 2*z*y, v7 = 2*z*z. [source:raw]
    // ASSIGNMENT: Row 0: a1[0] = 1 - 2*y*y - 2*z*z, a1[1] = 2*x*y + 2*z*w, a1[2] = 2*x*z - 2*y*w, a1[3] = 0.0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Row 1: a1[4] = 2*x*y - 2*z*w, a1[5] = 1 - 2*x*x - 2*z*z, a1[6] = 2*y*z + 2*x*w, a1[7] = 0.0. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // ASSIGNMENT: Row 2: a1[8] = 2*x*z + 2*y*w, a1[9] = 2*y*z - 2*x*w, a1[10] = 1 - 2*x*x - 2*y*y, a1[11] = 0.0. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Row 3: a1[12] = a1[13] = a1[14] = 0.0 and a1[15] = 1.0. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // RETURN: Return the output matrix pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_50D85D(float* out, float* q) {
    //     float x2 = 2*q[0], y2 = 2*q[1], z2 = 2*q[2], w = q[3];
    //     float xx = x2*q[0], yy = y2*q[1], zz = z2*q[2];
    //     float xy = y2*q[0], xz = z2*q[0], yz = z2*q[1];
    //     float xw = x2*w, yw = y2*w, zw = z2*w;
    //     out[0] = 1 - yy - zz; out[1] = xy + zw; out[2] = xz - yw; out[3] = 0;
    //     out[4] = xy - zw;     out[5] = 1 - xx - zz; out[6] = yz + xw; out[7] = 0;
    //     out[8] = xz + yw;     out[9] = yz - xw;     out[10] = 1 - xx - yy; out[11] = 0;
    //     out[12] = out[13] = out[14] = 0;  out[15] = 1;
    //     return out;
    //   }
    // UNRESOLVED: Global flt_59E800 (0x0059E800) is read but never named in the raw source; it is likely the compiler-materialised float constant 2.0 or 1.0 backing the scaling literals, value not grounded by the packet.
}
