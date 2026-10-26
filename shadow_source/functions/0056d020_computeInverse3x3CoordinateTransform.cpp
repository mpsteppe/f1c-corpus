// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D020
// Canonical corpus name: F_3x3MatrixInverseCoordinateTransform
// Owner: MatrixTransformWorkspace [DERIVED]
// Raw source: functions/F_3x3MatrixInverseCoordinateTransform_0056d020.c

void MatrixTransformWorkspace::computeInverse3x3CoordinateTransform()
{
    // Computes a 3x3 inverse coordinate transform. Transforms two input vectors stored in the workspace buffer via Matrix3x3VectorMultiply, then assembles cofactor-based inverse matrix rows and applies additional matrix-vector products to build the inverse transform and transformed vectors in the result buffer (this+0x10). Used by the vehicle physics pipeline to transform forces/vectors between coordinate frames.
    // CALL: Matrix3x3VectorMultiply transforms the first input vector (workspace +24) by the matrix in the first block (block+28), storing the result at workspace +72. [callee:0x00435E00, field:this:0x00000004, field:this:0x00000008]
    // CALL: Matrix3x3VectorMultiply transforms the second input vector (workspace +48) by the same matrix, storing the result at workspace +96. [callee:0x00435E00, field:this:0x00000004, field:this:0x00000008]
    // CALCULATION: First three result-buffer doubles are assembled as dot products combining elements of the second matrix block (this+0xC) with the two transformed workspace vectors. [field:this:0x0000000C, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: Cross products and cofactor-based inverse matrix rows are computed into the result buffer (this+0x10): elements at this+0x28 through this+0x50 receive the cross-product/cofactor terms. [field:this:0x00000010, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, field:this:0x00000048, field:this:0x00000050, source:raw]
    // CALCULATION: Remaining result-buffer elements (this+0x58 through this+0x80) receive the additional matrix-vector products that complete the inverse transform columns. [field:this:0x00000010, field:this:0x00000058, field:this:0x00000060, field:this:0x00000068, field:this:0x00000070, field:this:0x00000078, field:this:0x00000080, source:raw]
    // RETURN: Function returns a pointer into the result buffer (this+0x10). [field:this:0x00000010, function:0x0056D020]

    // Conservative worker pseudocode:
    //   Matrix3x3VectorMultiply(this->m1 + 28, this->work + 24, this->work + 72);
    //   Matrix3x3VectorMultiply(this->m1 + 28, this->work + 48, this->work + 96);
    //   // assemble first result rows from matrix block 2 and transformed vectors
    //   // compute cross products and cofactor inverse rows into result buffer
    //   // apply remaining matrix-vector products
    //   return this->result;
    // UNRESOLVED: Mapping between individual source writes (result[0..14]) and the packet result-buffer field offsets (this+0x28..0x80) is not evidenced; fields are grouped by source region only.
    // UNRESOLVED: Roles of the header/padding fields at this+0x18 and this+0x20 (inside the pointed-to data blocks) are not attributable to any operation.
}
