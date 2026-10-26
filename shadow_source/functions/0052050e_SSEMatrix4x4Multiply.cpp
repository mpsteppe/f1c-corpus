// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052050E
// Canonical corpus name: SSEMatrix4x4Multiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEMatrix4x4Multiply_0052050e.c

void UnknownObject::SSEMatrix4x4Multiply()
{
    // SSE 4x4 matrix multiply. Loads the source matrix rows from a3 with _mm_loadh_ps/_mm_shuffle_ps, computes the matrix product rows through a chain of SSE multiplies, adds and transposes (shuffle masks 136/221/177/78), then reduces one row product to a scalar homogeneous term v35 (sum of all four lanes of v13*v30). If v35 is zero the function returns NULL; otherwise it optionally writes the integer bit pattern of v35 into *a2, computes a refined reciprocal 1/v35 (initial estimate plus one Newton-Raphson step), and stores the four product rows scaled by that reciprocal into a1 (a1..a1+7 in double units, i.e. a float[16] destination). Returns a1 on success. There is no external call: every __m128 intrinsic compiles to an SSE instruction, so the callee list is empty.
    // CALL: Loads source matrix rows from a3 (offsets a3+2, a3+3, a3+6, a3+7) via _mm_loadh_ps and combines them with _mm_shuffle_ps masks 136 and 221 into the four initial SSE vectors (v3..v15). [function:0x0052050E, source:raw]
    // CALCULATION: Builds the matrix product row vectors: element-wise _mm_mul_ps and _mm_add_ps/_mm_sub_ps chains (v16, v18, v21, v26, v30, v31, v41, v44, v45, v47, v50, v51, v52) with intermediate transpose shuffles (masks 177 and 78). [source:raw]
    // CALCULATION: Reduces the product to a scalar homogeneous term: v33 = v13 * v30, v34 = shuffle(v33,78) + v33, then v35 = shuffle(v34,177) with the low lane set to v34_low + v30_low. v35 equals the dot-product sum of all four lanes of v13*v30. [source:raw]
    // GUARD: If v35.m128_f32[0] == 0.0, returns 0 (NULL) to signal a singular/non-invertible result. [source:raw]
    // GUARD: Checks whether the optional output pointer a2 is non-NULL before writing to it. [source:raw]
    // ASSIGNMENT: When a2 is non-NULL, writes the integer bit pattern of v35 (v35.m128_i32[0]) into *a2. [source:raw]
    // CALCULATION: Computes 1/v35: v53 = 1.0 / v35, refined by one Newton-Raphson step v55 = (v53 + v53) - (v35 * (v53 * v53)), then broadcast across all lanes via v56 = shuffle(v55, 0). [source:raw]
    // ASSIGNMENT: Stores destination row 0: v57 = v61 * v56 written to a1 (storel) and a1+1 (storeh). [source:raw]
    // ASSIGNMENT: Stores destination row 1: v58 = v50 * v56 written to a1+2 (storel) and a1+3 (storeh). [source:raw]
    // ASSIGNMENT: Stores destination row 2: v59 = v71 * v56 written to a1+4 (storel) and a1+5 (storeh). [source:raw]
    // ASSIGNMENT: Stores destination row 3: v60 = v56 * v52 written to a1+6 (storel) and a1+7 (storeh). [source:raw]
    // RETURN: Returns a1 (the destination pointer) on success, or 0 (NULL) when the homogeneous term v35 was zero. [source:raw]

    // Conservative worker pseudocode:
    //   float* SSEMatrix4x4Multiply(float* dest, uint32* scaleOut, const float* src) {
    //       // SSE-only body: load src rows (src+2,+3,+6,+7), shuffle/transpose, and
    //       // build the four matrix-product rows via mul/add/sub chains (no calls).
    //       float h; // homogeneous term: sum of all four lanes of one row product
    //       if (h == 0.0f) return NULL;   // singular result
    //       if (scaleOut) *scaleOut = (uint32)h;   // integer bit pattern of h
    //       float rcp = h * refine;      // 1/h: initial estimate + Newton-Raphson step
    //       dest[0..3]  = productRow0 * rcp;
    //       dest[4..7]  = productRow1 * rcp;
    //       dest[8..11] = productRow2 * rcp;
    //       dest[12..15]= productRow3 * rcp;
    //       return dest;
    //   }
    // UNRESOLVED: Semantic meaning of the homogeneous term v35 and of the *a2 bit-pattern output (candidate: determinant or perspective w) is not derivable from this function alone.
    // UNRESOLVED: Only one matrix operand (a3) is loaded; no second explicit matrix operand is observed, so the exact operands and multiplication order of the product are unresolved.
    // UNRESOLVED: Row-major vs column-major layout of a1/a3 cannot be established from this function alone.
    // UNRESOLVED: Purpose of the fixed shuffle masks 136/221/177/78 (standard SSE transpose pattern) is inferred, not stated.
}
