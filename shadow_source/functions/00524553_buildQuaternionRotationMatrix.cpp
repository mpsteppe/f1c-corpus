// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00524553
// Canonical corpus name: SIMDQuaternionRotationArithmetic
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SIMDQuaternionRotationArithmetic_00524553.c

void UnknownObject::buildQuaternionRotationMatrix()
{
    // 3DNow!-intrinsic build of a 4x4 rotation matrix from a quaternion (a2, packed pair) and an angle scalar (a3) using pfmul/pfadd/pfsub/punpck intrinsics. The quaternion pair is normalized in place via sub_5262C2, the angle is fed through the PackedFloatingPointMath trigonometric helper, and the resulting matrix is written across all eight output __m64 slots of a1. The ABI lead (LEGACY) names this SIMD_Quaternion_Rotation_Arithmetic. Returns the output matrix pointer a1.
    // CALCULATION: Extract quaternion components from a2 (a2[0].m64_u64 and a2[1].m64_u32[0]) and keep a stack copy m64_u64 for in-place normalization; v24 holds the low half of a2[1]. [source:raw]
    // CALL: sub_5262C2(&m64_u64, &m64_u64): normalize/reduce the packed quaternion pair in place on the stack copy. [callee:0x005262C2, source:raw]
    // CALL: PackedFloatingPointMath(): trigonometric helper (sin/cos approximation) driven by the angle scalar a3; the LEGACY ABI lead labels the whole routine SIMD_Quaternion_Rotation_Arithmetic. [callee:0x005295E0, abi:lead, source:raw]
    // CALCULATION: Seed packed coefficients from the angle scalar a3: v5 = 1.0 - a3 against the packed constant 0x3F8000003F800000, v25 = high half of a3; the packet's fact table flags qword_5AF900 as read (rendered inline in the raw source, so the exact global-to-constant mapping is not established). [global:0x005AF900, source:raw]
    // CALCULATION: Compute the quaternion-product terms v10/v12/v13/v14/v17/v18 forming the rotation rows, using pfmul/pfadd/pfsub and punpck of the normalized quaternion against the (1.0 - angle) coefficients. [source:raw]
    // ASSIGNMENT: Write the four rotation rows into all eight output slots: a1[0] = packed rotation term, a1[1], a1[2], a1[3], a1[4], a1[5] = packed terms, a1[6] = 0, a1[7] = packed 1.0/1.0 (0x3F8000003F800000), fully overwriting the output matrix. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // RETURN: Execute _m_femms() to exit MMX state and return the output matrix pointer a1. [function:0x00524553, source:raw]

    // Conservative worker pseudocode:
    //   q = a2; // packed quaternion pair
    //   q_copy = q; normalize_quaternion(&q_copy); // sub_5262C2
    //   trig_approx(a3); // PackedFloatingPointMath (sin/cos for the angle)
    //   c1 = (1.0, 1.0) - (a3, a3); // 0x3F8000003F800000
    //   // build rotation rows from quaternion products and c1
    //   a1[0..7] = rotation_rows; a1[6] = 0; a1[7] = (1.0, 1.0);
    //   _m_femms(); return a1;
    // UNRESOLVED: qword_5AF900 is flagged by the packet as read but does not appear by name in the raw decompiled source (the constant 0x3F8000003F800000 renders inline); its mapping is not established.
    // UNRESOLVED: The exact contract of sub_5262C2 (normalization vs. reduction) and PackedFloatingPointMath (sin/cos approximation precision) is unconfirmed; PackedFloatingPointMath is called with no visible arguments.
    // UNRESOLVED: The field R/W annotations in the packet mark this+0x0 as RW and the remaining output slots as read, while the raw source writes all eight slots; the discrepancy is unresolved.
    // UNRESOLVED: The owner object is not established; the function has no static callers, and the LEGACY ABI name SIMD_Quaternion_Rotation_Arithmetic is not independent evidence of ownership.
}
