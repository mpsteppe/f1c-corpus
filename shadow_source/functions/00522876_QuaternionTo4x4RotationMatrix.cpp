// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00522876
// Canonical corpus name: QuaternionTo4x4RotationMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionTo4x4RotationMatrix_00522876.c

void UnknownObject::QuaternionTo4x4RotationMatrix()
{
    // 3DNow!/MMX quaternion-to-matrix conversion: normalizes input quaternion a2 via F_3DVectorNormalize_7578 into a stack pair (v11/v12), then builds a 4x4 rotation matrix in a1. Packed lane scaling uses v4 = v11 * -2.0 and v5 = v12 * (-2.0, 1.0) (0xC0000000C0000000 / 0x3F800000C0000000), lanes are duplicated with punpckldq/punpckhdq, and the eight __m64 matrix slots are written with pfadd/pfmul combinations that place 1.0 identity elements (0x3F800000 lanes) on the diagonal. MMX state is cleared with _m_femms() on entry and exit; returns a1.
    // STATE_TRANSITION: Clear MMX/3DNow! state with _m_femms() on entry. [source:raw]
    // CALL: Normalize input quaternion a2 through F_3DVectorNormalize_7578((int)&v11, a2); normalized result lands in stack quaternion v11/v12. [source:raw, callee:0x00527578]
    // CALCULATION: Scale packed components: v4 = v11 * 0xC0000000C0000000 (per-lane -2.0) and v5 = v12 * 0x3F800000C0000000. [source:raw]
    // CALCULATION: Duplicate low and high dword lanes of v11 into v7 and v8 via punpckldq/punpckhdq. [source:raw]
    // ASSIGNMENT: Write a1[0] (field this+0x0): 1.0 (0x3F800000 lane) + v7*v4; write a1[1] (field this+0x8): (v7>>32)*v5. [source:raw, field:this:0x00000000, field:this:0x00000008]
    // ASSIGNMENT: Write a1[2] (field this+0x10): 1.0 + v8*v4; write a1[3] (field this+0x18): (v8>>32)*v5. [source:raw, field:this:0x00000010, field:this:0x00000018]
    // CALCULATION: Duplicate low and high dword lanes of v12 into v9 and v10 via punpckldq/punpckhdq. [source:raw]
    // ASSIGNMENT: Write a1[4] (field this+0x20): v9*v4; write a1[5] (field this+0x28): 1.0 + (v9>>32)*v5. [source:raw, field:this:0x00000020, field:this:0x00000028]
    // ASSIGNMENT: Write a1[6] (field this+0x30): v10*v4; write a1[7] (field this+0x38): 1.0 + (v10>>32)*v5. [source:raw, field:this:0x00000030, field:this:0x00000038]
    // CALCULATION: Read four packed qword globals (5AF9C0, 5AF9C8, 5AF9D8, 5AF9E0) as identity/matrix constants used by the conversion; their contents are not present in the packet. [global:0x005AF9C0, global:0x005AF9C8, global:0x005AF9D8, global:0x005AF9E0]
    // STATE_TRANSITION: Clear MMX/3DNow! state with _m_femms() before returning. [source:raw]
    // RETURN: Return a1, the pointer to the filled 4x4 rotation matrix. [source:raw]

    // Conservative worker pseudocode:
    //   m64 *sub_522876(m64 *a1 /* out 4x4 matrix * /, int a2 /* quaternion * /) {
    //     _m_femms();
    //     F_3DVectorNormalize_7578(&v11, a2);
    //     v4 = v11 * -2.0f;  v5 = v12 * (-2.0f, 1.0f);
    //     // duplicate lanes and fill the 8 __m64 slots with pfadd/pfmul terms
    //     // placing 1.0 identity elements on the diagonal
    //     _m_femms();
    //     return a1;
    //   }
    // UNRESOLVED: Owner/class of the function is UNKNOWN (no callers in packet; packet owner trust UNKNOWN).
    // UNRESOLVED: Exact contents of the four global packed constants are not in the packet; only that they are read.
    // UNRESOLVED: The precise quaternion-to-matrix element order (row/column convention) is inferred from lane placement, not packet-confirmed.
}
