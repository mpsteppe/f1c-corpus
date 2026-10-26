// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00527578
// Canonical corpus name: F_3DVectorNormalize_7578
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DVectorNormalize_7578_00527578.c

void UnknownObject::Normalize4ComponentVector3DNow()
{
    // Normalizes a 4-component vector (x,y,z,w) using 3DNow! SIMD. Computes the packed squared length via pfmul/pfadd/pfacc, derives a reciprocal square root with Newton-Raphson refinement, and guards against near-zero length by masking the outputs to zero when the squared length is not above the threshold.
    // CALCULATION: Load the second input component pair a2[1] (z,w). [field:this:0x00000008, source:raw]
    // CALCULATION: Square each component pair (a2[0] and a2[1] via pfmul), sum the squares with pfadd, then horizontally accumulate with pfacc to obtain the packed squared length v5. [source:raw]
    // GUARD: Packed compare of the squared length v5 against the threshold qword_5AF970 (0x0080000000800000); when the length is not greater, the resulting mask v7 is zero so the output is nulled. [global:0x005AF970, source:raw]
    // CALCULATION: Compute the reciprocal square root of v5 with Newton-Raphson refinement (pfrsqrt, pfrsqit1, pfrcpit2). [source:raw]
    // CALCULATION: Mask each input component pair with the zero mask v7 (mask qword_5AF950) so degenerate vectors normalize to zero. [global:0x005AF950, source:raw]
    // ASSIGNMENT: Write the normalized first component pair (x,y) to the output a1[0] as masked input times the reciprocal root. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the normalized second component pair (z,w) to the output a1[1] as masked input times the reciprocal root. [field:this:0x00000008, source:raw]
    // CALL: Called by F_3DNowQuaternionFromAngle (0x0052278B) and QuaternionTo4x4RotationMatrix (0x00522876) to normalize quaternion/rotation vectors. [caller:0x0052278B, caller:0x00522876]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_527578(float *out, const float *in) {
    //     /* in[0..1] = packed (x,y); in[2..3] = packed (z,w) * /
    //     /* v5 = packed squared length (pfmul/pfadd/pfacc over components) * /
    //     /* v7 = zero mask when v5 <= threshold qword_5AF970 * /
    //     /* r = Newton-Raphson refined reciprocal sqrt of v5 * /
    //     out[0] = (in[0] & v7) * r;
    //     out[1] = (in[1] & v7) * r;
    //     return out;
    //   }
    // UNRESOLVED: Exact roles of the SIMD globals qword_5AF950 and qword_5AF970 beyond mask/threshold usage.
    // UNRESOLVED: Whether the fourth component (w) carries meaning or is always 1.0 for these callers.
    // UNRESOLVED: Owning context: a free helper or a math-library member.
}
