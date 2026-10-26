// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CBB6
// Canonical corpus name: F_4x4MatrixMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixMultiply_0050cbb6.c

void UnknownObject::F_4x4MatrixMultiply()
{
    // Multiplies two 4x4 float matrices (a2 * a3) and stores the row-major product into output a1. Each of the 16 output elements receives the dot product of one row of a2 with one column of a3. When output a1 aliases either input a2 or a3, the product is computed into a stack temporary (0x40 bytes) and copied back to a1 via qmemcpy. Returns the output pointer a1.
    // GUARD: If output pointer a1 aliases input a2 (a1 == a2) or input a3 (a1 == a3), compute the product into a stack temporary instead of writing directly into a1. [function:0x0050CBB6, source:raw]
    // ASSIGNMENT: Output element at offset 0x0 (row 0, col 0) receives a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a2[3]*a3[12]. [field:this:0x00000000]
    // ASSIGNMENT: Output element at offset 0x4 (row 0, col 1) receives the product-sum of row 0 of a2 with column 1 of a3. [field:this:0x00000004]
    // ASSIGNMENT: Output element at offset 0x8 (row 0, col 2) receives the product-sum of row 0 of a2 with column 2 of a3. [field:this:0x00000008]
    // ASSIGNMENT: Output element at offset 0xC (row 0, col 3) receives the product-sum of row 0 of a2 with column 3 of a3. [field:this:0x0000000C]
    // ASSIGNMENT: Output element at offset 0x10 (row 1, col 0) receives the product-sum of row 1 of a2 with column 0 of a3. [field:this:0x00000010]
    // ASSIGNMENT: Output element at offset 0x14 (row 1, col 1) receives the product-sum of row 1 of a2 with column 1 of a3. [field:this:0x00000014]
    // ASSIGNMENT: Output element at offset 0x18 (row 1, col 2) receives the product-sum of row 1 of a2 with column 2 of a3. [field:this:0x00000018]
    // ASSIGNMENT: Output element at offset 0x1C (row 1, col 3) receives the product-sum of row 1 of a2 with column 3 of a3. [field:this:0x0000001C]
    // ASSIGNMENT: Output element at offset 0x20 (row 2, col 0) receives the product-sum of row 2 of a2 with column 0 of a3. [field:this:0x00000020]
    // ASSIGNMENT: Output element at offset 0x24 (row 2, col 1) receives the product-sum of row 2 of a2 with column 1 of a3. [field:this:0x00000024]
    // ASSIGNMENT: Output element at offset 0x28 (row 2, col 2) receives the product-sum of row 2 of a2 with column 2 of a3. [field:this:0x00000028]
    // ASSIGNMENT: Output element at offset 0x2C (row 2, col 3) receives the product-sum of row 2 of a2 with column 3 of a3. [field:this:0x0000002C]
    // ASSIGNMENT: Output element at offset 0x30 (row 3, col 0) receives the product-sum of row 3 of a2 with column 0 of a3. [field:this:0x00000030]
    // ASSIGNMENT: Output element at offset 0x34 (row 3, col 1) receives the product-sum of row 3 of a2 with column 1 of a3. [field:this:0x00000034]
    // ASSIGNMENT: Output element at offset 0x38 (row 3, col 2) receives the product-sum of row 3 of a2 with column 2 of a3. [field:this:0x00000038]
    // ASSIGNMENT: Output element at offset 0x3C (row 3, col 3) receives the product-sum of row 3 of a2 with column 3 of a3. [field:this:0x0000003C]
    // ASSIGNMENT: When the product was computed into the stack temporary (alias case), copy 0x40 bytes back to output a1 with qmemcpy. [function:0x0050CBB6, source:raw]
    // RETURN: Return the output pointer a1. [function:0x0050CBB6, source:raw]

    // Conservative worker pseudocode:
    //   // C = A * B for two 4x4 float matrices (row-major): out[r][c] = sum_k A[r][k] * B[k][c].
    //   // Unrolled as 16 scalar product-sums. out may alias A or B.
    //   if (out == a || out == b)
    //       tmp = stack_scratch;      // 0x40 bytes
    //   else
    //       tmp = out;
    //   tmp[0]  = a[0]*b[0]  + a[1]*b[4]  + a[2]*b[8]  + a[3]*b[12];
    //   tmp[1]  = a[0]*b[1]  + a[1]*b[5]  + a[2]*b[9]  + a[3]*b[13];
    //   tmp[2]  = a[0]*b[2]  + a[1]*b[6]  + a[2]*b[10] + a[3]*b[14];
    //   tmp[3]  = a[0]*b[3]  + a[1]*b[7]  + a[2]*b[11] + a[3]*b[15];
    //   tmp[4]  = a[4]*b[0]  + a[5]*b[4]  + a[6]*b[8]  + a[7]*b[12];
    //   tmp[5]  = a[4]*b[1]  + a[5]*b[5]  + a[6]*b[9]  + a[7]*b[13];
    //   tmp[6]  = a[4]*b[2]  + a[5]*b[6]  + a[6]*b[10] + a[7]*b[14];
    //   tmp[7]  = a[4]*b[3]  + a[5]*b[7]  + a[6]*b[11] + a[7]*b[15];
    //   tmp[8]  = a[8]*b[0]  + a[9]*b[4]  + a[10]*b[8] + a[11]*b[12];
    //   tmp[9]  = a[8]*b[1]  + a[9]*b[5]  + a[10]*b[9] + a[11]*b[13];
    //   tmp[10] = a[8]*b[2]  + a[9]*b[6]  + a[10]*b[10]+ a[11]*b[14];
    //   tmp[11] = a[8]*b[3]  + a[9]*b[7]  + a[10]*b[11]+ a[11]*b[15];
    //   tmp[12] = a[12]*b[0] + a[13]*b[4] + a[14]*b[8] + a[15]*b[12];
    //   tmp[13] = a[12]*b[1] + a[13]*b[5] + a[14]*b[9] + a[15]*b[13];
    //   tmp[14] = a[12]*b[2] + a[13]*b[6] + a[14]*b[10]+ a[15]*b[14];
    //   tmp[15] = a[12]*b[3] + a[13]*b[7] + a[14]*b[11]+ a[15]*b[15];
    //   if (tmp != out)
    //       memcpy(out, tmp, 0x40);
    //   return out;
    // UNRESOLVED: Owner class of the three matrix pointers is unknown; there are no static callers in the packet.
    // UNRESOLVED: The stack temporary pointer is a scratch buffer only; it carries no semantic identity.
}
