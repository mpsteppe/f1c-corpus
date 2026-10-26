// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055EEAF
// Canonical corpus name: sub_55EEAF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55EEAF_0055eeaf.c

void UnknownObject::TransformVectorByMatrix4x4()
{
    // Float 3-vector transform by a 16-float row-major 4x4 matrix with translation. Reads the input vector a1[0..2] (this byte offsets 0x0, 0x4, 0x8) and computes three dot products against matrix rows, adding the translation components a3[12], a3[13], a3[14], storing the result into a2[0..2]. No branches or calls.
    // ASSIGNMENT: Compute a2[0] = a3[0]*a1[0] + a3[4]*a1[1] + a3[8]*a1[2] + a3[12] (matrix row 0 plus translation x). [source:raw]
    // ASSIGNMENT: Compute v3 = a3[1]*a1[0] + a3[5]*a1[1] + a3[9]*a1[2] + a3[13] (matrix row 1 plus translation y), later stored to a2[1]. [source:raw]
    // ASSIGNMENT: Compute v4 = a3[2]*a1[0] + a3[6]*a1[1] + a3[10]*a1[2] + a3[14] (matrix row 2 plus translation z), later stored to a2[2]. [source:raw]
    // ASSIGNMENT: Write the two remaining result components a2[1] = v3 and a2[2] = v4. [source:raw]
    // CALCULATION: Read the 3-component input vector a1 from this[0..2] at byte offsets 0x0, 0x4, 0x8 as the vector being transformed. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]

    // Conservative worker pseudocode:
    //   void sub_55EEAF(float* a1, float* a2, float* a3) {
    //     float v3 = a3[1]*a1[0] + a3[5]*a1[1] + a3[9]*a1[2] + a3[13];
    //     float v4 = a3[2]*a1[0] + a3[6]*a1[1] + a3[10]*a1[2] + a3[14];
    //     a2[0] = a3[0]*a1[0] + a3[4]*a1[1] + a3[8]*a1[2] + a3[12];
    //     a2[2] = v4;
    //     a2[1] = v3;
    //   }
    // UNRESOLVED: a3 is interpreted as a 16-float row-major 4x4 matrix with linear part a3[0..10] and translation row a3[12..14]; this interpretation is DERIVED from the arithmetic.
    // UNRESOLVED: Prelabel cluster_copy proposes a link to Vector3ScalarMultiply (0045eb00), but the raw source is a matrix-by-vector product with translation, so that label is DERIVED and may be inaccurate.
    // UNRESOLVED: Whether a2 is consumed by the caller as a transformed point or a direction is caller-defined.
}
