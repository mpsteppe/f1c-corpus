// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F650
// Canonical corpus name: BilinearInterpolation_f650
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BilinearInterpolation_f650_0051f650.c

void UnknownObject::BilinearInterpolation()
{
    // Full 4-component vector blend: computes a2 + (a3 - a2) * broadcast(low element of a5) + (a4 - a2) * broadcast(low element of a6), stores the result into the first argument a1, and returns a1. The two scale values come from the low elements of a5 and a6 respectively.
    // CALCULATION: Load the four input vectors: base a2, sample a3, and sample a4. [source:raw]
    // CALCULATION: Compute the bilinear blend a2 + (a3 - a2) * broadcast(low element of a5) + (a4 - a2) * broadcast(low element of a6); the ABI name labels this a bilinear interpolation. [source:raw, abi:lead]
    // ASSIGNMENT: Store the blended 4-float result into the output vector *a1. [field:this:0x00000000]
    // RETURN: Return the output vector pointer a1. [function:0x0051F650]

    // Conservative worker pseudocode:
    //   __m128 *sub_51F650(__m128 *a1, __m128 *a2, __m128 *a3, __m128 *a4, unsigned int a5, unsigned int a6) {
    //     __m128 t1 = _mm_shuffle_ps((__m128)a5, (__m128)a5, 0);
    //     __m128 t2 = _mm_shuffle_ps((__m128)a6, (__m128)a6, 0);
    //     *a1 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(*a3, *a2), t1), *a2),
    //                      _mm_mul_ps(_mm_sub_ps(*a4, *a2), t2));
    //     return a1;
    //   }
    // UNRESOLVED: Whether the two scale operands are interpolation fractions, weights, or a blend factor plus an unrelated scalar is caller-dependent.
    // UNRESOLVED: Class/object ownership is unknown; only the output vector at offset +0 is evidenced.
}
