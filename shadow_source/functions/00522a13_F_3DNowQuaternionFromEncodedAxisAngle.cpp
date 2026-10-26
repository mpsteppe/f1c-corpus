// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00522A13
// Canonical corpus name: F_3DNowQuaternionFromEncodedAxisAngle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowQuaternionFromEncodedAxisAngle_00522a13.c

void UnknownObject::F_3DNowQuaternionFromEncodedAxisAngle()
{
    // Decodes an encoded axis-angle parameter a2 into a 4x4 matrix in the output __m64 buffer a1. The parameter is loaded into mm0, expanded into the packed-float domain by PackedFloatingPointMath, then placed as-is into a1[0], a negated reshuffled copy (punpckhdq/punpckldq with pxor 0x80000000) into a1[2], 1.0f identity elements at a1[5] and a1[7], and zeros elsewhere. All eight slots are written once; the function returns the output pointer.
    // CALL: Load the encoded axis-angle parameter a2 into mm0 and call PackedFloatingPointMath (0x005295E0) to expand it into the packed-float domain; the quaternion-init constant global (0x005AF978) participates in this expansion state. [callee:0x005295E0, global:0x005AF978, source:raw]
    // ASSIGNMENT: Write the encoded axis-angle value v2 into matrix slot a1[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero matrix slot a1[1]. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the negated reshuffled copy (punpckhdq/punpckldq plus pxor 0x80000000) of v2 into matrix slot a1[2]. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero matrix slot a1[3]. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero matrix slot a1[4]. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write the 1.0f identity element (1065353216) into matrix slot a1[5]; the value is sourced from the 3DNow! identity constant global (0x005AF9C0). [field:this:0x00000028, global:0x005AF9C0, source:raw]
    // ASSIGNMENT: Zero matrix slot a1[6]. [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write the homogeneous {1.0, 1.0} row (0x3F80000000000000) into matrix slot a1[7]; the value is sourced from the matrix-constants global (0x005AF9C8). [field:this:0x00000038, global:0x005AF9C8, source:raw]
    // RETURN: Emit the MMX/3DNow! state reset (_m_femms) and return the constructed matrix pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   __m64 *sub_522A13(__m64 *a1, unsigned int a2) {
    //     mm0 = a2;
    //     PackedFloatingPointMath();      // expand encoded axis-angle
    //     a1[0] = mm0;                    // encoded axis-angle value
    //     a1[1] = {0, 0};
    //     a1[2] = pxor(punpckldq(punpckhdq(mm0, mm0), mm0), 0x80000000);
    //     a1[3] = {0, 0};
    //     a1[4] = {0, 0};
    //     a1[5] = 1.0f;                   // identity element (1065353216)
    //     a1[6] = {0, 0};
    //     a1[7] = {1.0f, 1.0f};           // 0x3F80000000000000 homogeneous row
    //     return a1;
    //   }
    // UNRESOLVED: Encoding of the axis-angle parameter a2 (how angle/axis components are packed into the dword) is not deciphered; only its placement into the matrix is shown.
    // UNRESOLVED: Consumer of the decoded matrix and the frame it represents depend on the caller and are not visible here.
}
