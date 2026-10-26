// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051FB1E
// Canonical corpus name: QuaternionToRotationMatrix_fb1e
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionToRotationMatrix_fb1e_0051fb1e.c

void UnknownObject::QuaternionToRotationMatrix()
{
    // Converts a quaternion (a2) into a 4x4 rotation matrix (a1) using SSE intrinsics: loads the quaternion, extracts components with a bitmask, normalizes via Newton-Raphson refined inverse-sqrt, then builds the four matrix rows from scaled quaternion component products plus precomputed additive constants.
    // ASSIGNMENT: Load the low part of the quaternion input a2 into an SSE register (loadl_ps). [source:raw]
    // CALCULATION: Apply the bitmask xmmword_5D8BC0 to the loaded quaternion to extract the component values. [global:0x005D8BC0]
    // CALCULATION: Compute v8 as the sum of the squared quaternion components, then normalize with a Newton-Raphson-refined inverse square root using fsqrt and the constants dword_5D8BB0 (scale) and dword_5D8BA0 (subtractive coefficient). [global:0x005D8BB0, global:0x005D8BA0]
    // CALCULATION: Multiply the quaternion vector by the normalization scalar (shuffle 0) to produce the normalized component product vector v9. [source:raw]
    // CALCULATION: Scale the normalized products by xmmword_5D8B90 into v10. [global:0x005D8B90]
    // CALCULATION: Compute matrix row 0 from the component products plus the additive bias xmmword_5D8B80. [global:0x005D8B80]
    // CALCULATION: Compute matrix row 1 from the component products plus the additive constant xmmword_5D8B70. [global:0x005D8B70]
    // CALCULATION: Compute matrix row 2 from the component products plus the additive constant xmmword_5D8B60. [global:0x005D8B60]
    // CALCULATION: Compute matrix row 3 from the component products plus the additive constant xmmword_5D8B50. [global:0x005D8B50]
    // ASSIGNMENT: Store the four rows into the output matrix: a1[0] = row 0 (this+0x0), a1[1] = row 1 (this+0x10), a1[2] = row 2 (this+0x20), a1[3] = row 3 (this+0x30). [field:this:0x00000000, field:this:0x00000010, field:this:0x00000020, field:this:0x00000030]
    // RETURN: Return the output matrix pointer a1. [function:0x0051FB1E]

    // Conservative worker pseudocode:
    //   q = loadl_ps(a2) & xmmword_5D8BC0;
    //   v8 = sum_squares(q);
    //   inv_len = 1.0 / fsqrt(v8);
    //   inv_len = dword_5D8BB0 * inv_len * (dword_5D8BA0 - v8 * inv_len * inv_len);
    //   q = q * inv_len;
    //   p = xmmword_5D8B90 * q;
    //   a1[0] = add(p, shuffle(q,0), xmmword_5D8B80);
    //   a1[1] = add(p, shuffle(q,1), xmmword_5D8B70);
    //   a1[2] = add(p, shuffle(q,2), xmmword_5D8B60);
    //   a1[3] = add(p, shuffle(q,3), xmmword_5D8B50);
    // UNRESOLVED: The exact component-to-cell mapping of the shuffle patterns is only inferred; the per-matrix-cell assignment semantics beyond row grouping is not recoverable from this packet alone.
    // UNRESOLVED: The values held by the eight SSE constants (bitmask, scales, additive biases) live in read-only data and are not resolved here.
}
