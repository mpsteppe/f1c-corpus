// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00523E7A
// Canonical corpus name: F_3DNowPackedFloatMatrixQuaternionOps
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowPackedFloatMatrixQuaternionOps_00523e7a.c

void UnknownObject::F_3DNowPackedFloatMatrixQuaternionOps()
{
    // Multiplies two packed-float quaternion operands a2 and a3 and converts the product to a 4x4 rotation matrix in the output __m64 buffer a1. Both inputs are scaled by 0.5 via _m_pfmul with the packed constant 0x3F0000003F000000 (global 0x005AF900), then multiplied using 3DNow! shuffles (punpck*), sign flips (pxor 0x8000000000000000, global 0x005AF920) and pfadd/pfmul accumulation. The product is converted to a matrix with the cofactor/adjugate pattern: doubled cross terms and a trace subtraction via pfsubr of the packed 1.0 constant 0x3F8000003F800000 (global 0x005AF990). All eight __m64 slots of a1 are written once (slots 0-5 rotation components, slot 6 zeroed, slot 7 the {0, 1.0} homogeneous row) and the output pointer is returned.
    // CALL: Scale both input quaternions by 0.5 via _m_pfmul with the packed constant 0x3F0000003F000000 (global 0x005AF900), preceded by PackedFloatingPointMath (0x005295E0) expansion calls. [callee:0x005295E0, global:0x005AF900, source:raw]
    // CALCULATION: Multiply the scaled quaternions using 3DNow! shuffles (punpck*) and sign flips (pxor with 0x8000000000000000, global 0x005AF920) with pfadd/pfmul accumulation, producing the quaternion product components. [global:0x005AF920, source:raw]
    // CALCULATION: Convert the product to a 4x4 rotation matrix using the cofactor/adjugate pattern: doubled cross-term products and a trace subtraction via pfsubr of the packed 1.0 constant 0x3F8000003F800000 (global 0x005AF990), plus component shuffling. [global:0x005AF990, source:raw]
    // ASSIGNMENT: Store the computed rotation components into matrix slots a1[0] through a1[5]. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Zero matrix slot a1[6] (row 3 column 0). [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write the homogeneous row {0, 1.0} into matrix slot a1[7]. [field:this:0x00000038, source:raw]
    // RETURN: Emit the MMX/3DNow! state reset (_m_femms) and return the output matrix pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   __m64 *sub_523E7A(__m64 *a1, __m64 a2, __m64 a3) {
    //     PackedFloatingPointMath();
    //     a3 = pfmul(a3, 0x3F0000003F000000);   // scale by 0.5
    //     PackedFloatingPointMath();
    //     a2 = pfmul(a2, 0x3F0000003F000000);   // scale by 0.5
    //     // 3DNow! quaternion product: punpck* shuffles, pxor sign flips,
    //     //   pfadd/pfmul accumulation across mm registers and stack temporaries
    //     // Convert product to 4x4 rotation matrix (cofactor/adjugate pattern,
    //     //   pfsubr trace subtraction with packed 1.0 constant)
    //     a1[0..5] = rotation components;
    //     a1[6] = {0, 0};
    //     a1[7] = {0, 1.0f};                     // homogeneous row
    //     return a1;
    //   }
    // UNRESOLVED: Exact quaternion convention (component order and sign convention of the encoded a2/a3 operands) is not pinned down; the operand encoding matches a caller-specific quaternion layout.
    // UNRESOLVED: The cofactor/adjugate matrix conversion is recognized from the constant pattern, but the mapping of the eight __m64 output slots to concrete matrix cells is only partially verified.
}
