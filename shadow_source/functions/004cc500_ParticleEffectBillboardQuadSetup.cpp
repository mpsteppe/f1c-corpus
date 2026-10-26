// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CC500
// Canonical corpus name: ParticleEffectBillboardQuadSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleEffectBillboardQuadSetup_004cc500.c

void UnknownObject::ParticleEffectBillboardQuadSetup()
{
    // Billboard quad vertex writer for a particle sprite. Builds a camera-facing unit perpendicular from the cross product of the particle axis vector a2[18..20] and the facing vector a3[0..2], scales it by half the particle size (this[4] * 0.5), then computes the four quad corners around the particle center a2[11..13]. Each corner is written to the particle texture buffer via PixelWriteToTextureBuffer. When the cross-product magnitude is zero the perpendicular degenerates to an axis-aligned half-extent.
    // CALCULATION: Compute the three cross-product components of a2[18..20] x a3[0..2]: v6, v9, v12. [source:raw]
    // CALCULATION: Compute the squared magnitude of the perpendicular as v3 = v12^2 + v9^2 + v6^2. [source:raw]
    // GUARD: Guard on the squared magnitude v3 > 0.0 (zero-threshold test); when zero the perpendicular direction is degenerate and an axis-aligned fallback is used instead. [source:raw, global:0x0059E440]
    // CALCULATION: When non-degenerate: scale the unit perpendicular by half the particle size, v4 = this[4] * 0.5 / sqrt(v3), and form the scaled perpendicular components v15, v16, v17. [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Degenerate fallback: v15 = 0.0, v17 = 0.0, v16 = this[4] * 0.5 (axis-aligned half-extent). [source:raw, field:this:0x00000010]
    // CALCULATION: First quad corner: particle center a2[11..13] plus the scaled perpendicular (v18, v20, v22). [source:raw]
    // CALL: Write quad corner 1 and corner 2 (corner 2 = corner 1 minus the facing vector a3[0..2]) to the texture buffer via PixelWriteToTextureBuffer, passing the texture handle *(_DWORD*)a2, the corner index, the corner position, and the color *((_DWORD*)a2 + 24). [callee:0x00558E10, source:raw]
    // CALCULATION: Remaining two corners: particle center a2[11..13] minus the scaled perpendicular (v19, v21, v23), then minus the facing vector a3[0..2] for the last corner (v8, v11, v14). [source:raw]
    // CALL: Write quad corners 0 and 3 to the texture buffer via PixelWriteToTextureBuffer with the same texture handle and color. [callee:0x00558E10, source:raw]
    // RETURN: Return the result of the final PixelWriteToTextureBuffer call. [callee:0x00558E10, source:raw]
    // CALL: Invoked from ParticleSpawnFunction (0x004CCE90) and ParticleSystemUpdateWithWindAndDamping (0x004CD220) to emit particle quad vertices. [caller:0x004CCE90, caller:0x004CD220, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CC500(float *this, float *a2, float *a3) {
    //     // a2[0] texture handle, a2[11..13] particle center, a2[18..20] axis vector,
    //     // a2[24] vertex color, this[4] particle size (half-extent basis).
    //     float v6 = a3[1]*a2[20] - a3[2]*a2[19];
    //     float v9 = a3[2]*a2[18] - a2[20]*a3[0];
    //     float v12 = a2[19]*a3[0] - a3[1]*a2[18];
    //     float mag2 = v6*v6 + v9*v9 + v12*v12;
    //     float hx, hy, hz;
    //     if (mag2 > 0.0f) {
    //       float s = this[4] * 0.5f / sqrt(mag2);
    //       hx = v6*s; hy = v9*s; hz = v12*s;
    //     } else {
    //       hx = 0.0f; hy = this[4] * 0.5f; hz = 0.0f;
    //     }
    //     // corners around center a2[11..13]
    //     PixelWriteToTextureBuffer(a2[0], 1, a2[11]+hx, a2[12]+hy, a2[13]+hz, a2[24]);
    //     PixelWriteToTextureBuffer(a2[0], 2, a2[11]+hx-a3[0], a2[12]+hy-a3[1], a2[13]+hz-a3[2], a2[24]);
    //     PixelWriteToTextureBuffer(a2[0], 0, a2[11]-hx, a2[12]-hy, a2[13]-hz, a2[24]);
    //     return PixelWriteToTextureBuffer(a2[0], 3, a2[11]-hx-a3[0], a2[12]-hy-a3[1], a2[13]-hz-a3[2], a2[24]);
    //   }
    // UNRESOLVED: Exact role of globals flt_59E440 (zero threshold) and flt_59E450 (degrees-to-radians) is not visible in the raw source; the threshold test appears as a literal 0.0, so these reads are likely compiler constant-hoisting artifacts.
    // UNRESOLVED: a2 layout (texture handle at index 0, center at 11..13, axis vector at 18..20, color at 24) is derived from index usage, not confirmed by an explicit struct.
    // UNRESOLVED: this[4] particle size is read as a half-extent basis; the relationship to a2's own size data is unknown.
}
