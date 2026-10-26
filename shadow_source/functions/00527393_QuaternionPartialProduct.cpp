// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00527393
// Canonical corpus name: sub_527393
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_527393_00527393.c

void UnknownObject::QuaternionPartialProduct()
{
    // Computes a partial quaternion product using 3DNow!/MMX intrinsics. Loads the low dword of the a3 second pair (v4), computes the packed product v5 = pfmul(a2[0], a3[0]), accumulates it with pfacc and adds a dot-product-like term from the low dwords of the a2/a3 second pairs to form v6. Copies the a3 first pair into a1[0], stores v4's low dword into a1[1].low, and stores the sign-flipped (negated, via XOR 0x80000000 backed by global qword_5AF978) value of v6 into a1[1].high. Clears MMX/3DNow state with _m_femms at entry and exit and returns the output pointer a1. Existing analysis (skeletons_filled) names it QuaternionPartialProduct.
    // CALL: Clear MMX/3DNow state via _m_femms before the arithmetic sequence. [source:raw]
    // CALCULATION: Load the low dword of the a3 second pair into v4 via _mm_cvtsi32_si64(a3[1].m64_u32[0]). [field:this:0x00000008, source:raw]
    // CALCULATION: Compute the packed product v5 = _m_pfmul(a2[0], a3[0]) of the two first component pairs. [field:this:0x00000000, source:raw]
    // CALCULATION: Accumulate v5 with pfacc and add the dot-product term _m_pfmul(_mm_cvtsi32_si64(a2[1].m64_u32[0]), v4) to form v6. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Copy the a3 first component pair into the output a1[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the low dword of v4 into the output second pair a1[1].m64_i32[0] via _mm_cvtsi64_si32. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store the negated value of v6 into a1[1].m64_i32[1] via _m_pxor(v6, 0x80000000) (single-float sign-flip constant backed by global qword_5AF978). [global:0x005AF978, field:this:0x00000008, source:raw]
    // CALL: Clear MMX/3DNow state via _m_femms after the arithmetic sequence. [source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x00527393, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   __m64 v4 = cvtsi32_si64(a3[1].low);
    //   __m64 v5 = a2[0] * a3[0];                 // packed product
    //   __m64 v6 = pfacc(v5) + cvtsi32_si64(a2[1].low) * v4;
    //   a1[0] = a3[0];                            // copy first pair
    //   a1[1].low = cvtsi64_si32(v4);
    //   a1[1].high = cvtsi64_si32(pxor(v6, 0x80000000)); // negated result
    //   femms();
    //   return a1;
    // UNRESOLVED: The binding of the immediate sign-flip 0x80000000 to global qword_5AF978 follows the existing analysis name MMX_QuatInitConst_AF978 [DERIVED] and is not stated in the raw source.
    // UNRESOLVED: The precise meaning of the partial product (which quaternion components the low-dword terms select) is not recoverable from this function alone.
    // UNRESOLVED: Owner is UNKNOWN; the packet carries no owner evidence and no static callers.
}
