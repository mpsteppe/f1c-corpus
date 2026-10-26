// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CE79
// Canonical corpus name: Matrix4x4Multiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Matrix4x4Multiply_0050ce79.c

void UnknownObject::Matrix4x4Multiply()
{
    // Multiplies two 4x4 matrices stored as float[16] arrays (a2 and a3), writing the 16-element product into a1 and returning a1. If a1 aliases either operand, the product is computed into a temporary stack buffer and copied back into a1 (0x40 bytes) afterward, making the call safe for in-place use.
    // GUARD: If the destination a1 aliases either operand (a1 == a2 or a1 == a3), redirect all output writes to a stack temporary buffer instead of the destination. [function:0x0050CE79, source:raw]
    // CALCULATION: Compute the 4x4 matrix product; each of the 16 output elements is the dot product of one row of a2 with one column of a3 (or the equivalent column-major/operand-order variant of the same multiply). [function:0x0050CE79, source:raw]
    // ASSIGNMENT: Write output matrix element at this+0x0: dot product of a2 row terms with a3 column terms. [field:this:0x00000000]
    // ASSIGNMENT: Write output matrix element at this+0x4: dot product of a2 row terms with a3 column terms. [field:this:0x00000004]
    // ASSIGNMENT: Write output matrix element at this+0x8: dot product of a2 row terms with a3 column terms. [field:this:0x00000008]
    // ASSIGNMENT: Write output matrix element at this+0xC: dot product of a2 row terms with a3 column terms. [field:this:0x0000000C]
    // ASSIGNMENT: Write output matrix element at this+0x10: dot product of a2 row terms with a3 column terms. [field:this:0x00000010]
    // ASSIGNMENT: Write output matrix element at this+0x14: dot product of a2 row terms with a3 column terms. [field:this:0x00000014]
    // ASSIGNMENT: Write output matrix element at this+0x18: dot product of a2 row terms with a3 column terms. [field:this:0x00000018]
    // ASSIGNMENT: Write output matrix element at this+0x1C: dot product of a2 row terms with a3 column terms. [field:this:0x0000001C]
    // ASSIGNMENT: Write output matrix element at this+0x20: dot product of a2 row terms with a3 column terms. [field:this:0x00000020]
    // ASSIGNMENT: Write output matrix element at this+0x24: dot product of a2 row terms with a3 column terms. [field:this:0x00000024]
    // ASSIGNMENT: Write output matrix element at this+0x28: dot product of a2 row terms with a3 column terms. [field:this:0x00000028]
    // ASSIGNMENT: Write output matrix element at this+0x2C: dot product of a2 row terms with a3 column terms. [field:this:0x0000002C]
    // ASSIGNMENT: Write output matrix element at this+0x30: dot product of a2 row terms with a3 column terms. [field:this:0x00000030]
    // ASSIGNMENT: Write output matrix element at this+0x34: dot product of a2 row terms with a3 column terms. [field:this:0x00000034]
    // ASSIGNMENT: Write output matrix element at this+0x38: dot product of a2 row terms with a3 column terms. [field:this:0x00000038]
    // ASSIGNMENT: Write output matrix element at this+0x3C: dot product of a2 row terms with a3 column terms. [field:this:0x0000003C]
    // ASSIGNMENT: If the destination was redirected to the temp buffer, copy 64 bytes (0x40) from the buffer back into a1. [function:0x0050CE79, source:raw]
    // RETURN: Return a1, the output matrix pointer (ABI lead name Matrix4x4Multiply). [abi:lead, function:0x0050CE79]

    // Conservative worker pseudocode:
    //   float *dest = a1;
    //   if (a1 == a2 || a1 == a3) dest = temp_buffer;
    //   dest[0]  = a2[3]*a3[12] + a2[0]*a3[0] + a2[2]*a3[8] + a3[4]*a2[1];
    //   dest[1]  = a2[4]*a3[0] + a3[12]*a2[7] + a3[8]*a2[6] + a3[4]*a2[5];
    //   dest[2]  = a2[10]*a3[8] + a2[9]*a3[4] + a3[12]*a2[11] + a2[8]*a3[0];
    //   dest[3]  = a2[13]*a3[4] + a2[15]*a3[12] + a3[0]*a2[12] + a2[14]*a3[8];
    //   dest[4]  = a3[9]*a2[2] + a3[1]*a2[0] + a3[13]*a2[3] + a2[1]*a3[5];
    //   dest[5]  = a3[13]*a2[7] + a3[9]*a2[6] + a2[5]*a3[5] + a2[4]*a3[1];
    //   dest[6]  = a2[9]*a3[5] + a3[13]*a2[11] + a3[9]*a2[10] + a2[8]*a3[1];
    //   dest[7]  = a2[13]*a3[5] + a3[13]*a2[15] + a3[9]*a2[14] + a3[1]*a2[12];
    //   dest[8]  = a3[10]*a2[2] + a3[2]*a2[0] + a2[1]*a3[6] + a3[14]*a2[3];
    //   dest[9]  = a3[14]*a2[7] + a3[10]*a2[6] + a2[5]*a3[6] + a2[4]*a3[2];
    //   dest[10] = a2[9]*a3[6] + a3[14]*a2[11] + a3[10]*a2[10] + a2[8]*a3[2];
    //   dest[11] = a2[13]*a3[6] + a3[14]*a2[15] + a3[10]*a2[14] + a3[2]*a2[12];
    //   dest[12] = a3[11]*a2[2] + a3[3]*a2[0] + a2[1]*a3[7] + a3[15]*a2[3];
    //   dest[13] = a3[15]*a2[7] + a3[11]*a2[6] + a2[5]*a3[7] + a2[4]*a3[3];
    //   dest[14] = a2[9]*a3[7] + a3[15]*a2[11] + a3[11]*a2[10] + a2[8]*a3[3];
    //   dest[15] = a2[13]*a3[7] + a3[15]*a2[15] + a3[11]*a2[14] + a3[3]*a2[12];
    //   if (dest != a1) memcpy(a1, dest, 0x40);
    //   return a1;
    // UNRESOLVED: Storage layout (row-major vs column-major) of the float[16] matrices is not established from the packet alone.
    // UNRESOLVED: Whether the multiply is a2*a3 or a3*a2 depends on the unresolved layout convention; only the dot-product structure is established.
    // UNRESOLVED: No callers or callees are recorded in the packet, so no caller-arg context exists to pin the operand roles.
}
