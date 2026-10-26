// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051FD90
// Canonical corpus name: RotationMatrixToAxisAngleConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixToAxisAngleConversion_0051fd90.c

void UnknownObject::RotationMatrixToAxisAngleConversion()
{
    // Converts a 3x3 rotation matrix (a2, float[9]) into a 4-component output (a1) holding a normalized axis and angle/quaternion scalar. Computes the matrix trace; when the trace exceeds the threshold flt_8D611C it uses the trace-based branch (scalar = sqrt(trace + flt_8D6120) * flt_8D6124 at a1[3], axis components from paired off-diagonal differences scaled by flt_8D6128 / scalar). Otherwise it selects the largest diagonal element via the dword_8D6110 index LUT and derives axis/angle from the corresponding off-diagonal sums and differences with constants flt_8D6130/flt_8D6134/flt_8D6138. No calls, no callees.
    // ASSIGNMENT: result = a1; return pointer is the output buffer. [source:raw]
    // CALCULATION: Compute matrix trace v3 = *a2 + a2[5] + a2[10] (sum of the three diagonal elements). [source:raw]
    // GUARD: Branch guard: if flt_8D611C < trace, take the trace-based conversion branch; otherwise fall through to the largest-diagonal branch. [global:0x008D611C, source:raw]
    // CALCULATION: Trace branch: v15 = sqrt(trace + flt_8D6120) * flt_8D6124 (scalar/angle magnitude). [global:0x008D6120, global:0x008D6124, source:raw]
    // CALCULATION: Trace branch: v16 = flt_8D6128 / v15 (axis scale factor). [global:0x008D6128, source:raw]
    // ASSIGNMENT: Trace branch: a1[3] = v15 stores the scalar/angle component at offset 0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Trace branch: a1[0] = (a2[6] - a2[9]) * v16; axis X from matrix off-diagonal difference. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Trace branch: a1[1] = (a2[8] - a2[2]) * v16; axis Y component. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Trace branch: a1[2] = v16 * (a2[1] - a2[4]); axis Z component. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Largest-diagonal branch: copy the three diagonal elements into local v17 (v17[0]=*a2, v17[1]=a2[5], v17[2]=a2[10]). [source:raw]
    // GUARD: Select v8 = index of the largest diagonal element: start with v8=2, compare v17[v5 > v4] against a2[10]; if less, set v8 = (v5 > v4). [source:raw]
    // CALCULATION: Look up LUT permutation: v9 = dword_8D6110[v8] and v10 = dword_8D6110[v9]. [global:0x008D6110, source:raw]
    // CALCULATION: Compute v12 = sqrt(flt_8D6130 + v17[v8] - v17[v9] - v17[v10]) * flt_8D6134 (scalar/angle from largest diagonal). [global:0x008D6130, global:0x008D6134, source:raw]
    // CALCULATION: Compute v13 = flt_8D6138 / v12 (axis scale factor). [global:0x008D6138, source:raw]
    // ASSIGNMENT: a1[v8] = v12 stores the scalar at the selected diagonal slot (offset 0x0/0x4/0x8). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: a1[v9] = (a2[4*v8 + v9] + a2[v8 + 4*v9]) * v13; axis component from summed off-diagonals. [source:raw]
    // ASSIGNMENT: a1[v10] = (a2[4*v8 + v10] + a2[v8 + 4*v10]) * v13; second axis component from summed off-diagonals. [source:raw]
    // ASSIGNMENT: a1[3] = v13 * (a2[4*v9 + v10] - a2[4*v10 + v9]) stores the sign-corrected scalar at offset 0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return the output buffer pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float *convert(float *out, const float *m) {
    //     float trace = m[0] + m[4] + m[8];
    //     if (flt_8D611C < trace) {
    //       float s = sqrt(trace + flt_8D6120) * flt_8D6124;
    //       float t = flt_8D6128 / s;
    //       out[3] = s;
    //       out[0] = (m[5] - m[7]) * t;
    //       out[1] = (m[6] - m[2]) * t;
    //       out[2] = (m[1] - m[3]) * t;
    //     } else {
    //       float diag[3] = { m[0], m[4], m[8] };
    //       int i = 2;
    //       if (diag[diag[1] > diag[0]] >= m[8]) i = (diag[1] > diag[0]);
    //       int j = dword_8D6110[i];
    //       int k = dword_8D6110[j];
    //       float s = sqrt(flt_8D6130 + diag[i] - diag[j] - diag[k]) * flt_8D6134;
    //       float t = flt_8D6138 / s;
    //       out[i] = s;
    //       out[j] = (m[4*i+j] + m[i+4*j]) * t;
    //       out[k] = (m[4*i+k] + m[i+4*k]) * t;
    //       out[3] = t * (m[4*j+k] - m[4*k+j]);
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Semantic reading of the 4-component output (strict axis-angle vs. quaternion w,x,y,z) is not determined by the packet; a1[3] holds the scalar and a1[0..2] the axis-like components.
    // UNRESOLVED: Concrete float values of flt_8D6120, flt_8D6124, flt_8D6128, flt_8D6130, flt_8D6134, flt_8D6138 (typically 1.0 / 0.5 / 1.0 / 1.0 / 0.5 / 1.0) are not decoded in the packet.
    // UNRESOLVED: dword_8D6110 LUT contents and the row-major/column-major layout of a2 are inferred from the algorithm, not verified in the packet.
}
