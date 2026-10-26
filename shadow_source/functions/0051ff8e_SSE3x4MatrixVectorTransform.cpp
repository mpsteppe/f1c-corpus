// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051FF8E
// Canonical corpus name: SSE3x4MatrixVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSE3x4MatrixVectorTransform_0051ff8e.c

void UnknownObject::SSE3x4MatrixVectorTransform()
{
    // Transforms a 3-component source vector at a2 through a 3x4 matrix at a3 and stores the resulting 3-component vector at a1. Matrix pointer alignment (a3 & 0xF) selects between unaligned 8-byte half-row loads and aligned __m128 row loads; both branches compute the same x*row0 + y*row1 + z*row2 combination. Returns a1, the destination vector.
    // GUARD: Dispatch on matrix pointer alignment: when (a3 & 0xF) != 0 the matrix rows are loaded as 8-byte halves, otherwise rows are read as aligned 16-byte __m128 values at offsets 0, 16, 32. [function:0x0051FF8E, source:raw]
    // CALCULATION: Broadcast each source component from a2 (x and y from the low 8 bytes, z from offset 8) and multiply each broadcast by the corresponding 16-byte matrix row to build the three row contributions. [source:raw]
    // CALCULATION: Sum the three row contributions to form the transformed vector: x*row0 + y*row1 + z*row2. [source:raw]
    // ASSIGNMENT: Write the result to a1: the low 8 bytes hold the first two components and the upper 4 bytes at a1+8 hold the third component. [field:this:0x00000008, source:raw]
    // RETURN: Return a1, the destination vector pointer. [source:raw]
    // UNKNOWN: Legacy ABI name 'SSE_3x4_Matrix_Vector_Transform' is retained as the identity signal for this entry; it does not claim an owner object. [abi:lead]

    // Conservative worker pseudocode:
    //   float* sub_51FF8E(float* dst, const float* src, const float* m) {
    //     if ((unsigned int)m & 0xF) { /* unaligned path: rows loaded as 8-byte halves * / }
    //     else { /* aligned path: rows loaded as __m128 at m+0, m+16, m+32 * / }
    //     /* result = x*row0 + y*row1 + z*row2; first two components to dst[0..1], third to dst[2] * /
    //     return dst;
    //   }
    // UNRESOLVED: Exact lane and component layout of the SIMD loads depends on the decompiler's representation; component selection inferred from the shuffle immediates.
    // UNRESOLVED: Whether the 3x4 matrix rows encode rotation, scaling, or both is caller-defined; no translation row is added here.
}
