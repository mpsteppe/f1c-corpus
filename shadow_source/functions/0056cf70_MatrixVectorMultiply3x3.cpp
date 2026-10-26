// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056CF70
// Canonical corpus name: F_3x3MatrixVectorMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3x3MatrixVectorMultiply_0056cf70.c

void UnknownObject::MatrixVectorMultiply3x3()
{
    // Performs two independent 3x3 matrix-vector products in-place. For the first pair, reads the matrix block pointer from this[1] (this+0x4) and the vector buffer pointer from this[2] (this+0x8); the matrix data is the nine doubles starting at block+28 (with the double at +44 read as element [0][2]), and the three input components are buffer[0..2], with the result written to buffer[3..5]. The same product is then applied to the second pair from this[3] (this+0xC) and this[4] (this+0x10). Returns the second vector buffer pointer.
    // ASSIGNMENT: Load the first matrix block pointer from this[1] (this+0x4) and the first vector buffer pointer from this[2] (this+0x8). [field:this:0x00000004, field:this:0x00000008, function:0x0056CF70, source:raw]
    // CALCULATION: Apply the 3x3 matrix-vector product to the first pair: matrix data is the nine doubles at block+28 (the double at block+44 is used as matrix element [0][2]); each output component is the dot product of one matrix column with the input buffer[0..2], and the result is written to buffer[3], buffer[4], buffer[5]. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Load the second matrix block pointer from this[3] (this+0xC) and the second vector buffer pointer from this[4] (this+0x10). [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: Repeat the same 3x3 matrix-vector product on the second pair, writing the result to result[3], result[4], result[5] from input result[0..2]. [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: Return the second vector buffer pointer (this+0x10). [field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   double *sub_56CF70(_DWORD *this) {
    //     m = (double*)this[1]; v = (double*)this[2];
    //     v[3] = *(m+44) * v[2] + *(m+36) * v[1] + *(m+28) * v[0];
    //     v[4] = *(m+68) * v[2] + *(m+60) * v[1] + *(m+52) * v[0];
    //     v[5] = *(m+92) * v[2] + *(m+84) * v[1] + *(m+76) * v[0];
    //     m = (double*)this[3]; r = (double*)this[4];
    //     r[3] = *(m+44) * r[2] + *(m+36) * r[1] + *(m+28) * r[0];
    //     r[4] = *(m+68) * r[2] + *(m+60) * r[1] + *(m+52) * r[0];
    //     r[5] = *(m+92) * r[2] + *(m+84) * r[1] + *(m+76) * r[0];
    //     return r;
    //   }
    // UNRESOLVED: The eleven flattened buffer fields this+0x18/0x20/0x28/0x30/0x38/0x40/0x48/0x50/0x58/0x60/0x68 are pipeline-derived offsets into the pointed-to matrix/vector buffers; the raw source only dereferences through this[1..4], so their exact mapping to the header-plus-nine-doubles layout is not independently grounded.
    // UNRESOLVED: The column-major reading of the 3x3 product (output component n is the dot of matrix column n) is inferred from the index pattern in the raw source.
    // UNRESOLVED: The transform semantics (suspension/joint force transforms per callers VehiclePhysicsInitializer, VehiclePhysicsJointSystemLoader, BatchProcessingLoop3Passes) come from the callers, not from this packet.
}
