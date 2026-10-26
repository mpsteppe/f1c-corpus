// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F0BE
// Canonical corpus name: SSE3DCrossProductWith33Matrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSE3DCrossProductWith33Matrix_0051f0be.c

void UnknownObject::SSE3DCrossProductWith33Matrix()
{
    // SSE-accelerated 3D vector math routine. Loads high-pair floats from three input pointers (a2, a3, a4), performs shuffle/multiply/subtract/add operations to form a cross-product-like result, applies a sign-flip XOR mask from xmmword_5D8A20, and stores the result into the __m128 output at a1.
    // ASSIGNMENT: Load high 64 bits of a3 and a2 and a4 via _mm_loadh_ps; shuffle variants v6, v9, v13, v14 prepare the three input rows for the multiplication network. [source:raw]
    // CALCULATION: Compute the cross-product term: v10 = shuffle(v9,57)*v6; v11 = v9*v6; v12 = v6*v8; then combine v13*(shuffle(v11,57)-shuffle(v12,78)) + (shuffle(v10,78)-v10)*v14 + shuffle(v14,57)*(v11-shuffle(v12,57)). [source:raw]
    // ASSIGNMENT: XOR the accumulated sum with xmmword_5D8A20 (sign-flip mask) and store the final __m128 into *a1. [field:this:0x00000000, global:0x005D8A20, source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   __m128 *SSE3DCrossProductWith33Matrix(a1, a2, a3, a4) {
    //     __m128 v5 = _mm_loadh_ps((const double *)(a3 + 8));
    //     __m128 v6 = _mm_shuffle_ps(v5, v5, 57);
    //     __m128 v7 = _mm_loadh_ps((const double *)(a2 + 8));
    //     __m128 v8 = _mm_loadh_ps((const double *)(a4 + 8));
    //     __m128 v9 = _mm_shuffle_ps(v8, v8, 78);
    //     __m128 v10 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 57), v6);
    //     __m128 v11 = _mm_mul_ps(v9, v6);
    //     __m128 v12 = _mm_mul_ps(v6, v8);
    //     __m128 v13 = _mm_shuffle_ps(v7, v7, 57);
    //     __m128 v14 = _mm_shuffle_ps(v13, v13, 57);
    //     *a1 = _mm_xor_ps(_mm_add_ps(_mm_add_ps(
    //       _mm_mul_ps(v13, _mm_sub_ps(_mm_shuffle_ps(v11, v11, 57), _mm_shuffle_ps(v12, v12, 78))),
    //       _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v10, v10, 78), v10), v14)),
    //       _mm_mul_ps(_mm_shuffle_ps(v14, v14, 57), _mm_sub_ps(v11, _mm_shuffle_ps(v12, v12, 57)))),
    //       (__m128)xmmword_5D8A20);
    //     return a1;
    //   }
    // UNRESOLVED: Vector semantics (cross product vs general 3x3 matrix product) asserted by canonical name and existing analysis but not proven by packet; input layout at a2/a3/a4 is 8-byte aligned pairs only.
    // UNRESOLVED: Mask value stored at xmmword_5D8A20 is not present in packet evidence.
    // UNRESOLVED: Owner type unknown; no class/vtable evidence.
}
