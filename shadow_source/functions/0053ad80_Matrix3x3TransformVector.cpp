// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053AD80
// Canonical corpus name: F_3x3MatrixTransformVector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3x3MatrixTransformVector_0053ad80.c

void UnknownObject::Matrix3x3TransformVector()
{
    // SSE-accelerated 3x3 matrix x integer 3-vector transform. Loads the output-vector working buffer pointer from this+0x10 and the matrix-column buffer pointer from this+0x30, copies the three input vector components (a2) and the three matrix columns (a4[0..2]) into those buffers, then computes the transform as a sum of per-column dot products via SSE shuffle/mul/add. Stores the three resulting components to a3 and returns the first component.
    // ASSIGNMENT: Load the matrix-column buffer pointer from this+0x30 into v4 and the output-vector buffer pointer from this+0x10 into v7 [field:this:0x00000030, field:this:0x00000010]
    // ASSIGNMENT: Copy the three input vector components a2[0..2] into the vector working buffer at *(this+0x10) (+0x0, +0x4, +0x8) [field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004]
    // ASSIGNMENT: Copy the three matrix columns a4[0], a4[1], a4[2] into the matrix buffer at *(this+0x30) at offsets +0x0, +0x10, +0x20 [field:*(this+0x30):0x00000000, field:*(this+0x30):0x00000010, field:*(this+0x30):0x00000020]
    // CALCULATION: Matrix-vector product: result = shuffle(v7,0)*col0 + shuffle(v7,85)*col1 + shuffle(v7,170)*col2, broadcasting each vector component and summing the three column products with SSE add/mul [source:raw]
    // ASSIGNMENT: Store the three computed components of the transform result from the working buffer into output a3[0..2] [field:*(this+0x10):0x00000000, source:raw]
    // RETURN: Return the first transformed component (the value stored to a3[0]) [function:0x0053AD80, source:raw]

    // Conservative worker pseudocode:
    //   v4 = *(this + 0x30);
    //   v7 = *(this + 0x10);
    //   v7[0] = a2[0]; v7[1] = a2[1]; v7[2] = a2[2];
    //   v4[0] = a4[0]; v4[1] = a4[1]; v4[2] = a4[2];
    //   v7 = shuffle(v7,0)*v4[0] + shuffle(v7,85)*v4[1] + shuffle(v7,170)*v4[2];
    //   a3[0] = v7[0]; a3[1] = v7[1]; a3[2] = v7[2];
    //   return a3[0];
    // UNRESOLVED: The owning object holding the working buffers (this+0x10, this+0x30) is unidentified; owner is UNKNOWN
    // UNRESOLVED: The input vector is integer (a2 is __int32*) and the matrix columns are __m128; the exact float/integer interpretation boundary of the SSE transform is not documented by the packet
    // UNRESOLVED: Shuffle control constants 0, 85, 170 encode the component broadcast but their row/column ordering of the 3x3 matrix is DERIVED from the math, not stated in evidence
}
