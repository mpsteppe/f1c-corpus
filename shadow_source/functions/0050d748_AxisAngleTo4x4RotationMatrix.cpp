// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D748
// Canonical corpus name: AxisAngleTo4x4RotationMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AxisAngleTo4x4RotationMatrix_0050d748.c

void UnknownObject::AxisAngleTo4x4RotationMatrix()
{
    // Builds a 4x4 column-major rotation matrix (a1) from an axis vector (a2: x, y, z) and an angle a3 using the Rodrigues formula R = cos(a3)*I + (1 - cos(a3))*n*n^T + sin(a3)*[n]x, with translation row/column zeroed and bottom-right element = 1.0. Returns a1.
    // ASSIGNMENT: Compute v14 = cos(a3) and v13 = sin(a3) from the angle argument. [source:raw]
    // ASSIGNMENT: Read the three axis components a2[0..2] into v10, v11, v12 and compute v16 = 1.0 - cos(a3). [source:raw]
    // CALL: Call ThunkTo (0x0050C2B3) mid-function; its exact purpose (math helper or null thunk) is not resolvable from the packet. [callee:0x0050C2B3]
    // CALCULATION: Precompute scaled axis products: x*y*(1-c), y*z*(1-c), z*x*(1-c), x*sin, y*sin, z*sin for reuse in all matrix elements. [source:raw]
    // ASSIGNMENT: Row 0: a1[0] = x*x*(1-c) + c, a1[1] = x*y*(1-c) + z*sin, a1[2] = z*x*(1-c) - y*sin, a1[3] = 0.0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Row 1: a1[4] = x*y*(1-c) - z*sin, a1[5] = y*y*(1-c) + c, a1[6] = x*sin + y*z*(1-c), a1[7] = 0.0. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // ASSIGNMENT: Row 2: a1[8] = y*sin + z*x*(1-c), a1[9] = y*z*(1-c) - x*sin, a1[10] = z*z*(1-c) + c, a1[11] = 0.0. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Row 3: a1[12] = a1[13] = a1[14] = 0.0 and a1[15] = 1.0. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // RETURN: Return the output matrix pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_50D748(float* out, float* axis, float angle) {
    //     float c = cos(angle), s = sin(angle);
    //     float x = axis[0], y = axis[1], z = axis[2];
    //     float omc = 1.0f - c;
    //     float xy = x*y*omc, xz = x*z*omc, yz = y*z*omc;
    //     float xs = x*s, ys = y*s, zs = z*s;
    //     out[0] = x*x*omc + c;  out[1] = xy + zs; out[2] = xz - ys; out[3] = 0;
    //     out[4] = xy - zs;      out[5] = y*y*omc + c; out[6] = xs + yz; out[7] = 0;
    //     out[8] = ys + xz;      out[9] = yz - xs;      out[10] = z*z*omc + c; out[11] = 0;
    //     out[12] = out[13] = out[14] = 0;  out[15] = 1;
    //     return out;
    //   }
    // UNRESOLVED: Purpose of the ThunkTo call (0x0050C2B3) is unknown; the raw source does not explain what it computes.
    // UNRESOLVED: Row/column-major convention is inferred from the element arithmetic (Rodrigues formula), not named by the packet.
}
