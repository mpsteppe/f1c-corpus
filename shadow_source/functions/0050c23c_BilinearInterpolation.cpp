// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C23C
// Canonical corpus name: BilinearInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BilinearInterpolation_0050c23c.c

void UnknownObject::BilinearInterpolation()
{
    // Per-axis weighted interpolation on float2-like points. For each of the first two components it computes out = (b - a) * a5 + (c - a) * a6 + a, where a = a2, b = a3, c = a4 are the source corners, a5/a6 are the two interpolation weights, and a1 is the destination. Returns a1 unchanged.
    // CALCULATION: Write component 0 of the destination: a1[0] = (a3[0] - a2[0]) * a5 + (a4[0] - a2[0]) * a6 + a2[0]. [field:this:0x00000000, source:raw]
    // CALCULATION: Write component 1 of the destination: a1[1] = (a3[1] - a2[1]) * a5 + (a4[1] - a2[1]) * a6 + a2[1]. [field:this:0x00000004, source:raw]
    // RETURN: Return the destination pointer a1. [function:0x0050C23C, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50C23C(float *out, float *cornerA, float *cornerB, float *cornerC, float wB, float wC) {
    //     out[0] = (cornerB[0] - cornerA[0]) * wB + (cornerC[0] - cornerA[0]) * wC + cornerA[0];
    //     out[1] = (cornerB[1] - cornerA[1]) * wB + (cornerC[1] - cornerA[1]) * wC + cornerA[1];
    //     return out;
    //   }
    // UNRESOLVED: Only two of the three spatial components are interpolated; whether the caller needs a 2D point or a third component is left elsewhere.
    // UNRESOLVED: The packet prelabel ('structural twin of FlagSetterWithOR 004a3560') does not match the arithmetic body and is treated as unreliable.
}
