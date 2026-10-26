// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005289E0
// Canonical corpus name: RGBAColorSpaceConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RGBAColorSpaceConversion_005289e0.c

void UnknownObject::RGBAColorSpaceDecode()
{
    // Decodes packed RGBA channel data with SSE SIMD: masks the four channels out of the input, dequantizes via a coefficient and bias, evaluates two polynomial approximations, and conditionally blends the two decode paths based on a zero-comparison before storing the result to a2 and a3.
    // ASSIGNMENT: Mask the packed input *a1 (this+0x0) against xmmword_5D9050 into v3 and against xmmword_5D9060 into v4, splitting the packed color into channel groups. [field:this:0x00000000, global:0x005D9050, global:0x005D9060]
    // CALCULATION: Dequantize: v6 = v4 * xmmword_5D9040 + xmmword_5D8FF0, then v7 = v6 - xmmword_5D8FF0 to strip the bias. [global:0x005D9040, global:0x005D8FF0]
    // CALCULATION: Compute the residual v10 = v4 minus the weighted sum of v7 against xmmword_5D9030, xmmword_5D9020, xmmword_5D9010, and xmmword_5D9000, then square it into v11 = v10 * v10. [global:0x005D9030, global:0x005D9020, global:0x005D9010, global:0x005D9000]
    // ASSIGNMENT: Extract lane state into the stack work area: *v5 = (v6 & xmmword_5D8FC0) & xmmword_5D8FB0, and v5[1] = v5[2] = v6 & xmmword_5D8FC0. [global:0x005D8FC0, global:0x005D8FB0]
    // CALCULATION: Pack each of the four 32-bit lanes: v5[1].i32[k] = (dword_5D8FA0 & (v5[1].i32[k] - v5[0].i32[k])) << 30, v5[2].i32[k] = (dword_5D8FA0 & (v5[0].i32[k] + v5[2].i32[k])) << 30, and the first lane shifted left by 30. [global:0x005D8FA0]
    // STATE_TRANSITION: Compare a stored intermediate lane against zero with _mm_cmpneq_ps to produce the blend mask v14 that selects between the two decode paths. [source:raw]
    // CALCULATION: Evaluate decode path A: v15 = (((v8 * v11 + xmmword_5D8F90) * v11 + xmmword_5D8F70) * v11 + xmmword_5D8F50) * v10, using xmmword_5D8FE0 as the leading coefficient. [global:0x005D8FE0, global:0x005D8F90, global:0x005D8F70, global:0x005D8F50]
    // CALCULATION: Evaluate decode path B: v16 = (((v9 * v11 + xmmword_5D8F80) * v11 + xmmword_5D8F60) * v11 + xmmword_5D8F40) * v11 + xmmword_5D8F30, using xmmword_5D8FD0 as the leading coefficient. [global:0x005D8FD0, global:0x005D8F80, global:0x005D8F60, global:0x005D8F40, global:0x005D8F30]
    // CALCULATION: Blend the two paths with the mask: v17 = andnot(v14, v15) | and(v14, v16), and v18 = xor(or(and(v14, v15), andnot(v14, v16)), a packed lane operand). [source:raw]
    // ASSIGNMENT: Combine the masked channels: *a2 = xor(v17, v13) where v13 is the masked input xor of a packed lane, and *a3 = v18; return the a2 pointer. [source:raw]
    // RETURN: Return the destination pointer a2 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   v3 = a1[0] & mask_5D9050; v4 = a1[0] & mask_5D9060;
    //   v6 = v4 * coeff_5D9040 + bias_5D8FF0; v7 = v6 - bias_5D8FF0;
    //   v10 = v4 - v7 * (5D9030 + 5D9020 + 5D9010 + 5D9000); v11 = v10 * v10;
    //   lane-pack from v6 via 5D8FC0/5D8FB0 and dword_5D8FA0 with 30-bit shifts;
    //   v14 = cmpneq(packed_lane, 0);
    //   v15 = polyA(v11, v10, 5D8FE0/5D8F90/5D8F70/5D8F50); v16 = polyB(v11, 5D8FD0/5D8F80/5D8F60/5D8F40/5D8F30);
    //   *a2 = (v14 ? v16 : v15) xor packed; *a3 = xor(or(and(v14,v15),andnot(v14,v16)), packed); return a2;
    // UNRESOLVED: The exact semantic role of each xmm constant (dequantization coefficients vs polynomial coefficients) is only DERIVED from the surrounding operations; the constants themselves carry no names in the packet.
    // UNRESOLVED: Which packed lane feeds the zero-comparison (v14) and the final XOR operands is ambiguous in the decompiler output due to stack-aliased __m128 temporaries.
    // UNRESOLVED: The caller QuaternionConstructionTransform (0051febe) is the only known caller, but the meaning of the a3 output channel is unknown.
}
