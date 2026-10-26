// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052466C
// Canonical corpus name: MMXPackedFloatingPointSIMDMath
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MMXPackedFloatingPointSIMDMath_0052466c.c

void UnknownObject::composeCompositeTransformMatrixMMX()
{
    // MMX/3DNow!-intrinsic composition of a 4x4 transformation matrix from up to six optional packed-float inputs, structurally a twin of F_3DNowMatrixVectorMath (00522ce2) but using _m_pswapd/_m_pfpnacc where the twin uses plain punpck. Reads rotation/axis data from a3/a4, optionally applies translation from a2, optionally post-multiplies an a6 rotation and subtracts an a5 translation, then optionally adds an a7 translation; every null input falls back to an identity component. Returns the output matrix pointer a1. The LEGACY ABI lead names it MMX_Packed_Floating_Point_SIMD_Math.
    // GUARD: If a4 is null, no rotation source exists: initialize the output to identity. [source:raw]
    // ASSIGNMENT: Identity fallback: write a1[0] = 1.0f (0x3F800000), a1[1] = 0, a1[2] = packed 1.0/1.0, a1[3] = 0, a1[4] = 0, a1[5] = 1.0f, a1[6] = 0, a1[7] = packed 1.0/1.0, filling every output matrix slot. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // GUARD: If a4 is present but a3 is null, build a rotation matrix from a4 alone: a1[0] = a4[0] low half, a1[2] = a4[0] high half, a1[5] = a4[1] low float, a1[7] = 0x3F80000000000000 (packed 1.0/1.0), with the remaining slots zeroed. [source:raw]
    // GUARD: If both a4 and a3 are present, build the full 3x3 inverse rotation from the a3/a4 packed data. [source:raw]
    // CALCULATION: Compute the inverse-rotation products from a3/a4 using pfadd, pfmul, pfsub/pfsubr, pfpnacc and pswapd intrinsics against the packed constant 0x3F8000003F800000 (1.0/1.0) and 1065353216 (1.0f), staging the rotation row components into stack buffers v367..v391. [source:raw]
    // CALCULATION: The packet's fact table flags three read-only globals as read by this function (qword_5AF8E0, qword_5AF8F0, qword_5AF900); the raw decompilation renders their values as inline literals (0x3F800000 identity, 0x3F8000003F800000 packed 1.0/1.0, 1065353216), so the exact global-to-constant mapping is not established. [global:0x005AF8E0, global:0x005AF8F0, global:0x005AF900, source:raw]
    // GUARD: Inside the a3/a4 rotation path: if a2 is non-null, apply a2 as a translation and compose the full matrix. [source:raw]
    // ASSIGNMENT: a2-present path: stage identity+translation from a2 (a1[0]=1.0f, a1[1]=0, a1[2]=packed 1.0/1.0, a1[5]=1.0f, a1[6]=-a2[0], a1[7]=packed (1.0f - a2[1])), then read back matrix rows a1[0..7] while accumulating the 4x4 multiply into every output slot. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // ASSIGNMENT: a2-null path: store the pure rotation matrix rows a1[0..7] (translation and homogeneous slots left as the rotation-composed values). [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // GUARD: If a6 is non-null, post-multiply the accumulated matrix by a second rotation built from a6. [source:raw]
    // CALCULATION: Build the a6 rotation using the same inverse-rotation product sequence (pfadd, pfmul, pfsubr, pfpnacc, pswapd against 0x3F8000003F800000, 1065353216) staged in stack buffers v371..v383. [source:raw]
    // GUARD: Inside the a6 path: if a5 is non-null, subtract a5 as a translation before composing. [source:raw]
    // ASSIGNMENT: a5-present path: subtract a5 from the output translation slots (result[6] -= a5[0], result[7].low-int32 -= a5[1] float), then accumulate the 4x4 multiply across the output matrix rows. [field:this:0x00000030, field:this:0x00000038, source:raw]
    // ASSIGNMENT: a5-null path: compose the a6 rotation into the output matrix rows without a translation adjustment. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // GUARD: If a7 is non-null, add a7 as a final translation. [source:raw]
    // ASSIGNMENT: Add a7 into the output translation slots: result[6] += a7[0] and result[7].low-int32 += a7[1] float. [field:this:0x00000030, field:this:0x00000038, source:raw]
    // RETURN: Execute _m_femms() to exit MMX state and return the output matrix pointer a1. [function:0x0052466C, source:raw]

    // Conservative worker pseudocode:
    //   if (a4) {
    //     if (a3) { build_inverse_rotation_from(a3, a4);
    //       if (a2) { compose_translation(a2); compose_full_matrix(); }
    //       else { store_rotation_only(); } }
    //     else { build_axis_rotation_from(a4); }
    //   } else { identity_matrix(); }
    //   if (a6) { build_rotation_from(a6);
    //     if (a5) { subtract_translation(a5); compose(); }
    //     else { compose(); } }
    //   if (a7) { add_translation(a7); }
    //   _m_femms(); return a1;
    // UNRESOLVED: The three read-only globals (qword_5AF8E0, qword_5AF8F0, qword_5AF900) are flagged by the packet as read but do not appear by name in the raw decompiled source (constants render inline); their exact mapping to the literals 0x3F800000 / 0x3F8000003F800000 / 1065353216 is not established.
    // UNRESOLVED: The structural-twin relationship to 00522ce2 (cluster_copy prelabel, DERIVED) is grounded in control-flow shape, not in verified identity of the packed-float semantics.
    // UNRESOLVED: The claimed 3x3 inverse-rotation interpretation of the a3 path is carried from the twin's existing analysis; the packed-float semantics of a3/a4 as axis-vs-quaternion are unconfirmed.
    // UNRESOLVED: The owner object is not established; the LEGACY ABI name MMX_Packed_Floating_Point_SIMD_Math is not independent evidence of ownership, and the function has no static callers or callees.
    // UNRESOLVED: The translation slots this+0x30/0x38 double as homogeneous-row storage; the exact layout of the 4x4 matrix in row-major packed pairs is inferred, not verified.
}
