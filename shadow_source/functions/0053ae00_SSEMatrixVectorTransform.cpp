// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053AE00
// Canonical corpus name: SSEMatrixVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEMatrixVectorTransform_0053ae00.c

void UnknownObject::SSEMatrixVectorTransform()
{
    // SSE-accelerated 4x4 matrix transform of a single 3-component integer vector with an implicit w=1. Copies the four __m128 matrix columns from argument a4 into the column buffer at *(this+0x30) and the three input components plus the constant 1065353216 (1.0f) into the working vector buffer at *(this+0x10), then computes the full four-component dot product per column via SSE shuffle/multiply/add and stores the three transformed integer components to a3. Straight-line, no branches, no calls.
    // ASSIGNMENT: Loads the matrix column buffer pointer from the this+0x30 slot (*(this+0x30)) [field:this:0x00000030]
    // ASSIGNMENT: Copies all four __m128 matrix columns from argument a4 into the column buffer at *(this+0x30), columns at +0x0/+0x10/+0x20/+0x30 [field:*(this+0x30):0x00000000, field:*(this+0x30):0x00000010, field:*(this+0x30):0x00000020, field:*(this+0x30):0x00000030]
    // ASSIGNMENT: Loads the working vector buffer pointer from the this+0x10 slot (*(this+0x10)) [field:this:0x00000010]
    // ASSIGNMENT: Copies the three input components from a2 into the working buffer (X at +0x0, Y at +0x4) and forces the fourth component to 1065353216 (1.0f as float), supplying the affine w term [field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004]
    // CALCULATION: Computes the 4x4 matrix-vector product: each output component is the sum over the four matrix columns of (shuffled working-buffer component x matrix column), implemented with _mm_shuffle_ps / _mm_mul_ps / _mm_add_ps over *(this+0x30) [field:*(this+0x10):0x00000000, field:*(this+0x30):0x00000000, source:raw]
    // ASSIGNMENT: Stores the three transformed integer components from the working buffer into a3 (a3[0], a3[1], a3[2]) [field:*(this+0x10):0x00000000, source:raw]
    // RETURN: Returns the first transformed component (the X value) [function:0x0053AE00, source:raw]

    // Conservative worker pseudocode:
    //   columns = *(this + 0x30);
    //   for (i = 0; i < 4; ++i) columns[i] = a4[i];
    //   buf = *(this + 0x10);
    //   buf->i32 = { a2[0], a2[1], a2[2], 1065353216 };
    //   out = SSE 4-column dot product of buf against columns;
    //   a3[0] = out[0]; a3[1] = out[1]; a3[2] = out[2];
    //   return out[0];
    // UNRESOLVED: The working vector buffer slot *(this+0x10):0x4 is packet-flagged read-only while the decompiled source both reads and writes the Y component through it; the slot's ownership intent is unresolved
    // UNRESOLVED: Matrix and vector buffers are reached only through the this+0x10 and this+0x30 pointer slots; the owning class layout and why the transform is split across two buffers is not established
}
