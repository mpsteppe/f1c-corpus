// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005214AA
// Canonical corpus name: QuaternionMul3DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionMul3DNow_005214aa.c

void UnknownObject::QuaternionMul3DNow()
{
    // Multiplies two quaternions supplied as 3DNow! __m64 operand pairs (a2, a3) using packed floating-point intrinsics. Both operands are pre-scaled by the 0.5 constant 0x3F0000003F000000 (matching qword_5AF980), PackedFloatingPointMath is called three times for component setup, then the quaternion product is assembled with pfmul/pfadd and sign-flip XOR against 0x8000000000000000 (matching qword_5AF990). Writes the two __m64 halves of the result to a1[0] and a1[1]. MMX state is cleared with _m_femms before and after.
    // CALL: Clear MMX/3DNow state via _m_femms before the arithmetic sequence. [source:raw]
    // CALCULATION: Pre-scale the first quaternion operand a2 by the 0.5 constant 0x3F0000003F000000 (qword_5AF980) into v9. [source:raw, global:0x005AF980]
    // CALL: Call PackedFloatingPointMath three times for packed-component setup/expansion of the intermediate vectors. [callee:0x005295E0]
    // CALCULATION: Pre-scale the second quaternion operand a3 by the 0.5 constant 0x3F0000003F000000 (qword_5AF980) into v3. [source:raw, global:0x005AF980]
    // CALCULATION: Unpack and shuffle v9/v3 to build the per-component temporaries v5, v6, v7, v8 used by the product. [source:raw]
    // CALCULATION: Assemble the first product term by multiplying permuted components and applying the sign-flip XOR constant 0x8000000000000000 (qword_5AF990), then add the cross terms. [source:raw, global:0x005AF990]
    // ASSIGNMENT: Store the first 64-bit half of the quaternion product into a1 at offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Store the second 64-bit half of the quaternion product into a1 at offset 0x8. [field:this:0x00000008]
    // CALL: Clear MMX/3DNow state via _m_femms after the arithmetic sequence. [source:raw]
    // RETURN: Return the output buffer pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   v9 = a2 * 0.5;  // 0x3F0000003F000000
    //   PackedFloatingPointMath(); PachedFloatingPointMath(); PackedFloatingPointMath();
    //   v3 = a3 * 0.5;  // 0x3F0000003F000000
    //   a1[0] = quaternion_product_half(v9, v3, sign_mask);
    //   a1[1] = quaternion_product_half(v9, v3, sign_mask);
    //   femms();
    //   return a1;
    // UNRESOLVED: The split between globals qword_5AF980 and qword_5AF990 and the raw immediates is ambiguous: the raw source uses literals (0x3F0000003F000000, 0x8000000000000000) while deterministic facts list two read globals; the exact global-to-literal binding is DERIVED, not verified.
    // UNRESOLVED: Which packed lanes correspond to w/x/y/z of each quaternion half is not recoverable from this function alone.
    // UNRESOLVED: Owner is UNKNOWN; no static callers identify the containing object.
}
