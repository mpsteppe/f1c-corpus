// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052014E
// Canonical corpus name: SSE4x4Matrix4VectorMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSE4x4Matrix4VectorMultiply_0052014e.c

void UnknownObject::SSE4x4Matrix4VectorMultiply()
{
    // Multiplies a 4-component vector at a2 by a 4x4 matrix at a3 and stores the resulting 4-vector at a1. Matrix pointer alignment (a3 & 0xF) selects between unaligned 8-byte half-row loads and aligned __m128 row loads; both branches compute x*row0 + y*row1 + z*row2 + w*row3. Returns a1, the destination vector.
    // GUARD: Dispatch on matrix pointer alignment: when (a3 & 0xF) != 0 the matrix rows are loaded as 8-byte halves, otherwise rows are read as aligned 16-byte __m128 values at offsets 0, 16, 32, 48. [function:0x0052014E, source:raw]
    // CALCULATION: Broadcast each of the four source components from *a2 (shuffle immediates 0, 85, 170, 255 select x, y, z, w) and multiply each broadcast by the corresponding 16-byte matrix row. [source:raw]
    // CALCULATION: Sum the four row contributions to form the transformed vector: *a1 = x*row0 + y*row1 + z*row2 + w*row3. [source:raw]
    // ASSIGNMENT: Store the full 16-byte result 4-vector into *a1 at offset 0. [field:this:0x00000000, source:raw]
    // RETURN: Return a1, the destination vector pointer. [source:raw]
    // UNKNOWN: Legacy ABI name 'SSE_4x4_Matrix_4_Vector_Multiply' is retained as the identity signal for this entry; it does not claim an owner object. [abi:lead]

    // Conservative worker pseudocode:
    //   __m128* sub_52014E(__m128* dst, const __m128* src, const float* m) {
    //     if ((unsigned int)m & 0xF) { /* unaligned path: rows loaded as 8-byte halves * / }
    //     else { /* aligned path: rows loaded as __m128 at m+0, m+16, m+32, m+48 * / }
    //     *dst = src.x*m_row0 + src.y*m_row1 + src.z*m_row2 + src.w*m_row3;
    //     return dst;
    //   }
    // UNRESOLVED: Matrix memory layout and component order follow caller convention; the shuffle immediates fix component selection but not the semantic meaning of the four components.
    // UNRESOLVED: No w-divide or normalization is applied here; the 4-component result is written unchanged.
}
