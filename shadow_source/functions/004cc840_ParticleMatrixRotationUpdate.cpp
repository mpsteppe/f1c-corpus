// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CC840
// Canonical corpus name: sub_4CC840
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CC840_004cc840.c

void UnknownObject::ParticleMatrixRotationUpdate()
{
    // Recalculates a strided array of particle orientation axes. Reads a source direction (and a Y component) from an object reached through VirtualDispatchHelper(&dword_5EA510) at offset +36, scales the X and Z components by -0.03125, then walks entries of 10 floats starting at unk_8AC840 up to the end marker flt_8ACAC0. For each entry it derives the three axis vectors from the direction and the previous row, computes their cross product, and normalizes it to length this[4]/2 (or applies a default axis of length this[4]/2 along X when the magnitude is zero). Called by sub_4CC970 and ParticleEffectPhysics.
    // CALL: Call VirtualDispatchHelper(&dword_5EA510) and take a pointer at result+36 to obtain the source direction data v2. [callee:0x0040C870, global:0x005EA510, source:raw]
    // CALCULATION: Compute scaled direction components: v3 = v2[0] * -0.03125 (X), v13 = v2[1] (Y kept raw), v4 = v2[2] * -0.03125 (Z). [global:0x005EA510, source:raw]
    // LOOP: Iterate over the strided entry array with an entry stride of 10 floats, starting at unk_8AC840 and continuing while the entry address is below flt_8ACAC0. [global:0x008AC840, global:0x008ACAC0, source:raw]
    // CALCULATION: Per entry, write the derived direction vector: X = v3, Y = (previous Y - v13) * 0.03125, Z = v4 into the entry slots. [global:0x008AC840, source:raw]
    // CALCULATION: Compute the cross product of the two direction vectors: v14, v15, and v16 = v7 - v9 from the raw component products. [source:raw]
    // ASSIGNMENT: Store the cross product as the entry's axis vectors: *(v5-1) = v14, *v5 = v15, v5[1] = v16. [source:raw]
    // GUARD: Per entry, check the squared magnitude of the axis vector; when it is > 0.0 the vector is normalized. [source:raw]
    // CALCULATION: Normalize the axis: scale each component by this[4] * 0.5 / sqrt(magnitude) so the vector length becomes this[4]/2. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: When the magnitude is zero, set a default axis: X = this[4] * 0.5, Y = 0, Z = 0. [field:this:0x00000010, source:raw]
    // CALCULATION: Advance the entry pointer by the 10-float stride and continue while below flt_8ACAC0. [global:0x008ACAC0, source:raw]

    // Conservative worker pseudocode:
    //   void ParticleMatrixRotationUpdate(float *this) {
    //     float *src = VirtualDispatchHelper(&dword_5EA510) + 36;
    //     float sx = src[0] * -0.03125f;
    //     float sy = src[1];
    //     float sz = src[2] * -0.03125f;
    //     float *p = (float*)&unk_8AC840;
    //     do {
    //       p[-4] = sx;
    //       p[-3] = (p[-5] - sy) * 0.03125f;
    //       p[-2] = sz;
    //       float ax = p[-3] * p[-6] - p[-2] * p[-7];
    //       float ay = p[-2] * p[-8] - p[-4] * p[-6];
    //       float az = p[-4] * p[-7] - p[-3] * p[-8];
    //       p[-1] = ax; p[0] = ay; p[1] = az;
    //       float m = ax*ax + ay*ay + az*az;
    //       if (m > 0.0f) {
    //         float k = this[4] * 0.5f / sqrtf(m);
    //         p[-1] *= k; p[0] *= k; p[1] *= k;
    //       } else {
    //         p[-1] = 0.0f; p[0] = this[4] * 0.5f; p[1] = 0.0f;
    //       }
    //       p += 10;
    //     } while ((int)p < (int)&flt_8ACAC0);
    //   }
    // UNRESOLVED: The object type behind VirtualDispatchHelper(&dword_5EA510) and the meaning of its +36 field are unknown.
    // UNRESOLVED: The 10-float entry layout and the exact meaning of each axis row in the unk_8AC840 array are inferred from the arithmetic only.
    // UNRESOLVED: flt_8ACAC0 is treated as an end-marker address for the strided array; its identity as an array terminator is DERIVED.
}
