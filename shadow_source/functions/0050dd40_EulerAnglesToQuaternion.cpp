// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DD40
// Canonical corpus name: EulerAnglesToQuaternion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EulerAnglesToQuaternion_0050dd40.c

void UnknownObject::EulerAnglesToQuaternion()
{
    // __stdcall helper converting three Euler angles (a2, a3, a4) into a quaternion written as (x, y, z, w) to the caller-supplied float pointer a1 (a1[0..3]). It halves each angle, computes the sine/cosine of each half-angle, and combines the products into the four quaternion components using the standard cross-term composition. Returns a1.
    // CALCULATION: Halve the a4 angle (v9 = a4 * 0.5) and compute v14 = cos(v9), v17 = sin(v9). [source:raw]
    // CALCULATION: Halve the a3 angle (v15 = a3 * 0.5) and compute v12 = cos(v15), v10 = sin(v15). [source:raw]
    // CALCULATION: Halve the a2 angle (v16 = a2 * 0.5) and compute v13 = cos(v16), v11 = sin(v16). [source:raw]
    // ASSIGNMENT: Write quaternion x to this+0x0: v14 * v6 + v5 * v17 where v5 = v11 * v12 and v6 = v13 * v10. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write quaternion y to this+0x4: v5 * v14 - v6 * v17. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write quaternion z to this+0x8: v7 * v17 - v8 * v14 where v7 = v13 * v12 and v8 = v11 * v10. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write quaternion w to this+0xC: v8 * v17 + v7 * v14. [field:this:0x0000000C, source:raw]
    // RETURN: Return the output quaternion base pointer a1. [function:0x0050DD40, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50DD40(float *out, float angle_x, float angle_y, float angle_z) {
    //     float hx = angle_x * 0.5f;
    //     float cx = cosf(hx), sx = sinf(hx);
    //     float hy = angle_y * 0.5f;
    //     float cy = cosf(hy), sy = sinf(hy);
    //     float hz = angle_z * 0.5f;
    //     float cz = cosf(hz), sz = sinf(hz);
    //     float v5 = sx * cy;
    //     float v6 = cx * sy;
    //     out[0] = cz * v6 + v5 * sz;
    //     out[1] = v5 * cz - v6 * sz;
    //     float v7 = cx * cy;
    //     float v8 = sx * sy;
    //     out[2] = v7 * sz - v8 * cz;
    //     out[3] = v8 * sz + v7 * cz;
    //     return out;
    //   }
    // UNRESOLVED: flt_59E450 (0x0059E450), statically read by this function and DERIVED as a DegreesToRadians scale in the existing analysis, does not appear in the raw decompiled C text; whether and how it feeds the input angles is unresolved.
    // UNRESOLVED: Rotation order implied by the cross-term composition (a2 then a3 then a4) is not confirmed against the caller's convention.
    // UNRESOLVED: Owner class is unknown; no static callers are recorded.
}
