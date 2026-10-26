// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EDAE
// Canonical corpus name: NormalizedVectorWithThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NormalizedVectorWithThreshold_0051edae.c

void UnknownObject::NormalizedVectorWithThreshold()
{
    // Normalizes a 3-component float vector with a squared-length threshold. Computes the squared length of input a2; when it is at least the global threshold dword_8D6000, computes a Newton-Raphson refined reciprocal square root and scales each input component into the output a1; otherwise writes a zero vector to a1. Returns a1.
    // CALCULATION: Compute the squared length v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2] [source:raw]
    // GUARD: Normalization branch is taken only when the squared length v5 is greater than or equal to the global threshold dword_8D6000; otherwise the zero-vector branch is taken [global:0x008D6000]
    // CALCULATION: Compute v6 = 1.0 / fsqrt(v5), the reciprocal square root of the squared length [source:raw]
    // CALCULATION: Newton-Raphson refinement: v7 = dword_8D6004 * v6 * (dword_8D6008 - v5 * v6 * v6) [global:0x008D6004, global:0x008D6008]
    // ASSIGNMENT: Scale each input component by v7 into the output vector: a1[0] = v7*a2[0], a1[1] = v7*a2[1], a1[2] = v7*a2[2] [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Threshold-fail branch: write 0.0 to all three output components a1[0], a1[1], a1[2] [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // RETURN: Return the output vector pointer a1 [function:0x0051EDAE, source:raw]

    // Conservative worker pseudocode:
    //   v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2];
    //   if (v5 >= dword_8D6000) {
    //     v6 = 1.0f / fsqrt(v5);
    //     v7 = dword_8D6004 * v6 * (dword_8D6008 - v5 * v6 * v6);
    //     a1[0] = v7 * a2[0]; a1[1] = v7 * a2[1]; a1[2] = v7 * a2[2];
    //   } else {
    //     a1[0] = 0.0f; a1[1] = 0.0f; a1[2] = 0.0f;
    //   }
    //   return a1;
    // UNRESOLVED: The semantic meaning of the three read-only globals dword_8D6000, dword_8D6004, dword_8D6008 (threshold, scale factor, subtractive coefficient per the skeleton fill) is unverifiable from this packet
    // UNRESOLVED: The ABI name Normalized_Vector_with_Threshold carries LEGACY trust and is consistent with the source behavior but was not independently confirmed
}
