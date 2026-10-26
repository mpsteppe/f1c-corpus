// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053BE60
// Canonical corpus name: F_3DSquaredDistance
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DSquaredDistance_0053be60.c

void UnknownObject::F_3DSquaredDistance()
{
    // Squared Euclidean distance between two 3D vectors: computes the per-component differences a1[i] - a2[i] for i in 0..2 and returns the sum of their squares as a double. Pure scalar math routine with no guards, globals or calls.
    // CALCULATION: Compute the x difference v3 = a1[0] - a2[0], reading the first float of the vector at this+0x0. [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the y difference v2 = a1[1] - a2[1], reading the component at this+0x4. [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the z difference v4 = a1[2] - a2[2], reading the component at this+0x8. [field:this:0x00000008, source:raw]
    // CALCULATION: Square each difference and sum them: v3*v3 + v2*v2 + v4*v4. [source:raw]
    // RETURN: Return the squared 3D distance as a double. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_53BE60(const float *a1, const float *a2) {
    //     double v3 = (double)*a1 - *a2;
    //     double v2 = (double)a1[1] - a2[1];
    //     double v4 = (double)a1[2] - a2[2];
    //     return v3 * v3 + v2 * v2 + v4 * v4;
    //   }
    // UNRESOLVED: The cluster_copy prelabel names a structural twin at 0045eb00 (Vector3ScalarMultiply) as DERIVED evidence; whether the two routines share a true owner class is unverified.
    // UNRESOLVED: Only the a1-side components are listed as packet fields; the a2-side reads use the same offsets, so no separate fields are recorded.
}
