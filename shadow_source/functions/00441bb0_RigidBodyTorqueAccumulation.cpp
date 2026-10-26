// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441BB0
// Canonical corpus name: RigidBodyTorqueAccumulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RigidBodyTorqueAccumulation_00441bb0.c

void UnknownObject::RigidBodyTorqueAccumulation()
{
    // Accumulates a torque-like force contribution between two rigid bodies referenced from this: loads the source body pointer at this+0x15F0 and the target body pointer at this+0x1D4, rotates the local vector at this+444 by the source body rotation matrix via Matrix3x3VectorMultiply, adds the source body position, forms a cross-product vector against the source body components, subtracts the target body position to form a lever arm, scales the result using a target body parameter at target+0xAC combined with the scalars at this+0x1D8 and this+0x1E0, accumulates scaled components into the target body force buffer at target+0x134/0x13C/0x144, and returns the result of F_3DVectorSubtractWithCrossProduct on the intermediate vectors.
    // CALL: Load the source body pointer v2 = *(this+0x15F0) and rotate the local vector at this+444 into world space: Matrix3x3VectorMultiply(matrix at v2+28, vector at this+444, out v16/v17/v18). [field:this:0x000015F0, callee:0x00435E00, source:raw]
    // CALCULATION: Add the source body position components at v2+0x4/0xC/0x14 to the rotated vector components v16/v17/v18, producing v3 = v16 + *(v2+0x4), v5 = v17 + *(v2+0xC) and v23[2] = v18 + *(v2+0x14). [field:*(this+0x15F0):0x00000004, field:*(this+0x15F0):0x0000000C, field:*(this+0x15F0):0x00000014, source:raw]
    // CALCULATION: Compute a cross product of the rotated vector (v16/v17/v18) against the source body components at v2+0x7C/0x84/0x8C: v6 = v18*0x8C - v17*0x84, v7 = v16*0x84 - v18*0x7C, v19[2] = v17*0x7C - v16*0x8C. [field:*(this+0x15F0):0x0000007C, field:*(this+0x15F0):0x00000084, field:*(this+0x15F0):0x0000008C, source:raw]
    // CALCULATION: Add the source body components at v2+0x64/0x6C/0x74 into the cross-product vector: v19[0] = v6 + *(v2+0x64), v19[1] = v7 + *(v2+0x6C), v19[2] += *(v2+0x74). [field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, source:raw]
    // ASSIGNMENT: Load the target body pointer v4 = *(this+0x1D4). [field:this:0x000001D4, source:raw]
    // CALCULATION: Form the lever arm between the transformed source point and the target body position: v23[0] = v3 - *(v4+0x4), v8 = v5 - *(v4+0xC), v9 = v23[2] - *(v4+0x14). [field:*(this+0x1D4):0x00000004, field:*(this+0x1D4):0x0000000C, field:*(this+0x1D4):0x00000014, source:raw]
    // CALCULATION: Subtract the target body components at v4+0x64/0x6C/0x74 from the force vector: v10 = v19[0] - *(v4+0x64), v11 = v19[1] - *(v4+0x6C), v19[2] -= *(v4+0x74). [field:*(this+0x1D4):0x00000064, field:*(this+0x1D4):0x0000006C, field:*(this+0x1D4):0x00000074, source:raw]
    // CALCULATION: Compute scaling factors from the target body parameter at v4+0xAC and the this-object scalars: v12 = *(v4+0xAC), v14 = v12 * *(this+0x1D8), v15 = sqrt(v14 * v12) * *(this+0x1E0). [field:*(this+0x1D4):0x000000AC, field:this:0x000001D8, field:this:0x000001E0, source:raw]
    // CALCULATION: Combine lever arm and force vectors under the two scalars: v20/v21/v22 = v10/v11/v19[2] scaled by v15; v23[0] and v23[1] scaled by v14; reassemble v19[0] = v23[0]+v20, v19[1] = v21+v23[1], v19[2] = v22 + v9*v14; then copy v19 into v23 (qmemcpy). [source:raw]
    // CALCULATION: Accumulate the computed vector into the target body force buffer: *(v4+0x134) += v19[0], *(v4+0x13C) += v23[1], *(v4+0x144) += v23[2]. [field:*(this+0x1D4):0x00000134, field:*(this+0x1D4):0x0000013C, field:*(this+0x1D4):0x00000144, source:raw]
    // RETURN: Return F_3DVectorSubtractWithCrossProduct(&v16, v23). [callee:0x00569B70, source:raw]

    // Conservative worker pseudocode:
    //   int RigidBodyTorqueAccumulation(int this) {
    //     char* src = *(char**)(this + 0x15F0);
    //     double v[3];
    //     Matrix3x3VectorMultiply((double*)(src + 28), (double*)(this + 444), v);
    //     double p0[3] = { v[0] + *(double*)(src + 4), v[1] + *(double*)(src + 12), v[2] + *(double*)(src + 20) };
    //     double f[3] = {
    //       v[2]**(double*)(src+132) - v[1]**(double*)(src+140) + *(double*)(src+100),
    //       v[0]**(double*)(src+140) - v[2]**(double*)(src+124) + *(double*)(src+108),
    //       v[1]**(double*)(src+124) - v[0]**(double*)(src+132) + *(double*)(src+116) };
    //     char* dst = *(char**)(this + 0x1D4);
    //     double arm[3] = { p0[0] - *(double*)(dst+4), p0[1] - *(double*)(dst+12), p0[2] - *(double*)(dst+20) };
    //     f[0] -= *(double*)(dst+100); f[1] -= *(double*)(dst+108); f[2] -= *(double*)(dst+116);
    //     double stiff = *(double*)(dst+172);
    //     double a = stiff * *(double*)(this + 0x1D8);
    //     double b = sqrt(a * stiff) * *(double*)(this + 0x1E0);
    //     double out[3] = { arm[0]*a + f[0]*b, arm[1]*a + f[1]*b, arm[2]*a + f[2]*b };
    //     *(double*)(dst+308) += out[0]; *(double*)(dst+316) += out[1]; *(double*)(dst+324) += out[2];
    //     return F_3DVectorSubtractWithCrossProduct(v, out);
    //   }
    // UNRESOLVED: The source body components at v2+0x7C/0x84/0x8C and v2+0x64/0x6C/0x74 and the this+444 vector have no per-field purpose confirmed beyond the arithmetic shown; the torque/spring/damper interpretation of the target body parameter at v4+0xAC and the scalars at this+0x1D8/this+0x1E0 is DERIVED, not confirmed.
    // UNRESOLVED: The vector input at this+444 used by Matrix3x3VectorMultiply has no corresponding packet field evidence reference.
    // UNRESOLVED: The exact role and semantics of the return value of F_3DVectorSubtractWithCrossProduct are unknown.
    // UNRESOLVED: The qmemcpy between v19 and v23 and the final mixing of v23[1]/v23[2] into the accumulators (rather than the reassembled v19) is a decompiler artifact whose exact storage intent is unclear.
    // UNRESOLVED: Only one caller (PhysicsIntegrationStep 0x00441D60) is present in this packet.
}
