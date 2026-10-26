// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C665
// Canonical corpus name: Vec4CrossProduct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Vec4CrossProduct_0050c665.c

void UnknownObject::Vec4CrossProduct()
{
    // Straight-line vector helper: computes a four-component float output buffer a1 from three four-component float inputs a2, a3, a4. Each output component is a signed sum of pairwise products (2x2 cross-product-like determinants of a3/a4 components) weighted by components of a2, then stored to a1[0..3]. Returns the output buffer pointer. No branches, calls, globals, or state writes.
    // CALCULATION: Compute cross-product-like intermediate terms from a3 and a4 components: v6 = a4[3]*a3[2], v8 = a3[3]*a4[2], v20 = a4[3]*a3[1] - a3[3]*a4[1], v17 = a3[1]*a4[2], v18 = a3[2]*a4[1], v19 = a3[3]*a4[0], v21 = a4[3]*a3[0], v16 = a4[0]*a3[2] - a3[0]*a4[2], v9 = a3[0]*a4[1], v10 = a4[0]*a3[1]. [source:raw]
    // CALCULATION: Compute output component 0: v12 = (v6 - v8)*a2[1] - v20*a2[2] + (v17 - v18)*a2[3]. [source:raw, function:0x0050C665]
    // ASSIGNMENT: Write a1[0] = v12, the first output component. [source:raw, field:this:0x00000000]
    // CALCULATION: Compute output component 1: v13 = (v8 - v6)*a2[0] - (v19 - v21)*a2[2] + v16*a2[3]. [source:raw, function:0x0050C665]
    // ASSIGNMENT: Write a1[1] = v13, the second output component. [source:raw, field:this:0x00000004]
    // CALCULATION: Compute output component 2: v14 = v20*a2[0] - (v21 - v19)*a2[1] + (v9 - v10)*a2[3]. [source:raw, function:0x0050C665]
    // ASSIGNMENT: Write a1[2] = v14, the third output component. [source:raw, field:this:0x00000008]
    // CALCULATION: Compute output component 3: v15 = (v18 - v17)*a2[0] - v16*a2[1] + (v10 - v9)*a2[2]. [source:raw, function:0x0050C665]
    // ASSIGNMENT: Write a1[3] = v15, the fourth output component. [source:raw, field:this:0x0000000C]
    // RETURN: Return the output buffer pointer a1. [source:raw, function:0x0050C665]

    // Conservative worker pseudocode:
    //   float *Vec4CrossProduct(float *a1, float *a2, float *a3, float *a4) {
    //     float t0 = a4[3] * a3[2];
    //     float t1 = a3[3] * a4[2];
    //     float t2 = a4[3] * a3[1] - a3[3] * a4[1];
    //     float t3 = a3[1] * a4[2];
    //     float t4 = a3[2] * a4[1];
    //     float out0 = (t0 - t1) * a2[1] - t2 * a2[2] + (t3 - t4) * a2[3];
    //     float t5 = a3[3] * a4[0];
    //     float t6 = a4[3] * a3[0];
    //     float t7 = a4[0] * a3[2] - a3[0] * a4[2];
    //     float out1 = (t1 - t0) * a2[0] - (t5 - t6) * a2[2] + t7 * a2[3];
    //     float t8 = a3[0] * a4[1];
    //     float t9 = a4[0] * a3[1];
    //     float out2 = t2 * a2[0] - (t6 - t5) * a2[1] + (t8 - t9) * a2[3];
    //     float out3 = (t4 - t3) * a2[0] - t7 * a2[1] + (t9 - t8) * a2[2];
    //     a1[0] = out0;
    //     a1[1] = out1;
    //     a1[2] = out2;
    //     a1[3] = out3;
    //     return a1;
    //   }
    // UNRESOLVED: Role of a2: weights (or a second operand) applied to the cross-product-like a3/a4 terms; exact mathematical meaning is not established from this function alone.
    // UNRESOLVED: Whether the inputs are expected to be normalized or how component order (x/y/z/w) maps to indices 0..3.
    // UNRESOLVED: The name Vec4CrossProduct is inherited from the abi:lead symbol (LEGACY trust); it is not independently confirmed by callers, and no caller evidence exists in this packet.
    // UNRESOLVED: Semantic intent of the embedded 2x2 determinant terms is reconstructed, not verified against an alternate source.
}
