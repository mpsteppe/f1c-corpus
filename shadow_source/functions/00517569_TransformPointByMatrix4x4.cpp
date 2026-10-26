// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517569
// Canonical corpus name: sub_517569
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_517569_00517569.c

void UnknownObject::TransformPointByMatrix4x4()
{
    // Applies an affine 4x4 matrix transform to a 3-component input vector: for each output component i, a1[i] = a2[0]*a3[i] + a2[1]*a3[4+i] + a2[2]*a3[8+i] + a3[12+i], where the a3[12..15] terms embed the translation. a2 is read only as a 3-vector, so the fourth homogeneous coordinate is implicitly 1 (point semantics, not direction). Computes components 1-3 into temporaries v3/v4/v5, writes all four output components at this+0x0..+0xC, and returns a1. Pure coordinate-transform helper with no branches, globals, or callees; structural twin of F_4DAffineTransform (0050c525) per packet prelabel and sibling TransformVectorByMatrix4x4 (00517653).
    // CALCULATION: v3 = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] + a3[13] (output component 1, matrix row/column index 1). [function:0x00517569, source:raw]
    // CALCULATION: v4 = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a3[14] (output component 2, matrix row/column index 2). [function:0x00517569, source:raw]
    // CALCULATION: v5 = a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a3[15] (output component 3, matrix row/column index 3). [function:0x00517569, source:raw]
    // ASSIGNMENT: a1[0] = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a3[12] (output component 0, matrix row/column index 0). [field:this:0x00000000, function:0x00517569, source:raw]
    // ASSIGNMENT: a1[1] = v3 (output component 1). [field:this:0x00000004, function:0x00517569, source:raw]
    // ASSIGNMENT: a1[2] = v4 (output component 2). [field:this:0x00000008, function:0x00517569, source:raw]
    // ASSIGNMENT: a1[3] = v5 (output component 3). [field:this:0x0000000C, function:0x00517569, source:raw]
    // RETURN: Return a1 (output vector pointer). [function:0x00517569, source:raw]

    // Conservative worker pseudocode:
    //   float* TransformPointByMatrix4x4(float* out, const float* v, const float* m) {
    //     float v3 = v[0]*m[1] + v[1]*m[5]  + v[2]*m[9]  + m[13];
    //     float v4 = v[0]*m[2] + v[1]*m[6]  + v[2]*m[10] + m[14];
    //     float v5 = v[0]*m[3] + v[1]*m[7]  + v[2]*m[11] + m[15];
    //     out[0] = v[0]*m[0] + v[1]*m[4]  + v[2]*m[8]  + m[12];
    //     out[1] = v3;
    //     out[2] = v4;
    //     out[3] = v5;
    //     return out;
    //   }
    // UNRESOLVED: Matrix orientation (column-major out = M*v vs row-major out = v*M) is not provable from this packet alone; the stride-4 layout with translation in m[12..15] is certain, the orientation is not.
    // UNRESOLVED: a2 is consumed as a 3-component vector, so the implicit homogeneous coordinate is assumed to be 1 (point transform); whether callers ever pass an implicit 0 (direction) is not evidenced here.
    // UNRESOLVED: No caller or owner evidence links this helper to a specific class, so owner stays UnknownObject/UNKNOWN despite the 0050c525 cluster twin prelabel.
    // UNRESOLVED: The fourth output component a1[3] is written but has no corresponding a2[3] input term; its meaning (affine w row) is inferred, not evidenced.
}
