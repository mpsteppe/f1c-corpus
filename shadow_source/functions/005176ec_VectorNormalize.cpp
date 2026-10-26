// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005176EC
// Canonical corpus name: VectorNormalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VectorNormalize_005176ec.c

void UnknownObject::VectorNormalize()
{
    // Normalizes the 3-vector a2 into a1. Computes the squared length; if it is 0.0, writes an all-zero vector to a1. Otherwise computes 1.0 minus the squared length and branches: when |1.0 - length^2| exceeds the magic threshold 0x3727C5AC, scales each component by a fast table-based reciprocal-square-root approximation (table address appears only in raw source as 5D79E0h, magic constant -1090519041); else, when a1 and a2 differ, copies a2 into a1 (length already near 1.0). Writes a1[0] at this+0x0, a1[1] at this+0x4, a1[2] at this+0x8 and returns a1.
    // CALCULATION: Compute squared length v8 = a2[0]^2 + a2[1]^2 + a2[2]^2. [source:raw]
    // GUARD: If squared length v8 is 0.0, output an all-zero vector. [source:raw]
    // ASSIGNMENT: Write 0.0 to a1[0] at this+0x0 (zero-length branch). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0.0 to a1[1] at this+0x4 (zero-length branch). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write 0.0 to a1[2] at this+0x8 (zero-length branch). [field:this:0x00000008, source:raw]
    // CALCULATION: Compute v9 = 1.0 - v8 and test |v9| against magic threshold 0x3727C5AC to select the fast approximate-normalize path. [source:raw]
    // GUARD: If |1.0 - v8| > 0x3727C5AC, normalize using the fast reciprocal-square-root approximation; otherwise if a1 != a2, copy a2 into a1. [source:raw]
    // ASSIGNMENT: Store a1[0] at this+0x0 as a2[0] scaled by the approximate reciprocal of the length (fast path). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store a1[1] at this+0x4 as a2[1] scaled by the approximate reciprocal of the length (fast path). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store a1[2] at this+0x8 as a2[2] scaled by the approximate reciprocal of the length (fast path). [field:this:0x00000008, source:raw]
    // GUARD: Else-branch condition: when the squared length is close to 1.0 (and a1 != a2), copy the input unchanged. [source:raw]
    // ASSIGNMENT: Copy a2[0] into a1[0] at this+0x0 (near-unit-length branch). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy a2[1] into a1[1] at this+0x4 (near-unit-length branch). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Copy a2[2] into a1[2] at this+0x8 (near-unit-length branch). [field:this:0x00000008, source:raw]
    // RETURN: Return the output vector a1. [function:0x005176EC, source:raw]

    // Conservative worker pseudocode:
    //   float* sub_5176EC(float* a1, float* a2) {
    //     float len2 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2];
    //     if (len2 == 0.0f) {
    //       a1[0] = a1[1] = a1[2] = 0.0f;
    //     } else if (fabsf(1.0f - len2) > 0x3727C5AC-as-float) {
    //       float inv = fast_rsqrt_table(len2);
    //       a1[0] = a2[0] * inv;
    //       a1[1] = a2[1] * inv;
    //       a1[2] = a2[2] * inv;
    //     } else if (a1 != a2) {
    //       a1[0] = a2[0]; a1[1] = a2[1]; a1[2] = a2[2];
    //     }
    //     return a1;
    //   }
    // UNRESOLVED: The fast path uses a table-based reciprocal-square-root approximation (lookup table address appears in raw source only as 5D79E0h, magic constants 0x3727C5AC, 0x3F000000, -1090519041); its exact numeric accuracy and edge-case behavior are only verifiable at runtime.
    // UNRESOLVED: The legacy ABI name Vector_Normalize is not corroborated by an owner or caller in this packet.
    // UNRESOLVED: Whether a zero-length input is meant to yield a true zero vector is not resolvable from this packet.
}
