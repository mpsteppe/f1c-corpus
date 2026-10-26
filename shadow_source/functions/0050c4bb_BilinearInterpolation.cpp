// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C4BB
// Canonical corpus name: BilinearInterpolation_c4bb
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BilinearInterpolation_c4bb_0050c4bb.c

void UnknownObject::BilinearInterpolation()
{
    // Component-wise bilinear interpolation of two offset vectors a3 and a4 against a base vector a2, driven by weights a5 and a6. Each of the three float components at a1[0..2] is computed as a2[i] + a5 * (a3[i] - a2[i]) + a6 * (a4[i] - a2[i]). Returns the output vector pointer a1.
    // CALCULATION: First component: *a1 = (*a3 - *a2) * a5 + (*a4 - *a2) * a6 + *a2. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the interpolated first component into *a1. [field:this:0x00000000, abi:lead]
    // CALCULATION: Second component: a1[1] = (a3[1] - a2[1]) * a5 + (a4[1] - a2[1]) * a6 + a2[1]. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the interpolated second component into a1[1]. [field:this:0x00000004, abi:lead]
    // CALCULATION: Third component: a1[2] = (a3[2] - a2[2]) * a5 + (a4[2] - a2[2]) * a6 + a2[2]. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the interpolated third component into a1[2]. [field:this:0x00000008, abi:lead]
    // RETURN: Return the output vector pointer a1. [function:0x0050C4BB, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50C4BB(float *out, float *base, float *p1, float *p2, float w1, float w2) {
    //     out[0] = base[0] + w1 * (p1[0] - base[0]) + w2 * (p2[0] - base[0]);
    //     out[1] = base[1] + w1 * (p1[1] - base[1]) + w2 * (p2[1] - base[1]);
    //     out[2] = base[2] + w1 * (p1[2] - base[2]) + w2 * (p2[2] - base[2]);
    //     return out;
    //   }
    // UNRESOLVED: Semantic role of the two interpolated vectors a3/a4 and the weights a5/a6 (tracks, wings, visual offsets) is caller-supplied and unknown here.
    // UNRESOLVED: this+0x0/0x4/0x8 are the three written floats of the output vector; no object membership is proven for a1.
}
