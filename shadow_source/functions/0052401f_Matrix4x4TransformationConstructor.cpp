// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052401F
// Canonical corpus name: F_4x4TransformationMatrixConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4TransformationMatrixConstructor_0052401f.c

void UnknownObject::Matrix4x4TransformationConstructor()
{
    // Composes a 4x4 transformation matrix in a1 (8 __m64 slots) from a scale value a2, an optional rotation matrix a4, an optional origin matrix a3 and an optional additive translation a5. First seeds a1 with a diagonal scale matrix (a2 at this+0x0, this+0x10 high cell and this+0x28; this+0x38 homogeneous 1.0/1.0 from a SIMD constant). When a4 is non-null, computes the 3x3 adjugate/inverse of the rotation in stack __m64 locals and multiplies it into the scale-seeded a1 (translating by a3 first when it is non-null, then re-adding it). When a5 is non-null, adds its translation into the last row. Exits 3DNow mode and returns a1.
    // ASSIGNMENT: Seed a1 with a diagonal scale matrix: this+0x0 = a2, this+0x8 = 0, this+0x10 low cell = 0 with high cell = a2, this+0x18 = 0, this+0x20 = 0, this+0x28 = a2, this+0x30 = 0, this+0x38 = 0x3F80000000000000LL (homogeneous 1.0/1.0 from the SIMD constant global) [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, global:0x005AF8E0, source:raw]
    // GUARD: When a4 (rotation matrix) is non-null, enter the rotation composition path [source:raw]
    // CALCULATION: Compute the 3x3 adjugate/inverse of the a4 rotation using 3DNow pfadd/pfmul/pfacc/pfsub and the angle constants from the SIMD constant global, packing the resulting rotation components into the stack __m64 locals (v118..v124) [global:0x005AF900, source:raw]
    // GUARD: Nested: when a3 (translation/origin matrix) is non-null, subtract a3 from the last row of a1 (this+0x30, this+0x38) before the rotation multiply [field:this:0x00000030, field:this:0x00000038, source:raw]
    // CALCULATION: Multiply the inverse rotation into the scale-seeded matrix, writing the composed 3x3 result back into this+0x0 through this+0x28 [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: In the a3 (translation) case, re-add a3 to the last row (this+0x30, this+0x38) so the origin is restored after the rotation [field:this:0x00000030, field:this:0x00000038, source:raw]
    // GUARD: When a5 (additive translation) is non-null, add a5's translation into the last row: this+0x30 += a5 low, this+0x38 low cell += a5 high low cell [field:this:0x00000030, field:this:0x00000038, source:raw]
    // CALL: Exit 3DNow mode with _m_femms() before returning [source:raw]
    // RETURN: Return a1, the fully composed 4x4 transformation matrix [function:0x0052401F, source:raw]

    // Conservative worker pseudocode:
    //   seed diagonal scale from a2;
    //   a1[0] = a2; a1[1] = 0; a1[2] = {0, a2}; a1[3] = 0;
    //   a1[4] = 0; a1[5] = a2; a1[6] = 0; a1[7] = 0x3F80000000000000LL;
    //   if (a4) {
    //     rot = inverse_3x3(a4);
    //     if (a3) {
    //       a1[6] -= a3[0]; a1[7] -= a3[1];
    //       a1 = rot * a1;
    //       a1[6] += a3[0]; a1[7] += a3[1];
    //     } else {
    //       a1 = rot * a1;
    //     }
    //   }
    //   if (a5) { a1[6] += a5[0]; a1[7] += a5[1]; }
    //   femms();
    //   return a1;
    // UNRESOLVED: The exact identities of the two SIMD constant globals (qword_5AF8E0 for the identity/homogeneous seeding, qword_5AF900 for the angle pair used in the inverse computation) are DERIVED from prior analysis, not evidenced in the raw source
    // UNRESOLVED: The float layout of a3 and a5 as translation matrices (component packed in the low cell of each __m64) is inferred from the last-row arithmetic, not evidenced directly
    // UNRESOLVED: The inverse-rotation computation is understood to be an adjugate form, but the precise formula is not recovered
}
